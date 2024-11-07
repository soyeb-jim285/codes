<h1 style='text-align: center;'> B. Multiply by 2, divide by 6</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$. In one move, you can either multiply $n$ by two or divide $n$ by $6$ (if it is divisible by $6$ without the remainder).

Your task is to find the minimum number of moves needed to obtain $1$ from $n$ or determine if it's impossible to do that.

You have to answer $t$ independent test cases.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases. Then $t$ test cases follow. 

The only line of the test case contains one integer $n$ ($1 \le n \le 10^9$).

## Output

For each test case, print the answer — the minimum number of moves needed to obtain $1$ from $n$ if it's possible to do that or -1 if it's impossible to obtain $1$ from $n$.

## Example

## Input


```

7
1
2
3
12
12345
15116544
387420489

```
## Output


```

0
-1
2
-1
-1
12
36

```
## Note

Consider the sixth test case of the example. The answer can be obtained by the following sequence of moves from the given integer $15116544$:

1. Divide by $6$ and get $2519424$;
2. divide by $6$ and get $419904$;
3. divide by $6$ and get $69984$;
4. divide by $6$ and get $11664$;
5. multiply by $2$ and get $23328$;
6. divide by $6$ and get $3888$;
7. divide by $6$ and get $648$;
8. divide by $6$ and get $108$;
9. multiply by $2$ and get $216$;
10. divide by $6$ and get $36$;
11. divide by $6$ and get $6$;
12. divide by $6$ and get $1$.


#### tags 

#900 #math 