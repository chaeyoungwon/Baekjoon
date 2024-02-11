#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int lo = 0;
	int hi = n - 1;
	int resLo = lo, resHi = hi;

	while (lo < hi) {
		int resSub = abs(v[hi] + v[lo]);
		if (abs(v[resHi] + v[resLo]) > resSub) {
			resHi = hi;
			resLo = lo;
		}

		if (v[hi] + v[lo] > 0) {
			hi -= 1;
		}
		else if (v[hi] + v[lo] == 0) {
			break;
		}
		else {
			lo += 1;
		}
	}

	cout << v[resLo] << " " << v[resHi];
	return 0;
}