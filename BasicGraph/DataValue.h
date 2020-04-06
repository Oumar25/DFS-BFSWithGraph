#pragma once
#include "pch.h"
#include <string>


using namespace std;

class DataValue
{
public:
	DataValue(string name);
	~DataValue();

	string getName();

private:
	string name;
};

