#include<iostream>
#include<utility>
#include<string>
#include <sstream> 

#include"Graph.h"

using namespace std;

void Init_Graph_for_test_from_presentation(Graph* test);

void Init_Names_of_Node_for_Grahp_from_3_lab(Graph* Deikstri_Grahp);

void Graph_for_Lab_3_withtout_entering_form_UI(Graph* Deikstri_Grahp);

void Graph_for_Lab_3_WITH_enterieng_from_UI(Graph* Deikstri_Grahp, bool straight_of_reserved);

void Graph_for_Lab_4_without_entering_form_UI(Graph* Floyd_Graph);

void Graph_for_Lab_4_with_enterieng_from_UI(Graph* Floyd_Graph);

int main()
{
	string Node1, Node2;

	Graph* test = new Graph(4);

	Graph *Deikstri_Grahp = new Graph(12);

	Graph* Floyd_Graph = new Graph(5);
	
	bool straight_or_Reversed_Graph_for_3th_Lab;

	int Deikstri_or_Floyd;

	cout << "|||||||||||WELCOME|||||||||||\n" <<
		"1) Deikstri(3 Lab)\n \tor\n2)Floyd(4 Lab)\n" <<
		"Enter your choise (1 or 2) ";

	cin >> Deikstri_or_Floyd;

	switch(Deikstri_or_Floyd)
	{
	case 0:

		//here is grpah from presentation
		//i tested if my algorithm working correctly

		Init_Graph_for_test_from_presentation(test);
		
		test->Show_Grpah();

		test->Canculate_Weights_and_Ways_Between_Nodes_by_Floyd();
		test->Show_Result_in_Floyd_Style();

		break;

	case 1:

		Init_Names_of_Node_for_Grahp_from_3_lab(Deikstri_Grahp);

		//Graph_for_Lab_3_withtout_entering_form_UI(Deikstri_Grahp);


		cout << "Straight or reversed?" << endl << "Enter 1 or 0 ";

		cin >> straight_or_Reversed_Graph_for_3th_Lab;

		Graph_for_Lab_3_WITH_enterieng_from_UI(Deikstri_Grahp, straight_or_Reversed_Graph_for_3th_Lab);

		cout << "This is your graph" << endl;

		Deikstri_Grahp->Show_Grpah();

		Deikstri_Grahp->Canculate_Weights_and_Ways_Between_Nodes_by_Floyd();

		cout << "Enter names of nodes, way between which need to be canculated" << endl;

		cin >> Node1 >> Node2;

		//Deikstri_Grahp->Show_Result_in_Floyd_Style();

		break;
	
	case 2:
	
		//Graph_for_Lab_4_without_entering_form_UI(Floyd_Graph);

		Graph_for_Lab_4_with_enterieng_from_UI(Floyd_Graph);

		Floyd_Graph->Show_Grpah();

		Floyd_Graph->Canculate_Weights_and_Ways_Between_Nodes_by_Floyd();

		Floyd_Graph->Show_Result_in_Floyd_Style();
		
		break;
	}

	system("Pause");
	return 0;
}

void Init_Graph_for_test_from_presentation(Graph* test)
{
	test->Add_Edge(0, 1, 1);
	test->Add_Edge(1, 7, 2);
	test->Add_Edge(2, 2, 3);
	test->Add_Edge(3, 1, 0);
	test->Add_Edge(0, 2, 2);
	test->Add_Edge(2, 6, 0);
	test->Add_Edge(0, 1, 3);
	test->Add_Edge(3, 4, 2);
	test->Add_Edge(2, 5, 1);
	test->Add_Edge(1, 2, 0);
}

void Init_Names_of_Node_for_Grahp_from_3_lab(Graph* Deikstri_Grahp)
{
	Deikstri_Grahp->Add_Node_Name("A", 0);
	Deikstri_Grahp->Add_Node_Name("F", 1);
	Deikstri_Grahp->Add_Node_Name("H", 2);
	Deikstri_Grahp->Add_Node_Name("B", 3);

	Deikstri_Grahp->Add_Node_Name("Z", 4);
	Deikstri_Grahp->Add_Node_Name("L", 5);
	Deikstri_Grahp->Add_Node_Name("M", 6);
	Deikstri_Grahp->Add_Node_Name("K", 7);

	Deikstri_Grahp->Add_Node_Name("D", 8);
	Deikstri_Grahp->Add_Node_Name("J", 9);
	Deikstri_Grahp->Add_Node_Name("I", 10);
	Deikstri_Grahp->Add_Node_Name("E", 11);
}

