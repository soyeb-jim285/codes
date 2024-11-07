<h1 style='text-align: center;'> B. I love AAAB</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a string good if its length is at least $2$ and all of its characters are $\texttt{A}$ except for the last character which is $\texttt{B}$. The good strings are $\texttt{AB},\texttt{AAB},\texttt{AAAB},\ldots$. ## Note

 that $\texttt{B}$ is not a good string.

You are given an initially empty string $s_1$.

You can perform the following operation any number of times: 

* Choose any position of $s_1$ and insert some good string in that position.

Given a string $s_2$, can we turn $s_1$ into $s_2$ after some number of operations?

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single string $s_2$ ($1 \leq |s_2| \leq 2 \cdot 10^5$).

It is guaranteed that $s_2$ consists of only the characters $\texttt{A}$ and $\texttt{B}$.

It is guaranteed that the sum of $|s_2|$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print "YES" (without quotes) if we can turn $s_1$ into $s_2$ after some number of operations, and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

4AABABABBAAAAAAAABA
```
## Output


```

YES
NO
YES
NO

```
## Note

In the first test case, we transform $s_1$ as such: $\varnothing \to \color{red}{\texttt{AAB}} \to \texttt{A}\color{red}{\texttt{AB}}\texttt{AB}$.

In the third test case, we transform $s_1$ as such: $\varnothing \to \color{red}{\texttt{AAAAAAAAB}}$.

In the second and fourth test case, it can be shown that it is impossible to turn $s_1$ into $s_2$.



#### tags 

#800 #constructive_algorithms #implementation 