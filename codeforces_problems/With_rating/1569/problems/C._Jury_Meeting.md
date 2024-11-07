<h1 style='text-align: center;'> C. Jury Meeting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ people gathered to hold a jury meeting of the upcoming competition, the $i$-th member of the jury came up with $a_i$ tasks, which they want to share with each other.

First, the jury decides on the order which they will follow while describing the tasks. Let that be a permutation $p$ of numbers from $1$ to $n$ (an array of size $n$ where each integer from $1$ to $n$ occurs exactly once).

Then the discussion goes as follows:

* If a jury member $p_1$ has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
* If a jury member $p_2$ has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
* ...
* If a jury member $p_n$ has some tasks left to tell, then they tell one task to others. Otherwise, they are skipped.
* If there are still members with tasks left, then the process repeats from the start. Otherwise, the discussion ends.

A permutation $p$ is nice if none of the jury members tell two or more of their own tasks in a row. 

Count the number of nice permutations. The answer may be really large, so print it modulo $998\,244\,353$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of the test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — number of jury members.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the number of problems that the $i$-th member of the jury came up with.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the number of nice permutations, taken modulo $998\,244\,353$.

## Example

### Input


```text
4
2
1 2
3
5 5 5
4
1 3 3 7
6
3 4 2 1 3 3
```
### Output


```text
1
6
0
540
```
## Note

Explanation of the first test case from the example:

There are two possible permutations, $p = [1, 2]$ and $p = [2, 1]$. For $p = [1, 2]$, the process is the following:

1. the first jury member tells a task;
2. the second jury member tells a task;
3. the first jury member doesn't have any tasks left to tell, so they are skipped;
4. the second jury member tells a task.

So, the second jury member has told two tasks in a row (in succession), so the permutation is not nice.

For $p = [2, 1]$, the process is the following:

1. the second jury member tells a task;
2. the first jury member tells a task;
3. the second jury member tells a task.

So, this permutation is nice.



#### Tags 

#1500 #NOT OK #combinatorics #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_113_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
