#include <iostream>
using namespace std;
//a little trickier way to handle this question please check the algo of it.........
int square(int num, int exp)
{

    if (exp == 0)
        return 0;

    if (exp == 1)
        return num;

    // recursive call
    int ans = square(num, exp / 2);

    // if exp is even
    if (exp % 2 == 0)
    {
        return ans * ans;
    }

    else
    {
        // if b is odd
        return num * ans * ans;
    }
}

int main()
{

    int num = 5;
    int exp = 2;

    int ans = square(num, exp);
    cout << ans;
    return 0;
}