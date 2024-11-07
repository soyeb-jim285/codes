<h1 style='text-align: center;'> F. Tubular Bells</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Do you know what tubular bells are? They are a musical instrument made up of cylindrical metal tubes. In an orchestra, tubular bells are used to mimic the ringing of bells.

Mike has tubular bells, too! They consist of $n$ tubes, and each of the tubes has a length that can be expressed by a integer from $l$ to $r$ inclusive. It is clear that the lengths of all the tubes are different (it makes no sense to make the same tubes). It is also known that $r-l+1 = n$.

Formally, we can say that Mike's tubular bells are described by a permutation $a$ of length $n$ that contains all numbers from $l$ to $r$ inclusive, with $a_i$ denoting the length of the $i$-th tube.

You are offered an interesting task: to guess what Mike's instrument looks like. Simply, you must guess the permutation.

Mike won't tell you $l$ or $r$. He will only tell you $n$, and will allow you to ask no more than $n + 5000$ queries.

In each query, you name two positive integers $x$, $y$ such that $1 \le x, y \le n, x \neq y$. In response to this query, the program written by Mike will give you $\mathrm{lcm}(a_x, a_y)$, where $\mathrm{lcm}(c,d)$ denotes the least common multiple of $c$ and $d$.

Solve Mike's problem!

### Input

Each test contains multiple test cases.

The first line contains one positive integer $t$ ($1 \le t \le 20$), denoting the number of test cases. Description of the test cases follows.

The single line of each test case contains one positive integer $n$ ($3 \le n \le 10^5$) — number of tubes in Mike's tubular bells. Also $1 \le l \le r \le 2 \cdot 10^5$, i.e. the lengths of the tubes do not exceed $2 \cdot 10^5$.

It is guaranteed that the sum of maximal number of queries (i.e. $n + 5000$) over all test cases does not exceed $10^5 + 5000$. It means that sum of $n$ does not exceed $10^5 + 5000 - t \cdot 5000$.

## Interaction

For each set of input data, read one integer $n$. You are allowed to make no more than $n + 5000$ queries.

If you want to make a query, output it in the format "? $x$ $y$", where $x$ and $y$ — the numbers of tubes for which you learn the lcm (least common multiple) of their lengths. Note that $1 \le x, y \le n, x \neq y$ must be satisfied. The interactor will return a single integer —the answer to your query.

If you are ready to print the answer, print it in the format "! $a_1$ $a_2$ ... $a_n$". The output of the answer is not considered a query and is not included in the number of queries.

After each query and answer output, don't forget to output the line translation and reset the output buffer. Otherwise you will get the verdict "Idleness limit exceeded". To reset the buffer use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Note that the interactor is not adaptive. That is, the original permutation is fixed in the beginning and don't depend on your queries.

Hacks:

Use the following format for hacks:

The first line contains a single positive integer $t$ ($1 \le t \le 20$) — the number of input datasets. A description of the input data sets is given below.

The first line of each test case contains one positive integer $n$ ($3 \le n \le 10^5$) —the number of tubes. It is known that $1 \le l \le r \le 2 \cdot 10^5$, i.e. the lengths of the tubes do not exceed $2 \cdot 10^5$.

The second line of each test case contains an array $a$ of $n$ positive integers — the lengths of the tubes in each input dataset. Remember that $l \le a_i \le r$ and $r-l+1 = n$, and that all $a_i$ are different.

## Example

### Input


```text
3
5
8 10 7 6 9
5
24 25 28 27 26
7
1 2 3 4 5 6 7
```
#Output
```text

? 1 2
40
? 2 5
90
? 3 1
56
? 4 5
18
! 8 10 7 6 9
? 1 5
312
? 2 4
675
! 24 25 28 27 26
? 1 4
4
? 2 5
10
? 3 7
21
? 6 2
6
? 2 5
10
? 1 2
2
? 1 2
2
? 1 2
2
? 1 2
2
? 1 2
2
! 1 2 3 4 5 6 7
```


#### Tags 

#2900 #NOT OK #interactive #math #number_theory #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_741_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
