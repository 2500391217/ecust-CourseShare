function []=gTh(G)
%�������ж�һ�����󹹳ɵļ����ܷ񹹳�Ⱥ
%Ⱥ�˷��Ķ����Ǿ���˷�
%G��Ԫ�飬Ԫ���Ǿ��������52λ��
%�������Ⱥ��������˷����������0
i=complex(0,1);
n=length(G);
M=zeros(n);
%�ж�G�Ƿ�������
is_j=isreal(cell2mat(G));
for i0=1:n
    for j=1:n
        for k=1:n
            if cell2mat(G(i0))*cell2mat(G(j))==cell2mat(G(k))
                M(i0,j)=char(k+64);
            elseif ~is_j
                if round(real(cell2mat(G(i0))*cell2mat(G(j))))==round(real(cell2mat(G(k))))
                    M(i0,j)=char(k+64);
                end
            end
        end
    end
end
if all(M)
    %���ȫ���㣬����Ⱥ������˷���
    fprintf('*| ')
    for i0=1:n
        fprintf('  %s   ',char(i0+64));
    end
    fprintf('\n');
    for i0=1:n
        fprintf('______');
    end
    fprintf('__');
    for i0=1:n
        fprintf('\n%s| ',char(i0+64));
        for j=1:n
            fprintf('%s*%s=%s ',char(i0+64),char(j+64),M(i0,j));
        end
    end
    fprintf('\n');    
else
    disp('�����ɾ���');
    disp(M);
end
end