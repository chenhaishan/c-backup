#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <typename Object> 
class List
{
	
private:
	/***节点对象***/
	struct Node{
		Object data;
		Node *prev;
		Node *next;
		/***struct 不会自动生成默认构造函数***/
		Node(){}
		Node(Object x, Node *p, Node *n): data(x), prev(p), next(n){}
	};
public:
	/***迭代器类型，主要是要实现一些方法***/
	class iterator;
	class const_iterator {
		friend class List<Object>;//声明List<Object>为友元类
		/***由于const_iterator 与 iterator 不能够同时声明对方的友元成员函数
		 * 原因很简单，因为此时双方相互依赖对方声明完全，形成死循环
		 * 最简单的办法就是彼此声明成为友元类***/
		friend class iterator;
		/*
		friend bool iterator::operator= (const const_iterator &rhs);
		friend bool iterator::operator== (const const_iterator &rhs);
		friend bool iterator::operator!= (const const_iterator &rhs);
		*/
	public:
		const_iterator(): current(nullptr){
				cout<<"const_iterator(): current(nullptr)"<<endl;
		}
		const_iterator(const const_iterator &rhs)
		:const_iterator(rhs.current){
			cout<<"const_iterator(const const_iterator &rhs)"
			<<":const_iterator(rhs.current)"<<endl;
		}
		/***从iterator 初始化const_iteratro***/
		const_iterator(const iterator &rhs)
		:const_iterator(rhs.current){
				cout<<"const_iterator(const iterator &rhs)"
					<<":const_iterator(rhs.current)"<<endl;
		}
		
                const Object & operator *(){
                        cout<<"const Object & operator *() const"<<endl;
                        return current->data;;
                }

		const Object & operator *() const{
                        cout<<"const Object & operator *() const"<<endl;
                        return current->data;;
		}
		const const_iterator & operator++ (){
			cout<<"const const_iterator & operator++ ()"<<endl;
			current = current->next;
			return *this;
		}
		const const_iterator operator++ (int){
			cout<<"const const_iterator & operator++ (int)"<<endl;
			const_iterator old(current);
			++(*this);
			return old;
		}
		
		/***我添加的operator=重载***/
		const const_iterator & operator= (const const_iterator &rhs){
			cout<<"const const_iterator & operator= "
			<<"(const const_iterator &rhs)"<<endl;
			current = rhs.current;
			return *this;
		}
		/***将该函数声明为iterator的友元函数***/
		const const_iterator & operator= (const iterator &rhs){
			cout<<"const const_iterator & operator= "
			<<"(const iterator &rhs)"<<endl;
			current = rhs.current;
			return *this;
		}
		/***我添加的operator--重载***/
		const const_iterator & operator-- (){
			current = current->prev;
			return *this;
		}
		const const_iterator operator-- (int){
			const_iterator old(*this);
			/***调用前--***/
			--(*this);
			return old;
		}
		
		
		
                bool operator== (const const_iterator &rhs)const {
			cout<<"bool operator== (const const_iterator &rhs)"<<endl;
			return this->current == rhs.current;
		}
		
                bool operator!= (const const_iterator &rhs)const {
			cout<<"bool operator!= (const const_iterator &rhs)"<<endl;
			return !operator== (rhs);
		}
		/***将以下两个函数都声明为iterator的友元***/
                bool operator== (const iterator &rhs)const {
			cout<<"bool operator== (const iterator &rhs)"<<endl;
			return this->current == rhs.current;
		}
                bool operator!= (const iterator &rhs)const {
			cout<<"bool operator!= (const iterator &rhs)"<<endl;
			return !operator== (rhs);
		}
        private:
		Node *current;
                /*
		Object & retrieve() const {
			return current->data;
		}
                */
		/***将带参数的构造函数放在protected下，是为了防止List<Object>中定义的其
		 他类访问该方法。除非继承自const_iterator***/
                const_iterator(Node *p):current(p){
                    cout<<"const_iterartor(Node *p):current(p)"<<endl;
                }
	};
	
	/***iterator***/
	class iterator {
		friend class List<Object>;
		friend class const_iterator;
		/*
		friend bool const_iterator::operator =(const iterator &rhs);
		friend bool const_iterator::operator ==(const iterator &rhs);
		friend bool const_iterator::operator !=(const iterator &rhs);
		*/
	public:
		iterator(){}
		iterator(const iterator &rhs):iterator(rhs.current){
				cout<<"iterator(const iterator &rhs)"
				<<":iterator(rhs.current)"<<endl;
		}
		iterator(const const_iterator &rhs):iterator(rhs.current){
				cout<<"iterator(const const_iterator &rhs)"
				<<":iterator(rhs.current)"<<endl;
		}

                Object & operator *() const{
			cout<<"const Object & operator *() const"<<endl;
                        return current->data;
		}

