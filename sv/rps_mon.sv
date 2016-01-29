
class rps_mon1;
    mailbox #(rps_c) fifo;
    function rps_c pin2trans;
        rps_c trans = new;
        case({top.r1, top.p1, top.s1})
            3'b100: trans.rps = ROCK;
            3'b010: trans.rps = PAPER;
            3'b001: trans.rps = SCISSOR;
        endcase
        trans.score = top.score1;
        $display("time:%0d mon 1 got trans %s", $time, trans.rps);
        return trans;
    endfunction

    task run;
        forever @(posedge top.dut_busy)
            fifo.put(pin2trans());
    endtask
endclass

class rps_mon2;
    mailbox #(rps_c) fifo;
    function rps_c pin2trans;
        rps_c trans = new;
        case({top.r2, top.p2, top.s2})
            3'b100: trans.rps = ROCK;
            3'b010: trans.rps = PAPER;
            3'b001: trans.rps = SCISSOR;
        endcase
        trans.score = top.score2;
        $display("time:%0d mon 2 got trans %s", $time, trans.rps);
        return trans;
    endfunction

    task run;
        forever @(posedge top.dut_busy)
            fifo.put(pin2trans());
    endtask
endclass
