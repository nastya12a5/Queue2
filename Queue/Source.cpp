#include<iostream>
#include "TQueue.h"
using namespace std;
int main()
{
	TLQueue<int> q;
	
		q.Push(1);
		q.Push(2);
		q.Push(3);
		q.Push(4);
	

	TLQueue<int> q1(q);
	q1.output();
	cout << "Front "<<q1.Front() << endl;
	cout << "Back " << q1.Back();
	
}
