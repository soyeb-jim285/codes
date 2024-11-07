<h1 style='text-align: center;'> F. Make It Ascending</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ consisting of $n$ elements. You may apply several operations (possibly zero) to it.

During each operation, you choose two indices $i$ and $j$ ($1 \le i, j \le n$; $i \ne j$), increase $a_j$ by $a_i$, and remove the $i$-th element from the array (so the indices of all elements to the right to it decrease by $1$, and $n$ also decreases by $1$).

Your goal is to make the array $a$ strictly ascending. That is, the condition $a_1 < a_2 < \dots < a_n$ should hold (where $n$ is the resulting size of the array).

Calculate the minimum number of actions required to make the array strictly ascending.

### Input

The first line contains one integer $T$ ($1 \le T \le 10000$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $n$ ($1 \le n \le 15$) — the number of elements in the initial array $a$.

The second line contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($1 \le a_i \le 10^6$).

It is guaranteed that: 

* the number of test cases having $n \ge 5$ is not greater than $5000$;
* the number of test cases having $n \ge 8$ is not greater than $500$;
* the number of test cases having $n \ge 10$ is not greater than $100$;
* the number of test cases having $n \ge 11$ is not greater than $50$;
* the number of test cases having $n \ge 12$ is not greater than $25$;
* the number of test cases having $n \ge 13$ is not greater than $10$;
* the number of test cases having $n \ge 14$ is not greater than $3$;
* the number of test cases having $n \ge 15$ is not greater than $1$.
### Output

For each test case, print the answer as follows:

In the first line, print $k$ — the minimum number of operations you have to perform. Then print $k$ lines, each containing two indices $i$ and $j$ for the corresponding operation. 
## Note

 that the numeration of elements in the array changes after removing elements from it. If there are multiple optimal sequences of operations, print any one of them.

## Example

### Input


```text
4
8
2 1 3 5 1 2 4 5
15
16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
2
3 3
14
1 2 3 4 5 6 7 8 9 10 11 12 13 14
```
### Output


```text
3
6 8
1 6
4 1
7
1 15
1 13
1 11
1 9
1 7
1 5
1 3
1
2 1
0
```
## Note

In the first test case, the sequence of operations changes $a$ as follows:

$[2, 1, 3, 5, 1, 2, 4, 5] \rightarrow [2, 1, 3, 5, 1, 4, 7] \rightarrow [1, 3, 5, 1, 6, 7] \rightarrow [2, 3, 5, 6, 7]$.



#### Tags 

#3000 #NOT OK #bitmasks #brute_force #dp 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_86_(Rated_for_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
