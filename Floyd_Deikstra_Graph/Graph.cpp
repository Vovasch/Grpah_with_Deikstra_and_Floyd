 #include "Graph.h"
#include "Matrix.h"
#define Max_size_of_unsigned_long_long_int 18446744073709551

using namespace std;

void Graph::Set_Default_Matrix_of_Weights(Matrix<unsigned long long int>* weights)
{
	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for (int e = 0; e < amount_of_Nodes; e++)
		{
			weights->Push_Value(Max_size_of_unsigned_long_long_int, i, e);
			
			if (i == e)
				weights->Push_Value(0, i, e);
		}
	}
}

void Graph::Set_Default_matrix_of_Ways(Matrix<vector<pair<int, int>>>* wayes)
{
	vector<pair<int, int>> way;
	
	pair<int, int> def_part_of_way;
	
	def_part_of_way.first = def_part_of_way.second = -1;
	
	way.push_back(def_part_of_way);
	
	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for (int e = 0; e < amount_of_Nodes; e++)
		{	
			wayes->Push_Value(way, i, e);
		}
	}
}

void Graph::Show_Matrix_of_Weights(int nomer)
{
	for (int e = 0; e < this->amount_of_Nodes; e++)
	{
		for (int k = 0; k < this->amount_of_Nodes; k++)
		{
			unsigned long long int a = this->all_Weights[nomer].Get_Value(e, k);
			if (a >= Max_size_of_unsigned_long_long_int)
				cout << "  " << "i";
			else
			{
				if (a < 10)
					cout << "  " << a;
				else
					cout << " " << a;
			}

		}
		cout << endl;
	}
	cout << endl;
}

void Graph::Show_Matrix_of_Ways(int nomer)
{
	for (int e = 0; e < this->amount_of_Nodes; e++)
	{
		for (int k = 0; k < this->amount_of_Nodes; k++)
		{
			vector<pair<int, int>> it = this->all_Ways[nomer].Get_Value(e, k);
			for (int c = 0; c < it.size(); c++)
			{
				int f = it[c].first, s = it[c].second;

				if (it.size() < 2)
					cout << "     ";

				if (f < 0 || s < 0)// if(-1,-1) means there is no way to show
					cout << "     ";
				else
					cout << "(" << it[c].first << "," << it[c].second << ")";
			}
			cout << " / ";
		}
		cout << endl;
	}
	cout << endl;
}

void Graph::Show_Zero_Matrix()
{
	for (int e = 0; e < this->amount_of_Nodes; e++)
	{
		for (int k = 0; k < this->amount_of_Nodes; k++)
		{
			unsigned long long int a = this->zero_matrix_of_ways->Get_Value(e, k);
			if (a >= Max_size_of_unsigned_long_long_int)
				cout << "  " << "i";
			else
			{
				if (a < 10)
					cout << "  " << a;
				else
					cout << " " << a;
			}

		}
		cout << endl;
	}
	cout << endl;
}

void Graph::Show_Canculation(int nomer_of_Matrix)
{

	if (nomer_of_Matrix == 0)
	{
		for (int i = 0; i < this->amount_of_Nodes; i++)
		{
			for (int e = 0; e < this->amount_of_Nodes; e++)
			{
				cout <<"1d("<<i<<"," << e << ") = min (0d("<<i<< "," <<nomer_of_Matrix<<") + 0d(" << nomer_of_Matrix <<"," << e <<")"<<", 0d(" << i <<"," << e <<") = "
					<< "min(" << this->zero_matrix_of_ways->Get_Value(i, nomer_of_Matrix) << " + " << this->zero_matrix_of_ways->Get_Value(nomer_of_Matrix, e) << ", " <<
					this->zero_matrix_of_ways->Get_Value(i, e) << ") = " << this->all_Weights[0].Get_Value(i,e) << endl;
			}
			cout << endl;
		}
	}
	else
	{

		for (int i = 0; i < this->amount_of_Nodes; i++)
		{
			for (int e = 0; e < this->amount_of_Nodes; e++)
			{
				cout << nomer_of_Matrix +1  <<"d(" << i << "," << e << ") = min ("<< nomer_of_Matrix<<"d(" << i << "," << nomer_of_Matrix << ") + "<< nomer_of_Matrix<< "d(" << nomer_of_Matrix << "," << e << ")" << ", " << nomer_of_Matrix<< "d(" << i << "," << e << ") = "
					<< "min(" << this->all_Weights[nomer_of_Matrix - 1].Get_Value(i, nomer_of_Matrix) << " + " << this->all_Weights[nomer_of_Matrix - 1].Get_Value(nomer_of_Matrix, e) << ", " <<
					this->all_Weights[nomer_of_Matrix - 1].Get_Value(i, e) << ") = " << this->all_Weights[nomer_of_Matrix].Get_Value(i,e)<< endl;
			}
			cout << endl;
		}
	}
}

Graph::Graph(int amount_of_Nodes)
{
	this->Names_of_Nodes.reserve(amount_of_Nodes);
	
	this->if_Can_Use_Deikstra_Algorithm = 1;

	this->amount_of_Nodes = amount_of_Nodes;

	this->zero_matrix_of_ways = new Matrix<unsigned long long int>(amount_of_Nodes, amount_of_Nodes);

	this->Set_Default_Matrix_of_Weights(this->zero_matrix_of_ways);
	
}

