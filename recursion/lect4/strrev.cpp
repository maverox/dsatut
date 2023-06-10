#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}
void strrev(string& s, int i= 0) {
    if (i > s.length()-i-1) return;
    swap(s[i], s[s.length()-i-1]);
    strrev(s, i+1);
}
bool isPalindrome(string s, int i=0) {
    if (i> s.length()-i-1) return true;
    if (s[i] != s[s.length()-i-1]) return false;
    isPalindrome(s, i+1);
}
int main () {
    string s = "hello olleh";
    // cout << s << endl;
    // strrev(s);
    // cout << s << endl;
    (isPalindrome(s)) ? cout << "is Palindrome \n" : cout << "is not a Palindrome \n";
}