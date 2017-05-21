#include <hls_stream.h>
#include <malloc.h>
#include <cmath>
#include "OpticalFlow.h"

void opflow( hls::stream<int8> & input1, hls::stream<int8> & input2, hls::stream<data9_t> & velocityX, hls::stream<data10_t> & velocityY)
{
	int8 alpha=2;
  int8 aplhaSquare = alpha*alpha;
  const int  _ct1 = ( R);
  const int  _ct2 = ( C);
  hls::stream<data1_t> It_out_stream("It_out1");
  hls::stream<int8> input1_Ix_stream("inp1_ix1");
  
    for (int_t  _ci1 = 0; (_ci1 <= (_ct1 - 1)); _ci1 = (_ci1 + 1))
    {
      pipe15:for (int_t  _ci2 = 0; (_ci2 <= (_ct2 - 1)); _ci2 = (_ci2 + 1))
      {
        
		int8 input2_in_val = input2.read();
		int8 input1_in_val = input1.read();
		
		It_out_stream.write((input2_in_val - input1_in_val));
		input1_Ix_stream.write(input1_in_val);
        
      }
    }
  

  const int  _ct4 = (R);
  const int  _ct5 = (C);
  hls::stream<data2_t> Ix_out_stream("ix_out2");
  hls::stream<int8> input1_Iy_stream("inp1_iy2");
  int8  Ix_input1_LBuffer[3][_ct5];
  int8  Ix_input1_WBuffer[3][3];

  
    for(int_t  _ci4 = 0; (_ci4 <= (_ct4 - 1)); _ci4 = (_ci4 + 1))
    {
      pipe5:for(int_t  _ci5 = 0; (_ci5 <= (_ct5 - 1)); _ci5 = (_ci5 + 1))
      {
        if( !input1_Ix_stream.empty() ){
			int8 input1_in_val = input1_Ix_stream.read();
			for(int_t i=0;i<3-1;i++){
				Ix_input1_LBuffer[i][_ci5] = Ix_input1_LBuffer[i+1][_ci5];
			}
			Ixx_input1_LBuffer[3-1][_ci5] = input1_in_val;

			for(int_t i=0;i<3;i++){
				for(int_t j=0;j<3-1;j++){
					Ix_input1_WBuffer[i][j] = Ix_input1_WBuffer[i][j+1];
				}
			}
			for(int_t i=0;i<3;i++){
				Ix_input1_WBuffer[i][3-1] = Ix_input1_LBuffer[i][_ci5];
			}
			if(_ci5 == 0 || _ci4 == 0){
				Ix_out_stream.write(0);
			}
			if(_ci5>=3-1 && _ci4>=3-1)
			{
				data2_t sum = (-Ix_input1_WBuffer[0][0] + Ix_input1_WBuffer[0][2] - (Ix_input1_WBuffer[1][0]*2) +
						(Ix_input1_WBuffer[1][2] * 2) -Ix_input1_WBuffer[2][0] + Ix_input1_WBuffer[2][2]);
				data2_t out_val=data2_t(sum/12);
				Ix_out_stream.write(out_val);
			}
			if(_ci5 == C-1 || _ci4 == R-1){
				Ix_out_stream.write(0);
			}
			input1_Iy_stream.write(input1_in_val);
        }
	  }
    }
  //  cout << "IX" << endl;
  //cout << Ix_out_stream.size() << endl;
  const int  _ct7 = ( R);
  const int  _ct8 = ( C);
  hls::stream<data3_t> Iy_out_stream("iy_out3");
  int8  Iy_input1_LBuffer[3][_ct8];
  int8  Iy_input1_WBuffer[3][3];

    for (int_t  _ci7 = 0; (_ci7 <= (_ct7 - 1)); _ci7 = (_ci7 + 1))
    {
      pipe2:for (int_t  _ci8 = 0; (_ci8 <= (_ct8 - 1)); _ci8 = (_ci8 + 1))
      {
        
    	 if( !input1_Iy_stream.empty() ){

			int8 input1_in_val = input1_Iy_stream.read();


			for(int_t i=0;i<3-1;i++){
				Iy_input1_LBuffer[i][_ci8] = Iy_input1_LBuffer[i+1][_ci8];
			}
			Iy_input1_LBuffer[3-1][_ci8] = input1_in_val;

			for(int_t i=0;i<3;i++){
				for(int_t j=0;j<3-1;j++){
					Iy_input1_WBuffer[i][j] = Iy_input1_WBuffer[i][j+1];
				}
			}
			for(int_t i=0;i<3;i++){
				Iy_input1_WBuffer[i][3-1] = Iy_input1_LBuffer[i][_ci8];
			}
			if(_ci8 == 0 || _ci7 == 0){
				Iy_out_stream.write(0);
			}
			if(_ci8>=3-1 && _ci7>=3-1)
			{
				data3_t sum = (-Iy_input1_WBuffer[0][0] + Iy_input1_WBuffer[2][0] -
						  (Iy_input1_WBuffer[0][1] * 2) + (Iy_input1_WBuffer[2][1] * 2) -
						  Iy_input1_WBuffer[0][2] + Iy_input1_WBuffer[2][2]);
				data3_t out_val=data3_t(sum/12);
				
			  Iy_out_stream.write(out_val);
		  	}
		  	if(_ci8 == C-1 || _ci7 == R-1){
				Iy_out_stream.write(0);
			}
		}
	  }
    }
  //  cout << "Iy" << endl;
  //cout << Iy_out_stream.size() << endl;
  const int  _ct10 = (R);
  const int  _ct11 = (C);
  hls::stream<data4_t> Ixx_out_stream("ixx_out4");
  hls::stream<data2_t> Ix_commonX_stream("commonx4");
 
    for (int_t  _ci10 = 0; (_ci10 <= (_ct10 - 1)); _ci10 = (_ci10 + 1))
    {
      pipe6:for (int_t  _ci11 = 0; (_ci11 <= (_ct11 - 1)); _ci11 = (_ci11 + 1))
      {
    	  if( !Ix_out_stream.empty() ){
    		data2_t Ix_in_val = Ix_out_stream.read();
    		data4_t k = Ix_in_val * Ix_in_val;
			Ixx_out_stream.write(k);
			Ix_commonX_stream.write(Ix_in_val);
			
    	  }
	  }
    }
  

  const int  _ct13 = (R);
  const int  _ct14 = (C);
  hls::stream<data5_t> Iyy_out_stream("iyy_out5");
  hls::stream<data3_t> Iy_commonY_stream("commony5");
 
    for (int_t  _ci13 = 0; (_ci13 <= (_ct13 - 1)); _ci13 = (_ci13 + 1))
    {
      pipe3:for (int_t  _ci14 = 0; (_ci14 <= (_ct14 - 1)); _ci14 = (_ci14 + 1))
      {
    	  if( !Iy_out_stream.empty() ){
    		data3_t Iy_in_val = Iy_out_stream.read();
    		data5_t k = Iy_in_val * Iy_in_val;
			Iyy_out_stream.write(k);
			Iy_commonY_stream.write(Iy_in_val);
			
    	  }
      }
    }
  
  
  const int  _ct16 = (R);
  const int  _ct17 = (C);
  hls::stream<data6_t> denom_out_stream("denom6");
    for (int_t  _ci16 = 0; (_ci16 <= (_ct16 - 1)); _ci16 = (_ci16 + 1))
    {
      pipe0:for (int_t  _ci17 = 0; (_ci17 <= (_ct17 - 1)); _ci17 = (_ci17 + 1))
      {
    	  if( !Ixx_out_stream.empty() && !Iyy_out_stream.empty() ){
    		data4_t Ixx_in_val = Ixx_out_stream.read();
    		data5_t Iyy_in_val = Iyy_out_stream.read();
    		data6_t k =data6_t(aplhaSquare) + data6_t(Ixx_in_val) + data6_t(Iyy_in_val);
			denom_out_stream.write( k);

			
    	  }
	  }
    }

  const int  _ct19 = (R);
  const int  _ct20 = (C);

  hls::stream<data7_t> commonX_out_stream("commonx7");
  hls::stream<data2_t> Ix_common_0_stream("ix_common7");

 // cout << denom_out_stream.size() << endl;
  //cout << Ix_commonX_stream.size() << endl;
  hls::stream<data6_t> denom_commonY_stream;
    for (int_t  _ci19 = 0; (_ci19 <= (_ct19 - 1)); _ci19 = (_ci19 + 1))
    {
      pipe4:for (int_t  _ci20 = 0; (_ci20 <= (_ct20 - 1)); _ci20 = (_ci20 + 1))
      {
        if(!denom_out_stream.empty() && !Ix_commonX_stream.empty()){
        	data6_t denom_in_val = denom_out_stream.read();
        	data2_t Ix_in_val = Ix_commonX_stream.read();
			data7_t out_val = ( Ix_in_val/denom_in_val);
			commonX_out_stream.write(out_val);
			Ix_common_0_stream.write(Ix_in_val);
			denom_commonY_stream.write(denom_in_val);
        }
	  }
    }
  
  const int  _ct22 = (R);
  const int  _ct23 = (C);
  hls::stream<data8_t> commonY_out_stream("commony8");
  hls::stream<data3_t> Iy_common_0_stream("iy_common8");

    for (int_t  _ci22 = 0; (_ci22 <= (_ct22 - 1)); _ci22 = (_ci22 + 1))
    {
      pipe8:for (int_t  _ci23 = 0; (_ci23 <= (_ct23 - 1)); _ci23 = (_ci23 + 1))
      {
    	  if( !Iy_commonY_stream.empty() && !denom_commonY_stream.empty() ){
			data3_t Iy_in_val = Iy_commonY_stream.read();
			data6_t denom_in_val = denom_commonY_stream.read();
			data8_t out_val = (Iy_in_val/denom_in_val);
			commonY_out_stream.write(out_val);
			Iy_common_0_stream.write(Iy_in_val);
			
    	  }
	  }
    }

  
  const int  _ct25 = (R);
  const int  _ct26 = (C);

  hls::stream<data9_t> velocityX_0_out_stream("vx9");

  hls::stream<data7_t> commonX_velocityX_stream("cx_vx9");

  hls::stream<data1_t> It_velocityY_0_stream;

    for (int_t  _ci25 = 0; (_ci25 <= (_ct25 - 1)); _ci25 = (_ci25 + 1))
    {
      pipe9:for (int_t  _ci26 = 0; (_ci26 <= (_ct26 - 1)); _ci26 = (_ci26 + 1))
      {
    	  if(!It_out_stream.empty() && !commonX_out_stream.empty()){
			data1_t It_in_val = It_out_stream.read();
			data7_t commonX_in_val = commonX_out_stream.read();
			data9_t k = -1*It_in_val * commonX_in_val;
			velocityX_0_out_stream.write(k);
			commonX_velocityX_stream.write(commonX_in_val);
			It_velocityY_0_stream.write(It_in_val);
			
    	  }
	    }
    }

  const int  _ct28 = (R);
  const int  _ct29 = (C);
 
  hls::stream<data10_t> velocityY_0_out_stream("vy10");
  hls::stream<data8_t> commonY_velocityY_stream("cy_vy10");

  hls::stream<data1_t> It_common_0_stream("it_common10");

    for (int_t  _ci28 = 0; (_ci28 <= (_ct28 - 1)); _ci28 = (_ci28 + 1))
    {
      pipe11:for (int_t  _ci29 = 0; (_ci29 <= (_ct29 - 1)); _ci29 = (_ci29 + 1))
      {
    	  if(!It_velocityY_0_stream.empty() && !commonY_out_stream.empty() ){
			data1_t It_in_val = It_velocityY_0_stream.read();
			data8_t commonY_in_val = commonY_out_stream.read();
			data10_t k = -1*It_in_val * commonY_in_val;
			velocityY_0_out_stream.write(k);
			commonY_velocityY_stream.write(commonY_in_val);
			It_common_0_stream.write(It_in_val);
			
    	  }
      }
    }

  hls::stream<data9_t> velocityX_out[3];
  hls::stream<data10_t> velocityY_out[3];
  hls::stream<data2_t> Ix_out[3];
  hls::stream<data3_t> Iy_out[3];
  hls::stream<data1_t> It_out[3];
  hls::stream<data7_t> commonX_out[3];
  hls::stream<data8_t> commonY_out[3];


  iterationMiddle(velocityX_0_out_stream,velocityY_0_out_stream,Ix_common_0_stream,Iy_common_0_stream,It_common_0_stream,
		  commonX_velocityX_stream,commonY_velocityY_stream,
  		velocityX_out[0],velocityY_out[0],Ix_out[0],Iy_out[0],It_out[0],commonX_out[0],commonY_out[0]);


  iterationMiddle(velocityX_out[0],velocityY_out[0],Ix_out[0],Iy_out[0],It_out[0],commonX_out[0],commonY_out[0],
    		velocityX_out[1],velocityY_out[1],Ix_out[1],Iy_out[1],It_out[1],commonX_out[1],commonY_out[1]);

  iterationMiddle(velocityX_out[1],velocityY_out[1],Ix_out[1],Iy_out[1],It_out[1],commonX_out[1],commonY_out[1],
		  velocityX_out[2],velocityY_out[2],Ix_out[2],Iy_out[2],It_out[2],commonX_out[2],commonY_out[2]);

  finalIteration(velocityX_out[2],velocityY_out[2],Ix_out[2],Iy_out[2],It_out[2],commonX_out[2],commonY_out[2],
  		  velocityX,velocityY);

}

