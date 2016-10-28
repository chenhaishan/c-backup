#include <iostream>
#include <vector>
using namespace std;

struct X{
    X(){cout<<"X()"<<endl;}
    X(const X &rhs){cout<<"X(const X &)"<<endl;}
    ~X(){cout<<"~X()"<<endl;}
    X& operator= (const X &rhs){
        cout<<"operator=(const X&)"<<endl;
    }
};

int main(){
    X temp;
    vector<X> vx(10, temp);
    
    X *p = new X;
    delete p;
    return 0;
}
