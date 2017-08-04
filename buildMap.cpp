#include "buildMap.h"
#include "mapNode.h"



void buildMap::test() {
	cout << "print from buildMap test" << endl;
	set<string> bucket;
	mapNode x(bucket, 5.23);
	cout << x.score << endl;
}

void buildMap::loadBranchMap(string filename) {
	cout << "file name is: " << filename << endl;
	cout << "loading..." << endl;
	ifstream file;
	file.open(filename);
	string from, to, weight;
	while (file.good()) 
	{
	  getline(file, from,',');
	  getline(file, to,',');
	  getline(file, weight,'\n');
	  branches[from].push_back(make_pair(to, stod(weight)));
	}
	file.close();
}

void buildMap::branchMapcheck() {
	string input;
	while (input != "Q") {
		cin >> input;
		for (int i = 0; i < branches[input].size(); ++i) {
			cout << input << ", " << branches[input][i].first << ", " << branches[input][i].second << endl;
		}
	}
}

void buildMap::initialize(string filename) {
	loadBranchMap(filename);
	branchMapcheck();
}