<h1 style='text-align: center;'> A. Integer Diversity</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ integers $a_1, a_2, \ldots, a_n$. You choose any subset of the given numbers (possibly, none or all numbers) and negate these numbers (i. e. change $x \to (-x)$). What is the maximum number of different values in the array you can achieve?

## Input

The first line of input contains one integer $t$ ($1 \leq t \leq 100$): the number of test cases.

The next lines contain the description of the $t$ test cases, two lines per a test case.

In the first line you are given one integer $n$ ($1 \leq n \leq 100$): the number of integers in the array.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-100 \leq a_i \leq 100$).

## Output

For each test case, print one integer: the maximum number of different elements in the array that you can achieve negating numbers in the array.

## Example

## Input


```

3
4
1 1 2 2
3
1 2 3
2
0 0

```
## Output


```

4
3
1

```
## Note

In the first example we can, for example, negate the first and the last numbers, achieving the array $[-1, 1, 2, -2]$ with four different values.

In the second example all three numbers are already different.

In the third example negation does not change anything.



#### tags 

#800 #implementation 