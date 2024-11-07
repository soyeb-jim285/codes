<h1 style='text-align: center;'> C. Have Your Cake and Eat It Too</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice, Bob and Charlie want to share a rectangular cake cut into $n$ pieces. Each person considers every piece to be worth a different value. The $i$-th piece is considered to be of value $a_i$ by Alice, $b_i$ by Bob and $c_i$ by Charlie.

The sum over all $a_i$, all $b_i$ and all $c_i$ individually is the same, equal to $tot$.

Given the values of each piece of the cake for each person, you need to give each person a contiguous slice of cake. In other words, the indices at the left and right ends of these subarrays (the slices given to each person) can be represented as $(l_a, r_a)$, $(l_b, r_b)$ and $(l_c, r_c)$ respectively for Alice, Bob and Charlie. The division needs to satisfy the following constraints:

* No piece is assigned to more than one person, i.e., no two subarrays among $[l_a,\ldots,r_a]$, $[l_b, \ldots, r_b]$ and $[l_c, \ldots, r_c]$ intersect.
* $ \sum_{i = l_a}^{r_a} a_i, \sum_{i = l_b}^{r_b} b_i, \sum_{i = l_c}^{r_c} c_i \geq \lceil \frac{tot}{3} \rceil$.

Here, the notation $\lceil \frac{a}{b} \rceil$ represents ceiling division. It is defined as the smallest integer greater than or equal to the exact division of $a$ by $b$. In other words, it rounds up the division result to the nearest integer. For instance $\lceil \frac{10}{3} \rceil = 4$ and $\lceil \frac{15}{3} \rceil = 5$. 

### Input

The first line contains an integer $t$, the number of testcases, ($1 \le t \le 10^4$)

For each testcase:

The first line contains the integer $n$ ($3 \le n \le 2 \cdot 10^5$).

The following three lines contain $n$ integers each:

One line with $n$ integers $a_1, a_2, \ldots, a_n$ represents the values for Alice ($1 \le a_i \le 10^6$).

The next line with $n$ integers $b_1, b_2, \ldots, b_n$ represents the values for Bob ($1 \le b_i \le 10^6$).

The next line with $n$ integers $c_1, c_2, \ldots, c_n$ represents the values for Charlie ($1 \le c_i \le 10^6$).

It is guaranteed that $ \sum_{i = 1}^{n} a_i = \sum_{i = 1}^{n} b_i = \sum_{i = 1}^{n} c_i$.

The sum of $n$ over all testcases does not exceed $2 \cdot 10^5$.

### Output

For each testcase, output $-1$ if the required condition is impossible. 

Otherwise, output six numbers – $l_a, r_a, l_b, r_b, l_c, r_c$, the respective starting and ending indices ($1$-indexed) of the subarrays for Alice, Bob and Charlie, respectively.

## Example

### Input


```text
1055 1 1 1 11 1 5 1 11 1 1 1 561 2 3 4 5 65 6 1 2 3 43 4 5 6 1 244 4 4 44 4 4 44 4 4 455 10 5 2 109 6 9 7 110 7 10 2 334 5 26 1 41 8 2310 4 108 7 910 4 10757113 65383 19795 53580 74452 3879 2325512917 16782 89147 93107 27365 15044 4309533518 63581 33565 34112 46774 44151 4175666 3 1 8 7 110 2 6 2 2 410 9 2 1 2 255 5 4 5 51 6 3 8 62 4 1 9 8101 1 1 1 1001 1 1 1001 1 11 1 1 1 1 1 2001 1 1 11 1 1 1 1 1001 1 1 1 1001
```
### Output

```text

1 1 2 3 4 5 
5 6 1 2 3 4 
-1
-1
1 1 3 3 2 2 
-1
1 2 3 4 5 7 
3 6 1 1 2 2 
1 2 3 4 5 5 
1 5 6 7 8 10 

```
## Note

In the first testcase, the sum of either of the three arrays is $9$. Each person needs a cake slice corresponding to a subarray with a total value of at least $\lceil \frac{9}{3} \rceil = 3$. 

If we assign the subarray ($1$,$1$) to Alice, its total value to her is $5$, which is $\ge 3$; the subarray ($2$,$3$) to Bob, its total value to him is $1 + 5 = 6$, which is $\ge 3$; and the subarray ($4$,$5$) to Charlie, its total value to him $1 + 5 = 6$, which is also $\ge 3$. Each person gets their own separate pieces of the cake, and no piece is common to two or more people.

It can be shown that for the third test case, it is not possible to give slices of the cake in a way that satisfies the given constraints.



#### Tags 

#1400 #OK #binary_search #brute_force #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_956_(Div._2)_and_ByteRace_2024.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
