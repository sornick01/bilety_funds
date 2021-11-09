//  На языке программирования C++ описать шаблонный класс (поля,
// методы (без реализации)) двусвязного списка и реализовать алгоритм
// удаления элемента по значению (сравнение элементов задаётся
// реализацией паттерна "стратегия")

#include <iostream>

// template <class T>
// class Strategy
// {	
// public:
// 	virtual int compare(const T &a, const T &b) const = 0;
// };

// class Strategy_int final : public Strategy<int>
// {
// 	virtual int compare(const int &a, const int &b) const override
// 	{
// 		return (a - b);
// 	}
// };

template <class T>
class	Node
{
	template <class U>  friend class DLList;
	T 		_data;
	Node	*_next;
	Node	*_prev;
	Node(const T &data) : _data(data), _next(nullptr), _prev(nullptr)
	{}
public:
	~Node()
	{
	
	}
};

template <class T>
class	DLList
{
	Node<T>	*head;
	Node<T>	*tail;
	Strategy<T> *strat;
public:
	~DLList()
	{
		// Node<T> *tmp;
		// while (head)
		// {
		// 	tmp = head;
		// 	head = head->_next;
		// 	delete tmp;
		// }
		while (head)
		{
			tail = head->_next;
			delete head;
			head = tail;
		}
		
	}
	DLList(Strategy<T> *strategy)
		: head(nullptr), tail(nullptr), strat(strategy)
	{ }
	void	pushBack(const T &data);
	void	pushFront(const T &data);
	void	delElem(const T &data);
	void	print_reverse();
};

template <class T>
void	DLList<T>::pushBack(const T &data)
{
	Node<T>	*tmp = new Node<T>(data);
	if (!head)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->_next = tmp;
		tmp->_prev = tail;
		tail = tmp;
	}
}

template <class T>
void	DLList<T>::pushFront(const T &data)
{
	Node<T>	*tmp = new Node<T>(data);
	if (!head)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tmp->_next = head;
		head->_prev = tmp;
		head = tmp;
	}
}

template <class T>
void	DLList<T>::delElem(const T &data)
{
	Node<T>	*tmp = head;
	while (tmp)
	{
		if (strat->compare(tmp->_data, data) == 0)
		{
			if (tmp == head)
			{
				head = head->_next;
				head->_prev = nullptr;
			}
			else if (tmp == tail)
			{
				tail = tail->_prev;
				tail->_next = nullptr;
			}
			else
			{
				tmp->_prev->_next = tmp->_next;
				tmp->_next->_prev = tmp->_prev;
			}
			delete tmp;
			return ;
		}
		tmp = tmp->_next;
	}
}

template <class T>
void	DLList<T>::print_reverse()
{
	Node<T> *tmp = tail;
	while (tmp)
	{
		std::cout << tmp->_data << " ";
		tmp = tmp->_prev;
	}
	std::cout << std::endl;
}

int main()
{
	Strategy_int strat;
	DLList<int>	list(&strat);
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);
	list.pushBack(4);
	list.pushBack(5);
	list.print_reverse();
	list.delElem(5);
	list.delElem(2);
	list.print_reverse();

	list.pushBack(12);
	list.pushBack(4);
	list.pushFront(41);
	list.delElem(1);
	list.print_reverse();

}