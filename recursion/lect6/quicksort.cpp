#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1; i <= e; i++){
        if (arr[i]<=pivot) cnt++;
    }
    int pIdx = s+cnt;
    swap(arr[s], arr[pIdx]);
    int i = s, j = e;
    while (i < pIdx && j > pIdx) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pIdx && j > pIdx){
            swap(arr[i++], arr[j--]);
        }
    }
    return pIdx;
}
void quickSort (int arr[], int s, int e) {
    if (s>=e) return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
        cout << endl;
}
int main()
{
    int arr[] = {21, 5, 45, 8, 7, 9, 53};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);
    quickSort(arr, 0, arr_size-1);
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
