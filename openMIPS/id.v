module id(
    input rst_,
    input [31:0] id_pc,
    input [31:0] id_inst,
    input [31:0] reg0_data,
    input [31:0] reg1_data,

    output reg reg0_read,
    output reg reg1_read,
    output reg [4:0] reg0_addr,
    output reg [4:0] reg1_addr,

    output reg [7:0] id_alu_op,
    output reg [2:0] id_alu_sel,
    output reg [31:0] id_reg0,
    output reg [31:0] id_reg1,
    output reg [4:0] id_wd,
    output reg id_wreg,
);

// R type
wire [5:0] op = id_inst[31:26];
wire [4:0] rs = id_inst[25:21];
wire [4:0] rt = id_inst[20:16];
wire [4:0] rd = id_inst[15:11];
wire [4:0] sa = id_inst[10:6];
wire [5:0] func = id_inst[5:0];
// I type
wire [15:0] imme = id_inst[15:0];
// J type
wire [25:0] addr = id_inst[25:0];

reg inst_vld;

// DECODE
always @* begin
    if (!rst_) begin
        reg0_read = 'b0;
        reg1_read = 'b0;

        id_alu_op = 'b0;
        id_alu_sel = 'b0;
        id_reg0 = 'b0;
        id_reg1 = 'b0;
        id_wd = 'b0;
        id_wreg = 'b0;
    end else begin
        case (op) begin
            `EXE_ORI: begin
                id_wreg = 'b1;
                id_alu_op = `EXE_OR_OP;
                id_alu_sel = `EXE_RES_LOGIC;
                reg0_read = 'b1;
                id_wd = rt;
            end
            default: begin
            end
        end
    end
end

// SRC0
always @* begin
    if (!rst_) begin
        id_reg0 = 'b0;
    end else if (reg0_read) begin
        id_reg0 = reg0_data;
    end else if (!reg0_read) begin
        id_reg0 = imme;
    end else begin
        id_reg0 = 'b0;
    end
end
// SRC1
always @* begin
    if (!rst_) begin
        id_reg1 = 'b0;
    end else if (reg0_read) begin
        id_reg1 = reg0_data;
    end else if (!reg0_read) begin
        id_reg1 = imme;
    end else begin
        id_reg1 = 'b0;
    end
end

endmodule
