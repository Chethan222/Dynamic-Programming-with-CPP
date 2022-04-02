// Write a function 'how_sum(target_sum,numbers)' that takes in a target sum and an array of numbers
// as arguments.
// It should return combination of character that should sum upto target sum

#include <iostream>
#include <vector>
#include <map>

std::map<int, std::vector<int>> memo;

void print(int *ans)
{
    if (!ans)
    {
        return;
    }
    int n = sizeof(ans) / sizeof(ans[0]);
    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }
}

int *spread(int *numbers, int num, int *arr)
{
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int j = 0;
    for (j = 0; j < n; j++)
    {
        arr[j] = numbers[j];
    }
    arr[j] = num;
    return arr;
}

int *how_sum(int sum, int *numbers)
{
    print(numbers);
    static int arr[1000];
    // Base terminate condition
    if (sum == 0)
    {
        return arr;
    }
    else if (sum < 0)
    {
        return nullptr;
    }

    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Trying with different combinations
    for (int i = 0; i < n; i++)
    {
        int difference = sum - numbers[i];

        // Recursively checking for each element
        int *result = how_sum(difference, numbers);
        print(result);
        if (result != nullptr)
        {
            return spread(result, numbers[i], arr);
        }
    }

    return nullptr;
}

int main()
{
    int arr[] = {2, 3, 4};
    int *ans;

    ans = how_sum(9, arr);

    print(ans);
    return 0;
}