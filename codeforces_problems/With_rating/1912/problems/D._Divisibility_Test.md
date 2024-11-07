<h1 style='text-align: center;'> D. Divisibility Test</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Daisy has recently learned divisibility rules for integers and she is fascinated by them. One of the tests she learned is a divisibility test by 3. You can find a sum of all digits of a decimal number and check if the resulting sum is divisible by 3. Moreover, the resulting sum of digits is congruent modulo 3 to the original number — the remainder modulo 3 is preserved. For example, $75 \equiv 7 + 5 \pmod 3$. Daisy is specifically interested in such remainder preserving divisibility tests.

There are more examples like that that she learned for decimal integers (integers base 10):

* To test divisibility modulo 11, find an alternating sum of digits. Counting digits from the last (least significant) digit, add digits on odd positions (the last, 3rd to the last, etc) and subtract digits on even positions (2nd to the last, 4th to the last, etc) to get the sum that is congruent modulo 11 to the original number. For example, $123 \equiv 1 - 2 + 3 \pmod {11}$.
* To test divisibility modulo 4, keep the last two digits. Their value is congruent modulo 4 to the original number. For example, $876543 \equiv 43 \pmod 4$.
* To test divisibility modulo 7, find an alternating sum of groups of three digits. For example, $4389328 \equiv 4 - 389 + 328 \pmod 7$.

Similar tests can be found in other bases. For example, to test divisibility modulo 5 for octal numbers (base 8), find an alternating sum of groups of two digits. For example, $1234_8 \equiv -12_8 + 34_8 \pmod 5$.

Daisy wants to find such rules for a given base $b$. She is interested in three kinds of divisibility rules:

* Kind 1 — take the last $k$ digits of an integer in base $b$.
* Kind 2 — take a sum of groups of $k$ digits of an integer in base $b$.
* Kind 3 — take an alternating sum of groups of $k$ digits of an integer in base $b$.

It is not always possible to find such a divisibility rule. For example, in base 10 there is no such test for divisibility modulo 6, even though different approaches to testing divisibility by 6 exist.

Given base $b$ and modulo $n$, Daisy wants to know the smallest group size $k$ for which such a divisibility test exits.

### Input

There are several tests in the input. The first line of the input contains an integer $t$ — the number of tests. The next $t$ lines describe the tests.

Each test consists of a line with two integers $b$ and $n$ — the base and the modulo ($b, n \ge 2$). The sum of all $b$ values in the input does not exceed $10^6$, and the sum of all $n$ values in the input does not exceed $10^6$.

### Output

Write $t$ lines — a line for each test in the input. On a line for a test write a single integer $0$ if the divisibility test for a given $b$ and $n$ does not exist. Otherwise, write two integers $a$ and $k$, where $a$ is the kind of the divisibility test (1, 2, or 3) and $k$ is the number of digits in a group for the test, such that $k$ is the lowest among all possible divisiblity tests for the given $b$ and $n$.

## Example

### Input


```text
610 310 1110 410 78 510 6
```
### Output

```text

2 1
3 1
1 2
3 3
3 2
0

```


#### Tags 

#1900 #NOT OK #math 

## Blogs
- [All Contest Problems](../2023-2024_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Discussion (en)](../blogs/Discussion_(en).md)
