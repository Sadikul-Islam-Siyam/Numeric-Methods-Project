#include <bits/stdc++.h>

using namespace std;

// Function to be integrated: f(x) = 1/(1+x^2)
double y(double x)
{
    return 1/(1+x*x);
}

int main()
{
    // Open input file
    ifstream input("../Input/input.txt");
    ofstream output("../Output/output.txt");
    
    double a, b;
    int n;
    
    // Read from input file
    input >> n >> a >> b;
    
    double h = (b - a) / n;
    output << "f(x) = 1/(1+x^2)" << endl;
    output << "a = " << a << ", b = " << b << ", n = " << n << ", h = " << h << endl;
    
    double y1, y2 = 0, y3 = 0;
    
    y1 = y(a) + y(b);
    double a1 = a + h;
    //simsons method
    for(int i = 1; i < n; i++)
    {
        if((i % 2) == 1)
        {
            y2 += y(a1);
        }
        if((i % 2) == 0)
        {
            y3 += y(a1);
        }
        a1 += h;
    }
    
    double ans = (h / 3) * (y1 + 4 * y2 + 2 * y3);
    
    output << "Result = " << fixed << setprecision(6) << ans << endl;
    
    input.close();
    output.close();
    
    return 0;
}
