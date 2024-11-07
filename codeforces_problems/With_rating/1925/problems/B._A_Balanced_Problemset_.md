<h1 style='text-align: center;'> B. A Balanced Problemset?</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jay managed to create a problem of difficulty $x$ and decided to make it the second problem for Codeforces Round #921. 

But Yash fears that this problem will make the contest highly unbalanced, and the coordinator will reject it. So, he decided to break it up into a problemset of $n$ sub-problems such that the difficulties of all the sub-problems are a positive integer and their sum is equal to $x$. 

The coordinator, Aleksey, defines the balance of a problemset as the [GCD](https://en.wikipedia.org/wiki/Greatest_common_divisor) of the difficulties of all sub-problems in the problemset. 

Find the maximum balance that Yash can achieve if he chooses the difficulties of the sub-problems optimally.

### Input

The first line of input contains a single integer $t$ ($1\leq t\leq 10^3$) denoting the number of test cases.

Each test case contains a single line of input containing two integers $x$ ($1\leq x\leq 10^8$) and $n$ ($1\leq n\leq x$).

### Output

For each test case, print a single line containing a single integer denoting the maximum balance of the problemset Yash can achieve.

## Example

### Input


```text
310 35 5420 69
```
### Output

```text

2
1
6

```
## Note

For the first test case, one possible way is to break up the problem of difficulty $10$ into a problemset having three problems of difficulties $4$, $2$ and $4$ respectively, giving a balance equal to $2$.

For the second test case, there is only one way to break up the problem of difficulty $5$ into a problemset of $5$ problems with each problem having a difficulty $1$ giving a balance equal to $1$.



#### Tags 

#1200 #NOT OK #brute_force #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_921_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
