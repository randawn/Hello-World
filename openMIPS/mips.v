module mips(
    input clk,
    input rst_,

    input [31:0] inst_data,
    output [31:0] pc,
    output pc_vld,
);

//if_pc,
//if_pc_vld,
pc_reg u_pc_reg(.*);

// if_pc,
if_inst,
// id_pc,
// id_inst,
if_id u_if_id(.*);

//we,
//waddr,
//wdata,
//re0,
//raddr0,
//rdata0,
//re1,
//raddr1,
//rdata1,
regfile u_regfile(
    .re0(reg0_read),
    .raddr0(reg0_addr),
    .rdata0(reg0_data),
    .re1(reg1_read),
    .raddr1(reg1_addr),
    .rdata1(reg1_data),
    .we(wb_wreg),
    .waddr(wb_wd),
    .wdata(wb_wdata),
    .*
);

//id_pc,
//id_inst,

//reg0_data,
//reg1_data,
//reg0_read,
//reg1_read,
//reg0_addr,
//reg1_addr,

//id_alu_op,
//id_alu_sel,
//id_reg0,
//id_reg1,
//id_wd,
//id_wreg,

id u_id(.*);

//id_alu_op,
//id_alu_sel,
//id_reg0,
//id_reg1,
//id_wd,
//id_wreg,

//ex_alu_op,
//ex_alu_sel,
//ex_reg0,
//ex_reg1,
//ex_wd,
//ex_wreg,
id_ex u_id_ex(.*);

//ex_alu_op,
//ex_alu_sel,
//ex_reg0,
//ex_reg1,
//ex_wd,
//ex_wreg,

//ex_wd_o,
//ex_wreg_o,
//ex_wdata_o,
ex u_ex(.*);


//ex_wd_o,
//ex_wreg_o,
//ex_wdata_o,
//mem_wd,
//mem_wreg,
//mem_wdata,
ex_mem u_ex_mem(.*);

//mem_wd,
//mem_wreg,
//mem_wdata,

//wb_wd,
//wb_wreg,
//wb_wdata,
mem u_mem(.*);

endmodule
