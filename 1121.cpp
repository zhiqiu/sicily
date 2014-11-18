// Problem#: 1119
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == -1)
			return 0;
		long long num[n + 1];
		num[0] = 1;    //  初始化前面几个结果
		num[2] = 3;
		num[4] = 11;
		for (int i = 2; i <= n; i += 2) {   // n为偶数，dp
			num[i] = 3 * num[i - 2];        // 排列组合乘法原理
			for (int j = 0; j <= i - 4; j += 2)  // 排列组合加法原理
				num[i] += 2 * num[j];
		}
		if (n % 2)            // n为奇数，输出0
			cout << 0 << endl;
		else
			cout << num[n] << endl;
	}
	return 0;
}

