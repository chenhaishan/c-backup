#include <iostream>
#include <list>
using namespace std;

union test{
        double d;
        char c;
        int i;
};

int main(){
        list<test> lt;
        test newtest={3.90};
        lt.push_back(newtest);
        cout<<(lt.front()).d<<endl;
        cout<<(lt.front()).c<<endl;
        cout<<(lt.front()).i<<endl;
        return 0;
}
