#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include  "cinder/Rand.h"

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

	//Particula
	ci::Vec2f * pos;
	ci::Vec2f * vel;
	float	   * radius;
	ci::ColorA * col;
};

void VideoTestQTApp::setup()
{
	mMovie = qtime::MovieGl::create(loadAsset("video.mp4"));
	mMovie->setLoop();
	mMovie->play();

	int  w = mMovie->getWidth();
	int  h = mMovie->getHeight();
	setWindowSize(w, h);

	pos = new ci::Vec2f[100];
	vel = new ci::Vec2f[100];
	col = new ci::ColorA[100];
	radius = new float[100];

	for (int i = 0; i < 100; i++){
		float x = ci::Rand::randFloat(200, 500);
		float y = ci::Rand::randFloat(200, 500);
		pos[i] = ci::Vec2f(x, y);
		float vx = ci::Rand::randFloat(-0.1, 0.1);
		float vy = ci::Rand::randFloat(-0.1, 0.1);
		vel[i] = ci::Vec2f(vx, vy);
		radius[i] = 2 + ci::Rand::randFloat(1, 6);
	}
	
}

void VideoTestQTApp::mouseDown( MouseEvent event )
{
}

void VideoTestQTApp::update()
{
	if (mMovie){
		mTexture = mMovie->getTexture();
		if (mTexture){
			int index = 0;
			mSurface = Surface(mTexture);
		}
	}


	if (mSurface){
		for (int i = 0; i < 100; i++){
			int x = (int)pos[i].x;
			int y = (int)pos[i].y;
			col[i] = mSurface.getPixel(ci::Vec2i(x, y));
			pos[i] += vel[i];
		}
	}
}

void VideoTestQTApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );

	if (mSurface){
		//gl::draw(mSurface);
	}

	for (int i = 0; i < 100; i++){
		gl::color(col[i]);
		gl::drawSolidCircle(pos[i], radius[i]);
	}
}

CINDER_APP_NATIVE( VideoTestQTApp, RendererGl )
