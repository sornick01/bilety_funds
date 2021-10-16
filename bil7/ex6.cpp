// На языке программирования C++ описать шаблонный класс (поля,
// методы (без реализации)) бинарного дерева поиска и реализовать алгоритм
// удаления элемента.

#include <iostream>

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
	~Node()
	{}
};

template <class T>
class BTree
{
	Node<T>	*_root;
public:
	BTree();
	~BTree()
	{}

	void	insert(const T &data);

	void	print_prefix(Node<T> root);
	void	print_infix(Node<T> root);
	void	print_postfix(Node<T> root);

	void	del_elem(const T &data);
};

template <class T>
void	BTree<T>::insert(const T &data)
{
	Node<T>		*tmp = _root;
	int 		comp;

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

template <class T>
void	BTree<T>::print_prefix(Node<T> root)
{

	if (root)
	{
		std::cout << root->_data;
		print_prefix(root->_left);
		print_prefix(root->_right);
	}
}

template <class T>
void	BTree<T>::print_infix(Node<T> root)
{

	if (root)
	{
		print_infix(root->_left);
		std::cout << root->_data;
		print_infix(root->_right);
	}
}

template <class T>
void	BTree<T>::print_postfix(Node<T> root)
{

	if (root)
	{
		print_postfix(root->_left);
		print_postfix(root->_right);
		std::cout << root->_data;
	}
}

