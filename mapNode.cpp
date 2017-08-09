#include "mapNode.h"

string mapNode::set2key() {
	string strset;//string tpye of the ordered set
	for(auto i : bucket) {//for all elements in the set
		if (strset.size() == 0) {//first element
			strset = i;
		} else {//rest of the elements
			strset += "," + i;
		}
		
	}
	return strset;
}

mapNode::mapNode() {
	this->score = 0;
}

mapNode::mapNode(set<string> set_in, double score_in) {
	this->score = score_in;
	this->bucket = set_in;
	this->key = set2key();
}

void mapNode::showNode() {
	cout << "This set contains: " << this->key << endl;
	//cout << "This set size is: " << this->bucket.size() << endl;
	//cout << "This set score is: " << this->score << endl;
}