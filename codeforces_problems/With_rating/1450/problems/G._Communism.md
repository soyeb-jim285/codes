<h1 style='text-align: center;'> G. Communism</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 32 megabytes</h5>

Please pay attention to the unusual memory limit in this problem.

In a parallel universe, Satan is called "Trygub". For that reason, the letters of his namesake were deleted from the alphabet in ancient times.

The government has $n$ workers standing in a row and numbered with integers from $1$ to $n$ from left to right. Their job categories can be represented as a string $s$ of length $n$, where the character $s_i$ represents the job category of the $i$-th worker.

A new law will be approved to increase the equality between the workers. The government decided to make everyone have the same job category by performing the following operation any number of times (possibly zero).

There is a fixed rational parameter $k=\frac ab$ describing how easy it is to convince the public, and it will be used to determine the success of an operation.

In an operation, the government first selects a job category $x$ with at least one worker at the current moment. Suppose $i_1,\ldots, i_m$ ($i_1<\ldots<i_m$) are the positions of all the workers with job category $x$. If $k\cdot (i_m-i_1+1)\le m$, the government is able to choose any job category $y$ with at least one worker at the current moment and change the job category of all workers with job category $x$ to job category $y$.

If it is possible to make all workers have job category $x$, we say that $x$ is obtainable. Can you tell the government the set of obtainable job categories?

### Input

The first line contains three integers $n, a, b$ ($1 \le n \le 5000$, $1\le a\le b\le 10^5$) — the number of workers and the numerator and denominator of the parameter $k$, respectively.

The second line contains a string $s$ of length $n$, consisting of lowercase English characters — the job categories of each worker. The characters 't', 'r', 'y', 'g', 'u', and 'b' do not appear in the string $s$.

### Output

Print an integer $c$ equal to the number of obtainable job categories followed by $c$ space-separated characters — the obtainable job categories sorted in the lexicographical order.

## Example

### Input


```text
7 1 2
comicom
```
### Output


```text
3 c m o
```
## Note

The first operation must select the job category 'i' because all other job categories cannot satisfy the condition, therefore 'i' is not obtainable.

Below is showed how to obtain 'c', 'm', and 'o'. The square brackets denote the segment containing all workers of the selected category, the red color denotes this category and the blue color denotes the new category after the change.

* Get 'c':
	1. ($\texttt{com}\color{red}{\texttt{[i]}}\texttt{com} \rightarrow \texttt{com}\color{#1E90FF}{\texttt{[o]}}\texttt{com}$)
	2. ($\texttt{c}\color{red}{\texttt{[o}}\texttt{m}\color{red}{\texttt{o}}\texttt{c}\color{red}{\texttt{o]}}\texttt{m} \rightarrow \texttt{c}\color{#1E90FF}{\texttt{[m}}\texttt{m}\color{#1E90FF}{\texttt{m}}\texttt{c}\color{#1E90FF}{\texttt{m]}}\texttt{m}$)
	3. ($\texttt{c}\color{red}{\texttt{[mmm}}\texttt{c}\color{red}{\texttt{mm]}} \rightarrow \texttt{c}\color{#1E90FF}{\texttt{[ccc}}\texttt{c}\color{#1E90FF}{\texttt{cc]}}$)
* Get 'm':
	1. ($\texttt{com}\color{red}{\texttt{[i]}}\texttt{com} \rightarrow \texttt{com}\color{#1E90FF}{\texttt{[o]}}\texttt{com}$)
	2. ($\texttt{c}\color{red}{\texttt{[o}}\texttt{m}\color{red}{\texttt{o}}\texttt{c}\color{red}{\texttt{o]}}\texttt{m} \rightarrow \texttt{c}\color{#1E90FF}{\texttt{[c}}\texttt{m}\color{#1E90FF}{\texttt{c}}\texttt{c}\color{#1E90FF}{\texttt{c]}}\texttt{m}$)
	3. ($\color{red}{\texttt{[cc}}\texttt{m}\color{red}{\texttt{ccc]}}\texttt{m} \rightarrow \color{#1E90FF}{\texttt{[mm}}\texttt{m}\color{#1E90FF}{\texttt{mmm]}}\texttt{m}$)
* Get 'o':
	1. ($\texttt{com}\color{red}{\texttt{[i]}}\texttt{com} \rightarrow \texttt{com}\color{#1E90FF}{\texttt{[c]}}\texttt{com}$)
	2. ($\color{red}{\texttt{[c}}\texttt{om}\color{red}{\texttt{cc]}}\texttt{om} \rightarrow \color{#1E90FF}{\texttt{[m}}\texttt{om}\color{#1E90FF}{\texttt{mm]}}\texttt{om}$)
	3. ($\color{red}{\texttt{[m}}\texttt{o}\color{red}{\texttt{mmm}}\texttt{o}\color{red}{\texttt{m]}} \rightarrow \color{#1E90FF}{\texttt{[o}}\texttt{o}\color{#1E90FF}{\texttt{ooo}}\texttt{o}\color{#1E90FF}{\texttt{o]}}$)


#### Tags 

#3500 #NOT OK #bitmasks #dp #trees 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_12.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
