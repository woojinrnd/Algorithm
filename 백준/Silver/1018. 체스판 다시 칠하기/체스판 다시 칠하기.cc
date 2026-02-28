#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char map[51][51];
char target_map[8][8];
int cnt = 64;   // 최대 64칸이므로 64로 초기화

char ref_map_white[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

char ref_map_black[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
}

void solution() {

    for (int start_y = 0; start_y <= N - 8; ++start_y) {
        for (int start_x = 0; start_x <= M - 8; ++start_x) {

            // 8x8 잘라서 target_map에 저장
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    target_map[i][j] = map[start_y + i][start_x + j];
                }
            }

            // white 시작 비교
            int tmp_white = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (target_map[i][j] != ref_map_white[i][j])
                        tmp_white++;
                }
            }

            // black 시작 비교
            int tmp_black = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (target_map[i][j] != ref_map_black[i][j])
                        tmp_black++;
                }
            }

            // 최소값 갱신
            cnt = min(cnt, min(tmp_white, tmp_black));
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solution();
    
    return 0;
}