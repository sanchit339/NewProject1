#include<bits/stdc++.h>
using namespace std;
void omp(int arr[],int n){
    int sum=0,sum1=0,i,j,size=n;
    cout<<"\nSteps to merge files are :\n";
    for(i=0;i<size;i++) cout<<arr[i]<<"\t";
    cout<<endl;
    while(size>2)
    {
    sum = arr[0] + arr[1];
    for(i=2;i<size;i++) arr[i-2]=arr[i];
    i=0;
    size-=1;
    while (sum>=arr[i] && i<size-1) i++;
    for(j=size-1;j>i;j--) arr[j]=arr[j-1];
    arr[i]=sum;
    for(i=0;i<size;i++) cout<<arr[i]<<"\t";
    cout<<endl;
    sum1+=sum;
    }
    sum1+=arr[0]+arr[1];
    cout<<endl<<"Minimum solution is : "<<sum1;
    
}
int main(){
    int n;
    cout<<"Enter no. of files : ";
    cin>>n;
    int arr[n];
    cout<<endl<<"Enter size of each file : ";
    for (int i = 0; i < n; i++) cin>>arr[i];
    sort(arr,arr+n);
    omp(arr,n);
    
    return 0;
}