#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//fibonacci recursivo
int Fib_R(int n)
{
    if(n<=0) return 0;
    else if(n==1) return 1;
    else return Fib_R(n-1)+Fib_R(n-2);
}

// iterative version
int Fib_I(int n)
{
    int fib[] = {0,1,1};
    for(int i=2; i<=n; i++)
    {
        fib[i%3] = fib[(i-1)%3] + fib[(i-2)%3];
        cout << "fib(" << i << ") = " << fib[i%3] << endl;
    }
    return fib[n%3];
}
//Recursiva

int main()
{
    int a = 35;
    auto start = high_resolution_clock::now();
    cout << endl << "From recursive function" << endl;
    for(int i=1; i<=a; ++i)
        cout << "fib(" << i << ") = " << Fib_R(i) << endl;
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo "<< duration.count()<< " microseconds" << endl;
    return 0;
}
//Iterativa

/*
int main()
{
    int a = 30;
    auto start = high_resolution_clock::now();
     cout << "From iterative function" << endl;
    Fib_I(a);
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo "<< duration.count()<< " microseconds" << endl;
    return 0;
}*/

