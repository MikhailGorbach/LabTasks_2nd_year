#pragma once
#include "Train.h"
#include <list>
class List
{
private:
	list<Train> list;
public:
	List();
	void NewList();
	void Print();
	void PrintById(int id);
	void PrintByStation(string station);
	void Save();
	void Upload();
};