#include <bits/stdc++.h>
#include <cmath>
#include <fstream>
using namespace std;

double func(double x)
{
    return 1 / (1 + (x * x));
}

double dif1(double x)
{
    double y = pow((1 + x * x), 2);
    return -2 * x / (y);
}

double diff2(double x)
{
    double y1 = pow((1 + x * x), 2);
    double y2 = pow((1 + x * x), 3);
    return (-2 * y1 + 8 * x * x * (1 + x * x)) / y2;
}

int main()
{
    // Open input and output files
    ifstream input("../Input/input.txt");
    ofstream output("../Output/output.txt");
    
    if (!input) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }
    if (!output) {
        cerr << "Error: Could not open output file!" << endl;
        return 1;
    }

    double b, a, n, p;
    input >> b >> a >> n >> p;
    double h = (b - a) / n;
    
    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++)
    {
        X[i] = a + i * h;
        Y[i] = func(a + i * h);
    }
    vector<vector<double>> table(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++)
    {
        table[i][0] = Y[i];
    }

    // used forward interpolation 
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1];
        }
    }
    //difference table
    output<<"Difference Table:"<<endl;
    for (int i = 0; i < n; i++)
    {
        output << fixed << setprecision(4);
        for (int j = 0; j < n - i; j++)
        {
            output << setw(12) << table[i][j];
        }
        output << "\n";
    }
    
    // Forward Interpolation (for points near the beginning)
    double u=(p-a)/h;
    double del1=table[0][1];
    double del2=table[0][2];
    double del3=table[0][3];
    double del4=table[0][4];
   
    double di1=del1+ ((2*u-1)*del2)/2 + ((3*u*u-6*u+2)*del3)/6 + ((4*pow(u,3)-18*u*u+22*u-6)*del4)/24;
    di1/=h;
  
    double di2=del2+((u-1)*del3)+((11*u*u-23*u+10)*del4)/12;
    di2/=(h*h);
    double true1=dif1(p);
    double true2=diff2(p);
    double error1=abs((true1-di1)/true1)*100;
    double error2=abs((true2-di2)/true2)*100;
    output<<"\nForward Interpolation:\n";
    output<<"1st derivative True value:"<<true1<<"\n";
    output<<"1st derivative calculated:"<<di1<<"\n";
    output<<"Error:"<<error1<<"%\n";
    output<<"2nd derivative True value:"<<true2<<"\n";
    output<<"2nd derivative calculated:"<<di2<<"\n";
    output<<"Error:"<<error2<<"%\n";
    /*
    Backward Interpolation (for points near the end)
    //where v = (xn - p)/h
    double v = (b - p) / h;  // v should be between 0 and 1 for accuracy
    int last = n - 1;
    double nabla1 = table[last][1];     // ∇fn
    double nabla2 = table[last-1][2];   // ∇²fn
    double nabla3 = table[last-2][3];   // ∇³fn
    double nabla4 = table[last-3][4];   // ∇⁴fn
    
    double di1_back = nabla1 + ((2*v+1)*nabla2)/2 + ((3*v*v+6*v+2)*nabla3)/6 + ((4*pow(v,3)+18*v*v+22*v+6)*nabla4)/24;
    di1_back /= h;
    
    double di2_back = nabla2 + ((v+1)*nabla3) + ((11*v*v+23*v+10)*nabla4)/12;
    di2_back /= (h*h);
    double error1_back = abs((true1-di1_back)/true1)*100;
    double error2_back = abs((true2-di2_back)/true2)*100;
    output<<"\nBackward Interpolation:\n";
    output<<"1st derivative True value:"<<true1<<"\n";
    output<<"1st derivative calculated:"<<di1_back<<"\n";
    output<<"Error:"<<error1_back<<"%\n";
    output<<"2nd derivative True value:"<<true2<<"\n";
    output<<"2nd derivative calculated:"<<di2_back<<"\n";
    output<<"Error:"<<error2_back<<"%\n";
    */

    // Close files
    input.close();
    output.close();

    return 0;
}
