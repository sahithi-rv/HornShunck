############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project OpticalFlow
set_top opflow
add_files ./OpticalFlow.cpp
add_files ./OpticalFlow.h
add_files -tb ./main.cpp
add_files -tb ./constants.h
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
#set_part {xc7k160tfbg484-1} -tool vivado
create_clock -period 5 -name default
source "./directives.tcl"
csim_design -compiler gcc
#csynth_design
#export_design -flow syn -rtl verilog -format ip_catalog
exit
