#include <iostream>
#include <algorithm>

using namespace std;

int N; //물건
int K; // 최대 무게
int W[101], V[101]; // 무게, 가치
int DP[101][100010]; // DP[a][b]=c : a번째 물건을 찾고, 가방의 현재 무게가 b일때 가방에 담긴 물건들의 가치는 C


void input() {
    cin >> N >> K;
    for (int i=1; i<=N; ++i) {
        cin >> W[i] >> V[i];
    }
}

void solution() {
    // DP 문제
    // 현재 탐색중인 물건을 가방에 담을 수 있냐없냐 (무게판단) (if j >= w[i], else)
    // 물건을 진짜로 담을거냐 말거냐 (가치판단)
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=K; ++j) {
            if (j>=W[i]) DP[i][j] = max(DP[i-1][j], DP[i-1][j-W[i]]+V[i]);
            else DP[i][j] = DP[i-1][j];
        }
    }
    cout << DP[N][K] << '\n';
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}