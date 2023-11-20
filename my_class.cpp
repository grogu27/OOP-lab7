#include "my_class.hpp"

using namespace std;

    template <class T>
	List<T>::List() : next(nullptr), data(0), elements(0) {}

    template <class T>
	List<T>::List(T data) : data(data), next(nullptr), elements(1) {}

    template <class T>
	int List<T>::GetElements() {
		return elements;
	}

    template <class T>
	void List<T>::add(T value) {
		if (!elements) {
			data = value;
			elements += 1;
			return;
		}
		List* node = this;
		while (node->next != nullptr) {
			node = node->next;
		}
		node->next = new List<T>(value);
		elements += 1;
	}

    template <class T>
	T List<T>::get_back() {
		if (!elements) return -1;
		List* node = this;
		List* parent = nullptr;
		while (node->next != nullptr) {
			parent = node;
			node = node->next;
		}
		return node->data;
	}

    template <class T>
	void List<T>::pop_front() {
		List<T>* node = this;
		List<T>* parent = nullptr;
		while (node->next != nullptr) {
			node->data = node->next->data;
			parent = node;
			node = node->next;
		}
		if (parent != nullptr) {
			parent->next = nullptr;
		}
		elements -= 1;
		delete node;
	}

    template <class T>
	void List<T>::pop_back() {
		if (!elements) return;
		List* node = this;
		List * parent = nullptr;
		while (node->next != nullptr) {
			parent = node;
			node = node->next;
		}
		if (parent != nullptr) { 
			parent->next = nullptr;
		}
		delete node;
		elements -= 1;

	}
	
    template <class T>
	void List<T>::print() {
		if (this->elements == 0) {
			cout << "List is Empty!" << endl;
			return;
		}
		T value = data;
		List* node = this;
		for (int i = 0; i < elements; i++) {
			cout << value << " ";
			node = node->next;
			if (node == nullptr) {
				cout << "\n";
				return;
			}
			value = node->data;
		}
		cout << "\n";
	}

    template <class T>
	List<T>::~List() {
		if (next != nullptr) {
			delete next;
		}
	}


    template <class T>
	Stack<T>::Stack() : List<T>::List() {}

    template <class T>
	Stack<T>::Stack(T data) : List<T>(data) { count++; }

    template <class T>
	void Stack<T>::push(T data){
		List<T>::add(data);
		count++;
	};

    template <class T>
	T Stack<T>::getTop() {
		if (this->elements == 0) throw runtime_error("Stack is EMPTY!");
		return List<T>::get_back();
	};

    template <class T>
	T Stack<T>::pop() {
		if (this->elements == 0) throw runtime_error("Stack is EMPTY!");
		T result = this->get_back();
		this->pop_back();
		count--;
		return result;
	}

    template <class T>
	int Stack<T>::getCount() {
		return count;
	}


    template <class T>
	Queue<T>::Queue() : List<T>::List() {}

    template <class T>
	Queue<T>::Queue(T data) : List<T>(data) {}

    template <class T>
	void Queue<T>::enqueue(T data) {
		List<T>::add(data);
	};
    
    template <class T>
	T Queue<T>::dequeue() {
		if (!this->elements) throw runtime_error("Queue is EMPTY!");
		T result = this->data;
		this->pop_front();
		return result;
	}

    template <class T>
	T Queue<T>::getFirst() {
		if (!this->elements) throw runtime_error("Queue is EMPTY!");
		return this->data;
	};

template <class T>
int Stack<T>::count = 0;
