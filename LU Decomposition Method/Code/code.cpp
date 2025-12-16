#include <bits/stdc++.h>
using namespace std;

// Function to print any matrix
void printMatrix(const vector<vector<double>>& mat, const string& name, ofstream& outFile) {
    cout << "\n" << name << " Matrix:\n";
    outFile << "\n" << name << " Matrix:\n";
    for (auto &row : mat) {
        for (auto &val : row) {
            cout << setw(10) << fixed << setprecision(3) << val << " ";
            outFile << setw(10) << fixed << setprecision(3) << val << " ";
        }
        cout << "\n";
        outFile << "\n";
    }
}

int main() {
    // Open input and output files
    ifstream inputFile("../Input/input.txt");
    ofstream outputFile("../Output/output.txt");
    
    if (!inputFile) {
        cerr << "Error opening input.txt\n";
        return 1;
    }
    
    int n;
    cout << "Enter matrix size n: ";
    cin >> n;
    inputFile >> n;
    outputFile << "Matrix size: " << n << "\n\n";

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Enter " << n << "x" << n << " matrix A:\n";
    outputFile << "Matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            inputFile >> A[i][j];
            outputFile << setw(10) << fixed << setprecision(3) << A[i][j] << " ";
        }
        outputFile << "\n";
    }

    vector<double> b(n);
    cout << "Enter b vector (" << n << " values): ";
    outputFile << "\nVector b:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        inputFile >> b[i];
        outputFile << setw(10) << fixed << setprecision(3) << b[i] << "\n";
    }

    // Initialize L and U
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U = A;

    // Set diagonal of L = 1
    for (int i = 0; i < n; i++)
        L[i][i] = 1;

    // Gaussian elimination process
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double factor = U[j][i] / U[i][i];
            L[j][i] = factor; // Store multiplier in L

            for (int k = i; k < n; k++)
                U[j][k] -= factor * U[i][k];
        }
    }

    // Print intermediate results
    printMatrix(L, "Lower (L)", outputFile);
    printMatrix(U, "Upper (U)", outputFile);

    // Step 1: Solve Ly = b (Forward substitution)
    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
        // since L[i][i] = 1
    }

    // Step 2: Solve Ux = y (Backward substitution)
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }

    // Print results
    cout << "\nSolution Vector (x):\n";
    outputFile << "\nSolution Vector (x):\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(3) << x[i] << "\n";
        outputFile << "x" << i + 1 << " = " << fixed << setprecision(3) << x[i] << "\n";
    }

    inputFile.close();
    outputFile.close();
    cout << "\nResults written to output.txt\n";
    
    return 0;
}
/*

3
2 1 1
3 2 3
1 4 9
10 18 16

*/
