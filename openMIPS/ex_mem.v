module ex_mem(
    input clk,
    input rst_, 

    input [4:0] ex_wd_o,
    input ex_wreg_o,
    input [31:0] ex_wdata_o,

    output reg [4:0] mem_wd,
    output reg mem_wreg,
    output reg [31:0] mem_wdata,
);

dr_reg #(5) wd_reg    (.d(ex_wd_o), .q(mem_wd), .*);
dr_reg #(1) wreg_reg  (.d(ex_wreg_o), .q(mem_wreg), .*);
dr_reg #(31) wdata_reg(.d(ex_wdata_o), .q(mem_wdata), .*);

endmodule
