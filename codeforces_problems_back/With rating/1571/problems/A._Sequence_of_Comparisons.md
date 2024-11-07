<h1 style='text-align: center;'> A. Sequence of Comparisons</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time, Petya had an array of integers $a$ of length $n$. But over time, the array itself was lost, and only $n-1$ results of comparisons of neighboring array elements remained. In other words, for every $i$ from $1$ to $n-1$, Petya knows exactly one of these three facts:

* $a_i < a_{i+1}$;
* $a_i = a_{i+1}$;
* $a_i > a_{i+1}$.

Petya wonders if it is possible to uniquely determine the result of comparing $a_1$ and $a_n$.

You have to help Petya determine the result of comparing $a_1$ and $a_n$ or report that the result cannot be determined unambiguously.

## Input

The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases.

The only line of the test case contains the string $s$ ($1 \le |s| \le 100$), where $s_i$ is:

* <, if $a_i < a_{i + 1}$;
* >, if $a_i > a_{i + 1}$;
* =, if $a_i = a_{i + 1}$.
## Output

For each test case, print a single string equal to:

* <, if $a_1 < a_n$;
* >, if $a_1 > a_n$;
* =, if $a_1 = a_n$;
* ?, if it is impossible to uniquely determine the result of the comparison.
## Example

## Input


```

4
>>>
<><=<
=
<<==

```
## Output


```

>
?
=
<

```
## Note

Consider the test cases of the example:

* in the first test case, it's easy to see that $a_1 > a_4$ since $a_1 > a_2 > a_3 > a_4$;
* in the second test case, both sequences $[1, 2, 0, 10, 10, 15]$ and $[10, 11, 1, 2, 2, 5]$ meet the constraints; in the first one, $a_1 < a_6$, and in the second one, $a_1 > a_6$, so it's impossible to compare $a_1$ and $a_6$;
* in the third test case, we already know that $a_1 = a_2$;
* in the fourth test case, it's easy to see that $a_3 = a_4 = a_5$, and $a_1 < a_2 < a_3$, so $a_1 < a_5$.


#### tags 

#800 #*special 