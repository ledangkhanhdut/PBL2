#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <thread>
#include <windows.h>

using namespace std;
// Khai báo trong file header
//extern void Design();
void Design();
string getCurrentDate();
string add_day(const string &, int);
int calculateDayDifference(const string &, const string &);
bool isNumeric(const string &);
void String_processing(string &);
void removeDashes(string &);
string Extral_Status(char);