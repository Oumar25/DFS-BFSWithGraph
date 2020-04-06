#pragma once
#include <memory>
#include <string>
#include <map>
#include <stdexcept>
#include "Vertex.h"

using namespace std;

class Graph
{
public:
	Graph();
	~Graph();

	shared_ptr<Vertex> getTargetVertex(string name);
	void addAdjacentVertex(string start, string end);
	void addVertex(string name);


private:
	shared_ptr<map<string, shared_ptr<Vertex>>> vertexMap;	//holds vertices as they're created

};

