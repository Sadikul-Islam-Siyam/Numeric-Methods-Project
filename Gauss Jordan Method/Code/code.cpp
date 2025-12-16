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
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n;j++)
        {
            output<<"("<<mat[i][j]<<"x"<<j<<") + ";
        }
        output<<"("<<mat[i][n]<<"x"<<n<<") = "<<mat[i][n+1]<<endl;
    }
    output<<endl;
    
    int m=n+1;
    int rank = 0;
    bool hasNoSolution = false;
    
    // Gauss-Jordan Elimination with solution type detection
    for(int i=1; i<=n; i++)
    {
        // Find pivot
        int pivot=i;
        for(int j=i+1; j<=n; j++)
        {
            if(abs(mat[j][i])>abs(mat[pivot][i]))
            {
                pivot=j;
            }
        }
        swap(mat[i],mat[pivot]);
        
        // Check if pivot is zero
        if(abs(mat[i][i])<1e-9)
        {
            // Check if this row has non-zero RHS (inconsistent system)
            bool allZero = true;
            for(int k=i; k<=n; k++)
            {
                if(abs(mat[i][k])>1e-9)
                {
                    allZero = false;
                    break;
                }
            }
            
            if(allZero && abs(mat[i][m])>1e-9)
            {
                // 0 = non-zero (no solution)
                hasNoSolution = true;
                break;
            }
            else if(allZero && abs(mat[i][m])<1e-9)
            {
                // 0 = 0 (dependent equation, might have infinite solutions)
                continue;
            }
            else
            {
                // Try to find a non-zero element in this row
                bool found = false;
                for(int j=i+1; j<=n; j++)
                {
                    if(abs(mat[i][j])>1e-9)
                    {
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    continue;
                }
            }
        }
        
        rank++;
        
        // Normalize pivot row
        double pele=mat[i][i];
        for(int k=1; k<=m; k++)
        {
            mat[i][k]/=pele;
        }
        
        // Eliminate column
        for(int j=1; j<=n; j++)
        {
            if(i==j)continue;
            double factor=mat[j][i];
            for(int k=1; k<=m; k++)
            {
                mat[j][k]-=factor*mat[i][k];
            }
        }
    }
    
    // Check for no solution
    if(hasNoSolution)
    {
        output<<"Solution Type: NO SOLUTION (Inconsistent System)"<<endl;
        output<<"The system of equations is inconsistent and has no solution."<<endl;
    }
    else if(rank < n)
    {
        // Infinite solutions
        output<<"Solution Type: INFINITE SOLUTIONS"<<endl;
        output<<"The system has infinitely many solutions (rank = "<<rank<<" < "<<n<<")."<<endl;
        output<<"One possible solution set:"<<endl;
        
        vector<double>ans(n+1);
        for(int i=1; i<=n; i++)
        {
            ans[i]=mat[i][m];
        }
        for(int i=1; i<=n; i++)
        {
            output<<"x"<<i<<" = "<<fixed<<setprecision(6)<<ans[i]<<endl;
        }
    }
    else
    {
        // Unique solution
        output<<"Solution Type: UNIQUE SOLUTION"<<endl;
        output<<endl;
        
        vector<double>ans(n+1);
        for(int i=1; i<=n; i++)
        {
            ans[i]=mat[i][m];
        }
        
        output<<"Solution:"<<endl;
        for(int i=1; i<=n; i++)
        {
            output<<"x"<<i<<" = "<<fixed<<setprecision(6)<<ans[i]<<endl;
        }
    }
    
    input.close();
    output.close();
    
    return 0;
}
