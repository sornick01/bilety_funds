// Структура данных типа косое (splay) дерево. Алгоритмы вставки,
// удаления, поиска, обхода (префиксного, инфиксного, постфиксного) для
// косого дерева, слияния косых деревьев, разделения по ключу, их
// сложности.

#include <iostream>
#include <exception>

template <class T>
class Node
{
	template <class U> friend class MyStack;
	T data;
	Node *next;
	Node(const T &_data)
	{
		data = _data;
		next = nullptr;
	}
}; 

template <class T>
class MyStack
{
	size_t	size;
	Node<T>	*head;

public:
	MyStack();
	~MyStack();
	T pop();
	T peek();
	void push(const T &_data);

};

template <class T>
MyStack<T>::MyStack() : size(0), head(nullptr)
{}

template <class T>
MyStack<T>::~MyStack()
{
	Node<T> *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <class T>
void	MyStack<T>::push(const T &_data)
{

	if (!head)
	{
		head = new Node<T>(_data);
	}
	else
	{
		Node<T> *new_node = new Node<T>(_data);
		Node<T> *tmp = head;
		head = new_node;
		head->next = tmp;
	}
}

template <class T>
T	MyStack<T>::pop()
{
	T res;
	if (!head)
		throw std::logic_error("stack is empty");
	res = head->data;
	Node<T> *tmp = head;
	head = head->next;
	delete tmp;
	return (res);
}

template <class T>
T	MyStack<T>::peek()
{
	if (!head)
		throw std::logic_error("stack is empty");
	Node<T> *tmp = head;
	head = head->next;
	delete tmp;
}


int main ()
{
	MyStack<int> steck;
	steck.push(13);
	steck.push(123);
	steck.push(-76);
	steck.push(-34);
	try
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << steck.pop() << std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}