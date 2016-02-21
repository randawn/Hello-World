module regfile(
    input clk,
    input rst_,
    input we,
    input [4:0] waddr,
    input [31:0] wdata,
    input re0,
    input [4:0] raddr0,
    output [31:0] rdata0,
    input re1,
    input [4:0] raddr1,
    output [31:0] rdata1
);

reg [31:0] regs [0:31];

always @(posedge clk) begin
    if (we && (waddr!=0)) begin
        regs[waddr] <= #1 wdata;
    end
end

assign rdata0 = !rst_ ? 'b0:
                !re0  ? 'b0:
                (raddr0=='b0) ? 'b0:
                ((raddr0==waddr) && we) ? wdata:
                                   regs[raddr0];
assign rdata1 = !rst_ ? 'b0:
                !re1  ? 'b0:
                (raddr1=='b0) ? 'b0:
                ((raddr1==waddr) && we) ? wdata:
                                   regs[raddr1];

endmodule
