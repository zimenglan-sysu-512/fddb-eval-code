#include "RectangleR.hpp"
#ifndef __XCODE__
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#endif

#include <vector>
using std::vector;

RectangleR::RectangleR(IplImage *I, vector<double> *v) :
		Region(I) {
	x = v->at(0);
	y = v->at(1);
	w = v->at(2);
	h = v->at(3);
	detScore = v->at(4);
}
void RectangleR::getLoc(double& left, double& top, double& width,
		double& height) {
	left = x;
	top = y;
	width = w;
	height = h;
}
IplImage *RectangleR::display(IplImage *mask, CvScalar color, int lineWidth,
		const char *text) {
	// Draw the rectangle
	cvRectangle(mask, cvPointFrom32f(cvPoint2D32f(x, y)),
			cvPointFrom32f(cvPoint2D32f(x + w, y + h)), color, lineWidth);

	if (text != NULL) {
		// Add text
		CvFont font;
		cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5, 0, 1, CV_AA);
		cvPutText(mask, text, cvPointFrom32f(cvPoint2D32f(x, y)), &font,
				cvScalar(0, 0, 255));
	}
	return mask;
}
