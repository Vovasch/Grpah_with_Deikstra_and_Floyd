#include "Graph.h"
#include "Matrix.h"
#define Max_size_of_unsigned_long_long_int 18446744073709551615

using namespace std;

Graph::Graph(int amount_of_Nodes)
{
	this->if_Can_Use_Deikstra_Algorithm = 1;

	this->amount_of_Nodes = amount_of_Nodes;

	Matrix<unsigned long long int>matrix_of_weights(amount_of_Nodes, amount_of_Nodes);
	Matrix<pair<int, int>> matrix_of_ways(amount_of_Nodes, amount_of_Nodes);

	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for (int e = 0; e < amount_of_Nodes; e++)
		{
			matrix_of_weights.Push_Value(Max_size_of_unsigned_long_long_int, i, e);
		}
	}

	pair<int, int> way;
	way.first = way.second = -1;

	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for (int e = 0; e < amount_of_Nodes; e++)
		{
			matrix_of_ways.Push_Value(way, i, e);
		}
	}

	this->weights.push_back(matrix_of_weights);
	this->wayes.push_back(matrix_of_ways);
}

void Graph::Add_Edge(int nomer_of_node, int weight)
{
	if (weight < 0)
		this->if_Can_Use_Deikstra_Algorithm = 0;

	this->weights[0].Push_Value(nomer_of_node, nomer_of_node, weight);
}

void Graph::Add_Edge(string name, int weight)
{
	vector<string>::iterator it = find(this->Names_of_Nodes.begin(), this->Names_of_Nodes.end(), name);
	this->Add_Edge(distance(this->Names_of_Nodes.begin(), it), weight);
}


