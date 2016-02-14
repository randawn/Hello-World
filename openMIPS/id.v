module id(
    input rst_,
    input [31:0] id_i_pc,
    input [31:0] id_i_inst,
    input [31:0] reg0_data,
    input [31:0] reg1_data,

    output reg reg0_read,
    output reg reg1_read,
    output reg [4:0] reg0_addr,
    output reg [4:0] reg1_addr,

    output reg [7:0] id_o_alu_op,
    output reg [2:0] id_o_alu_sel,
    output reg [31:0] id_o_reg0,
    output reg [31:0] id_o_reg1,
    output reg [4:0] id_o_waddr,
    output reg id_o_wreg
);

// R type
wire [5:0] op = id_i_inst[31:26];
wire [4:0] rs = id_i_inst[25:21];
wire [4:0] rt = id_i_inst[20:16];
wire [4:0] rd = id_i_inst[15:11];
wire [4:0] sa = id_i_inst[10:6];
wire [5:0] func = id_i_inst[5:0];
// I type
wire [15:0] imme = id_i_inst[15:0];
// J type
wire [25:0] addr = id_i_inst[25:0];

reg inst_vld;

assign reg0_addr = rt;
assign reg1_addr = rs;
// DECODE
always @* begin
    if (!rst_) begin
        reg0_read = 'b0;
        reg1_read = 'b0;

        id_o_alu_op = 'b0;
        id_o_alu_sel = 'b0;
        id_o_reg0 = 'b0;
        id_o_reg1 = 'b0;
        id_o_waddr = 'b0;
        id_o_wreg = 'b0;
    end else begin
        case (op)
            `EXE_ORI: begin
                id_o_wreg = 'b1;
                id_o_alu_op = `EXE_OR_OP;
                id_o_alu_sel = `EXE_RES_LOGIC;
                reg0_read = 'b1;
                id_o_waddr = rt;
            end
            default: begin
            end
        endcase
    end
end

// SRC0
always @* begin
    if (!rst_) begin
        id_o_reg0 = 'b0;
    end else if (reg0_read) begin
        id_o_reg0 = reg0_data;
    end else if (!reg0_read) begin
        id_o_reg0 = imme;
    end else begin
        id_o_reg0 = 'b0;
    end
end
// SRC1
always @* begin
    if (!rst_) begin
        id_o_reg1 = 'b0;
    end else if (reg1_read) begin
        id_o_reg1 = reg1_data;
    end else if (!reg1_read) begin
        id_o_reg1 = imme;
    end else begin
        id_o_reg1 = 'b0;
    end
end

endmodule
