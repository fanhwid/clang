#include <stdio.h>
#include <math.h>

void print_parity(int x)
{
    if (x % 2 == 0)
        printf("%d is even.\n", x);
    else
        printf("%d is odd.\n", x);
}

int get_unit(int x)
{
    return x % 10;
}

int get_dec(int x)
{
    return (x / 10) % 10;
}

void print_unit(int x)
{
    printf("%d\n", get_unit(x));
}

void print_dec(int x)
{
    printf("%d\n", get_dec(x));
}

void print_logarithm(double x)
{
    if (x <= 0.0) {
        printf("Postive number only!\n");
        return;
    }
    printf("The log of %f is %f.\n", x, log(x));
}

int is_even(int x)
{
    return !(x % 2);
}

double distance(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    double squared_sum = dx * dx + dy * dy;
    double dist = sqrt(squared_sum);
    return dist;
}

double circle_area(double radius)
{
    return 3.1416 * radius * radius;
}

int gcd(int a, int b)
{
    if (a > 0 && b > 0) {
        if (a < b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
        if (a % b == 0) {
            return b;
        }
        else {
            return gcd(b, a % b);
        }
    }
    else {
        printf("Input postive number.\n");
        return -1;
    }
}

int fib(int n)
{
    if (n < 0)
        return -1;
    else {
        if (n <= 1)
            return 1;
        else
            return fib(n - 1) + fib(n - 2);
    }
}

int is_prime(int n)
{
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            break;
        }
    }
    if (i == n)
        return 1;
    else
        return 0;
}

int main(void)
{
    int x = -1;
    int y = 46;
    int a = -8;
    int b = 12;
    float z = 1.0;
    print_parity(x);
    print_parity(y);
    printf("The unit is %d.\n", get_unit(y));
    printf("The dec is %d.\n", get_dec(y));
    print_unit(y);
    print_dec(y);
    print_logarithm(z);
    printf("the distance is %f\n", distance(3.0, 0.0, 0.0, 4.0));
    double radius = distance(3.0, 0.0, 0.0, 4.0);
    double area = circle_area(radius);
    printf("The circle area is %f\n", area);
    printf("The gcd of %d and %d is %d.\n", a, b, gcd(b, a));
    printf("fib %d is %d.\n", 5, fib(5));
    int n = 1;
    int result = 0;
    while (n < 100)
    {
        if (get_dec(n) == 9) {
            result = result + 1;
        }
        else if (get_unit(n) == 9)
        {
            result = result + 1;
        }
        n = n + 1;
        
    }
    printf("The num of 9 is %d.\n", result);
    
    return 0;
}