void Graph::Add_Node_Name(string name)
{
	this->Names_of_Nodes.push_back(name);
}

void Graph::Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed)
{
	if (weight < 0)
		this->if_Can_Use_Deikstra_Algorithm = 0;

	this->zero_matrix_of_ways->Push_Value(weight, nomer_of_node, nomer_of_where_directed);
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
	
	Matrix<unsigned long long int>m = *this->zero_matrix_of_ways;
	
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
	Matrix<unsigned long long int>matrix_of_weights(this->amount_of_Nodes, this->amount_of_Nodes);
	Matrix<vector<pair<int, int>>>curent_matrix_wayes(this->amount_of_Nodes, this->amount_of_Nodes);

	this->Set_Default_Matrix_of_Weights(&matrix_of_weights);
	this->Set_Default_matrix_of_Ways(&curent_matrix_wayes);
	vector<pair<int, int>> vect_for_ways;
	pair<int, int> pair_of_nodes;

	matrix_of_weights = *this->zero_matrix_of_ways;

	for (int i = 0; i < this->amount_of_Nodes; i++)
	{
		for (int j = 0; j < this->amount_of_Nodes; j++)
		{
			if (i == j)
				continue;

			vect_for_ways.clear();

			unsigned long long int sum, prev;
			sum = matrix_of_weights.Get_Value(i, 0);
			sum += matrix_of_weights.Get_Value(0, j);

			prev = matrix_of_weights.Get_Value(i, j);

			if (sum < prev)
			{
				matrix_of_weights.Push_Value(sum, i, j);
				pair_of_nodes.first = i;
				pair_of_nodes.second = 0;

				vect_for_ways.push_back(pair_of_nodes);

				pair_of_nodes.first = 0;
				pair_of_nodes.second = j;

				vect_for_ways.push_back(pair_of_nodes);

				curent_matrix_wayes.Push_Value(vect_for_ways, i, j);
			}
			else if(prev < Max_size_of_unsigned_long_long_int)
			{
				pair_of_nodes.first = i;
				pair_of_nodes.second = j;

				vect_for_ways.push_back(pair_of_nodes);

				curent_matrix_wayes.Push_Value(vect_for_ways, i, j);
			}
		}
	}

	this->all_Weights.push_back(matrix_of_weights);
	this->all_Ways.push_back(curent_matrix_wayes);

	for (int n = 1; n < this->amount_of_Nodes; n++)
	{
		matrix_of_weights = *this->all_Weights.rbegin();
		curent_matrix_wayes = *this->all_Ways.rbegin();

		for (int i = 0; i < this->amount_of_Nodes; i++)
		{
			for (int j = 0; j < this->amount_of_Nodes; j++)
			{
				vect_for_ways.clear();

				unsigned long long int sum, prev;
				sum = matrix_of_weights.Get_Value(i, n);
				sum += matrix_of_weights.Get_Value(n, j);

				prev = matrix_of_weights.Get_Value(i, j);

				if (sum < prev)
				{
					matrix_of_weights.Push_Value(sum, i, j);
					pair_of_nodes.first = i;
					pair_of_nodes.second = n;

					vect_for_ways.push_back(pair_of_nodes);

					pair_of_nodes.first = n;
					pair_of_nodes.second = j;

					vect_for_ways.push_back(pair_of_nodes);

					curent_matrix_wayes.Push_Value(vect_for_ways, i, j);
				}
			}
		}

		this->all_Weights.push_back(matrix_of_weights);
		this->all_Ways.push_back(curent_matrix_wayes);
	}
}

void Graph::Show_Way_Between_Nodes(int nomer_of_starting_node, int nomer_of_targed_node)
{
	vector<int> way_we_are_building;


	auto curent_way = all_Ways.rbegin()->Get_Value(nomer_of_starting_node, nomer_of_targed_node);

	for (auto it = curent_way.rbegin(); it != curent_way.rend(); ++it) 
	{
		way_we_are_building.push_back(it->second);
	}

	way_we_are_building.push_back(nomer_of_starting_node);

	for (auto it = way_we_are_building.rbegin(); it != way_we_are_building.rend(); ++it)
	{
		cout << *it << " ";
	}
}

void Graph::Show_Way_Between_Nodes(string nomer_of_starting_node, string nomer_of_targed_node)
{
	vector<string>::iterator it1 = find(this->Names_of_Nodes.begin(), this->Names_of_Nodes.end(), nomer_of_starting_node);

	vector<string>::iterator it2 = find(this->Names_of_Nodes.begin(), this->Names_of_Nodes.end(), nomer_of_targed_node);

	int a, b;
	a = distance(this->Names_of_Nodes.begin(), it1);
	b = distance(this->Names_of_Nodes.begin(), it2);

	this->Show_Way_Between_Nodes(a, b);
}

void Graph::Show_Result_in_Floyd_Style()
{
	cout << "Staring matrix" << endl;

	this->Show_Zero_Matrix();

	for (int i = 0; i < amount_of_Nodes; i++)
	{
		cout << "Step " << i+1 << endl;
		this->Show_Canculation(i);

		cout << "Matrix of weights " << i + 1 << endl;
		this->Show_Matrix_of_Weights(i);

		cout << "Matrix of ways " << i + 1 << endl;
		this->Show_Matrix_of_Ways(i);
	}
}