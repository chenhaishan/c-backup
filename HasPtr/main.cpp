#include <iostream>
#include <string>
#include <utility>

using namespace std;

class HasPtr{
private:
    string *ps;
    int i;
public:
    explicit HasPtr(const string &s = string())
        :ps(new string(s)), i(0){
        cout << "HasPtr(const string &s = string())" << endl;
    }
/*
    HasPtr& operator= (HasPtr rhs){
        //swap(*this, rhs);
        string *tmp = ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = tmp;
        return *this;
    }
*/
    HasPtr(const HasPtr &p):
        ps(new std::string(*(p.ps))),
        i(p.i){
        cout << "HasPtr(const HasPtr &p)" << endl;
    }

    HasPtr& operator= (const HasPtr &other){
        if(this != &other){
            string *old = ps;
            ps = other.ps;
            i = other.i;
            free(old);
        }
        return *this;
    }

    //move constructor
    explicit HasPtr(HasPtr &&p)noexcept:ps(p.ps), i(p.i){
        p.ps = 0;
        cout << "HasPtr(HasPtr &&)" << endl;
    }


};

int main()
{
    string *sp = new string("world");
    string *sp1 = new string(*sp);
    cout << "sp: "<< *sp << endl
         << "sp1: " << *sp1 << endl;
    HasPtr hp("hello");
    HasPtr hp2 = hp;
    HasPtr hp3("world");
    HasPtr hp4(std::move(hp));
    hp3 = hp2;
    //HasPtr &&hp5 = std::move(hp3);

    return 0;
}
