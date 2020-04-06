#include "pch.h"
#include "DataValue.h"

using namespace std;

DataValue::DataValue(string n)
{
	name = n;
}


DataValue::~DataValue()
{
}

string DataValue::getName()
{
	return name;
}

