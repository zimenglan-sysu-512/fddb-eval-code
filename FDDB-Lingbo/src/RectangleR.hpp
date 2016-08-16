#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Region.hpp"
#include <vector>

#ifndef __XCODE__
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#endif

/**
 * Specification of a rectangular region
 *  */
class RectangleR: public Region {
private:
	/// x-position of the left-top corner
	double x;
	/// y-position of the left-top corner
	double y;
	/// width 
	double w;
	/// height 
	double h;
public:
	/// Constructor
	RectangleR(IplImage *, std::vector<double> *);
	/// Method to add this rectangle of a given color and 
	/// line width to an image. If the 
	/// last parameter is not NULL, display the text also.
	virtual IplImage *display(IplImage *, CvScalar color, int lineWidth,
			const char *text);

	void getLoc(double& left, double& top, double& width, double& height);

	double getH() const {
		return h;
	}

	void setH(double h) {
		this->h = h;
	}

	double getW() const {
		return w;
	}

	void setW(double w) {
		this->w = w;
	}

	double getX() const {
		return x;
	}

	double getY() const {
		return y;
	}

	void setY(double y) {
		this->y = y;
	}
};

#endif
