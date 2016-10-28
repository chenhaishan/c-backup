#include <iostream>
#include <memory>
using namespace std;

int main()
{
    int *p = new int(100);
    shared_ptr<int> s1(p);
    cout << "s1.use_count(): "<<s1.use_count()<<endl;
    shared_ptr<int> s2(p);
    cout << "s2.use_count(): "<<s2.use_count()<<endl;
    
    s1.reset();
    if(s2){
        cout<<"after s1.reset(), s2.use_count(): "<<s2.use_count()<<endl;
    }else{
        cout<<"after s1.reset(), memory is freed "<<endl;
    }
    
    
    return 0;
}
