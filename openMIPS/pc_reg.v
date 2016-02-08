module pc_reg(
    input   clk,
    input   rst_,
    output  reg [31:0] if_pc,
    output  reg if_pc_vld,
);

wire [31:0] if_pc_next = if_pc + 'd4;
dr_reg #(32) if_pc_reg(.d(if_pc_next), .q(if_pc), .*);

wire pc_vld_next = 'b1;
dr_reg #(1) if_pc_vld_reg(.d(if_pc_vld), .q(if_pc_vld_next), .*);

endmodule
