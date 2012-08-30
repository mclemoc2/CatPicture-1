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
	Surface* mySurface_;
	// Variables for the brightness of the pixels
	float red_;
	float green_;
	float blue_;

	// increments as the program runs and keeps track of time
	float time_;

	static const int kAppWidth = 800;
	static const int kAppHeight = 600;
	static const int kTextureSize = 1024;

	void tileWithRectangles(uint8_t* pixels, int x1, int y1, int x2, int y2, int rect_width, int rect_height, Color8u fill1, Color8u border1, Color8u fill2, Color8u border2);
};

void CatPictureApp::tileWithRectangles(uint8_t* pixels, int x1, int y1, int x2, int y2, int rect_width, int rect_height, Color8u fill1, Color8u border1, Color8u fill2, Color8u border2)
{

}
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
