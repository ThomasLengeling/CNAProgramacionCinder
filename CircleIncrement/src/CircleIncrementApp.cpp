#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CircleIncrementApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    ci::Vec2f ellipsePositionLeft;
    ci::Vec2f ellipsePositionRight;
    
    float tamLeft;
    float tamRight;
};

void CircleIncrementApp::setup()
{
    setWindowSize(ci::Vec2i(1024, 768));
    ellipsePositionLeft  = ci::Vec2f(getWindowWidth()/2.0 - 200, getWindowHeight()/2.0);
    ellipsePositionRight = ci::Vec2f(getWindowWidth()/2.0 + 200, getWindowHeight()/2.0);
    
    tamLeft  = 10;
    tamRight = 10;
}

void CircleIncrementApp::mouseDown( MouseEvent event )
{
}

void CircleIncrementApp::update()
{
    tamLeft += 0.1;
    if(tamLeft >90)
        tamLeft = 0;
    
    tamRight += 0.3;
    if(tamRight > 120)
        tamRight = 0;
}

void CircleIncrementApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::enableAlphaBlending();
    
    gl::color(0.4, 0.4, 0.4, 0.9);
    gl::drawSolidCircle(ellipsePositionLeft, tamLeft);
    
    gl::color(0.8, 0.8, 0.8, 0.9);
    gl::drawSolidCircle(ellipsePositionRight, tamRight);
}

CINDER_APP_NATIVE( CircleIncrementApp, RendererGl )
