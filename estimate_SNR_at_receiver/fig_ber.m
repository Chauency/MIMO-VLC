%warning off
close all
clear 
clc
%%%%%%%%%%%%%%%%%Parameters of the figure%%%%%%%%
width = 12;
height = width * 0.75;
fontsize = 14;
linewidth = 2;
markersize = 9;
ColorSet = [...
    0         0    1.0000
    0    0.5000         0
    1.0000         0         0
    0    0.7500    0.7500
    0.7500         0    0.7500
    0.7500    0.7500         0
    0.2500    0.2500     0.2500
    ];
set(gcf, 'DefaultAxesColorOrder', ColorSet);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%BER of RC
h = figure(1);
fig(h, 'units','inches','width',width, 'height', height, 'font','Times New Roman','fontsize',fontsize);
semilogy(RC2(:,1), RC2(:,2),'r-','LineWidth',linewidth)
hold on;
%%
h =[...
    8.8278e-06   8.3394e-06   8.3394e-06   7.8917e-06
    8.3394e-06   8.8278e-06   7.8917e-06   8.3394e-06
    8.3394e-06   7.8917e-06   8.8278e-06   8.3394e-06
    7.8917e-06   8.3394e-06   8.3394e-06   8.8278e-06];
snr = 111:2:135;
N0 = 10.^(-0.1 * snr);
M = 16;
E_s = 1;
N_t = 4;
N_r = 4;
x = 1/(M-1).*sqrt(E_s./(N0*N_t^2)*sum(sum(h,1).^2));
ber_rc = 2*(M-1)/(M*log2(M)) .* Qfunction(x);
semilogy(snr,ber_rc,'ro')
%%
semilogy(RC4(:,1), RC4(:,2),'b-','LineWidth',linewidth)
%%
h=[...
    1.7002e-05   5.0134e-06   5.0134e-06   2.4286e-06
    5.0134e-06   1.7002e-05   2.4286e-06   5.0134e-06
    5.0134e-06   2.4286e-06   1.7002e-05   5.0134e-06
    2.4286e-06   5.0134e-06   5.0134e-06   1.7002e-05
    ];
snr = 111:2:135;
N0 = 10.^(-0.1 * snr);
M = 16;
E_s = 1;
N_t = 4;
N_r = 4;
x = 1/(M-1).*sqrt(E_s./(N0*N_t^2)*sum(sum(h,1).^2));
ber_rc = 2*(M-1)/(M*log2(M)) .* Qfunction(x);
semilogy(snr,ber_rc,'bo')
%%
hold on;

semilogy(RSRC2(:,1), RSRC2(:,2),'r>-','LineWidth',linewidth)
hold on;
semilogy(RSRC4(:,1), RSRC4(:,2),'b>-','LineWidth',linewidth)
hold on;

semilogy(BMSTRC2(:,1), BMSTRC2(:,2),'rs-','LineWidth',linewidth)
hold on;
semilogy(BMSTRC4(:,1), BMSTRC4(:,2),'bs-','LineWidth',linewidth)
hold on;

sl=[112.35,113.4];
plot([sl(1),sl(1)],[10e-7, 1],'r--','LineWidth',linewidth)
plot([sl(2),sl(2)],[10e-7, 1],'b--','LineWidth',linewidth)

semilogy(BMSTRC2lowerbound(:,1), BMSTRC2lowerbound(:,2),'r:','LineWidth',linewidth)
hold on;
semilogy(BMSTRC4lowerbound(:,1), BMSTRC4lowerbound(:,2),'b:','LineWidth',linewidth)
hold on;

grid on;
h_legend = legend(...
    'RC {\itP}_1 Simulation result',...
    'RC {\itP}_1 Theoretical bound',...
    'RC {\itP}_2 Simulation result',...
    'RC {\itP}_2 Theoretical bound',...
    'RS-RC {\itP}_1',...
    'RS-RC {\itP}_2',...
    'BMST-RC {\itP}_1',...
    'BMST-RC {\itP}_2',...
    'Shannon limit {\itP}_1',...
    'Shannon limit {\itP}_2',...
    'Lower bound BMST-RC {\itP}_1',...
    'Lower bound BMST-RC {\itP}_2',...
    'Location','northeast');
axis([110,140,10^-5 ,1]);
xlabel('SNR(1/\sigma^2)(dB)');
ylabel('BER');
set(get(gca,'Children'),'linewidth',linewidth);
set(gca, 'XTick', 110:2:140);
set(get(gca,'Children'), 'markersize', markersize);
print(gcf, '-depsc', 'BERRC.eps'); %epscolor
print(gcf, '-dpng', 'BERRC.png'); %pdfcolor















