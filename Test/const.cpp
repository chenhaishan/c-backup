#include <iostream>
#include <cstring>
using namespace std;
class A{
public:
        A(){
                s = new char[10];
        }
        void sets(const char *ss) const;
private:
        char *s;
};


void A::sets(const char *ss) const {
        for (int i = 0; i < strlen(ss); ++i){
                //s[i] = ss[i];
                (this->s)[i] = ss[i];
        }
}

int main(){
        const A a;
        a.sets("hello");
        return 0;
}
