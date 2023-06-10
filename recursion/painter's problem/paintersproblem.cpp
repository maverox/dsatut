#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int m, int mid)
{
    int painterCount = 1;
    int blockCount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((blockCount + arr[i]) <= mid)
        {
            blockCount += arr[i];
        }
        else
        {
            if (++painterCount > m || arr[i] > mid)
            {
                return false;
            }
            blockCount = arr[i];
        }
    }
    return true;
}
int paintersProb(vector<int> arr, int m, int s, int e)
{
    static int ans = -1;
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, m, mid))
        {
            ans = mid;
            paintersProb(arr, m, s, mid - 1);
        }
        else
        {
            paintersProb(arr, m, mid + 1, e);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {5,10,30,20,15};
    int sum  = 0;
    for (int i : arr) {
        sum += i;
    }
    cout << paintersProb(arr, 3, 0, sum) << endl;
}