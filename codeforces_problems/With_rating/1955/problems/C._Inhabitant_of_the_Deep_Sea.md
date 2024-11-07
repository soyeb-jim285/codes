<h1 style='text-align: center;'> C. Inhabitant of the Deep Sea</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ ships set out to explore the depths of the ocean. The ships are numbered from $1$ to $n$ and follow each other in ascending order; the $i$-th ship has a durability of $a_i$.

The Kraken attacked the ships $k$ times in a specific order. First, it attacks the first of the ships, then the last, then the first again, and so on.

Each attack by the Kraken reduces the durability of the ship by $1$. When the durability of the ship drops to $0$, it sinks and is no longer subjected to attacks (thus the ship ceases to be the first or last, and the Kraken only attacks the ships that have not yet sunk). If all the ships have sunk, the Kraken has nothing to attack and it swims away.

For example, if $n=4$, $k=5$, and $a=[1, 2, 4, 3]$, the following will happen:

1. The Kraken attacks the first ship, its durability becomes zero and now $a = [2, 4, 3]$;
2. The Kraken attacks the last ship, now $a = [2, 4, 2]$;
3. The Kraken attacks the first ship, now $a = [1, 4, 2]$;
4. The Kraken attacks the last ship, now $a = [1, 4, 1]$;
5. The Kraken attacks the first ship, its durability becomes zero and now $a = [4, 1]$.

How many ships were sunk after the Kraken's attack?

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$, $1 \le k \le 10^{15}$) — the number of ships and how many times the Kraken will attack the ships.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the durability of the ships.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the number of ships sunk by the Kraken on a separate line.

## Example

### Input


```text
64 51 2 4 34 61 2 4 35 202 7 1 8 22 23 22 151 52 75 2
```
### Output

```text

2
3
5
0
2
2

```


#### Tags 

#1300 #NOT OK #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_938_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
