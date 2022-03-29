#include<iostream>
#include<vector>
using namespace std;
int combinatorial(int a, int b) {
	//主要是推导递归过程C(a,b)=C(a - 1, b) + C(a - 1, b - 1)
	if (a == b || b == 0) return 1;//递归终点
	else return combinatorial(a - 1, b) + combinatorial(a - 1, b - 1);
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		cout << combinatorial(n, m)<<endl;
	}
	return 0;
}
