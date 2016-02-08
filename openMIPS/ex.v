module ex(
    input rst_,
    
    input [7:0]  ex_alu_op,
    input [2:0]  ex_alu_sel,
    input [31:0] ex_reg0,
    input [31:0] ex_reg1,
    input [4:0]  ex_wd,
    input ex_wreg,

    output reg [4:0] ex_wd_o,
    output reg ex_wreg_o,
    output reg [31:0] ex_wdata_o,
);

reg [31:0] logicout;

always @* begin
    if (!rst_) begin
        logicout = 'b0;
    end else begin
        case (ex_alu_op)
            `EXE_OR_OP: begin
                logicout = ex_reg0 | ex_reg1;
            end
            default: begin
                logicout = 'b0;
            end
        endcase
    end
end

always @* begin
    if (!rst_) begin
        ex_wreg_o = 'b0;
    end else begin
        ex_wreg_o = ex_wreg;
        ex_wd_o = ex_wd;
        case (ex_alu_sel) begin
            `EXE_RES_LOGIC: begin
                ex_wdata_o = logicout;
            end
            default: begin
                ex_wdata_o = 'b0;
            end
        end
    end
end


endmodule
