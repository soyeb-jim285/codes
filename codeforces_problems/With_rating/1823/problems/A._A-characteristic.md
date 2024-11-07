<h1 style='text-align: center;'> A. A-characteristic</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider an array $a_1, a_2, \dots, a_n$ consisting of numbers $1$ and $-1$. Define $A$-characteristic of this array as a number of pairs of indices $1 \le i < j \le n$, such that $a_i \cdot a_j = 1$.

Find any array $a$ with given length $n$ with $A$-characteristic equal to the given value $k$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The only line of each test case contains two integers $n$ and $k$ ($2 \le n \le 100$; $0 \le k \le \frac{(n-1) n}{2}$) — the length of required array and required $A$-characteristic.

### Output

For each test case, if there is no array $a$ with given $A$-characteristic $k$, print NO.

Otherwise, print YES and $n$ numbers $1$ and $-1$, which form the required array $a$. If there are multiple answers, print any of them.

## Example

### Input


```text
72 02 13 13 23 35 45 5
```
### Output

```text

YES
1 -1 
YES
1 1 
YES
1 -1 1 
NO
YES
1 1 1 
YES
-1 1 -1 1 1 
NO
```
## Note

In the first test case, there is only one pair of different elements in the array, and their product is $a_1 \cdot a_2 = -1 \neq 1$, hence its $A$-characteristic is $0$.

In the second test case, there is only one pair of different elements in the array, and their product is $a_1 \cdot a_2 = 1$, hence its $A$-characteristic is $1$.

In the third test case, there are three pairs of different elements in the array, and their product are: $a_1 \cdot a_2 = -1$, $a_1 \cdot a_3 = 1$, $a_2 \cdot a_3 = -1$, hence its $A$-characteristic is $1$.

In the fourth test case, we can show, that there is no array with length $3$, which $A$-characteristic is $2$.



#### Tags 

#800 #OK #combinatorics #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_868_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
