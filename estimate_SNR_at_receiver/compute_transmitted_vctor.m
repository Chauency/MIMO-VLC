% M = 128;%light sources
% N = 1;%PD
% M_PAM_SM = 2; %order of PAM for SM
% I_SM = 2*(1:M_PAM_SM)/(M_PAM_SM+1);
% H=[ 0.00010808   0.00010808];
% H = [0.00010708   0.00010708   0.00010708   0.00010708];
% %H=10^-4*[0.9937 1.0708 1.0708 0.9937 0.9937 1.0708 1.0708 0.9937];
% signal  = zeros(M_PAM_SM * M,M);
% for i = 1:size(signal,1)
%     j = mod(i,2)+1;
%     signal(i,floor((i+1)/M_PAM_SM)) = I_SM(1,j); 
% end
% signal;
% s = signal * H';
% s_SM= s/sum(s)
% 
% A = [ 0.485678        1.514322 ];
% A=[1.539083        0.953256        1.233220        0.274442];
% A=[ 0.150036        1.480751        2.073058        0.384229        0.568379        1.156448        1.295430        0.891668];
% 
% A=[0.870618 1.557595        1.151375        1.298569        0.066298        1.893276        1.717551        1.365738        0.272183        0.676023        1.663687        0.339659        0.470414        1.001225        0.636317        1.019471];
% 
% %A=A/sum(A)*M;
% A1=diag(A) 
% 
% signal1 = signal*A1;
% 
% s1 = signal1*H';
% s_SM1 = s1/sum(s1)




%%
%RC
H=10^-4*[0.9937 1.0708 1.0708 0.9937 0.9937 1.0708 1.0708 0.9937];

M=8;
N = 1;
M_PAM_RC = 16;
I_RC = 2*(0:M_PAM_RC-1)/(M_PAM_RC-1);
signal = repmat(I_RC',1,8);
s = signal * H';
s_RC= s/sum(s)/8

%%






M = 2;%light sources
N = 1;%PD
M_PAM_SM = 4; %order of PAM for SM
I_SM = 2*(1:M_PAM_SM)/(M_PAM_SM+1);
H=[0.00010509   0.00010509];
signal  = zeros(M_PAM_SM * M,M);
for i = 1:size(signal,1)
    j = mod(i,2)+1;
    signal(i,floor((i+1)/M_PAM_SM)) = I_SM(1,j); 
end
signal
s = signal * H';
s_SM= s/sum(s)


%%
%RC
M=2;
N = 1;
M_PAM_RC = 4;
I_RC = 2*(0:M_PAM_RC-1)/(M_PAM_RC-1);
signal = repmat(I_RC',1,M);
s = signal * H';
s_RC = s/sum(s);
H=[0.00010509   0.00010509];