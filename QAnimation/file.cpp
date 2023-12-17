#include "../Queue/TQueue.h"
#include <iostream>

#include <random>

int main() {
	std::TQueue<int> tasks;
	int tasksAdded = 0;
	int tasksProcessed = 0;
	int emptyQueueCount = 0;
	int fullQueueCount = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);

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

	std::cout � "��������� �������: " � tasksAdded � std::endl;
	std::cout � "��������� �������: " � tasksProcessed � std::endl;
	std::cout � "������� ���� ������ " � emptyQueueCount � " ���" � std::endl;
	std::cout � "������� ���� ������ " � fullQueueCount � " ���" � std::endl;

	return 0;
}
