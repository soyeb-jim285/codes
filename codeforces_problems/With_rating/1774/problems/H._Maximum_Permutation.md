<h1 style='text-align: center;'> H. Maximum Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ecrade bought a deck of cards numbered from $1$ to $n$. Let the value of a permutation $a$ of length $n$ be $\min\limits_{i = 1}^{n - k + 1}\ \sum\limits_{j = i}^{i + k - 1}a_j$.

Ecrade wants to find the most valuable one among all permutations of the cards. However, it seems a little difficult, so please help him! 

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^4$)  — the number of test cases. The description of test cases follows.

The only line of each test case contains two integers $n,k$ ($4 \leq k < n \leq 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^6$.

### Output

For each test case, output the largest possible value in the first line. Then in the second line, print $n$ integers $a_1,a_2,\dots,a_n$ ($1 \le a_i \le n$, all $a_i$ are distinct)  — the elements of the permutation that has the largest value.

If there are multiple such permutations, output any of them.

## Example

### Input


```text
2
5 4
8 4
```
### Output


```text

13
1 4 5 3 2
18
4 2 5 7 8 3 1 6
```
## Note

In the first test case, $[1,4,5,3,2]$ has a value of $13$. It can be shown that no permutations of length $5$ have a value greater than $13$ when $k = 4$.

In the second test case, $[4,2,5,7,8,3,1,6]$ has a value of $18$. It can be shown that no permutations of length $8$ have a value greater than $18$ when $k = 4$.



#### Tags 

#3500 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Polynomial_Round_2022_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
