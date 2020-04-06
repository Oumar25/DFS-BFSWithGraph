// BasicGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "DataValue.h"
#include "Vertex.h"
#include "Graph.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <list>

using namespace std;

//Do not modify this method
bool alreadyvisit(vector<string> & checked, string city1);

void createVertices(shared_ptr<Graph> graph)
{
	graph->addVertex("Austin");
	graph->addVertex("Denver");
	graph->addVertex("Chicago");
	graph->addVertex("Houston");
	graph->addVertex("Washington");
	graph->addVertex("Atlanta");
	graph->addVertex("Dallas");
}

//Do not modify this method
void createEdges(shared_ptr<Graph> graph)
{
	graph->addAdjacentVertex("Dallas", "Austin");
	graph->addAdjacentVertex("Dallas", "Chicago");
	graph->addAdjacentVertex("Dallas", "Denver");

	graph->addAdjacentVertex("Austin", "Dallas");
	graph->addAdjacentVertex("Austin", "Houston");

	graph->addAdjacentVertex("Chicago", "Denver");

	graph->addAdjacentVertex("Denver", "Chicago");
	graph->addAdjacentVertex("Denver", "Washington");

	graph->addAdjacentVertex("Houston", "Atlanta");

	graph->addAdjacentVertex("Washington", "Dallas");
	graph->addAdjacentVertex("Washington", "Atlanta");

	graph->addAdjacentVertex("Atlanta", "Washington");
	graph->addAdjacentVertex("Atlanta", "Houston");
}

//add code to do BFS search to this method
void doBFS(shared_ptr<Graph> graph, string startCity, string destinationCity)
{
	cout << "The BFS path is: " << endl;
	queue<shared_ptr<Vertex>> myqueue;
	bool found = false;
	myqueue.push(graph->getTargetVertex(startCity));
	shared_ptr<Vertex> endcity = graph->getTargetVertex(destinationCity);

	vector<string> passthrougIt;
	string y;
	vector<pair<string, string>> city;
	list<pair<string, string>> citylist;
	
	
	
	do
	{
		shared_ptr<Vertex> end = myqueue.front();
		myqueue.pop();
		
		if (end == endcity)
		{
			passthrougIt.push_back(end->getDataValue()->getName());
			found = true;
		}
		else
		{
		
			if (alreadyvisit(passthrougIt, end->getDataValue()->getName()) == false)
			{
				passthrougIt.push_back(end->getDataValue()->getName());
				y = end->getDataValue()->getName();
				shared_ptr<Vertex> vertex = graph->getTargetVertex(end->getDataValue()->getName());
				vector<shared_ptr<Vertex>> adjNodes = vertex->getAdjacencies();
				vector<shared_ptr<Vertex>>::iterator vertexIter;
				for (vertexIter = adjNodes.begin(); vertexIter != adjNodes.end(); vertexIter++)
				{
					shared_ptr<Vertex> targetEdge = *vertexIter;				
					if (alreadyvisit(passthrougIt, targetEdge->getDataValue()->getName()) == false)
					{    
						myqueue.push(targetEdge);	
						city.emplace_back(y, targetEdge->getDataValue()->getName());	
						citylist.push_back(make_pair(y, targetEdge->getDataValue()->getName()));
					}
				}
			}
		}
	} while (!myqueue.empty() && !found);
	
	list<string> cityPrintList;
	string currentCity = passthrougIt.back();
	cityPrintList.push_back(currentCity);
	do
	{
		for (pair<string, string> tempCityPair : city)
		{
			if (tempCityPair.second == cityPrintList.back())
			{
				currentCity = tempCityPair.first;
				break;
			}
		}
		cityPrintList.push_back(currentCity);
	} while (cityPrintList.back() != graph->getTargetVertex(startCity)->getDataValue()->getName());
	cityPrintList.reverse();
	cityPrintList.pop_back();
	list <string> ::iterator it;
	for (list<string>::iterator it = cityPrintList.begin(); it != cityPrintList.end(); ++it) {
		cout << *it << "-->";
	}
	cout << destinationCity;
	cout << endl << endl;
}

