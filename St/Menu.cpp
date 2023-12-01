#include "lib.h"
int comp(Group* j, Group* i) {
	return (int)(((Group*)j)->get_number() - ((Group*)i)->get_number());
}
void Menu::main_menu() {
	while (exit == 1) {
		switch (show_options()) {
		case 1:
			show_all();
			break;
		case 2:
			add_new_group();
			break;
		case 3:
			show_all();
			add_new_stud();
			break;
		case 4:
			delete_group();
			break;
		case 5:
			delete_student();
			break;
		case 6:
			average_stud();
			break;
		case 7:
			red_group();
			break;
		case 8:
			red_student();
			break;
		case 9:
			scan();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}
void Menu::scan() {
	FileScanner a;
	a.scan_text();
}
void Menu::average_stud() {
	string back;
	float num = 0;
	bool fl = false;
	while (fl == false) {
		try {
			getline(cin, back);
			num = stof(back);
			fl = true;
		}
		catch (...) {
			cout << "Enter avarage mark" << endl;
		}
	}
	cout << "List of students whose average mark more than " << num << ":" << endl;
	int flag = 0;
	bool emp = true;
	for (int i = 0; i < count; i++) {
		flag = 0;
		for (int j = 0; j < list[i].get_size(); j++) {
			if (list[i].get_data()[j].av_mark() >= num) {
				if (flag == 0) {
					flag = 1;
				}
					if (flag == 1) {
						flag = 2;
						cout << "Group number:" << list[i].get_number() << endl;
					}
				list[i].get_data()[j].show();
			}
		}
		if (flag != 0) emp = false;
	}
	if (emp == true) cout << "There are no such students" << endl;
}
int Menu::show_options()
{
	int c1;
	cout << "\nWhat do you want to do?" << endl;
	cout << "Task #1" << endl;
	cout << "1 - Show all groups" << endl;
	cout << "2 - Add group" << endl;
	cout << "3 - Add new student" << endl;
	cout << "4 - Delete a group" << endl;
	cout << "5 - Delete a student" << endl;
	cout << "6 - Displaying all students whose average mark is greater than the specified one; " << endl;
	cout << "7 - Redact group" << endl;
	cout << "8 - Redact student" << endl;
	//To work correctly, you need to enter a real number, with two numbers after the dot
	cout << "Task #2" << endl;
	cout << "9 - File Scan" << endl;
	cout << "0 - Exit" << endl;
	cout << "-> ";
	cin >> c1;
	return c1;
}
void Menu::show_all()
{
	try {
		if (count == 0) {
			throw "There's nothing to show.";
		}
		for (int i = 0; i < count; i++) {
			cout << "_" << endl;
			cout << i + 1 << "|";
			list[i].show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
}

void Menu::add_new_stud() {
	string back;
	int num = 0;
	bool fl = false;
	while (fl == false)
	{
		try {
			getline(cin, back);
			num = stoi(back);
			fl = true;
		}
		catch (...) {
			cout << "Enter the number of group" << endl;
		}
	}

	Student* student;
	student = new Student;
	student->rewrite();
	this->list[num - 1].insert(student);
}
void Menu::delete_student() {
	cout << "Enter number of group" << endl;
	int num;
	cin >> num;
	cout << "Enter number of student" << endl;
	int ind;
	cin >> ind;
	this->list[num - 1].insert(ind - 1);
}
void Menu::add_new_group() {
	string back;
	int num = 0;
	bool fl = false;

	while (fl == false) {

		try {
			getline(cin, back);
			num = stoi(back);
			fl = true;
		}
		catch (...) {
			cout << "Enter the number of group" << endl;
		}
	}

	Group* backup = new Group[count];
	for (int i = 0; i < count; i++) {
		backup[i] = list[i];
	}
	list = new Group[count + 1];
	list[count] = *(new Group(0, num));
	for (int i = 0; i < count; i++) {
		list[i] = backup[i];
	}
	count++;
	qsort(list, count, sizeof(*list), (int(*)(const void*, const void*))comp);
}
void Menu::delete_group() {
	int ind;
	Group backup;
	Group* buff;
	cout << "Enter number: ";
	cin >> ind;
	ind -= 1;
	for (int i = ind; i < count - 1; i++) {
		backup = list[i];
		list[i] = list[i + 1];
		list[i + 1] = backup;
	}
	buff = new Group[count - 1];
	for (int i = 0; i < count - 1; i++) {
		buff[i] = list[i];
	}
	list = new Group[count - 1];
	for (int i = 0; i < count - 1; i++) {
		list[i] = buff[i];
	}
	count--;
}
void Menu::red_group() {
	string back;
	int num = 0;
	bool fl = false;
	while (fl == false) {
		try {
			getline(cin, back);
			num = stoi(back);
				fl = true;
		}
		catch (...) {
			cout << "Enter the number of group" << endl;
		}
	}
	cout << "Enter new number:" << endl;
	fl = false;
	int num_n = 0;
	while (fl == false) {
		try {
			getline(cin, back);
			num_n = stoi(back);
			fl = true;
		}
		catch (...) {
			cout << "Enter new number of group" << endl;
		}
	}
	list[num - 1].set_number(num_n);
	qsort(list, count, sizeof(*list), (int(*)(const void*, const void*))comp);
}
void Menu::red_student() {
	string back;
	int num = 0;
	bool fl = false;
	while (fl == false) {
		try {
			getline(cin, back);
			num = stoi(back);
			fl = true;
		}
		catch (...) {
			cout << "Enter the number of group" << endl;
		}
	}
	int num_stud = 0;
	fl = false;
	while (fl == false) {
		try {
			getline(cin, back);
			num_stud = stoi(back);
			fl = true;
		}
		catch (...) {
			cout << "Enter the number of student" << endl;
		}
	}
	list[num - 1].get_data()[num_stud - 1].rewrite();
}
void Menu::exit_from_programm()
{
	exit = 0;
}