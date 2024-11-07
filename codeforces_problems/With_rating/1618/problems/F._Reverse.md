<h1 style='text-align: center;'> F. Reverse</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two positive integers $x$ and $y$. You can perform the following operation with $x$: write it in its binary form without leading zeros, add $0$ or $1$ to the right of it, reverse the binary form and turn it into a decimal number which is assigned as the new value of $x$.

For example: 

* $34$ can be turned into $81$ via one operation: the binary form of $34$ is $100010$, if you add $1$, reverse it and remove leading zeros, you will get $1010001$, which is the binary form of $81$.
* $34$ can be turned into $17$ via one operation: the binary form of $34$ is $100010$, if you add $0$, reverse it and remove leading zeros, you will get $10001$, which is the binary form of $17$.
* $81$ can be turned into $69$ via one operation: the binary form of $81$ is $1010001$, if you add $0$, reverse it and remove leading zeros, you will get $1000101$, which is the binary form of $69$.
* $34$ can be turned into $69$ via two operations: first you turn $34$ into $81$ and then $81$ into $69$.

Your task is to find out whether $x$ can be turned into $y$ after a certain number of operations (possibly zero).

####### Input

The only line of the input contains two integers $x$ and $y$ ($1 \le x, y \le 10^{18}$).

####### Output

Print YES if you can make $x$ equal to $y$ and NO if you can't.

## Examples

####### Input


```text
3 3
```
####### Output


```text
YES
```
####### Input


```text
7 4
```
####### Output


```text
NO
```
####### Input


```text
2 8
```
####### Output


```text
NO
```
####### Input


```text
34 69
```
####### Output


```text
YES
```
####### Input


```text
8935891487501725 71487131900013807
```
####### Output


```text
YES
```
## Note

In the first example, you don't even need to do anything.

The fourth example is described in the statement.



#### Tags 

#2000 #NOT OK #bitmasks #constructive_algorithms #dfs_and_similar #implementation #math #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_760_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
