
/* Write a function "can_sum(target_sum,numbers)" that takes in a target sum and an array of numbers
as arguments.
It should return whether target sum can be using values in the numbers array.
*/
#include <iostream>
#include <vector>
#include <map>

std::map<int, int> memo;

bool can_sum(int sum, int *numbers, std::map<int, int> memo = memo)
{
    // Returning value from memory
    if (!(memo.find(sum) == memo.end()))
    {
        return memo[sum];
    }
    // Base terminate condition
    if (sum == 0)
    {
        return true;
    }
    else if (sum < 0)
    {
        return false;
    }

    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Trying with different combinations
    for (int i = 0; i < n; i++)
    {
        // Recursively checking for each element
        if (can_sum(sum - numbers[i], numbers, memo))
        {
            // Storing in memory
            memo[sum] = true;
            return true;
        }
    }
    // Storing in memory
    memo[sum] = false;
    return false;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 7, 9};

    std::cout << can_sum(48, arr);
    return 0;
}