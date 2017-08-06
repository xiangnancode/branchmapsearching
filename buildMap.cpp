#include "buildMap.h"

void buildMap::test() {
	cout << "print from buildMap test" << endl;
	set<string> bucket;
	mapNode x(bucket, 5.23);
	cout << x.score << endl;
}

set<string> buildMap::loadBranchMap(string filename) {
	cout << "file name is: " << filename << endl;
	cout << "loading..." << endl;
	ifstream file;
	file.open(filename);
	string from, to, weight;
	set<string> bucket;
	while (file.good()) 
	{
	  getline(file, from,',');
	  getline(file, to,',');
	  getline(file, weight,'\n');
	  branches[from].push_back(make_pair(to, stod(weight)));
	  bucket.insert(from);
	}
	file.close();
	return bucket;
}

void buildMap::branchMapcheck() {
	string input;
	while (input != "Q") {
		cin >> input;
		for (auto i = 0; i < branches[input].size(); ++i) {
			cout << input << ", " << branches[input][i].first << ", " << branches[input][i].second << endl;
		}
	}
}

void buildMap::initialize(string filename) {
	set<string> bucket;
	bucket = loadBranchMap(filename);
	branchMapcheck();
	mapNode* root = new mapNode(bucket, 0.123);
	root->showNode();
	queue<mapNode*> BFSorder;
	BFSorder.push(root);
	//while (BFSorder.size() > 0) {

	//}
}