#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main(int argc, char* argv[]){
	vector<int> vals;
	int diff = INT_MAX, right, left= 0;
	bool found = false;	
	string inFile, outFile, line;
	ifstream reader;
	ofstream writer;
	inFile = argv[1];
	outFile = argv[2];
	reader.open(inFile);
	while(!reader.eof()){
		reader >> line;
		vals.push_back(atoi(line.c_str()));
	}
	reader.close();
	vals.pop_back();
	sort(vals.begin(), vals.end());
	right = vals.size() - 1;
	while(!found && right > 0){
		while(left < right){
			diff = vals.at(right) - vals.at(left);
			if(binary_search(vals.begin(), vals.end(), diff)){
				found = true;
				break;
			}
			left++;
		}
		right--;
	}
	writer.open(outFile, ofstream::trunc);
	if(diff != INT_MAX && found){
		writer << diff;	
	}
	writer.close();
	return 0;
}
