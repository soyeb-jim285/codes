<h1 style='text-align: center;'> B. Maximum Rounding</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a natural number $x$. You can perform the following operation: 

* choose a positive integer $k$ and round $x$ to the $k$-th digit

## Note

 that the positions are numbered from right to left, starting from zero. If the number has $k$ digits, it is considered that the digit at the $k$-th position is equal to $0$.

The rounding is done as follows: 

* if the digit at the $(k-1)$-th position is greater than or equal to $5$, then the digit at the $k$-th position is increased by $1$, otherwise the digit at the $k$-th position remains unchanged (mathematical rounding is used).
* if before the operations the digit at the $k$-th position was $9$, and it should be increased by $1$, then we search for the least position $k'$ ($k'>k$), where the digit at the $k'$-th position is less than $9$ and add $1$ to the digit at the $k'$-th position. Then we assign $k=k'$.
* after that, all digits which positions are less than $k$ are replaced with zeros.

Your task is to make $x$ as large as possible, if you can perform the operation as many times as you want.

For example, if $x$ is equal to $3451$, then if you choose consecutively: 

* $k=1$, then after the operation $x$ will become $3450$
* $k=2$, then after the operation $x$ will become $3500$
* $k=3$, then after the operation $x$ will become $4000$
* $k=4$, then after the operation $x$ will become $0$

 To maximize the answer, you need to choose $k=2$ first, and then $k=3$, then the number will become $4000$.
### Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases.

Each test case consists of positive integer $x$ with a length of up to $2 \cdot 10^5$. It is guaranteed that there are no leading zeros in the integer.

It is guaranteed that the sum of the lengths of all integers $x$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each set of input data, output the maximum possible value of $x$ after the operations. The number should not have leading zeros in its representation.

## Example

### Input


```text
101599913198020444204456094741986040862016542130810467
```
### Output

```text

1
10
100
1000
2000
20444
21000
100000
420000
41000000000000000000

```
## Note

In the first sample, it is better not to perform any operations.

In the second sample, you can perform one operation and obtain $10$.

In the third sample, you can choose $k=1$ or $k=2$. In both cases the answer will be $100$.



#### Tags 

#1100 #OK #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_891_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
