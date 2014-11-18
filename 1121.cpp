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
		num[0] = 1;    //  ��ʼ��ǰ�漸�����
		num[2] = 3;
		num[4] = 11;
		for (int i = 2; i <= n; i += 2) {   // nΪż����dp
			num[i] = 3 * num[i - 2];        // ������ϳ˷�ԭ��
			for (int j = 0; j <= i - 4; j += 2)  // ������ϼӷ�ԭ��
				num[i] += 2 * num[j];
		}
		if (n % 2)            // nΪ���������0
			cout << 0 << endl;
		else
			cout << num[n] << endl;
	}
	return 0;
}

