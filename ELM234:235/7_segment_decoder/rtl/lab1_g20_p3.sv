module lab1_g20_p3(input logic A,B,C,D,
output logic a,b,c,d,e,f,g);
    assign a=(~D)&(~C)&((~B)&(~A)| (B&A));
    assign b=(~D)| C;
    assign c=(~B)|(~D);
    assign d=(~D)&(~C)&(~B)&(~A);
    assign e=(B&D)|((~B)&(~D));
    assign f=(~B)| (D&(~C));
    assign g=(~D)&(A |(~B));
endmodule