#include <iostream>
#include <fstream>
using namespace std;

void choice_sort(int n, int mass[]) {
	int buf = 0;
	for (int i = 0; i < n - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < n; j++) {
			if (mass[j] < mass[min_i]) { min_i = j; }
		}
		if (min_i != i) {
			buf = mass[i];
			mass[i] = mass[min_i];
			mass[min_i] = buf;
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
	int n, count;
	string name, t = ".txt";
	cout << "\n\t1. Случайный ввод\n\t2. Ручной ввод\n\t3. Ввод с файла\n\t4. Выход\n\n\tВыберите пункт: ";
	cin >> n;
	cout << endl;
	while (true){
	switch (n) {
	case 1: {
		int n, buf = 0;
		cout << "\tВведите количество элементов: ";
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
		cout << "\n\tВремя сортировки массива состовляет: " << time << " секунд\n";
		ofstream fout("sort_array.txt");
		for (int i = 0; i < n; i++) {
			fout << mass[i] << endl;
		}
		fout.close();
		exit(0);
	}
	case 2: {
		int n;
		cout << "\tВведите количество элементов: ";
		cin >> n;
		cout << endl;
		int* mass = new int[n];
		for (int i = 0; i < n; i++) {
			cout << "\tВведите " << i + 1 << " элемент массива: ";
			cin >> mass[i];
			cout << endl;
		}
		time_t start = clock();
		choice_sort(n, mass);
		time_t stop = clock();
		double time = stop - start;
		cout << "\tВремя сортировки массива состовляет: " << time << " милисекунд\n\n" << "Сортированный массив: ";
		for (int i = 0; i < n; i++) {
			cout << mass[i] << " ";
		}
		exit(0);
	}
	case 3: {
		cout << "\tВведите имя файла: ";
		cin >> name;
		name += t;
		ifstream fin(name);
		fin >> count;
		int* mass = new int[count];
		for (int i = 0; i < count; i++) {
			fin >> mass[i];
		}
		fin.close();
		time_t start = clock();
		choice_sort(count, mass);
		time_t stop = clock();
		double time = (stop - start) / 1000.0;
		cout << "\n\tВремя сортировки массива состовляет: " << time << " секунд";
		ofstream fout("sort_array.txt");
		for (int i = 0; i < count; i++) {
			fout << mass[i] << endl;
		}
		fout.close();
		exit(0);
	}
	case 4: { exit(0); } break;
	default: { cout << "Такого пункта нет, попробуйте ещё раз" << endl; }break;
	}
}
}

int main(){
	setlocale(0, "");
	menu();
	return 0;
}