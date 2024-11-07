<h1 style='text-align: center;'> A. Matching</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

An integer template is a string consisting of digits and/or question marks.

A positive (strictly greater than $0$) integer matches the integer template if it is possible to replace every question mark in the template with a digit in such a way that we get the decimal representation of that integer without any leading zeroes.

For example:

* $42$ matches 4?;
* $1337$ matches ????;
* $1337$ matches 1?3?;
* $1337$ matches 1337;
* $3$ does not match ??;
* $8$ does not match ???8;
* $1337$ does not match 1?7.

You are given an integer template consisting of at most $5$ characters. Calculate the number of positive (strictly greater than $0$) integers that match it.

## Input

The first line contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases.

Each test case consists of one line containing the string $s$ ($1 \le |s| \le 5$) consisting of digits and/or question marks — the integer template for the corresponding test case.

## Output

For each test case, print one integer — the number of positive (strictly greater than $0$) integers that match the template.

## Example

## Input


```

8???09031??7?5?9??99
```
## Output


```

90
9
0
1
0
100
90
100

```


#### tags 

#800 #combinatorics #math 