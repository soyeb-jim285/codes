<h1 style='text-align: center;'> E. Arithmetic Progression</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem!

An arithmetic progression or arithmetic sequence is a sequence of integers such that the subtraction of element with its previous element ($x_i - x_{i - 1}$, where $i \ge 2$) is constant — such difference is called a common difference of the sequence.

That is, an arithmetic progression is a sequence of form $x_i = x_1 + (i - 1) d$, where $d$ is a common difference of the sequence.

There is a secret list of $n$ integers $a_1, a_2, \ldots, a_n$.

It is guaranteed that all elements $a_1, a_2, \ldots, a_n$ are between $0$ and $10^9$, inclusive.

This list is special: if sorted in increasing order, it will form an arithmetic progression with positive common difference ($d > 0$). For example, the list $[14, 24, 9, 19]$ satisfies this requirement, after sorting it makes a list $[9, 14, 19, 24]$, which can be produced as $x_n = 9 + 5 \cdot (n - 1)$.

Also you are also given a device, which has a quite discharged battery, thus you can only use it to perform at most $60$ queries of following two types:

* Given a value $i$ ($1 \le i \le n$), the device will show the value of the $a_i$.
* Given a value $x$ ($0 \le x \le 10^9$), the device will return $1$ if an element with a value strictly greater than $x$ exists, and it will return $0$ otherwise.

Your can use this special device for at most $60$ queries. Could you please find out the smallest element and the common difference of the sequence? That is, values $x_1$ and $d$ in the definition of the arithmetic progression. ## Note

 that the array $a$ is not sorted.

## Interaction

The interaction starts with a single integer $n$ ($2 \le n \le 10^6$), the size of the list of integers.

Then you can make queries of two types:

* "? i" ($1 \le i \le n$) — to get the value of $a_i$.
* "> x" ($0 \le x \le 10^9$) — to check whether there exists an element greater than $x$

After the query read its result $r$ as an integer.

* For the first query type, the $r$ satisfies $0 \le r \le 10^9$.
* For the second query type, the $r$ is either $0$ or $1$.
* In case you make more than $60$ queries or violated the number range in the queries, you will get a $r = -1$.
* If you terminate after receiving the -1, you will get the "Wrong answer" verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

When you find out what the smallest element $x_1$ and common difference $d$, print

* "! $x_1$ $d$"

And quit after that. This query is not counted towards the $60$ queries limit.

After printing any query do not forget to output end of line and flush the output. Otherwise you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

For hack, use the following format:

The first line should contain an integer $n$ ($2 \le n \le 10^6$) — the list's size.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the elements of the list.

Also, after the sorting the list must form an arithmetic progression with positive common difference.

## Example

Input
```

4

0

1

14

24

9

19


```
Output
```


> 25

> 15

? 1

? 2

? 3

? 4

! 9 5
```
## Note

## Note

 that the example interaction contains extra empty lines so that it's easier to read. The real interaction doesn't contain any empty lines and you shouldn't print any extra empty lines as well.

The list in the example test is $[14, 24, 9, 19]$.



#### tags 

#2200 #binary_search #interactive #number_theory #probabilities 