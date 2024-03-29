#include "pch.h"
#include "all.h"

#include <iostream>
using namespace std;

template<class T>
class Stack_template
{
private:
	int the_size;
	int start;
	T *stack_;
	int current_size;
public:
	int s_size();
	Stack_template();
	Stack_template(T, int);
	bool isEmpty();
	bool isFull();
	void push(T);
	int top();
	void pop();
	void make_empty();
	~Stack_template();
};

template<class T>
Stack_template<T>::~Stack_template()
{
	make_empty();
}

template<class T>
Stack_template<T>::Stack_template()
{
	the_size = 15;
	stack_ = new T[the_size];
	start = 0;
	current_size = 0;
}

template<class T>
Stack_template<T>::Stack_template(T val, int times)
{
	make_empty();
	start = 0;
	stack_ = new T[times];
	while (start < times)
		stack_[start++] = val;
	the_size = times;
	current_size = the_size;

}

template<class T>
void Stack_template<T>::push(T n)
{
	if (!isFull())
	{
		stack_[start] = n;
		start++;
		current_size++;
	}
	else
		cout << "Stack is full" << endl;
}

template<class T>
bool Stack_template<T>::isEmpty()
{
	return(current_size == 0);
}

template<class T>
bool Stack_template<T>::isFull()
{
	return(current_size == the_size);
}

template<class T>
int Stack_template<T>::top()
{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
		return -1;
	}
	else
		return stack_[start - 1];
}

template<class T>
void Stack_template<T>::pop()
{
	if (!isEmpty())
	{
		start--;
		current_size--;
	}
	else
		cout << "Empty Stack" << endl;
}

template<class T>
void Stack_template<T>::make_empty()
{
	delete[]stack_;
	start = 0;
	current_size = 0;
	the_size = 0;
}

template<class T>
int Stack_template<T>::s_size()
{
	return current_size;
}

int main()
{
	srand(time(0));
	cout << "***********************************************\n\n\n";
	cout << "**********STACK(value,times)************\n\n";
	Stack_template<int> obj(4, 5);
	int t = 5;
	while (t--)
	{
		cout << "Size: " << obj.s_size() << endl;
		cout << "Top: " << obj.top() << endl;
		obj.pop();
	}
	cout << "Size: " << obj.s_size() << endl;

	cout << "***********************************************\n\n\n";
	cout << "************STACK***************\n\n";


	Stack_template<int> st;
	int x = 10;
	cout << "Size: " << st.s_size() << endl;
	cout << "Top: " << st.top() << endl;

	while (x--)
		st.push(rand() % 100);
	st.pop();
	cout << "Size: " << st.s_size() << endl;
	cout << "Top: " << st.top() << endl;
	st.pop();
	cout << "Top: " << st.top() << endl;
	st.pop();
	st.pop();
	cout << "Size: " << st.s_size() << endl;
	system("pause");
	return 0;
}
