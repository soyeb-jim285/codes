<h1 style='text-align: center;'> A. Everything Everywhere All But One</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$. After you watched the amazing film "Everything Everywhere All At Once", you came up with the following operation.

In one operation, you choose $n-1$ elements of the array and replace each of them with their arithmetic mean (which doesn't have to be an integer). For example, from the array $[1, 2, 3, 1]$ we can get the array $[2, 2, 2, 1]$, if we choose the first three elements, or we can get the array $[\frac{4}{3}, \frac{4}{3}, 3, \frac{4}{3}]$, if we choose all elements except the third.

Is it possible to make all elements of the array equal by performing a finite number of such operations?

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 200$)  — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \le n \le 50$)  — the number of integers.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 100$).

## Output

For each test case, if it is possible to make all elements equal after some number of operations, output $\texttt{YES}$. Otherwise, output $\texttt{NO}$.

You can output $\texttt{YES}$ and $\texttt{NO}$ in any case (for example, strings $\texttt{yEs}$, $\texttt{yes}$, $\texttt{Yes}$ will be recognized as a positive response).

## Example

## Input


```

4342 42 4251 2 3 4 544 3 2 1324 2 22
```
## Output


```

YES
YES
NO
NO

```
## Note

In the first test case, all elements are already equal.

In the second test case, you can choose all elements except the third, their average is $\frac{1 + 2 + 4 + 5}{4} = 3$, so the array will become $[3, 3, 3, 3, 3]$.

It's possible to show that it's impossible to make all elements equal in the third and fourth test cases.



#### tags 

#800 #greedy 