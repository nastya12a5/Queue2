#include "../Queue/TQueue.h"
#include <iostream>
#include "queue";
#include <random>
#include <locale.h>
#include <cstdlib>
#include <ctime>
using namespace std;
struct TTask {
	int id;
};
int main() {
	
	setlocale(LC_CTYPE, "Russian");
	queue<int> tasks;
	int tasksAdded = 0;
	int tasksProcessed = 0;
	int emptyQueueCount = 0;
	int fullQueueCount = 0;

	srand(static_cast<unsigned int>(time(0)));

	double P = 0.4; // вероятность добавления задания
	double Q = 0.8; // вероятность извлечения задания

	for (int i = 0; i < 100; ++i) { // имитируем 100 итераций
		if ((double)rand()/RAND_MAX < P) { // добавляем задание с вероятностью P
			TTask newTask;
			newTask.id = i;
			tasks.push(i);
			tasksAdded++;
			
		}
		
		if (!tasks.empty() && (double)rand() / RAND_MAX < Q) { // извлекаем задание с вероятностью Q
			tasks.pop();
			tasksProcessed++;
		}
		if (tasks.size() >= 10) {
			fullQueueCount++;
		}
		 else if (tasks.empty()) {
			emptyQueueCount++;
		}
		
	}
	
	cout << "Добавлено заданий: " << tasksAdded << endl;
	cout << "Извлечено заданий: " << tasksProcessed << endl;
	cout << "Очередь была пустой " << emptyQueueCount << " раз" << endl;
	cout << "Очередь была полной " << fullQueueCount << " раз" << endl;

	return 0;
}