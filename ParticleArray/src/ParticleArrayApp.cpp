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

class ParticleArrayApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    
    std::vector<Particle> mParticles;
};

void ParticleArrayApp::setup()
{
    for(int i = 0; i < 100; i++){
        mParticles.push_back(Particle(getWindowCenter()));
    }
}

void ParticleArrayApp::mouseDown( MouseEvent event )
{
}

void ParticleArrayApp::update()
{
    for(int i = 0; i < 100; i++){
        mParticles[i].update();
    }
}

void ParticleArrayApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    for(int i = 0; i < 100; i++){
        mParticles[i].draw();
    }
}

CINDER_APP_NATIVE( ParticleArrayApp, RendererGl )
