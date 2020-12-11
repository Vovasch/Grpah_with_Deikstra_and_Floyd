#include<string>

#pragma once

using namespace std;

struct Node
{
	string Name_of_Node;
	long long int distance_from_beginning;
	int nomer_of_Previous_Node; // use it for building way based on Dejkstra algorthm
	
	bool already_Canculated_by_Dejkstra_algr;

	Node();
	void Show_Node(int nomer_of_its_Node);
	
};