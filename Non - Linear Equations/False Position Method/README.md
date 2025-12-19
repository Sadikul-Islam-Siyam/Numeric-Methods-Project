# False Position Method (Regula Falsi)

## Theory

The False Position Method (*Regula Falsi* method in Latin) is also known as the Linear Interpolation Method. It is a root-finding algorithm similar to the Bisection Method, but instead of using the midpoint, it uses a weighted average based on function values to find a better approximation.

### Mathematical Condition:
If f(x) is real and continuous in the interval a < x < b, and f(a) and f(b) are of opposite sign, that is:
```
f(a) × f(b) < 0
```
Then there is at least one real root in the interval between a and b.

![False Position Method Illustration](../../RESOURCES/False%20Position.png)

### Algorithm:

**Step 1:** Choose 2 real numbers x₁ and x₂ such that f(x₁) × f(x₂) < 0 and stopping criterion E.

**Step 2:** Define root x₀ = x₁ - f(x₁) × (x₂ - x₁) / (f(x₂) - f(x₁))

**Step 3:** Find f(x₀)

**Step 4:** Check the following conditions:
- If f(x₀) = 0, then the root is x₀ → **Stop**
- If f(x₀) × f(x₁) < 0, then root is between x₀ and x₁, so set x₂ = x₀
- If f(x₀) × f(x₂) < 0, then root is between x₀ and x₂, so set x₁ = x₀

**Step 5:** Return to **Step 2** until finding abs((x₂ - x₁) / x₂) < E

### False Position Formula:
```
x₀ = x₁ - f(x₁) × (x₂ - x₁) / (f(x₂) - f(x₁))
```

Where:
- x₁ = a and x₂ = b
- x₀ is the point where the line connecting (x₁, f(x₁)) and (x₂, f(x₂)) crosses the x-axis

### Convergence:
- Generally faster than Bisection Method
- Convergence is guaranteed if initial conditions are met
- Uses linear interpolation to get better approximation
- Stops when the interval size is less than the error tolerance

### Advantages:
- Faster convergence than Bisection Method
- More accurate root approximation at each iteration
- Does not require derivative calculation
- Guaranteed to find a root if one exists in the interval
- Better approximation using function values

### Disadvantages:
- Can be slower than other methods in some cases
- May converge slowly if one endpoint remains fixed
- Requires two initial guesses with opposite signs
- One end of the interval may remain stationary for many iterations

---

## Implementation Details
### How the Code Works:

1. **Input Reading**: Reads 4 coefficients (an1, an2, an3, an4), error tolerance (e), and step size (h) from input file
2. **Range Detection**: Automatically finds all intervals where f(a)×f(b) < 0 within [-xmax, xmax]
3. **Root Finding**: Applies False Position method to each detected interval:
   - Calculates intersection point: c = b - f(b)×(b-a)/(f(b)-f(a))
   - Checks which half contains the root based on sign change
   - Repeats until |b - a|/2 < e
4. **Output Generation**: Writes equation, ranges, roots, and iteration counts to output file

### Code Limitations:

- **Fixed Polynomial Type**: Only works for 4th degree polynomials of the form: an1×x⁴ + an2×x³ + an3×x² + an4×x
- **No Constant Term**: Missing the constant term (an5), can only find roots that pass through origin
- **Fixed Step Size**: Uses constant step size (h) for range detection, may miss roots in narrow intervals
- **Stagnant Endpoint**: One endpoint may remain fixed for many iterations causing slow convergence
- **Division by Zero**: No check for f(b) = f(a) which causes division by zero
- **Division by Zero in xmax()**: No check for an1 = 0
- **Limited Precision**: Uses long double which may have precision issues

### Code Constraints:

- **Input Format**: Must provide exactly 6 values: an1, an2, an3, an4, e, h
- **Coefficient Constraint**: an1 ≠ 0 (required for xmax calculation)
- **Error Tolerance**: e > 0 (positive value required)
- **Step Size**: h > 0 and h < |xmax|
- **Function Values**: f(b) ≠ f(a) to avoid division by zero
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
Root 1: -1.000000
Number of iterations: 36

Finding Root 2:
Root 2: 0.000000
Number of iterations: 16
```
**Explanation:**
- Found 2 roots: x = -1.0 and x = 0.0
- First root required 36 iterations (more than Bisection due to fixed endpoint)
- Second root required 16 iterations
- Both roots achieved exact values within tolerance
