function g=smit(G)
%ʩ�������������������������������G��һ������ÿһ����һ������
%�Զ�ѡ���һ����������
[m,n]=size(G);
g=zeros(m,n);
g(:,1)=G(:,1);
g2=sqrt( sum(g(:,1).^2));
g(:,1)=g(:,1)/g2;
for i=2:n
    g(:,i)=G(:,i);
    for j=1:i-1
        g(:,i)=g(:,i)-G(:,i)'*g(:,j)./( g(:,j)'*g(:,j))*g(:,j);
    end
    g2=sqrt( sum(g(:,i).^2));
    g(:,i)=g(:,i)/g2;
end
