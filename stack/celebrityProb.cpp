#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &celebs, int n)
{
    stack<int> s;   
    for (int i = 0; i < n; i++) {
        s.push(i);
    }
    
    while (s.size()!=1) {
       int a = s.top();
        s.pop();
      int  b = s.top();
        s.pop();
        if (celebs[a][b] == 1) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }
    int candidate = s.top();
    bool knowsNone = true,isFamous = true; 
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && celebs[candidate][i]==1) {
            knowsNone = false;
            break;
        } 
        if (i!= candidate && celebs[i][candidate] == 0){ 
            isFamous = false;
            break;
}
    }
    return (knowsNone && isFamous) ? candidate: -1;
}

int main()
{
    vector<vector<int>> celebs = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

    cout << celebrity(celebs, celebs.size());
}