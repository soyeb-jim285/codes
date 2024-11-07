<h1 style='text-align: center;'> B. Olya and Game with Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Artem suggested a game to the girl Olya. There is a list of $n$ arrays, where the $i$-th array contains $m_i \ge 2$ positive integers $a_{i,1}, a_{i,2}, \ldots, a_{i,m_i}$.

Olya can move at most one (possibly $0$) integer from each array to another array. 
## Note

 that integers can be moved from one array only once, but integers can be added to one array multiple times, and all the movements are done at the same time.

The beauty of the list of arrays is defined as the sum $\sum_{i=1}^n \min_{j=1}^{m_i} a_{i,j}$. In other words, for each array, we find the minimum value in it and then sum up these values.

The goal of the game is to maximize the beauty of the list of arrays. Help Olya win this challenging game!

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 25000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 25000$) — the number of arrays in the list.

This is followed by descriptions of the arrays. Each array description consists of two lines.

The first line contains a single integer $m_i$ ($2 \le m_i \le 50000$) — the number of elements in the $i$-th array.

The next line contains $m_i$ integers $a_{i, 1}, a_{i, 2}, \ldots, a_{i, m_i}$ ($1 \le a_{i,j} \le 10^9$) — the elements of the $i$-th array.

It is guaranteed that the sum of $m_i$ over all test cases does not exceed $50000$.

### Output

For each test case, output a single line containing a single integer — the maximum beauty of the list of arrays that Olya can achieve.

## Example

### Input


```text
3221 224 313100 1 6341001 7 1007 538 11 622 9
```
### Output

```text

5
1
19

```
## Note

In the first test case, we can move the integer $3$ from the second array to the first array. Then the beauty is $\min(1, 2, 3) + \min(4) = 5$. It can be shown that this is the maximum possible beauty.

In the second test case, there is only one array, so regardless of the movements, the beauty will be $\min(100, 1, 6) = 1$.



#### Tags 

#1000 #OK #constructive_algorithms #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_892_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
