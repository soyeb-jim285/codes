<h1 style='text-align: center;'> G. Vlad and the Mountains</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad decided to go on a trip to the mountains. He plans to move between $n$ mountains, some of which are connected by roads. The $i$-th mountain has a height of $h_i$.

If there is a road between mountains $i$ and $j$, Vlad can move from mountain $i$ to mountain $j$ by spending $h_j - h_i$ units of energy. If his energy drops below zero during the transition, he will not be able to move from mountain $i$ to mountain $j$. Note that $h_j - h_i$ can be negative and then the energy will be restored.

Vlad wants to consider different route options, so he asks you to answer the following queries: is it possible to construct some route starting at mountain $a$ and ending at mountain $b$, given that he initially has $e$ units of energy?

## Input

The first line of the input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The descriptions of the test cases follow.

The first line of each test case contains two numbers $n$ and $m$ ($2 \le n \le 2 \cdot 10^5$, $1 \le m \le \min(\frac{n\cdot(n - 1)}{2}, 2 \cdot 10^5)$) — the number of mountains and the number of roads between them, respectively.

The second line contains $n$ integers $h_1, h_2, h_3, \dots, h_n$ ($1 \le h_i \le 10^9$) — the heights of the mountains.

The next $m$ lines contain two integers $u$ and $v$ ($1 \le u, v \le n$, $u \ne v$) — the numbers of the mountains connected by a road. It is guaranteed that no road appears twice.

The next line contains an integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of queries.

The following $q$ lines contain three numbers $a$, $b$, and $e$ ($1 \le a, b \le n$, $0 \le e \le 10^9$) — the initial and final mountains of the route, and the amount of energy, respectively.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. The same guarantee applies to $m$ and $q$.

## Output

For each query, output "YES" if Vlad can construct a route from mountain $a$ to mountain $b$, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

In the examples below, the answers for different test cases are separated by an empty line, which you do not need to output.

## Examples

## Input


```

27 71 5 3 4 2 4 11 44 33 63 22 55 65 751 1 36 2 04 7 01 7 41 7 26 54 7 6 2 5 11 35 31 52 46 251 5 11 3 11 2 10006 2 66 2 5
```
## Output


```

YES
NO
YES
YES
NO

YES
NO
NO
YES
NO

```
## Input


```

23 21 3 91 22 351 1 13 2 21 1 23 3 01 2 13 31 4 11 22 31 353 3 91 3 61 1 23 3 63 3 4
```
## Output


```

YES
YES
YES
YES
NO

YES
YES
YES
YES
YES

```
## Input


```

16 107 9 2 10 8 64 26 14 53 56 41 32 66 51 23 654 4 83 3 15 5 92 1 76 6 10
```
## Output


```

YES
YES
YES
YES
YES

```


#### tags 

#2000 #binary_search #data_structures #dsu #graphs #implementation #sortings #trees #two_pointers 