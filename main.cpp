#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
// #include "opencv2/video/tracking.hpp"
// #include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include "OpticalFlow.h"
#include <fstream>

using namespace cv;


void image_info(Mat &img)
{
    std::cout << "Channels: " << img.channels() << std::endl;
    std::cout << "Depth: "  << img.type() << std::endl;
    std::cout << "Size: "  << img.size() << std::endl;
}

int main(int argc, char** argv)
{
	int imgSize = (3 * (R) * (C));
	int_t threshold = 1, weight = 1;
	Mat img, img1, imgf, imgf1, output;
	cout << frame1 << endl;
	img = imread(frame1,  CV_LOAD_IMAGE_GRAYSCALE);
	image_info(img);
//	Rect roi(0, 0, R+2, C+2);
//	Mat img_region = img(roi).clone();

//	image_info(img_region);

	hls::stream<int8> src_img_strm_1("src_img_strm1");
	hls::stream<data9_t> dst_img_strm_1("dst_img_strm1");
	hls::stream<int8> src_img_strm_2("src_img_strm2");
	hls::stream<data10_t> dst_img_strm_2("dst_img_strm2");

	for(int j = 0;j<C;j++){
		src_img_strm_1 << 0;

	}
	for (int i = 0; i < R; i++){
		//cout << i << endl;
		src_img_strm1 << 0;
		for (int j = 0; j < C; j++){
			int8 val = img.at<uchar>(i, j);
		//	printf("%f, ", val);
			src_img_strm_1 << val;
		}
		src_img_strm1 << 0;
	//	cout <<  endl;
	}
	for(int j = 0;j<C;j++){
		src_img_strm_1 << 0;

	}
	img = imread(frame2,  CV_LOAD_IMAGE_GRAYSCALE);
	//img_region = img(roi).clone();
	image_info(img);
	for(int j = 0;j<C;j++){
		src_img_strm_2 << 0;

	}
	for (int i = 0; i < R; i++){
		src_img_strm_2 << 0;
		for (int j = 0; j < C; j++){
			int8 val = img.at<uchar>(i, j);
			//printf("%f, ", val);
			src_img_strm_2 << val;
		}
		src_img_strm_2 << 0;
	}
	for(int j = 0;j<C;j++){
		src_img_strm_2 << 0;

	}
	opflow(src_img_strm_1,src_img_strm_2,dst_img_strm_1,dst_img_strm_2);
	ofstream myfile;
	myfile.open (output_file1);
	ofstream myfile1;
	myfile1.open (output_file2);
	cout << output_file2 << endl;
	float dst_val;
	cout << R*C << endl;
	//cout << dst_img_strm_1.size() << endl;
	//cout << dst_img_strm_2.size() << endl;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			data9_t dst_val = dst_img_strm_1.read();
				data10_t dst_val1 = dst_img_strm_2.read();
				

				myfile << dst_val ;
				myfile << "\n";
				myfile1 << dst_val1 ;
				myfile1 << "\n";
		}
	}

	return 0;

}
