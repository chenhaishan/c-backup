#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include <vector>
#include "binaryheapexceptins.h"
using namespace std;

template <typename Comparable>
class BinaryHeap{
	template <typename Object>
    friend void printheap(BinaryHeap<Object> &bh);
private:
	int currentsize;//当前节点的数量
	vector<Comparable> array;
    void buildHeap(){
        for(int hole=currentsize/2; hole > 0; --hole){
            precolateDown(hole);
        }
    }

    void precolateDown(int hole){
        int child;
        Comparable tmp = array[hole];
        for(;hole *2 <= currentsize; hole = child){
            child = hole*2;
            if(child !=currentsize && array[child+1] < array[child])
                ++child;
            if(array[child] < tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[child] = tmp;
    }

	void precolateUp(int hole);

public:
    explicit BinaryHeap(int capacity = 100):currentsize(0){
        if(capacity <1){
            cout<<"capacity should be postive!"<<endl;
            throw CapacityError();
        }
        array.resize(capacity);
    }

    explicit BinaryHeap(const vector<Comparable> & v){
        makeEmpty();
		if(array.size() < v.size()){
			array.resize(v.size() *2);
		}
		currentsize = v.size();
        for(int i = 1; i <= v.size(); ++i){
            array[i] = v[i-1];
        }
        buildHeap();
    }

    bool isEmpty(){
        return currentsize==0?true:false;
    }

    const Comparable & findMin() const{
        return &array[1];
    }

    void insert(const Comparable &x){
        if(currentsize == array.size()-1){
            array.resize(array.size() *2);
        }
        int hole = ++currentsize;
        for(;hole >1 && x < array[hole/2]; hole /=2){
            array[hole] = array[hole/2];
        }
        array[hole] = x;
    }

    void deleteMin(){
        if(isEmpty()){
            throw UnderflowExcpetion();
        }
        array[1] = array[currentsize--];
        precolateDown(1);
    }

    void deleteMin(Comparable &minItem){
        if(isEmpty()){
            throw UnderflowExcpetion();
        }
        minItem = array[1];
        array[1] = array[currentsize--];
        precolateDown(1);
    }

    void makeEmpty(){
        currentsize = 0;
        //array.resize(0);
    }
};

template <typename Object>
void printheap(BinaryHeap<Object> &bh){
    for(int i = 1; i <=bh.currentsize; ++i){
        cout<<(bh.array)[i]<<endl;
    }
}


#endif
