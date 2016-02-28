
`define TURE        1'b1
`define FALSE       1'b0

// for EX
// op
`define EXE_OP_NOP  8'd0

`define EXE_OP_OR   8'd1
`define EXE_OP_AND  8'd2
`define EXE_OP_NOR  8'd3
`define EXE_OP_XOR  8'd4

`define EXE_OP_SLL  8'd5
`define EXE_OP_SRL  8'd6
`define EXE_OP_SRA  8'd7

// sel
`define EXE_RES_NOP   3'd0
`define EXE_RES_LOGIC 3'd1
`define EXE_RES_SHIFT 3'd2

// FOR ID
// OP (31:26) inst: 31-29 group 28-26 index
`define INS_OP_GRP_BASIC    3'd0
`define INS_OP_GRP_IMM      3'd1
`define INS_OP_GRP_TLB      3'd2
`define INS_OP_GRP_LOAD     3'd4
`define INS_OP_GRP_RESEVE   3'd4
`define INS_OP_GRP_STORE    3'd5
`define INS_OP_GRP_FPLD     3'd6
`define INS_OP_GRP_FPST     3'd7

// OP=6'b0 FUNC(5:0) for R-format 
`define INS_FUNC_GRP_SHT    3'd0
`define INS_FUNC_GRP_JMP    3'd1
`define INS_FUNC_GRP_MTH    3'd2
`define INS_FUNC_GRP_MUL    3'd3
`define INS_FUNC_GRP_BAS    3'd4
`define INS_FUNC_GRP_SET    3'd5

