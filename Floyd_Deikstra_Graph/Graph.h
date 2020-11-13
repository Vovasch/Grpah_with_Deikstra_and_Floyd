#include<utility>
#include<vector>
#include<string>

#include"Matrix.h"

using namespace std;

#pragma once

class Graph
{
private:

	int amount_of_Nodes;

	vector<string> Names_of_Nodes;

	bool if_Can_Use_Deikstra_Algorithm; // if edge < 0 we can't use Deikstra Algorithm

	vector<Matrix<unsigned long long int>>weights;

	vector<Matrix<pair<int, int>>>wayes;


public:

	Graph(int amount_of_Nodes);

	void Add_Edge(int nomer_of_node, int weight);
	void Add_Edge(string name, int weight);



};