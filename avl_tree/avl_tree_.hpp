#include "avl_tree.hpp"

template<class T>
size_t	AVLTree<T>::get_height(Node<T> *node)
{
	if (node)
		return node->height;
	return 0;
}

template <class T>
int	AVLTree<T>::balance_factor(Node<T> *node)
{
	return (get_height(node->_right) - get_height(node->_left));
}

template <class T>
void		AVLTree<T>::set_height(Node <T> *node)
{
	node->height = std::max(get_height(node->_left), get_height(node->_right)) + 1;
}

template <class T>
Node<T>	*AVLTree<T>::left_rotation(Node<T> *node)
{
	Node<T>	*cpy;

	cpy = node->_right;
	node->_right = cpy->_left;
	cpy->_left = node;

	set_height(node);
	set_height(cpy);
	return (cpy);
}

template <class T>
Node<T>	*AVLTree<T>::right_rotation(Node<T> *node)
{
	Node<T>	*cpy;

	cpy = node->_left;
	node->_left = cpy->_right;
	cpy->_right = node;

	set_height(node);
	set_height(cpy);
	return (cpy);
}

template <class T>
Node<T>	*AVLTree<T>::big_left_rotation(Node<T> *node)
{
	node->_right = right_rotation(node->_right);
	return (left_rotation(node));
}

template <class T>
Node<T>	*AVLTree<T>::big_right_rotation(Node<T> *node)
{
	node->_left = left_rotation(node->_left);
	return (right_rotation(node));
}

template <class T>
Node<T>	*AVLTree<T>::balance(Node<T> *node)
{
	set_height(node);
	if (balance_factor(node) == 2)
	{
		if (balance_factor(node->_right) < 0)
			return (big_left_rotation(node));
		else
			return left_rotation(node);
	}
	else if (balance_factor(node) == -2)
	{
		if (balance_factor(node->_left) > 0)
			return big_right_rotation(node);
		else
			return right_rotation(node);
	}
	return (node);
}

template <class T>
Node<T>	*AVLTree<T>::insert(Node<T> *node, const T &data)
{
	if (!node)
		return (new Node<T>(data));
	if (data < node->_data)
	{
		// std::cout << "<" << std::endl;
		node->_left = insert(node->_left, data);
	}
	else
	{
		// std::cout << ">" << std::endl;
		node->_right = insert(node->_right, data);
	}
	return (balance(node));
}

template <class T>
void	AVLTree<T>::add(const T &data)
{
	this->_root = insert(this->_root, data);
}

template <class T>
bool	AVLTree<T>::search(Node<T> *node, const T &data)
{
	if (!node)
		return false;
	if (data < node->_data)
		return search(node->_left, data);
	if (data > node->_data)
		return search(node->_right, data);
	if (data == node->_data)
		return true;
	return false;
}

template <class T>
bool		AVLTree<T>::find(const T &data)
{
	return search(this->_root, data);
}


template <class T>
void		AVLTree<T>::delete_all_nodes(Node<T> *x)
{
	if (x)
	{
		delete_all_nodes(x->_left);
		delete_all_nodes(x->_right);
		delete x;
	}
}

template <class T>
Node<T>		*AVLTree<T>::find_min(Node<T> *x)
{
	// return node->_left ? find_min(node->_left) : node;
	while (x->_left)
		x = x->_left;
	return (x);
}

template <class T>
Node<T>		*AVLTree<T>::remove_min(Node<T> *node)
{
	if (!node->_left)
		return node->_right;
	node->_left = remove_min(node->_left);
	return balance(node);
}

template <class T>
Node<T>		*AVLTree<T>::remove(Node<T> *node, const T &data)
{
	if (!node)
		return (nullptr);
	if (data < node->_data)
		node->_left = remove(node->_left, data);
	else if (data > node->_data)
		node->_right = remove(node->_right, data);
	else
	{
		Node<T>	*l = node->_left;
		Node<T>	*r = node->_right;
		delete node;
		if (!r)
			return (l);
		Node<T>	*min = find_min(r);
		min->_right = remove_min(r);
		min->_left = l;
		return balance(min);
	}
	return balance(node);
}

template <class T>
void		AVLTree<T>::del(const T &data)
{	
	this->_root = remove(this->_root, data);
}

template <class T>
void		AVLTree<T>::print(Node<T> *x, int i)
{
	
	for (int j = 0; j < i; j++)
	{
		std::cout << "\t";
	}
	if (!x)
	{
		printf("\x1b[37;42m (null) \x1b[0m\n");
		return ;
	}
	printf("\x1b[37;42m %d \x1b[0m \x1b[33;44m(%lu)\x1b[0m\n", x->_data, x->height);
	print(x->_left, i + 1);
	print(x->_right, i + 1);
}

template <class T>
void		AVLTree<T>::print()
{
	
	print(this->_root, 1);
	std::cout << "MAX HIGH - " << this->_root->height << std::endl;
}

