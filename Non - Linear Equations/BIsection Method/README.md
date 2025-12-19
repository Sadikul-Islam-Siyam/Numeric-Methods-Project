# Bisection Method

## Theory

The Bisection Method (also called Binary Chopping or Half-Interval Method) is a root-finding algorithm that repeatedly divides an interval in half and selects the subinterval where the root exists.

### Mathematical Condition:
If f(x) is real and continuous in the interval a < x < b, and f(a) and f(b) are of opposite sign, that is:
```
f(a) × f(b) < 0
```
Then there is at least one real root in the interval between a and b.

![Bisection Method Illustration](../../RESOURCES/Bisection.png)

### Algorithm:

**Step 1:** Choose 2 real numbers x₁ and x₂ such that f(x₁) × f(x₂) < 0 and stopping criterion E.

**Step 2:** Define root x₀ = (x₁ + x₂) / 2

**Step 3:** Find f(x₀)

**Step 4:** Check the following conditions:
- If f(x₀) = 0, then the root is x₀ → **Stop**
- If f(x₀) × f(x₁) < 0, then root is between x₀ and x₁, so set x₂ = x₀
- If f(x₀) × f(x₂) < 0, then root is between x₀ and x₂, so set x₁ = x₀

**Step 5:** Return to **Step 2** until finding abs((x₂ - x₁) / x₂) < E

### Midpoint Formula:
```
x₀ = (x₁ + x₂) / 2
```

Where:
- x₁ = a and x₂ = b
- x₀ is the midpoint between a and b

### Convergence:
- Always converges if f(a) and f(b) have opposite signs
- Convergence is guaranteed but relatively slow (linear)
- Stops when the interval size is less than the error tolerance

### Advantages:
- Simple and reliable method
- Always converges if initial conditions are met
- Guaranteed to find a root if one exists in the interval

### Disadvantages:
- Slow convergence rate compared to other methods
- Requires two initial guesses with opposite signs
- Cannot find multiple roots in the same interval
- Not efficient for functions with multiple roots

---

## Implementation Details

### How the Code Works:

1. **Input Reading**: Reads 4 coefficients (an1, an2, an3, an4), error tolerance (e), and step size (h) from input file
2. **Range Detection**: Automatically finds all intervals where f(a)×f(b) < 0 within [-xmax, xmax]
3. **Root Finding**: Applies bisection method to each detected interval:
   - Calculates midpoint c = (a + b) / 2
   - Checks which half contains the root based on sign change
   - Repeats until |b - a|/2 < e
4. **Output Generation**: Writes equation, ranges, roots, and iteration counts to output file

### Code Limitations:

- **Fixed Polynomial Type**: Only works for 4th degree polynomials of the form: an1×x⁴ + an2×x³ + an3×x² + an4×x
- **No Constant Term**: Missing the constant term (an5), can only find roots that pass through origin
- **Fixed Step Size**: Uses constant step size (h) for range detection, may miss roots in narrow intervals
- **No Multiple Roots**: Cannot detect multiple roots in the same interval
- **Division by Zero**: No check for an1 = 0 in xmax() function
- **Limited Precision**: Uses long double which may have precision issues for very small tolerances

### Code Constraints:

- **Input Format**: Must provide exactly 6 values: an1, an2, an3, an4, e, h
- **Coefficient Constraint**: an1 ≠ 0 (required for xmax calculation)
- **Error Tolerance**: e > 0 (positive value required)
- **Step Size**: h > 0 and h < |xmax| (should be small enough to detect all sign changes)
- **File Dependency**: Requires input.txt in ../Input/ directory
- **Range Limitation**: Only searches within [-xmax, xmax] interval

---

## Input/Output Example

### Input Format:
```
an1 an2 an3 an4
e
h
```

### Input:
```
1 -3 2 6
0.0001
0.5
```
**Explanation:**
- Line 1: Coefficients (1, -3, 2, 6) for f(x) = x⁴ - 3x³ + 2x² + 6x
- Line 2: Error tolerance = 0.0001
- Line 3: Step size for range detection = 0.5

### Output:
```
The equation is: f(x) = (1)x^4 + (-3)x^3 + (2)x^2 + (6)x

Error tolerance: 0.0001

Range found: [-1.23607 , -0.736068]
Range found: [-0.236068 , 0.263932]

Finding Root 1:
Root 1: -1.000106
Number of iterations: 12

Finding Root 2:
Root 2: -0.000106
Number of iterations: 12
```
**Explanation:**
- Found 2 roots: x ≈ -1.0 and x ≈ 0.0
- Each root required 12 iterations to converge
- Both roots satisfied the error tolerance condition
