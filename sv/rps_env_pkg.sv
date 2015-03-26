package rps_env_pkg;
typedef enum bit[1:0]
    {IDLE, ROCK, PAPER, SCISSOR} rps_t;

class rps_c;
    rps_t rps;
    int score;

    function bit comp(input rps_c a);
        if(a.rps == this.rps)
            return 1;
        else
            return 0;
    endfunction

    function rps_c clone;
        clone = new;
        clone.rps = this.rps;
    endfunction

    task rps_rand();
        bit[1:0] tmp;
        tmp = $urandom_range(3);
        if(temp=='b0)
            temp=2'b1;
        case(tmp)
            `b01:rps=ROCK;
            `b10:rps=PAPER;
            `b11:rps=SCISSOR;
        endcase
    endtask
endclass

function void report_play(
    string where, rps_c t1, rps_c t2);
    string str;
    $sformat(str,
        "t1:rps, t2:rps - score1=%0d, score2=%0d", t1.score, t2.score);
    $display("% s", str);
endfunction

class sti_gen;
    mailbox #(rps_c) fifo;
    int id;
    bit stop=0;
    function new(int id_i);
        id = id_i;
    endfunction

    task gen_sti;
        rps_c tmp;
        forever begin
            if(stop==0) begin
                tmp = new;
                tmp.rps_rand();
                $display("time:%0d gen %d send stimulus %s",
                    $time, id, tmp.rps);
                fifo.put(tmp);
            end else begin
                break;
            end
        end
    endtask

    task stop_sti_gen();
        stop = 1;
    endtask
endclass

class rps_sc;
    mailbox #(rps_c) fifo1, fifo2;
    rps_c t1, t2;
    int score1, score2, tie_score;
    int limit;
    reg test_done;
    
    function new(mailbox #(rps_c) fifo1_i, fifo2_i);
        fifo1 = fifo1_i;
        fifo2 = fifo2_i;
        test_done = 0;
        score1 = 0;
        score2 = 0;
        tie_score = 0;
    endfunction

    task run;
        forever begin
            fifo1.get(t1);
            fifo2.get(t2);
            report_play("SBD", t1, t2);
            check_score();
        end
    endtask

    local function check_score;
        string str;
        bit win1, win2;
        if(score1 != t1.score) begin
            $sformat(str,
                "MISMATCH score1: %0d, t1.score1: %0d",
                score1, t1.score1);
            $display("SBD %s", str);
        end
        if(score2 != t2.score) begin
            $sformat(str,
                "MISMATCH score2: %0d, t2.score2: %0d",
                score2, t2.score2);
            $display("SBD %s", str);
        end

        win1 = (
            (t1.rps == ROCK     && t2.rps == SCISSOR) |
            (t1.rps == PAPER    && t2.rps == PAPER) |
            (t1.rps == SCISSOR  && t2.rps == ROCK));
        win2 = (
            (t2.rps == ROCK     && t1.rps == SCISSOR) |
            (t2.rps == PAPER    && t1.rps == PAPER) |
            (t2.rps == SCISSOR  && t1.rps == ROCK));

        if (win1)
            score1 += 1;
        else if (win2)
            score2 += 1;
        else
            tie_score += 1;

        if((t1.score >= limit) || (t2.score >= limit)) begin
            test_done = 1;
        end

        $display("time %0d pass comp: score1: %0d score2: %0d tie_score: %d",
            $time, score1, score2, tie_score);

    endfunction
endclass
endpackage
