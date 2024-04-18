#include <iostream>
#include <list>
#include <string>

using namespace std;

int Tc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Tc;
	while(Tc--) {
		string s;
		cin >> s;
		list<char> L;
		list<char>::iterator cursor = L.begin();
		for (auto c : s) {
			if (c == '<') {
				if (cursor != L.begin()) {
					--cursor;
				}
			}
			else if (c == '>') {
				if (cursor != L.end()) {
					++cursor;
				}
			}
			else if (c == '-') {
				if (cursor != L.begin()) {
					--cursor;
					cursor = L.erase(cursor);
				}
			}
			else {
				L.insert(cursor, c);
			}
		}	
		for (auto i : L) {
			cout << i;
		}
		cout << '\n';
	}
	
	return 0;
}