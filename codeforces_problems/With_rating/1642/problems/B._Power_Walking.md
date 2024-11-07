<h1 style='text-align: center;'> B. Power Walking</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sam is a kindergartener, and there are $n$ children in his group. He decided to create a team with some of his children to play "brawl:go 2".

Sam has $n$ power-ups, the $i$-th has type $a_i$. A child's strength is equal to the number of different types among power-ups he has.

For a team of size $k$, Sam will distribute all $n$ power-ups to $k$ children in such a way that each of the $k$ children receives at least one power-up, and each power-up is given to someone.

For each integer $k$ from $1$ to $n$, find the minimum sum of strengths of a team of $k$ children Sam can get.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 3 \cdot 10^5$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$). 

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — types of Sam's power-ups.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For every test case print $n$ integers.

The $k$-th integer should be equal to the minimum sum of strengths of children in the team of size $k$ that Sam can get.

## Example

### Input


```text
231 1 265 1 2 2 2 4
```
### Output

```text

2 2 3 
4 4 4 4 5 6 

```
## Note

One of the ways to give power-ups to minimise the sum of strengths in the first test case: 

* $k = 1: \{1, 1, 2\}$
* $k = 2: \{1, 1\}, \{2\}$
* $k = 3: \{1\}, \{1\}, \{2\}$

One of the ways to give power-ups to minimise the sum of strengths in the second test case: 

* $k = 1: \{1, 2, 2, 2, 4, 5\}$
* $k = 2: \{2, 2, 2, 4, 5\}, \{1\}$
* $k = 3: \{2, 2, 2, 5\}, \{1\}, \{4\}$
* $k = 4: \{2, 2, 2\}, \{1\}, \{4\}, \{5\}$
* $k = 5: \{2, 2\}, \{1\}, \{2\}, \{4\}, \{5\}$
* $k = 6: \{1\}, \{2\}, \{2\}, \{2\}, \{4\}, \{5\}$


#### Tags 

#900 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_773_(Div._2).md)
- [Codeforces Round #773](../blogs/Codeforces_Round_773.md)
- [Tutorial](../blogs/Tutorial.md)
