#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	const long long int MOD = 1e9 + 7;
	vector<vector<long long int>> dp;
	// dp[i][0] ��ʾ��i��ΪG
	// dp[i][1] ��ʾ��i��ΪR
	// dp[i][2] ��ʾ��i��ΪP
public:
	// G����u��������R��������v��
	long long int cal(long long int n, long long int u, long long int v) {
		int i;
		dp[0][1] = dp[0][0] = 0;
		dp[0][2] = 1;
		
		for (i = 1; i <= n; i ++ ) {
			long long int sum = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
			dp[i][2] = sum;
			if (i <= u) {
				dp[i][0] = sum;
			}
			else if (i == u + 1) {
				dp[i][0] = (sum - 1) % MOD;
			}
			else {
				dp[i][0] = (sum - dp[i - u - 1][1] - dp[i - u - 1][2]) % MOD;
			}
			
			if (i <= v) {
				dp[i][1] = sum;
			}
			else if (i == v + 1) {
				dp[i][1] = (sum - 1) % MOD;
			}
			else {
				dp[i][1] = (sum - dp[i - v - 1][0] - dp[i - v - 1][2]) % MOD;
			}
		}
		
		return (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
	}
	
	long long int getWaysToArrange(long long int n, long long int m, long long int k) {
		dp.resize(n + 1, vector<long long int> (3, 0));
		long long int ans = cal(n, n, k);
		
		ans = ((ans - cal(n, m - 1, k)) % MOD + MOD) % MOD;  
		//ע��������ܳ��ָ�����ȡģ��ʱ��Ҫ�ر���һ�¡�
		
		return ans;
	}
};

int main() {
	long long int n, m, k;
	Solution solution;
	
	while (scanf("%lld%lld%lld", &n, &m, &k) == 3) {
		cout << solution.getWaysToArrange(n, m, k) << endl;
	}
	
	return 0;
}
