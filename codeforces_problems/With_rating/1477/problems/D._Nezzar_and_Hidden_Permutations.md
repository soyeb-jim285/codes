<h1 style='text-align: center;'> D. Nezzar and Hidden Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Nezzar designs a brand new game "Hidden Permutations" and shares it with his best friend, Nanako.

At the beginning of the game, Nanako and Nezzar both know integers $n$ and $m$. The game goes in the following way:

* Firstly, Nezzar hides two permutations $p_1,p_2,\ldots,p_n$ and $q_1,q_2,\ldots,q_n$ of integers from $1$ to $n$, and Nanako secretly selects $m$ unordered pairs $(l_1,r_1),(l_2,r_2),\ldots,(l_m,r_m)$;
* After that, Nanako sends his chosen pairs to Nezzar;
* On receiving those $m$ unordered pairs, Nezzar checks if there exists $1 \le i \le m$, such that $(p_{l_i}-p_{r_i})$ and $(q_{l_i}-q_{r_i})$ have different signs. If so, Nezzar instantly loses the game and gets a score of $-1$. Otherwise, the score Nezzar gets is equal to the number of indices $1 \le i \le n$ such that $p_i \neq q_i$.

However, Nezzar accidentally knows Nanako's unordered pairs and decides to take advantage of them. Please help Nezzar find out two permutations $p$ and $q$ such that the score is maximized.

### Input

The first line contains a single integer $t$ ($1 \le t \le 5 \cdot 10^5$) — the number of test cases.

The first line of each test case contains two integers $n,m$ ($1 \le n \le 5 \cdot 10^5, 0 \le m \le \min(\frac{n(n-1)}{2},5 \cdot 10^5)$). 

Then $m$ lines follow, $i$-th of them contains two integers $l_i,r_i$ ($1 \le l_i,r_i \le n$, $l_i \neq r_i$), describing the $i$-th unordered pair Nanako chooses. It is guaranteed that all $m$ unordered pairs are distinct.

It is guaranteed that the sum of $n$ for all test cases does not exceed $5 \cdot 10^5$, and the sum of $m$ for all test cases does not exceed $5\cdot 10^5$.

### Output

For each test case, print two permutations $p_1,p_2,\ldots,p_n$ and $q_1,q_2,\ldots,q_n$ such that the score Nezzar gets is maximized.

## Example

### Input


```text
3
4 2
1 2
3 4
6 4
1 2
1 3
3 5
3 6
2 1
1 2
```
### Output


```text
1 2 3 4
3 4 1 2
2 3 4 1 6 5
1 4 3 2 5 6
1 2
1 2
```
## Note

For first test case, for each pair given by Nanako:

* for the first pair $(1,2)$: $p_1 - p_2 = 1 - 2 = -1$, $q_1 - q_2 = 3 - 4 = -1$, they have the same sign;
* for the second pair $(3,4)$: $p_3 - p_4 = 3 - 4 = -1$, $q_3 - q_4 = 1 - 2 = -1$, they have the same sign.

As Nezzar does not lose instantly, Nezzar gains the score of $4$ as $p_i \neq q_i$ for all $1 \leq i \leq 4$. Obviously, it is the maximum possible score Nezzar can get.



#### Tags 

#2800 #NOT OK #constructive_algorithms #dfs_and_similar #graphs 

## Blogs
- [All Contest Problems](../Codeforces_Round_698_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
