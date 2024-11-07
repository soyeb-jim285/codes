<h1 style='text-align: center;'> A. The Good Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $n$ and $k$.

An array $a_1, a_2, \ldots, a_n$ of length $n$, consisting of zeroes and ones is good if for all integers $i$ from $1$ to $n$ both of the following conditions are satisfied:

* at least $\lceil \frac{i}{k} \rceil$ of the first $i$ elements of $a$ are equal to $1$,
* at least $\lceil \frac{i}{k} \rceil$ of the last $i$ elements of $a$ are equal to $1$.

Here, $\lceil \frac{i}{k} \rceil$ denotes the result of division of $i$ by $k$, rounded up. For example, $\lceil \frac{6}{3} \rceil = 2$, $\lceil \frac{11}{5} \rceil = \lceil 2.2 \rceil = 3$ and $\lceil \frac{7}{4} \rceil = \lceil 1.75 \rceil = 2$.

Find the minimum possible number of ones in a good array.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains two integers $n$, $k$ ($2 \le n \le 100$, $1 \le k \le n$) — the length of array and parameter $k$ from the statement.

### Output

For each test case output one integer — the minimum possible number of ones in a good array.

It can be shown that under the given constraints at least one good array always exists.

## Example

### Input


```text
73 25 29 37 110 49 58 8
```
### Output

```text

2
3
4
7
4
3
2

```
## Note

In the first test case, $n = 3$ and $k = 2$: 

* Array $[ \, 1, 0, 1 \, ]$ is good and the number of ones in it is $2$.
* Arrays $[ \, 0, 0, 0 \, ]$, $[ \, 0, 1, 0 \, ]$ and $[ \, 0, 0, 1 \, ]$ are not good since for $i=1$ the first condition from the statement is not satisfied.
* Array $[ \, 1, 0, 0 \, ]$ is not good since for $i=1$ the second condition from the statement is not satisfied.
* All other arrays of length $3$ contain at least $2$ ones.

Thus, the answer is $2$.

In the second test case, $n = 5$ and $k = 2$: 

* Array $[ \, 1, 1, 0, 0, 1 \, ]$ is not good since for $i=3$ the second condition is not satisfied.
* Array $[ \, 1, 0, 1, 0, 1 \, ]$ is good and the number of ones in it is $3$.
* It can be shown that there is no good array with less than $3$ ones, so the answer is $3$.

In the third test case, $n = 9$ and $k = 3$: 

* Array $[ \, 1, 0, 1, 0, 0, 0, 1, 0, 1 \, ]$ is good and the number of ones in it is $4$.
* It can be shown that there is no good array with less than $4$ ones, so the answer is $4$.

In the fourth test case, $n = 7$ and $k = 1$. The only good array is $[ \, 1, 1, 1, 1, 1, 1, 1\, ]$, so the answer is $7$.



#### Tags 

#800 #NOT OK #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_876_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
