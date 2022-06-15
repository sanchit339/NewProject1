#include<bits/stdc++.h>
using namespace std;
void minmax(int arr[],int i,int j,int &min,int &max){
    
    if (i==j){
            min=arr[i];
            max=arr[i];
    }
    else if (i==j-1)
    {
        if (arr[i]>arr[j])
        {
            min=arr[j];
            max=arr[i];
        }
        else
        {
            min=arr[i];
            max=arr[j];
        }
        
    }
    else
    {
        int mid;
        mid=(i+j)/2;
        minmax(arr,i,mid,min,max);
        int min1=min,max1=max;
        minmax(arr,mid+1,j,min,max);
       if (min1<min)
       {
           min=min1;
       }
       if (max1>max)
       {
           max=max1;
       }   
    }
}
int main(){
    int arr[20];
    int n,i,min=INT_MAX,max=INT_MIN;
    cout<<"Enter no. of elements :";
    cin>>n;
    cout<<"\nEnter elements:";
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    minmax(arr,0,n-1,min,max);
    cout<<"Minimum : "<<min<<endl<<"Maximum : "<<max;
    return 0;
}