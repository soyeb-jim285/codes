<h1 style='text-align: center;'> D. Different Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ consisting of $n$ integers.

You have to perform the sequence of $n-2$ operations on this array:

* during the first operation, you either add $a_2$ to $a_1$ and subtract $a_2$ from $a_3$, or add $a_2$ to $a_3$ and subtract $a_2$ from $a_1$;
* during the second operation, you either add $a_3$ to $a_2$ and subtract $a_3$ from $a_4$, or add $a_3$ to $a_4$ and subtract $a_3$ from $a_2$;
* ...
* during the last operation, you either add $a_{n-1}$ to $a_{n-2}$ and subtract $a_{n-1}$ from $a_n$, or add $a_{n-1}$ to $a_n$ and subtract $a_{n-1}$ from $a_{n-2}$.

So, during the $i$-th operation, you add the value of $a_{i+1}$ to one of its neighbors, and subtract it from the other neighbor.

For example, if you have the array $[1, 2, 3, 4, 5]$, one of the possible sequences of operations is:

* subtract $2$ from $a_3$ and add it to $a_1$, so the array becomes $[3, 2, 1, 4, 5]$;
* subtract $1$ from $a_2$ and add it to $a_4$, so the array becomes $[3, 1, 1, 5, 5]$;
* subtract $5$ from $a_3$ and add it to $a_5$, so the array becomes $[3, 1, -4, 5, 10]$.

So, the resulting array is $[3, 1, -4, 5, 10]$.

An array is reachable if it can be obtained by performing the aforementioned sequence of operations on $a$. You have to calculate the number of reachable arrays, and print it modulo $998244353$.

#### Input

The first line contains one integer $n$ ($3 \le n \le 300$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 300$).

#### Output

Print one integer — the number of reachable arrays. Since the answer can be very large, print its remainder modulo $998244353$.

## Examples

#### Input


```text
4
1 1 1 1
```
#### Output


```text
3
```
#### Input


```text
5
1 2 3 5 0
```
#### Output


```text
7
```


#### Tags 

#2000 #NOT OK #brute_force #dp #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_141_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
