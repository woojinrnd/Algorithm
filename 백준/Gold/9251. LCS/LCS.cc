#include <iostream>
#include <string>
// #include <cstring>
#include <algorithm>

using namespace std;


// 완전 탐색 방법
// 부분 수열 구한다.
// 겹치는 개수를 구한다.

// 부분 수열을 구한다
// 1. 길이가 1,2,3,...n개
// 2. 같이 길이의 집합에서 비교한다.
// 3. 비교 후 같다면 겹치는 개수에 더해준다.


// DP
// 동일열에서 비교
// 1. 같다면    +1
// 2. 다르다면  각각의 문자를 넣었을 때의 더 큰값으로

#define MAX 1001

string A, B;
int dp[MAX][MAX];

void input() {
    getline(cin, A);
    getline(cin, B);
}

void show() {
    cout << A << '\n'; 
    cout << B << '\n';

    for (int i=1; i<=A.length(); ++i) {
        for (int j=1; j<=B.length(); ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

void findLCS() {
    string lcs;
    int i = A.length();
    int j = B.length();

    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            lcs += A[i-1];
            --i;
            --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    cout << lcs << '\n';
}

void solution() {
    // A[i]을 기준으로 B[1~n] 까지 비교
    for (int i=1; i<=A.length(); ++i) {
        for (int j=1; j<=B.length(); ++j) {
            // 같다면
            if (A[i-1] == B[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            // 다르다면
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[A.length()][B.length()] << '\n';
}

void solve() {
    input();
    solution();
    // show();
    // findLCS();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}