void finalIteration(hls::stream<data9_t> & velocityX,hls::stream<data10_t> & velocityY,hls::stream<data2_t> & Ix,
		hls::stream<data3_t> & Iy,hls::stream<data1_t> & It,hls::stream<data7_t> & commonX,hls::stream<data8_t> & commonY,
		hls::stream<data9_t> & velocityX_out,hls::stream<data10_t> & velocityY_out)
{
		  const int  _ct31 = (R);
		  const int  _ct32 = (C);
		  hls::stream<data9_t> averageX_0_out_stream;
		  data9_t  averageX_0_velocityX_0_LBuffer[3][_ct32];
		  data9_t  averageX_0_velocityX_0_WBuffer[3][3];
		 
		    for (int_t  _ci31 = 0; (_ci31 <= (_ct31 - 1)); _ci31 = (_ci31 + 1))
		    {
		      pipe10:for (int_t  _ci32 = 0; (_ci32 <= (_ct32 - 1)); _ci32 = (_ci32 + 1))
		      {

		    	  if(!velocityX.empty()){
					data9_t velocityX_0_in_val = velocityX.read();
					for(int_t i=0;i<3-1;i++){
						averageX_0_velocityX_0_LBuffer[i][_ci32] = averageX_0_velocityX_0_LBuffer[i+1][_ci32];
					}
					averageX_0_velocityX_0_LBuffer[2][_ci32] = velocityX_0_in_val;

					for(int_t i=0;i<3;i++){
						for(int_t j=0;j<2;j++){
							averageX_0_velocityX_0_WBuffer[i][j] = averageX_0_velocityX_0_WBuffer[i][j+1];
						}
					}
					for(int_t i=0;i<3;i++){
						averageX_0_velocityX_0_WBuffer[i][2] = averageX_0_velocityX_0_LBuffer[i][_ci32];
					}

					if(_ci32>=3-1 && _ci31>=3-1)
					{
						data9_t k = (averageX_0_velocityX_0_WBuffer[0][1] + averageX_0_velocityX_0_WBuffer[1][0] +
								averageX_0_velocityX_0_WBuffer[1][2] + averageX_0_velocityX_0_WBuffer[2][1]) ;
						averageX_0_out_stream.write(k/4);
						
						
					}
					else
						averageX_0_out_stream.write(velocityX_0_in_val);
		    	  }
		      }
		    }
		  const int  _ct34 = (R);
		  const int  _ct35 = (C);
		  hls::stream<data10_t> averageY_0_out_stream;
		  data10_t  averageY_0_velocityY_0_LBuffer[3][_ct35];
		  data10_t  averageY_0_velocityY_0_WBuffer[3][3];

	
		    for (int_t  _ci34 = 0; (_ci34 <= (_ct34 - 1)); _ci34 = (_ci34 + 1))
		    {
		      pipe12:for (int_t  _ci35 = 0; (_ci35 <= (_ct35 - 1)); _ci35 = (_ci35 + 1))
		      {
		    	  if(!velocityY.empty()){
					data10_t velocityY_0_in_val = velocityY.read();
					for(int_t i=0;i<3-1;i++){
						averageY_0_velocityY_0_LBuffer[i][_ci35] = averageY_0_velocityY_0_LBuffer[i+1][_ci35];
					}
					averageY_0_velocityY_0_LBuffer[2][_ci35] = velocityY_0_in_val;

					for(int_t i=0;i<3;i++){
						for(int_t j=0;j<2;j++){
							averageY_0_velocityY_0_WBuffer[i][j] = averageY_0_velocityY_0_WBuffer[i][j+1];
						}
					}
					for(int_t i=0;i<3;i++){
						averageY_0_velocityY_0_WBuffer[i][2] = averageY_0_velocityY_0_LBuffer[i][_ci35];
					}

					if(_ci35>=3-1 && _ci34>=3-1)
					{
						data10_t k = (averageY_0_velocityY_0_WBuffer[0][1] + averageY_0_velocityY_0_WBuffer[1][0] +
								averageY_0_velocityY_0_WBuffer[1][2] + averageY_0_velocityY_0_WBuffer[2][1]);
						averageY_0_out_stream.write( k/4);
						
					}
					else 
						averageY_0_out_stream.write(velocityY_0_in_val);
				  }
		      }
		    }
		  
		
		  const int  _ct37 = (R);
		  const int  _ct38 = (C);
		  hls::stream<data11_t> common_0_out_stream;
		  hls::stream<data9_t> avgX;
		  hls::stream<data10_t> avgY;
		
		    for (int_t  _ci37 = 0; (_ci37 <= (_ct37 - 1)); _ci37 = (_ci37 + 1))
		    {
		      pipe1:for (int_t  _ci38 = 0; (_ci38 <= (_ct38 - 1)); _ci38 = (_ci38 + 1))
		      {
		    	  if(!Iy.empty() && !Ix.empty()){
					data3_t Iy_in_val = Iy.read();
					data2_t Ix_in_val = Ix.read();
					data9_t averageX_0_in_val = averageX_0_out_stream.read();
					data1_t It_in_val = It.read();
					data10_t averageY_0_in_val = averageY_0_out_stream.read();
					data11_t k = data11_t(Ix_in_val * averageX_0_in_val) + data11_t(Iy_in_val * averageY_0_in_val) + data11_t(It_in_val);
					
					common_0_out_stream.write(k);
					avgX.write(averageX_0_in_val);
					avgY.write(averageY_0_in_val);
		    	  }
			  }
		    }
		
		  const int  _ct40 = (R);
		  const int  _ct41 = (C);
		  hls::stream<data11_t> common_0_velocityY_stream;
		
		    for (int_t  _ci40 = 0; (_ci40 <= (_ct40 - 1)); _ci40 = (_ci40 + 1))
		    {
		      pipe13:for (int_t  _ci41 = 0; (_ci41 <= (_ct41 - 1)); _ci41 = (_ci41 + 1))
		      {

		    	  if(!common_0_out_stream.empty() && !commonX.empty() ){
					data11_t common_0_in_val = common_0_out_stream.read();
					data7_t commonX_in_val = commonX.read();
					data9_t k = avgX.read() - data9_t(commonX_in_val * common_0_in_val);
					velocityX_out.write(k);
					
					common_0_velocityY_stream.write(common_0_in_val);
		    	  }
			  }
		    }
		  const int  _ct43 = (R);
		  const int  _ct44 = (C);
		
		    for (int_t  _ci43 = 0; (_ci43 <= (_ct43 - 1)); _ci43 = (_ci43 + 1))
		    {
		      pipe7:for (int_t  _ci44 = 0; (_ci44 <= (_ct44 - 1)); _ci44 = (_ci44 + 1))
		      {
		    	  if(!common_0_velocityY_stream.empty() && !commonY.empty()){
					data11_t common_0_in_val = common_0_velocityY_stream.read();
					data8_t commonY_in_val = commonY.read();
					data10_t k = avgY.read() - data10_t(commonY_in_val * common_0_in_val);
					velocityY_out.write(k);
					
		    	  }
			  }
		    }
		 
}


