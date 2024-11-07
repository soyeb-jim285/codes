<h1 style='text-align: center;'> A. Specific Tastes of Andre </h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Andre has very specific tastes. Recently he started falling in love with arrays.

Andre calls an nonempty array $b$ good, if sum of its elements is divisible by the length of this array. For example, array $[2, 3, 1]$ is good, as sum of its elements — $6$ — is divisible by $3$, but array $[1, 1, 2, 3]$ isn't good, as $7$ isn't divisible by $4$. 

Andre calls an array $a$ of length $n$ perfect if the following conditions hold: 

* Every nonempty subarray of this array is good.
* For every $i$ ($1 \le i \le n$), $1 \leq a_i \leq 100$.

Given a positive integer $n$, output any perfect array of length $n$. We can show that for the given constraints such an array always exists.

An array $c$ is a subarray of an array $d$ if $c$ can be obtained from $d$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first and only line of every test case contains a single integer $n$ ($1 \le n \le 100$).

### Output

For every test, output any perfect array of length $n$ on a separate line. 

## Example

### Input


```text
3
1
2
4
```
### Output


```text
24
19 33
7 37 79 49
```
## Note

Array $[19, 33]$ is perfect as all $3$ its subarrays: $[19]$, $[33]$, $[19, 33]$, have sums divisible by their lengths, and therefore are good.



#### Tags 

#800 #NOT OK #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_682_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
