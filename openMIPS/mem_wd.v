module ex_mem(
    input clk,
    input rst_, 

    input [4:0] mem_wd,
    input mem_wreg,
    input [31:0] mem_wdata,

    output reg [4:0] wb_wd,
    output reg wb_wreg,
    output reg [31:0] wb_wdata,
);

dr_reg #(5) wd_reg    (.d(mem_wd), .q(wb_wd), .*);
dr_reg #(1) wreg_reg  (.d(mem_wreg), .q(wb_wreg), .*);
dr_reg #(31) wdata_reg(.d(mem_wdata), .q(wb_wdata), .*);

endmodule
