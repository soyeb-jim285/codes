<h1 style='text-align: center;'> A. Plus or Minus</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $a$, $b$, and $c$ such that exactly one of these two equations is true: 

* $a+b=c$
* $a-b=c$

 ## Output

 + if the first equation is true, and - otherwise.## Input

The first line contains a single integer $t$ ($1 \leq t \leq 162$) — the number of test cases.

The description of each test case consists of three integers $a$, $b$, $c$ ($1 \leq a, b \leq 9$, $-8 \leq c \leq 18$). The additional constraint on the input: it will be generated so that exactly one of the two equations will be true.

## Output

For each test case, output either + or - on a new line, representing the correct equation.

## Example

## Input


```

111 2 33 2 12 9 -73 4 71 1 21 1 03 3 69 9 189 9 01 9 -81 9 10
```
## Output


```

+
-
-
+
+
-
+
+
-
-
+

```
## Note

In the first test case, $1+2=3$.

In the second test case, $3-2=1$.

In the third test case, $2-9=-7$. ## Note

 that $c$ can be negative.



#### tags 

#800 #implementation 