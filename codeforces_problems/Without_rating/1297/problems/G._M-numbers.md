<h1 style='text-align: center;'> G. M-numbers</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For a given positive integer $m$, a positive number is called a $m$-number if the product of its digits is $m$. For example, the beginning of a series of $24$-numbers are as follows: $38$, $46$, $64$, $83$, $138$, $146$, $164$, $183$, $226$ ...

You are given a positive integer $m$ and $k$. Print $k$-th among $m$-numbers if all $m$-numbers are sorted in ascending order.

###### Input

A single line of input contains two integers $m$ and $k$ ($2 \le m \le 10^9$, $1 \le k \le 10^9$).

###### Output

Print the desired number — $k$-th among all $m$-numbers if $m$-numbers are sorted in ascending order. If the answer does not exist, print -1.

## Examples

###### Input


```text
24 9
```
###### Output


```text
226
```
###### Input


```text
24 1
```
###### Output


```text
38
```
###### Input


```text
5040 1000000000
```
###### Output


```text
111121111315213227111
```
###### Input


```text
2020 2020
```
###### Output


```text
-1
```


#### Tags 

#NOT OK #*special #dp #math 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_3.md)
- [Kotlin Heroes: Episode 3 (en)](../blogs/Kotlin_Heroes:_Episode_3_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
