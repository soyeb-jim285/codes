<h1 style='text-align: center;'> C. Can I Square?</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Calin has $n$ buckets, the $i$-th of which contains $a_i$ wooden squares of side length $1$.

Can Calin build a square using all the given squares?

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of buckets.

The second line of each test case contains $n$ integers $a_1, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the number of squares in each bucket.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output "YES" if Calin can build a square using all of the given $1 \times 1$ squares, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

### Input


```text
519214 271 2 3 4 5 6 761 3 5 7 9 1142 2 2 2
```
### Output

```text

YES
YES
NO
YES
NO

```
## Note

In the first test case, Calin can build a $3 \times 3$ square.

In the second test case, Calin can build a $4 \times 4$ square.

In the third test case, Calin cannot build a square using all the given squares.



#### Tags 

#800 #OK #binary_search #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_918_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
