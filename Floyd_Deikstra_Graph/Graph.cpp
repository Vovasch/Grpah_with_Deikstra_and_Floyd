#include "Graph.h"
#include "Matrix.h"
#define Max_size_of_unsigned_long_long_int 18446744073709551

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
			
			if (i == e)
				weights->Push_Value(0, i, e);

			wayes->Push_Value(way, i, e);
		}
	}
}

Graph::Graph(int amount_of_Nodes)
{
	this->Names_of_Nodes.reserve(amount_of_Nodes);
	this->distances_From_Begging.reserve(amount_of_Nodes);

	for (auto i : this->distances_From_Begging)
	{
		i = Max_size_of_unsigned_long_long_int;
	}

	this->distances_From_Begging.push_back(0);

	this->if_Can_Use_Deikstra_Algorithm = 1;

	this->amount_of_Nodes = amount_of_Nodes;

	Matrix<unsigned long long int>matrix_of_weights(amount_of_Nodes, amount_of_Nodes);
	Matrix<vector<pair<int, int>>>wayes(amount_of_Nodes, amount_of_Nodes);

	this->Set_Default_Matrixes(&matrix_of_weights, &wayes);
	
	this->all_Weights.push_back(matrix_of_weights);
	this->all_Ways.push_back(wayes);
}

void Graph::Add_Node_Name(string name)
{
	this->Names_of_Nodes.push_back(name);
}

void Graph::Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed)
{
	if (weight < 0)
		this->if_Can_Use_Deikstra_Algorithm = 0;

	this->all_Weights[0].Push_Value(weight, nomer_of_node, nomer_of_where_directed);
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

	bool if_we_dont_have_names_of_nones = 0;

	if (!this->Names_of_Nodes.size())
	{
		if_we_dont_have_names_of_nones = 1;
		for (int i = 0; i < this->amount_of_Nodes; i++)
			Names_of_Nodes.push_back("");
	}
	int nomer_of_step = 1;
	
	Matrix<unsigned long long int>m = *this->all_Weights.begin();
	
	string for_beauty_showing_of_Nodes, for_beauty_showing_of_Edges;

	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for_beauty_showing_of_Nodes = "||";

		if(i > 9)
			for_beauty_showing_of_Nodes.pop_back();

		cout << "||" << this->Names_of_Nodes[i] << i << for_beauty_showing_of_Nodes;
		for (int e = 0; e < this->amount_of_Nodes; e++)
		{
			for_beauty_showing_of_Edges = "--";
			for_beauty_showing_of_Nodes = "||";

			unsigned long long int weight = m.Get_Value(i, e);

			if (weight > 9)
				for_beauty_showing_of_Edges.pop_back();

			if (e > 9)
				for_beauty_showing_of_Nodes.pop_back();

			if (weight == Max_size_of_unsigned_long_long_int || weight == 0)
				continue;
			else
			{
				cout << " "<<for_beauty_showing_of_Edges << weight << "--> " << "||" << this->Names_of_Nodes[e] << e << for_beauty_showing_of_Nodes;
			}
		}
		cout << endl;
	}
	if (if_we_dont_have_names_of_nones)
	{
		this->Names_of_Nodes.clear();
		this->Names_of_Nodes.reserve(this->amount_of_Nodes);
	}
	
}

void Graph::Canculate_Weights_and_Ways_Between_Nodes_by_Floyd()
{
	for (int i = 1; i < this->amount_of_Nodes; i++)//i=1, because we already have zero matrix
	{
		Matrix<unsigned long long int>matrix_of_weights(this->amount_of_Nodes, this->amount_of_Nodes);
		Matrix<vector<pair<int, int>>>curent_matrix_wayes(this->amount_of_Nodes, this->amount_of_Nodes);

		vector<pair<int, int>> vect_for_ways;
		pair<int, int> pair_of_nodes;

		this->Set_Default_Matrixes(&matrix_of_weights, &curent_matrix_wayes);

		for (int e = 0; e < this->amount_of_Nodes; e++)
		{			
			for (int k = 0; k < this->amount_of_Nodes; k++)
			{
				if (e == k)
					continue; // not sure about this, need to ask teacher

				vect_for_ways.clear();

				unsigned long long int a, b;

				a = this->all_Weights[i - 1].Get_Value(e, i);
				a += this->all_Weights[i - 1].Get_Value(i, k);

				b = this->all_Weights[i - 1].Get_Value(e, k);

				if (a < b)
				{
					matrix_of_weights.Push_Value(a, e, k);

					pair_of_nodes.first = e;
					pair_of_nodes.second = i;

					vect_for_ways.push_back(pair_of_nodes);

					pair_of_nodes.first = i;
					pair_of_nodes.second = k;

					vect_for_ways.push_back(pair_of_nodes);

					curent_matrix_wayes.Push_Value(vect_for_ways, e, k);
				}
				else if (b < Max_size_of_unsigned_long_long_int && a!= b)
				{					
					matrix_of_weights.Push_Value(b, e, k);
					
					pair_of_nodes.first = e;
					pair_of_nodes.second = k;

					vect_for_ways.push_back(pair_of_nodes);
					curent_matrix_wayes.Push_Value(vect_for_ways, e, k);
						
				}
				else
				{
					matrix_of_weights.Push_Value(this->all_Weights[i - 1].Get_Value(e, k), e, k);
					curent_matrix_wayes.Push_Value(this->all_Ways[i - 1].Get_Value(e, k), e, k);
				}
			}
		}

		this->all_Weights.push_back(matrix_of_weights);
		this->all_Ways.push_back(curent_matrix_wayes);
	}
}

void Graph::Show_Result_in_Deikstra_Style()
{
}

void Graph::Show_Result_in_Floyd_Style()
{
	for (int i = 0; i < amount_of_Nodes; i++)
	{
		cout << "Step/Matrix #" << i << endl;

		for (int e = 0; e < this->amount_of_Nodes; e++)
		{
			for (int k = 0; k < this->amount_of_Nodes; k++)
			{
				unsigned long long int a = this->all_Weights[i].Get_Value(e, k);
				if (a >= Max_size_of_unsigned_long_long_int)
					cout << "i";
				else
					cout << a;
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int e = 0; e < this->amount_of_Nodes; e++)
		{
			for (int k = 0; k < this->amount_of_Nodes; k++)
			{
				vector<pair<int, int>> it = this->all_Ways[i].Get_Value(e, k);
				for (int c = 0; c < it.size(); c++)
				{
					int f = it[c].first, s = it[c].second;

					if (it.size() < 2)
						cout << "      ";

					if (f < 0 || s < 0)
						cout << "      ";
					else
						cout <<  "("<< it[c].first << ", " << it[c].second << ")";
				}
				cout << "//";
			}
			cout << endl;
		}
	}
}