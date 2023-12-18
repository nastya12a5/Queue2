#pragma once
#include<iostream>

template <class T>
class TQueue
{
private:
	T* pMem;
	int size;
	int finish, start;
	int count;

public:
	TQueue();
	TQueue(int _size);                       
	~TQueue();                              
	TQueue(const TQueue& object);            
	bool empty();                            
	bool full();                             

	void Push(const T& element);             
	T Pop();                                 
	T front();                               
	T back();                                

	void operator = (const TQueue& object);  
	bool operator ==(const TQueue& object);  
	bool operator !=(const TQueue& object);  
	int GetHeadIndex();                      
	int GetCurrentSize();                    
	int GetMaxSize();                        
	int NumberOfElements();                  

	void output();                           
};

template <class T>
TQueue<T>::TQueue():size(10)
{

}
template<class T>
 TQueue<T>::TQueue(int _size)
{
	if (_size < 1)
	{
		throw std::exception();
	}
	size = _size;
	pMem = new T[size];
	start = 0;
	finish = -1;
	count = 0;
}

template<class T>
 TQueue<T>::~TQueue()
{
	delete[] pMem;
	start = 0;
	finish = -1;
	count = 0;
}

template<class T>
 TQueue<T>::TQueue(const TQueue& object)
{
	delete[] pMem;
	size = object.size;
	pMem = new T[size];
	std::copy(object.pMem, object.pMem + size, pMem);
	start = object.start;
	finish = object.finish;
	count = object.count;
}

template<class T>
bool TQueue<T>::empty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
 bool TQueue<T>::full()
{
	if (count == size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
 void TQueue<T>::Push(const T& element)
{
	if (full())
	{
		throw std::exception();
	}
	finish++;
	finish = finish % size;
	pMem[finish] = element;
	count++;
}

template<class T>
 T TQueue<T>::Pop()
{
	if (empty())
	{
		throw std::exception();
	}
	T element = pMem[start];
	start++;
	start = start % size;
	count--;
	return element;
}

template<class T>
 T TQueue<T>::front()
{
	if (this->empty())
	{
		throw std::exception();
	}
	return pMem[start];
}

template<class T>
 T TQueue<T>::back()
{
	if (this->empty())
	{
		throw std::exception();
	}
	return pMem[finish];
}

template<class T>
void TQueue<T>::operator=(const TQueue& object)
{
	start = object.start;
	finish = object.finish;
	count = object.count;
	if (count == object.count)
	{
		std::copy(object.pMem, object.pMem + size, pMem);
	}
	else
	{
		delete[] pMem;
		size = object.size;
		pMem = new T[size];
		std::copy(object.pMem, object.pMem + size, pMem);
	}
}

template<class T>
bool TQueue<T>::operator==(const TQueue& object)
{
	if (count != object.count)
	{
		return false;
	}
	else
	{
		TQueue this_tmp = *this;
		TQueue obj_tmp = object;
		while (!this_tmp.empty())
		{
			if (this_tmp.front() != obj_tmp.front())
			{
				return false;
			}
			this_tmp.Pop();
			obj_tmp.Pop();
		}
	}
	return true;
}

template<class T>
 bool TQueue<T>::operator!=(const TQueue& object)
{
	return !(*this == object);
}

template<class T>
 int TQueue<T>::GetHeadIndex()
{
	return start;
}

template<class T>
 int TQueue<T>::GetCurrentSize()
{
	return (finish - start) + 1;
}

template<class T>
 int TQueue<T>::GetMaxSize()
{
	return size;
}

template<class T>
 int TQueue<T>::NumberOfElements()
{
	return count;;
}

template<class T>
 void TQueue<T>::output()
{
	if (this->empty())
	{
		throw std::exception();
	}
	TQueue<T> this_tmp(*this);
	std::cout << "(";
	while (!(this_tmp.empty()))
	{
		std::cout <<" "<< this_tmp.Pop();
		
	}
	std::cout << " )";
	std::cout << std::endl;
}