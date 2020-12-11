#include <iostream>
#include "Node_Struct.h"

using namespace std;

Node::Node()
{
	this->Name_of_Node = "";
	this->distance_from_beginning = 9999999999;
	this->already_Canculated_by_Dejkstra_algr = false;
}

void Node::Show_Node(int nomer_of_its_Node)
{
	string frame_for_Node = "||";

	cout << frame_for_Node<< this->Name_of_Node<< nomer_of_its_Node;

	if (nomer_of_its_Node > 9)
		frame_for_Node.pop_back();

	cout << frame_for_Node;

}
