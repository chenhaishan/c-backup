#include <iostream>
#include <memory>
#include <list>
#include "X.h"

using namespace std;

int main()
{
    shared_ptr<X> sx = make_shared<X>();
    shared_ptr<Y> sy = make_shared<Y>();
    sy->registerX(sx.get());
    sx->change(10, 'a');

    shared_ptr<int> s_ptr = make_shared<int>(10);
    cout<<"count: "<<s_ptr.use_count()<<endl;
    weak_ptr<int> w_ptr(s_ptr);
    cout<<"count: "<<s_ptr.use_count()<<endl;
    shared_ptr<int> s_ptr1(w_ptr.lock());
    cout<<"count: "<<s_ptr.use_count()<<endl;
    shared_ptr<int> s_ptr2 = w_ptr.lock();
    cout<<"count: "<<s_ptr.use_count()<<endl;
    return 0;
}
