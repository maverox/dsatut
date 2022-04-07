#include <iostream>
using namespace std;

double squareroot(int n, int intpart, int precision) {
    double factor = 1;
    double ans =  intpart;
    for (int i = 0; i < precision; i++) {
        factor /=  10;
        for (double j = ans; j*j < n; j+=factor) {
            ans = j;
        }
    }
    return ans;
}