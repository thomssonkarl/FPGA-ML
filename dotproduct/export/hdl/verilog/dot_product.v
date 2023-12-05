// ==============================================================
// Generated by Vitis HLS v2023.2
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="dot_product_dot_product,hls_ip_2023_2,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z007s-clg225-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.912000,HLS_SYN_LAT=-1,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=1367,HLS_SYN_LUT=1178,HLS_VERSION=2023_2}" *)

module dot_product (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        arr1_address0,
        arr1_ce0,
        arr1_q0,
        arr2_address0,
        arr2_ce0,
        arr2_q0,
        result_address0,
        result_ce0,
        result_we0,
        result_d0,
        height,
        width
);

parameter    ap_ST_fsm_state1 = 6'd1;
parameter    ap_ST_fsm_state2 = 6'd2;
parameter    ap_ST_fsm_state3 = 6'd4;
parameter    ap_ST_fsm_state4 = 6'd8;
parameter    ap_ST_fsm_state5 = 6'd16;
parameter    ap_ST_fsm_state6 = 6'd32;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [16:0] arr1_address0;
output   arr1_ce0;
input  [31:0] arr1_q0;
output  [16:0] arr2_address0;
output   arr2_ce0;
input  [31:0] arr2_q0;
output  [16:0] result_address0;
output   result_ce0;
output   result_we0;
output  [31:0] result_d0;
input  [31:0] height;
input  [31:0] width;

reg ap_done;
reg ap_idle;
reg ap_ready;

(* fsm_encoding = "none" *) reg   [5:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [38:0] grp_fu_62_p2;
reg   [38:0] mul_ln6_reg_86;
wire    ap_CS_fsm_state2;
wire    ap_CS_fsm_state3;
wire   [70:0] grp_fu_58_p2;
reg   [70:0] mul_ln6_1_reg_102;
wire    ap_CS_fsm_state4;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_done;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_idle;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_ready;
wire   [16:0] grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_address0;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_ce0;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_we0;
wire   [31:0] grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_d0;
wire   [16:0] grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr1_address0;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr1_ce0;
wire   [16:0] grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr2_address0;
wire    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr2_ce0;
reg    grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start_reg;
reg   [5:0] ap_NS_fsm;
wire    ap_NS_fsm_state5;
wire    ap_CS_fsm_state6;
wire   [31:0] grp_fu_58_p0;
wire   [38:0] grp_fu_58_p1;
wire   [31:0] grp_fu_62_p0;
wire   [7:0] grp_fu_62_p1;
reg    ap_ST_fsm_state1_blk;
wire    ap_ST_fsm_state2_blk;
wire    ap_ST_fsm_state3_blk;
wire    ap_ST_fsm_state4_blk;
wire    ap_ST_fsm_state5_blk;
reg    ap_ST_fsm_state6_blk;
wire   [70:0] grp_fu_58_p00;
wire   [70:0] grp_fu_58_p10;
wire   [38:0] grp_fu_62_p00;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 6'd1;
#0 grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start_reg = 1'b0;
end

dot_product_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3 grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start),
    .ap_done(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_done),
    .ap_idle(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_idle),
    .ap_ready(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_ready),
    .mul_ln6_1(mul_ln6_1_reg_102),
    .mul_ln6(mul_ln6_reg_86),
    .result_address0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_address0),
    .result_ce0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_ce0),
    .result_we0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_we0),
    .result_d0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_d0),
    .arr1_address0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr1_address0),
    .arr1_ce0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr1_ce0),
    .arr1_q0(arr1_q0),
    .arr2_address0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr2_address0),
    .arr2_ce0(grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr2_ce0),
    .arr2_q0(arr2_q0)
);

dot_product_mul_32ns_39ns_71_2_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 39 ),
    .dout_WIDTH( 71 ))
mul_32ns_39ns_71_2_1_U12(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_58_p0),
    .din1(grp_fu_58_p1),
    .ce(1'b1),
    .dout(grp_fu_58_p2)
);

dot_product_mul_32ns_8ns_39_2_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 8 ),
    .dout_WIDTH( 39 ))
mul_32ns_8ns_39_2_1_U13(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(grp_fu_62_p0),
    .din1(grp_fu_62_p1),
    .ce(1'b1),
    .dout(grp_fu_62_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start_reg <= 1'b0;
    end else begin
        if (((1'b1 == ap_NS_fsm_state5) & (1'b1 == ap_CS_fsm_state4))) begin
            grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start_reg <= 1'b1;
        end else if ((grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_ready == 1'b1)) begin
            grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        mul_ln6_1_reg_102 <= grp_fu_58_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        mul_ln6_reg_86 <= grp_fu_62_p2;
    end
end

always @ (*) begin
    if ((ap_start == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

assign ap_ST_fsm_state2_blk = 1'b0;

assign ap_ST_fsm_state3_blk = 1'b0;

assign ap_ST_fsm_state4_blk = 1'b0;

assign ap_ST_fsm_state5_blk = 1'b0;

always @ (*) begin
    if ((grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_done == 1'b0)) begin
        ap_ST_fsm_state6_blk = 1'b1;
    end else begin
        ap_ST_fsm_state6_blk = 1'b0;
    end
end

always @ (*) begin
    if (((grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state6))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state6))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            if (((grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state6))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_NS_fsm_state5 = ap_NS_fsm[32'd4];

assign arr1_address0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr1_address0;

assign arr1_ce0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr1_ce0;

assign arr2_address0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr2_address0;

assign arr2_ce0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_arr2_ce0;

assign grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_ap_start_reg;

assign grp_fu_58_p0 = grp_fu_58_p00;

assign grp_fu_58_p00 = height;

assign grp_fu_58_p1 = grp_fu_58_p10;

assign grp_fu_58_p10 = mul_ln6_reg_86;

assign grp_fu_62_p0 = grp_fu_62_p00;

assign grp_fu_62_p00 = width;

assign grp_fu_62_p1 = 39'd100;

assign result_address0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_address0;

assign result_ce0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_ce0;

assign result_d0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_d0;

assign result_we0 = grp_dot_product_Pipeline_VITIS_LOOP_7_1_VITIS_LOOP_8_2_VITIS_LOOP_10_3_fu_46_result_we0;

endmodule //dot_product
