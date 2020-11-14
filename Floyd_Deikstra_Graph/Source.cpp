#include<iostream>
#include<utility>
#include<string>

#include"Graph.h"

using namespace std;


int main()
{
	Graph *Deikstri_Grahp = new Graph(12);


	Deikstri_Grahp->Add_Node_Name("A");
	Deikstri_Grahp->Add_Node_Name("F");
	Deikstri_Grahp->Add_Node_Name("H");
	Deikstri_Grahp->Add_Node_Name("B");

	Deikstri_Grahp->Add_Node_Name("Z");
	Deikstri_Grahp->Add_Node_Name("L");
	Deikstri_Grahp->Add_Node_Name("M");
	Deikstri_Grahp->Add_Node_Name("K");

	Deikstri_Grahp->Add_Node_Name("D");
	Deikstri_Grahp->Add_Node_Name("J");
	Deikstri_Grahp->Add_Node_Name("I");
	Deikstri_Grahp->Add_Node_Name("E");

	int Deikstri_or_Floyd;
	string all_wights;
	int amount_of_adges = 21;

	cout << "|||||||||||WELCOME|||||||||||\n" <<
		"1) Deikstri(3 Lab)\n \tor\n2)Floyd(4 Lab)\n" <<
		"Enter your choise (1 or 2) ";

	cin >> Deikstri_or_Floyd;

	if (Deikstri_or_Floyd == 1)
	{
		cout << "All nodes have already been downloaded into program,\n" <<
			"all edges have already been directed\n" <<
			"You only need to enter theirs values of weights\n" <<
			"So we have 21 adges, you need to enter every of them just from task,\n"<<
			"clicking 'Enter' after every";

		int value;
		
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("A", value, "F");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("F", value, "H");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("H", value, "B");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("A", value, "Z");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("A", value, "L");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("F", value, "L");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("H", value, "M");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("M", value, "B");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("B", value, "K");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("Z", value, "L");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("L", value, "M");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("M", value, "K");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("Z", value, "D");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("D", value, "L");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("L", value, "J");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("M", value, "I");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("M", value, "E");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("K", value, "E");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("D", value, "J");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("J", value, "I");
		cin >> value; cout << " ";
		Deikstri_Grahp->Add_Edge("I", value, "E");
		
		system("cls");

		cout << "This is your graph" << endl;

		Deikstri_Grahp->Show_Grpah_in_List_Style();

	}
	else if (Deikstri_or_Floyd == 2)
	{

	}


	system("Pause");
	return 0;
}
