<h1 style='text-align: center;'> E. Singers' Tour</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ towns are arranged in a circle sequentially. The towns are numbered from $1$ to $n$ in clockwise order. In the $i$-th town, there lives a singer with a repertoire of $a_i$ minutes for each $i \in [1, n]$.

Each singer visited all $n$ towns in clockwise order, starting with the town he lives in, and gave exactly one concert in each town. In addition, in each town, the $i$-th singer got inspired and came up with a song that lasts $a_i$ minutes. The song was added to his repertoire so that he could perform it in the rest of the cities.

Hence, for the $i$-th singer, the concert in the $i$-th town will last $a_i$ minutes, in the $(i + 1)$-th town the concert will last $2 \cdot a_i$ minutes, ..., in the $((i + k) \bmod n + 1)$-th town the duration of the concert will be $(k + 2) \cdot a_i$, ..., in the town $((i + n - 2) \bmod n + 1)$ — $n \cdot a_i$ minutes.

You are given an array of $b$ integer numbers, where $b_i$ is the total duration of concerts in the $i$-th town. Reconstruct any correct sequence of positive integers $a$ or say that it is impossible.

### Input

The first line contains one integer $t$ $(1 \le t \le 10^3$) — the number of test cases. Then the test cases follow.

Each test case consists of two lines. The first line contains a single integer $n$ ($1 \le n \le 4 \cdot 10^4$) — the number of cities. The second line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^{9}$) — the total duration of concerts in $i$-th city.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print the answer as follows:

If there is no suitable sequence $a$, print NO. Otherwise, on the first line print YES, on the next line print the sequence $a_1, a_2, \dots, a_n$ of $n$ integers, where $a_i$ ($1 \le a_i \le 10^{9}$) is the initial duration of repertoire of the $i$-th singer. If there are multiple answers, print any of them.

## Example

### Input


```text
4
3
12 16 14
1
1
3
1 2 3
6
81 75 75 93 93 87
```
### Output


```text
YES
3 1 3 
YES
1 
NO
YES
5 5 4 1 4 5 
```
## Note

Let's consider the $1$-st test case of the example:

1. the $1$-st singer in the $1$-st city will give a concert for $3$ minutes, in the $2$-nd — for $6$ minutes, in the $3$-rd — for $9$ minutes;
2. the $2$-nd singer in the $1$-st city will give a concert for $3$ minutes, in the $2$-nd — for $1$ minute, in the $3$-rd - for $2$ minutes;
3. the $3$-rd singer in the $1$-st city will give a concert for $6$ minutes, in the $2$-nd — for $9$ minutes, in the $3$-rd — for $3$ minutes.


#### Tags 

#1700 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_760_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
