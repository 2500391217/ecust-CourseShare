function [U] = ComputeU(S,n,t0683,delta_yi)
%COMPUTEU �˴���ʾ�йش˺�����ժҪS��׼�� n���� t0683 delta_yi������� �õ���ȷ����U
%   �˴���ʾ��ϸ˵��
U=((t0683(n-1)*S/sqrt(n))^2+(0.618*delta_yi)^2)^0.5;

end

