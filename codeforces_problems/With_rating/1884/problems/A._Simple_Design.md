<h1 style='text-align: center;'> A. Simple Design</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A positive integer is called $k$-beautiful, if the digit sum of the decimal representation of this number is divisible by $k^{\dagger}$. For example, $9272$ is $5$-beautiful, since the digit sum of $9272$ is $9 + 2 + 7 + 2 = 20$.

You are given two integers $x$ and $k$. Please find the smallest integer $y \ge x$ which is $k$-beautiful.

$^{\dagger}$ An integer $n$ is divisible by $k$ if there exists an integer $m$ such that $n = k \cdot m$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The only line of each test case contains two integers $x$ and $k$ ($1 \le x \le 10^9$, $1 \le k \le 10$).

### Output

For each test case, output the smallest integer $y \ge x$ which is $k$-beautiful.

## Example

### Input


```text
61 510 837 9777 31235 101 10
```
### Output

```text

5
17
45
777
1243
19

```
## Note

In the first test case, numbers from $1$ to $4$ consist of a single digit, thus the digit sum is equal to the number itself. None of the integers from $1$ to $4$ are divisible by $5$.

In the fourth test case, the digit sum of $777$ is $7 + 7 + 7 = 21$ which is already divisible by $3$.



#### Tags 

#800 #OK #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_904_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
