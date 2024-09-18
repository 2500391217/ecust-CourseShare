#include <iostream>
#include <cmath>

using namespace std;

/**
 * �þ�����εݹ�̫���ˣ�hdu�Ϲ�����
 * 
 * ��ͬ�������ظ�����һ���֣�����������F[65]�洢
 **/

class Solution {
private:
	unsigned long long F[65];
public:
	int hanoi4(int n) {
		F[1] = 1;
		for (int i = 2; i <= n; i ++ ) {
			unsigned long long minN = (unsigned long long ) (pow(2, i)) - 1;
			for (int j = 1; j < i; j ++ ) {
				unsigned long long u = 2 * F[j] + (unsigned long long ) (pow(2, i - j) - 1);
				if (u < minN) {
					minN = u;
				}
			}
			F[i] = minN;
		}
		return F[n];
	}
};


int main() {
	int n;
	Solution solution;
	while (cin >> n && n >= 1 && n <= 64) {
		cout << solution.hanoi4(n) << endl;
	}
	
	return 0;
}
