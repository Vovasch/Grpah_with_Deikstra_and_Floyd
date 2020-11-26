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

	Matrix<unsigned long long int>*zero_matrix_of_ways;

	vector<Matrix<unsigned long long int>>all_Weights;

	vector<Matrix<vector<pair<int, int>>>>all_Ways;

	void Set_Default_Matrix_of_Weights(Matrix<unsigned long long int>*weights);
	void Set_Default_matrix_of_Ways(Matrix<vector<pair<int, int>>>* wayes);

	void Show_Matrix_of_Weights(int nomer);
	void Show_Matrix_of_Ways(int nomer);

	void Show_Zero_Matrix();

	void Show_Canculation(int nomer_of_Matrix);

public:

	Graph(int amount_of_Nodes);
	

	void Add_Node_Name(string name);

	void Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed);
	void Add_Edge(string name, int weight, string name_of_where_directed);

	void Show_Grpah_in_List_Style();

	void Canculate_Weights_and_Ways_Between_Nodes_by_Floyd();

	void Show_Way_Between_Nodes(int nomer_of_starting_node, int nomer_of_targed_node);
	void Show_Way_Between_Nodes(string nomer_of_starting_node, string nomer_of_targed_node);

	void Show_Result_in_Floyd_Style();
};