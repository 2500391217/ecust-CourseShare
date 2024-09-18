/**
 * �������
 **/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


class Solution {
private:
    // dfs(candidates,target,combine,idx)
	// candidates����ĵ� idxλ
	// ��ʣ target Ҫ���
	// �Ѿ���ϵ��б�Ϊ combine
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }

        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }

        dfs(candidates, target, ans, combine, idx + 1);

        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

	// ��ȡһ���ڵ�����
	void inputArrays(vector<int>& input) {
		string line;
		while (getline(cin, line)) {		
			if (line.empty()) {
				continue;
			}
			
			istringstream iss(line);
			int num;
			
			while (iss >> num) {
				input.push_back(num);
			}
			
			break;
		}
	}
		
	
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
    
    void input(vector<int>& candidates, int& target) {
		cout << "����������candidates:(һ��)" << endl;
		inputArrays(candidates);
		cout << "������Ŀ����target: "  << endl;
		cin >> target;
	}
	
	void output(vector<vector<int>> ans) {
		cout << "�����£�" << endl;
		for (const vector<int> & p : ans) {
			for (const int & num : p) {
				cout << num << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Solution solution;
	vector<int> candidates;
	int target;
	
	solution.input(candidates, target);
	vector<vector<int>> ans = solution.combinationSum(candidates, target);
	solution.output(ans);
	
	return 0;
}

