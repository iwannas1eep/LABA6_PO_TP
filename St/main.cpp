#include "lib.h"
int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	Menu menu;
	menu.main_menu();
	return 0;
}