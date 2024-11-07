<h1 style='text-align: center;'> G. Pepe Racing</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There are $n^2$ pepes labeled $1, 2, \ldots, n^2$ with pairwise distinct speeds. You would like to set up some races to find out the relative speed of these pepes.

In one race, you can choose exactly $n$ distinct pepes and make them race against each other. After each race, you will only know the fastest pepe of these $n$ pepes.

Can you order the $n^2-n+1$ fastest pepes in at most $2n^2 - 2n + 1$ races? Note that the slowest $n - 1$ pepes are indistinguishable from each other.

Note that the interactor is adaptive. That is, the relative speeds of the pepes are not fixed in the beginning and may depend on your queries. But it is guaranteed that at any moment there is at least one initial configuration of pepes such that all the answers to the queries are consistent.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The only line of each test case contains a single integer $n$ ($2 \le n \le 20$) — the number of pepes in one race.

After reading the integer $n$ for each test case, you should begin the interaction.

It is guaranteed that the sum of $n^3$ over all test cases does not exceed $3 \cdot 10^5$.

## Interaction

To set up a race, print a line with the following format: 

* $\mathtt{?}\,x_1\,x_2 \ldots x_n$ ($1 \le x_i \le n^2$, $x_i$ are pairwise distinct) — the labels of the pepes in the race.

After each race, you should read a line containing a single integer $p$ ($1\le p\le n^2$) — the label of the fastest pepe in the race.

When you know the $n^2-n+1$ fastest pepes, print one line in the following format: 

* $\mathtt{!}\,p_1\,p_2 \ldots p_{n^2 - n + 1}$ ($1 \le p_i \le n^2$, $p_i$ are pairwise distinct)

 where $p$ is the sequence of these pepe's labels in descending order of speed.After that, move on to the next test case, or terminate the program if no more test cases are remaining.

If your program performs more than $2n^2 - 2n + 1$ races for one test case or makes an invalid race, you may receive a Wrong Answer verdict.

After printing a query do not forget to output the end of the line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hack format

For hacks, use the following format.

The first line should contain $t$ — the number of test cases.

The first line of each test case should contain an integer $n$ followed by the string manual.

The second line of each test case should contain a permutation $a_1,a_2,\ldots,a_{n^2}$ of the integers from $1$ to $n^2$. $a_i > a_j$ if and only if pepe $i$ has a faster speed than pepe $j$.

As an example, the hack format for the example input is: $\mathtt{1}\\\\\mathtt{2}~\mathtt{manual}\\\\\mathtt{1}~\mathtt{2}~\mathtt{3}~\mathtt{4}$

## Example

### Input


```text

1
2

2

4

4

3

2
```
#Output
```text



? 1 2

? 3 4

? 2 4

? 2 3

? 2 1

! 4 3 2
```


#### Tags 

#3200 #NOT OK #constructive_algorithms #implementation #interactive #sortings 

## Blogs
- [All Contest Problems](../CodeTON_Round_7_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
