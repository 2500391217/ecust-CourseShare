function [Y,X1,S] = ComputeZhuCha(X)
%COMPUTEZHUCHA �˴���ʾ�йش˺�����ժҪ
%   X1Ϊƽ��ֵ SΪ��׼�� XΪ�����n*1������    
n=size(X);%nҪΪż��
Y1=X(1:n/2);
Y2=X((n/2)+1:n);
Y=(Y2-Y1);
S=std(Y);
X1=mean(Y);


end

