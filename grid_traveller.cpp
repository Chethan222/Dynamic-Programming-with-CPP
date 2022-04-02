#include <iostream>
#include <algorithm>

int travel[10][10] = {1, 0};

int grid_traveller(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (m == 1 && n == 1)
        return 1;

    // Returing memoized path
    if (travel[m][n] != 0)
        return travel[m][n];
    else
    {
        // Calculating no. of possibilities at m,n
        travel[m][n] = grid_traveller(m - 1, n) + grid_traveller(m, n - 1);

        // No of. ways from 2,3 is same as 3,2
        travel[n][m] = travel[m][n];
        return travel[m][n];
    }
}

int main()
{
    std::cout << grid_traveller(3, 3);
    return 0;
}