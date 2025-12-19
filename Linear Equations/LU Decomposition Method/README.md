# LU Decomposition Method

## Theory

LU Decomposition (also called LU Factorization) is a matrix factorization method that decomposes a square matrix A into the product of a lower triangular matrix (L) and an upper triangular matrix (U). This decomposition is particularly efficient when solving multiple systems with the same coefficient matrix but different right-hand side vectors.

### Mathematical Basis:
For a system Ax = b, we factorize A as:
```
A = L × U
```

Where:
- **L** = Lower triangular matrix (elements above diagonal are 0)
- **U** = Upper triangular matrix (elements below diagonal are 0)
- **Diagonal of L** = 1 (Doolittle's method)

### Decomposition Structure:
```
[a₁₁ a₁₂ a₁₃]   [1   0   0 ]   [u₁₁ u₁₂ u₁₃]
[a₂₁ a₂₂ a₂₃] = [l₂₁ 1   0 ] × [0   u₂₂ u₂₃]
[a₃₁ a₃₂ a₃₃]   [l₃₁ l₃₂ 1 ]   [0   0   u₃₃]
```

### Solution Process:
Once A = LU is obtained, solving AX = B becomes:
```
LUX = B
```

**Step 1**: Solve LY = B (Forward Substitution)
- y₁ = b₁
- y₂ = b₂ - l₂₁y₁
- y₃ = b₃ - l₃₁y₁ - l₃₂y₂
- etc.

**Step 2**: Solve UX = Y (Backward Substitution)
- xₙ = yₙ / uₙₙ
- xₙ₋₁ = (yₙ₋₁ - uₙ₋₁,ₙxₙ) / uₙ₋₁,ₙ₋₁
- etc.

### Algorithm:

**Phase 1: LU Decomposition (Doolittle's Method)**

For i = 0 to n-1:
  - For j = i+1 to n-1:
    - Calculate multiplier: factor = U[j][i] / U[i][i]
    - Store in L: L[j][i] = factor
    - Update U: U[j][k] = U[j][k] - factor × U[i][k] for k = i to n-1
  - Set diagonal: L[i][i] = 1

**Phase 2: Forward Substitution (LY = B)**

For i = 0 to n-1:
  - y[i] = b[i]
  - For j = 0 to i-1:
    - y[i] = y[i] - L[i][j] × y[j]

**Phase 3: Backward Substitution (UX = Y)**

For i = n-1 down to 0:
  - x[i] = y[i]
  - For j = i+1 to n-1:
    - x[i] = x[i] - U[i][j] × x[j]
  - x[i] = x[i] / U[i][i]


---

## Input/Output Example

### Input Format:
```
n
a₁₁ a₁₂ ... a₁ₙ
a₂₁ a₂₂ ... a₂ₙ
...
aₙ₁ aₙ₂ ... aₙₙ
b₁
b₂
...
bₙ
```

### Input:
```
3
2 1 1
3 2 3
1 4 9
10
18
16
```
**Explanation:**
- n = 3 (3×3 matrix)
- Matrix A and vector b:
  - 2x₁ + x₂ + x₃ = 10
  - 3x₁ + 2x₂ + 3x₃ = 18
  - x₁ + 4x₂ + 9x₃ = 16

### Output:
```
Matrix size: 3

Matrix A:
     2.000      1.000      1.000 
     3.000      2.000      3.000 
     1.000      4.000      9.000 

Vector b:
    10.000 
    18.000 
    16.000 

Lower (L) Matrix:
     1.000      0.000      0.000 
     1.500      1.000      0.000 
     0.500      7.000      1.000 

Upper (U) Matrix:
     2.000      1.000      1.000 
     0.000      0.500      1.500 
     0.000      0.000     -2.000 

Solution Vector (x):
x1 = 1.000
x2 = 2.000
x3 = 3.000
```
**Explanation:**
- Matrix A successfully decomposed into L and U
- Verification: L × U = A
- Solution found: x₁ = 1, x₂ = 2, x₃ = 3
- Forward substitution solved LY = B
- Backward substitution solved UX = Y to get x

---

## Code Constraints:

- **Input Format**: 
  - Line 1: n (matrix size)
  - Next n lines: n values each (matrix A)
  - Next n lines: 1 value each (vector b)
- **Square Matrix**: Must be n×n matrix
- **Non-Singular**: Matrix must be invertible (det(A) ≠ 0)
- **Pivot Elements**: Diagonal elements of U must be non-zero
- **File Dependency**: Requires ../Input/input.txt
- **Matrix Size**: n ≥ 1
