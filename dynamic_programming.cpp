#include <iostream>
#include <vector>

using namespace std;


// 0 1 1 2 3 5 8 13

vector<int> memo(100, -1);

int fib(int n)
{

    if(memo[n] != -1)
    {
        return memo[n];
    }

    // base case
    if(n==0 || n==1)
    {
        return n;
    }
    memo[n] =  fib(n-1) + fib(n-2);
    return memo[n];
}

int fib2(int n)
{
    vector<int> fibList;

    fibList.push_back(0);
    fibList.push_back(1);

    for(int i=2 ; i<=n; i++)
    {
        fibList[i] = fibList[i-1] + fibList[i-2];
    }
    return fibList[n];
}

int main()
{
    // cout << fib(7) << endl;
    cout << fib2(8) <<endl;
    return 0;
}