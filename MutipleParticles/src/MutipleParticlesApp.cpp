#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MutipleParticlesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

	ci::Vec2f  * pos;
	ci::Vec2f  * vel;
	float	   * radius;
	ci::ColorA  color;

	int        numParticles;
};

void MutipleParticlesApp::setup()
{
	numParticles = 200;

	pos    = new ci::Vec2f[numParticles];
	vel    = new ci::Vec2f[numParticles];
	radius = new float[numParticles];

	for (int i = 0; i < numParticles; i++){
		pos[i] = getWindowCenter();
		float vy = ci::Rand::randFloat(-0.1, 0.1);
		float vx = ci::Rand::randFloat(-0.1, 0.1);
		vel[i] = ci::Vec2f(vx, vy);
		radius[i] = 2.0 + ci::Rand::randFloat(2, 5);
	}
}

void MutipleParticlesApp::mouseDown( MouseEvent event )
{
}

void MutipleParticlesApp::update()
{
	for (int i = 0; i < numParticles; i++){
		//pos[i] += vel[i];
		pos[i] = pos[i] + vel[i];
	}
}

void MutipleParticlesApp::draw()
{
	// clear out the window with black
	gl::enableAlphaBlending();
	gl::color(ci::ColorA(0, 0, 0, 0.04));
	gl::drawSolidRect(getWindowBounds());
	
	gl::color(ci::ColorA(0, 0.5, 0.6, 0.1));

	/* GL primitives
	GL_POINTS  glPointSize(10);
	GL_LINES
	GL_LINE_STRIP
	GL_TRIANGLES
	GL_TRIANGLE_STRI
	*/
	
	
	gl::begin(GL_TRIANGLES);
	for (int i = 0; i < numParticles/2.0; i++){
		gl::vertex(pos[i]);
	}
	gl::end();

	gl::begin(GL_LINE);
	for (int i = numParticles/2.0; i < numParticles; i++){
		gl::vertex(pos[i]);
	}
	gl::end();
	
}

CINDER_APP_NATIVE( MutipleParticlesApp, RendererGl )
