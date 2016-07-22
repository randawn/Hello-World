
interface AXI_if(input logic ACLK, input logic ARESETn);
// AW
logic [] AWID;      // group tag
logic [] AWADDR;    // first byte addr of a burst
logic [] AWLEN;
logic [] AWSIZE;
logic [] AWBURST;
logic [] AWLOCK;    // atomic characteristics
logic [] AWCACHEA   // how transactions are required to progress through system
logic [] AWPROT;    // privilege and security level, inst/data
logic [] AWQOS;     // Quality of Service, priority indicator
logic [] AWREGION;
logic [] AWUSER;
logic [] AWVALID;
logic [] AWREADY;
// W
// B
// AR
// R
endinterface

