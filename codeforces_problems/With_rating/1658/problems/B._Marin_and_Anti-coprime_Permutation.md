<h1 style='text-align: center;'> B. Marin and Anti-coprime Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Marin wants you to count number of permutations that are beautiful. A beautiful permutation of length $n$ is a permutation that has the following property: $$ \gcd (1 \cdot p_1, \, 2 \cdot p_2, \, \dots, \, n \cdot p_n) > 1, $$ where $\gcd$ is the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor).

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3, 4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

The first line contains one integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

Each test case consists of one line containing one integer $n$ ($1 \le n \le 10^3$).

### Output

For each test case, print one integer — number of beautiful permutations. Because the answer can be very big, please print the answer modulo $998\,244\,353$.

## Example

### Input


```text
71234561000
```
### Output

```text

0
1
0
4
0
36
665702330

```
## Note

In first test case, we only have one permutation which is $[1]$ but it is not beautiful because $\gcd(1 \cdot 1) = 1$.

In second test case, we only have one beautiful permutation which is $[2, 1]$ because $\gcd(1 \cdot 2, 2 \cdot 1) = 2$. 



#### Tags 

#800 #NOT OK #combinatorics #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_779_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
