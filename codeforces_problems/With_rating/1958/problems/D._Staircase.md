<h1 style='text-align: center;'> D. Staircase</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There is a staircase consisting of $n$ steps. Each step is either intact, or broken. For each broken step, an integer $a_i$ is given denoting the difficulty of repairing it.

Every day, you can either:

* repair an arbitrary broken step. The effort it takes to repair the $i$-th step is equal to $a_i$;
* or repair two adjacent broken steps. The effort it takes to repair both the $i$-th step and the $(i+1)$-th step is equal to $2 \cdot (a_i+a_{i+1})$.

You want to repair all broken steps of the staircase, and you want to do it in the minimum possible number of days. What is the minimum total effort it will take to repair all broken steps in the minimum number of days?

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of two lines:

* the first line contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of steps;
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 10^8$). If $a_i = 0$, then the $i$-th step does not need to be repaired; otherwise, the $i$-th step is broken and $a_i$ is the difficulty of repairing it.

Additional constraint on the input: the sum of values of $n$ does not exceed $3 \cdot 10^5$.

### Output

For each test case, print one integer — the minimum possible total effort it will take to repair all broken steps in the minimum number of days.

## Example

### Input


```text
650 0 0 0 040 13 15 8413 15 0 881 2 3 4 5 6 7 8599999999 100000000 99999999 99999999 9999999952 3 4 3 2
```
### Output

```text

0
59
64
72
899999993
24

```
## Note

In the first test case, you don't have to do anything.

In the second test case, you can repair the $3$-rd and the $4$-th step during the first day, and the $2$-nd step during the second day. The total effort will be $2 \cdot (15 + 8) + 13 = 59$.

In the third test case, you can repair the $4$-th step during the first day, and two first steps during the second day. The total effort will be $8 + 2 \cdot (13 + 15) = 64$.



#### Tags 

#1600 #NOT OK #*special 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_10.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
