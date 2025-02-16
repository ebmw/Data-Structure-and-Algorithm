#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
// O(n)
int func1(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        ++sum;
    }
    return sum;
}
// O(n^2)
int func2(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            ++sum;
        }
    }
    return sum;
}
// O(n^3)
int func3(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            /* code */
            ++sum;
        }
    }
    return sum;
}

// o(n^2)
int func4(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            /* code */
            ++sum;
        }
    }
    return sum;
}
// o(n^5)
int func5(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i * i; j++)
        {
            /* code */
            for (int k = 0; k < j; k++)
            {
                /* code */
                ++sum;
            }
        }
    }
    return sum;
}
// o(n^4)
int func6(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i * i; j++)
        {
            /* code */
            if (j % i == 0)
            {
                for (int k = 0; k < j; k++)
                {
                    ++sum;
                }
            }
        }
    }
    return sum;
}


void timeFunction(int (*func)(int), int n)
{
    auto start = chrono::high_resolution_clock::now();
    func(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    cout << "Time taken for N = " << n << ": " << duration.count() << " ms" << endl;
}

int main()
{
    int testSizes[] = {10, 100, 200}; // Different values for N

    for (int n : testSizes)
    {
        cout << "Function 1:" << endl;
        timeFunction(func1, n);
        cout << "Function 2:" << endl;
        timeFunction(func2, n);
        cout << "Function 3:" << endl;
        timeFunction(func3, n);
        cout << "Function 4:" << endl;
        timeFunction(func4, n);
        cout << "Function 5:" << func6(100) << endl;
        timeFunction(func5, n);
        cout << "Function 6:" << endl;
        timeFunction(func6, n);
        cout << "---------------------------" << endl;
    }

    return 0;
}
