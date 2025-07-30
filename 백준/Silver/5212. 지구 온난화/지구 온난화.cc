#include <iostream>
#include <queue>

using namespace std;

int R, C;
int island;
char N[10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
    bool Island;
};
point A[100];
point B[100];

void input() {
    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> N[i][j];
            if (N[i][j] == 'X') {
                A[island++] = {i, j, false};
            }
        }
    }
}

bool SeaCount(int x, int y) {
    int cnt = 0;
    for (int dir=0; dir<4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx<0||nx>=R||ny<0||ny>=C) {
            cnt++;
            continue;
        }
        if (N[nx][ny]=='.') cnt++;
    }
    if (cnt >= 3) return true;
    return false;
}

void ChangeMap() {
    for (int i=0; i<island; ++i) {
        if (SeaCount(A[i].x, A[i].y) == true) {
            A[i].Island = true;
        }
    }
    
    for (int i=0; i<island; ++i) {
        if (A[i].Island == true) {
            N[A[i].x][A[i].y] = '.';
        }
    }
}

void GetIsalnd() {
    island = 0;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            if (N[i][j] == 'X') {
                B[island++] = {i, j};
            }
        }
    }

    // for (int i=0; i<island; ++i) {
    //     cout << B[i].x << B[i].y << '\n';
    // }
}

void printMap() {
    int x_min = R;
    int x_max = 0;
    int y_min = C;
    int y_max = 0;
    for (int i=0; i<island; ++i) {
        if (B[i].x < x_min) {
            x_min = B[i].x;
        }
        if (B[i].x > x_max) {
            x_max = B[i].x;
        }
        if (B[i].y < y_min) {
            y_min = B[i].y;
        }
        if (B[i].y > y_max) {
            y_max = B[i].y;
        }
    }
    // cout << x_min << ' ' << x_max << '\n';
    // cout << y_min << ' ' << y_max << '\n';

    for (int i=x_min; i<=x_max; ++i) {
        for (int j=y_min; j<=y_max; ++j) {
            cout << N[i][j];
        }
        cout << '\n';
    }
}

void show() {
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cout << N[i][j]; 
        }
        cout << '\n';
    }
}

// 1. 각 섬에 대하여 인접한 바다의 개수 구하기
// 2. 바다의 개수가 >= 3 이면, 'X' -> '.'으로 바꾸기
// 3. 최외곽 X
void solution() {
    ChangeMap();
    GetIsalnd();
    // show();
    printMap();
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