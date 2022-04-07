#include <iostream>
int intpart(int n);
double squareroot(int n, int intpart, int precision);
using namespace std;
int main() {
    int n = 37;
    cout <<" square root of "<< n << "is " << squareroot(n, intpart(n), 3);
}

int intpart(int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    
    while (s <= e){
        long long int square = mid*mid;
        if (square == n) {
            return mid;
        } 
        if (square < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e =  mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
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