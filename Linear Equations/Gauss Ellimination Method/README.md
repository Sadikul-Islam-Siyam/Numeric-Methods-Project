# Gauss Elimination Method

## Theory

The Gauss Elimination Method (also known as Gaussian Elimination) is a systematic method for solving systems of linear equations. It transforms the augmented matrix [A | B] into an upper triangular form through forward elimination, then uses back substitution to find the solution.

### Mathematical Basis:
For a system of n linear equations with n unknowns:
```
a₁₁x₁ + a₁₂x₂ + ... + a₁ₙxₙ = b₁
a₂₁x₁ + a₂₂x₂ + ... + a₂ₙxₙ = b₂
...
aₙ₁x₁ + aₙ₂x₂ + ... + aₙₙxₙ = bₙ
```

The method transforms this into upper triangular form:
```
u₁₁x₁ + u₁₂x₂ + ... + u₁ₙxₙ = b'₁
        u₂₂x₂ + ... + u₂ₙxₙ = b'₂
                        .
                        .
                        .
                      uₙₙxₙ = b'ₙ
```

### Algorithm:

**Step 1: Forward Elimination**
- For each pivot row i (from 1 to n-1):
  - Apply **partial pivoting**: Find the row with maximum |aᵢⱼ| and swap rows
  - For each row j below pivot (from i+1 to n):
    - Calculate factor: mⱼᵢ = aⱼᵢ / aᵢᵢ
    - Subtract mⱼᵢ times row i from row j
    - This creates zeros below the diagonal

**Step 2: Check for Solutions**
- If any diagonal element is zero, check for:
  - No solution (inconsistent system)
  - Infinite solutions (dependent equations)

**Step 3: Back Substitution**
- Start from last equation: xₙ = b'ₙ / uₙₙ
- For i = n-1 down to 1:
  - xᵢ = (b'ᵢ - Σ(uᵢⱼ × xⱼ)) / uᵢᵢ for j from i+1 to n


### Convergence:
- **Direct method**: Obtains exact solution in finite steps (ignoring round-off errors)
- **Complexity**: O(n³) for forward elimination, O(n²) for back substitution
- **Guaranteed convergence**: For non-singular matrices (det(A) ≠ 0)


---

## Input/Output Example

### Input Format:
```
n
a₁₁ a₁₂ ... a₁ₙ b₁
a₂₁ a₂₂ ... a₂ₙ b₂
...
...
aₙ₁  aₙ₂ ... aₙₙ bₙ
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
- System has unique solution
- Solution: x₁ = 2, x₂ = 3, x₃ = -1
- Verification: 
  - 2(2) + 1(3) - 1(-1) = 4 + 3 + 1 = 8 
  - -3(2) - 1(3) + 2(-1) = -6 - 3 - 2 = -11 
  - -2(2) + 1(3) + 2(-1) = -4 + 3 - 2 = -3 
---


## Code Constraints:

- **Input Format**: First line must be n, followed by n lines of n+1 values each
- **Matrix Size**: n ≥ 1 (at least one equation)
- **Non-Singular Matrix**: det(A) ≠ 0 for unique solution
- **Pivot Elements**: Must have at least one non-zero element in each column
- **File Dependency**: Requires input.txt in ../Input/ directory
- **Numerical Stability**: Very small pivot elements (<1e-9) considered as zero
