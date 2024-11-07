<h1 style='text-align: center;'> D. Turtle and Multiplication</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Turtle just learned how to multiply two integers in his math class, and he was very excited.

Then Piggy gave him an integer $n$, and asked him to construct a sequence $a_1, a_2, \ldots, a_n$ consisting of integers which satisfied the following conditions:

* For all $1 \le i \le n$, $1 \le a_i \le 3 \cdot 10^5$.
* For all $1 \le i < j \le n - 1$, $a_i \cdot a_{i + 1} \ne a_j \cdot a_{j + 1}$.

Of all such sequences, Piggy asked Turtle to find the one with the minimum number of distinct elements.

Turtle definitely could not solve the problem, so please help him!

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^6$) — the length of the sequence $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, output $n$ integers $a_1, a_2, \ldots, a_n$ — the elements of the sequence $a$.

If there are multiple answers, print any of them.

## Example

### Input


```text
3234
```
### Output

```text

114514 114514
1 2 2
3 3 4 4

```
## Note

In the third test case, $a = [3, 4, 2, 6]$ violates the second condition since $a_1 \cdot a_2 = a_3 \cdot a_4$. $a = [2, 3, 4, 4]$ satisfy the conditions but its number of distinct elements isn't minimum.



#### Tags 

#2400 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_949_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
