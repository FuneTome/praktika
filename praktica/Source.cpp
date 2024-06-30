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
	cout << "\n\t1. ��������� ����\n\t2. ������ ����\n\t3. ���� � �����\n\t4. �����\n\n\t�������� �����: ";
	cin >> n;
	cout << endl;
	while (true){
	switch (n) {
	case 1: {
		int n, buf = 0;
		cout << "\t������� ���������� ���������: ";
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
		cout << "\n\t����� ���������� ������� ����������: " << time << " ������\n";
		ofstream fout("sort_array.txt");
		for (int i = 0; i < n; i++) {
			fout << mass[i] << endl;
		}
		fout.close();
		exit(0);
	}
	case 2: {
		int n;
		cout << "\t������� ���������� ���������: ";
		cin >> n;
		cout << endl;
		int* mass = new int[n];
		for (int i = 0; i < n; i++) {
			cout << "\t������� " << i + 1 << " ������� �������: ";
			cin >> mass[i];
			cout << endl;
		}
		time_t start = clock();
		choice_sort(n, mass);
		time_t stop = clock();
		double time = stop - start;
		cout << "\t����� ���������� ������� ����������: " << time << " ����������\n\n" << "������������� ������: ";
		for (int i = 0; i < n; i++) {
			cout << mass[i] << " ";
		}
		exit(0);
	}
	case 3: {
		cout << "\t������� ��� �����: ";
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
		cout << "\n\t����� ���������� ������� ����������: " << time << " ������";
		ofstream fout("sort_array.txt");
		for (int i = 0; i < count; i++) {
			fout << mass[i] << endl;
		}
		fout.close();
		exit(0);
	}
	case 4: { exit(0); } break;
	default: { cout << "������ ������ ���, ���������� ��� ���" << endl; }break;
	}
}
}

int main(){
	setlocale(0, "");
	menu();
	return 0;
}