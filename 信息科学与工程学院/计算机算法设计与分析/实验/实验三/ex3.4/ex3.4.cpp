/**
 * nɫ��������
 **/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
private:
	const string INPUT_FILE = "input.txt";
	const string OUTPUT_FILE = "output.txt";
	
	int n;
	vector<vector<int>> board; // �洢n��������������ɫ board[][6]
	vector<char> color;
	vector<vector<int>> solu; // �洢��
	vector<int> used;
	int ans;
	vector<vector<char>> ansVector; // ���յĴ�
public:
	Solution() {
		ans = 0;
		
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
				"4\n"
				"RGBY\n"
				"0 2 1 3 0 0\n"
				"3 0 2 1 0 1\n"
				"2 1 0 2 1 3\n"
				"1 3 3 0 2 2";
			output << content;
			output.close();
		}
		
		inputFile.close();
		
		// system("notepad input.txt");
	}
	
	bool input() {
		ifstream inputFile(INPUT_FILE);
		if (!inputFile.is_open()) {
			cout << "Cannot open file." << endl;
			return false;
		}
		
		inputFile >> n;
		board.resize(n, vector<int>(6, 0));
		solu.resize(n, vector<int>(6, 0));
		color.resize(n);
		used.resize(n);
		
		for (int j = 0; j < n; j ++ ) {
			inputFile >> color[j];
		}
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < 6; j ++ ) {
				inputFile >> board[i][j];
			}
		}
		
		cout << "�ɹ���ȡ���ݣ�" << endl;
		cout << "n: " << endl << n << endl;
		
		cout << "color: " << endl;
		for (const char & c : color) {
			cout << c << " ";
		}
		cout << endl;
		
		cout << "board: " << endl;
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < 6; j ++ ) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
		return true;
	}
	
	void search() {
		int i, t, cube, newg, over, ok;
		int *vert = new int[n];
		int *edge = new int[n * 2];
		
		for (i = 0; i < n; i ++ ) {
			vert[i] = 0;
		}
		t = -1;
		newg = 1;
		
		while (t > -2) {
			t ++;
			cube = t % n;
			if (newg) {
				edge[t] = -1;
			}
			over = 0;
			ok = 0;
			
			while (!ok && !over) {
				edge[t] ++;
				if (edge[t] > 2) {
					over = 1;
				}
				else {
					ok = (t < n || edge[t] != edge[cube]);
				}
			}
			if (!over) {
				if (++ vert[board[cube][edge[t] * 2]] > 2 + t / n * 2) {
					ok = 0;
				}
				if (++ vert[board[cube][edge[t] * 2 + 1]] > 2 + t / n * 2) {
					ok = 0;
				}
				if (t % n == n - 1 && ok) {
					for (i = 0; i < n; i ++ ) {
						if (vert[i] > 2 + t / n * 2) {
							ok = 0;
						}
					}
				}
				if (ok) {
					if (t == n * 2 - 1) {
						ans ++;
						out(edge);
						return;
					}
					else {
						newg = 1;
					}
				}
				else {
					-- vert[board[cube][edge[t] * 2]];
					-- vert[board[cube][edge[t] * 2 + 1]];
					t --;
					newg = 0;
				}
			}
			
			else {
				t --;
				if (t > -1) {
					cube = t % n;
					-- vert[board[cube][edge[t] * 2]];
					-- vert[board[cube][edge[t] * 2 + 1]];
				}
				t -- ;
				newg = 0;
			}
		}
	}
	
	void out(int* edge) {
		int k, a, b, c, d, j, i;
		
		for (i = 0; i < 2; i ++ ) {
			for (j = 0; j < n; j ++ ) {
				used[j] = 0;
			}
			do {
				j = 0;
				d = c = -1;
				while (j < n && used[j]) {
					j ++ ;
				}
				if (j < n) {
					do {
						a = board[j][edge[i * n + j] * 2];
						b = board[j][edge[i * n + j] * 2 + 1];
						if (b == d) {
							a = a ^ b;
							b = a ^ b;
							a = a ^ b;
						}
						solu[j][i * 2] = a;
						solu[j][i * 2 + 1] = b;
						used[j] = 1;
						if (c < 0) {
							c = a;
						}
						d = b;
						for (k = 0; k < n; k ++ ) {
							if (!used[k] && 
								(board[k][edge[i * n + k] * 2] == b || 
								 board[k][edge[i * n + k] * 2 + 1] == b)
								) {
								j = k;
							}
						}
					} while (b != c);
				} 	
			} while(j < n);
		}
		for (int j = 0; j < n; j ++ ) {
			k = 3 - edge[j] - edge[j + n];
			a = board[j][k * 2];
			b = board[j][k * 2 + 1];
			solu[j][4] = a;
			solu[j][5] = b;
		}
		for (i = 0; i < n; i ++ ) {
			vector<char> temp;
			for (j = 0; j < 6; j ++ ) {
				temp.push_back(color[solu[i][j]]);
//				cout << color[solu[i][j]];
			}
			ansVector.push_back(temp);
//			cout << endl;
		}
	}
	
	int getAns() const {
		return ans;
	}
	
	void output() {
		cout << "�ɹ���ȡ�𰸣�" << endl;
		ofstream outputFile(OUTPUT_FILE);
		if (!outputFile.is_open()) {
			cout << "Cannot open file." << endl;
		}
		
		if (ans == 0) {
			cout << "No Solution!" << endl;
			outputFile << "No Solution!";
		}
		else {
			for (const vector<char> & colors : ansVector) {
				for (const char & c : colors) {
					cout << c;
					outputFile << c;
				}
				cout << endl;
				outputFile << endl;
			}	
		}
		outputFile.close();
		cout << "�ɹ�����д���ļ�";
		// ���ļ�
		// system("notepad output.txt");
	}
};

int main() {
	Solution solution;
	if (solution.input()) {
		solution.search();
		solution.output();
	}
	
	return 0;
}
