module half_adder(input logic x,y, output logic s,c);
assign s = x^y;
assign c = x&y;
endmodule

module full_adder_str(input logic A,B,Cin, output logic Cout,Sum);
logic s0,c0,c1;
half_adder ha0 (.x(A) , .y(B) , .s(s0) , .c(c0));
half_adder ha1 (.x(s0), .y(Cin), .s(Sum), .c(c1));
assign Cout= c1 | c0;
endmodule

module ripple_carry_adder #(parameter N=4)(input logic [N-1:0] A,B, input logic Cin,
output logic [N-1:0] Sum, output logic Cout );
logic c[N:0];
assign c[0]=Cin;
assign Cout=c[N];

genvar i;
generate
    for(i=0;i<N;i++) begin: fa
        full_adder_str fa0 (.A(A[i]), .B(B[i]), .Cin(c[i]), .Sum(Sum[i]), .Cout(c[i+1]));
    end
endgenerate
endmodule