void iterationMiddle(hls::stream<data9_t> & velocityX,hls::stream<data10_t> & velocityY,hls::stream<data2_t> & Ix,
		hls::stream<data3_t> & Iy,hls::stream<data1_t> & It,hls::stream<data7_t> & commonX,hls::stream<data8_t> & commonY,
		hls::stream<data9_t> & velocityX_out,hls::stream<data10_t> & velocityY_out,hls::stream<data2_t> & Ix_out,
				hls::stream<data3_t> & Iy_out,hls::stream<data1_t> & It_out,hls::stream<data7_t> & commonX_out,
				hls::stream<data8_t> & commonY_out)
{
	  const int  _ct31 = (R);
	  const int  _ct32 = (C);
	  hls::stream<data9_t> averageX_0_out_stream;
	  data9_t  averageX_0_velocityX_0_LBuffer[3][_ct32];
	  data9_t  averageX_0_velocityX_0_WBuffer[3][3];
	 
	    for (int_t  _ci31 = 0; (_ci31 <= (_ct31 - 1)); _ci31 = (_ci31 + 1))
	    {
	      pipe10:for (int_t  _ci32 = 0; (_ci32 <= (_ct32 - 1)); _ci32 = (_ci32 + 1))
	      {
	    	  if(!velocityX.empty()){
				data9_t velocityX_0_in_val = velocityX.read();
				for(int_t i=0;i<3-1;i++){
					averageX_0_velocityX_0_LBuffer[i][_ci32] = averageX_0_velocityX_0_LBuffer[i+1][_ci32];
				}
				averageX_0_velocityX_0_LBuffer[2][_ci32] = velocityX_0_in_val;

				for(int_t i=0;i<3;i++){
					for(int_t j=0;j<2;j++){
						averageX_0_velocityX_0_WBuffer[i][j] = averageX_0_velocityX_0_WBuffer[i][j+1];
					}
				}
				for(int_t i=0;i<3;i++){
					averageX_0_velocityX_0_WBuffer[i][2] = averageX_0_velocityX_0_LBuffer[i][_ci32];
				}

				if(_ci32>=3-1 && _ci31>=3-1)
				{
					data9_t k = (averageX_0_velocityX_0_WBuffer[0][1] + averageX_0_velocityX_0_WBuffer[1][0] +
							averageX_0_velocityX_0_WBuffer[1][2] + averageX_0_velocityX_0_WBuffer[2][1]);
					averageX_0_out_stream.write( k/4);
					
				}
				else 
					averageX_0_out_stream.write(velocityX_0_in_val);
	    	  }
	      }
	    }
	  
	  
	  const int  _ct34 = (R);
	  const int  _ct35 = (C);
	  hls::stream<data10_t> averageY_0_out_stream;
	  data10_t  averageY_0_velocityY_0_LBuffer[3][_ct35];
	  data10_t  averageY_0_velocityY_0_WBuffer[3][3];

	  
	    for (int_t  _ci34 = 0; (_ci34 <= (_ct34 - 1)); _ci34 = (_ci34 + 1))
	    {
	      pipe12:for (int_t  _ci35 = 0; (_ci35 <= (_ct35 - 1)); _ci35 = (_ci35 + 1))
	      {
	    	  if(! velocityY.empty()){
				data10_t velocityY_0_in_val = velocityY.read();
				for(int_t i=0;i<3-1;i++){
					averageY_0_velocityY_0_LBuffer[i][_ci35] = averageY_0_velocityY_0_LBuffer[i+1][_ci35];
				}
				averageY_0_velocityY_0_LBuffer[2][_ci35] = velocityY_0_in_val;

				for(int_t i=0;i<3;i++){
					for(int_t j=0;j<2;j++){
						averageY_0_velocityY_0_WBuffer[i][j] = averageY_0_velocityY_0_WBuffer[i][j+1];
					}
				}
				for(int_t i=0;i<3;i++){
					averageY_0_velocityY_0_WBuffer[i][2] = averageY_0_velocityY_0_LBuffer[i][_ci35];
				}

				if(_ci35>=3-1 && _ci34>=3-1)
				{
					data10_t k = (averageY_0_velocityY_0_WBuffer[0][1] + averageY_0_velocityY_0_WBuffer[1][0] +
							averageY_0_velocityY_0_WBuffer[1][2] + averageY_0_velocityY_0_WBuffer[2][1]);
					averageY_0_out_stream.write( k/4);
				
				}
				else 
					averageY_0_out_stream.write(velocityY_0_in_val);
	    	  }
	      }
	    }

	  const int  _ct37 = (R);
	  const int  _ct38 = (C);
	  hls::stream<data11_t> common_0_out_stream;
	  hls::stream<data9_t> avgX;
	  hls::stream<data10_t> avgY;
	 
	    for (int_t  _ci37 = 0; (_ci37 <= (_ct37 - 1)); _ci37 = (_ci37 + 1))
	    {
	      pipe1:for (int_t  _ci38 = 0; (_ci38 <= (_ct38 - 1)); _ci38 = (_ci38 + 1))
	      {
	    	  if(!Iy.empty() && !Ix.empty()){
				data3_t Iy_in_val = Iy.read();
				data2_t Ix_in_val = Ix.read();
				data9_t averageX_0_in_val = averageX_0_out_stream.read();
				data1_t It_in_val = It.read();
				data10_t averageY_0_in_val = averageY_0_out_stream.read();
				data11_t k = data11_t(Ix_in_val * averageX_0_in_val) + data11_t(Iy_in_val * averageY_0_in_val) + data11_t(It_in_val);
				
				common_0_out_stream.write(k);
				Ix_out.write(Ix_in_val);
				Iy_out.write(Iy_in_val);
				It_out.write(It_in_val);
				avgX.write( averageX_0_in_val);
				avgY.write( averageY_0_in_val);
	    	  }
	      }
	    }
	  
	  const int  _ct39 = 3;
	  const int  _ct40 = (R);
	  const int  _ct41 = (C);
	  hls::stream<data11_t> common_0_velocityY_stream;
	  
	    for (int_t  _ci40 = 0; (_ci40 <= (_ct40 - 1)); _ci40 = (_ci40 + 1))
	    {
	      pipe13:for (int_t  _ci41 = 0; (_ci41 <= (_ct41 - 1)); _ci41 = (_ci41 + 1))
	      {

	    	  if(!common_0_out_stream.empty() && !commonX.empty() ){
				data11_t common_0_in_val = common_0_out_stream.read();
				data7_t commonX_in_val = commonX.read();
				data9_t k = avgX.read()  - data9_t(commonX_in_val * common_0_in_val);
				velocityX_out.write(k);
				common_0_velocityY_stream.write(common_0_in_val);
				commonX_out.write(commonX_in_val);
	    	  }
		  }
	    }

	 
	  const int  _ct43 = (R);
	  const int  _ct44 = (C);
	 
	    for (int_t  _ci43 = 0; (_ci43 <= (_ct43 - 1)); _ci43 = (_ci43 + 1))
	    {
	      pipe7:for (int_t  _ci44 = 0; (_ci44 <= (_ct44 - 1)); _ci44 = (_ci44 + 1))
	      {
	    	  if(!common_0_velocityY_stream.empty() && !commonY.empty()){
				data11_t common_0_in_val = common_0_velocityY_stream.read();
				data8_t commonY_in_val = commonY.read();
				data10_t k = avgY.read()  - data10_t(commonY_in_val * common_0_in_val);
				
				velocityY_out.write(k);
				commonY_out.write(commonY_in_val);
	    	  }
	      }
	    }
	  

}


