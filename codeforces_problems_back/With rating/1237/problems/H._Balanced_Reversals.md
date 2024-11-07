<h1 style='text-align: center;'> H. Balanced Reversals</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You have two strings $a$ and $b$ of equal even length $n$ consisting of characters 0 and 1.

We're in the endgame now. To finally make the universe perfectly balanced, you need to make strings $a$ and $b$ equal.

In one step, you can choose any prefix of $a$ of even length and reverse it. Formally, if $a = a_1 a_2 \ldots a_n$, you can choose a positive even integer $p \le n$ and set $a$ to $a_p a_{p-1} \ldots a_1 a_{p+1} a_{p+2} \ldots a_n$.

Find a way to make $a$ equal to $b$ using at most $n + 1$ reversals of the above kind, or determine that such a way doesn't exist. The number of reversals doesn't have to be minimized.

## Input

The first line contains a single integer $t$ ($1 \le t \le 2000$), denoting the number of test cases.

Each test case consists of two lines. The first line contains a string $a$ of length $n$, and the second line contains a string $b$ of the same length ($2 \le n \le 4000$; $n \bmod 2 = 0$). Both strings consist of characters 0 and 1.

The sum of $n$ over all $t$ test cases doesn't exceed $4000$.

## Output

For each test case, if it's impossible to make $a$ equal to $b$ in at most $n + 1$ reversals, output a single integer $-1$.

Otherwise, output an integer $k$ ($0 \le k \le n + 1$), denoting the number of reversals in your sequence of steps, followed by $k$ even integers $p_1, p_2, \ldots, p_k$ ($2 \le p_i \le n$; $p_i \bmod 2 = 0$), denoting the lengths of prefixes of $a$ to be reversed, in chronological order.

## Note

 that $k$ doesn't have to be minimized. If there are many solutions, output any of them.

## Example

## Input


```

4
0100011011
1101011000
10101010
10101010
0011
1001
100011
110010

```
## Output


```

3
6 4 10
0

-1
7
2 6 2 6 2 2 6

```
## Note

In the first test case, string $a$ changes as follows: 

* after the first reversal: 1000101011;
* after the second reversal: 0001101011;
* after the third reversal: 1101011000.


#### tags 

#3300 #constructive_algorithms 