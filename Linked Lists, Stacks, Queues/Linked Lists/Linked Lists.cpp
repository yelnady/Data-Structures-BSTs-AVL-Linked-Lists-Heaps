#include "pch.h"
#include <iostream>
using namespace std;


template <class T>
class list {
private:
	class Node {
	public:
		T info;
		Node*next;
		Node*prev;
	};
	Node *Start, *Last; int count;
public:
	class Iterator {
	private:
		Node *now;
		friend class list;
	public:
		Iterator() { now = NULL; }
		Iterator(Node*other) {
			now = other;
		}
		void operator++() {
			if (now->next == NULL) {
				throw "error";
			}
			now = now->next;
		}
		void operator--() {
			if (now->prev == NULL) {
				throw "error";
			}
			now = now->prev;
		}
		bool operator==(const Iterator&other) {
			return other.now = now;
		}
		T& operator*() { return now->info; }
	};
	list() {
		Start = Last = NULL; count = 0;
	}
	list(T value, int initial_size) {
		Node  *neww = new Node; ;
		Node  *current = NULL;
		count = initial_size;
		neww->prev = NULL;
		neww->next = NULL;
		for (int i = 0; i < initial_size; i++) {
			if (i == 0) {
				Last = Start = neww;
				neww->info = value;
			}
			else {
				neww = new Node;
				neww->info = value;
				neww->prev = NULL;
				neww->next = Start;
				Start->prev = neww;
				Start = neww;
			}


		}



		Last = current;
	}
	void insertINOrder(T elem) {
		Node *neww; neww = new Node;	neww->info = elem; neww->next = NULL; neww->prev = NULL;

		if (Start == NULL) {
			Start = Last = neww;
		}
		else {
			Node *current = Start;
			Node *back;
			while (current != NULL) {
				if (current->info >= elem) {
					break;
				}
				else {
					current = current->next;
				}
			}
			if (current == NULL) {
				Last->next = neww;
				neww->prev = Last;
				Last = neww;
			}
			else if (current == Start) {
				neww->next = Start;
				Start->prev = neww;
				Start = neww;
			}
			else {
				back = current->prev;
				back->next = neww;
				neww->prev = back;
				neww->next = current;
				current->prev = neww;
			}
		}
		count++;
	}
	void insert(T elem, Iterator &position) {
		Node* neww = new Node;
		neww->info = elem;
		neww->prev = NULL;
		neww->next = NULL;
		count++;
		if (position.now == Start) {
			neww->prev = NULL;
			neww->next = Start;
			Start->prev = neww;
			Start = neww;
			position.now = Start;
		}
		else {
			Node*current = position.now->prev;
			neww->prev = position.now->prev;
			neww->next = position.now;
			position.now->prev->next = neww;
			position.now->prev = neww;


		}

	}
	void print() {
		Node  *current = Start;
		while (current != NULL) {
			cout << current->info << endl;
			current = current->next;
		}
	}
	list(const list<T> & other) {
		if (other.Start == NULL) {
			Start = Last = NULL;
		}
		else {
			Node *current = other.Start; Node*newNode = new Node;
			Last = Start = newNode;
			newNode->info = current->info;
			newNode->next = NULL;
			current = current->next;
			while (current != NULL) {
				newNode = new Node;
				newNode->info = current->info;
				newNode->next = NULL;
				current = current->next;
				Last->next = newNode;
				Last = newNode;
			}
		}
	}
	~list() {
		Node*n = Start;
		while (Start != NULL) { n = Start; Start = Start->next; delete n; }
		Last = NULL; count = 0;

	}
	int size() const { return count; }
	Iterator begin() { return Iterator(Start); }
	Iterator end() { return Iterator(NULL); }
	Iterator erase(Iterator position) {
		Node *del;

		if (position.now == NULL) {
			throw "oops";
		}

		else {
			count--;
			if (position.now == Start) {
				del = Start;
				Start = Start->next;
				delete del;
				return Start;
			}
			else {
				del = position.now;
				position.now->prev = position.now->next;
				delete del;
				return position.now;
			}
		}
	}
	list<T> operator=(const list<T> &other) {
		if (Start != NULL) {
			Node* temp;
			while (Start != NULL) {
				temp = Start; Start = Start->next; delete temp;
			}
			Last = NULL;
			count = 0;
		}
		if (other.Start == NULL) {
			Last = Start = NULL; count = 0;
		}
		else {
			Node *current = other.Start;
			Node* newNode = new Node;
			count = other.count;
			newNode->info = current->info;
			newNode->next = NULL;
			newNode->prev = NULL;
			Last = Start = newNode;
			current = current->next;
			while (current != NULL) {
				newNode = new  Node;
				newNode->info = current->info;
				newNode->next = NULL;
				newNode->prev = Last;
				Last->next = newNode;
				Last = newNode;
				current = current->next;
			}
		}
		return *this;
	}
};
int main()
{

	try {
		list<int> s(6, 4);;
		list<int>::Iterator it = s.begin();
		cout << *it << endl;
		cout << endl;
		it = s.begin();
		s.insert(33, it);
		cout << *it << " ";
		++it;
		cout << *it << endl;
		it = s.begin();
		s.print();
		cout << endl;
		it = s.erase(it);
		list<int> s2;
		s2 = s;
		cout << "the copied list" << endl;
		s2.print();
	}
	catch (...) {
		cerr << "An Exception has been thrown" << endl;
	}


	system("pause");
	return 0;
}
