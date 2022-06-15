#include<bits/stdc++.h>
#define INF 999999
using namespace std;
int arr[50][50];
int minDist(int dist[],bool visited[],int vertices){
	int min = INF,minIndex=0;
	for(int i = 0;i < vertices;i++){
		if(!visited[i] && dist[i] < min){
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}
void dijkstra(int st,int vertices){
	int dist[vertices];
	bool visited[vertices];
	for (int i = 0; i < vertices; i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}
	
	dist[st] = 0;

	for (int i = 0; i < vertices; i++)
	{
		int nearest = minDist(dist,visited,vertices);
		 cout<<nearest<<endl;
		visited[nearest] = true;
		for(int adj=0;adj<vertices;adj++){
			if( dist[nearest] + arr[nearest][adj] < dist[adj] && arr[nearest][adj]!= INF )
			dist[adj] = dist[nearest] + arr[nearest][adj];
		}
		// for(int t=0;t<vertices;t++) cout<<dist[t]<<" ";
		// cout<<endl;
	}
	
	

	cout<<"\nDistance of vertex from starting node :\n";
	for(int k=0;k<vertices;k++){ 
		if(dist[k] == INF) cout<<k<<"\t\t"<<"INF"<<endl;
		else cout<<k<<"\t\t"<<dist[k]<<endl;}
}
int main(){
	int vertices,i,j,e,s,f,cost,st;
	cout<<"\nEnter no. of vertices :";
	cin>>vertices;
	
	for(i = 0;i <vertices;i++)
	for(j = 0;j <vertices;j++){
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
	cout<<"\nEnter starting vertex :";
	cin>>st;
	dijkstra(st,vertices);
	/*for(i = 0;i < vertices;i++){
		cout<<endl;
	for(j = 0;j < vertices;j++)
	cout<<arr[i][j]<<"  ";
	}*/
}
