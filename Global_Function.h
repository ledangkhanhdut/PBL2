#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cctype>
// #include <windows.h>

using namespace std;

void Design();
string getCurrentDate();
string add_day(const string &, int);
int calculateDayDifference(const string &, const string &);
bool isNumeric(const string &);
void String_processing(string &);
void removeDashes(string &);
string Extral_Status(char);