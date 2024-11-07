<h1 style='text-align: center;'> E. Long Inversions</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A binary string $s$ of length $n$ is given. A binary string is a string consisting only of the characters '1' and '0'.

You can choose an integer $k$ ($1 \le k \le n$) and then apply the following operation any number of times: choose $k$ consecutive characters of the string and invert them, i.e., replace all '0' with '1' and vice versa.

Using these operations, you need to make all the characters in the string equal to '1'.

For example, if $n=5$, $s=00100$, you can choose $k=3$ and proceed as follows: 

* choose the substring from the $1$-st to the $3$-rd character and obtain $s=\color{blue}{110}00$;
* choose the substring from the $3$-rd to the $5$-th character and obtain $s=11\color{blue}{111}$;

Find the maximum value of $k$ for which it is possible to make all the characters in the string equal to '1' using the described operations. Note that the number of operations required to achieve this is not important.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \le n \le 5000$) — the length of the string $s$.

The second line of each test case contains a string $s$ of length $n$, consisting of the characters '1' and '0'.

It is guaranteed that the sum of the values $n^2$ over all test cases in the test does not exceed $25 \cdot 10^6$.

## Output

For each test case, output the maximum integer $k$ ($1 \le k \le n$) for which it is possible to obtain a string $s$ consisting only of the characters '1' using the described operations.

## Example

## Input


```

5500100501000710111013000210
```
## Output


```

3
2
4
3
1

```


#### tags 

#1700 #brute_force #greedy #implementation #sortings 