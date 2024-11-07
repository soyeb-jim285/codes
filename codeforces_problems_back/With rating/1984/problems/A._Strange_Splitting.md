<h1 style='text-align: center;'> A. Strange Splitting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Define the range of a non-empty array to be the maximum value minus the minimum value. For example, the range of $[1,4,2]$ is $4-1=3$.

You are given an array $a_1, a_2, \ldots, a_n$ of length $n \geq 3$. It is guaranteed $a$ is sorted.

You have to color each element of $a$ red or blue so that: 

* the range of the red elements does not equal the range of the blue elements, and
* there is at least one element of each color.

If there does not exist any such coloring, you should report it. If there are multiple valid colorings, you can print any of them.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains an integer $n$ ($3 \leq n \leq 50$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$). It is guaranteed $a_1 \leq a_2 \leq \ldots \leq a_{n - 1} \leq a_{n}$.

## Output

For each test case, if it is impossible to color $a$ to satisfy all the constraints, output $\texttt{NO}$.

Otherwise, first output $\texttt{YES}$.

Then, output a string $s$ of length $n$. For $1 \leq i \leq n$, if you color $a_i$ red, $s_i$ should be $\texttt{R}$. For $1 \leq i \leq n$, if you color $a_i$ blue, $s_i$ should be $\texttt{B}$. 

## Example

## Input


```

741 1 2 251 2 3 4 533 3 341 2 2 231 2 231 1 231 9 84
```
## Output


```

YES
RBRR
YES
BBRBB
NO
YES
RBBR
YES
RRB
YES
BRR
YES
BRB
```
## Note

In the first test case, given the array $[1, 1, 2, 2]$, we can color the second element blue and the remaining elements red; then the range of the red elements $[1, 2, 2]$ is $2-1=1$, and the range of the blue elements $[1]$ is $1-1=0$.

In the second test case, we can color the first, second, fourth and fifth elements $[1, 2, 4, 5]$ blue and the remaining elements $[3]$ red. 

The range of the red elements is $3 - 3 = 0$ and the range of the blue elements is $5 - 1 = 4$, which are different.

In the third test case, it can be shown there is no way to color $a = [3, 3, 3]$ to satisfy the constraints.



#### tags 

#800 #constructive_algorithms 