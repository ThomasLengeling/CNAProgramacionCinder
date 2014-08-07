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
	float  * life;

	int contador;
};

void VideoTestQTApp::setup()
{
	mMovie = qtime::MovieGl::create(loadAsset("video.mp4"));
	mMovie->setLoop();
	mMovie->play();

	int  w = mMovie->getWidth();
	int  h = mMovie->getHeight();
	setWindowSize(w, h);

	pos = new ci::Vec2f[400];
	vel = new ci::Vec2f[400];
	col = new ci::ColorA[400];
	radius = new float[400];
	life = new float[400];

	contador = 0;

	for (int i = 0; i < 400; i++){
		pos[i] = ci::Vec2f(getWindowCenter());
		float vx = ci::Rand::randFloat(-0.2, 0.2);
		float vy = ci::Rand::randFloat(-0.2, 0.2);
		vel[i] = ci::Vec2f(vx, vy);
		radius[i] = 50 + ci::Rand::randFloat(2, 15);
		life[i] = ci::Rand::randFloat(20, 55);
	}
	
}

void VideoTestQTApp::mouseDown( MouseEvent event )
{
	//if (contador >= 400 - 10)
	for (int i = contador; i < contador + 10; i++){
		pos[i] = event.getPos();
	}
	
	contador = contador + 10;
	if (contador >= 400)
		contador = 400;
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
		for (int i = 0; i < contador; i++){
			int x = lmap < float >((int)pos[i].x, 0, getWindowWidth(), 0, mSurface.getWidth());
			int y = lmap < float >((int)pos[i].y, 0, getWindowHeight(), 0, mSurface.getHeight());
			col[i] = mSurface.getPixel(ci::Vec2i(x, y));
			pos[i] += vel[i];

			if (life[i] > 0)
				life[i] -= 0.1;
			else{
				life[i] = 0.0;
			}

		}
	}
}

void VideoTestQTApp::draw()
{
	// clear out the window with black
	//gl::clear( Color( 1, 1, 1 ) );
	//gl::enableAlphaBlending();
	//gl::color(0, 0, 0, 0.01);
	//gl::drawSolidRect(getWindowBounds());


	if (mSurface){
		//gl::draw(mSurface);
	}

	for (int i = 0; i < contador; i++){
		if (life[i] > 0){
			gl::color(col[i]);
			gl::drawSolidCircle(pos[i], radius[i]);

			if (radius[i] > 2){
				radius[i] -= 0.1;
			}
		}
	}
}

CINDER_APP_NATIVE( VideoTestQTApp, RendererGl )
