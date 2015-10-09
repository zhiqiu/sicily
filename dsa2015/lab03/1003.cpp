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
		stack <char> op;
		for(int i=0; i<strlen(str); i++){
			char c = str[i];
			//cout << "   " << c << " ";
			//if(!op.empty()) cout << op.top() << endl;
			//else cout << endl;
			if(('a' <= c && c <= 'z')||('A' <= c && c <= 'Z'))
				cout << c ;
			else{
				if(op.empty())   op.push(c);
				else{
					if(c == '(')  op.push(c);
					if(c == ')')  {
						while(op.top()!='('){
							cout << op.top() ;
							op.pop();
						}
						//cout << op.top();
						op.pop();
					}
					if(c == '+'||c == '-'){
						while(!op.empty()&&op.top()!='('){
							cout << op.top();
							op.pop();
						}
						op.push(c);
					}
					if(c == '*'||c == '/'){
						while(op.top()!='('&&op.top()!='+'&&op.top()!='-'){
							cout << op.top();
							op.pop();
						}
						op.push(c);
					}
				}
			}
		}
		while(!op.empty()){
			cout << op.top();
			op.pop();
		}
		cout << endl;
	}
	
	return 0;
}


