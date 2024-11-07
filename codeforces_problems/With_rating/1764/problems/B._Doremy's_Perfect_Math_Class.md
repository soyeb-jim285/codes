<h1 style='text-align: center;'> B. Doremy's Perfect Math Class</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

"Everybody! Doremy's Perfect Math Class is about to start! Come and do your best if you want to have as much IQ as me!" In today's math class, Doremy is teaching everyone subtraction. Now she gives you a quiz to prove that you are paying attention in class.

You are given a set $S$ containing positive integers. You may perform the following operation some (possibly zero) number of times:

* choose two integers $x$ and $y$ from the set $S$ such that $x > y$ and $x - y$ is not in the set $S$.
* add $x-y$ into the set $S$.

You need to tell Doremy the maximum possible number of integers in $S$ if the operations are performed optimally. It can be proven that this number is finite.

### Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of the test cases follows.

The first line contains an integer $n$ ($2 \le n\le 10^5$) — the size of the set $S$.

The second line contains $n$ integers $a_1,a_2,\dots,a_n$ ($1\le a_1 < a_2 < \cdots < a_n \le 10^9$) — the positive integers in $S$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, you need to output the maximum possible number of integers in $S$. It can be proven that this value is finite.

## Example

### Input


```text
221 235 10 25
```
### Output

```text

2
5

```
## Note

In the first test case, no such $x$ and $y$ exist. The maximum possible number of integers in $S$ is $2$.

In the second test case,

* $S=\{5,10,25\}$ at first. You can choose $x=25$, $y=10$, then add $x-y=15$ to the set.
* $S=\{5,10,15,25\}$ now. You can choose $x=25$, $y=5$, then add $x-y=20$ to the set.
* $S=\{5,10,15,20,25\}$ now. You can not perform any operation now.

After performing all operations, the number of integers in $S$ is $5$. It can be proven that no other sequence of operations allows $S$ to contain more than $5$ integers.



#### Tags 

#900 #NOT OK #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_24.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
