<h1 style='text-align: center;'> H. Expected Twist</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There is an array $a_1, a_2, \dots, a_n$ of $n$ integers hidden from you. Your task is to find the smallest element of the array.

To do this, you can ask several queries. In each query, you can pick two integers $l$ and $r$ ($1 \leq l \leq r \leq n$). In return, you will be given the value of $\max(a_l, a_{l+1}, \dots, a_r)$. In other words, you will be told the maximum value of the subarray from $a_l$ to $a_r$.

Find the minimum of the array. You can ask at most $\mathbf{624}$ queries.

It is guaranteed that the values $a_1, a_2, \dots, a_n$ are chosen uniformly at random between $0$ and $2^{32}-1$ (inclusive).

## Interaction

Begin the interaction by reading an integer $n$ ($1 \le n \le 10^4$) on a separate line.

To ask a query, print a line in the form $\texttt{?}\;\;l\;\;r$ ($1 \le l \le r \le n$). Then you should read a single line containing the answer to your query.

After you have determined the answer, print a line in the form $\texttt{!}\;\;x$ where $x$ is the minimum value.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Answer $\texttt{-1}$ means that you made an invalid query. Exit immediately after receiving $\texttt{-1}$ and you will see Wrong answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

## Example

#Input
```text

3

1295320727

984617979

1295320727

167316954
```
#Output
```text


? 1 3

? 1 1

? 2 2

? 3 3

! 167316954
```


#### Tags 

#NOT OK #*special #interactive 

## Blogs
- [All Contest Problems](../April_Fools_Day_Contest_2023.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
