//#include "my_class.hpp"
#include "my_class.cpp"
using namespace std;


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

	Queue<string> queue("q");
	queue.enqueue("w");
	queue.enqueue("e");
	queue.enqueue("r");
	queue.enqueue("t");
	queue.enqueue("y");

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