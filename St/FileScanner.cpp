#include "FileScanner.h"
#include "lib.h"
FileScanner::FileScanner() {}

FileScanner::~FileScanner() {}

void FileScanner::scan_text()
{
   ifstream inp("data.txt");
   string first;
   string second;
   while (inp >> first >> second) {
       if (!first.empty() && !second.empty()) {
           cout << second << ' ' << first << ' ' << endl;
       }
       else {
           cout << first << endl;
       }
   }
}
