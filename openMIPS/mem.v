module mem(
    input rst_,

    input [4:0] mem_i_waddr,
    input mem_i_wreg,
    input [31:0] mem_i_wdata,

    output reg mem_o_wreg,
    output reg [4:0] mem_o_waddr,
    output reg [31:0] mem_o_wdata
);

always @* begin
    mem_o_waddr = !rst_ ? 'b0 : mem_i_waddr;
    mem_o_wreg = !rst_ ? 'b0 : mem_i_wreg;
    mem_o_wdata = !rst_ ? 'b0 : mem_i_wdata;
end

endmodule
