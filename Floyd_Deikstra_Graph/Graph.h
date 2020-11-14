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

	vector<Matrix<vector<pair<int, int>>>>wayes;

	void Set_Default_Matrixes(Matrix<unsigned long long int>*weights, Matrix<vector<pair<int, int>>>*wayes);

public:

	Graph(int amount_of_Nodes);

	void Add_Node_Name(string name);

	void Add_Edge(int nomer_of_node, int weight, int nomer_of_where_directed);

	void Add_Edge(string name, int weight, string name_of_where_directed);

	void Show_Grpah_in_List_Style();

	void Canculate_Weights_and_Ways_Between_Nodes();

	void Show_Result_in_Deikstra_Style();

	void Show_Result_in_Floyd_Style();



};