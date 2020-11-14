#include "Graph.h"
#include "Matrix.h"
#define Max_size_of_unsigned_long_long_int 18446744073709551615

using namespace std;

void Graph::Set_Default_Matrixes(Matrix<unsigned long long int>* weights, Matrix<vector<pair<int, int>>>* wayes)
{
	vector<pair<int, int>> way;

	pair<int, int> def_part_of_way;

	def_part_of_way.first = def_part_of_way.second = -1;

	way.push_back(def_part_of_way);

	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for (int e = 0; e < amount_of_Nodes; e++)
		{
			weights->Push_Value(Max_size_of_unsigned_long_long_int, i, e);
			wayes->Push_Value(way, i, e);
		}
	}
}

Graph::Graph(int amount_of_Nodes)
{
	this->Names_of_Nodes.reserve(amount_of_Nodes);

	this->if_Can_Use_Deikstra_Algorithm = 1;

	this->amount_of_Nodes = amount_of_Nodes;

	Matrix<unsigned long long int>matrix_of_weights(amount_of_Nodes, amount_of_Nodes);
	Matrix<vector<pair<int, int>>>wayes(amount_of_Nodes, amount_of_Nodes);

	this->Set_Default_Matrixes(&matrix_of_weights, &wayes);
	
	this->weights.push_back(matrix_of_weights);
	this->wayes.push_back(wayes);
}

void Graph::Add_Node_Name(string name)
{
	this->Names_of_Nodes.push_back(name);
}

void Graph::Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed)
{
	if (weight < 0)
		this->if_Can_Use_Deikstra_Algorithm = 0;

	this->weights[0].Push_Value(weight, nomer_of_node, nomer_of_where_directed);
}

void Graph::Add_Edge(string name, int weight, string name_of_where_directed)
{
	vector<string>::iterator it1 = find(this->Names_of_Nodes.begin(), this->Names_of_Nodes.end(), name);

	vector<string>::iterator it2 = find(this->Names_of_Nodes.begin(), this->Names_of_Nodes.end(), name_of_where_directed);

	int a, b;
	a = distance(this->Names_of_Nodes.begin(), it1);
	b = distance(this->Names_of_Nodes.begin(), it2);

	this->Add_Edge(distance(this->Names_of_Nodes.begin(), it1), weight, distance(this->Names_of_Nodes.begin(), it2));
}

void Graph::Show_Grpah_in_List_Style()
{
	int nomer_of_step = 1;
	
	Matrix<unsigned long long int>m = *this->weights.begin();
	
	for (int i = 0; i < amount_of_Nodes; i++)
	{
		cout << "||" << this->Names_of_Nodes[i] << i << "||";
		for (int e = 0; e < this->amount_of_Nodes; e++)
		{
			unsigned long long int weight = m.Get_Value(i, e);

			if (weight == Max_size_of_unsigned_long_long_int || i == e)
				continue;
			else
			{
				cout << "   --" << weight << "--> " << "||" << this->Names_of_Nodes[e] << e << "||";
			}
		}
		cout << endl;
	}
}

void Graph::Canculate_Weights_and_Ways_Between_Nodes()
{

}

void Graph::Show_Result_in_Deikstra_Style()
{
}

void Graph::Show_Result_in_Floyd_Style()
{
}


