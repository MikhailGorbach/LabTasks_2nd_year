#include "Train.h"
Train::Train(int id, string end, int hours, int min)
{
	this->id = id;
	this->end = end;
	this->hours = hours;
	this->min = min;
}
Train::Train()
{
	this->id = 0;
	this->end = "";
	this->hours = 0;
	this->min = 0;
}
int Train::getId()
{
	return this->id;
}
string Train::getEnd()
{
	return this->end;
}
int Train::getHours()
{
	return this->hours;
}
int Train::getMin()
{
	return this->min;
}