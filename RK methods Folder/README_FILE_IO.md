# Runge Kutta Method

This folder contains the implementation of the Runge-Kutta method for solving ordinary differential equations.

## Structure

- `Code/`: Contains the source code (`code.cpp`) and the executable (`program`).
- `Input/`: Contains the input file (`input.txt`).
- `Output/`: Contains the output file (`output.txt`).

## Input Format (input.txt)

The input file should contain four floating-point numbers separated by spaces:
1.  `x0`: Initial value of x.
2.  `y0`: Initial value of y.
3.  `x`: Target value of x to find y(x).
4.  `h`: Step size.

### Example

```
0.0 1.0 2.0 0.2
```

## Output Format (output.txt)

The output file will contain the initial conditions, parameters, and the calculated result.

## How to Run

1.  Navigate to the `Code` directory:
    ```bash
    cd "RK methods Folder/Code"
    ```
2.  Compile the program:
    ```bash
    g++ code.cpp -o program
    ```
3.  Run the executable:
    ```bash
    ./program
    ```
4.  Check the console output or `../Output/output.txt` for results.
