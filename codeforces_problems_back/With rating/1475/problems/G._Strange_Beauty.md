<h1 style='text-align: center;'> G. Strange Beauty</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp found on the street an array $a$ of $n$ elements.

Polycarp invented his criterion for the beauty of an array. He calls an array $a$ beautiful if at least one of the following conditions must be met for each different pair of indices $i \ne j$: 

* $a_i$ is divisible by $a_j$;
* or $a_j$ is divisible by $a_i$.

For example, if: 

* $n=5$ and $a=[7, 9, 3, 14, 63]$, then the $a$ array is not beautiful (for $i=4$ and $j=2$, none of the conditions above is met);
* $n=3$ and $a=[2, 14, 42]$, then the $a$ array is beautiful;
* $n=4$ and $a=[45, 9, 3, 18]$, then the $a$ array is not beautiful (for $i=1$ and $j=4$ none of the conditions above is met);

Ugly arrays upset Polycarp, so he wants to remove some elements from the array $a$ so that it becomes beautiful. Help Polycarp determine the smallest number of elements to remove to make the array $a$ beautiful.

## Input

The first line contains one integer $t$ ($1 \leq t \leq 10$) — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains one integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ numbers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 2 \cdot 10^5$) — elements of the array $a$.

## Output

For each test case output one integer — the minimum number of elements that must be removed to make the array $a$ beautiful.

## Example

## Input


```

4
5
7 9 3 14 63
3
2 14 42
4
45 9 3 18
3
2 2 8

```
## Output


```

2
0
1
0

```
## Note

In the first test case, removing $7$ and $14$ will make array $a$ beautiful.

In the second test case, the array $a$ is already beautiful.

In the third test case, removing one of the elements $45$ or $18$ will make the array $a$ beautiful.

In the fourth test case, the array $a$ is beautiful.



#### tags 

#1900 #dp #math #number_theory #sortings 