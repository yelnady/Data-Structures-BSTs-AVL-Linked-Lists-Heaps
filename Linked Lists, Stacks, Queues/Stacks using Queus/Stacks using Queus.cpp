#include "pch.h"
#include "all.h"
using namespace std;
class i_stack {
private:
	queue<int> queue;

public:
	int top() {
		return queue.back();
	}

	void pop() {
		int size1 = queue.size();
		for (int i = 0; i < size1 - 1; i++)
		{
			queue.push(queue.front());
			queue.pop();
		}
		queue.pop();
	}

	void push(int value) {
		queue.push(value);
	}
};
int main()
{
	i_stack stack2;
	stack2.push(5);
	stack2.push(3);
	stack2.push(8);
	cout << stack2.top() << endl;
	stack2.pop();
	cout << stack2.top() << endl;
	stack2.pop();
	cout << stack2.top() << endl;
	stack2.pop();
	cout << endl;
	return 0;
}
