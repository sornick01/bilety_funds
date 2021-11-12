#include <iostream>

template <class T>
class	Node
{
	template <class U> friend class SplayTree;
	T		_data;
	Node	*_left;
	Node	*_right;
	Node	*_parent;
	Node(const T &data) : _data(data), _left(nullptr), _right(nullptr), _parent(nullptr) {}
	~Node()
	{}
};

template <class T>
class SplayTree
{
	Node<T>	*_root;
	
};