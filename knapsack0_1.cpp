// knapsack program....date:21 MAR 2022
#include<iostream>
using namespace std;
int search(double r[],int t,int n){
    for (int i = 0; i < n; i++)
    {
        if (r[i]==t)
        {
            return i;
        }
        
    }
   return -1; 
}
void sort(double r[],int n){
    int i,j,min;
    for ( i = 0; i < n-1; i++)
    {
        
        for ( j = 0; j < n-i-1; j++)
        {
            if (r[j]>r[j+1])
            {
                double temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
            
        }
        
    }
    
}
void knapsack(double W[],double P[],int w,int n){
    double ratio[20],ratio1[20];
    double F[20];
    for ( int i = 0; i < n; i++)
    {
        F[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        ratio[i]=P[i]/W[i];
    }
    
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<ratio[i]<<" ";
    // }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        ratio1[i]=ratio[i];
    }
    sort(ratio1,n);
//    for (int i = 0; i < n; i++)
//     {
//         cout<<ratio1[i]<<" ";
//     }
    //  cout<<endl;
    double wt=0,temp,profit=0;
    int p=n-1,index,j=0,ind[20];
       for(int k=0;k<n;k++){
         for (int i = 0; i < n; i++)
        {   temp=ratio1[p];
            
            if (ratio[i]==temp)
            {
            
            ind[j]=i;
            ratio[i]=0;
            // cout<<ind[j]<<" ";
            p--;
            j++;
            }
            } } 
            j=0; 
    while (wt<=w)
    {
        // cout<<index;
        wt=wt+W[ind[j]];
        F[ind[j]]=1.0;
        profit = profit + P[ind[j]];
        j++;

    }
    j--;
    profit = profit - P[ind[j]];
    wt=wt-W[ind[j]];
    F[ind[j]]=0;
    
    cout<<"\nWeights of items in knapsack : ( ";
    for (int i = 0; i < n; i++)
    {
        cout<<F[i]<<" , ";
    }
     cout<<")"; 
       cout<<"\nTotal profit is : "<<profit;
}
int main(){
    int w,n,i;
    double W[20],P[20];
    
    cout<<"Enter no. of items :";
    cin>>n;
    cout<<"\nEnter weights of items :";
    for ( i = 0; i < n; i++)
    {
        cin>>W[i];
    }
    cout<<"Enter profit of each item :";
    for ( i = 0; i < n; i++)
    {
        cin>>P[i];
    }
    cout<<"\nEnter max weight: ";
    cin>>w;
    
    knapsack(W,P,w,n);
    
    return 0;
}