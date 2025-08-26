// Program to compute a factorial, both recursively and in iteratively in a loop
#include <iostream>

#define ONE_MILLION 1000000

long long factorial(long long n);
long long factorial_recur(long long n);
int factorial_mod_m(int n);
int factorial_recur_mod_m(int n);
bool is_equal(double a, double b);

    int main(void)
{
    long long x{};
    int y{};
    std::cout << "Please enter a number that you want the factorial of: ";
    std::cin >> x;
    std::cout << "Please enter a number which you want the factorial of, mod 1 million: ";
    std::cin >> y;
    std::cout << "The factorial of the first number is " << factorial(x) << '\n';
    std::cout << "The factorial recursively computed of the first number is " << factorial_recur(x) << '\n';
    std::cout << "The factorial of the second number mod one million is " << factorial_mod_m(y) << '\n';
    std::cout << "The factorial recursively computed of the second number mod one million is " << factorial_recur_mod_m(y) << '\n';
    std::cout << is_equal(1 + 0.1, 1.1) << '\n';
    std::cout << is_equal(1.1, 1.2) << '\n';
}

long long factorial(long long n)
{
    long long x { 1 };
    for (long long i = 2; i < n + 1; ++i)
        x *= i;
    return x;
}

long long factorial_recur(long long n)
{
    if (n < 0)
        return 1;
    if (n == 0)
        return 1;
    return n * factorial_recur(n - 1);
}

int factorial_mod_m(int n)
{
    int x{ 1 };
    for (int i = 2; i < n + 1; ++i)
        x = (x * i) % ONE_MILLION;
    return x;
}

int factorial_recur_mod_m(int n)
{
    if (n < 0)
        return 1;
    if (n == 0)
        return 1;
    return (n * factorial_recur_mod_m(n - 1)) % ONE_MILLION;
}

bool is_equal(double a, double b)
{
    return abs(a - b) < 1e-9;
}