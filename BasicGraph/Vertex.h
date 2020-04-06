#pragma once
#include "pch.h"
#include "DataValue.h"
#include <string>
#include <memory>
#include <vector>

using namespace std;
class Vertex
{
public:
	Vertex(string name);
	~Vertex();

	vector <shared_ptr<Vertex>> getAdjacencies();
	void addAjacentVertex(shared_ptr<Vertex>);
	shared_ptr<DataValue> getDataValue();
	void setDataValue(shared_ptr<DataValue>);
	int getNumbAjacencies();

private:
	vector <shared_ptr<Vertex>> adjacencies;
	shared_ptr<DataValue> dataValue;
};

