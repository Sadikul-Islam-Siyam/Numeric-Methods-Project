# Newton-Raphson Method

## Theory

The Newton-Raphson Method is a powerful root-finding algorithm that uses the tangent line at a point to approximate the root. If f(x) is a **real and continuously differentiable function**, the Newton-Raphson method is used to find a root of the equation f(x) = 0.

### Mathematical Condition:
Let the initial approximation to the root be x₀. A better approximation x₁ is obtained using the formula:
```
x₁ = x₀ - f(x₀) / f'(x₀)
```

This process is repeated iteratively as:
```
xₙ₊₁ = xₙ - f(xₙ) / f'(xₙ)
```

The iteration continues until the difference between two successive values of x becomes sufficiently small.

![Newton-Raphson Method Illustration](../../RESOURCES/Newton%20Raphson.png)

### Algorithm:

**Step 1:** Find f'(xₙ)

**Step 2:** Choose 2 real numbers a and b such that f(a) × f(b) < 0 and stopping criterion E. If such a and b do not exist, then randomly guess a.

**Step 3:** Assume x₀ = a

**Step 4:** Find xₙ₊₁

**Step 5:** If |xₙ₊₁ - xₙ| < E, then the root is xₙ₊₁ and stop.
         Otherwise, set xₙ = xₙ₊₁ and repeat the iteration.

### Newton-Raphson Formula:
```
xₙ₊₁ = xₙ - f(xₙ) / f'(xₙ)
```

Where:
- x₀ is the initial approximation
- f'(xₙ) is the derivative of the function at xₙ
- The formula uses the tangent line to find the next approximation

### Conditions for Convergence:
- f(x) must be continuous and differentiable in the neighborhood of the root
- The first derivative f'(x) should not be zero near the root
- The initial guess x₀ should be sufficiently close to the actual root

### Convergence:
- Quadratic convergence when close to the root
- Very fast convergence rate when conditions are met
- Stops when the difference between successive iterations is less than error tolerance

---

## Input/Output Example

### Input Format:
```
x0
step
tol
maxIter
```

### Input:
```
1.3
0.00001
0.00001
100
```
**Explanation:**
- Line 1: Initial guess x₀ = 1.3
- Line 2: Step tolerance = 0.00001
- Line 3: Function value tolerance = 0.00001
- Line 4: Maximum iterations = 100

### Output:
```
The equation is: f(x) = e^(-x) * cos(x)

Initial guess (x0): 1.3
Step tolerance: 1e-005
Function value tolerance: 1e-005
Maximum iterations: 100


Root found: 1.570789
Number of iterations: 3
```
**Explanation:**
- Function: f(x) = e⁻ˣ × cos(x)
- Root found: x ≈ 1.570789 (approximately π/2)
- Converged in only 3 iterations (very fast!)
- Newton-Raphson's quadratic convergence demonstrated

---


## Code Constraints:

- **Input Format**: Must provide exactly 4 values: x0, step, tol, maxIter
- **Initial Guess**: x0 should be close to the actual root for convergence
- **Tolerances**: step > 0 and tol > 0 (positive values required)
- **Maximum Iterations**: maxIter > 0 (typically 100 or more)
- **Derivative Constraint**: f'(x) ≠ 0 in the neighborhood of the root
- **Function Continuity**: Function must be continuous and differentiable near the root
- **File Dependency**: Requires input.txt in ../Input/ directory
