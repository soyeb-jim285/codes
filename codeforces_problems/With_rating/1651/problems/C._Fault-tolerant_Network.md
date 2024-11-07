<h1 style='text-align: center;'> C. Fault-tolerant Network</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a classroom with two rows of computers. There are $n$ computers in each row and each computer has its own grade. Computers in the first row has grades $a_1, a_2, \dots, a_n$ and in the second row — $b_1, b_2, \dots, b_n$.

Initially, all pairs of neighboring computers in each row are connected by wire (pairs $(i, i + 1)$ for all $1 \le i < n$), so two rows form two independent computer networks.

Your task is to combine them in one common network by connecting one or more pairs of computers from different rows. Connecting the $i$-th computer from the first row and the $j$-th computer from the second row costs $|a_i - b_j|$.

You can connect one computer to several other computers, but you need to provide at least a basic fault tolerance: you need to connect computers in such a way that the network stays connected, despite one of its computer failing. In other words, if one computer is broken (no matter which one), the network won't split in two or more parts.

That is the minimum total cost to make a fault-tolerant network?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Next $t$ cases follow.

The first line of each test case contains the single integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the number of computers in each row.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the grades of computers in the first row.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^9$) — the grades of computers in the second row.

It's guaranteed that the total sum of $n$ doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the minimum total cost to make a fault-tolerant network.

## Example

### Input


```text
231 10 120 4 2541 1 1 11000000000 1000000000 1000000000 1000000000
```
### Output

```text

31
1999999998

```
## Note

In the first test case, it's optimal to connect four pairs of computers: 

1. computer $1$ from the first row with computer $2$ from the second row: cost $|1 - 4| = 3$;
2. computer $3$ from the first row with computer $2$ from the second row: cost $|1 - 4| = 3$;
3. computer $2$ from the first row with computer $1$ from the second row: cost $|10 - 20| = 10$;
4. computer $2$ from the first row with computer $3$ from the second row: cost $|10 - 25| = 15$;

 In total, $3 + 3 + 10 + 15 = 31$.In the second test case, it's optimal to connect $1$ from the first row with $1$ from the second row, and $4$ from the first row with $4$ from the second row.



#### Tags 

#1500 #NOT OK #brute_force #data_structures #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_124_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
