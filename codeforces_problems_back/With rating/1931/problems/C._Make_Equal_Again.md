<h1 style='text-align: center;'> C. Make Equal Again</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of $n$ integers. 

You can no more than once apply the following operation: select three integers $i$, $j$, $x$ ($1 \le i \le j \le n$) and assign all elements of the array with indexes from $i$ to $j$ the value $x$. The price of this operation depends on the selected indices and is equal to $(j - i + 1)$ burles. 

For example, the array is equal to $[1, 2, 3, 4, 5, 1]$. If we choose $i = 2, j = 4, x = 8$, then after applying this operation, the array will be equal to $[1, 8, 8, 8, 5, 1]$.

What is the least amount of burles you need to spend to make all the elements of the array equal?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of input test cases. The descriptions of the test cases follow.

The first line of the description of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10 ^ 5$) — the size of the array.

The second line of the description of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — array elements.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output one integer — the minimum number of burles that will have to be spent to make all the elements of the array equal. It can be shown that this can always be done.

## Example

## Input


```

861 2 3 4 5 171 1 1 1 1 1 188 8 8 1 2 8 8 81121 231 2 374 3 2 7 1 1 399 9 2 9 2 5 5 5 3
```
## Output


```

4
0
2
0
1
2
6
7

```


#### tags 

#1000 #brute_force #greedy #math 