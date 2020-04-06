#include "pch.h"
#include "Vertex.h"

using namespace std;


Vertex::Vertex(string name)
{
	dataValue = nullptr;
	adjacencies.clear();
	dataValue = shared_ptr<DataValue>(new DataValue(name));
}


Vertex::~Vertex()
{
}

vector<shared_ptr<Vertex>> Vertex::getAdjacencies()
{
	return adjacencies;
}

void Vertex::addAjacentVertex(shared_ptr<Vertex> vertex)
{
	adjacencies.push_back(vertex);
}

shared_ptr<DataValue> Vertex::getDataValue()
{
	return dataValue;
}

void Vertex::setDataValue(shared_ptr<DataValue> value)
{
	dataValue = value;
}

int Vertex::getNumbAjacencies()
{
	return adjacencies.size();
}
