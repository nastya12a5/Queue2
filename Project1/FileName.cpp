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

	double P = 0.7; // ����������� ���������� �������
	double Q = 0.5; // ����������� ���������� �������

	for (int i = 0; i < 100; ++i) { // ��������� 100 ��������
		if (dis(gen) < P) { // ��������� ������� � ������������ P
			tasks.push(i);
			tasksAdded++;
			if (tasks.size() == 10) {
				fullQueueCount++;
			}
		}

		if (!tasks.empty() && dis(gen) < Q) { // ��������� ������� � ������������ Q
			tasks.pop();
			tasksProcessed++;
		}
		else if (tasks.empty()) {
			emptyQueueCount++;
		}
	}
	
	cout << "��������� �������: " << tasksAdded << std::endl;
	cout << "��������� �������: " << tasksProcessed << std::endl;
	cout << "������� ���� ������ " << emptyQueueCount << " ���" << std::endl;
	cout << "������� ���� ������ " << fullQueueCount << " ���" << std::endl;

	return 0;
}