 #include "Graph.h"
#include "Matrix.h"

#define A_Big_Number 99999999

using namespace std;

void Graph::Set_Default_Matrix_of_Weights(Matrix< long long int>* weights)
{
	for (int i = 0; i < amount_of_Nodes; i++)
	{
		for (int e = 0; e < amount_of_Nodes; e++)
		{
			weights->Push_Value(A_Big_Number, i, e);
			
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
			 long long int a = this->all_Weights[nomer].Get_Value(e, k);
			if (a >= A_Big_Number)
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
					cout << "(" << it[c].first + 1 << "," << it[c].second + 1 << ")";
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
			 long long int a = this->zero_matrix_of_ways->Get_Value(e, k);
			if (a >= A_Big_Number)
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
				cout << "1d(" << i + 1 << "," << e + 1 << ") = min (0d(" << i + 1 << "," << nomer_of_Matrix + 1 << ") + 0d(" << nomer_of_Matrix + 1 << "," << e + 1 << ")" <<
					", 0d(" << i + 1 << "," << e + 1 << ") = "
					<< "min(" << this->zero_matrix_of_ways->Get_Value(i, nomer_of_Matrix) << " + " << this->zero_matrix_of_ways->Get_Value(nomer_of_Matrix, e) << ", " <<
					this->zero_matrix_of_ways->Get_Value(i, e) << ") = " << this->all_Weights[0].Get_Value(i, e) << " / ";
					
				for (auto it : this->all_Ways[nomer_of_Matrix].Get_Value(i, e))
				{
					int first, second;
					first = it.first;
					second = it.second;

					if (first < 0 || second < 0)
						continue;
					
					cout << "(" << first+1 << ", " << second+1 << ") ";
				}


				cout << endl;
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
				cout << nomer_of_Matrix +1<<"d(" << i+1 << "," << e+1 << ") = min ("<< nomer_of_Matrix<<"d(" << i+1 << "," << nomer_of_Matrix+1 << ") + "<< nomer_of_Matrix<< "d(" << nomer_of_Matrix+1 << "," << e+1 << ")" 
					<< ", " << nomer_of_Matrix<< "d(" << i+1 << "," << e+1 << ") = "
					<< "min(" << this->all_Weights[nomer_of_Matrix - 1].Get_Value(i, nomer_of_Matrix) << " + " << this->all_Weights[nomer_of_Matrix - 1].Get_Value(nomer_of_Matrix, e) << ", " <<
					this->all_Weights[nomer_of_Matrix - 1].Get_Value(i, e) << ") = " << this->all_Weights[nomer_of_Matrix].Get_Value(i,e)<< " // ";

				for (auto it : this->all_Ways[nomer_of_Matrix].Get_Value(i, e))
				{
					int first, second;
					first = it.first;
					second = it.second;

					if (first < 0 || second < 0)
						continue;

					cout << "(" << first + 1 << ", " << second + 1 << ") ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}
}

void Graph::Building_Way_by_Results_From_Floyd_Algrithm(int i, int j, vector<pair<int, int>>* way)
{
	if (this->all_Ways.rbegin()->Get_Value(i, j).size() > 1)
	{
		for (auto i : this->all_Ways.rbegin()->Get_Value(i, j))
		{
			this->Building_Way_by_Results_From_Floyd_Algrithm(i.first, i.second, way);
		}
	}
	else
	{
		way->push_back(*all_Ways.rbegin()->Get_Value(i, j).begin());
	}
}

vector<pair<int, int>> Graph::Get_Way_Between_Nodes(int nomer_of_starting_node, int nomer_of_targed_node)
{
	vector<pair<int, int>> way_we_are_building;

	pair<int, int> starting_node;

	starting_node.first = -1;
	starting_node.second = nomer_of_starting_node;

	way_we_are_building.push_back(starting_node);

	this->Building_Way_by_Results_From_Floyd_Algrithm(nomer_of_starting_node, nomer_of_targed_node, &way_we_are_building);

	return way_we_are_building;
}

int Graph::Get_Nomer_of_Node_with_the_Smallest_Dist_from_Beging()
{
	int the_smallest_dist = 9999999993483999999;

	vector<Node>::iterator node;

	for (auto it = this->nodes.begin(); it != this->nodes.end(); ++it)
	{
		if (the_smallest_dist > it->distance_from_beginning)
		{
			if (it->already_Canculated_by_Dejkstra_algr)
				continue;
			the_smallest_dist = it->distance_from_beginning;
			node = it;
		}
	}


	return distance(this->nodes.begin(), node);
}

void Graph::Canlulate_by_Dejkstra_algrithm(int nomer_of_starting_node, int nomer_of_targed_node)
{

	this->nodes[nomer_of_starting_node].distance_from_beginning = 0;



	int nomer_of_Node_We_are_Working_With = this->Get_Nomer_of_Node_with_the_Smallest_Dist_from_Beging();

	while (nomer_of_Node_We_are_Working_With != -1)
	{
		if (nomer_of_Node_We_are_Working_With == nomer_of_targed_node)
			break;

		int a = nodes[nomer_of_Node_We_are_Working_With].distance_from_beginning;

		cout << endl;
		this->nodes[nomer_of_Node_We_are_Working_With].Show_Node(nomer_of_Node_We_are_Working_With);
		cout << endl << endl;

		

		for (int i = 0; i < amount_of_Nodes; i++)
		{

			int b = this->zero_matrix_of_ways->Get_Value(nomer_of_Node_We_are_Working_With, i);

			if (b >= A_Big_Number || i == nomer_of_Node_We_are_Working_With)
				continue;

			cout << "d(" << nodes[i].Name_of_Node << ") = min (d(" << nodes[i].Name_of_Node << "), (d(" << nodes[nomer_of_Node_We_are_Working_With].Name_of_Node << " + a(" <<
				nodes[nomer_of_Node_We_are_Working_With].Name_of_Node << ", " << nodes[i].Name_of_Node << ") = ";

			cout << "Min(" << b << " + " << a << ", ";

			b += a;
			int c = this->nodes[i].distance_from_beginning;

			cout << c << ") = ";

			if (b < c)
			{
				this->nodes[i].distance_from_beginning = b;
				this->nodes[i].nomer_of_Previous_Node = nomer_of_Node_We_are_Working_With;
				cout << b;
			}
			else
				cout << c;

			cout << endl;


		}
		this->nodes[nomer_of_Node_We_are_Working_With].already_Canculated_by_Dejkstra_algr = 1;

		nomer_of_Node_We_are_Working_With = this->Get_Nomer_of_Node_with_the_Smallest_Dist_from_Beging();
	}
	vector<Node>way;

	int nomer_that_we_is_previous = nomer_of_targed_node;

	while (nomer_that_we_is_previous != nomer_of_starting_node)
	{
		way.push_back(nodes[nomer_that_we_is_previous]);
		nomer_that_we_is_previous = nodes[nomer_that_we_is_previous].nomer_of_Previous_Node;
	}

	way.push_back(nodes[nomer_of_starting_node]);

	for (auto it = way.rbegin(); it != way.rend(); ++it)
	{
		cout << it->Name_of_Node << " ";
	}
}
void Graph::Canlulate_by_Dejkstra_algrithm(string name_of_starting_node, string name_of_targed_node)
{
	Canlulate_by_Dejkstra_algrithm(this->Get_Nomer_of_Node_by_its_Name(name_of_starting_node), this->Get_Nomer_of_Node_by_its_Name(name_of_targed_node));
}

int Graph::Get_Nomer_of_Node_by_its_Name(string name)
{

	//for (auto i : this->nodes)
	for(auto i = this->nodes.begin(); i != this->nodes.end(); ++i)
	{
		if (i->Name_of_Node == name)
			return distance(this->nodes.begin(), i);
	}

	return 0;
}


Graph::Graph(int amount_of_Nodes)
{
	this->amount_of_Nodes = amount_of_Nodes;
	
	this->nodes.reserve(amount_of_Nodes);

	Node node;

	this->nodes.insert(this->nodes.begin(),amount_of_Nodes, node);
	
	this->if_Can_Use_Deikstra_Algorithm = 1;

	this->zero_matrix_of_ways = new Matrix< long long int>(amount_of_Nodes, amount_of_Nodes);

	this->Set_Default_Matrix_of_Weights(this->zero_matrix_of_ways);
	
}

void Graph::Add_Node_Name(string name, int nomer_of_Node)
{
	this->nodes[nomer_of_Node].Name_of_Node = name;
}

void Graph::Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed)
{
	if (weight < 0)
		this->if_Can_Use_Deikstra_Algorithm = 0;

	this->zero_matrix_of_ways->Push_Value(weight, nomer_of_node, nomer_of_where_directed);
}

void Graph::Add_Edge(string name, int weight, string name_of_where_directed)
{
	this->Add_Edge(this->Get_Nomer_of_Node_by_its_Name(name), weight, this->Get_Nomer_of_Node_by_its_Name(name_of_where_directed));
}

void Graph::Show_Grpah()
{
	int nomer_of_step = 1;
	
	Matrix< long long int>m = *this->zero_matrix_of_ways;
	
	string for_beauty_showing_of_Edges;

	for (int i = 0; i < amount_of_Nodes; i++)
	{
		this->nodes[i].Show_Node(i);

		for (int e = 0; e < this->amount_of_Nodes; e++)
		{
			for_beauty_showing_of_Edges = "--";

			 long long int weight = m.Get_Value(i, e);

			if (weight > 9)								//--9-->                        --9-->
				for_beauty_showing_of_Edges.pop_back(); //--10--> not beautiful so we take away one '-' -10-->


			if (weight == A_Big_Number || weight == 0)
				continue;
			else
			{
				cout << " " << for_beauty_showing_of_Edges << "|"<<weight << "|--> "; 
																						
				this->nodes[i].Show_Node(i);
			}
		}
		cout << endl;
	}
	
	
}

void Graph::Canculate_Weights_and_Ways_Between_Nodes_by_Floyd()
{
	Matrix< long long int>matrix_of_weights(this->amount_of_Nodes, this->amount_of_Nodes);
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

			 long long int sum, prev;
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
			else if(prev < A_Big_Number )
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

				long long int sum, prev;
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

