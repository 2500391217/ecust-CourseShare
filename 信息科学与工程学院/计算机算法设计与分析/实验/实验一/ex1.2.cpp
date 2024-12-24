#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
private:
	/*
	// ����һ
	static const int MIN_VALUE = numeric_limits<int>::min();
	
	int maxCrossSubArray(vector<int>& nums, int left, int mid, int right) {
		int leftSum(MIN_VALUE);
		int sum(0);
		
		for (int i = mid; i >= left; i -- ) {
			sum += nums[i];
			if (sum > leftSum) {
				leftSum = sum;
			}
		}
		
		int rightSum(MIN_VALUE);
		sum = 0;
		for (int i = mid + 1; i <= right; i ++ ) {
			sum += nums[i];
			if (sum > rightSum) {
				rightSum = sum;
			}
		}
		
		return leftSum + rightSum;
	}
	
	int maxSum(vector<int>& nums, int left, int right) {
		if (left == right) {
			return nums[left];
		}
		
		int mid = (left + right) >> 1;
		int maxLeft = maxSum(nums, left, mid);
		int maxRight = maxSum(nums, mid + 1, right);
		int maxCross = maxCrossSubArray(nums, left, mid, right);
		
		return max(max(maxLeft, maxRight), maxCross);
	}
	
	// return maxSum(nums, 0, nums.size() - 1);
	*/
	
	
	// ������
	// lSum ��ʾ [l,r] ���� l Ϊ��˵������Ӷκ�
	// rSum ��ʾ [l,r] ���� r Ϊ�Ҷ˵������Ӷκ�
	// mSum ��ʾ [l,r] �ڵ�����Ӷκ�
	// iSum ��ʾ [l,r] �������
	struct Status {
		int lSum, rSum, mSum, iSum;
	};
	
	Status pushUp(Status l, Status r) {
		int iSum = l.iSum + r.iSum;
		int lSum = max(l.lSum, l.iSum + r.lSum);
		int rSum = max(r.rSum, l.rSum + r.iSum);
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
		return (Status) {lSum, rSum, mSum, iSum};
	}
	Status get(vector<int>& nums, int left, int right) {
		if (left == right) {
			return (Status) {nums[left], nums[left], nums[left], nums[left]};
		}
		
		int mid = (left + right) >> 1;
		Status lSub = get(nums, left, mid);
		Status rSub = get(nums, mid + 1, right);
		
		return pushUp(lSub, rSub);
	}
	
	/*
	// ������
	int maxSubArray(vector<int>& nums) {
		int prev(0), maxSum(nums[0]);
		
		for (const int& num : nums) {
			prev = max(prev + num, num);
			maxSum = max(maxSum, prev);
		}
		
		return maxSum;
	}
	*/
	
public:
	int maxSubArray(vector<int>& nums) {
		return get(nums, 0, nums.size() - 1).mSum;
	}
};

int main() {
	vector<int> input;
	Solution solution;
	
	int num;
	while (cin >> num) {
		input.emplace_back(num);
	}
	
	cout << solution.maxSubArray(input) << endl;
	
	system("pause");
	return 0;
}
