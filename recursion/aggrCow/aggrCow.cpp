#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> arr, int m, int mid)
{
    int cowCount = 1;
    int lastStall = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i] - lastStall) >= mid)
        {
            if (++cowCount == m)
            {
                return true;
            }
            lastStall = arr[i];
        }
    }
    return false;
}
int aggrCow(vector<int> arr, int m, int s, int e)
{
    static int ans = -1;
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, m, mid))
        {
            ans = mid;
            aggrCow(arr, m, mid + 1, e);
        }
        else
        {
            aggrCow(arr, m, s, mid - 1);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 2, 1, 3, 6};
    sort(arr.begin(), arr.end());
    int upperBound = arr[arr.size() - 1] - arr[0];
    cout << aggrCow(arr, 2, 0, upperBound) << endl;
}