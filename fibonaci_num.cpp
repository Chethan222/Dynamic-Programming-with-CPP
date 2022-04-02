#include <bits/stdc++.h>
#include <algorithm>

int term[1000];
void init()
{
    std::fill_n(term, 1000, -1);
}

// Fibonacci Series using memoized Recursion
int fib(int n)
{
    // base case
    if (n <= 2)
        return n;
    if (term[n] != -1)
    {
        return term[n];
    }
    else
    {
        term[n] = fib(n - 1) + fib(n - 2);
        return term[n];
    }
}

int main()
{
    init();
    std::cout << fib(6);
    return 0;
}
