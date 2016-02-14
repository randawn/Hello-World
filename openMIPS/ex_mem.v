module ex_mem(
    input clk,
    input rst_, 

    input [4:0] ex_o_waddr,
    input ex_o_wreg,
    input [31:0] ex_o_wdata,

    output reg [4:0] mem_i_waddr,
    output reg mem_i_wreg,
    output reg [31:0] mem_i_wdata
);

dr_reg #(5) wd_reg    (.d(ex_o_waddr), .q(mem_i_waddr), .*);
dr_reg #(1) wreg_reg  (.d(ex_o_wreg), .q(mem_i_wreg), .*);
dr_reg #(32) wdata_reg(.d(ex_o_wdata), .q(mem_i_wdata), .*);

endmodule
