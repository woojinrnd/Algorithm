#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> combination;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
    // 입력 집합
    for (int i=0; i<n; ++i) {
    	nums.push_back(i+1);
	}
	
    // 선택할 요소의 개수
    int k = m;

    // 조합을 저장할 벡터
    vector<int> combination(nums.size(), 0);
    for (int i = 0; i < k; ++i) {
        combination[i] = 1;
    }

    // prev_permutation을 이용하여 이전 조합을 탐색하고 출력
    do {
        // 현재 조합 출력
        for (int i = 0; i < nums.size(); ++i) {
            if (combination[i] == 1) {
                cout << nums[i] << " ";
            }
        }
        cout << endl;
    } while (prev_permutation(combination.begin(), combination.end()));

    return 0;
}
