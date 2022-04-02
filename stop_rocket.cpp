#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1E6;
int dp[maxn]; int a[10000];
int main() {
	int T;
	while (cin >> T) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));//每次重新输入重置数组
		for (int i = 0; i < T; i++) {
			cin >> a[i];
		}
		dp[0] = 1;
		for (int i = 1; i < T; i++) {
			dp[i] = 1;//初始化每个dp[i]的值如果前面没有比自己大的子序列，则返回自身
			for (int j = 0; j < i; j++) {
				if (a[i] <= a[j]) {
					dp[i] = max(dp[j] + 1, dp[i]);//寻找比自己大的前i-1个最长子序列的最大值加上本身
				}
			}
		}
		cout << *max_element(dp, dp + T) << endl;
	}
	return 0;
}
