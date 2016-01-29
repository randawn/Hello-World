// Rock Paper Scissor arbitrator
module rps_dut(
    input r1, p1, s1,
    input r2, p2, s2,
    output reg [31:0] score1, score2,
    input go1, go2,
    input clk, rst,
    output reg dut_busy);

wire win1 = (r1 & s2) | (s1 & p2) | (p1 & r2);
wire win2 = (r2 & s1) | (s2 & p1) | (p2 & r1);
assign both_ready = go1 & go2;
reg [31:0] tie_score;

always @(posedge clk) begin
    if(!rst) begin
        dut_busy <= 0;
        score1 <= 0;
        score2 <= 0;
        tie_score <= 0;
    end else begin
        if (both_ready) begin
            dut_busy <= 1;
            if(win1)
                score1 <= score1 + 1;
            else if(win2)
                score2 <= score2 + 1;
            else
                tie_score <= tie_score + 1;
        end else begin
            dut_busy <= 0;
        end
    end
end

endmodule