void Graph_for_Lab_3_withtout_entering_form_UI(Graph* Deikstri_Grahp)
{

	//straight graph
	Deikstri_Grahp->Add_Edge("A", 13, "F");
	Deikstri_Grahp->Add_Edge("F", 14, "H");
	Deikstri_Grahp->Add_Edge("H", 4, "B");
	Deikstri_Grahp->Add_Edge("A", 10, "Z");
	Deikstri_Grahp->Add_Edge("A", 9, "L");
	Deikstri_Grahp->Add_Edge("F", 13, "L");
	Deikstri_Grahp->Add_Edge("H", 1, "M");
	Deikstri_Grahp->Add_Edge("B", 19, "M");
	Deikstri_Grahp->Add_Edge("B", 19, "K");
	Deikstri_Grahp->Add_Edge("Z", 13, "L");
	Deikstri_Grahp->Add_Edge("L", 5, "M");
	Deikstri_Grahp->Add_Edge("M", 18, "K");
	Deikstri_Grahp->Add_Edge("Z", 5, "D");
	Deikstri_Grahp->Add_Edge("L", 16, "D");
	Deikstri_Grahp->Add_Edge("L", 4, "J");
	Deikstri_Grahp->Add_Edge("M", 13, "I");
	Deikstri_Grahp->Add_Edge("M", 1, "E");
	Deikstri_Grahp->Add_Edge("K", 5, "E");
	Deikstri_Grahp->Add_Edge("D", 13, "J");
	Deikstri_Grahp->Add_Edge("J", 9, "I");
	Deikstri_Grahp->Add_Edge("I", 12, "E");

	//reversed graph
	Deikstri_Grahp->Add_Edge("F", 12, "A");
	Deikstri_Grahp->Add_Edge("H", 10, "F");
	Deikstri_Grahp->Add_Edge("B", 18, "H");
	Deikstri_Grahp->Add_Edge("Z", 19, "A");
	Deikstri_Grahp->Add_Edge("L", 12, "A");
	Deikstri_Grahp->Add_Edge("L", 9, "F");
	Deikstri_Grahp->Add_Edge("M", 16, "H");
	Deikstri_Grahp->Add_Edge("M", 12, "B");
	Deikstri_Grahp->Add_Edge("K", 3, "B");
	Deikstri_Grahp->Add_Edge("L", 10, "Z");
	Deikstri_Grahp->Add_Edge("M", 10, "L");
	Deikstri_Grahp->Add_Edge("K", 13, "M");
	Deikstri_Grahp->Add_Edge("D", 3, "Z");
	Deikstri_Grahp->Add_Edge("D", 1, "L");
	Deikstri_Grahp->Add_Edge("J", 13, "L");
	Deikstri_Grahp->Add_Edge("I", 17, "M");
	Deikstri_Grahp->Add_Edge("E", 12, "M");
	Deikstri_Grahp->Add_Edge("E", 7, "K");
	Deikstri_Grahp->Add_Edge("J", 15, "D");
	Deikstri_Grahp->Add_Edge("I", 14, "J");
	Deikstri_Grahp->Add_Edge("E", 6, "I");	
}

void Graph_for_Lab_3_WITH_enterieng_from_UI(Graph* Deikstri_Grahp, bool straight_of_reserved)
{
	cout << "All nodes have already been downloaded into program,\n" <<
		"all edges have already been directed\n" <<
		"You only need to enter theirs values of weights\n" <<
		"So we have 21 adges, you need to enter every of them just from task,\n" <<
		"clicking 'Enter' after every" << endl;

	vector<pair<string, string>> pair_of_nodes = { {"A", "F"}, {"F", "H"},{"H","B"},{"A","Z"},{"A","L"},{"F","L"},{"H","M"},{"B","M"},{"B", "K"},{"Z","L"},{"L","M"},{"M","K"},{"Z","D"},{"L","D"},{"L","J"},{"M","I"},{"M","E"},{"K","E"},{"D","J"},{"J","I"},{"I","E"} };

	int value;

	
	if (straight_of_reserved)
	{
		for (auto i : pair_of_nodes)
		{
			cin >> value;

			Deikstri_Grahp->Add_Edge(i.first, value, i.second);

		}
	}
	else
	{
		for (auto i : pair_of_nodes)
		{
			cin >> value;

			Deikstri_Grahp->Add_Edge(i.second, value, i.first);
		}
	}
}

void Graph_for_Lab_4_without_entering_form_UI(Graph* Floyd_Graph)
{
	Floyd_Graph->Add_Edge(0, 1, 1);
	Floyd_Graph->Add_Edge(1, 4, 0);
	Floyd_Graph->Add_Edge(1, 2, 2);
	Floyd_Graph->Add_Edge(2, 1, 1);
	Floyd_Graph->Add_Edge(2, 8, 0);
	Floyd_Graph->Add_Edge(0, 8, 2);
	Floyd_Graph->Add_Edge(3, 4, 0);
	Floyd_Graph->Add_Edge(0, 1, 3);
	Floyd_Graph->Add_Edge(4, 2, 3);
	Floyd_Graph->Add_Edge(3, 6, 4);
	Floyd_Graph->Add_Edge(1, 6, 4);
	Floyd_Graph->Add_Edge(4, 8, 1);
	Floyd_Graph->Add_Edge(2, 2, 4);
	Floyd_Graph->Add_Edge(4, 5, 2);
}

void Graph_for_Lab_4_with_enterieng_from_UI(Graph* Floyd_Graph)
{
	cout << "Enter value of every node clicking 'Enter' after every, " << endl <<
		"if you have '*' enter '*'" << endl << endl;

	vector<string> weights;

	int amount_of_adges = 14;

	string weight;

	for (int i = 0; i < amount_of_adges; i++)
	{

		cout << "Enter edge # " << i + 1 << " ";
		cin >> weight;
		weights.push_back(weight);
	}

	vector<pair<int, int>> nodes{ {0,1},{1,0},{1,2}, {2,1},{2,0},{0,2},{3,0},{0,3},{4,3},{3,4},{1,4},{4,1},{2,4},{4,2} };

	for (int i = 0; i < amount_of_adges; i++)
	{
		if (weights[i] == "*")
			continue;

		stringstream num(weights[i]);

		int x = 0;
		num >> x;

		Floyd_Graph->Add_Edge(nodes[i].first, x, nodes[i].second);
	}
}
