module top;
import rps_env_pkg::*;

bit r1, p1, s1;
bit r2, p2, s2;
int score1, score2;
bit go1, go2;
bit clk, rst, dut_busy;

rps_clk_reset cr(.clk(clk), .rst(rst));

rps_dut dut(
    .r1(r1), .r2(r2),
    .p1(p1), .p2(p2),
    .s1(s1), .s2(s2),
    .score1(score1), .score2(score2),
    .go1(go1), .go2(go2),
    .clk(clk),
    .rst(rst),
    .dut_busy(dut_busy));

rps_env env;

initial begin
    env = new();
    fork
        cr.run();
    join_none
    env.execute();
    $stop();
end
endmodule
