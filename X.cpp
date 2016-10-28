#include "X.h"
#include <memory>
#include <iostream>
using namespace std;

X::X(int j, char d):i(j), c(d)
{
}

void X::registerY(Y *y){
    wy = make_shared<Y>(*y);
}

void X::check_reg(){
    if(wy.lock()){
        cout<<"registered!"<<endl;
    }
    else{
        cout<<"don't register"<<endl;
    }
}

void X::change(int j, char d){
    i = j;
    c = d;
    notify();
}
    
void X::notify(){
    if(wy.lock()){
        wy.lock()->update(i, c);
    }
    else{
        cout<<"Y is not registerd"<<endl;
    }
}

void Y::registerX(X *x){
    wx = make_shared<X>(*x);
    x->registerY(this);
}

void Y::update(int j, char d){
    i = j;
    c = d;
    cout<<"updated:?"<<endl<<"i:"<<i<<","<<"c: "<<c<<endl;
}
