#pragma once
#include<iostream>
#include <algorithm>

template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};

template <class T>
class TLQueue
{
private:
	TNode<T>* pFirst, * pLast;

public:
	TLQueue() { pFirst = nullptr; pLast = nullptr; };         
	~TLQueue() { ClearQueue(); };
	TLQueue(const TLQueue<T>& q);                  

	TLQueue<T>& operator=(const TLQueue<T>& q);   
	bool operator==(const TLQueue<T>& q);          
	bool operator != (const TLQueue<T>& q);         

	bool empty();                                             
	void Push(const T& el);                              
	T Pop();                                                 
	T Front();                                                
	T Back();                                                
	int size_queue();                                     
	void ClearQueue();                                        
	void output();                                            
};

template<class T>
inline TLQueue<T>::TLQueue(const TLQueue<T>& obj)
{
	TNode<T>* tmp = obj.pFirst, * node;
	pFirst = pLast = nullptr;
	while (tmp != nullptr)
	{
		node = new TNode<T>;
		node->value = tmp->value;
		if (pFirst == nullptr)
		{
			pFirst = node;
			pLast = node;
		}
		else
		{
			pLast->pNext = node;
			pLast = node;
		}
		tmp = tmp->pNext;
	}
}

template<class T>
inline TLQueue<T>& TLQueue<T>::operator=(const TLQueue<T>& obj)
{
	if (obj.pFirst == nullptr)
	{
		ClearQueue();
	}
	else
	{
		
		TNode<T>* tmp = obj.pFirst, * node;
		while (tmp != nullptr)
		{
			node = new TNode<T>;
			node->value = tmp->value;
			if (pFirst == nullptr)
			{
				pFirst = node;
				pLast = node;
			}
			else
			{
				pLast->pNext = node;
				pLast = node;
			}
			tmp = tmp->pNext;
		}
	}
	return *this;
}

template<class T>
inline bool TLQueue<T>::operator==(const TLQueue<T>& obj)
{
	TLQueue<T> current_queue(*this);
	TLQueue<T> another_queue(obj);

	if (size_queue() != another_queue.size_queue())
	{
		return false;
	}
	if (pFirst == nullptr && obj.pFirst == nullptr)
	{
		return true;
	}
	while (!current_queue.empty())
	{
		if (current_queue.Pop() != another_queue.Pop())
		{
			return false;
		}
	}
	return true;
}

template<class T>
inline bool TLQueue<T>::operator!=(const TLQueue<T>& obj)
{
	return !(*this == obj);
}

template<class T>
inline bool TLQueue<T>::empty()
{
	if (pFirst == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline T TLQueue<T>::Pop()
{
	if (empty())
	{
		throw "Queue is empty";
	}

	TNode<T>* tmp = pFirst;
	T result = pFirst->value;
	pFirst = pFirst->pNext;
	delete tmp;
	return result;
}

template<class T>
inline void TLQueue<T>::Push(const T& el)
{
	TNode<T>* tmp = new TNode<T>;
	tmp->value = el;
	tmp->pNext = nullptr;
	if (empty())
	{
		pFirst = tmp;
		pLast = tmp;
	}
	else
	{
		pLast->pNext = tmp;
		pLast = tmp;
	}
}

template<class T>
inline T TLQueue<T>::Front()
{
	if (empty())
	{
		throw "Queue is empty";
	}
	return pFirst->value;
}

template<class T>
inline T TLQueue<T>::Back()
{
	if (empty())
	{
		throw "Queue is empty";
	}
	return pLast->value;
}

template<class T>
inline int TLQueue<T>::size_queue()
{
	TNode<T>* tmp = pFirst;
	int i = 0;
	while (tmp != nullptr)
	{
		i++;
		tmp = tmp->pNext;
	}
	return i;
}

template<class T>
inline void TLQueue<T>::ClearQueue()
{
	while (!empty())
	{
		Pop();
	}
	pFirst = nullptr;
	pLast = nullptr;
}

template<class T>
inline void TLQueue<T>::output()
{
	if (empty())
	{
		std::cout << "( )";
	}
	else
	{
		TLQueue<T> current(*this);
		std::cout << "( ";
		while (!current.empty())
		{
			std::cout << current.Pop() << " ";
		}
		std::cout << ")" << std::endl;
	}
}