		iterator & operator++(){
			cout<<"iterator & operator++()"<<endl;
			current = current->next;
			return *this;
		}
		iterator  operator++ (int){
			cout<<"iterator  operator++ (int)"<<endl;
			iterator old(*this);
			++(*this);
			return old;
		}
		iterator & operator --(){
			current = current->prev;
			return *this;
		}
		iterator  operator --(int){
			iterator old(*this);
			--(*this);
			return old;
		}
		
		iterator& operator =(const iterator &rhs){
			cout<<"iterator& operator =(const iterator &rhs)"<<endl;
			current = rhs.current;
			return *this;
		}
		
		iterator& operator =(const const_iterator &rhs){
			cout<<"iterator& operator =(const const_iterator &rhs)"<<endl;
			current = rhs.current;
			return *this;
		}
		
		bool operator== (const iterator &rhs) const{
			cout<<"bool operator== (const iterator &rhs) const"<<endl;
			return current == rhs.current;
		}
		
		bool operator== (const const_iterator &rhs) const{
			cout<<"bool operator== (const const_iterator &rhs) const"<<endl;
			return current == rhs.current;
		}
		
		bool operator!= (const iterator &rhs) const{
			cout<<"bool operator!= (const iterator &rhs) const"<<endl;
			return !operator== (rhs);
		}
		
		bool operator!= (const const_iterator &rhs) const{
			cout<<"bool operator!= (const const_iterator &rhs) const"<<endl;
			return !operator== (rhs);
		}
	private:
		Node *current;
                iterator(Node *p):current(p){
                    cout << "iterator(Node *p):current(p)"<<endl;
                }
                /*
		Object & retrieve(){
			return current->data;
		}
                */
	};
	
public:
	/***将双链表的初始化单独提取***/
	void init(){
		theSize = 0;
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
	}
	List(){
		cout<<"List()"<<endl;
		init();
	}
	List(const List &rhs){
		cout<<"List(const List &rhs)"<<endl;
		init();
		/***调用重载operatro=函数***/
		*this = rhs;
	}
        List& operator= (const List &rhs){
		cout<<"const List& operator= (const List &rhs)"<<endl;
		if(this == &rhs){
			return *this;
		}
		clear();
		for(const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr){
			push_back(*itr);
		}
		return *this;
	}
	~List(){
		cout<<"~List()"<<endl;
		/***首先删除所有除了表头节点和尾节点之外的所有节点***/
		clear();
		delete head;
		delete tail;
	}
	
	
	/***迭代器操作***/
	iterator begin(){
		cout<<"iterator begin()"<<endl;
		return iterator(head->next);
	}
	const_iterator begin() const {
		cout<<"cosnt_iterator begin() const"<<endl;
		return const_iterator(head->next);
	}
	iterator end(){
		cout<<"iterator end()"<<endl;
		return iterator(tail);
	}
	const_iterator end() const {
		cout<<"cosnt_iterator end()const"<<endl;
		return const_iterator(tail);
	}
	
	/***信息查询操作***/
	int size() const {
		return theSize;
	}
	
	bool empty() const {
		return size() == 0;
	}
	
	/***增查改删***/
	Object & front(){
		cout<<"Object & front()"<<endl;
		return *begin();
	}
	const Object & front() const {
		cout<<"const Object & front() const "<<endl;
		return *begin();
	}
	Object & back(){
		cout<<"Object & back()"<<endl;
		return *--end();
	}
	const Object & back() const {
		cout<<"const Object & back() const"<<endl;
		return *--end();
	}
	void clear(){
		cout<<"void clear()"<<endl;
		while(!empty()){
			pop_front();
		}
	}
	void pop_front(){
		cout<<"pop_front()"<<endl;
                erase(++begin());
	}
	void pop_back(){
		cout<<"pop_back()"<<endl;
		erase(--end());
	}
	void push_back(const Object & x){
		cout<<"push_back(const Object & x)"<<endl;
		insert(end(), x);
	}
	void push_front(const Object & x){
		cout<<"push_front(const Object & x)"<<endl;
		insert(begin(), x);
	}
	
	iterator erase(iterator itr){
		cout<<"iterator erase(iterator itr)"<<endl;
		Node *p = itr.current;
		iterator retval(p->next);
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
		--theSize;
		return retval;		
	}
	
	iterator erase(iterator b, iterator e){
		cout<<"iterator erase(iterator b, iterator e)"<<endl;
		for(iterator i = b; i!=e; ){
			i = erase(i);
		}
		return e;
	}
	/***前插入***/
        iterator insert (iterator itr, const Object &x){
		cout<<"iterator insert (iterator itr, const Object &x)"<<endl;
		Node *p = itr.current;
		++theSize;
		/***简练的赋值！！！***/
		Node *newNode = new Node(x, p->prev, p);
		p->prev->next = newNode;
		p->prev = newNode;
		return newNode;
		//return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
	}
	
	
private:
	int theSize;
	Node *head;//头节点
	Node *tail;//尾部节点
};

#endif
