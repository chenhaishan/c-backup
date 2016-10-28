#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
class A{
public:
        explicit void func()const{
                cout<<"const"<<endl;
        }
        explicit void func(){
                cout<<"non-const"<<endl;
        }
};
*/

explicit void f(const int* ptr)
{
	cout<<*ptr<<"const"<<endl;
}

/*
void f(int *ptr){
	cout<<*ptr<<"non-const"<<endl;
}
*/


int main(){
/*
        A a;
        const A b;
        a.func();
        b.func();
*/      
 	int i = 10;
	int j = 20;
	int *ptr = &i;
	const int *cptr = &j;
	f(ptr);
	f(cptr);       
        
        return 0;
}
