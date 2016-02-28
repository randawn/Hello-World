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
reg [31:0] shiftout;

always @* begin
    if (!rst_) begin
        logicout = 'b0;
    end else begin
        case (ex_i_alu_op)
            `EXE_OP_AND: begin
                logicout = ex_i_reg0 & ex_i_reg1;
            end
            `EXE_OP_OR: begin
                logicout = ex_i_reg0 | ex_i_reg1;
            end
            `EXE_OP_NOR: begin
                logicout = ~(ex_i_reg0 | ex_i_reg1);
            end
            `EXE_OP_XOR: begin
                logicout = ex_i_reg0 ^ ex_i_reg1;
            end
            default: begin
                logicout = 'b0;
            end
        endcase
    end
end

always @* begin
    if (!rst_) begin
        shiftout = 'b0;
    end else begin
        case (ex_i_alu_op)
            `EXE_OP_SLL: begin
                shiftout = ex_i_reg1 << ex_i_reg0;
            end
            `EXE_OP_SRL: begin
                shiftout = ex_i_reg1 >> ex_i_reg0;
            end
            `EXE_OP_SRA: begin
                shiftout = (ex_i_reg1 >> ex_i_reg0) |
                           ((32'hffffffff >> ex_i_reg0) << ex_i_reg0);
            end
            default: begin
                shiftout = 'b0;
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
            `EXE_RES_SHIFT: begin
                ex_o_wdata = shiftout;
            end
            default: begin
                ex_o_wdata = 'b0;
            end
        endcase
    end
end


endmodule
