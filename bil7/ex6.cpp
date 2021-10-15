#include <iostream>

template <class T>
class Node
{
	template <class U> friend class BTree;
	T		data;
	Node	*_left;
	Node	*_right;
public:
	~Node()
	{}
};

template <class T>
class BTree
{
	Node<T>	*_root;

public:
	~BTree()
	{}

	void	insert(const T &data);

	void	print_prefix();
	void	print_infix();
	void	print_postfix();

	void	del_elem(const T &data);
};
