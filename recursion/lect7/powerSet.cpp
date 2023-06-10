#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
    output.pop_back();
    // exclude
    solve(nums, output, index + 1, ans);
    
    
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
} 
// void subsets(vector<int> &input, int index, vector<int> output, vector<vector<int>> &powerSet) {
//     if(index >= input.size()) {
//         powerSet.push_back(output);
//         return;
//     }
//     //include
//     int element = input[index];
//     output.push_back(element);
//     subsets(input, index+1, output, powerSet);
//     subsets(input, index+1, output, powerSet);
//     //exclude
// }
void printVector(vector<vector<int>>& vec) {
     cout << "{ ";
        for (vector<int> v : vec)
        {
            cout << "{  ";
            for (int i : v)
            {
                cout << i << ", ";
            }
            cout << "}, ";
        }
        cout << '}';
}
int main(){
        vector<int> ip = {1, 2, 3};

       vector<vector<int>> ans = subsets(ip);
       printVector(ans);
}