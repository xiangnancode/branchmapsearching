#include "buildMap.h"
#include "mapNode.h"



void buildMap::test() {
	cout << "print from buildMap test" << endl;
	set<string> bucket;
	mapNode x(bucket, 5.23);
	cout << x.score << endl;
}

