#include "lib.h"
FileScanner::FileScanner() { cout << "!Конструктор FileScanner был вызван" << endl; }
FileScanner::~FileScanner() { cout << "!Деструктор FileScanner был вызван" << endl; }
void FileScanner::scan_text()
{
	try
	{
		ifstream inp("data.txt");
		while (inp.peek() != EOF) {
			string first;
			string second;
			inp >> first >> second;
			if (!first.empty() && !second.empty()) {
				cout << second << ' ' << first << ' ';
			}
			else {
				cout << first;
			}
		}
	}
	catch (const char* ex) { cout << "Ошибка: " << ex << endl; }
	cout << endl;
}