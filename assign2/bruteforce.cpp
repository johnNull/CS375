#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include "point.h"
#include <cmath>
using namespace std;
vector<point> p;

int distance(point p1, point p2){
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main(int argc, char* argv[]){
	string inFile, outFile, line;
	int x, y, i1, i2, min = 99999;
	ifstream reader;
	ofstream writer;
	inFile = argv[1];
	outFile = argv[2];
	reader.open(inFile);
	while(!reader.eof()){
		reader >> line;
		x = atoi(line.c_str());
		reader >> line;
		y = atoi(line.c_str());
		p.push_back(point(x, y));
	}

	for(int i = 0; i < p.size() - 1; i++){
		for(int q = i + 1; q < p.size();q++){
			if(distance(p.at(i), p.at(q)) < min){
				min = distance(p.at(i), p.at(q));
				i1 = i;
				i2 = q;
			}
		}
	}
	writer.open(outFile, ofstream::trunc);
	writer << i1;
	writer << " ";
	writer << i2;
	writer << " ";
	writer << min ;	
	writer.close();
	return 0;
}	
