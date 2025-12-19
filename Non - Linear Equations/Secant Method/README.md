# Secant Method

## Theory

The Secant Method is a root-finding algorithm similar to Newton-Raphson Method, but instead of using the derivative f'(x), it approximates the derivative using two points. This method avoids the need to calculate derivatives analytically, making it useful when derivatives are difficult or impossible to compute.

### Mathematical Condition:
The Secant Method uses two initial approximations x₀ and x₁ to find the root. The next approximation is calculated using the secant line (the line passing through two points on the curve) instead of the tangent line.

The formula is derived by approximating the derivative:
```
f'(xₙ) ≈ [f(xₙ) - f(xₙ₋₁)] / (xₙ - xₙ₋₁)
```

![Secant Method Illustration](../../RESOURCES/Secant.png)

### Algorithm:

**Step 1:** Choose 2 initial guesses x₀ and x₁, and stopping criterion E.

**Step 2:** Calculate the next approximation:
```
xₙ₊₁ = xₙ - f(xₙ) × (xₙ - xₙ₋₁) / (f(xₙ) - f(xₙ₋₁))
```

**Step 3:** Find f(xₙ₊₁)

**Step 4:** Check if |xₙ₊₁ - xₙ| < E or |f(xₙ₊₁)| < E, then the root is xₙ₊₁ and **Stop**

**Step 5:** Update: xₙ₋₁ = xₙ, xₙ = xₙ₊₁ and return to **Step 2**

### Secant Method Formula:
```
xₙ₊₁ = xₙ - f(xₙ) × (xₙ - xₙ₋₁) / (f(xₙ) - f(xₙ₋₁))
```

Where:
- x₀ and x₁ are two initial approximations
- The formula uses a secant line instead of a tangent line
- No derivative calculation is required

### Convergence:
- Superlinear convergence (between linear and quadratic)
- Convergence rate is approximately 1.618 (golden ratio)
- Slightly slower than Newton-Raphson but faster than Bisection and False Position
- Stops when the difference between successive iterations is less than error tolerance
---


## Input/Output Example

### Input Format:
```
x1
x2
E
maxIter
```

### Input:
```
0
1
0.0001
100
```
**Explanation:**
- Line 1: First initial guess x₁ = 0
- Line 2: Second initial guess x₂ = 1
- Line 3: Error tolerance E = 0.0001
- Line 4: Maximum iterations = 100

### Output:
```
The equation is: f(x) = x^3 + x - 1

Initial guesses: x1 = 0, x2 = 1
Error tolerance(E): 0.0001
Maximum iterations: 100

Iteration 1: x1 = 0.000000, x2 = 1.000000, x0 = 0.500000, f(x0) = -0.375000
Iteration 2: x1 = 1.000000, x2 = 0.500000, x0 = 0.636364, f(x0) = -0.105935
Iteration 3: x1 = 0.500000, x2 = 0.636364, x0 = 0.690052, f(x0) = 0.018636
Iteration 4: x1 = 0.636364, x2 = 0.690052, x0 = 0.682020, f(x0) = -0.000737
Iteration 5: x1 = 0.690052, x2 = 0.682020, x0 = 0.682326, f(x0) = -0.000005

Root found: 0.682326
Number of iterations: 5
```
**Explanation:**
- Function: f(x) = x³ + x - 1
- Root found: x ≈ 0.682326
- Converged in 5 iterations
- Shows rapid convergence without needing derivatives
- Each iteration shows the progression of x₀ values
---
## Code Constraints:

- **Input Format**: Must provide exactly 4 values: x1, x2, E, maxIter
- **Sign Constraint**: f(x1) × f(x2) < 0 (opposite signs required for convergence)
- **Error Tolerance**: E > 0 (positive value required)
- **Maximum Iterations**: maxIter > 0 (typically 100 or more)
- **Function Values**: f(x2) ≠ f(x1) to avoid division by zero
- **Initial Guesses**: x1 ≠ x2 (different values required)
- **File Dependency**: Requires input.txt in ../Input/ directory
- **Convergence Region**: Initial guesses should be  close to the actual root

