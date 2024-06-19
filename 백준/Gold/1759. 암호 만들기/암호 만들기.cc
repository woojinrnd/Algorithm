#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<char> N;     // 입력값
vector<char> comb;  // 현재 조합

void input() {
    cin >> n >> m;
    N.resize(m);
    for (int i=0; i<m; ++i) {
        cin >> N[i];
    }
    // 오름차순 정렬
    sort(N.begin(), N.end());
}

void print() {
    for (char i : comb) {
        cout << i;
    }
    cout << '\n';
}

bool valid() {
    int cnt1 = 0; // 모음
    int cnt2 = 0; // 자음
    for (char i : comb) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') 
            cnt1++;
        else 
            cnt2++;
    }

    if (cnt1>=1 && cnt2>=2) return true;

    return false;
}

void dfs(int idx, int cnt) {
    if (cnt == n) {
        if (valid())
            print();
        return ;
    }

    for (int i=idx; i<m; ++i) {
        comb.push_back(N[i]);
        dfs(i+1, cnt+1);
        comb.pop_back();
    }
}

void solution() {
    dfs(0, 0);
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