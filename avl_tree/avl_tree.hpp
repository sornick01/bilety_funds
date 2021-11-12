/*
удление
поиск
вставка

*/
#pragma once

#include <iostream>

template <class T>
class Node
{
	template <class U> friend class AVLTree;
	T		_data;
	Node<T>	*_left;
	Node<T>	*_right;
	size_t	height;

	Node() : _left(nullptr), _right(nullptr), height(1)
	{}
	Node(const T &data) : _left(nullptr), _right(nullptr), height(1), _data(data)
	{}
	~Node()
	{
	}
};

template <class T>
class AVLTree
{
private:
	Node<T>	*_root;

	size_t		get_height(Node<T> *node);
	int			balance_factor(Node<T> *node);
	void		set_height(Node <T> *node);
	Node<T>		*left_rotation(Node<T> *node);
	Node<T>		*big_left_rotation(Node<T> *node);
	Node<T>		*right_rotation(Node<T> *node);
	Node<T>		*big_right_rotation(Node<T> *node);
	Node<T>		*balance(Node<T> *node);
	bool		search(Node<T> *node, const T &data);
	Node<T>		*insert(Node<T> *node, const T &data);
	Node<T>		*remove_min(Node<T> *node);
	Node<T>		*find_min(Node<T> *node);
	Node<T>		*remove(Node<T> *node, const T &data);
	void		print(Node<T> *x, int i);
	void		delete_all_nodes(Node<T> *x);
public:
	AVLTree() : _root(nullptr)
	{}
	~AVLTree() 
	{
		delete_all_nodes(this->_root);
	}
	void		del(const T &data);
	bool		find(const T &data);
	void		add(const T &data);
	void		print();

};