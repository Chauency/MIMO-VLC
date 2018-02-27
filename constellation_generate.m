format longg
%Copy-and-paste the channel matrix H here
H = 10^-4 * [
    1.0708 0.9937 0.9937 0.9226
    0.9937 1.0708 0.9226 0.9937
    0.9937 0.9226 1.0708 0.9937
    0.9226 0.9937 0.9937 1.0708];

%order of PAM for SM
M_PAM_SM = 4;

N_t = 4;
N_r = 4;
I_SM = 2*(1:M_PAM_SM)/(M_PAM_SM+1);
signal  = zeros(M_PAM_SM * N_t,N_t);
for i = 1:size(signal,1)
    j = mod(i,M_PAM_SM)+1;
    signal(i,ceil((i)/M_PAM_SM)) = I_SM(1,j);
end
signal = (H * signal')';

%Copy-and-paste the output of signal to Modem_**.txt
for i = 1 : size(signal, 1)
    for j = 1 : size(signal, 2)
        fprintf('%1.10f ', signal(i, j))
    end
    fprintf('\n')
end

