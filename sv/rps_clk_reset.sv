module rps_clk_reset(
    output bit clk, rst
);
parameter bit ACT_RST = 0;

task run(
    int rst_hold=4,
    int half_period=10);
    clk = 0;
    rst = ACT_RST;
    for(int rst_i=0; rst_i<rst_hold; rst_i++) begin
        #half_period; clk=!clk;
        #half_period; clk=!clk;
    end

    rst = !rst;
    forever begin
        #half_period; clk=!clk;
    end
endtask

endmodule
