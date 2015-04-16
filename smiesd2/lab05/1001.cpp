#include <iostream>
using namespace std;

class student{
    private:
        int id;
        int score;
    public:
        student(){
            id = 0;
            score = 0;
        }
        student(int a, int b): id(a), score(b){}
        void set(int a, int b){
            this->id = a;
            this->score = b;
        }
        int getid(){
            return id;
        }
        int getscore(){
            return score;
        }
};

int main() {
    student sd[5];
    
    for(int i = 0; i < 5; i++){
        int sid, score;
        cin >> sid >> score;
        sd[i].set(sid, score);
    }
    for(int i = 0; i < 5; i += 2){
        cout << (sd+i) -> getid() <<" " << (sd+i) -> getscore() << endl;
    }
    
    return 0;
}                                 
