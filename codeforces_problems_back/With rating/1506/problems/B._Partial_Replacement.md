<h1 style='text-align: center;'> B. Partial Replacement</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a number $k$ and a string $s$ of length $n$, consisting of the characters '.' and '*'. You want to replace some of the '*' characters with 'x' characters so that the following conditions are met: 

* The first character '*' in the original string should be replaced with 'x';
* The last character '*' in the original string should be replaced with 'x';
* The distance between two neighboring replaced characters 'x' must not exceed $k$ (more formally, if you replaced characters at positions $i$ and $j$ ($i < j$) and at positions $[i+1, j-1]$ there is no "x" symbol, then $j-i$ must be no more than $k$).

For example, if $n=7$, $s=$.**.*** and $k=3$, then the following strings will satisfy the conditions above: 

* .xx.*xx;
* .x*.x*x;
* .xx.xxx.

 But, for example, the following strings will not meet the conditions: * .**.*xx (the first character '*' should be replaced with 'x');
* .x*.xx* (the last character '*' should be replaced with 'x');
* .x*.*xx (the distance between characters at positions $2$ and $6$ is greater than $k=3$).

Given $n$, $k$, and $s$, find the minimum number of '*' characters that must be replaced with 'x' in order to meet the above conditions.

## Input

The first line contains one integer $t$ ($1 \le t \le 500$). Then $t$ test cases follow.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 50$).

The second line of each test case contains a string $s$ of length $n$, consisting of the characters '.' and '*'.

It is guaranteed that there is at least one '*' in the string $s$.

It is guaranteed that the distance between any two neighboring '*' characters does not exceed $k$.

## Output

For each test case output the minimum number of '*' characters that must be replaced with 'x' characters in order to satisfy the conditions above.

## Example

## Input


```

5
7 3
.**.***
5 1
..*..
5 2
*.*.*
3 2
*.*
1 1
*

```
## Output


```

3
1
3
2
1

```


#### tags 

#1100 #greedy #implementation 