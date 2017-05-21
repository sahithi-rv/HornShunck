#ifndef OPTICALFLOW_H_
#define OPTICALFLOW_H_

#include <hls_stream.h>
#include <cmath>
#include <ap_int.h>
#include "constants.h"


typedef ap_int<16> int_t;
typedef unsigned char int8;

using namespace std;

void opflow( hls::stream<int8> & input1, hls::stream<int8> & input2, hls::stream<data9_t> & velocityX, hls::stream<data10_t> & velocityY);
void finalIteration(hls::stream<data9_t> & velocityX,hls::stream<data10_t> & velocityY,hls::stream<data2_t> & Ix,
		hls::stream<data3_t> & Iy,hls::stream<data1_t> & It,hls::stream<data7_t> & commonX,hls::stream<data8_t> & commonY,
		hls::stream<data9_t> & velocityX_out,hls::stream<data10_t> & velocityY_out);

void iterationMiddle(hls::stream<data9_t> & velocityX,hls::stream<data10_t> & velocityY,hls::stream<data2_t> & Ix,
		hls::stream<data3_t> & Iy,hls::stream<data1_t> & It,hls::stream<data7_t> & commonX,hls::stream<data8_t> & commonY,
		hls::stream<data9_t> & velocityX_out,hls::stream<data10_t> & velocityY_out,hls::stream<data2_t> & Ix_out,
				hls::stream<data3_t> & Iy_out,hls::stream<data1_t> & It_out,hls::stream<data7_t> & commonX_out,
				hls::stream<data8_t> & commonY_out);

#endif


