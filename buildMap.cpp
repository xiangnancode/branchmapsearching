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
	set<string> bucket, all;
	while (file.good()) 
	{
	  getline(file, from,',');
	  getline(file, to,',');
	  getline(file, weight,'\n');
	  branches[from].push_back(make_pair(to, stod(weight)));
	  bucket.insert(from);
	  all.insert(from);
	  all.insert(to);
	}
	file.close();
	amount = all.size();
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

void buildMap::showMap() {
	for (auto i : my_map) {
		cout << i.first << ',' << i.second->score << endl;
	}
	cout << "Map size is: " << my_map.size() << endl;
}

void buildMap::initialize(string filename) {
	set<string> bucket;
	bucket = loadBranchMap(filename);//initial state
	//branchMapcheck();
	mapNode* root = new mapNode(bucket, 0);//create new node for initial state
	root->showNode();
	cout << "amount = " << amount << endl;
	queue<mapNode*> BFSorder;
	BFSorder.push(root);//BFS root
	my_map[root->key] = root;//put root into my_map
	while (BFSorder.size() > 0) {
		for (int i = 0; i < BFSorder.size(); ++i) {//for each level
			mapNode* curr = BFSorder.front();//look into this node
			bucket = curr->bucket;//the bucket in this node
			for (auto j : curr->bucket) {//for each element of this bucket
				//cout << j << endl;
				//cout << curr->set2key(bucket) << endl;
				if (branches.find(j) != branches.end()) {//if there are branches start with this element
					bucket.erase(j);//remove one element
					for (int k = 0; k < branches[j].size(); ++k) {//for each branch from this removed element
						//cout << branches[j][k].first << ',' << branches[j][k].second << endl;
						if (bucket.find(branches[j][k].first) == bucket.end()) {//if the destnation is not in bucket
							bucket.insert(branches[j][k].first);//put the destnation in
							if (my_map.find(curr->set2key(bucket)) == my_map.end()) {//if the state is new
								mapNode* newnode = new mapNode(bucket, curr->score + branches[j][k].second);//create new node with new state and score after jump
								my_map[newnode->key] = newnode;//put new node into my_map
								BFSorder.push(newnode);//put the new node in the order
							} else {//if the state already exists
								my_map[curr->set2key(bucket)]->score += branches[j][k].second;//update the score
							}
							//my_map[curr->set2key(bucket)]->showNode();
							bucket.erase(branches[j][k].first);
						}
					}
					bucket.insert(j);//put this element back in for next iteration
				}
				
			}
			BFSorder.pop();//done with this node
		}
	}
	showMap();
}