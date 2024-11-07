<h1 style='text-align: center;'> D. Required Length</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two integer numbers, $n$ and $x$. You may perform several operations with the integer $x$.

Each operation you perform is the following one: choose any digit $y$ that occurs in the decimal representation of $x$ at least once, and replace $x$ by $x \cdot y$.

You want to make the length of decimal representation of $x$ (without leading zeroes) equal to $n$. What is the minimum number of operations required to do that?

## Input

The only line of the input contains two integers $n$ and $x$ ($2 \le n \le 19$; $1 \le x < 10^{n-1}$).

## Output

Print one integer — the minimum number of operations required to make the length of decimal representation of $x$ (without leading zeroes) equal to $n$, or $-1$ if it is impossible.

## Examples

## Input


```

2 1

```
## Output


```

-1

```
## Input


```

3 2

```
## Output


```

4

```
## Input


```

13 42

```
## Output


```

12

```
## Note

In the second example, the following sequence of operations achieves the goal:

1. multiply $x$ by $2$, so $x = 2 \cdot 2 = 4$;
2. multiply $x$ by $4$, so $x = 4 \cdot 4 = 16$;
3. multiply $x$ by $6$, so $x = 16 \cdot 6 = 96$;
4. multiply $x$ by $9$, so $x = 96 \cdot 9 = 864$.


#### tags 

#1700 #brute_force #dfs_and_similar #dp #hashing #shortest_paths 