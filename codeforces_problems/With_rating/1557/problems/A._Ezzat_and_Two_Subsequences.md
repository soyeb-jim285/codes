<h1 style='text-align: center;'> A. Ezzat and Two Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ezzat has an array of $n$ integers (maybe negative). He wants to split it into two non-empty subsequences $a$ and $b$, such that every element from the array belongs to exactly one subsequence, and the value of $f(a) + f(b)$ is the maximum possible value, where $f(x)$ is the average of the subsequence $x$. 

A sequence $x$ is a subsequence of a sequence $y$ if $x$ can be obtained from $y$ by deletion of several (possibly, zero or all) elements.

The average of a subsequence is the sum of the numbers of this subsequence divided by the size of the subsequence.

For example, the average of $[1,5,6]$ is $(1+5+6)/3 = 12/3 = 4$, so $f([1,5,6]) = 4$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$)— the number of test cases. Each test case consists of two lines.

The first line contains a single integer $n$ ($2 \le n \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $3\cdot10^5$.

### Output

For each test case, print a single value — the maximum value that Ezzat can achieve.

Your answer is considered correct if its absolute or relative error does not exceed $10^{-6}$.

Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is accepted if and only if $\frac{|a - b|}{\max{(1, |b|)}} \le 10^{-6}$.

## Example

### Input


```text
4
3
3 1 2
3
-7 -6 -6
3
2 2 2
4
17 3 5 -3
```
### Output


```text
4.500000000
-12.500000000
4.000000000
18.666666667
```
## Note

In the first test case, the array is $[3, 1, 2]$. These are all the possible ways to split this array: 

* $a = [3]$, $b = [1,2]$, so the value of $f(a) + f(b) = 3 + 1.5 = 4.5$.
* $a = [3,1]$, $b = [2]$, so the value of $f(a) + f(b) = 2 + 2 = 4$.
* $a = [3,2]$, $b = [1]$, so the value of $f(a) + f(b) = 2.5 + 1 = 3.5$.

 Therefore, the maximum possible value $4.5$.In the second test case, the array is $[-7, -6, -6]$. These are all the possible ways to split this array: 

* $a = [-7]$, $b = [-6,-6]$, so the value of $f(a) + f(b) = (-7) + (-6) = -13$.
* $a = [-7,-6]$, $b = [-6]$, so the value of $f(a) + f(b) = (-6.5) + (-6) = -12.5$.

 Therefore, the maximum possible value $-12.5$.

#### Tags 

#800 #NOT OK #brute_force #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_737_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
