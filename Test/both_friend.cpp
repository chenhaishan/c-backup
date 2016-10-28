#include <iostream>

class B;
class A;
class A{
        friend void B::func(A a);
public:
        void func(B b){
                cout<<"A-->func()"<<endl;
        }
};

class B{
        friend void A::func(B b);
public:
        void func(A a){
                cout<<"A-->func()"<<endl;
        }
};

int main(){
        A a;
        B b;
        a.func(a);
        return 0;
}
