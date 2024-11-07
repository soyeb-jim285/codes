<h1 style='text-align: center;'> C. Twin Clusters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Famous worldwide astrophysicist Mleil waGrasse Tysok recently read about the existence of twin galaxy clusters. Before he shares this knowledge with the broader audience in his podcast called S.tarT-ok, he wants to prove their presence on his own. Mleil is aware that the vastness of the universe is astounding (almost as astounding as his observation skills) and decides to try his luck and find some new pair of twin clusters.

To do so, he used his TLEscope to observe a part of the night sky that was not yet examined by humanity in which there are exactly $2^{k + 1}$ galaxies in a row. $i$-th of them consist of exactly $0 \le g_i < 4^k$ stars.

A galaxy cluster is any non-empty contiguous segment of galaxies. Moreover, its' trait is said to be equal to the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all values $g_i$ within this range.

Two galaxy clusters are considered twins if and only if they have the same traits and their corresponding segments are disjoint.

Write a program that, for many scenarios, will read a description of a night sky part observed by Mleil and outputs a location of two intervals belonging to some twin clusters pair, or a single value $-1$ if no such pair exists.

### Input

The first line contains a single integer $t$, denoting the number of test cases that the program has to handle. The following lines contain test case descriptions, each containing exactly two lines.

The first of them contains a single integer $k$ ($0 \le k \le 17$).

The second line contains $2^{k + 1}$ integers $g_1, g_2, \ldots, g_{2^{k+1}}$ ($0 \le g_i < 4^k$).

We guarantee that the sum of values $2^{k + 1}$ over all test cases does not exceed $2^{18}$.

### Output

Answers for all test cases should be present in separate lines. If there exist a pair of twin galaxies, then output four integers $a$, $b$, $c$, and $d$ denoting their inclusive ranges $[a, b]$ and $[c, d]$ (the first interval does not need to start before the second one, but they have to be disjoint). If no pair of such galaxies exist, output a single value $-1$ instead.

## Example

### Input


```text
424 15 0 7 11 8 3 210 1 2 300 0315 63 57 39 61 25 42 61 50 41 27 41 56 23 17 27
```
### Output

```text

2 4 6 6
2 2 3 4
1 1 2 2
1 1 4 10

```
## Note

In the first test case we pick intervals $[2, 4]$ and $[6, 6]$ as our twin clusters. The trait of the first interval equals $15 \oplus 0 \oplus 7 = 8$, and the trait of the second interval equals $8$, so these galaxy clusters are indeed twins.



#### Tags 

#2600 #NOT OK #bitmasks #brute_force #constructive_algorithms #math #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_880_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
