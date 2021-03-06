#ifndef X_H
#define X_H

#include <memory>
using namespace std;
class Y;
class X{
friend class Y;
private:
    int i;
    char c;
    weak_ptr<Y> wy;
public:
    X(int j=0, char d=0);
    void registerY(Y *y);
    void check_reg();
    
    void change(int j, char d);
    
    void notify();
};


class Y{
friend class X;
private:
    int i;
    char c;
    weak_ptr<X> wx;
public:
    //Y(int j=0, char d=0):i(j), c(d){}
    void registerX(X *x);
    
    void update(int j, char d);
};


#endif
