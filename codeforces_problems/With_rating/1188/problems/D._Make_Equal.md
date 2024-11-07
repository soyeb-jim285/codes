<h1 style='text-align: center;'> D. Make Equal</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ numbers $a_1, a_2, \dots, a_n$. In one operation we can add to any one of those numbers a nonnegative integer power of $2$.

What is the smallest number of operations we need to perform to make all $n$ numbers equal? It can be proved that under given constraints it doesn't exceed $10^{18}$.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^{17}$).

#### Output

#### Output

 exactly one integer — the smallest number of operations we need to perform to make all $n$ numbers equal.

## Examples

#### Input


```text
4
228 228 228 228
```
#### Output


```text
0
```
#### Input

```text

3
2 2 8

```
#### Output


```text

3
```
## Note

In the first example, all numbers are already equal. So the needed number of operation is $0$.

In the second example, we can apply the operation $3$ times: add $8$ to first $2$, add $8$ to second $2$, add $2$ to $8$, making all numbers equal to $10$. It can be proved that we can't make all numbers equal in less than $3$ operations.



#### Tags 

#3100 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_572_(Div._1).md)
- [Codeforces Round #572](../blogs/Codeforces_Round_572.md)
- [Tutorial](../blogs/Tutorial.md)
