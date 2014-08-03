#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Particle{
public:
    Particle( ci::Vec2f loc )
    {
        mLoc	= loc;
        mDir	= Rand::randVec2f();
        mVel	= Rand::randFloat( 5.0f );
        mRadius	= 3.0f;
    }

    void update()
    {
        mLoc += mDir * mVel;
    }

    void draw()
    {
        gl::drawSolidCircle( mLoc, mRadius );
    }
    
    ci::Vec2f	mLoc;
	ci::Vec2f	mDir;
	float		mVel;
	
	float		mRadius;
};

class SingleParticleApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Particle *particle;
    
};

void SingleParticleApp::setup()
{
    particle  = new Particle(getWindowCenter());
}

void SingleParticleApp::mouseDown( MouseEvent event )
{
}

void SingleParticleApp::update()
{
    particle->update();
}

void SingleParticleApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    particle->draw();
}

CINDER_APP_NATIVE( SingleParticleApp, RendererGl )
