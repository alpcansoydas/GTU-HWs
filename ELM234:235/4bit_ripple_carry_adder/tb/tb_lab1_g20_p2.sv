module tb_lab1_g20_p2();
    logic [3:0] A;
    logic [3:0] B;
    logic Cin;
    logic [3:0] Sum;
    logic Cout;
     ripple_carry_adder dut(A,B,Cin,Sum,Cout);    
     initial begin
     A = 4'b0011;B=4'b0011;Cin = 1'b0; #10;
     A = 4'b1011;B=4'b0111;Cin = 1'b1; #10;
     A = 4'b1111;B=4'b1111;Cin = 1'b0; #10;
     end

endmodule