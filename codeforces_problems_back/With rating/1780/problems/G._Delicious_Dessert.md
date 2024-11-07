<h1 style='text-align: center;'> G. Delicious Dessert</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Today is an important day for chef Tonio — an auditor has arrived in his hometown of Morioh. He has also arrived at Tonio's restaurant and ordered dessert. Tonio has not been prepared for this turn of events.

As you know, dessert is a string of lowercase English letters. Tonio remembered the rule of desserts — a string $s$ of length $n$. Any dessert $t$ is delicious if the number of occurrences of $t$ in $s$ as a substring is divisible by the length of $t$.

Now Tonio wants to know the number of delicious substrings of $s$. If the substring occurs several times in the string $s$, then all occurrences must be taken into account.

## Input

The first line contains an integer $n$ ($1 \leq n \leq 10^6$) — the length of the rule $s$.

The second line contains the string $s$ of length $n$ — the rule. The rule consists only of lowercase English letters.

## Output

In a single line print the number of delicious substrings of $s$.

## Examples

## Input


```

7
abacaba

```
## Output


```

11

```
## Input


```

8
abaababa

```
## Output


```

11

```
## Input


```

10
deadinside

```
## Output


```

12

```
## Input


```

5
aaaaa

```
## Output


```

12

```
## Note

In the first sample, there are many delicious substrings. $7$ of them are substrings of length $1$ (because any number is divisible by $1$). Consider other delicious substrings:

* "ab" occurs in $s$ $2$ times, which is divisible by the length of the substring.
* "ba" also occurs $2$ times.

Therefore, the answer is $7 + 2 + 2 = 11$.

## Note

 that the answer includes both occurrences of "ab" and "ba".



#### tags 

#2400 #binary_search #dsu #hashing #math #number_theory #string_suffix_structures 