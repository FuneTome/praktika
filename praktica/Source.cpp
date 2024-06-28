#include <iostream>
#include <fstream>
using namespace std;

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
void create_file(int n) {
	ofstream fout("no_sort_array.txt");
	srand(time(0));
	for (int i = 0; i < n; i++) {
		fout << rand() % 20001 - 10000 << endl;
	}
	fout.close();
}
void menu() {
	int n;
	cout << "\n\t1. Случайный ввод\n\t2. Ручной ввод\n\t3. Ввод с файла\n\t4. Выход\n\tВыберите пункт: ";
	cin >> n;
	switch (n) {
	case 1: {
		int n, buf = 0;
		cout << "Введите количество элементов: ";
		cin >> n;
		int* mass = new int[n];
		create_file(n);
		ifstream fin("no_sort_array.txt");
		for (int i = 0; i < n; i++) {
			fin >> mass[i];
		}
		fin.close();
		time_t start = clock();
		choice_sort(n, mass);
		time_t stop = clock();
		double time = (stop - start) / 1000.0;
		cout << time;
		ofstream fout("sort_array.txt");
		for (int i = 0; i < n; i++) {
			fout << mass[i] << endl;
		}
		fout.close();
	}break;
	case 2: {
		int n;
		cout << "Введите количество элементов: ";
		cin >> n;
		int* mass = new int[n];
	}break;
	case 3: {}break;
	case 4: { exit(0); } break;
	default:{ cout << "Такого пункта нет, попробуйте ещё раз" << endl; }break;
	}
}

int main(){
	setlocale(0, "");
	menu();
	return 0;
}