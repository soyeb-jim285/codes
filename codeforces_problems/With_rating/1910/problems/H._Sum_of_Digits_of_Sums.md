<h1 style='text-align: center;'> H. Sum of Digits of Sums</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $[a_1, a_2, \dots, a_n]$, consisting of positive integers.

For every $i$ from $1$ to $n$, calculate $\sum \limits_{j=1}^{n} F(a_i + a_j)$, where $F(x)$ is the sum of digits of $x$.

#### Input

The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i < 10^9$).

#### Output

Print $n$ integers. The $i$-th of them should be equal to $\sum \limits_{j=1}^{n} F(a_i + a_j)$.

## Examples

#### Input


```text
4
1 3 3 7
```
#### Output


```text
18 17 17 15 
```
#### Input


```text
3
42 1337 999
```
#### Output


```text
38 53 47 
```


#### Tags 

#2400 #NOT OK #*special #binary_search #data_structures 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_9_(Unrated,_T-Shirts_+_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
