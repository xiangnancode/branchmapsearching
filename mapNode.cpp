#include "mapNode.h"

mapNode::mapNode() {
	this->score = 0;
}

mapNode::mapNode(set<string> set_in, double score_in) {
	this->score = score_in;
	this->bucket = set_in;
}