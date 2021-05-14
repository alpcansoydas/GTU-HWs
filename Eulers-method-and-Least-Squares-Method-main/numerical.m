clear all;
clc;
 
Vs=2; %Source voltage
L=0.98; %inductance
R=14.2; %resistor
 
data=importdata('diodedata.dat');
for i=1:length(data)
    diode_current(i)=data(i,2);
    diode_voltage(i)=data(i,1);
end
 
%%lny=lnb+ax == ln(current)=ln(b)+a*voltage
voltage_sum=0;
ln_current=0;
voltage_square=0;
voltage_multiply_lncurrent=0;
for i=1:length(data)
    voltage_sum=voltage_sum+data(i);
    voltage_multiply_lncurrent=voltage_multiply_lncurrent+diode_voltage(i)*log(diode_current(i));
    ln_current=ln_current+log(diode_current(i));
    voltage_square=voltage_square+(diode_voltage(i))^2;
end
%coefficients a and b
a=(length(data)*voltage_multiply_lncurrent - voltage_sum*ln_current)/(length(data)*voltage_square-(voltage_sum)^2);
lnb=(voltage_square*ln_current - voltage_multiply_lncurrent*voltage_sum)/(length(data)*voltage_square-(voltage_sum)^2);
b=exp(lnb);
f=@(x) exp(lnb)*exp(a*x);
Vd=@(c) (log(c)-log(b))/a;
figure
v=0:0.01:1.3;
plot(v,exp(lnb)*exp(a*v),'LineWidth',1);
hold on
plot(diode_voltage,diode_current,'s','LineWidth',1);
hold on
legend('Least Squares Approximation','fprdata.dat');
ylabel('Current(A)');
xlabel('Voltage(V)');
title('Diode Characteristic');
%Euler's method for initial value problem
h1=0.025;
h2=0.0025;
w1=zeros(length(0.6/h1));
t1=0:h1:0.6;
w1(1)=10^-12;
for i=1:1:length(t1)-1
    w1(i+1)=w1(i)+h1*((Vs - (log(w1(i)/b))/a - R*w1(i))/L);
end
figure
plot(t1,w1,'LineWidth',1);
xlabel('Time(sn)');
ylabel('Current(A)');
title('Time-Current');
hold on;
w2=zeros(length(0.6/h2));
w2(1)=10^-12;
t2=0:h2:0.6;
for i=1:length(t2)-1
   w2(i+1)=w2(i)+h2*((Vs-Vd(w2(i))-R*w2(i))/L);
end
plot(t2,w2,'LineWidth',1);
legend('t=0.025sn','t=0.0025sn');
hold on;
%V1(t)3
figure
plot(t1,R*w1,'LineWidth',1);
hold on
plot(t2,R*w2,'LineWidth',1);
xlabel('Time(sn)');
ylabel('V1(V)');
title('Time-V1(t)');
legend('V1(t) for t=0.025 sn','V1(t) for t=0.0025sn');
%Vd(t)
figure
plot(t1,(log(w1/b))/a,'LineWidth',1);
hold on
plot(t2,(log(w2/b))/a,'LineWidth',1);
xlabel('Time(sn)');
ylabel('Vd(V)');
title('Time-Vd(t)');
legend('Vd(t) for t=0.025sn','Vd(t) for t=0.0025sn');
%V2(t)
figure
plot(t1,(Vs-(log(w1/b))/a-R*w1),'LineWidth',1);
hold on
plot(t2,(Vs-(log(w2/b))/a-R*w2),'LineWidth',1);
xlabel('Time(sn)');
ylabel('V2(V)');
title('Time-V2(t)');
legend('V2(t) for t=0.025sn','V2(t) for t=0.0025sn');
