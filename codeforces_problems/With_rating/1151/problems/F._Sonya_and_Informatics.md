<h1 style='text-align: center;'> F. Sonya and Informatics</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A girl named Sonya is studying in the scientific lyceum of the Kingdom of Kremland. The teacher of computer science (Sonya's favorite subject!) invented a task for her.

Given an array $a$ of length $n$, consisting only of the numbers $0$ and $1$, and the number $k$. Exactly $k$ times the following happens: 

* Two numbers $i$ and $j$ are chosen equiprobable such that ($1 \leq i < j \leq n$).
* The numbers in the $i$ and $j$ positions are swapped.

Sonya's task is to find the probability that after all the operations are completed, the $a$ array will be sorted in non-decreasing order. She turned to you for help. Help Sonya solve this problem.

It can be shown that the desired probability is either $0$ or it can be represented as $\dfrac{P}{Q}$, where $P$ and $Q$ are coprime integers and $Q \not\equiv 0~\pmod {10^9+7}$.

##### Input

The first line contains two integers $n$ and $k$ ($2 \leq n \leq 100, 1 \leq k \leq 10^9$) — the length of the array $a$ and the number of operations.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 1$) — the description of the array $a$.

##### Output

If the desired probability is $0$, print $0$, otherwise print the value $P \cdot Q^{-1}$ $\pmod {10^9+7}$, where $P$ and $Q$ are defined above.

## Examples

##### Input


```text
3 2
0 1 0
```
##### Output


```text
333333336
```
##### Input

```text

5 1
1 1 1 0 0

```
##### Output


```text
0
```
##### Input

```text

6 4
1 0 0 1 1 0

```
##### Output


```text

968493834
```
## Note

In the first example, all possible variants of the final array $a$, after applying exactly two operations: $(0, 1, 0)$, $(0, 0, 1)$, $(1, 0, 0)$, $(1, 0, 0)$, $(0, 1, 0)$, $(0, 0, 1)$, $(0, 0, 1)$, $(1, 0, 0)$, $(0, 1, 0)$. Therefore, the answer is $\dfrac{3}{9}=\dfrac{1}{3}$.

In the second example, the array will not be sorted in non-decreasing order after one operation, therefore the answer is $0$.



#### Tags 

#2300 #NOT OK #combinatorics #dp #matrices #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_553_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
