<h1 style='text-align: center;'> A. Guess the Maximum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob came up with a rather strange game. They have an array of integers $a_1, a_2,\ldots, a_n$. Alice chooses a certain integer $k$ and tells it to Bob, then the following happens:

* Bob chooses two integers $i$ and $j$ ($1 \le i < j \le n$), and then finds the maximum among the integers $a_i, a_{i + 1},\ldots, a_j$;
* If the obtained maximum is strictly greater than $k$, Alice wins, otherwise Bob wins.

Help Alice find the maximum $k$ at which she is guaranteed to win.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 5 \cdot 10^4$) — the number of elements in the array.

The second line of each test case contains $n$ integers $a_1, a_2,\ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^4$.

### Output

For each test case, output one integer — the maximum integer $k$ at which Alice is guaranteed to win.

## Example

### Input


```text
642 4 1 751 2 3 4 521 1337 8 16510 10 10 10 9103 12 9 5 2 3 2 9 8 2
```
### Output

```text

3
1
0
15
9
2

```
## Note

In the first test case, all possible subsegments that Bob can choose look as follows: $[2, 4], [2, 4, 1], [2, 4, 1, 7], [4, 1], [4, 1, 7], [1, 7]$. The maximums on the subsegments are respectively equal to $4, 4, 7, 4, 7, 7$. It can be shown that $3$ is the largest integer such that any of the maximums will be strictly greater than it.

In the third test case, the only segment that Bob can choose is $[1, 1]$. So the answer is $0$.



#### Tags 

#800 #NOT OK #brute_force #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_951_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
