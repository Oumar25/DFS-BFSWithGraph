#include "pch.h"
#include "Graph.h"


Graph::Graph()
{
	vertexMap = shared_ptr<map<string, shared_ptr<Vertex>>>(new map<string, shared_ptr<Vertex>>());
}


Graph::~Graph()
{
}

shared_ptr<Vertex> Graph::getTargetVertex(string name)
{
	map<string, shared_ptr<Vertex>>::iterator iter;
	iter = vertexMap->find(name);
	if (iter == vertexMap->end())
	{
		throw invalid_argument(" Not Found: " + name);
	}
	return iter->second;
}

void Graph::addAdjacentVertex(string start, string end)
{
	shared_ptr<Vertex> startLoc = getTargetVertex(start);
	shared_ptr<Vertex> endLoc = getTargetVertex(end);
	startLoc->addAjacentVertex(endLoc);
}

void Graph::addVertex(string name)
{
	shared_ptr<Vertex> vertex = shared_ptr<Vertex>(new Vertex(name));
	vertexMap->insert(std::pair<string, shared_ptr<Vertex>>(name, vertex));
}
