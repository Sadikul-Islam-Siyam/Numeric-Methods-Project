# Inverse Matrix Method

## Theory

The Inverse Matrix Method solves a system of linear equations AX = B by computing the inverse matrix A⁻¹ and then multiplying it with the right-hand side vector B. This method is conceptually simple but computationally expensive.

### Mathematical Basis:
Given a system of linear equations:
```
AX = B
```

If matrix A is non-singular (det(A) ≠ 0), then A⁻¹ exists, and:
```
A⁻¹AX = A⁻¹B
IX = A⁻¹B
X = A⁻¹B
```

Where:
- **A** = n×n coefficient matrix
- **X** = n×1 unknown vector
- **B** = n×1 right-hand side vector
- **A⁻¹** = inverse of matrix A
- **I** = identity matrix

### Methods to Calculate Inverse:

#### 1. **Adjoint Matrix Method (Used in this implementation)**
```
A⁻¹ = adj(A) / det(A)
```

Steps:
- Calculate determinant: det(A)
- Find matrix of minors
- Apply cofactor signs: (-1)^(i+j)
- Transpose to get adjoint: adj(A)
- Divide adjoint by determinant

#### 2. **Gauss-Jordan Elimination**
- Augment A with identity: [A | I]
- Row reduce to get: [I | A⁻¹]

#### 3. **LU Decomposition**
- Decompose: A = LU
- Solve for each column of A⁻¹

### Algorithm (Adjoint Method):

**Step 1: Calculate Determinant**
- Use recursive cofactor expansion
- For 2×2: det = a₁₁a₂₂ - a₁₂a₂₁
- For n×n: det = Σ(aᵢⱼ × cofactor(aᵢⱼ))

**Step 2: Check if Invertible**
- If |det(A)| < ε (very small), matrix is singular
- Cannot proceed if singular

**Step 3: Calculate Matrix of Cofactors**
- For each element (i,j):
  - Remove row i and column j to get minor
  - Calculate determinant of minor
  - Apply sign: (-1)^(i+j) × det(minor)

**Step 4: Transpose to Get Adjoint**
- adj(A) = [cofactor matrix]ᵀ
- Swap aᵢⱼ with aⱼᵢ

**Step 5: Calculate Inverse**
- A⁻¹ = adj(A) / det(A)
- Divide each element by determinant

**Step 6: Solve System**
- X = A⁻¹ × B
- Perform matrix-vector multiplication


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
 2 -1  0
-1  2 -1
 0 -1  2

1
0
1
```
**Explanation:**
- n = 3 (3×3 matrix)
- Matrix A (tridiagonal):
  - 2x₁ - x₂ = 1
  - -x₁ + 2x₂ - x₃ = 0
  - -x₂ + 2x₃ = 1
- Vector B = [1, 0, 1]ᵀ

### Output:
```
Inverse matrix:
0.75000 0.50000 0.25000 
0.50000 1.00000 0.50000 
0.25000 0.50000 0.75000 

Solution vector x:
1.00000 1.00000 1.00000 
```
**Explanation:**
- Successfully calculated A⁻¹
- Inverse matrix is symmetric (A was symmetric)
- Solution: x = A⁻¹B = [1, 1, 1]ᵀ
- Verification: 
  - 2(1) - 1(1) + 0(1) = 1 
  - -1(1) + 2(1) - 1(1) = 0 
  - 0(1) - 1(1) + 2(1) = 1 

---


## Code Constraints:

- **Input Format**:
  - Line 1: n (matrix size)
  - Next n lines: n values each (matrix A)
  - Next n lines: 1 value each (vector b)
- **Matrix Size**: Practical limit n ≤ 5 due to O(n!) complexity
- **Non-Singular**: det(A) must not be zero or very small
- **File Dependency**: Uses freopen for ../Input/input.txt
- **Square Matrix**: Must be n×n
- **Valid System**: Matrix must be invertible
