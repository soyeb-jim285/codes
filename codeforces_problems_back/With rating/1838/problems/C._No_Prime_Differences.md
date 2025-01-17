<h1 style='text-align: center;'> C. No Prime Differences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given integers $n$ and $m$. Fill an $n$ by $m$ grid with the integers $1$ through $n\cdot m$, in such a way that for any two adjacent cells in the grid, the absolute difference of the values in those cells is not a prime number. Two cells in the grid are considered adjacent if they share a side.

 ![](images/a0834d13365d1753094fd957deb6b0ac5840c83a.png) It can be shown that under the given constraints, there is always a solution.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains two integers $n$ and $m$ ($4 \le n, m \le 1000$) — the dimensions of the grid.

It is guaranteed that the sum of $n\cdot m$ over all test cases does not exceed $10^6$.

## Output

For each test case, output $n$ lines of $m$ integers each, representing the final grid. Every number from $1$ to $n\cdot m$ should appear exactly once in the grid.

The extra spaces and blank lines in the sample output below are only present to make the output easier to read, and are not required.

If there are multiple solutions, print any of them.

## Example

## Input


```

34 45 76 4
```
## Output


```

16  7  1  9
12  8  2  3
13  4 10 11
14  5  6 15

29 23 17  9  5  6  2
33 27 21 15 11  7  1
32 31 25 19 20 16 10
26 30 24 18 14  8  4
35 34 28 22 13 12  3

 2  3  7 11
 8  9  1 10
17 13  5  4
18 14  6 12
19 23 15 21
20 24 16 22

```
## Note

The first sample case corresponds to the picture above. The only absolute differences between adjacent elements in this grid are $1$, $4$, $6$, $8$, and $9$, none of which are prime. 



#### tags 

#1400 #constructive_algorithms #math #number_theory 