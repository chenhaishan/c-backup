#ifndef STACK_LIST_H
#define STACK_LIST_H
#include "stack_exceptions.h"
template <typename Object>
class Stack{

public:
	Stack():theSize(0), theCapacity(SAPARE_SIZE){
		objects = new Object[theCapacity];
	}
	Stack(const Stack &s){
		theSize = s.theSize;
		reserve(s.theCapacity);
		for(auto i = s.begin(); i != s.end(); ++i){
			s.push(*i);
		}
	}
	Stack & operator= (const Stack &rhs){
		clear();
		theSize = rhs.theSize;
		reserve(rhs.theCapacity);
		for(auto i = rhs.begin(); i != rhs.end(); ++i){
			push(*i);
		}
	}
	void reserve(int newSize){
		if(theCapacity >= newSize)
			return ;
		Object *old = objects;
		objects = new Object[newSize];
		for(int i = 0; i < theSize; ++i){
			objects[i] = old[i];
		}
		theCapacity = newSize;
		delete [] old;
	}
	typedef Object * iterator;
	typedef const Object * const_iterator;
	const_iterator begin() const{
		return &objects[0];
	}
	iterator begin(){
		return &objects[0];
	}
	const_iterator end() const {
		return &objects[theSize-1];
	}
	iterator end(){
		return &objects[theSize-1];
	}
	
	void clear(){
		theSize = 0;
		theCapacity = SAPARE_SIZE;
		Object *old = objects;
		objects = new Object[theCapacity];
		delete [] old;
	}
	
	void push(const Object &x){
		if(theSize == theCapacity)
			reserve(theSize *2 + 1);
		objects[theSize++] = x;
	}
	
	Object pop(){
		if(empty()){
			throw OutofStack();
		}
		else{
			--theSize;
			return objects[theSize];
		}
	}
	
	bool empty(){
		return !theSize;
	}
	
	int size(){
		return theSize;
	}
	
	Object top(){
		if(empty())
			throw EmptyStack();
		return objects[theSize -1];
	}
	enum{SAPARE_SIZE = 10};
private:
	int theSize;
	int theCapacity;
	Object *objects;
	
};

#endif