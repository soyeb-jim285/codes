<h1 style='text-align: center;'> A. 2-3 Moves</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are standing at the point $0$ on a coordinate line. Your goal is to reach the point $n$. In one minute, you can move by $2$ or by $3$ to the left or to the right (i. e., if your current coordinate is $x$, it can become $x-3$, $x-2$, $x+2$ or $x+3$). Note that the new coordinate can become negative.

Your task is to find the minimum number of minutes required to get from the point $0$ to the point $n$.

You have to answer $t$ independent test cases.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then $t$ lines describing the test cases follow.

The $i$-th of these lines contains one integer $n$ ($1 \le n \le 10^9$) — the goal of the $i$-th test case.

## Output

For each test case, print one integer — the minimum number of minutes required to get from the point $0$ to the point $n$ for the corresponding test case.

## Example

## Input


```

413412
```
## Output


```

2
1
2
4

```


#### tags 

#800 #greedy #math 