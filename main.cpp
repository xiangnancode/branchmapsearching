#include "buildMap.h"
#include <iostream>

using namespace std;


int main() {
	cout << "Hello World!" << endl;
	buildMap my_map;
	my_map.test();
	//my_map.initialize("./input/short.csv");
	my_map.initialize("./input/CNBCIQ_100.csv");


	return 1;
}