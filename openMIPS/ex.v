module ex(
    input rst_,
    
    input [7:0]  ex_i_alu_op,
    input [2:0]  ex_i_alu_sel,
    input [31:0] ex_i_reg0,
    input [31:0] ex_i_reg1,
    input [4:0]  ex_i_waddr,
    input ex_i_wreg,

    output reg ex_o_wreg,
    output reg [4:0] ex_o_waddr,
    output reg [31:0] ex_o_wdata
);

reg [31:0] logicout;

always @* begin
    if (!rst_) begin
        logicout = 'b0;
    end else begin
        case (ex_i_alu_op)
            `EXE_OR_OP: begin
                logicout = ex_i_reg0 | ex_i_reg1;
            end
            default: begin
                logicout = 'b0;
            end
        endcase
    end
end

always @* begin
    if (!rst_) begin
        ex_o_wreg = 'b0;
    end else begin
        ex_o_wreg = ex_i_wreg;
        ex_o_waddr= ex_i_waddr;
        case (ex_i_alu_sel)
            `EXE_RES_LOGIC: begin
                ex_o_wdata = logicout;
            end
            default: begin
                ex_o_wdata = 'b0;
            end
        endcase
    end
end


endmodule
