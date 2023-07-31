#include <bits/stdc++.h>
using namespace std;

namespace recursive
{
    int celebrityRec(vector<vector<int>> &celebs, int n)
    {
        if (n == 0)
            return -1;
        int curr = n - 1;
        int prevCeleb = celebrityRec(celebs, n - 1);
        if (prevCeleb != -1)
        {
            if (celebs[prevCeleb][curr] == 1)
            {
                if (celebs[curr][prevCeleb] == 1)
                {
                    return -1;
                }
                else
                {
                    return curr;
                }
            }
            else
            {
                if (celebs[curr][prevCeleb] == 1)
                {
                    return prevCeleb;
                }
                else
                {
                    return curr;
                }
            }
        }
        else
            return curr;
    }
    // wrapper to check whether the candidate is a celebrity or not
    int celebrity(vector<vector<int>> &celebs, int n)
    {
        // find the celebrity
        int id = celebrityRec(celebs, n);

        // check if the celebrity found
        // is really the celebrity
        if (id == -1)
            return id;
        else
        {
            int c1 = 0, c2 = 0;

            // check the id is really the
            // celebrity
            for (int i = 0; i < n; i++)
                if (i != id)
                {
                    c1 += celebs[id][i];
                    c2 += celebs[i][id];
                }

            // if the person is known to
            // everyone.
            if (c1 == 0 && c2 == n - 1)
                return id;

            return -1;
        }
    }
}
int celebrity(vector<vector<int>> &celebs, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (celebs[a][b] == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int candidate = s.top();
    bool knowsNone = true, isFamous = true;
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && celebs[candidate][i] == 1)
        {
            knowsNone = false;
            break;
        }
        if (i != candidate && celebs[i][candidate] == 0)
        {
            isFamous = false;
            break;
        }
    }
    return (knowsNone && isFamous) ? candidate : -1;
}
// two pointer appraoch
namespace twoPointer
{
    int celebrity(vector<vector<int>> &celebs, int n)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (celebs[j][i] == 1) // j knows i
                j--;
            else // j doesnt know i so i cant be celebrity
                i++;
        }
        // i points to our celebrity candidate
        int candidate = i;

        // Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one
        for (i = 0; i < n; i++)
        {
            if (i != candidate)
            {
                if (celebs[i][candidate] == 0 || celebs[candidate][i] == 1)
                    return -1;
            }
        }
        // if we reach here this means that the candidate
        // is really a celebrity
        return candidate;
    }

}

int main()
{
    vector<vector<int>> celebs = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    cout << twoPointer::celebrity(celebs, celebs.size());
}