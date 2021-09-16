#pragma once
#include <string>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Train
{
private:
	int id;
	string end;
	int hours;
	int min;
	int sec;
public:
	Train();
	Train(int id, string end, int hours, int min);
};
