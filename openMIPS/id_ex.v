module id_ex(
    input clk,
    input rst_,
    input [7:0]  id_alu_op,
    input [2:0]  id_alu_sel,
    input [31:0] id_reg0,
    input [31:0] id_reg1,
    input [4:0]  id_wd,
    input id_wreg,

    output reg [7:0]  ex_alu_op,
    output reg [2:0]  ex_alu_sel,
    output reg [31:0] ex_reg0,
    output reg [31:0] ex_reg1,
    output reg [4:0]  ex_wd,
    output reg ex_wreg,
);

dr_reg #(8)  alu_op_reg(.d(id_ alu_op), .q(ex_alu_op), .*);
dr_reg #(3) alu_sel_reg(.d(id_alu_sel), .q(ex_alu_sel), .*);
dr_reg #(32)   reg0_reg(.d(id_reg0),    .q(ex_reg0), .*);
dr_reg #(32)   reg1_reg(.d(id_reg1),    .q(ex_reg1), .*);
dr_reg #(5)      wd_reg(.d(id_wd),      .q(ex_wd), .*);
dr_reg #(1)    wreg_reg(.d(id_wreg),    .q(ex_wreg), .*);

endmodule
