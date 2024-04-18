#include <iostream>
#include <list>

using namespace std;

list<char> L;
string s;
int q; // command number

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	for (int i=0; i<s.size(); ++i) {
		L.push_back(s[i]);
	}
	// init cursor position
	list<char>::iterator cur = L.end();
	cin >> q;
	while(q--) {
		char c;
		cin >> c;
		switch (c) {
			case 'P' : 
				char add;
				cin >> add;
				L.insert(cur, add);
				break;
			case 'B' :
				if (cur != L.begin()) {
					cur--;
					cur = L.erase(cur);
				}
				break;
			case 'L' :
				if (cur != L.begin()) {
					cur--;
				}
				break;
			case 'D' :
				if (cur != L.end()) {
					cur++;
				}
				break;
		}
	}
	for (auto i : L) {
		cout << i;
	}
	
	return 0;
}