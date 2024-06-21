#include <iostream>

using namespace std;

string A, B;
int freqA[26], freqB[26];
int res;

void input() {
    cin >> A >> B;
}

void solution() {
    for (char i : A) {
        freqA[i - 'a']++;
    }
    for (char i : B) {
        freqB[i - 'a']++;
    }
    for (int i=0; i<26; ++i) {
        res += abs(freqA[i] - freqB[i]);
    }

    cout << res << '\n';
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