module mem(
    input rst_,
    input 

    input [4:0] mem_wd,
    input mem_wreg,
    input [31:0] mem_wdata,

    output reg [4:0] wb_wd,
    output reg wb_wreg,
    output reg [31:0] wb_wdata,
);

always @* begin
    wb_wd = !rst_ ? 'b0 : mem_wd;
    wb_wreg = !rst_ ? 'b0 : mem_wreg;
    wb_wdata = !rst_ ? 'b0 : mem_wdata;
end

endmodule
