module if_id(
    input clk,
    input rst_,
    input [31:0] if_pc,
    input [31:0] if_inst,
    output reg [31:0] id_pc,
    output reg [31:0] id_inst,
);

dr_reg #(32) pc_reg(.d(if_pc), .q(id_pc), .*);
dr_reg #(32) inst_reg(.d(if_inst), .q(id_inst), .*);

endmodule
