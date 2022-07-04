#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

constexpr auto MIN_HOUR = 3, MAX_HOUR = 15, MONTH = 11;

class month {

private:
	string name;
	int first;
	int firstLeap;
	int lastLEap;
	int last;

public:

static	bool isLeapYear(string);

	void setName(string);
	void setFirst(int);
	void setLast(int);
	void setFirstLeap(int);
	void setLastLeap(int);

	string getName();
	int getFirst();
	int getLast();
	int getFirstLeap();
	int getLastLeap();
	
};

void monthInitializer(month*);
int whatMonth(string , int , month* );
void Download(int, int, string, string, string, string, string);
void DownloadM(int, int, string, string, string, string, string, int, month*);
void DownloadGM(int, int, string, string, string, string, string, month*);
void waitForInput();

