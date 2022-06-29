#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

constexpr auto MIN_HOUR = 3, MAX_HOUR = 15;

class month {

private:
	string name;
	int id;
	int first;
	int firstLeap;
	int lastLEap;
	int last;

public:
	bool isLeapYear(string);
	int getFirst();
	int getLast();
	int getFirstLeap();
	int getLastLeap();
	int getId();

};

void Download(int, int, string, string, string, string, string);
void waitForInput();
