#include "../Queue/TQueue.h"
#include <iostream>
#include "queue";
#include <random>
#include <locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	queue<int> tasks;
	int tasksAdded = 0;
	int tasksProcessed = 0;
	int emptyQueueCount = 0;
	int fullQueueCount = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);

	double P = 0.7; // вероятность добавления задания
	double Q = 0.5; // вероятность извлечения задания

	for (int i = 0; i < 100; ++i) { // имитируем 100 итераций
		if (dis(gen) < P) { // добавляем задание с вероятностью P
			tasks.push(i);
			tasksAdded++;
			if (tasks.size() == 10) {
				fullQueueCount++;
			}
		}

		if (!tasks.empty() && dis(gen) < Q) { // извлекаем задание с вероятностью Q
			tasks.pop();
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

	return 0;
}