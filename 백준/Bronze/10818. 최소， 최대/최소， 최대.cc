#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	int N;
	cin >> N;
	int *A = new int[N]; 
	for (int i=0; i<N; ++i) {
		cin >> A[i];
	}
	int min = *(min_element(A, A+N));
	int max = *(max_element(A, A+N));
	
	cout << min << " " << max;
	
	delete[] A;
	
	return 0;
}