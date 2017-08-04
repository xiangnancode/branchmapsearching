#ifndef MAPNODE_H
#define MAPNODE_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class mapNode {
private:
    
public:
	set<string> bucket;
	double score;
	vector< pair<string, double> > log;

    mapNode();
    mapNode(set<string>, double);
};

#endif