<h1 style='text-align: center;'> D. XOR-gun</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Arkady owns a non-decreasing array $a_1, a_2, \ldots, a_n$. You are jealous of its beauty and want to destroy this property. You have a so-called XOR-gun that you can use one or more times.

In one step you can select two consecutive elements of the array, let's say $x$ and $y$, remove them from the array and insert the integer $x \oplus y$ on their place, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR). 
## Note

 that the length of the array decreases by one after the operation. You can't perform this operation when the length of the array reaches one.

For example, if the array is $[2, 5, 6, 8]$, you can select $5$ and $6$ and replace them with $5 \oplus 6 = 3$. The array becomes $[2, 3, 8]$.

You want the array no longer be non-decreasing. What is the minimum number of steps needed? If the array stays non-decreasing no matter what you do, print $-1$.

##### Input

The first line contains a single integer $n$ ($2 \le n \le 10^5$) — the initial length of the array.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array. It is guaranteed that $a_i \le a_{i + 1}$ for all $1 \le i < n$.

##### Output

Print a single integer — the minimum number of steps needed. If there is no solution, print $-1$.

## Examples

##### Input


```text
4
2 5 6 8
```
##### Output


```text
1
```
##### Input


```text
3
1 2 3
```
##### Output


```text
-1
```
##### Input


```text
5
1 2 4 6 20
```
##### Output


```text
2
```
## Note

In the first example you can select $2$ and $5$ and the array becomes $[7, 6, 8]$.

In the second example you can only obtain arrays $[1, 1]$, $[3, 3]$ and $[0]$ which are all non-decreasing.

In the third example you can select $1$ and $2$ and the array becomes $[3, 4, 6, 20]$. Then you can, for example, select $3$ and $4$ and the array becomes $[7, 6, 20]$, which is no longer non-decreasing.



#### Tags 

#2000 #NOT OK #bitmasks #brute_force #constructive_algorithms 

## Blogs
- [All Contest Problems](../Technocup_2021_-_Elimination_Round_2.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
