#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"

#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ImageTestApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	ci::Surface  imagen;

	ci::params::InterfaceGlRef mParams;
	ci::Vec2i  step;
	float	   fps;

	int			drawType;
};

void ImageTestApp::setup()
{
	imagen = Surface(loadImage(loadAsset("cinder.png")));
	
	int h = imagen.getHeight();
	int w = imagen.getWidth();

	setWindowSize(w, h);

	mParams = ci::params::InterfaceGl::create(getWindow(), "GUI", ci::Vec2i(200, 200));
	mParams->addParam("FPS", &fps, "");
	mParams->addParam("Step X", &step.x, "");
	mParams->addParam("Step Y", &step.y, "");

	step = ci::Vec2i(15, 15);
}

void ImageTestApp::mouseDown( MouseEvent event )
{
}

void ImageTestApp::update()
{
	fps = getAverageFps();
}

void ImageTestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	/*
	gl::begin(GL_POINTS);
	for (int i = 0; i < imagen.getWidth(); i++){
		for (int j = 0; j < imagen.getHeight(); j++){
			ci::Color col = imagen.getPixel(ci::Vec2i(i, j));
			gl::color(col);
			gl::vertex(i, j);
		}
	}
	gl::end();

	Surface::Iter      iterImage(imagen.getIter());

	while (iterImage.line()){
		while (iterImage.pixel()) {
	
		}
	}
	*/
	for (int i = 0; i < imagen.getWidth(); i+=step.x){
		for (int j = 0; j < imagen.getHeight(); j+=step.y){
			ci::ColorA col = imagen.getPixel(ci::Vec2i(i, j));
			gl::color(col);
			gl::drawSolidRect(ci::Rectf(i, j, step.x +i, step.y +j));
		}
	}
	
	mParams->draw();

	//gl::draw(imagen);
	//ci::Color color = imagen.getPixel(ci::Vec2i(100, 100));

	//gl::draw(imagen.getChannelRed(), ci::Vec2i(imagen.getWidth(), 0));
}

CINDER_APP_NATIVE( ImageTestApp, RendererGl )
