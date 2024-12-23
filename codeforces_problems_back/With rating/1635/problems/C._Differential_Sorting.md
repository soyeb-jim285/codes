<h1 style='text-align: center;'> C. Differential Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ elements. 

Your can perform the following operation no more than $n$ times: Select three indices $x,y,z$ $(1 \leq x < y < z \leq n)$ and replace $a_x$ with $a_y - a_z$. After the operation, $|a_x|$ need to be less than $10^{18}$.

Your goal is to make the resulting array non-decreasing. If there are multiple solutions, you can output any. If it is impossible to achieve, you should report it as well.

## Input

Each test contains multiple test cases. The first line will contain a single integer $t$ $(1 \leq t \leq 10000)$ — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains a single integer $n$ $(3 \leq n \leq 2 \cdot 10^5)$ — the size of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots ,a_n$ $(-10^9 \leq a_i \leq 10^9)$, the elements of $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print $-1$ in a single line if there is no solution. Otherwise in the first line you should print a single integer $m$ $(0 \leq m \leq n)$ — number of operations you performed.

Then the $i$-th of the following $m$ lines should contain three integers $x,y,z$ $(1 \leq x < y < z \leq n)$— description of the $i$-th operation.

If there are multiple solutions, you can output any. ## Note

 that you don't have to minimize the number of operations in this task.

## Example

## Input


```

3
5
5 -4 2 -1 2
3
4 3 2
3
-3 -2 -1

```
## Output


```

2
1 2 3
3 4 5
-1
0

```
## Note

In the first example, the array becomes 

$[-6,-4,2,-1,2]$ after the first operation,

$[-6,-4,-3,-1,2]$ after the second operation.

In the second example, it is impossible to make the array sorted after any sequence of operations.

In the third example, the array is already sorted, so we don't need to perform any operations.



#### tags 

#1200 #constructive_algorithms #greedy 