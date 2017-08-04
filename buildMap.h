#ifndef BUILDMAP_H
#define BUILDMAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>


using namespace std;

class buildMap {
private:
	unordered_map<string, vector< pair<string, double> > > branches;
	void loadBranchMap(string);
	void branchMapcheck();
    
public:
    //buildMap();

    void initialize(string);
    void test();


};

#endif