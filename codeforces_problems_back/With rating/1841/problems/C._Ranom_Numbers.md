<h1 style='text-align: center;'> C. Ranom Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

No, not "random" numbers.

Ranom digits are denoted by uppercase Latin letters from A to E. Moreover, the value of the letter A is $1$, B is $10$, C is $100$, D is $1000$, E is $10000$.

A Ranom number is a sequence of Ranom digits. The value of the Ranom number is calculated as follows: the values of all digits are summed up, but some digits are taken with negative signs: a digit is taken with negative sign if there is a digit with a strictly greater value to the right of it (not necessarily immediately after it); otherwise, that digit is taken with a positive sign.

For example, the value of the Ranom number DAAABDCA is $1000 - 1 - 1 - 1 - 10 + 1000 + 100 + 1 = 2088$.

You are given a Ranom number. You can change no more than one digit in it. Calculate the maximum possible value of the resulting number.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains a string $s$ ($1 \le |s| \le 2 \cdot 10^5$) consisting of uppercase Latin letters from A to E — the Ranom number you are given.

The sum of the string lengths over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print a single integer — the maximum possible value of the number, if you can change no more than one digit in it.

## Example

## Input


```

4DAAABDCAABABCDEEDCBADDDDAAADDABECD
```
## Output


```

11088
10010
31000
15886

```
## Note

In the first example, you can get EAAABDCA with the value $10000-1-1-1-10+1000+100+1=11088$.

In the second example, you can get EB with the value $10000+10=10010$.



#### tags 

#1800 #brute_force #dp #greedy #math #strings 