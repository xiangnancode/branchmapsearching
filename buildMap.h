#ifndef BUILDMAP_H
#define BUILDMAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <limits>
#include <ctime>
#include <stack>

using namespace std;

class buildMap {
private:
	unordered_map<string, vector< pair<string, double> > > branches;//input, branches and weight of the map
	unordered_map<string, double> my_map;//hash map from state to mapNode
	string loadBranchMap(string);//load the input file to 'branches' and return the initail state
	int amount;
	void branchMapcheck();//also user to check 'branches'. ussage: input 'from' from the command line, print all 'to' and 'weight'
    void showMap();
    //void printResult(double, mapNode*);
    string set2str(set<string> );
    void uniformSize(string&);
public:
    //buildMap();
    void initialize(string);//initialize the map from input file
    void test();


};

#endif