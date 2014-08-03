#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class LineConnectionsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void keyDown( KeyEvent event );
	void update();
	void draw();
    
    
    ci::Vec2f              mousePos;
    std::vector<ci::Vec2f> history;
};

void LineConnectionsApp::setup()
{
}

void LineConnectionsApp::mouseDown( MouseEvent event )
{
    
}

void LineConnectionsApp::mouseDrag(MouseEvent event)
{
    history.insert(history.begin(), event.getPos());
    //console()<<event.getPos()<<std::endl;
}

void LineConnectionsApp::keyDown( KeyEvent event )
{
    if(event.getChar() == 'a'){
        history.clear();
    }
}

void LineConnectionsApp::update()
{
    
}

void LineConnectionsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
    
    gl::enableAlphaBlending();
    
    gl::color(ci::ColorA(0.0, 0.0, 0.0, 0.1));
    for(int i = 0; i < history.size(); i++){
        for(int j = 0; j < history.size(); j++){
            if(history[i].distance(history[j]) < 50){
                gl::drawLine(history[i], history[j]);
            }
        }
    }
}

CINDER_APP_NATIVE( LineConnectionsApp, RendererGl )
