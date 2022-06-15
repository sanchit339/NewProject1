#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h, int n)
{
    int n1 = m - l + 1, n2 = h - m;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        b[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int h, int n)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid, n);
        mergesort(arr, mid + 1, h, n);

        merge(arr, l, mid, h, n);
    }
}
int main()
{
    int n, i;
    cout << "Enter no. of elements :";
    cin >> n;
    int arr[n], F[n];
    cout << "\nEnter elements:";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1, n);
    cout << "\nSorted elements are:";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}