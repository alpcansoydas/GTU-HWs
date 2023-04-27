module fsm_mealy(input logic clk, A, reset ,
output logic unlock);

typedef enum{S0,S1,S2,S3,S4} statetype;
statetype state , nextstate;

always_ff @(posedge clk)
if(reset) state<=S0;
else state <= nextstate;

always_comb
    case(state)
    S0:
    begin
    if(A) nextstate=S1;
    else nextstate=S0;
    end
    S1:
    begin
    if(A) nextstate=S2;
    else nextstate=S1;
    end
    S2:
    begin
    if(A) nextstate=S0;
    else nextstate=S3;
    end
    S3:
    begin
    if(A) nextstate=S2;
    else nextstate=S4;
    end
    S4:
    begin
    if(A) nextstate=S0;
    else nextstate=S1;
    end
    default: nextstate=S0;
    endcase

    //output logic
    always_comb
    if(state==S4 && A) unlock=1'b1;
    else unlock=1'b0;
    endmodule