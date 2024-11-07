<h1 style='text-align: center;'> C. Thermostat</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad came home and found out that someone had reconfigured the old thermostat to the temperature of $a$.

The thermostat can only be set to a temperature from $l$ to $r$ inclusive, the temperature cannot change by less than $x$. Formally, in one operation you can reconfigure the thermostat from temperature $a$ to temperature $b$ if $|a - b| \ge x$ and $l \le b \le r$.

You are given $l$, $r$, $x$, $a$ and $b$. Find the minimum number of operations required to get temperature $b$ from temperature $a$, or say that it is impossible.

## Input

The first line of input data contains the single integer $t$ ($1 \le t \le 10^4$) — the number of test cases in the test.

The descriptions of the test cases follow.

The first line of each case contains three integers $l$, $r$ and $x$ ($-10^9 \le l \le r \le 10^9$, $1 \le x \le 10^9$) — range of temperature and minimum temperature change.

The second line of each case contains two integers $a$ and $b$ ($l \le a, b \le r$) — the initial and final temperatures.

## Output

## Output

 $t$ numbers, each of which is the answer to the corresponding test case. If it is impossible to achieve the temperature $b$, output -1, otherwise output the minimum number of operations.

## Example

## Input


```

103 5 63 30 15 54 50 10 53 73 5 63 4-10 10 11-5 6-3 3 41 0-5 10 89 21 5 12 5-1 4 30 2-6 3 6-1 -4
```
## Output


```

0
2
3
-1
1
-1
3
1
3
-1

```
## Note

In the first example, the thermostat is already set up correctly.

In the second example, you can achieve the desired temperature as follows: $4 \rightarrow 10 \rightarrow 5$.

In the third example, you can achieve the desired temperature as follows: $3 \rightarrow 8 \rightarrow 2 \rightarrow 7$.

In the fourth test, it is impossible to make any operation.



#### tags 

#1100 #greedy #math #shortest_paths 