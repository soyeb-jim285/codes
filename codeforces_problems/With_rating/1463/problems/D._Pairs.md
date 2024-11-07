<h1 style='text-align: center;'> D. Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have $2n$ integers $1, 2, \dots, 2n$. You have to redistribute these $2n$ elements into $n$ pairs. After that, you choose $x$ pairs and take minimum elements from them, and from the other $n - x$ pairs, you take maximum elements.

Your goal is to obtain the set of numbers $\{b_1, b_2, \dots, b_n\}$ as the result of taking elements from the pairs.

What is the number of different $x$-s ($0 \le x \le n$) such that it's possible to obtain the set $b$ if for each $x$ you can choose how to distribute numbers into pairs and from which $x$ pairs choose minimum elements?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains the integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_1 < b_2 < \dots < b_n \le 2n$) — the set you'd like to get.

It's guaranteed that the sum of $n$ over test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print one number — the number of different $x$-s such that it's possible to obtain the set $b$.

## Example

### Input


```text
3
1
1
5
1 4 5 9 10
2
3 4
```
### Output


```text
1
3
1
```
## Note

In the first test case, $x = 1$ is the only option: you have one pair $(1, 2)$ and choose the minimum from this pair.

In the second test case, there are three possible $x$-s. If $x = 1$, then you can form the following pairs: $(1, 6)$, $(2, 4)$, $(3, 5)$, $(7, 9)$, $(8, 10)$. You can take minimum from $(1, 6)$ (equal to $1$) and the maximum elements from all other pairs to get set $b$.

If $x = 2$, you can form pairs $(1, 2)$, $(3, 4)$, $(5, 6)$, $(7, 9)$, $(8, 10)$ and take the minimum elements from $(1, 2)$, $(5, 6)$ and the maximum elements from the other pairs.

If $x = 3$, you can form pairs $(1, 3)$, $(4, 6)$, $(5, 7)$, $(2, 9)$, $(8, 10)$ and take the minimum elements from $(1, 3)$, $(4, 6)$, $(5, 7)$.

In the third test case, $x = 0$ is the only option: you can form pairs $(1, 3)$, $(2, 4)$ and take the maximum elements from both of them.



#### Tags 

#1900 #NOT OK #binary_search #constructive_algorithms #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_100_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
