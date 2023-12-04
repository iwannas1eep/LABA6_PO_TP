#include "lib.h"
Student::Student() {
}
Student::Student(string new_name) {
	name = new_name;
	mark = nullptr;
	size = 0;
	//cout << "!Группа конструкторов была вызвана" << endl;
}
Student::~Student() {
	//cout << "!Деструктор был вызван" << endl;
}
Student::Student(const Student& Student_copy) {
	name = Student_copy.name;
	mark = Student_copy.mark;
	size = Student_copy.size;
	//cout << "!Группа деструкторов была вызвана" << endl;
}
string Student::get_name() const { return name; }
int* Student::get_mark() const { return mark; }
int Student::get_size() const { return size; }
void Student::set_name(string new_name) { name = new_name; }
void Student::set_mark(int* new_mark) { mark = new_mark; }
void Student::set_size(int new_size) { size = new_size; }
float Student::av_mark() {
	float res = 0;
	for (int i = 0; i < size; i++) {
		res += *(mark + i);
	}
	return res / size;
}
void Student::show() {
	cout << "Имя: " << name << endl;
	cout << "Оценки: ";
	for (int i = 0; i < size; i++) {
		cout << *(mark + i) << " ";
	}
	cout << endl;
}
void Student::rewrite() {
	cin.ignore(32767, '\n');
	cout << "Введите имя: ";
	getline(cin, name);

	cout << "Введите количество оценок: ";
	cin >> size;

	mark = new int[size];
	cout << "Введите оценки: ";
	for (int i = 0; i < size; i++)
	{
		cin >> *(mark + i);
	}
}
