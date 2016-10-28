#include "Stack_List.h"
#include <iostream>
using namespace std;
int main(){
	Stack<int> SI;
	for(int i = 0; i < 5; ++i)
		SI.push(i);
	for(int i = 0; i< 5; ++i){
		cout<<SI.top()<<endl;
		SI.pop();
	}
	try{
		SI.top();
	}
	catch(OutofStack){
		cout<<"OutofStack"<<endl;
	}
	catch(EmptyStack){
		cout<<"EmptyStack"<<endl;
	}
	
	try{
		SI.pop();
	}
	catch(OutofStack){
		cout<<"OutofStack"<<endl;
	}
	catch(EmptyStack){
		cout<<"EmptyStack"<<endl;
	}
	return 0;
}