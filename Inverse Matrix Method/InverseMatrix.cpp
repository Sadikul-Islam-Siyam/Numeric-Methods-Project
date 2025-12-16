#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// determinant recursively
double detRec(const vector<vector<double>> &a, int n) {
    if(n == 1) return a[0][0];
    if(n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    double det = 0;
    for(int p = 0; p < n; p++) {
        vector<vector<double>> sm(n-1, vector<double>(n-1));
        for(int i = 1; i < n; i++) {
            int cj = 0;
            for(int j = 0; j < n; j++) {
                if(j == p) continue;
                sm[i-1][cj++] = a[i][j];
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * a[0][p] * detRec(sm, n-1);
    }
    return det;
}

// adjoint recursively
void adjRec(const vector<vector<double>> &a, vector<vector<double>> &adj) {
    int n = a.size();
    if(n == 1) { adj[0][0] = 1; return; }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            vector<vector<double>> sm(n-1, vector<double>(n-1));
            int ri = 0;
            for(int r = 0; r < n; r++) {
                if(r == i) continue;
                int cj = 0;
                for(int c = 0; c < n; c++) {
                    if(c == j) continue;
                    sm[ri][cj++] = a[r][c];
                }
                ri++;
            }
            adj[j][i] = ((i+j)%2==0 ? 1 : -1) * detRec(sm, n-1);
        }
}

// inverse using adjoint/determinant
bool invMat(const vector<vector<double>> &a, vector<vector<double>> &inv) {
    int n = a.size();
    double det = detRec(a, n);
    if(det == 0) return false;

    vector<vector<double>> adj(n, vector<double>(n));
    adjRec(a, adj);

    inv.assign(n, vector<double>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / det;

    return true;
}

// New: multiply inverse × b to get solution x
vector<double> getSolution(const vector<vector<double>> &inv, const vector<double> &b) {
    int n = inv.size();
    vector<double> x(n, 0.0);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            x[i] += inv[i][j] * b[j];

    return x;
}

int main() {
    int n;
    cout << "Enter size of matrix A: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    cout << "Enter matrix A elements:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    // read vector b for Ax=b
    vector<double> b(n);
    cout << "Enter vector b (RHS values):\n";
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<double>> inv;

    if(invMat(A, inv)) {
        cout << "\nInverse matrix:\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << fixed << setprecision(5) << inv[i][j] << " ";
            cout << "\n";
        }

        // Solve Ax = b
        vector<double> x = getSolution(inv, b);

        cout << "\nSolution vector x:\n";
        for(double v : x)
            cout << fixed << setprecision(5) << v << " ";
        cout << "\n";

    } else {
        cout << "Matrix is singular and cannot be inverted.\n";
    }

    return 0;
}
