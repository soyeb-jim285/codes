<h1 style='text-align: center;'> A. Upload More RAM</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Oh no, the ForceCodes servers are running out of memory! Luckily, you can help them out by uploading some of your RAM!

You want to upload $n$ GBs of RAM. Every second, you will upload either $0$ or $1$ GB of RAM. However, there is a restriction on your network speed: in any $k$ consecutive seconds, you can upload only at most $1$ GB of RAM in total.

Find the minimum number of seconds needed to upload $n$ GBs of RAM!

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains two integers $n$ and $k$ ($1 \le n, k \le 100$) — the number of GBs that you want to upload and the length of the time window respectively.

## Output

For each test case, output a single integer — the minimum number of seconds needed to upload $n$ GBs of RAM.

## Example

## Input


```

65 12 22 31 711 5100 100
```
## Output


```

5
3
4
1
51
9901

```
## Note

In the first test case, you can upload $1$ GB of RAM per second, so to upload $5$ GBs, you need $5$ seconds.

In the second test case, you can upload $1$ GB in the first second, $0$ GBs in the second second, and $1$ GB in the third second, which in total adds up to exactly $2$ GBs of uploaded RAM.

In the third test case, you can upload $1$ GB in the first second, $0$ GBs in the second second, $0$ GBs in the third second, and $1$ GB in the fourth second, which in total adds up to exactly $2$ GBs of uploaded RAM.



#### tags 

#800 #greedy #math 