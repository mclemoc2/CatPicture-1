#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
private:
	// Variables for the brightness of the pixels
	float red_;
	float green_;
	float blue_;

	// increments as the program runs and keeps track of time
	float time_;
};

void CatPictureApp::setup()
{
	time_ = 0.0;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	time_ = time_ + 0.05;
	red_ = .5*cos(time_/2) + 0.5;
	green_ = .5*cos(time_) + 0.5;
	blue_ = .5*cos(time_*2) + 0.5;	
}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( red_, green_, blue_ ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
