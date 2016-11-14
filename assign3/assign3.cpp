#include <climits>
#include <cstdio>
#include <string>
using namespace std;
int P[11][11] = {0};
string cities[] = {"Toronto","Kingston","Montreal","Buffalo","Rochester","Syracuse",
"Albany","Binghamton","Scranton","Allentown","NYC"};

//find intermediate nodes by recursively tracing through the P table
void findPath(int q, int r){
	if(P[q][r] != 0){
		findPath(q, P[q][r]);
		printf("%s ", cities[P[q][r]].c_str());
		findPath(P[q][r], r);
		return;
	}
	else return;	
}

int main(){
int max = INT_MAX;

//hardcoding adjacency matrix
int D[11][11] = {
0, 180, max, 100, max, max, max, max, max, max, max, //Toronto
180, 0, 160, max, max, 65, max, max, max, max, max, //Kingston
max, 160, 0, max, max, max, 130, max, max, max, max, //Montreal
100, max, max, 0, 60, max, max, max, max, max, max, //Buffalo
max, max, max, 60, 0, 70, max, max, max, max, max, //Rochester
max, 65, max, max, 70, 0, 100, 70, max, max, max, //Syracuse
max, max, 130, max, max, 100, 0, max, max, max, 140, //Albany
max, max, max, max, max, 70, max, 0, 60, max, 180, //Binghamton
max, max, max, max, max, max, max, 60, 0, 65, 100, //Scranton
max, max, max, max, max, max, max, max, 65, 0, 70, //Allentown
max, max, max, max, max, max, 140, 180, 100, 70, 0}; //NYC

//Floyd's algorithm, creating D0 - D10 to complete final P table 
for(int k = 0; k < 11; k++){
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < 11; j++){
			if(D[i][k] != max && D[k][j] != max && D[i][j] > D[i][k] + D[k][j]){
				D[i][j] = D[i][k] + D[k][j];
				P[i][j] = k;
			}
		}
	}
}
printf("NYC ");
findPath(10, 0);
printf("Toronto");
return 0;
}
