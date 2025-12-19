#include <bits/stdc++.h>
using namespace std;

long double f(long double x)
{
    // equation: x^3 + x - 1
    return pow(x, 3) + x - 1;
}

int main()
{
    // Open input and output files
    ifstream input("../Input/input.txt");
    ofstream output("../Output/output.txt");
    
    if(!input.is_open())
    {
        return 1;
    }
    
    // Reading initial guesses and tolerance(E) from input file
    long double x1, x2, E;
    int maxIter;
    input >> x1 >> x2 >> E >> maxIter;
    
    output << "The equation is: f(x) = x^3 + x - 1" << endl;
    output << endl;
    output << "Initial guesses: x1 = " << x1 << ", x2 = " << x2 << endl;
    output << "Error tolerance(E): " << E << endl;
    output << "Maximum iterations: " << maxIter << endl;
    output << endl;
    output << fixed << setprecision(6);
    
    if(f(x1) * f(x2) >= 0)
    {
        output << "Error: Cannot find a root in the given interval" << endl;
        output << "f(x1) and f(x2) must have opposite signs" << endl;
        input.close();
        output.close();
        return 0;
    }
    
    long double x0, xm;
    int n = 0;
    
    do {
        n++;
        
        // Calculating the intermediate value using secant formula
        x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        
        output << "Iteration " << n << ": x1 = " << x1 << ", x2 = " << x2;
        output << ", x0 = " << x0 << ", f(x0) = " << f(x0) << endl;
        
        // Checking if x0 is the root of equation
        if(f(x0) == 0)
        {
            break;
        }
       
        x1 = x2;
        x2 = x0;
        
        // Checking for maximum iterations
        if(n >= maxIter)
        {
            output << endl;
            output << "Maximum iterations reached" << endl;
            output << "Approximate root: " << x0 << endl;
            input.close();
            output.close();
            return 0;
        }
        
        xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        
    } while(fabs(xm - x0) >= E);
    
    output << endl;
    output << "Root found: " << x0 << endl;
    output << "Number of iterations: " << n << endl;
    
    input.close();
    output.close();
    
    return 0;
}
