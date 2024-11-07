<h1 style='text-align: center;'> G. Sorting Pancakes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nastya baked $m$ pancakes and spread them on $n$ dishes. The dishes are in a row and numbered from left to right. She put $a_i$ pancakes on the dish with the index $i$.

Seeing the dishes, Vlad decided to bring order to the stacks and move some pancakes. In one move, he can shift one pancake from any dish to the closest one, that is, select the dish $i$ ($a_i > 0$) and do one of the following:

* if $i > 1$, put the pancake on a dish with the previous index, after this move $a_i = a_i - 1$ and $a_{i - 1} = a_{i - 1} + 1$;
* if $i < n$, put the pancake on a dish with the following index, after this move $a_i = a_i - 1$ and $a_{i + 1} = a_{i + 1} + 1$.

Vlad wants to make the array $a$non-increasing, after moving as few pancakes as possible. Help him find the minimum number of moves needed for this.

The array $a=[a_1, a_2,\dots,a_n]$ is called non-increasing if $a_i \ge a_{i+1}$ for all $i$ from $1$ to $n-1$.

####### Input

The first line of the input contains two numbers $n$ and $m$ ($1 \le n, m \le 250$) — the number of dishes and the number of pancakes, respectively.

The second line contains $n$ numbers $a_i$ ($0 \le a_i \le m$), the sum of all $a_i$ is equal to $m$.

####### Output

Print a single number: the minimum number of moves required to make the array $a$ non-increasing.

## Examples

####### Input


```text
6 19
5 3 2 3 3 3
```
####### Output


```text
2
```
####### Input


```text
3 6
3 2 1
```
####### Output


```text
0
```
####### Input


```text
3 6
2 1 3
```
####### Output


```text
1
```
####### Input


```text
6 19
3 4 3 3 5 1
```
####### Output


```text
3
```
####### Input


```text
10 1
0 0 0 0 0 0 0 0 0 1
```
####### Output


```text
9
```
## Note

In the first example, you first need to move the pancake from the dish $1$, after which $a = [4, 4, 2, 3, 3, 3]$. After that, you need to move the pancake from the dish $2$ to the dish $3$ and the array will become non-growing $a = [4, 3, 3, 3, 3, 3]$.



#### Tags 

#2300 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_787_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
