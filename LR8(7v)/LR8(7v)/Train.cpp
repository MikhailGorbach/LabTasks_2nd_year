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