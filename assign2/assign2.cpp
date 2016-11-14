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

int main(int argc, char* argv[]){
	string inFile, outFile, line;
	int x, y;
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
	reader.close();

	return 0;
}

int distance(point p1, point p2){
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

vector<int> closePair(int bi, int ei){
	int d = 0;
	vector<int> ret;
	if((ei - bi) == 1){
		ret.push_back(bi);
		ret.push_back(ei);
		ret.push_back(distance(p.at(bi), p.at(ei)));
	}
	else if((ei - bi) == 2){
		d = fmin(distance(p.at(bi), p.at(bi + 1)), distance(p.at(bi), p.at(ei)));
		d = fmin(d, distance(p.at(bi + 1), p.at(ei)));
		if(d = distance(p.at(bi), p.at(bi + 1))){
			ret.push_back(bi);
			ret.push_back(bi+1);
		}
		else if(d = distance(p.at(bi), p.at(ei))){
			ret.push_back(bi);
			ret.push_back(ei);
		}
		else{
			ret.push_back(bi+1);
			ret.push_back(ei);
		}
		ret.push_back(d);
	}
	else{
		
	}
	return ret;
}
