<h1 style='text-align: center;'> A. Distinct Buttons</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Deemo - Entrance](https://soundcloud.com/iceloki/entrance-deemo)⠀You are located at the point $(0, 0)$ of an infinite Cartesian plane. You have a controller with $4$ buttons which can perform one of the following operations:

* $\texttt{U}$: move from $(x, y)$ to $(x, y+1)$;
* $\texttt{R}$: move from $(x, y)$ to $(x+1, y)$;
* $\texttt{D}$: move from $(x, y)$ to $(x, y-1)$;
* $\texttt{L}$: move from $(x, y)$ to $(x-1, y)$.

Unfortunately, the controller is broken. If you press all the $4$ buttons (in any order), the controller stops working. It means that, during the whole trip, you can only press at most $3$ distinct buttons (any number of times, in any order).

There are $n$ special points in the plane, with integer coordinates $(x_i, y_i)$.

Can you visit all the special points (in any order) without breaking the controller?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the number of special points.

Each of the next $n$ lines contains two integers $x_i$, $y_i$ ($-100 \leq x_i, y_i \leq 100$), which represent the special point $(x_i, y_i)$.

## Note

 that there are no constraints on the sum of $n$ over all test cases.

## Output

For each test case, output "YES" (without quotes), if you can reach all the special points without breaking the controller, and "NO" (without quotes) otherwise.

You may output each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

## Example

## Input


```

631 -10 01 -14-3 -2-3 -1-3 0-3 141 1-1 -11 -1-1 16-4 14-9 -13-14 514 15-8 -419 9682 6439 913 4687 8374 217 251100 -100
```
## Output


```

YES
YES
NO
NO
YES
YES

```
## Note

In the first test case, you can move as follows: 

* you start from $(0, 0)$;
* you visit the special point $(x_2, y_2) = (0, 0)$;
* you press $\texttt{R}$, and you move from $(0, 0)$ to $(1, 0)$;
* you press $\texttt{D}$, and you move from $(1, 0)$ to $(1, -1)$;
* you visit the special point $(x_1, y_1) = (1, -1)$;
* you visit the special point $(x_3, y_3) = (1, -1)$.

Therefore, you can visit all the special points using only the buttons $\texttt{R}$, $\texttt{D}$, so the controller does not break.

## Note

 that the special points may coincide.

In the second test case, you can show that you can visit all the special points using only the buttons $\texttt{U}$, $\texttt{D}$, $\texttt{L}$.

In the third test case, you can show that you must press all the buttons ($\texttt{U}$, $\texttt{R}$, $\texttt{D}$, $\texttt{L}$) to visit all the points, so the controller would break.



#### tags 

#800 #implementation #math 