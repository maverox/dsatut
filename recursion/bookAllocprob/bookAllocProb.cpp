#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int m, int mid)
{
    int studentCount = 1;
    int pageCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((pageCount + arr[i]) <= mid)
        {
            pageCount += arr[i];
        }
        else
        {
            if (++studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageCount = arr[i];
        }
    }
    return true;
}
int bookAllocProb(vector<int> arr, int m, int s, int e)
{
    static int ans = -1;
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, m, mid))
        {
            ans = mid;
            bookAllocProb(arr, m, s, mid - 1);
        }
        else
        {
            bookAllocProb(arr, m, mid + 1, e);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int sum  = 0;
    for (int i : arr) {
        sum += i;
    }
    cout << bookAllocProb(arr, 2, 0, sum) << endl;
}