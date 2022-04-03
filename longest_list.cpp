#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const int maxn = 1E6;
int dp[maxn];
int a[1000+10];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		dp[0] = a[0];
		for (int i = 0; i < n; i++) {
			dp[i] = max(dp[i], dp[i - 1] + a[i]);//在前一项的最大和和本身中选一个
		}
		cout << *max_element(dp, dp + n) << endl;
	}
	return 0;
}
