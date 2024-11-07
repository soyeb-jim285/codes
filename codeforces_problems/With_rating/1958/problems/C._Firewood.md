<h1 style='text-align: center;'> C. Firewood</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

It's pretty cold in Berland (yes, even in May). So Monocarp has to light his fireplace.

Monocarp has a big log of wood, which weighs $2^n$ grams. Monocarp has watched the weather forecast and decided that he has to burn $k$ grams of wood in the fireplace today, and the remaining $2^n-k$ grams of wood will be used tomorrow.

In one minute, Monocarp can use his saw to split one of his logs in half. Initially he has only one log, but of course, after splitting a log, he gets two new logs. If the weight of the log is $x$, then each of the resulting logs has weight equal to $\frac{x}{2}$. Monocarp can't split logs of weight $1$ gram.

Monocarp has to cut his log in such a way that some of the resulting logs weigh exactly $k$ grams in total (and since the total weight of wood doesn't change, the remaining logs will have a total weight equal to exactly $2^n-k$). Help him to calculate the minimum number of minutes he has to spend cutting the logs.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of one line containing two integers $n$ and $k$ ($1 \le n \le 60$; $1 \le k \le 2^n-1$). 

### Output

For each test case, print one integer — the minimum number of minutes Monocarp has to spend splitting the wood.

## Example

### Input


```text
42 22 110 350 36679020707840
```
### Output

```text

1
2
10
16

```
## Note

In the first test case, Monocarp has to cut his log exactly once. Then he will have two logs weighing $2$ grams each.

In the second test case, Monocarp has to cut his log of $4$ grams once, then cut one of the resulting logs. He will have one log of weight $2$ and two logs of weight $1$, so he can use two logs to get exactly $3$ grams.



#### Tags 

#1500 #NOT OK #*special 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_10.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
