#include <iostream>

using namespace std;

int N[9][9];
int res;
int row = 1;
int col = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			cin >> N[i][j];
			if (res < N[i][j]) {
				res = N[i][j];
				row = i+1;
				col = j+1;
			}
		}
	}
	cout << res << '\n';
	cout << row << ' ' << col;
	
	return 0;
}