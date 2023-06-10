#include <iostream>
using namespace std;

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int sqrtInt(int low, int high, int N)
{

    // If the range is still valid
    if (low <= high)
    {

        // Find the mid-value of the range
        int mid = (low + high) / 2;

        // Base Case
        if ((mid * mid <= N) && ((mid + 1) * (mid + 1) > N))
        {
            return mid;
        }

        // Condition to check if the
        // left search space is useless
        else if (mid * mid < N)
        {
            return sqrtInt(mid + 1, high, N);
        }
        else
        {
            return sqrtInt(low, mid - 1, N);
        }
    }
    return low;
}
double preciseRoot(double approx, double factor, double precision, int n)
{
    cout << approx<< endl;
    if (factor >= precision)
    {   
        if ((approx) * (approx) <= n)
        {
            approx += factor; 
            factor+= factor;
            preciseRoot(approx, factor/10, precision, n);
        }
    }
    return approx;
}
int main()
{
    int n;
    cin >> n;
    cout << "square root of " << n << "is " << preciseRoot((double)sqrtInt(0, n, n), 0.1, 0.001, n)<< endl;
}