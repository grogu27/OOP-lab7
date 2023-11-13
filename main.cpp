#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class List {
protected:
	T data;
	List* next;
	int elements;
public:
	List() : next(nullptr), data(0), elements(0) {};
	List(T data) : data(data), next(nullptr), elements(1) {};

	int GetElements() {
		return elements;
	}

	void add(T value) {
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

	T get_back() {
		if (!elements) return NULL;
		List* node = this;
		List* parent = nullptr;
		while (node->next != nullptr) {
			parent = node;
			node = node->next;
		}
		return node->data;
	}

	void pop_front() {
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

	void pop_back() {
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
	
	void print() {
		if (!elements) {
			cout << "Stack is Empty!" << endl;
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

	~List() {
		if (next != nullptr) {
			delete next;
		}
	}
};

template <class T>
class Stack : public List<T> {
private:
	static int count;
public:
	Stack() : List<T>::List() {};
	Stack(T data) : List<T>(data) { count++; }
	void push(T data){
		List<T>::add(data);
		count++;
	};
	T getTop() {
		if (!this->elements) throw runtime_error("Stack is EMPTY!");
		return List<T>::get_back();
	};
	T pop() {
		if (!this->elements) throw runtime_error("Stack is EMPTY!");
		T result = this->get_back();
		this->pop_back();
		count--;
		return result;
	}
	static int getCount() {
		return count;
	}
};

template <class T>
class Queue : public List<T> {
public:
	Queue() : List<T>::List() {};
	Queue(T data) : List<T>(data) {}

	void enqueue(T data) {
		List<T>::add(data);
	};
	T dequeue() {
		if (!this->elements) throw runtime_error("Stack is EMPTY!");
		T result = this->data;
		this->pop_front();
		return result;
	}
	T getFirst() {
		if (!this->elements) throw runtime_error("Stack is EMPTY!");
		return this->data;
	};
};

template <class T>
int Stack<T>::count = 0;

int main() {
	cout << "> Stack" << endl;
	Stack<float> stack(5);
	stack.push(6);
	stack.push(1);
	stack.push(3);
	stack.push(5);
	stack.push(0);

    stack.print();
    cout << "Top: " << stack.getTop() << endl;
	cout << "Elements: " << stack.GetElements() << endl;
    cout << endl;

	cout << "stack pop: " << stack.pop() << endl;
	cout << "stack pop: " << stack.pop() << endl;
    cout << endl;
	stack.print();

	cout << "Top: " << stack.getTop() << endl;
	cout << "Elements: " << stack.GetElements() << endl;
	cout << "\n> Queue" << endl;

	Queue<float> queue(5);
	queue.enqueue(6);
	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(0);

    queue.print();
    cout << "First: " << queue.getFirst() << endl;
	cout << "Elements: " << queue.GetElements() << endl;
    cout << endl;

	cout << "queue dequeue: " << queue.dequeue() << endl;
	cout << "queue dequeue: " << queue.dequeue() << endl;
    cout << endl;
	queue.print();

	cout << "First: " << queue.getFirst() << endl;
	cout << "Elements: " << queue.GetElements() << endl;
	return 0;
}