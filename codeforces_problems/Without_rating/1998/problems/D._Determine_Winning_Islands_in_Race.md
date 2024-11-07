<h1 style='text-align: center;'> D. Determine Winning Islands in Race</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

MOOOOOOOOOOOOOOOOO— Bessie the Cow, The Art of Racing on IslandsTwo of Farmer John's cows, Bessie and Elsie, are planning to race on $n$ islands. There are $n - 1$ main bridges, connecting island $i$ to island $i + 1$ for all $1 \leq i \leq n - 1$. Additionally, there are $m$ alternative bridges. Elsie can use both main and alternative bridges, while Bessie can only use main bridges. All bridges are one way and can only be used to travel from an island with a lower index to an island with a higher index.

Initially, Elsie starts on island $1$, and Bessie starts on island $s$. The cows alternate turns, with Bessie making the first turn. Suppose the cow is on island $i$. During a cow's turn, if there are any bridges connecting island $i$ to island $j$, then the cow can move to island $j$. Then, island $i$ collapses, and all bridges connecting to island $i$ also collapse. Also, note the following:

* If there are no bridges connecting island $i$ to another island, then island $i$ collapses, and this cow is eliminated from the race.
* If the other cow is also on island $i$, then after this cow moves to another island, the island collapses, and the other cow is eliminated from the race.
* After an island or bridge collapses, no cows may use them.
* If a cow is eliminated, their turn is skipped for the rest of the race.

The race ends once either cow reaches island $n$. It can be shown that regardless of the cows' strategies, at least one cow reaches island $n$. Bessie wins if and only if she reaches island $n$ first.

For each $1 \leq s \leq n - 1$, determine whether Bessie wins if she starts the race on island $s$. Assume both cows follow optimal strategies to ensure their own respective victories.

### Input

The first line contains $t$ ($1 \leq t \leq 10^4$) – the number of test cases.

The first line of each test case contains $n$ and $m$ ($2 \leq n \leq 2 \cdot 10^5$, $0 \leq m \leq 2 \cdot 10^5$) – the number of islands and the number of alternative bridges.

The next $m$ lines of each test case contain $u$ and $v$ ($1 \leq u < v \leq n$) – the islands that the alternative bridge connects. It is guaranteed all alternative bridges are distinct, and they do not coincide with the main bridges.

It is guaranteed that neither the sum of $n$ nor the sum of $m$ over all test cases exceeds $2 \cdot 10^5$.

### Output

For each test case, output a binary string of length $n - 1$ on a new line. The $i$'th character is $1$ if it is possible for Bessie to win if she starts on island $i$. Otherwise, it is $0$.

## Example

### Input


```text
56 06 12 66 11 510 41 31 62 73 815 32 84 98 15
```
### Output

```text

11111
11011
10011
100001111
11000111000111

```
## Note

In the first test case, there are no alternative bridges for Elsie to overtake Bessie and reach island $n$ first, so Bessie will win on all islands because she always moves first.

In the second case, Bessie will lose if she starts on island $3$ because:

* Bessie's Turn: Take a main bridge from island $3$ to island $4$.
* Elsie's Turn: Take a main bridge from island $1$ to island $2$.
* Bessie's Turn: Take a main bridge from island $4$ to island $5$.
* Elsie's Turn: Take an alternative bridge from island $2$ to island $6$. Elsie reaches island $n$ first.


#### Tags 

#NOT OK #data_structures #dp #graphs #greedy #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_965_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
