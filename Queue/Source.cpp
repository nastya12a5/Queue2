#include<iostream>
#include "TQueue.h"

/*int main()
{
	TQueue<int> q(4);
	int i = 1;
	while (!(q.full()))
	{
		q.Push(i);
		i++;
	}
	
	q.output();

	TQueue<int> q1(q);
	q1.output();
	
}*/
//#include "../Queue/TQueue.h"
#include <iostream>

#include <random>
using namespace std;
int main() {
	TQueue<int> tasks;
	int tasksAdded = 0;
	int tasksProcessed = 0;
	int emptyQueueCount = 0;
	int fullQueueCount = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);

	double P = 0.7; // вероятность добавления задания
	double Q = 0.5; // вероятность извлечения задания

	for (int i = 0; i < 100; ++i) { // имитируем 100 итераций
		if (dis(gen) < P) { // добавляем задание с вероятностью P
			tasks.Push(i);
			tasksAdded++;
			if (tasks.GetMaxSize() == 10) {
				fullQueueCount++;
			}
		}

		if (!tasks.empty() && dis(gen) < Q) { // извлекаем задание с вероятностью Q
			tasks.Pop();
			tasksProcessed++;
		}
		else if (tasks.empty()) {
			emptyQueueCount++;
		}
	}

	cout << "Добавлено заданий: " << tasksAdded << std::endl;
	cout << "Извлечено заданий: " << tasksProcessed << std::endl;
	cout << "Очередь была пустой " << emptyQueueCount << " раз" << std::endl;
	cout << "Очередь была полной " << fullQueueCount << " раз" << std::endl;

	//return 0;
}