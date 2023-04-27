`timescale 1ns/1ps

module tb_lab1_g20_p3();
 
    logic A,B,C,D;
    logic a,b,c,d,e,f,g;

    lab1_g20_p3 dut0(A,B,C,D,a,b,c,d,e,f,g);

    initial begin
    
    A=0; B=1; C=0; D=0; #10;    // for E
	if(a==0 && b==1 && c==1 && d==0 && e==0 && f==0 && g==0) $display("character E successful");
    A=1; B=1; C=0; D=0; #10;    // for L
	if(a==1 && b==1 && c==1 && d==0 && e==0 && f==0 && g==1) $display("character L successful");
    A=1; B=1; C=1; D=0; #10;    // for C
	if(a==0 && b==1 && c==1 && d==0 && e==0 && f==0 && g==1) $display("character C successful");
    A=1; B=0; C=0; D=1; #10;    // for 2
	if(a==0 && b==0 && c==1 && d==0 && e==0 && f==1 && g==0) $display("number 2 successful");
    A=1; B=1; C=0; D=1; #10;    // for 3
	if(a==0 && b==0 && c==0 && d==0 && e==1 && f==1 && g==0) $display("3 successful");
    A=1; B=1; C=1; D=1; #10;    // for 5
	if(a==0 && b==1 && c==0 && d==0 && e==1 && f==0 && g==0) $display("number 5 successful");
    
    end
endmodule