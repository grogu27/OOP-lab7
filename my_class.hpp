#include <iostream>
#include <stdexcept>
//#include "my_class.tpp"
using namespace std;

template <class T>
class List {
protected:
	T data;
	List* next;
	int elements;
public:
	List();
	List(T data);

	int GetElements();

	void add(T value);

	T get_back();

	void pop_front();
	
	void pop_back();
	
	void print();

	~List();

};

template <class T>
class Stack : public List<T> {
private:
	static int count;
public:
	Stack() ;
	Stack(T data);
	void push(T data);

	T getTop();

	T pop();

	static int getCount();

};

template <class T>
class Queue : public List<T> {
public:
	Queue();
	Queue(T data) ;

	void enqueue(T data);

	T dequeue();

	T getFirst();
};

