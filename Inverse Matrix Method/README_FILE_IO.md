# Inverse Matrix Method

This program calculates the inverse of a square matrix and solves the linear system $Ax = b$ using the inverse matrix.

## Files

- `main.cpp`: The main program file that handles file I/O.
- `InverseMatrix.h`: Header file containing the logic for matrix inversion and solving the system.
- `input.txt`: Input file containing the matrix size, matrix elements, and the vector $b$.
- `output.txt`: Output file where the inverse matrix and the solution vector $x$ will be written.

## Input Format (input.txt)

1.  The first line contains an integer `n`, the size of the matrix ($n \times n$).
2.  The next `n` lines contain `n` floating-point numbers each, representing the rows of matrix $A$.
3.  The following line (or lines) contains `n` floating-point numbers representing the vector $b$.

### Example

```
3
2 -1 0
-1 2 -1
0 -1 2
1 0 1
```

## Output Format (output.txt)

The output file will contain:
1.  The inverse matrix of $A$.
2.  The solution vector $x$.

## How to Run

1.  Compile the program:
    ```bash
    g++ main.cpp -o program
    ```
2.  Run the executable:
    ```bash
    ./program
    ```
3.  Check `output.txt` for the results.
