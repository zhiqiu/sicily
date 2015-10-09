#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
char str[110];

int main(){
	int n;
	cin >> n;
	while(n--){
		cin >> str;
		stack<char> bracket;
		int ok = 1;
		for(int i=0; i<strlen(str); i++){
			char c = str[i];
			if(c=='(' || c=='[' || c=='{'){
				bracket.push(c);
			}
			if(c==')'){
				if((!bracket.empty())&& bracket.top()=='('){
					bracket.pop();
				}
				else 
					ok = 0;
			}
			if(c==']'){
				if((!bracket.empty())&& bracket.top()=='[')
					bracket.pop();
				else 
					ok = 0;
			}
			if(c=='}'){
				if((!bracket.empty())&& bracket.top()=='{')
					bracket.pop();
				else 
					ok = 0;
			}
		}
		if(!bracket.empty())  ok = 0;
		if(ok)  cout << "Yes" << endl;
		else    cout << "No" << endl;
	}
	return 0;
}
