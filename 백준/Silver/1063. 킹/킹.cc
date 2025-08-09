#include <iostream>
#include <string>
using namespace std;

int n;
string cmd[50];

// R L B T RT LT RB LB
int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct point {
    int x, y; // x=행(row), y=열(col)
};

point pos_king, pos_stone;

int findDir(const string& CMD) {
    if (CMD == "R") return 0;
    if (CMD == "L") return 1;
    if (CMD == "B") return 2;
    if (CMD == "T") return 3;
    if (CMD == "RT") return 4;
    if (CMD == "LT") return 5;
    if (CMD == "RB") return 6;
    if (CMD == "LB") return 7;
    return -1;
}

bool inRange(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void input() {
    string King, Stone;
    cin >> King >> Stone >> n;
    pos_king = { '8' - King[1], King[0] - 'A' };
    pos_stone = { '8' - Stone[1], Stone[0] - 'A' };
    for (int i = 0; i < n; ++i) {
        cin >> cmd[i];
    }
}

void solution() {
    for (int i = 0; i < n; ++i) {
        int dir = findDir(cmd[i]);
        int nkx = pos_king.x + dx[dir];
        int nky = pos_king.y + dy[dir];

        if (!inRange(nkx, nky)) continue; // 킹이 밖으로 나가면 무시

        // 돌과 부딪히는 경우
        if (nkx == pos_stone.x && nky == pos_stone.y) {
            int nsx = pos_stone.x + dx[dir];
            int nsy = pos_stone.y + dy[dir];
            if (!inRange(nsx, nsy)) continue; // 돌이 나가면 무시
            pos_stone = { nsx, nsy };
        }
        pos_king = { nkx, nky };
    }

    cout << char(pos_king.y + 'A') << char('8' - pos_king.x) << '\n';
    cout << char(pos_stone.y + 'A') << char('8' - pos_stone.x) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solution();
    return 0;
}
