<h1 style='text-align: center;'> A. From Zero To Y</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two positive (greater than zero) integers $x$ and $y$. There is a variable $k$ initially set to $0$.

You can perform the following two types of operations: 

* add $1$ to $k$ (i. e. assign $k := k + 1$);
* add $x \cdot 10^{p}$ to $k$ for some non-negative $p$ (i. e. assign $k := k + x \cdot 10^{p}$ for some $p \ge 0$).

Find the minimum number of operations described above to set the value of $k$ to $y$.

## Input

The first line contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases.

Each test case consists of one line containing two integer $x$ and $y$ ($1 \le x, y \le 10^9$).

## Output

For each test case, print one integer — the minimum number of operations to set the value of $k$ to $y$.

## Example

## Input


```

3
2 7
3 42
25 1337

```
## Output


```

4
5
20

```
## Note

In the first test case you can use the following sequence of operations: 

1. add $1$;
2. add $2 \cdot 10^0 = 2$;
3. add $2 \cdot 10^0 = 2$;
4. add $2 \cdot 10^0 = 2$.

 $1 + 2 + 2 + 2 = 7$.In the second test case you can use the following sequence of operations: 

1. add $3 \cdot 10^1 = 30$;
2. add $3 \cdot 10^0 = 3$;
3. add $3 \cdot 10^0 = 3$;
4. add $3 \cdot 10^0 = 3$;
5. add $3 \cdot 10^0 = 3$.

 $30 + 3 + 3 + 3 + 3 = 42$.

#### tags 

#900 #*special #math 