#include "EllipseR.hpp"
#ifndef __XCODE__
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#endif
#include <vector>
#include <iostream>
#include "OpenCVUtils.hpp"

EllipseR::EllipseR(IplImage *I, std::vector<double> *v) :
		Region(I) {
	cx = v->at(0);
	cy = v->at(1);
	angle = v->at(2);
	ra = v->at(3);
	rb = v->at(4);
	detScore = v->at(5);
}
void EllipseR::getLoc(double& x, double& y, double& w, double& h) {
	x = cx;
	y = cy;
	w = ra;
	h = rb;
}
IplImage *EllipseR::display(IplImage *mask, CvScalar color, int lineWidth,
		const char *text) {
	// draw the ellipse on the mask image
	cvEllipse(mask, cvPointFrom32f(cvPoint2D32f(cx, cy)),
			cvSize((int) ra, (int) rb), angle, 0, 360, color, lineWidth);

	if (text != NULL) {
		// add text
		CvFont font;
		cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 1.0, 1.0, 0, 1, CV_AA);
		cvPutText(mask, text, cvPointFrom32f(cvPoint2D32f(cx, cy)), &font, color);
	}
	return mask;
}
