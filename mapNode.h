#ifndef MAPNODE_H
#define MAPNODE_H

#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

class mapNode {
private:
	
    
public:
	set<string> bucket;//indicates the state of a map node
	double score;//indicates the score of this state
	vector< pair<string, double> > log;//state to state log, indicate the path from initial state to current state and the score change
	string key;//key value for hash map<key, mapNode*> to locate this node

    mapNode();//construtor
    mapNode(set<string>, double);//constructor
    string set2key(set<string>);//convert the ordered set to string, each element was separated by ','
    void showNode();//print all information of this node to terminal
};

#endif