#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// to check whether the next step is possible
struct coordinates
{
    int x;
    int y;
};
bool isPossible(coordinates dest, vector<vector<int>> &maze, vector<vector<int>> &visited, int n)
{
    if ((dest.x < n && dest.x >= 0) && (dest.y < n && dest.y >= 0) && (visited[dest.x][dest.y] == 0) && (maze[dest.x][dest.y] == 1))
        return true;
    return false;
}
void pathfinder(coordinates pos, vector<vector<int>> &maze, vector<vector<int>> &visited, int n, string path, vector<string> &ans)
{   
    if ((pos.x == n - 1) && (pos.x == n - 1))
    {
        ans.push_back(path);
        return;
    }
    visited[pos.x][pos.y] = 1;
    coordinates dest;
    // L movement
    dest.x = pos.x - 1;
    dest.y = pos.y;
    if (isPossible(dest, maze, visited, n))
    {
        path.push_back('L');
        pathfinder(dest, maze, visited, n, path, ans);
        path.pop_back();
        
    }
    // R movement
    dest.x = pos.x + 1;
    dest.y = pos.y;
    if (isPossible(dest, maze, visited, n))
    {
        path.push_back('R');
        pathfinder(dest, maze, visited, n, path, ans);
        path.pop_back();
        
    }
    // U movement
    dest.x = pos.x;
    dest.y = pos.y - 1;
    if (isPossible(dest, maze, visited, n))
    {
        path.push_back('U');
        pathfinder(dest, maze, visited, n, path, ans);
        path.pop_back();
        
    }
    // D movement
    dest.x = pos.x;
    dest.y = pos.y + 1;
    if (isPossible(dest, maze, visited, n))
    {
        path.push_back('D');
        pathfinder(dest, maze, visited, n, path, ans);
        path.pop_back();
        
    }
    visited[pos.x][pos.y] = 0;
}
vector<string> ratMazeSolution(vector<vector<int>> &maze, int n)
{   
    vector<string> ans;
    string path = "";
    if (maze[0][0] == 0)
    {
        ans.push_back("");
        return ans;
    }
    vector<vector<int>> visited = maze;
    for (auto &i : visited)
    {
        for (auto &j : i)
        {
            j = 0;
        }
    }

    coordinates src = {0, 0};
    pathfinder(src, maze, visited, n, path, ans);
    sort(ans.begin(),  ans.end()); // remember to check the ans before and after sorting ans (lexicographically)
    return ans;
}
int main()
{
    vector<vector<int>> maze{
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 1}};
    int n = 4;
    vector<string> ans = ratMazeSolution(maze, n);
    
    for (auto &i : ans)
    {
        for (auto &j : i)
        {
            cout << j << "->";
            
        }
        cout<<"dest" << '\n';
    }
}