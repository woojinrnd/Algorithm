#include <iostream>
using namespace std;

#define MAX 1000005

int N;
int A[MAX];
int B, C;
long long res; // 반드시 long long!

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> B >> C;
}

void solution() {
    res = 0;
    for (int i = 0; i < N; ++i) {
        // 총감독관 1명
        res += 1;
        int remain = A[i] - B;
        if (remain > 0) {
            // ceil(remain / C)
            res += (remain + C - 1) / C;
        }
    }
    cout << res << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();
    return 0;
}
