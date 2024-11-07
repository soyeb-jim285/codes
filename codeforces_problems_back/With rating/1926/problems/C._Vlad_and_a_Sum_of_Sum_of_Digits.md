<h1 style='text-align: center;'> C. Vlad and a Sum of Sum of Digits</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Please note that the time limit for this problem is only 0.5 seconds per test.

Vladislav wrote the integers from $1$ to $n$, inclusive, on the board. Then he replaced each integer with the sum of its digits.

What is the sum of the numbers on the board now?

For example, if $n=12$ then initially the numbers on the board are: $$1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12.$$ Then after the replacement, the numbers become: $$1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3.$$ The sum of these numbers is $1+2+3+4+5+6+7+8+9+1+2+3=51$. Thus, for $n=12$ the answer is $51$.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the largest number Vladislav writes.

## Output

For each test case, output a single integer — the sum of the numbers at the end of the process.

## Example

## Input


```

71212314342024200000
```
## Output


```

51
1
3
6
18465
28170
4600002

```


#### tags 

#1200 #dp #implementation 