<h1 style='text-align: center;'> C. Good Prefixes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alex thinks some array is good if there exists some element that can be represented as the sum of all other elements (the sum of all other elements is $0$ if there are no other elements). For example, the array $[1,6,3,2]$ is good since $1+3+2=6$. Furthermore, the array $[0]$ is also good. However, the arrays $[1,2,3,4]$ and $[1]$ are not good.

Alex has an array $a_1,a_2,\ldots,a_n$. Help him count the number of good non-empty prefixes of the array $a$. In other words, count the number of integers $i$ ($1 \le i \le n$) such that the length $i$ prefix (i.e. $a_1,a_2,\ldots,a_i$) is good.

### Input

The first line of the input contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of elements in the array.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0 \le a_i \le 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. 

### Output

For each test case, output a single integer — the number of good non-empty prefixes of the array $a$.

## Example

### Input


```text
7101141 1 2 050 1 2 1 471 1 0 3 5 2 1271000000000 1000000000 1000000000 1000000000 1000000000 1000000000 294967296100 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 589934592
```
### Output

```text

1
0
3
3
4
1
2

```
## Note

In the fourth test case, the array has five prefixes: 

* prefix $[0]$ is a good array, as mentioned in the statement;
* prefix $[0, 1]$ is not a good array, since $0 \ne 1$;
* prefix $[0, 1, 2]$ is not a good array, since $0 \ne 1 + 2$, $1 \ne 0 + 2$ and $2 \ne 0 + 1$;
* prefix $[0, 1, 2, 1]$ is a good array, since $2 = 0 + 1 + 1$;
* prefix $[0, 1, 2, 1, 4]$ is a good array, since $4 = 0 + 1 + 2 + 1$.

As you can see, three of them are good, so the answer is $3$.



#### Tags 

#1000 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_952_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
