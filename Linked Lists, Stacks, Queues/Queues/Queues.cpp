#include "pch.h"
#include "all.h"
using namespace std;

template<class T>
class Queue_template
{
private:
	int the_size;
	int end_;
	T *Queue_;
public:
	int current_size;
	int q_size();
	Queue_template();
	Queue_template(T, int);
	~Queue_template();
	void pop();
	void push(T);
	void make_empty();
	T front();
	bool isEmpty();
	bool isFull();
};

template<class T>
Queue_template<T>::Queue_template()
{
	the_size = 15;
	end_ = 0;
	current_size = 0;
	Queue_ = new T[the_size];
}

template<class T>
bool Queue_template<T>::isEmpty()
{
	return(current_size == 0);
}

template<class T>
bool Queue_template<T>::isFull()
{
	return(end_ == the_size - 1);
}

template<class T>
Queue_template<T>::Queue_template(T val, int times)
{
	make_empty();
	the_size = times;
	end_ = times - 1;
	Queue_ = new T[the_size];
	int t = 0;
	while (t < times)
		Queue_[t++] = val;
	current_size = the_size;
}

template<class T>
void Queue_template<T>::push(T val)
{
	if (isFull())
	{
		cout << "Queue is Full.\n";
		return;
	}
	current_size++;
	Queue_[end_++] = val;
}

template<class T>
T Queue_template<T>::front()
{
	if (isEmpty())
	{
		cout << "Queue is Empty.\n";
		return -777;
	}
	return Queue_[0];
}

template<class T>
void Queue_template<T>::pop()
{
	if (isEmpty())
	{
		cout << "Queue is Empty.\n";
	}
	for (int i = 0; i < current_size - 1; i++)
	{
		Queue_[i] = Queue_[i + 1];
	}
	current_size--;
	end_--;
}

template<class T>
void Queue_template<T>::make_empty()
{
	delete[]Queue_;
	end_ = 0;
	current_size = 0;
	the_size = 0;
}

template<class T>
int Queue_template<T>::q_size()
{
	return current_size;
}

template<class T>
Queue_template<T>::~Queue_template()
{
	delete[]Queue_;
	current_size = 0;
	the_size = 0;
	end_ = 0;
}


int main()
{
	Queue_template<int> q;
	q.push(11);
	q.push(7);
	q.push(2);
	q.push(1998);
	q.pop();
	cout << "Front: " << q.front() << endl;
	cout << "Size: " << q.q_size() << endl;


	cout << "************************\n\n\n";
	Queue_template<int> q1(4, 5);
	cout << "Front: " << q1.front() << endl;
	cout << "Size: " << q1.q_size() << endl;
	q1.pop(); q1.pop(); q1.pop(); q1.pop();

	cout << "Front: " << q1.front() << endl;
	cout << "Size: " << q1.q_size() << endl;

	return 0;
}
