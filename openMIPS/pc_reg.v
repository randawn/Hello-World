module pc_reg(
    input   clk,
    input   rst_,
    output  reg [31:0] if_o_pc,
    output  reg if_o_pc_vld
);

wire [31:0] if_o_pc_next = if_o_pc + 'd4;
dr_reg #(32) if_o_pc_reg(.d(if_o_pc_next), .q(if_o_pc), .*);

wire if_o_pc_vld_next = 'b1;
dr_reg #(1) if_o_pc_vld_reg(.d(if_o_pc_vld), .q(if_o_pc_vld_next), .*);

endmodule
