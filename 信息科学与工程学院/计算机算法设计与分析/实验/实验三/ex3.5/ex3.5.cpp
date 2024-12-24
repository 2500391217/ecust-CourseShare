/**
 * �����任����
 **/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Solution {
private:
	const string INPUT_FILE = "input.txt";
	const string OUTPUT_FILE = "output.txt";
	
	int n, m;
	int k; // ��ǰ�����������
	queue<char> q; // ��Ÿ������

public:
	Solution() {
		k = 1;
		
		// �鿴�Ƿ����input.txt�ļ��������ڴ���
		ifstream inputFile(INPUT_FILE);
		
		if (!inputFile.good()) {
			ofstream output(INPUT_FILE);
			cout << "input.txt�����ڣ����ڴ���" << endl;
			if (!output.is_open()) {
				cout << "����ʧ��";
				exit(0);
			}
			string content = 
				"15 4";
			output << content;
			output.close();
		}
		
		inputFile.close();
	}
	
	bool input() {
		ifstream inputFile(INPUT_FILE);
		if (!inputFile.is_open()) {
			cout << "Cannot open file" << endl;
			return false;
		}
		
		inputFile >> n >> m;
		cout << "�ɹ���ȡ���ݣ�" << endl;
		cout << "n = " << n << endl;
		cout << "m = " << m << endl;
		
		inputFile.close();
		return true;
	}
	
	bool dfs(int x, int n) {
		if (x > k) {
			return false;
		}
		
		if (n == m) {
			return true;
		}
		
		int temp(n);
		for (int i = 0; i < 2; i ++ ) {
			if (i == 0) {
				temp = n * 3;
			}
			else {
				temp = n / 2;
			}
			if (dfs(x + 1, temp)) {
				if (i == 0) {
					q.push('f');
				}
				else {
					q.push('g');
				
				}
				return true;	
			}
		}
		
		return false;
	}
	
	void compute() {
		while (!dfs(0, n)) {
			k ++ ;
		}
	}
	
	void output() {
		ofstream outputFile(OUTPUT_FILE);
		if (!outputFile.is_open()) {
			cout << "Cannot open the file." << endl;
		}
		cout << "�ɹ���ȡ�𰸣�" << endl;
		cout << k << endl;
		outputFile << k << endl;
		
		while(!q.empty()) {
			cout << q.front();
			outputFile << q.front();
			q.pop();
		}
		cout << endl;
		
		outputFile.close();
		cout << "�ɹ�д���ļ�" << endl;
		// ���ļ�
		// system("notepad output.txt");
	}
};

int main() {
	Solution solution;
	
	if (solution.input()) {
		solution.compute();
		solution.output();
	}	
	
	return 0;
}
