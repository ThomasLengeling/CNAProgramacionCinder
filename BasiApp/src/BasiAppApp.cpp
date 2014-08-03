#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasiAppApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void BasiAppApp::setup()
{
}

void BasiAppApp::mouseDown( MouseEvent event )
{
}

void BasiAppApp::update()
{
}

void BasiAppApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( BasiAppApp, RendererGl )