%%
%BER of SMP
h = figure(2);
fig(h, 'units','inches','width',width, 'height', height, 'font','Times New Roman','fontsize',fontsize);


semilogy(SMP2(:,1), SMP2(:,2),'r-','LineWidth',linewidth)
hold on;
%%
h =[...
    8.8278e-06   8.3394e-06   8.3394e-06   7.8917e-06
    8.3394e-06   8.8278e-06   7.8917e-06   8.3394e-06
    8.3394e-06   7.8917e-06   8.8278e-06   8.3394e-06
    7.8917e-06   8.3394e-06   8.3394e-06   8.8278e-06];
snr = 81:2:170;
N0 = 10.^(-0.1 * snr);
M = 2;
E_s = 1;
N_t = 4;
N_r = 4;
r = 1;
T_s = 1;
s = [0,0,0,0
    0,0,0,0.5
    0,0,0.5,0
    0,0.5,0,0
    0.5,0,0,0
    0,0,0.5,0.5
    0,0.5,0,0.5
    0.5,0,0,0.5
    0.5,0,0.5,0
    0.5,0.5,0,0
    0,0.5,0.5,0
    0.5,0.5,0.5,0
    0.5,0.5,0,0.5
    0.5,0,0.5,0.5
    0,0.5,0.5,0.5
    0.5,0.5,0.5,0.5];
