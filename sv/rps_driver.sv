class rps_driver1;
    mailbox #(rps_c) fifo;
    rps_c trans;

    task run;
        top.r1 = 'b0; 
        top.p1 = 'b0; 
        top.s1 = 'b0; 
        top.go1= 'b0;
        @(posedge top.rst);
        forever @(posedge top.clk) begin
            if(fifo.try_get(trans)) begin
                top.r1 = 'b0; 
                top.p1 = 'b0; 
                top.s1 = 'b0; 
                $display("driver 1 get stimulus: %s", trans.rps);
                case(trans.rps)
                    ROCK    :top.r1=1;
                    PAPER   :top.p1=1;
                    SCISSOR :top.s1=1;
                endcase
                top.go1 = 1;
                @(posedge top.clk);
                top.go1 = 0;
                @(posedge top.clk);
                top.r1 = 'b0; 
                top.p1 = 'b0; 
                top.s1 = 'b0; 
            end
        end
    endtask
endclass

class rps_driver2;
    mailbox #(rps_c) fifo;
    rps_c trans;

    task run;
        top.r2 = 'b0; 
        top.p2 = 'b0; 
        top.s2 = 'b0; 
        top.go2= 'b0;
        @(posedge top.rst);
        forever @(posedge top.clk) begin
            if(fifo.try_get(trans)) begin
                top.r2 = 'b0; 
                top.p2 = 'b0; 
                top.s2 = 'b0; 
                $display("driver 2 get stimulus: %s", trans.rps);
                case(trans.rps)
                    ROCK    :top.r2=1;
                    PAPER   :top.p2=1;
                    SCISSOR :top.s2=1;
                endcase
                top.go2 = 1;
                @(posedge top.clk);
                top.go2 = 0;
                @(posedge top.clk);
                top.r2 = 'b0; 
                top.p2 = 'b0; 
                top.s2 = 'b0; 
            end
        end
    endtask
endclass

