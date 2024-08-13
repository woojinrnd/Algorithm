#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
vector<int> N(10);

void input() {
    for (int i=0; i<10; ++i) {
        cin >> N[i];
    }
}

void solution() {
    sort(N.begin(), N.end(), greater<int>());
    cout << N[2] << '\n';
}

void solve() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        //N.clear();
        input();
        solution();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}