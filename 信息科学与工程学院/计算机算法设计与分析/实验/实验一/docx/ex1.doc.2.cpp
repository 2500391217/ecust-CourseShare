#include <stdio.h>

const int MAX_N = 1010;
int a[MAX_N];

/**
 * ģ��(�벻�����ֳ����ε��㷨)
 **/

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int t1(0); // ��������
		int t2(0); // �½�����
		
		for (int i = 1; i <= n; i ++ ) {
			scanf("%d", a + i);
			if (a[i] > a[i - 1]) {
				t1 += a[i] - a[i - 1];
			}
			else if (a[i] < a[i - 1]) {
				t2 += a[i - 1] - a[i];
			}
		}
		printf("%d\n", t1 * 6 + t2 * 4 + n * 5);
	}
	
	return 0;
}
