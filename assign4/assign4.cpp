#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int courses[15][3] = {5, -1, -1,
	3, -1, -1,
	5, 11, -1,
	4, 6, 13,
	7, -1, -1,
	7, 12, 13,
	8, -1, -1,
	10, -1, -1,
	9, -1, -1,
	-1, -1, -1,
	-1, -1, -1,
	-1, -1, -1,
	-1, -1, -1,
	14, -1, -1,
	-1, -1, -1};
	vector<int> queue;
	int visited[15] = {0};
	int maximum = 0, temp, track;
	//bfs
	for(int i = 0; i < 15; i++){
		if(!visited[i]){
			temp = 1;
			visited[i] = 1;
			queue.push_back(i);
			int q = i;
			while(!queue.empty()){
				track = 1;
				q = queue.front();
				//cout << q + 1 << " ";
				queue.erase(queue.begin());
				for(int w = 0; w < 3; w++){
					if(courses[q][w] != -1 && !visited[courses[q][w]]){
						visited[courses[q][w]] = 1;
						queue.push_back(courses[q][w]);
						if(track){
							temp++;
							track = 0;
						}
					}
				}
			}
			//cout << "\n";
			if(maximum < temp) maximum = temp;
		}
	}
	cout << maximum << " semesters\n";
	//linear program
	double tempPrice = 0, price = 9999, priceLoc = 0;
	vector<int> X;
	vector<int> Y;
	double tempY;
	bool xFlag = false;
	for(double i = 0; !xFlag; i++){
		if(60*i >= 300 && 12*i >= 36 && 10*i >= 90){
			X.push_back(i);
			xFlag = true;
		}
		else{
			X.push_back(i);
			tempY = max(ceil((300 - (i*60)) / 60), ceil((36 - (12*i))/6));
			Y.push_back(max(tempY, ceil((90 -(i*10))/30)));
			tempPrice = (Y.at(i) * .15) + (X.at(i) * .12);
			if(tempPrice < price){
				priceLoc = i;
				price = tempPrice;
			}
		}
	}
	cout << "Price: $" << price << ", X: " << priceLoc << ", Y: " << Y.at(priceLoc); 
}
