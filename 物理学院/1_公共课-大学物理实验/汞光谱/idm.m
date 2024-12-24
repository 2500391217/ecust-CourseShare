function [y,mean_y] = idm(x)
%����interative differential method����
%xһ��Ϊ����ǰ�벿�����벿����
%ȡ����ֵ��ƽ����
N = length(x);
x = sort(x);
% x_back = x(N/2+1:end);
% x_for = x(1:N/2);
% x_mean = mean(abs(x_back-x_for));
for i = 1:N-1
    y(i) = x(i+1)-x(i);
end
mean_y = mean(y);