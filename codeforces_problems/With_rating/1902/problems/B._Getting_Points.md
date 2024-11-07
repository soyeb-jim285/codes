<h1 style='text-align: center;'> B. Getting Points</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is a student at Berland State University. Due to recent changes in the Berland education system, Monocarp has to study only one subject — programming.

The academic term consists of $n$ days, and in order not to get expelled, Monocarp has to earn at least $P$ points during those $n$ days. There are two ways to earn points — completing practical tasks and attending lessons. For each practical task Monocarp fulfills, he earns $t$ points, and for each lesson he attends, he earns $l$ points.

Practical tasks are unlocked "each week" as the term goes on: the first task is unlocked on day $1$ (and can be completed on any day from $1$ to $n$), the second task is unlocked on day $8$ (and can be completed on any day from $8$ to $n$), the third task is unlocked on day $15$, and so on.

Every day from $1$ to $n$, there is a lesson which can be attended by Monocarp. And every day, Monocarp chooses whether to study or to rest the whole day. When Monocarp decides to study, he attends a lesson and can complete no more than $2$ tasks, which are already unlocked and not completed yet. If Monocarp rests the whole day, he skips a lesson and ignores tasks.

Monocarp wants to have as many days off as possible, i. e. he wants to maximize the number of days he rests. Help him calculate the maximum number of days he can rest!

### Input

The first line contains a single integer $tc$ ($1 \le tc \le 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains four integers $n$, $P$, $l$ and $t$ ($1 \le n, l, t \le 10^9$; $1 \le P \le 10^{18}$) — the number of days, the minimum total points Monocarp has to earn, the points for attending one lesson and points for completing one task.

It's guaranteed for each test case that it's possible not to be expelled if Monocarp will attend all lessons and will complete all tasks.

### Output

For each test, print one integer — the maximum number of days Monocarp can rest without being expelled from University.

## Example

### Input


```text
51 5 5 214 3000000000 1000000000 500000000100 20 1 108 120 10 2042 280 13 37
```
### Output

```text

0
12
99
0
37

```
## Note

In the first test case, the term lasts for $1$ day, so Monocarp should attend at day $1$. Since attending one lesson already gives $5$ points ($5 \ge P$), so it doesn't matter, will Monocarp complete the task or not.

In the second test case, Monocarp can, for example, study at days $8$ and $9$: at day $8$ he will attend a lesson for $10^9$ points and complete two tasks for another $5 \cdot 10^8 + 5 \cdot 10^8$ points. And at day $9$ he only attends a lesson for another $10^9$ points.

In the third test case, Monocarp can, for example, study at day $42$: attending a lesson gives him $1$ point and solving $2$ out of $6$ available tasks gives him another $2 \cdot 10$ points.

In the fourth test case, Monocarp has to attend all lessons and complete all tasks to get $8 \cdot 10 + 2 \cdot 20 = 120$ points.

In the fifth test case, Monocarp can, for example, study at days: $8$ — one lesson and first and second tasks; $15$ — one lesson and the third task; $22$ — one lesson and the fourth task; $29$ — one lesson and the fifth task; $36$ — one lesson and the sixth task.



#### Tags 

#1100 #NOT OK #binary_search #brute_force #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_159_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
