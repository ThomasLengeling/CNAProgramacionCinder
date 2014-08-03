#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasiAppApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseUp( MouseEvent event);
	void update();
	void draw();
    
    ci::Vec2f  mousePos;
    ci::Vec2f  pMousePos;
    bool       activateMouse;
};

void BasiAppApp::setup()
{
    gl::clear( Color( 0, 0, 0 ) );

}

void BasiAppApp::mouseDown( MouseEvent event )
{
    activateMouse = true;
    pMousePos = mousePos;
    mousePos = event.getPos();
}

void BasiAppApp::mouseDrag( MouseEvent event )
{
    if(activateMouse){
        pMousePos = mousePos;
        mousePos  = event.getPos();
    }

}

void BasiAppApp::mouseUp(MouseEvent event)
{
    activateMouse = false;
    pMousePos = mousePos;
    mousePos  = event.getPos();
}


void BasiAppApp::update()
{
    
}

void BasiAppApp::draw()
{
    
	// clear out the window with black
//	gl::clear( Color( 0, 0, 0 ) );
    gl::drawLine(mousePos, pMousePos);
}

CINDER_APP_NATIVE( BasiAppApp, RendererGl )
