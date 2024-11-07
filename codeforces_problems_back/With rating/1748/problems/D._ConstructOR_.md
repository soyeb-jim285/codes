<h1 style='text-align: center;'> D. ConstructOR </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $a$, $b$, and $d$. Your task is to find any integer $x$ which satisfies all of the following conditions, or determine that no such integers exist:

* $0 \le x \lt 2^{60}$;
* $a|x$ is divisible by $d$;
* $b|x$ is divisible by $d$.

Here, $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

## Input

Each test contains multiple test cases. The first line of input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. 

Each test case consists of one line, containing three integers $a$, $b$, and $d$ ($1 \le a,b,d \lt 2^{30}$).

## Output

For each test case print one integer. If there exists an integer $x$ which satisfies all of the conditions from the statement, print $x$. Otherwise, print $-1$.

If there are multiple solutions, you may print any of them. 

## Example

## Input


```

812 39 56 8 14100 200 2003 4 62 2 218 27 3420 666 69987654321 123456789 999999999
```
## Output


```

18
14
-1
-1
0
11
25599
184470016815529983
```
## Note

In the first test case, $x=18$ is one of the possible solutions, since $39|18=55$ and $12|18=30$, both of which are multiples of $d=5$.

In the second test case, $x=14$ is one of the possible solutions, since $8|14=6|14=14$, which is a multiple of $d=14$.

In the third and fourth test cases, we can show that there are no solutions.



#### tags 

#2100 #bitmasks #chinese_remainder_theorem #combinatorics #constructive_algorithms #math #number_theory 