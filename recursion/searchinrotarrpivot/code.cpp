// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int pivot(int *arr, int s, int e) {
    if (s<e) {
        int mid = s + (e-s)/2;
       // cout << mid<< endl;
        if (arr[0]< arr[mid]) pivot(arr, mid + 1, e);
        else {
            if (arr[mid-1] > arr[mid]) return mid;
            pivot (arr, s, mid-1);
        }
    }
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
    
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}    
int srchRotArr(int *arr, int n, int key) {
    int piv = pivot(arr, 0, n-1);
    if (arr[piv] < key && arr[n-1] > key) {
        binarySearch(arr, piv, n-1, key);
    } else {
        binarySearch(arr, 0, piv-1, key);
    }
}

int main() {
    // Write C++ code here
    int arr[] = {5, 15, 16, 18, 52, 53, 54, 55, 1, 2, 3, 4, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << srchRotArr(arr, size, 15);

    return 0;
}