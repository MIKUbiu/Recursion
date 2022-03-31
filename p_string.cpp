#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
const int maxn = 1E6;
int dp[1000][1000];
int main() {
	string s;
	cin >> s;
	int n = s.size();
	if (n < 2) {
		cout << s;
	}
	int maxlen = 1;
	int begin = 0;
	//vector<vector<int>>dp(n, vector<int>(n));这里面的vector<int>(n)是干啥的
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	//从下往上递归
	for(int L = 2;L<= n;L++){//从长度为2的字符串长度开始遍历
		for (int i = 0; i < n; i++) {
			int j = L + i - 1;
			if (j >= n)break;//j是下标
			if (s[i] != s[j])dp[i][j]=0;//最左边的字符和最右边的字符不相等
			else 
				if (j - i < 3)dp[i][j]=1;//j-i+1=3<4，最左边和最右边相等时，长度又小于4时是回文串
				else dp[i][j] = dp[i + 1][j - 1];//判断子串是不是回文串
			
			if (dp[i][j] && j - i + 1 > maxlen) {//找到最长回文串更新首标和最低长度
				maxlen = j - i + 1;
				begin = i;
			}

		}
		
	}
	//string::iterator it = &s[begin];//我想用迭代器输出从固定下标输出长度固定的字符串
	for (int i = begin; i < maxlen; i++) {
		cout << s[i];
	}
	return 0;
}
