#include <iostream>
#include <vector>

using namespace std;

int K;
struct info {
    int dir; // 동(1),서(2),남(3),북(4)
    int len;
};
info N[6];
int cnt;

void input() {
    cin >> K;
    for (int i=0; i<6; ++i) {
        int dir, len;
        cin >> dir >> len;
        N[i].dir = dir;
        N[i].len = len;
    }
}

void solution() {
    int x_max=0, y_max=0;
    int x_subs=0, y_subs=0;
    int area;
    for (int i=0; i<6; ++i) {
        // 가로 최댓값
        if ((N[i].dir==1||N[i].dir==2) && N[i].len > x_max) {
            x_max = N[i].len;
        }
        // 세로 최댓값
        else if ((N[i].dir==3||N[i].dir==4) && N[i].len > y_max) {
            y_max = N[i].len;
        }
    }

    // cut box
    // 원형 큐
    for (int i=0; i<6; ++i) {
        int prev = (i+5) % 6;
        int next = (i+1) % 6;
        if (N[prev].dir == N[next].dir) {
            if (N[i].dir == 1|| N[i].dir == 2) {
                x_subs = N[i].len;
            }
            else {
                y_subs = N[i].len;
            }
        }
    }

    area = (x_max*y_max) - (x_subs*y_subs);
    cnt = area*K;

    cout << cnt << '\n';
}

void solve() {
    input();
    solution();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}