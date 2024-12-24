/**
 * DFS
 **/

#include <iostream>

using namespace std;

class Solution {
private:
	long long factorial(long long n) {
		long long res(1);
		
		for (long long i = 1; i <= n; i ++ ) {
			res = res * i;
		}
		
		return res;
	}
	
public:
	/**
	 * @brief ���Ծ�����ѧ֤��ǰ��10λ����ֻ�����ĸ���
	 * �������������2147483647����ôhdu�Ͽ϶���ʱ������
	 * 
	 **/
	void work() {
		long long sum(0), res(0);
		for (long long i = 1; i <= 43432; i ++ ) {
			res = i;
			sum = 0;
			while (res) {
				sum += (factorial(res % 10));
				res /= 10;
			}
			if (sum == i) {
				printf("%lld\n", i);
			}
		}
	}
};

int main() {
	Solution solution;
	solution.work();
	
	return 0;
}
