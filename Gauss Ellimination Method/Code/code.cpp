#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Open input and output files
    ifstream input("../Input/input.txt");
    ofstream output("../Output/output.txt");
    
    if(!input.is_open())
    {
        return 1;
    }
    
    int n;
    input>>n;
    vector<vector<double>>mat(n+1,vector<double>(n+2));
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+2; j++)
        {
            input>>mat[i][j];
        }
    }
    
    // Display equations
    output<<"Given System of Equations:"<<endl;
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n; j++)
        {
            output<<"("<<mat[i][j]<<"x"<<j<<") + ";
        }
        output<<"("<<mat[i][n]<<"x"<<n<<") = "<<mat[i][n+1]<<endl;
    }
    output<<endl;
    
    int m=n+1;
    
    // Forward elimination
    for(int i=1; i<=n; i++)
    {
        // Partial pivoting
        int pivot=i;
        for(int j=i+1; j<=n; j++)
        {
            if(abs(mat[j][i])>abs(mat[pivot][i]))
            {
                pivot=j;
            }
        }
        swap(mat[i],mat[pivot]);
        
        if(abs(mat[i][i])<1e-9)
        {
            output<<"Solution Type: NO UNIQUE SOLUTION"<<endl;
            output<<"The system does not have a unique solution."<<endl;
            input.close();
            output.close();
            return 0;
        }
        
        // Eliminate below pivot
        for(int j=i+1; j<=n; j++)
        {
            double factor=mat[j][i]/mat[i][i];
            for(int k=i; k<=m; k++)
            {
                mat[j][k]-=factor*mat[i][k];
            }
        }
    }
    
    // Back substitution
    vector<double>ans(n+1);
    for(int i=n; i>=1; i--)
    {
        ans[i]=mat[i][m];
        for(int j=i+1; j<=n; j++)
        {
            ans[i]-=ans[j]*mat[i][j];
        }
        ans[i]/=mat[i][i];
    }
    
    // Output solution
    output<<"Solution Type: UNIQUE SOLUTION"<<endl;
    output<<endl;
    output<<"Solution:"<<endl;
    for(int i=1; i<=n; i++)
    {
        output<<"x"<<i<<" = "<<fixed<<setprecision(6)<<ans[i]<<endl;
    }
    
    input.close();
    output.close();
    
    return 0;
}
