#include <iostream>
using namespace std;

class towerOfhanoi
{
    int n, srcPeg, destPeg, auxPeg;

public:
    towerOfhanoi(int n, int srcPeg, int destPeg, int auxPeg)
    {
        this->n = n;
        this->srcPeg = srcPeg;
        this->destPeg = destPeg;
        this->auxPeg = auxPeg;
    }

    void solve(int n, int srcPeg, int destPeg, int auxPeg)
    {
        if (n == 1)
        {
            move(srcPeg, destPeg);
            return;
        }
        solve(n - 1, srcPeg, auxPeg, destPeg);
        move(srcPeg, destPeg);
        solve(n - 1, auxPeg, destPeg, srcPeg);
    }
    void move(int srcPeg, int destPeg)
    {
        cout << "move topmost disk from peg " << srcPeg << " to " << destPeg << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    towerOfhanoi h(n, 1, 3, 2);
    h.solve(n, 1, 3, 2);
}