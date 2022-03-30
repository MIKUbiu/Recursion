#include<iostream>
#include<vector>
using namespace std;
int dp[10000];
int a[] = {1,2,4,5,10};
int change(int x) {
	if (dp[x] != 0)return dp[x];
	if (find(a,a+5,x)!=a+5)
		//find在数组a里面找不到时，
		//会返回一个迭代器指向数组最后一个元素的下一个位置
	return dp[x]=1;
	int best = x;//表示钱都用1元表示
	for (int i = 0; i < 5; i++) {
		if (x >a[i])best = min(change(x -a[i])+1,best);
	}
	return dp[x]=best;
}
int main() {
	int n;
	cin >> n;
	cout << change(n);
	return 0;
}
