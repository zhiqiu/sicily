#include <iostream>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;
char str[110];
int main(){
	int n;
	cin >> n;

	while(n--){
		cin >> str;
		stack <float> ep;
		for(int i=0; i<strlen(str); i++){
			char c = str[i];
			if('a' <= c && c <= 'z')
				ep.push(c-'a'+1);
			else{
				float b = ep.top(); ep.pop();
				float a = ep.top(); ep.pop();
				if(c == '+')  ep.push(a+b);
				if(c == '-')  ep.push(a-b);
				if(c == '*')  ep.push(a*b);
				if(c == '/')  ep.push(a/b);
			}
		}

		cout << fixed << setprecision(2) << ep.top() << endl;
	}
	return 0;
}


