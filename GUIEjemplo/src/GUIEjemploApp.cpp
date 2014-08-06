#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GUIEjemploApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	ci::params::InterfaceGlRef mParams;

	ci::Vec2f pos;
	ci::Vec2f vel;

	ci::ColorA color;
	float      radius;
	bool       enableAlpha;
	float      fps;
};

void GUIEjemploApp::setup()
{
	setWindowSize(1024, 764);
	setFrameRate(60);
	mParams = ci::params::InterfaceGl::create(getWindow(), "GUI", ci::Vec2i(200, 200));
	mParams->addParam("FPS", &fps, "");
	mParams->addParam("vel X", &vel.x, "min =-2 max=2, step=0.01");
	mParams->addParam("vel Y", &vel.y, "min =-2 max=2, step=0.01");
	mParams->addParam("Color", &color);
	mParams->addParam("Radius", &radius);

	radius = 30;
	color  = ci::ColorA(1, 0, 0);
	vel    = ci::Vec2f(0.1, 0.3);
	pos = ci::Vec2f(getWindowCenter());
}

void GUIEjemploApp::mouseDown( MouseEvent event )
{
}

void GUIEjemploApp::update()
{
	fps = getAverageFps();
	pos += vel;
}

void GUIEjemploApp::draw()
{
	// clear out the window with black
	gl::enableAlphaBlending();
	gl::color( ColorA( 0, 0, 0, 0.05 ) );
	gl::drawSolidRect(getWindowBounds());

	gl::color(color);
	gl::drawSolidCircle(pos, radius);
	mParams->draw();
}

CINDER_APP_NATIVE( GUIEjemploApp, RendererGl )
