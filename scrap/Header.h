#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <boost/filesystem.hpp>
#include <vector>	
#include <iterator>
#include <algorithm>

using namespace std;
using namespace boost::filesystem;


#define MIN_HOUR 3
#define MAX_HOUR 15


void Download(int, int, string, string, string, string, string);

void waitForInput();
int FileTime(string);
int FileArray(string);
int FileArrayRec(string);
