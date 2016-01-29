class rps_env;
    sti_gen s1, s2;
    mailbox #(rps_c) f1, f2, ap1, ap2;
    rps_driver1 d1;
    rps_driver2 d2;
    rps_mon1 m1;
    rps_mon2 m2;
    rps_sc sb;

    function new;
        s1 = new(1);
        s2 = new(2);
        f1 = new;
        f2 = new;
        d1 = new;
        d2 = new;
        m1 = new;
        m2 = new;
        ap1 = new;
        ap2 = new;

        sb = new(ap1, ap2);
        sb.limit = 3;

        s1.fifo = f1;
        s2.fifo = f2;
        d1.fifo = f1;
        d2.fifo = f2;
        m1.fifo = ap1;
        m2.fifo = ap2;
    endfunction

    task execute;
        fork
            terminate;
            s1.gen_sti();
            s2.gen_sti();
            d1.run();
            d2.run();
            m1.run();
            m2.run();
            sb.run();
        join
    endtask

    task terminate;
       @(posedge sb.test_done);
       s1.stop_sti_gen();
       s2.stop_sti_gen();
       $display("test finish");
    endtask
endclass
