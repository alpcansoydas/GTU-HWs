`timescale 1ns/1ps

module tb_fsm_moore ();

    logic clk, A;
    logic reset;
    logic unlock;
    logic [15:0] pattern = 19'b1010010011010011; // 2 adet 01001

    fsm_moore fsm_moore(.clk(clk), .reset(reset), .A(A), .unlock(unlock));
    
    always
    begin
        clk = 0; #5; clk = 1; #5;
    end

    initial
    begin
        A = 0; reset = 1; #20;
        reset = 0; #5;
        for (int i=0; i<15; i++) begin
            A = pattern[15];
            pattern = pattern << 1'b1;
            #10;
        end
        #20;
        $stop;
    end

endmodule