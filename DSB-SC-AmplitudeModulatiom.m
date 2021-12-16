% DSB-SC-AM Modulation and Demodulation
clc

% %Plotting m(t)
%t = 0:0.0001:0.02; %Time interval for one period plot
%m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
%subplot(4,1,1);
% plot(t,m);
% xlabel('Time(s)');
% ylabel('Amplitude');
% title('Message signal');
% grid on;

% %Plotting M(f)
% fs = 1000; %sampling frequency
% ts = 1/fs; %sampling period
% t=0:ts:1-ts ; %time interval
% m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
% freq_vector = -500:(fs/length(m)):500-(fs/length(m));
% fft_m = (1/length(m).*fft(m));
% %subplot(4,1,2);
% plot(freq_vector, abs(fftshift(fft_m)));
% title('Spectrum of the message signal');
% xlabel('Frequency(Hz)');
% ylabel('Amplitude');
% grid on;

% %Plotting y(t)
% t = 0:0.0001:0.02;
% m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
% c = 100.*cos(500*pi*t); % carrier signal
% y = m.*c; %modulated signal
% %subplot(4,1,3);
% plot(t,y);
% xlabel('Time(s)');
% ylabel('Amplitude');
% title('Modulated signal');
% grid on;

% Plotting Y(f)
% fs = 1000; %sampling frequency
% ts = 1/fs; %sampling period
% t=0:ts:1-ts ; %time interval
% m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
% c = 100.*cos(500*pi*t); % carrier signal
% y = m.*c; %modulated signal
% freq_vector = -500:(fs/length(y)):500-(fs/length(y));
% fft_y = (1/length(y).*fft(y));
% %subplot(4,1,4)
% plot(freq_vector,abs(fftshift(fft(y))));
% title('Y(f)');
% xlabel('Frequency(Hz)');
% ylabel('Amplitude');
% grid on;

%Plotting e(t)
% t = 0:0.0001:0.03; %Time interval for one period plot
% m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
% c = 100.*cos(500*pi*t); % carrier signal
% y = m.*c; %modulated signal
% Cd = cos(520*pi*t); %Carrier signal at the demodulator
% e = y .* Cd; %Signal before pass the LPF
% plot(t,e);
% xlabel('Time(s)');
% ylabel('Amplitude');
% title('e(t)');
% grid on;

% %Plotting e(f)
fs = 1000; %sampling frequency
ts = 1/fs; %sampling period
t=0:ts:1-ts ; %time interval
m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
c = 100.*cos(500*pi*t); % carrier signal
y = m.*c; %modulated signal
Cd = cos(500*pi*t); %Carrier signal at the demodulator
e = y .* Cd; %Signal before pass the LPF
freq_vector = -500:(fs/length(e)):500-(fs/length(e));
fft_e = (1/length(e).*fft(e));
%subplot(4,1,4)
plot(freq_vector,abs(fftshift(fft(e))));
title('e(f)');
xlabel('Frequency(Hz)');
ylabel('Amplitude');
grid on;
% 
% 
% %Defining Transfer function for LPF
% fs = 1000; %sampling frequency
% ts = 1/fs; %sampling period
% t=0:ts:1-ts ; %time interval
% m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
% c = 100.*cos(500*pi*t); % carrier signal
% y = m.*c; %modulated signal
% Cd = cos(520*pi*t); %Carrier signal at the demodulator
% e = y .* Cd; %Signal before pass the LPF
% freq_vector = -500:(fs/length(e)):500-(fs/length(e));
% fft_e = (1/length(e).*fft(e));
% f1=-499:-100;
% f2=-100:100;
% f3=100:498;
% f=[f1 f2 f3];
% x1=zeros(size(f1));
% x2=ones(size(f2));
% x3=zeros(size(f3));
% H=[x1 x2 x3]; % transfer function of the LPF

%Plotting Z(f)
% Zf = abs(fftshift(fft(e))) .* H;
% plot(freq_vector,Zf)
% xlabel('Frequency(Hz)');
% ylabel('Amplitude');
% title('Low Pass Filter=>Z(f)');

%Inverse fourier transform to obtain Z(t)
% t=-500:499;
% zt= ifftshift(ifft(Zf));
% plot(t,zt)
% xlabel('Time(s)');
% ylabel('Amplitude');
% title('z(t)');








%Low pass filter(LPF)
% fs=1000; % sampling frequency
% ts=1/fs; % sampling period
% t=-500:499; % time interval
% 
% transfer_func = zeros(1,1000);
% 
% for i =476: 525
%     transfer_func(1,i)=1;
% end
% 
% plot(t,transfer_func);
% title("Low-pass filter");
% xlabel('Frequency(Hz)');
% ylabel('Amplitude');
% hold on;
% m = 20.*cos(100*pi*t) + 10*cos(200*pi*t); %message signal
% c = 100.*cos(500*pi*t); % carrier signal
% y = m.*c; %modulated signal
% Cd = cos(500*pi*t); %Carrier signal at the demodulator
% e = y .* Cd; %Signal before pass the LP
% zf = fft_e .* transfer_func; %z(f) = e(f) * AGF transfer fonksiyonu
% zt = ifftshift(ifft(zf)); %z(f) ->TersFouirer-> z(t)
% subplot(3,1,1); plot (t,zf);
% title('Z(f) ','fontsize', [12]);
% xlabel('frekans (Hz)');
% ylabel('Genlik');
% hold on;
% 
% subplot(3,1,2); plot (t,zt);
% title('z(t) çıkış işareti','fontsize', [12]);
% xlabel('frekans (Hz)');
% ylabel('Genlik');
% hold on;