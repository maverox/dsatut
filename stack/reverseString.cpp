#include <iostream>
#include <stack>
using namespace std;

string reverse(string &s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {char c = s[i];
        stk.push(c);
    }int size = stk.size();
   
    for (int i = 0; i < size; i++) {char c = stk.top();
        s[i] = c;
        stk.pop();
    }
    return s;
}
int main ()
 {
    string s = "uzzairrr";
    s = reverse(s);
    cout << s;
 }