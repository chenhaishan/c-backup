#include <iostream>
#include <memory>
using namespace std;

class A{
public:
    static int stat;
    
};

int A::stat = 10;

int main(){
    A a;
    const A &b = a;
    cout<<"a.stat: "<<a.stat<<endl;
    cout<<"b.stat: "<<b.stat<<endl;
    
    ++a.stat;
    
    cout<<"after ++a.stat, b.stat: "<<b.stat<<endl;
    
    shared_ptr<int> s1 = make_shared<int>(100);
    const shared_ptr<int> &cs = s1;
    auto s2 = s1;
    *s2 = 1000;
    cout<<cs.use_count()<<endl;
    cout<<*cs<<endl;
    return 0;
}
