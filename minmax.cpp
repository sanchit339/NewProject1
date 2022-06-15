#include<iostream>
using namespace std;
void minmax(int arr[],int n){
    int min,max,i;
    min=max=arr[0];
    for ( i = 1; i < n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        else if (arr[i]<min)
        {
            min=arr[i];
        }
        
        
    }
   cout<<"\nMinimum value is : "<<min<<endl<<"Maximum value is: "<<max; 

}
int main(){
    int arr[20],n,i;
    cout<<"Enter no. of elements :";
    cin>>n;
    cout<<"\nEnter elements:";
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    minmax(arr,n);
    return 0;
}