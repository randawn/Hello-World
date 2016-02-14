module if_id(
    input clk,
    input rst_,
    input [31:0] if_o_pc,
    input [31:0] if_o_inst,
    output reg [31:0] id_i_pc,
    output reg [31:0] id_i_inst
);

dr_reg #(32) pc_reg(.d(if_o_pc), .q(id_i_pc), .*);
dr_reg #(32) inst_reg(.d(if_o_inst), .q(id_i_inst), .*);

endmodule
