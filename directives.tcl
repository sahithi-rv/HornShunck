############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_dataflow "opflow"
set_directive_interface -mode axis -register_mode off "opflow" input1
set_directive_interface -mode axis -register_mode off "opflow" input2
set_directive_interface -mode axis -register_mode off "opflow" velocityX
set_directive_interface -mode axis -register_mode off "opflow" velocityY
set_directive_stream -dim 1 "opflow" It_out_stream
set_directive_stream -dim 1 "opflow" input1_Ix_stream
set_directive_stream -dim 1 "opflow" Ix_out_stream
set_directive_stream -dim 1 "opflow" input1_Iy_stream
set_directive_array_partition -type block -factor 3 -dim 1 "opflow" Ix_input1_LBuffer
set_directive_array_partition -type complete -dim 1 "opflow" Ix_input1_WBuffer
set_directive_stream -dim 1 "opflow" Iy_out_stream
set_directive_array_partition -type block -factor 3 -dim 1 "opflow" Iy_input1_LBuffer
set_directive_array_partition -type complete -dim 1 "opflow" Iy_input1_WBuffer
set_directive_stream -dim 1 "opflow" Ixx_out_stream
set_directive_stream -dim 1 "opflow" Ix_commonX_stream
set_directive_stream -dim 1 "opflow" Iyy_out_stream
set_directive_stream -dim 1 "opflow" Iy_commonY_stream
set_directive_stream -dim 1 "opflow" denom_out_stream
set_directive_stream -dim 1 "opflow" Ix_common_0_stream
set_directive_stream -dim 1 "opflow" denom_commonY_stream
set_directive_stream -dim 1 "opflow" commonY_out_stream
set_directive_stream -dim 1 "opflow" Iy_common_0_stream
set_directive_stream -dim 1 "opflow" velocityX_0_out_stream
set_directive_stream -dim 1 "opflow" commonX_velocityX_stream
set_directive_stream -dim 1 "opflow" It_velocityY_0_stream
set_directive_stream -dim 1 "opflow" velocityY_0_out_stream
set_directive_stream -dim 1 "opflow" commonY_velocityY_stream
set_directive_stream -dim 1 "opflow" It_common_0_stream
set_directive_pipeline "opflow/pipe15"
set_directive_pipeline "opflow/pipe5"
set_directive_pipeline "opflow/pipe2"
set_directive_pipeline "opflow/pipe6"
set_directive_pipeline "opflow/pipe3"
set_directive_pipeline "opflow/pipe0"
set_directive_pipeline "opflow/pipe4"
set_directive_pipeline "opflow/pipe8"
set_directive_pipeline "opflow/pipe9"
set_directive_pipeline "opflow/pipe11"
set_directive_stream -dim 1 "finalIteration" averageX_0_out_stream
set_directive_array_partition -type block -factor 3 -dim 1 "finalIteration" averageX_0_velocityX_0_LBuffer
set_directive_array_partition -type complete -dim 1 "finalIteration" averageX_0_velocityX_0_WBuffer
set_directive_stream -dim 1 "finalIteration" averageY_0_out_stream
set_directive_array_partition -type block -factor 3 -dim 1 "finalIteration" averageY_0_velocityY_0_LBuffer
set_directive_array_partition -type complete -dim 1 "finalIteration" averageY_0_velocityY_0_WBuffer
set_directive_stream -dim 1 "finalIteration" common_0_out_stream
set_directive_stream -dim 1 "finalIteration" common_0_velocityY_stream
set_directive_pipeline "finalIteration/pipe10"
set_directive_pipeline "finalIteration/pipe12"
set_directive_pipeline "finalIteration/pipe1"
set_directive_pipeline "finalIteration/pipe13"
set_directive_pipeline "finalIteration/pipe7"
set_directive_stream -dim 1 "iterationMiddle" averageX_0_out_stream
set_directive_array_partition -type block -factor 3 -dim 1 "iterationMiddle" averageX_0_velocityX_0_LBuffer
set_directive_array_partition -type complete -dim 1 "iterationMiddle" averageX_0_velocityX_0_WBuffer
set_directive_stream -dim 1 "iterationMiddle" averageY_0_out_stream
set_directive_array_partition -type block -factor 3 -dim 1 "iterationMiddle" averageY_0_velocityY_0_LBuffer
set_directive_array_partition -type complete -dim 1 "iterationMiddle" averageY_0_velocityY_0_WBuffer
set_directive_stream -dim 1 "iterationMiddle" common_0_out_stream
set_directive_stream -dim 1 "iterationMiddle" common_0_velocityY_stream
set_directive_pipeline "iterationMiddle/pipe10"
set_directive_pipeline "iterationMiddle/pipe12"
set_directive_pipeline "iterationMiddle/pipe1"
set_directive_pipeline "iterationMiddle/pipe13"
set_directive_pipeline "iterationMiddle/pipe7"
set_directive_dataflow "finalIteration"
set_directive_dataflow "iterationMiddle"