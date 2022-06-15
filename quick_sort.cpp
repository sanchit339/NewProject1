#include <bits/stdc++.h>
using namespace std;
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int Partition(int arr[], int l, int r)
{
    int pivot, i, j;
    pivot = arr[l];
    i = l + 1;
    j = r;

    do
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);

    int temp = arr[j];
    arr[j] = arr[l]; // pivot swap with j
    arr[l] = temp;
    return j;
}

void Quick_sort(int arr[], int l, int r)
{
    int partition_index;
    if (l < r)
    {
        partition_index = Partition(arr, l, r);
        Quick_sort(arr, l, partition_index - 1);
        Quick_sort(arr, partition_index + 1, r);
    }
}
int main()
{
    int n;
    cout << "\nEnter size of array :";
    cin >> n;
    int arr[n];
    cout << "\nEnter elements of array :";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    print_array(arr,n);
    Quick_sort(arr, 0, n - 1);
    print_array(arr,n);
    return 0;
}