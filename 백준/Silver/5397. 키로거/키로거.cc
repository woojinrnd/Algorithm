#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    // C++ 표준 입출력과 동기화를 끊어줌으로써 입출력 성능 향상
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 테스트 케이스의 개수 입력
    int t;
    cin >> t;

    // 테스트 케이스 반복
    while (t--) {
        // 문자열을 저장할 리스트 및 iterator 초기화
        list<char> lis;
        list<char>::iterator iter = lis.begin();
        
        // 문자열 입력
        string s;
        cin >> s;

        // 입력된 문자열 순회
        for (auto c : s) {
            // '-'인 경우 현재 iterator의 이전 원소 삭제
            if (c == '-') {
                if (iter != lis.begin())
                    iter = lis.erase(--iter);
            }
            // '<'인 경우 iterator를 이전으로 이동
            else if (c == '<') {
                if (iter != lis.begin())
                    iter--;
            }
            // '>'인 경우 iterator를 다음으로 이동
            else if (c == '>') {
                if (iter != lis.end())
                    iter++;
            }
            // 그 외의 경우 현재 iterator 위치에 문자 추가
            else
                lis.insert(iter, c);
        }

        // 결과 출력
        for (auto a : lis)
            cout << a;
        cout << '\n';
    }
    return 0;
}
