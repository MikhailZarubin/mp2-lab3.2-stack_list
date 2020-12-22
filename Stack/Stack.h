#include<iostream>
template<class T>
struct TLink {
	T val;
	TLink<T>* pNext;
};
template <class T>
class Stack
{
	TLink<T>* pFirst;
public:
	Stack();
	Stack(const Stack<T>& s);
	~Stack();
	Stack<T>& operator =(const Stack<T>& s);
	bool operator == (const Stack<T>& s);
	bool operator != (const Stack<T>& s);
	bool Empty();
	void Push(T a);
	T Pop();
	T Top();
	void clear_stack();
};
template<class T>
void Stack<T>::clear_stack()
{
	while (pFirst != NULL)
	{
		TLink<T>* tmp = pFirst->pNext;
		delete pFirst;
		pFirst = tmp;
	}
}
template <class T>
Stack<T>::Stack()
{
	pFirst = NULL;
}
template <class T>
Stack<T>::Stack(const Stack <T>& s)
{
	if (s.pFirst != NULL)
	{
		TLink<T>* prev = new TLink<T>;
		TLink<T>* tmp = s.pFirst;
	    prev->val = s.pFirst->val;
		pFirst = prev;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			TLink<T>* p = new TLink<T>;
			p->val = tmp->val;
			prev->pNext = p;
			prev = p;
			tmp = tmp->pNext;
		}
		prev->pNext = NULL;
	}
	else
		pFirst = NULL;
}
template<class T>
Stack<T>::~Stack()
{
	while (pFirst != NULL)
	{
		TLink<T>* tmp = pFirst->pNext;
		delete pFirst;
		pFirst = tmp;
	}
}
template<class T>
Stack<T>& Stack<T>:: operator = (const Stack<T>& s) 
{
	if (s.pFirst != NULL)
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
		TLink<T>* prev = new TLink<T>;
		TLink<T>* tmp = s.pFirst;
		pFirst = prev;
		prev->val = s.pFirst->val;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			TLink<T>* p = new TLink<T>;
			p->val = tmp->val;
			prev->pNext = p;
			prev = p;
			tmp = tmp->pNext;
		}
		prev->pNext = NULL;
	}
	else
		pFirst = NULL;
	return (*this);
}
template <class T>
bool Stack<T>:: operator == (const Stack<T>& s) 
{
	if (this != &s)
	{
		TLink<T>* tmp_1 = s.pFirst;
		TLink<T>* tmp_2 = pFirst;
		while (true)
		{
			if (tmp_1 == NULL && tmp_2 == NULL)
				break;
			if (tmp_1->val != tmp_2->val)
				return false;
			tmp_1 = tmp_1->pNext;
			tmp_2 = tmp_2->pNext;
		}
	}
	return true;
}
template <class T>
bool Stack<T>:: operator != (const Stack<T>& s) 
{
	return !(*this == s);
}
template <class T>
bool Stack<T>::Empty() 
{
	return pFirst == NULL;
}
template <class T>
void Stack<T>::Push(T a)
{
	TLink<T>* tmp = new TLink<T>;
	tmp->val = a;
	tmp->pNext = pFirst;
	pFirst = tmp;
}
template <class T>
T Stack<T>::Top()
{
	if (pFirst == NULL)
		throw NULL;
	return pFirst->val;
}
template <class T>
T Stack <T>::Pop()
{
	if (pFirst == NULL)
		throw NULL;
	T elem = pFirst->val;
	TLink<T>* tmp = pFirst;
	pFirst = tmp->pNext;
	delete tmp;
	return elem;
}
