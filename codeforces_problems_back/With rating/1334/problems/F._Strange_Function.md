<h1 style='text-align: center;'> F. Strange Function</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's denote the following function $f$. This function takes an array $a$ of length $n$ and returns an array. Initially the result is an empty array. For each integer $i$ from $1$ to $n$ we add element $a_i$ to the end of the resulting array if it is greater than all previous elements (more formally, if $a_i > \max\limits_{1 \le j < i}a_j$). Some examples of the function $f$:

1. if $a = [3, 1, 2, 7, 7, 3, 6, 7, 8]$ then $f(a) = [3, 7, 8]$;
2. if $a = [1]$ then $f(a) = [1]$;
3. if $a = [4, 1, 1, 2, 3]$ then $f(a) = [4]$;
4. if $a = [1, 3, 1, 2, 6, 8, 7, 7, 4, 11, 10]$ then $f(a) = [1, 3, 6, 8, 11]$.

You are given two arrays: array $a_1, a_2, \dots , a_n$ and array $b_1, b_2, \dots , b_m$. You can delete some elements of array $a$ (possibly zero). To delete the element $a_i$, you have to pay $p_i$ coins (the value of $p_i$ can be negative, then you get $|p_i|$ coins, if you delete this element). Calculate the minimum number of coins (possibly negative) you have to spend for fulfilling equality $f(a) = b$.

## Input

The first line contains one integer $n$ $(1 \le n \le 5 \cdot 10^5)$ — the length of array $a$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ $(1 \le a_i \le n)$ — the array $a$.

The third line contains $n$ integers $p_1, p_2, \dots, p_n$ $(|p_i| \le 10^9)$ — the array $p$.

The fourth line contains one integer $m$ $(1 \le m \le n)$ — the length of array $b$.

The fifth line contains $m$ integers $b_1, b_2, \dots, b_m$ $(1 \le b_i \le n, b_{i-1} < b_i)$ — the array $b$.

## Output

If the answer exists, in the first line print YES. In the second line, print the minimum number of coins you have to spend for fulfilling equality $f(a) = b$.

Otherwise in only line print NO.

## Examples

## Input


```

11
4 1 3 3 7 8 7 9 10 7 11
3 5 0 -2 5 3 6 7 8 2 4
3
3 7 10

```
## Output


```

YES
20

```
## Input


```

6
2 1 5 3 6 5
3 -9 0 16 22 -14
4
2 3 5 6

```
## Output


```

NO

```


#### tags 

#2500 #binary_search #data_structures #dp #greedy 