H_mult_s = (h*s')';
repmat_H_mult_s = repmat(H_mult_s,M^N_t,1);
kron_H_mult_s = kron(H_mult_s,ones(M^N_t,1));

repmat_s = repmat(s,M^N_t,1);
kron_s = kron(s,ones(M^N_t,1));
d_H = sum((repmat_s - kron_s)|(repmat_s - kron_s),2);
d_H_mult_s = sum((repmat_H_mult_s - kron_H_mult_s).^2,2);


repmat_N0 = repmat(N0,size(d_H_mult_s,1),1);
x = sqrt(r^2 .* T_s ./ (4 .* repmat_N0) .* repmat(d_H_mult_s,size(N0,1),size(N0,2)));
ber_smp = 1/(M^N_t*log2(M^N_t))* sum(repmat(d_H,size(N0,1),size(N0,2)).* Qfunction(x));
semilogy(snr,ber_smp,'ro')

%%
semilogy(SMP4(:,1), SMP4(:,2),'b-','LineWidth',linewidth)
hold on;
%%
h=[...
    1.7002e-05   5.0134e-06   5.0134e-06   2.4286e-06
    5.0134e-06   1.7002e-05   2.4286e-06   5.0134e-06
    5.0134e-06   2.4286e-06   1.7002e-05   5.0134e-06
    2.4286e-06   5.0134e-06   5.0134e-06   1.7002e-05
    ];
snr = 81:2:155;
N0 = 10.^(-0.1 * snr);
M = 2;
E_s = 1;
N_t = 4;
N_r = 4;
r = 1;
T_s = 1;
s = [0,0,0,0
    0,0,0,0.5
    0,0,0.5,0
    0,0.5,0,0
    0.5,0,0,0
    0,0,0.5,0.5
    0,0.5,0,0.5
    0.5,0,0,0.5
    0.5,0,0.5,0
    0.5,0.5,0,0
    0,0.5,0.5,0
    0.5,0.5,0.5,0
    0.5,0.5,0,0.5
    0.5,0,0.5,0.5
    0,0.5,0.5,0.5
    0.5,0.5,0.5,0.5];
H_mult_s = (h*s')';
repmat_H_mult_s = repmat(H_mult_s,M^N_t,1);
kron_H_mult_s = kron(H_mult_s,ones(M^N_t,1));

repmat_s = repmat(s,M^N_t,1);
kron_s = kron(s,ones(M^N_t,1));
d_H = sum((repmat_s - kron_s)|(repmat_s - kron_s),2);
d_H_mult_s = sum((repmat_H_mult_s - kron_H_mult_s).^2,2);


repmat_N0 = repmat(N0,size(d_H_mult_s,1),1);
x = sqrt(r^2 .* T_s ./ (4 .* repmat_N0) .* repmat(d_H_mult_s,size(N0,1),size(N0,2)));
ber_smp = 1/(M^N_t*log2(M^N_t))* sum(repmat(d_H,size(N0,1),size(N0,2)).* Qfunction(x));
semilogy(snr,ber_smp,'bo')

%%


semilogy(RSSMP2(:,1), RSSMP2(:,2),'r>-','LineWidth',linewidth)
hold on;
semilogy(RSSMP4(:,1), RSSMP4(:,2),'b>-','LineWidth',linewidth)
hold on;


semilogy(BMSTSMP2(:,1), BMSTSMP2(:,2),'rs-','LineWidth',linewidth)
hold on;
semilogy(BMSTSMP4(:,1), BMSTSMP4(:,2),'bs-','LineWidth',linewidth)
hold on;

sl=[115.2,107.65];
plot([sl(1),sl(1)],[10e-6, 1],'r--')
plot([sl(2),sl(2)],[10e-6, 1],'b--')
hold on;

semilogy(BMSTSMP2lowerbound(:,1), BMSTSMP2lowerbound(:,2),'r:','LineWidth',linewidth)
hold on;
semilogy(BMSTSMP4lowerbound(:,1), BMSTSMP4lowerbound(:,2),'b:','LineWidth',linewidth)
hold on;



grid on

h_legend = legend(...
    'SMP {\itP}_1 Simulation result',...
    'SMP {\itP}_1 Theoretical bound',...
    'SMP {\itP}_2 Simulation result',...
    'SMP {\itP}_2 Theoretical bound',...
    'RS-SMP {\itP}_1',...
    'RS-SMP {\itP}_2',...
    'BMST-SMP {\itP}_1',...
    'BMST-SMP {\itP}_2',...
    'Shannon limit {\itP}_1',...
    'Shannon limit {\itP}_2',...
    'Lower bound BMST-SMP {\itP}_1',...
    'Lower bound BMST-SMP {\itP}_2',...
    'Location','northeast');

hold off;
axis([100,170,10^-5 ,1]);%
xlabel('SNR(1/\sigma^2)(dB)');%
ylabel('BER');%
set(get(gca,'Children'),'linewidth',linewidth);%
%set(gca, 'XTick', 80:0.5:11);%
set(get(gca,'Children'), 'markersize', markersize );%
%set(get(gca,'Children'), 'MarkerEdgeColor','b', 'MarkerFaceColor','b');%
print(gcf, '-depsc', 'BERSMP.eps');%epscolor
print(gcf, '-dpng', 'BERSMP.png');%pdfcolor

%%
%figure of SM
h = figure(3);
fig(h, 'units','inches','width',width, 'height', height, 'font','Times New Roman','fontsize',fontsize);

semilogy(SM2(:,1), SM2(:,2),'r-','LineWidth',linewidth)
hold on;

%%
h=[8.8278e-06   8.3394e-06   8.3394e-06   7.8917e-06
    8.3394e-06   8.8278e-06   7.8917e-06   8.3394e-06
    8.3394e-06   7.8917e-06   8.8278e-06   8.3394e-06
    7.8917e-06   8.3394e-06   8.3394e-06   8.8278e-06];
min_snr = 100;
arc_snr = 2;
max_snr = 175;

snr_array = min_snr : arc_snr:max_snr;
ber_sm = zeros(size(snr_array));
iter = 0;
for snr = min_snr : arc_snr:max_snr
    iter = iter + 1;
    N0 = 10.^(-0.1 * snr);
    M = 4;
    E_s = 1;
    N_t = 4;
    N_r = 4;
    r = 1;
    T_s = 1;
    d_H = [...
        0.4000         0         0         0
        0.8000         0         0         0
        1.6000         0         0         0
        1.2000         0         0         0
        0    0.4000         0         0
        0    0.8000         0         0
        0    1.6000         0         0
        0    1.2000         0         0
        0         0    0.4000         0
        0         0    0.8000         0
        0         0    1.6000         0
        0         0    1.2000         0
        0         0         0    0.4000
        0         0         0    0.8000
        0         0         0    1.6000
        0         0         0    1.2000
        ];
    I=[0.4000 0.8000 1.6000 1.2000];
    
    for m1 = 1:M
        for nt1 = 1:N_t
            for m2 = 1:M
                for nt2 = 1:N_t
                    %d_H = biterr(m1*nt1-1,m2*nt2-1);
                    d_H = biterr(m1+N_t*(nt1-1)-1,m2+N_t*(nt2-1)-1);
                    temp_sum =0;
                    for nr = 1:N_r
                        temp_sum = temp_sum + (I(m2)*h(nr,nt2) - I(m1)*h(nr,nt1))^2;
                    end
                    x  = sqrt(r^2 .* T_s ./ (4 .* N0) .* temp_sum);
                    ber_sm(iter) = ber_sm(iter) + d_H * Qfunction(x);
                end
            end
        end
    end
    ber_sm(iter) = ber_sm(iter) * 1/(M*N_t*log2(M*N_t));
    
end
semilogy(snr_array,ber_sm,'ro')
%%

semilogy(SM4(:,1), SM4(:,2),'b-','LineWidth',linewidth)
hold on;

%%
h=[...
    1.7002e-05   5.0134e-06   5.0134e-06   2.4286e-06
    5.0134e-06   1.7002e-05   2.4286e-06   5.0134e-06
    5.0134e-06   2.4286e-06   1.7002e-05   5.0134e-06
    2.4286e-06   5.0134e-06   5.0134e-06   1.7002e-05
    ];
min_snr = 100;
arc_snr = 2;
max_snr = 175;

snr_array = min_snr : arc_snr:max_snr;
ber_sm = zeros(size(snr_array));
iter = 0;
for snr = min_snr : arc_snr:max_snr
    iter = iter + 1;
    N0 = 10.^(-0.1 * snr);
    M = 4;
    E_s = 1;
    N_t = 4;
    N_r = 4;
    r = 1;
    T_s = 1;
    d_H = [...
        0.4000         0         0         0
        0.8000         0         0         0
        1.6000         0         0         0
        1.2000         0         0         0
        0    0.4000         0         0
        0    0.8000         0         0
        0    1.6000         0         0
        0    1.2000         0         0
        
        0         0    0.4000         0
        0         0    0.8000         0
        0         0    1.6000         0
        0         0    1.2000         0
        0         0         0    0.4000
        0         0         0    0.8000
        0         0         0    1.6000
        0         0         0    1.2000];
    
    I=[0.4000 0.8000 1.6000 1.2000];
    
    for m1 = 1:M
        for nt1 = 1:N_t
            for m2 = 1:M
                for nt2 = 1:N_t
                    %d_H = biterr(m1*nt1-1,m2*nt2-1);
                    d_H = biterr(m1+N_t*(nt1-1)-1,m2+N_t*(nt2-1)-1);
                    temp_sum =0;
                    for nr = 1:N_r
                        temp_sum = temp_sum + (I(m2)*h(nr,nt2) - I(m1)*h(nr,nt1))^2;
                    end
                    x  = sqrt(r^2 .* T_s ./ (4 .* N0) .* temp_sum);
                    ber_sm(iter) = ber_sm(iter) + d_H * Qfunction(x);
                end
            end
        end
    end
    ber_sm(iter) = ber_sm(iter) * 1/(M*N_t*log2(M*N_t));
    
end
semilogy(snr_array,ber_sm,'bo')
%%

semilogy(RSSM2(:,1), RSSM2(:,2),'r>-','LineWidth',linewidth)
hold on;
semilogy(RSSM4(:,1), RSSM4(:,2),'b>-','LineWidth',linewidth)
hold on;


semilogy(BMSTSM2(:,1), BMSTSM2(:,2),'rs-','LineWidth',linewidth)
hold on;
semilogy(BMSTSM4(:,1), BMSTSM4(:,2),'bs-','LineWidth',linewidth)
hold on;

semilogy(BMSTSM2lowerbound(:,1), BMSTSM2lowerbound(:,2),'r:','LineWidth',linewidth)
hold on;
semilogy(BMSTSM4lowerbound(:,1), BMSTSM4lowerbound(:,2),'b:','LineWidth',linewidth)
hold on;


sl=[115.600000,104.500000];
plot([sl(1),sl(1)],[10e-6, 1],'r--')
plot([sl(2),sl(2)],[10e-6, 1],'b--')

hold on;

grid on
axis([100 175 1e-5 1])
xlabel('SNR(1/\sigma^2)(dB)');
ylabel('BER');
grid on
h_legend = legend(...
    'SM {\itP}_1 Simulation result',...
    'SM {\itP}_1 Theoretical bound',...
    'SM {\itP}_2 Simulation result',...
    'SM {\itP}_2 Theoretical bound',...
    'RS-SM {\itP}_1',...
    'RS-SM {\itP}_2',...
    'BMST-SM {\itP}_1',...
    'BMST-SM {\itP}_2',...
    'Shannon limit {\itP}_1',...
    'Shannon limit {\itP}_2',...
    'Lower bound BMST-SM {\itP}_1',...
    'Lower bound BMST-SM {\itP}_2',...
    'Location','northeast');

hold off;

axis([100 160 1e-5 1]);%
xlabel('SNR(1/\sigma^2)(dB)');%
ylabel('BER');%
set(get(gca,'Children'),'linewidth',linewidth);%
%set(gca, 'XTick', 80:0.5:11);%
set(get(gca,'Children'), 'markersize', markersize );%
%set(get(gca,'Children'), 'MarkerEdgeColor','b', 'MarkerFaceColor','b');%
print(gcf, '-depsc', 'BERSM.eps');%epscolor
print(gcf, '-dpng', 'BERSM.png');%pdfcolor






