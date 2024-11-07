<h1 style='text-align: center;'> C. Delete Two Elements</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has got an array $a$ consisting of $n$ integers. Let's denote $k$ as the mathematic mean of these elements (note that it's possible that $k$ is not an integer). 

The mathematic mean of an array of $n$ elements is the sum of elements divided by the number of these elements (i. e. sum divided by $n$).

Monocarp wants to delete exactly two elements from $a$ so that the mathematic mean of the remaining $(n - 2)$ elements is still equal to $k$.

Your task is to calculate the number of pairs of positions $[i, j]$ ($i < j$) such that if the elements on these positions are deleted, the mathematic mean of $(n - 2)$ remaining elements is equal to $k$ (that is, it is equal to the mathematic mean of $n$ elements of the original array $a$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains one integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the number of elements in the array.

The second line contains a sequence of integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 10^{9}$), where $a_i$ is the $i$-th element of the array.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

Print one integer — the number of pairs of positions $[i, j]$ ($i < j$) such that if the elements on these positions are deleted, the mathematic mean of $(n - 2)$ remaining elements is equal to $k$ (that is, it is equal to the mathematic mean of $n$ elements of the original array $a$).

## Example

## Input


```

4
4
8 8 8 8
3
50 20 10
5
1 4 7 3 5
7
1 2 3 4 5 6 7

```
## Output


```

6
0
2
3

```
## Note

In the first example, any pair of elements can be removed since all of them are equal.

In the second example, there is no way to delete two elements so the mathematic mean doesn't change.

In the third example, it is possible to delete the elements on positions $1$ and $3$, or the elements on positions $4$ and $5$.



#### tags 

#1200 #data_structures #dp #implementation #math #two_pointers 