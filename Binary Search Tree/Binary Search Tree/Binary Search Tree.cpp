#include "pch.h"
#include "all.h"
using namespace std;
class wordlines
{
public:
	string word = "";
	vector<int> lines;
	bool operator <(wordlines x)
	{
		if (word < x.word)
			return true;
		return false;
	}
};
template <class T>
class BSTNode
{
public:
	BSTNode<T> *leftChild = 0;
	BSTNode<T> *rightChild = 0;
	T value;
	BSTNode()
	{
		leftChild = 0;
		rightChild = 0;
		value;
	}
	BSTNode(T &val)
	{
		leftChild = 0;
		rightChild = 0;
		value = val;
	}
	BSTNode(BSTNode<T>*left, BSTNode<T>*right, T val)
	{
		value = val;
		leftChild = left;
		rightChild = right;
	}
};
template <class T>
class BSTFCI
{
public:
	BSTNode <T> *root;
	BSTFCI()
	{
		root;
	}
	int checkHeight(BSTNode<T>*root)
	{
		if (root == 0)
			return 0;
		int left = checkHeight(root->leftChild);
		if (left == -1)
			return -1;
		int right = checkHeight(root->rightChild);
		if (right == -1)
			return -1;
		int heightDifference = left - right;
		if (heightDifference > 1 || heightDifference < -1)
			return -1;
		else if (left > right)
			return left + 1;
		else
			return right + 1;
	}
	bool isBalance()
	{
		if (checkHeight(root) == -1)
			return false;
		else
			return true;
	}
	void insert(T val)
	{
		BSTNode<T>*p = root;
		BSTNode<T>	*prev;
		prev = 0;
		while (p != 0)
		{
			prev = p;
			if (p->value < val)
				p = p->rightChild;
			else
				p = p->leftChild;
		}
		if (root == 0)
			root = new BSTNode<T>(val);
		else if (prev->value < val)
			prev->rightChild = new BSTNode<T>(val);
		else
			prev->leftChild = new BSTNode<T>(val);
	}
	void PrintRange(BSTNode<T>* root, int min, int max)
	{
		if (root == 0)
		{
			return;
		}

		if (min < root->value)
		{
			PrintRange(root->leftChild, min, max);
		}

		if (root->value >= min && root->value <= max)
		{
			cout << root->value << endl;
		}

		if (max > root->value)
		{
			PrintRange(root->rightChild, min, max);
		}
	}
	void PrintRange(int min, int max)
	{
		PrintRange(root, min, max);
	}
};
class TreeApp
{
public:
	BSTFCI <wordlines> *T1 = new BSTFCI <wordlines>;
	wordlines node;
	TreeApp()
	{
	}
	/**/
	bool search(BSTNode<wordlines> *root, string &val, int &line)
	{
		if (root == NULL)
			return false;
		else
		{
			if (root->value.word == val)
			{
				root->value.lines.push_back(line);
				return true;
			}
			else if (root->value.word > val)
				search(root->leftChild, val, line);
			else
				search(root->rightChild, val, line);
		}
	}
	void convert(string text)
	{
		int line = 1;
		string word = "";
		BSTNode <wordlines> *x = new BSTNode <wordlines>;
		wordlines y;
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '\'' && text[i] != '"' && text[i] != ';' && text[i] != ':' && text[i] != '-' && text[i] != ' '&&text[i] != '\n')
				word += text[i];
			else
			{
				if (search(T1->root, word, line) == true)
				{
					int x = 5;
				}
				else
				{
					y.word = word;
					y.lines.push_back(line);
					T1->insert(y);
				}
				if (text[i] == '\n')
				{
					line++;
					text.erase(i, 0);
				}
				word = "";
				y.lines.clear();
			}
		}
	}
	void readfile(fstream &file, string &text)
	{
		char *arr;
		int x;
		file.seekg(0, ios::end);
		x = file.tellg();
		arr = new char[x];
		file.seekg(0);
		file.read(arr, x);
		for (int i = 0; i < x; i++)
		{
			text += arr[i];
		}
	}
	void print(BSTNode <wordlines> *x)
	{
		if (x != 0)
		{
			print(x->leftChild);
			cout << x->value.word << "		";
			for (int i = 0; i < x->value.lines.size(); i++)
				cout << x->value.lines[i] << ",";
			cout << endl;
			print(x->rightChild);
		}
	}
	void print()
	{
		print(T1->root);
	}
};
template <class T>
bool Identical(BSTNode <T> * root1, BSTNode <T>*root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;

	return (root1->value == root2->value && Identical(root1->leftChild, root2->leftChild) && Identical(root1->rightChild, root2->rightChild));
}
template <class T>
bool isSubTree(BSTNode <T> * t1, BSTNode <T>* t2)
{
	if (t2 == NULL)
		return true;

	if (t1 == NULL)
		return false;

	if (Identical(t1, t2))
		return true;
	return (isSubTree(t1->leftChild, t2) || isSubTree(t1->rightChild, t2));
}
template <class T>
bool isSubTree(BSTFCI <T> * t1, BSTFCI <T>* t2)
{
	return(isSubTree(t1->root, t2->root));
}
int main()
{
	BSTFCI <int> *t1 = new BSTFCI <int>;
	int x, y;
	for (int i = 0; i < 7; i++)
	{
		cout << "Enter a num\n";
		cin >> x;
		t1->insert(x);
	}
	cout << "Enter a max Num and Min num\n";
	cin >> x >> y;
	t1->PrintRange(x, y);
	if (t1->isBalance())
		cout << "BST is Balance\n";
	else
		cout << "BST is not Balance\n";
	BSTFCI <int> *t2 = new BSTFCI <int>;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter a num\n";
		cin >> x;
		t2->insert(x);
	}
	cout << "Enter a max Num and Min num\n";
	cin >> x >> y;
	t2->PrintRange(x, y);
	if (t2->isBalance())
		cout << "BST is Balance\n";
	else
		cout << "BST is not Balance\n";
	if (isSubTree(t1, t2))
		cout << "BST is SubTree \n";
	else
		cout << "BST is not SubTree\n";
	fstream file("data.txt", ios::in);
	TreeApp obj;
	string text = "";
	obj.readfile(file, text);
	obj.convert(text);
	obj.print();

}

