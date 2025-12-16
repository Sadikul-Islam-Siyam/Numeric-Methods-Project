#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "InverseMatrix.h"

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input.txt" << endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        cerr << "Error opening output.txt" << endl;
        return 1;
    }

    int n;
    // Read size of matrix A
    if (!(inputFile >> n)) {
        outputFile << "Error reading size of matrix." << endl;
        return 1;
    }

    vector<vector<double>> A(n, vector<double>(n));
    // Read matrix A elements
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            inputFile >> A[i][j];

    // Read vector b for Ax=b
    vector<double> b(n);
    for(int i = 0; i < n; i++) inputFile >> b[i];

    vector<vector<double>> inv;

    if(invMat(A, inv)) {
        outputFile << "Inverse matrix:\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                outputFile << fixed << setprecision(5) << inv[i][j] << " ";
            outputFile << "\n";
        }

        // Solve Ax = b
        vector<double> x = getSolution(inv, b);

        outputFile << "\nSolution vector x:\n";
        for(double v : x)
            outputFile << fixed << setprecision(5) << v << " ";
        outputFile << "\n";

    } else {
        outputFile << "Matrix is singular and cannot be inverted.\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Processing complete. Check output.txt for results." << endl;

    return 0;
}
