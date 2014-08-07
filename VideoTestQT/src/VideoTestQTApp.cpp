#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/qtime/QuickTime.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class VideoTestQTApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	gl::Texture					mTexture;
	ci::Surface                 mSurface;
	ci::qtime::MovieGlRef		mMovie;
};

void VideoTestQTApp::setup()
{
	mMovie = qtime::MovieGl::create(loadAsset("video_test.mov"));
	mMovie->setLoop();
	mMovie->play();

	int  w = mMovie->getWidth();
	int  h = mMovie->getHeight();
	setWindowSize(w, h);
}

void VideoTestQTApp::mouseDown( MouseEvent event )
{
}

void VideoTestQTApp::update()
{
	if (mMovie){
		mTexture = mMovie->getTexture();
		//mSurface = Surface(mMovie->getTexture());
	}
}

void VideoTestQTApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );

	if (mTexture){
		gl::draw(mTexture);
	}
}

CINDER_APP_NATIVE( VideoTestQTApp, RendererGl )
