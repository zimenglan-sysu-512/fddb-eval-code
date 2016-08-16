#ifndef __ELLIPSER_HPP__
#define __ELLIPSER_HPP__

#include "common.hpp"

#include <vector>
#ifndef __XCODE__
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#endif

#include "Region.hpp"
/**
 * Specification of an elliptical region
 *  */
class EllipseR : public Region{
    private:
	/// x-position of the center
	double cx;
	/// y-position of the center
	double cy;
	/// orientation of the major axis
	double angle;
	/// half-length of the major axis
	double ra;
	/// half-length of the minor axis
	double rb;
    public:
	/// Constructor
	EllipseR(IplImage *, std::vector<double> *);
	/// Method to add this ellipse of a given color and 
	/// line width to an image. If the 
	/// last parameter is not NULL, display the text also.
	virtual IplImage *display(IplImage *I, CvScalar color, int lineWidth, const char *text);
	virtual void getLoc(double& cx,double& cy,double& ra,double& rb);
};

#endif
