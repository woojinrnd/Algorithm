#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NOT_VISITED = 0; // 방문하지 않은 상태를 나타내는 상수
const int CYCLE_IN = -1;    // 사이클에 속한 학생을 나타내는 상수

vector<int> arr;  // 학생들이 선택한 학생들의 번호를 저장하는 배열
vector<int> state; // 각 학생의 상태를 저장하는 배열

// 사이클 탐색 함수
void run(int x) {
    int cur = x;
    while (true) {
        state[cur] = x; // 현재 학생의 상태를 갱신
        cur = arr[cur]; // 다음에 방문할 학생으로 이동
        // 이번 방문에서 지나간 학생에 도달했을 경우
        if (state[cur] == x) {
            // 사이클에 속한 학생들의 상태를 CYCLE_IN으로 표시
            while (state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = arr[cur];
            }
            return;
        }
        // 이전 방문에서 지나간 학생에 도달했을 경우
        else if (state[cur] != NOT_VISITED) return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T; // 테스트 케이스의 개수 입력
    
    while (T--) {
        int n;
        cin >> n; // 학생의 수 입력
        
        // 배열 크기 초기화
        arr.resize(n + 1);
        state.assign(n + 1, 0);
        
        // 학생들이 선택한 학생들의 번호 입력
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        
        // 모든 학생을 순회하면서 사이클을 찾음
        for (int i = 1; i <= n; ++i) {
            if (state[i] == NOT_VISITED) {
                run(i);
            }
        }
        
        // 사이클에 속하지 않는 학생의 수를 세기
        int cnt = count_if(state.begin() + 1, state.end(), [](int s) { return s != CYCLE_IN; });
        cout << cnt << '\n';
    }
    
    return 0;
}
