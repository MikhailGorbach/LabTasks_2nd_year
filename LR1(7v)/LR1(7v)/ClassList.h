#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Inf
{
	string fullname;
	int day;
	int month;
	int year;
};

struct Profile
{
	Inf data;
	Profile* next, * prev;
};

class List
{

private:
	struct Inf p;
	struct Profile* top, * left, * right;

public:
	List();
	List(struct Inf information);
	List(const List& other);
	~List();
	void AddFirst();
	void AddList();
	void Print();
	void SearchAfterDate(int Day, int Month, int Year);
	void Del();
	struct Profile* getValue();
};