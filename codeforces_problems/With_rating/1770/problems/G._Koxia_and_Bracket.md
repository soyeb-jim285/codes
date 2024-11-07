<h1 style='text-align: center;'> G. Koxia and Bracket</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Chiyuu has a bracket sequence$^\dagger$ $s$ of length $n$. Let $k$ be the minimum number of characters that Chiyuu has to remove from $s$ to make $s$ balanced$^\ddagger$.

Now, Koxia wants you to count the number of ways to remove $k$ characters from $s$ so that $s$ becomes balanced, modulo $998\,244\,353$.

## Note

 that two ways of removing characters are considered distinct if and only if the set of indices removed is different.

$^\dagger$ A bracket sequence is a string containing only the characters "(" and ")".

$^\ddagger$ A bracket sequence is called balanced if one can turn it into a valid math expression by adding characters + and 1. For example, sequences (())(), (), (()(())) and the empty string are balanced, while )(, ((), and (()))( are not.

#### Input

The first line of input contains a string $s$ ($1 \leq |s| \leq 5 \cdot {10}^5$) — the bracket sequence.

It is guaranteed that $s$ only contains the characters "(" and ")".

#### Output

#### Output

 a single integer — the number of ways to remove $k$ characters from $s$ so that $s$ becomes balanced, modulo $998\,244\,353$.

## Examples

#### Input


```text
())(()
```
#### Output


```text
4
```
#### Input


```text
(
```
#### Output


```text
1
```
## Note

In the first test case, it can be proved that the minimum number of characters that Chiyuu has to remove is $2$. There are $4$ ways to remove $2$ characters to make $s$ balanced as follows. Deleted characters are noted as red.

* $\texttt{(} \color{Red}{\texttt{)}} \texttt{)} \color{Red}{\texttt{(}} \texttt{(} \texttt{)}$,
* $\texttt{(} \texttt{)} \color{Red}{\texttt{)}} \color{Red}{\texttt{(}} \texttt{(} \texttt{)}$,
* $\texttt{(} \color{Red}{\texttt{)}} \texttt{)} \texttt{(} \color{Red}{\texttt{(}} \texttt{)}$,
* $\texttt{(} \texttt{)} \color{Red}{\texttt{)}} \texttt{(} \color{Red}{\texttt{(}} \texttt{)}$.

In the second test case, the only way to make $s$ balanced is by deleting the only character to get an empty bracket sequence, which is considered balanced.



#### Tags 

#3400 #NOT OK #divide_and_conquer #fft #math 

## Blogs
- [All Contest Problems](../Good_Bye_2022:_2023_is_NEAR.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
