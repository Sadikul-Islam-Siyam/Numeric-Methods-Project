# Gauss-Jordan Method

## Theory

The Gauss-Jordan Method is an extension of Gaussian Elimination that completely reduces the coefficient matrix to reduced row echelon form (RREF), specifically to an identity matrix. Unlike Gauss Elimination which requires back substitution, Gauss-Jordan directly provides the solution in the augmented column.

### Mathematical Basis:
For a system Ax = b, the Gauss-Jordan method transforms [A|b] into [I|x]:
```
[A | b] → [I | x]
```

Where I is the identity matrix and x is the solution vector.

### Key Difference from Gauss Elimination:
- **Gauss Elimination**: Creates upper triangular matrix, then uses back substitution
- **Gauss-Jordan**: Creates diagonal matrix (identity matrix), solution appears directly

### Algorithm:

**Step 1: Forward Elimination (Upper Triangular)**
- For each pivot row i (from 1 to n):
  - Apply partial pivoting (find maximum |aᵢⱼ| and swap rows)
  - Check if pivot is zero (singular or dependent system)
  - Eliminate all elements **below** the pivot
  - Create zeros: aⱼᵢ = 0 for all j > i

**Step 2: Backward Elimination (Diagonal)**
- For each pivot row i (from n down to 1):
  - Eliminate all elements **above** the pivot
  - Create zeros: aⱼᵢ = 0 for all j < i

**Step 3: Normalization**
- Divide each row by its diagonal element
- Create identity matrix: aᵢᵢ = 1 for all i
- The augmented column now contains the solution

### Transformation Process:
```
[A | b] → Forward Elim → [U | b'] → Backward Elim → [D | b''] → Normalize → [I | x]
```

Where:
- U = Upper triangular matrix
- D = Diagonal matrix
- I = Identity matrix
- x = Solution vector

### Solution Types Detection:

1. **Unique Solution**: rank(A) = rank([A|b]) = n
2. **No Solution**: rank(A) < rank([A|b]) (inconsistent system)
3. **Infinite Solutions**: rank(A) = rank([A|b]) < n (dependent equations)

### Convergence:
- **Direct method**: Solution obtained in finite steps
- **Complexity**: O(n³) operations (slightly more than Gauss Elimination)
- **No iteration required**: Unlike iterative methods
- **Exact solution**: Theoretically exact (ignoring round-off errors)


---

## Input/Output Example

### Input Format:
```
n
a₁₁ a₁₂ ... a₁ₙ b₁
a₂₁ a₂₂ ... a₂ₙ b₂
...
aₙ₁ aₙ₂ ...  aₙₙ bₙ
```

### Input:
```
 3
 2  1 -1  8
-3 -1  2 -11
-2  1  2 -3
```
**Explanation:**
- n = 3 (3 equations, 3 unknowns)
- System of equations:
  - 2x₁ + x₂ - x₃ = 8
  - -3x₁ - x₂ + 2x₃ = -11
  - -2x₁ + x₂ + 2x₃ = -3

### Output:
```
Given System of Equations:
(2x1) + (1x2) + (-1x3) = 8
(-3x1) + (-1x2) + (2x3) = -11
(-2x1) + (1x2) + (2x3) = -3

Solution Type: UNIQUE SOLUTION

Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000
```
**Explanation:**
- Matrix transformed from [A|b] to [I|x]
- Solution obtained directly without back substitution
- Unique solution: x₁ = 2, x₂ = 3, x₃ = -1
- Verification shows all equations satisfied

---


## Code Constraints:

- **Input Format**: First line n, then n lines of n+1 values
- **Square System**: Must have n equations and n unknowns
- **File Dependency**: Requires ../Input/input.txt
- **Numerical Threshold**: |value| < 1e-9 treated as zero
- **Matrix Size**: n ≥ 1
