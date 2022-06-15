#include <bits/stdc++.h>
using namespace std;
#define nV 20
#define INF 100000

void all_pairs(int arr[][nV],int v) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < v; i++)
    for (j = 0; j < v; j++)
        matrix[i][j] = arr[i][j];

  for (k = 0; k < v; k++) {
    for (i = 0; i < v; i++) {
      for (j = 0; j < v; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  cout<<"\nThe final distance matrix is :"<<endl;
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (matrix[i][j] == INF)
        cout<<"INF"<<"\t";
      else
       cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }
 
}

int main() {
  int arr[nV][nV],vertices,s,f,cost,i,j,e;

  cout<<"\nEnter no. of vertices :";
	cin>>vertices;
   for(i = 0;i < vertices;i++)
	for(j = 0;j < vertices;j++){
		if(i==j)
			arr[i][j] = 0;
		else 
			arr[i][j] = INF;
	}
	cout<<"\nEnter total no. of edges :";
	cin>>e;
	cout<<"\nEnter starting node ,ending node & cost of each edge :\n";
	for(i = 0;i < e;i++){
		cin>>s>>f>>cost;
		arr[s][f] = cost;
	} 
  all_pairs(arr,vertices);
}