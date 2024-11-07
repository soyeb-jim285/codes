<h1 style='text-align: center;'> I. Stairs</h1>

<h5 style='text-align: center;'>time limit per test: 10 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

For a permutation $p$ of numbers $1$ through $n$, we define a stair array $a$ as follows: $a_i$ is length of the longest segment of permutation which contains position $i$ and is made of consecutive values in sorted order: $[x, x+1, \ldots, y-1, y]$ or $[y, y-1, \ldots, x+1, x]$ for some $x \leq y$. For example, for permutation $p = [4, 1, 2, 3, 7, 6, 5]$ we have $a = [1, 3, 3, 3, 3, 3, 3]$. 

You are given the stair array $a$. Your task is to calculate the number of permutations which have stair array equal to $a$. Since the number can be big, compute it modulo $998\,244\,353$. Note that this number can be equal to zero.

####### Input

The first line of input contains integer $n$ ($1 \le n \le 10^5$)  — the length of a stair array $a$.

The second line of input contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$).

####### Output

Print the number of permutations which have stair array equal to $a$. Since the number can be big, compute it modulo $998\,244\,353$.

## Examples

####### Input


```text
6
3 3 3 1 1 1
```
####### Output


```text
6
```
####### Input


```text
7
4 4 4 4 3 3 3
```
####### Output


```text
6
```
####### Input


```text
1
1
```
####### Output


```text
1
```
####### Input


```text
8
2 2 2 2 2 2 1 1
```
####### Output


```text
370
```
####### Input


```text
4
3 2 3 1
```
####### Output


```text
0
```


#### Tags 

#3400 #NOT OK #combinatorics #divide_and_conquer #dp #fft #math 

## Blogs
- [All Contest Problems](../Harbour.Space_Scholarship_Contest_2021-2022_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
