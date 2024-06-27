#include <iostream>
using namespace std;

void mass_create(int n, int mass[]) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		mass [i] = rand() % 201 - 100;
	}
}
void choice_sort(int n, int mass[]) {
	int min_i = 0;
	for (int i = 0; i < n; i++) {
		int min = mass[i];
		for (int j = i + 1; j < n; j++) {
			if (mass[j] < min) {
				min = mass[j];
				min_i = j;
				mass[j] = mass[i];
				mass[i] = min;
			}
		}
	}
}

int main(){
	setlocale(0, "");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	int* mass = new int[n];
	mass_create(n, mass);
	time_t start = clock();
	choice_sort(n, mass);
	time_t stop = clock();
	double time = (stop - start) / 1000.0;
	cout << time;
	return 0;
}