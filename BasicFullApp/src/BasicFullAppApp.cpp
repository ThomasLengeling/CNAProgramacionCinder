#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/*
Reference
http://libcinder.org/docs/v0.8.1/classcinder_1_1app_1_1_app_cinder_view.html
*/

class BasicFullAppApp : public AppNative {
  public:

  	void prepareSettings (Settings *settings);
	void setup();

	//MOUSE EVENTS
	void mouseDown( MouseEvent event );	
	void mouseUp( MouseEvent event );
	void mouseMove(MouseEvent event);
	void mouseDrag(MouseEvent event);
	void mouseWheel(MouseEvent event);

	//KEY EVENTS
	void keyUp(KeyEvent event);
	void keyDown(KeyEvent event);

	//UPDATE
	void update();
	void draw();

	void shutdown();
	void resize();

	ci::Vec2f pos;
};

void BasicFullAppApp::prepareSettings(Settings *settings)
{

}

void BasicFullAppApp::setup()
{
	pos = ci::Vec2f(200, 200);
}


//----------------MOUSE----------------------------------
void BasicFullAppApp::mouseDown(MouseEvent event)
{

}

void BasicFullAppApp::mouseUp(MouseEvent event)
{

}
void BasicFullAppApp::mouseMove(MouseEvent event)
{

}
void BasicFullAppApp::mouseDrag(MouseEvent event)
{

}

void BasicFullAppApp::mouseWheel(MouseEvent event)
{

}

//----- KEY EVENTS -------------------------------------
void BasicFullAppApp::keyUp(KeyEvent event)
{

}

void BasicFullAppApp::keyDown(KeyEvent event)
{

}


void BasicFullAppApp::update()
{
	pos.x += 0.4;
}

void BasicFullAppApp::draw()
{
	// clear out the window with black
	gl::enableAlphaBlending();
	gl::color(ci::ColorA(0, 0, 0, 0.06));
	gl::drawSolidRect(ci::Rectf(0, 0, getWindowWidth(), getWindowHeight()));

	gl::color(ci::ColorA(0, 1, 1, 0.2));
	gl::drawSolidCircle(pos, 50);
}

void BasicFullAppApp::shutdown()
{

}

void BasicFullAppApp::resize()
{

}


CINDER_APP_NATIVE( BasicFullAppApp, RendererGl )
