#include "pch.h"
#include "all.h"
using namespace std;
class Node
{
private:
	int key;
	Node *left;
	Node *right;
	int height;
public:
	Node(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
		height = 1;
	}
	Node* getLeft()
	{
		return left;
	}
	Node* getRight()
	{
		return right;
	}
	int getKey()
	{
		return key;
	}
	int getHeight()
	{
		return height;
	}
	void setLeft(Node *l)
	{
		left = l;
	}
	void setRight(Node *r)
	{
		right = r;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void setKey(int k)
	{
		key = k;
	}
};

class AVL
{
private:
	Node *root;

	Node* deleteNode(Node*, int);
	Node* insert(Node* node, int key);

	void preOrder(Node * n);
	void postOrder(Node *n);
	void inOrder(Node *n);

	Node *rightRotate(Node *y);
	Node *leftRotate(Node *x);

	int height(Node *N);
	int getBalance(Node *N);
	Node* maxNode(Node* node);

public:
	AVL();
	void deleteNode(int);
	void insert(int key);
	void print(int t);

};

AVL::AVL()
{
	root = NULL;
}

///printing
void AVL::print(int type)
{
	if (type == 0)
		preOrder(root);
	else if (type == 1)
		postOrder(root);
	else
		inOrder(root);
}
void AVL::preOrder(Node * n)
{
	if (n == NULL)
		return;
	cout << n->getKey() << endl;
	preOrder(n->getLeft());
	preOrder(n->getRight());
}
void AVL::postOrder(Node *n)
{
	if (n == NULL)
		return;
	postOrder(n->getLeft());
	postOrder(n->getRight());
	cout << n->getKey() << endl;
}
void AVL::inOrder(Node *n)
{
	if (n == NULL)
		return;

	inOrder(n->getLeft());
	cout << n->getKey() << endl;
	inOrder(n->getRight());

}
///calculate
Node* AVL::maxNode(Node* node)
{
	if (node->getRight() == 0)
	{
		return node;
	}
	return maxNode(node->getRight());
}

int AVL::height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->getHeight();
}
int AVL::getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->getLeft()) - height(N->getRight());
}
///rotating
Node* AVL::rightRotate(Node *y)
{
	Node *x = y->getLeft();
	Node *T2 = x->getRight();

	x->setRight(y);
	y->setLeft(T2);

	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
	x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);

	return x;
}
Node* AVL::leftRotate(Node *x)
{
	Node *y = x->getRight();
	Node *T2 = y->getLeft();

	y->setLeft(x);
	x->setRight(T2);

	x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);

	return y;
}
///deletion
void AVL::deleteNode(int key)
{
	deleteNode(root, key);
}

Node* AVL::deleteNode(Node * root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (key < root->getKey())
	{
		root->setLeft(deleteNode(root->getLeft(), key));
	}
	else if (key > root->getKey())
	{
		root->setRight(deleteNode(root->getRight(), key));
	}
	else
	{
		if (!root->getLeft())
		{
			Node* tmp = root->getRight();
			delete root;
			return tmp;
		}
		else if (!root->getRight())
		{
			Node* tmp = root->getLeft();
			delete root;
			return tmp;
		}
		else
		{
			Node* temp = maxNode(root->getLeft());
			root->setKey(temp->getKey());
			root->setLeft(deleteNode(temp, temp->getKey()));
		}
	}

	if (root == 0)
		return root;

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->getLeft()) >= 0)
	{
		return rightRotate(root);
	}
	else if (balance > 1 && getBalance(root->getLeft()) < 0)
	{
		root->setLeft(leftRotate(root->getLeft()));
		return rightRotate(root);
	}
	else if (balance < -1 && getBalance(root->getRight()) <= 0)
	{
		return leftRotate(root);
	}
	else if (balance < -1 && getBalance(root->getRight()) > 0)
	{
		root->setRight(rightRotate(root->getRight()));
		return leftRotate(root);
	}

	return root;
}
///adding
void AVL::insert(int key)
{
	root = insert(root, key);
}
Node* AVL::insert(Node* node, int key)
{
	if (node == NULL)
		return new Node(key);

	if (key < node->getKey())
		node->setLeft(insert(node->getLeft(), key));
	else
		node->setRight(insert(node->getRight(), key));


	node->setHeight(max(height(node->getLeft()), height(node->getRight())) + 1);


	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->getLeft()->getKey())
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->getRight()->getKey())
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->getLeft()->getKey())
	{
		node->setLeft(leftRotate(node->getLeft()));
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->getRight()->getKey())
	{
		node->setRight(rightRotate(node->getRight()));
		return leftRotate(node);
	}

	return node;
}

int main()
{
	AVL t;
	t.insert(4);
	t.insert(2);
	t.insert(3);
	t.insert(0);
	int val;
	cout << "Enter '0' for Pre_Order, '1' for Post_Order, Otherwise In_Order: ";
	cin >> val;
	t.print(val);
	cout << endl;
	t.deleteNode(-3);
	t.print(val - 1);
	return 0;
}
