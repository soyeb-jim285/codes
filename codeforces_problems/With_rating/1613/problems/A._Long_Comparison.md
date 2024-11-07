<h1 style='text-align: center;'> A. Long Comparison</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp wrote down two numbers on a whiteboard. Both numbers follow a specific format: a positive integer $x$ with $p$ zeros appended to its end.

Now Monocarp asks you to compare these two numbers. Can you help him?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains two integers $x_1$ and $p_1$ ($1 \le x_1 \le 10^6; 0 \le p_1 \le 10^6$) — the description of the first number.

The second line of each testcase contains two integers $x_2$ and $p_2$ ($1 \le x_2 \le 10^6; 0 \le p_2 \le 10^6$) — the description of the second number.

### Output

For each testcase print the result of the comparison of the given two numbers. If the first number is smaller than the second one, print '<'. If the first number is greater than the second one, print '>'. If they are equal, print '='.

## Example

### Input


```text
5
2 1
19 0
10 2
100 1
1999 0
2 3
1 0
1 0
99 0
1 2
```
### Output


```text
>
=
<
=
<
```
## Note

The comparisons in the example are: $20 > 19$, $1000 = 1000$, $1999 < 2000$, $1 = 1$, $99 < 100$.



#### Tags 

#900 #NOT OK #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_118_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
