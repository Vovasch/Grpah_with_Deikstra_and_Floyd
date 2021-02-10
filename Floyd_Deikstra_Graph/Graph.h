#include<utility>
#include<vector>
#include<string>

#include"Node_Struct.h"
#include"Matrix.h"

using namespace std;

#pragma once

class Graph
{
private:

	int amount_of_Nodes;

	vector<Node> nodes;

	//vector<string> Names_of_Nodes;

	//vector< long long int> distances_to_every_Node_from_the_Beginning;

	bool if_Can_Use_Deikstra_Algorithm; // if edge < 0 we can't use Deikstra Algorithm

	Matrix< long long int>*zero_matrix_of_ways;

	vector<Matrix< long long int>>all_Weights;

	vector<Matrix<vector<pair<int, int>>>>all_Ways;

	void Set_Default_Matrix_of_Weights(Matrix< long long int>*weights);
	void Set_Default_matrix_of_Ways(Matrix<vector<pair<int, int>>>* wayes);

	void Show_Matrix_of_Weights(int nomer);
	void Show_Matrix_of_Ways(int nomer);

	void Show_Zero_Matrix();

	void Show_Canculation(int nomer_of_Matrix);// for laboratry task, here we get values form previous matrixes and show how cancluatoin was processed

	void Building_Way_by_Results_From_Floyd_Algrithm(int i, int j, vector<pair<int, int>>* way);

	vector<pair<int, int>> Get_Way_Between_Nodes(int nomer_of_starting_node, int nomer_of_targed_node);

	int Get_Nomer_of_Node_with_the_Smallest_Dist_from_Beging();

	int Get_Nomer_of_Node_by_its_Name(string name);



public:

	Graph(int amount_of_Nodes);
	
	void Add_Node_Name(string name, int nomer_of_Node);

	void Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed); // reloaded functions to be able to add edges and by it's nomer and by it's name
	void Add_Edge(string name, int weight, string name_of_where_directed);

	void Show_Grpah(); 

	void Canculate_Weights_and_Ways_Between_Nodes_by_Floyd();// Floyds algorithm

	void Show_Result_in_Floyd_Style();// for task of my laboratory work

	void Canlulate_by_Dejkstra_algrithm(int nomer_of_starting_node, int nomer_of_targed_node);
	void Canlulate_by_Dejkstra_algrithm(string name_of_starting_node, string name_of_targed_node);

	
	
};