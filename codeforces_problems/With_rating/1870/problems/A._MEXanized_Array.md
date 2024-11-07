<h1 style='text-align: center;'> A. MEXanized Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three non-negative integers $n$, $k$, and $x$. Find the maximum possible sum of elements in an array consisting of non-negative integers, which has $n$ elements, its MEX is equal to $k$, and all its elements do not exceed $x$. If such an array does not exist, output $-1$.

The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

* The MEX of $[2,2,1]$ is $0$, because $0$ does not belong to the array.
* The MEX of $[3,1,0,1]$ is $2$, because $0$ and $1$ belong to the array, but $2$ does not.
* The MEX of $[0,3,1,2]$ is $4$, because $0$, $1$, $2$ and $3$ belong to the array, but $4$ does not.
### Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Then follows the description of the test cases.

The only line of each test case contains three integers $n$, $k$, and $x$ ($1 \leq n, k, x \leq 200$).

### Output

For each test case, output a single number — the maximum sum of elements in a valid array, or $-1$, if such an array does not exist.

## Example

### Input


```text
95 3 34 7 54 2 2812 10 657 51 122200 1 2002 2 13 2 14 7 10
```
### Output

```text

7
-1
57
-1
2007
39800
1
2
-1

```
## Note

In the first test case, the maximum sum is $7$, and one of the valid arrays is $[0, 1, 2, 2, 2]$.

In the second test case, there are no valid arrays of length $n$.

In the third test case, the maximum sum is $57$, and one of the valid arrays is $[0, 1, 28, 28]$.



#### Tags 

#800 #NOT OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_6_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
