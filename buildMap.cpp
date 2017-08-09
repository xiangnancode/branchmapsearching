#include "buildMap.h"

string buildMap::set2key(set<string> aSet) {
	string strset;//string tpye of the ordered set
	for(auto i : aSet) {//for all elements in the set
		if (strset.size() == 0) {//first element
			strset = i;
		} else {//rest of the elements
			strset += "," + i;
		}
		
	}
	return strset;
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
	/*
	for (auto i : my_map) {
		cout << i.first << ',' << i.second->score << endl;
	}
	*/
	cout << "Map size is: " << my_map.size() << endl;
}
/*
void buildMap::printResult(double maxscore, mapNode* maxstate) {
	ofstream file;
	file.open("./output/result.txt");
	string entry;
	entry = "maxscore is: " + to_string(maxscore);
	file << entry << endl;
	cout << entry << endl;
	entry = "maxstate is: " + maxstate->key;
	file << entry;
	cout << entry << endl;
	file.close();
	file.open("./output/logbook.csv");
	cout << "logbook: " << endl;
	for (int i = 0; i < maxstate->logbook.size(); ++i) {
		cout << maxstate->logbook[i] << endl;
		file << maxstate->logbook[i] + '\n';
	}
	file.close();
}
*/
void buildMap::initialize(string filename) {
	//for run time calculation
	clock_t t;
	t = clock();
	//
	set<string> bucket;
	bucket = loadBranchMap(filename);//initial state
	//branchMapcheck();
	//DFS




	//BFS
	/*
	mapNode* root = new mapNode(bucket, 0);//create new node for initial state
	root->showNode();
	cout << "amount = " << amount << endl;
	queue<mapNode*> BFSorder;
	BFSorder.push(root);//BFS root
	my_map[root->key] = root;//put root into my_map
	mapNode* maxstate;
	double maxscore = -10;
	int level = 0, mapsize = 1;
	while (BFSorder.size() > 0) {
		cout << "level " << level++ << endl;
		for (int i = 0; i < BFSorder.size(); ++i) {//for each level
			//cout << "Searching node #" << mapsize++ << endl;
			mapNode* curr = BFSorder.front();//look into this node
			bucket = curr->bucket;//the bucket in this node
			for (auto j : curr->bucket) {//for each element of this bucket
				//cout << j << endl;
				//cout << set2key(bucket) << endl;
				if (branches.find(j) != branches.end()) {//if there are branches start with this element
					bucket.erase(j);//remove one element
					for (int k = 0; k < branches[j].size(); ++k) {//for each branch from this removed element
						//cout << branches[j][k].first << ',' << branches[j][k].second << endl;
						if (bucket.find(branches[j][k].first) == bucket.end()) {//if the destnation is not in bucket
							bucket.insert(branches[j][k].first);//put the destnation in
							double newscore = curr->score + branches[j][k].second;
							string newlog = j + "," + branches[j][k].first + "," + to_string(branches[j][k].second) + "," + to_string(newscore);
							if (my_map.find(set2key(bucket)) == my_map.end()) {//if the state is new
								mapNode* newnode = new mapNode(bucket, newscore);//create new node with new state and score after jump
								my_map[newnode->key] = newnode;//put new node into my_map
								newnode->logbook = curr->logbook;//create logbook
								newnode->logbook.push_back(newlog);
								//cout << "Map size is: " << ++mapsize << endl;
								BFSorder.push(newnode);//put the new node in the order
							} else {//if the state already exists
								if (my_map[set2key(bucket)]->score < newscore) {
									my_map[set2key(bucket)]->score = newscore;//update the score
									my_map[set2key(bucket)]->logbook = curr->logbook;//replace logbook
									my_map[set2key(bucket)]->logbook.push_back(newlog);
								}
							}
							if (newscore > maxscore) {
								maxscore = newscore;
								maxstate = my_map[set2key(bucket)];
							}
							//my_map[set2key(bucket)]->showNode();
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
	printResult(maxscore, maxstate);
	*/
	//calculate run time
	t = clock() - t;
	cout << "run time is: " << ((float)t)/CLOCKS_PER_SEC << endl;
}