#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector <int> nextSmallest(vector<int> &nums) {
    vector <int> answer(nums.size());
    stack <int> s;
    s.push(-1);
    for (int i = nums.size()-1; i >= 0; i--) {
        while (s.top() != -1 && s.top() >= nums[i]) {
            s.pop();
        }
        answer[i] = s.top();
        s.push(nums[i]);
    }
    return answer;
}

void print(vector <int> arr) {
    for (auto i: arr) {
        cout << i << ' ';

    }cout << endl;
}
int main () {
    vector <int> arr = {5, 6, 4, 7, 9, 8 ,1 ,3 ,2};
    print(arr);
    vector <int> arr2 = nextSmallest(arr);
    print(arr2);
}