//add code to do DFS search to this method
void doDFS(shared_ptr<Graph> graph, string startCity, string destinationCity)
{
	cout << " The DFS path is: " << endl;
	stack<shared_ptr<Vertex>> mystack;
	bool found = false;
	mystack.push(graph->getTargetVertex(startCity));
	shared_ptr<Vertex> endcity = graph->getTargetVertex(destinationCity);
	vector<string> passthrougIt;
	string y;
	vector<pair<string, string>> city;

	do
	{
		shared_ptr<Vertex> end = mystack.top();
		mystack.pop();
		
		if (end == endcity)
		{
			passthrougIt.push_back(end->getDataValue()->getName());
			found = true;
		}
		else
		{
			if (alreadyvisit(passthrougIt, end->getDataValue()->getName()) == false)
			{
				passthrougIt.push_back(end->getDataValue()->getName());;
				y = end->getDataValue()->getName();
				shared_ptr<Vertex> vertex = graph->getTargetVertex(end->getDataValue()->getName());
				vector<shared_ptr<Vertex>> adjNodes = vertex->getAdjacencies();
				vector<shared_ptr<Vertex>>::iterator vertexIter;
				for (vertexIter = adjNodes.begin(); vertexIter != adjNodes.end(); vertexIter++)
				{
					shared_ptr<Vertex> targetEdge = *vertexIter;
					if (alreadyvisit(passthrougIt, targetEdge->getDataValue()->getName()) == false)
					{
						mystack.push(targetEdge);
						city.emplace_back(y, targetEdge->getDataValue()->getName());
					}
				}
			}
		}
	}while (!mystack.empty() && !found);
	
		
			for (int i = passthrougIt.size() - 1; i >= 1; --i) {
				string me = passthrougIt[i];
				string you = passthrougIt[i - 1];
				auto p = std::make_pair(you, me);
				if (find(city.begin(), city.end(), p) != city.end()) {

				}
				else
				{
					passthrougIt.erase(std::remove(passthrougIt.begin(), passthrougIt.end(), you), passthrougIt.end());
				}
			}
			passthrougIt.pop_back();
		for (auto const& i : passthrougIt) {
			cout << i << "-->";
		}
		cout << destinationCity;
		cout << endl << endl;
}
bool alreadyvisit(vector<string> & checked, string city1)
{
	vector<string>::iterator iter;
	for (iter = checked.begin(); iter != checked.end(); iter++)
	{
		string city = *iter;
		if (city == city1)
		{
			return true;
		}
	}
	return false;
}

//Do not modify this method
int main()
{
	shared_ptr<Graph> graph = shared_ptr<Graph>(new Graph());

	//create  vertices
	createVertices(graph);

	//now add the edges
	try
	{
		createEdges(graph);
	}
	catch (invalid_argument e)
	{
		cout << "Invalid city, cannot create edges: " << e.what() << endl;
		cout << "Program exiting" << endl << endl;
		system("pause");
		return 0;
	}

	bool doAnother = true;
	while (doAnother)
	{
		cout << endl << "Enter the starting city, or x to exit: ";
		string startCity;
		getline(cin, startCity);
		if (tolower(startCity[0]) == 'x')
		{
			doAnother = false;
			continue;
		}

		cout << "Enter the destination city: ";
		string destinationCity;
		getline(cin, destinationCity);

		try
		{
			doBFS(graph, startCity, destinationCity);
			doDFS(graph, startCity,destinationCity);
		}
		catch (invalid_argument e)
		{
			cout << "Invalid city in search: " << e.what() << endl;
		}

		


		//Debug code that you might find useful for testing, do not include it in your submission
		//it outputs all the adjacent cities
		/*shared_ptr<Vertex> vertex = graph->getTargetVertex(startCity);
		vector<shared_ptr<Vertex>> adjNodes = vertex->getAdjacencies();

		vector<shared_ptr<Vertex>>::iterator vertexIter;
		for (vertexIter = adjNodes.begin(); vertexIter != adjNodes.end(); vertexIter++)
		{
			shared_ptr<Vertex> targetEdge = *vertexIter;
			cout << "Start = " << startCity << ",  Target = " << targetEdge->getDataValue()->getName() << endl;
		}*/
	}
	return 0;
}