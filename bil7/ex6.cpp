// На языке программирования C++ описать шаблонный класс (поля,
// методы (без реализации)) бинарного дерева поиска и реализовать алгоритм
// удаления элемента.

#include <iostream>

template <class T>
class Strategy
{	
public:
	virtual int compare(const T &a, const T &b) const = 0;
};

class Strategy_int final : public Strategy<int>
{
	virtual int compare(const int &a, const int &b) const override
	{
		return (b - a);
	}
};

template <class T>
class Node
{
	template <class U> friend class BTree;
	T		_data;
	Node	*_left;
	Node	*_right;
	Node(const T &data) : _data(data), _left(nullptr), _right(nullptr)
	{}
public:
	void	print_prefix_node()
	{
		std::cout << this->_data << ' ';
		if (this->_left)
			this->_left->print_prefix_node();
		if (this->_right)
			this->_right->print_prefix_node();
	}
	void	print_infix_node()
	{
		if (this->_left)
			this->_left->print_infix_node();
	std::cout << this->_data << ' ';
		if (this->_right)
			this->_right->print_infix_node();
	}
	void	print_postfix_node()
	{
		if (this->_left)
			this->_left->print_postfix_node();
		if (this->_right)
			this->_right->print_postfix_node();
		std::cout << this->_data << ' ';
	}

	
	~Node()
	{}
};

template <class T>
class BTree
{
	Node<T>	*_root;
	Strategy<T> *comparator;
public:
	BTree(Strategy<T> *comp) : _root(nullptr), comparator(comp)
	{

	}
	~BTree()
	{}

	void	insert(const T &data);

	void	print_prefix();
	void	print_infix();
	void	print_postfix();

	void	print_node(Node<T>	*node, int level = 0)
	{
		for (int i = 0; i < level; i++)
		{
			std::cout << "\t";
		}
		if (node)
		{
			std::cout << node->_data << std::endl;
			print_node(node->_left, level + 1);
			print_node(node->_right, level + 1);
		}
		else
		{
			std::cout << "(null)" << std::endl;
		}
	}

	void	print()
	{
		print_node(this->_root);
	}

	void	del_elem(const T &data);
};

template <class T>
void	BTree<T>::insert(const T &data)
{
	Node<T>		*tmp = _root;
	int comp;
	if (!_root)
	{
		_root = new Node<T>(data);
	}
	else
	{
		while (tmp)
		{
			comp = comparator->compare(tmp->_data, data);
			if (comp >= 0)
			{
				if (tmp->_right)
					tmp = tmp->_right;
				else
				{
					tmp->_right = new Node<T>(data);
					break ;
				}
			}
			else if (comp < 0)
			{
				if (tmp->_left)
					tmp = tmp->_left;
				else
				{
					tmp->_left = new Node<T>(data);
					break ;
				}
			}
		}
	}
}

template <class T>
void	BTree<T>::print_prefix()
{
	if (_root)
		_root->print_prefix_node();
}

// template <class T>
// void	BTree<T>::print_infix(Node<T> root)
// {

// 	if (root)
// 	{
// 		print_infix(root->_left);
// 		std::cout << root->_data;
// 		print_infix(root->_right);
// 	}
// }

// template <class T>
// void	BTree<T>::print_postfix(Node<T> root)
// {

// 	if (root)
// 	{
// 		print_postfix(root->_left);
// 		print_postfix(root->_right);
// 		std::cout << root->_data;
// 	}
// }

int main()
{
	Strategy_int *comp = new Strategy_int;
	BTree<int> tree(comp);
	tree.insert(1);
	tree.insert(-4);
	tree.insert(-2);
	tree.insert(3);
	// tree.print_prefix();
	tree.print();
}