#include <iostream>
#include <algorithm>
#include <vector>

void print(int m, int n, std::vector<std::vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int grid_traveller(int m, int n)
{
    // Initializing grid with zero

    std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));

    // Adding 1 at (1,1) for one possibility
    grid[1][1] = 1;

    // Iterating over grid
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int curr_pos_val = grid[i][j];
            std::cout << "Curr" << curr_pos_val << std::endl;
            if (j + 1 <= n)
            {
                // Increment right cell by curr value
                grid[i][j + 1] += curr_pos_val;
            }
            if (i + 1 <= m)
            {
                // Increment down cell by cur value
                grid[i + 1][j] += curr_pos_val;
            }
            print(m, n, grid);
        }
    }
    return grid[m][n];
}

int main()
{
    std::cout << grid_traveller(2, 2);
    return 0;
}