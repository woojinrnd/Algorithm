#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 510

int H, W, Ans;
int Height[MAX];

void input() {
    cin >> H >> W;
    for (int i=1; i<=W; ++i) cin >> Height[i];
}

// 해당 열을 제외한, 나머지 열들의 높이에 의해서 결정
// 나머지 열들은 해당 열을 기준으로, left, right가 나누어짐
// 빗물 = min(left, right) - 해당열의 높이
void solution() {
    for (int i=2; i<W; ++i) {
        int left, right;
        left = right = 0;
        
        for (int j=1; j<i; ++j) left = max(left, Height[j]);
        for (int j=i+1; j<=W; ++j) right = max(right, Height[j]);
        int res = min(left, right) - Height[i];
        if (res >= 0) Ans += res;
    }
    cout << Ans << '\n';
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