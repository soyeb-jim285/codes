<h1 style='text-align: center;'> F. Omkar and Modes</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ray lost his array and needs to find it by asking Omkar. Omkar is willing to disclose that the array has the following qualities:

1. The array has $n$ ($1 \le n \le 2 \cdot 10^5$) elements.
2. Every element in the array $a_i$ is an integer in the range $1 \le a_i \le 10^9.$
3. The array is sorted in nondecreasing order.

Ray is allowed to send Omkar a series of queries. A query consists of two integers, $l$ and $r$ such that $1 \le l \le r \le n$. Omkar will respond with two integers, $x$ and $f$. $x$ is the mode of the subarray from index $l$ to index $r$ inclusive. The mode of an array is defined by the number that appears the most frequently. If there are multiple numbers that appear the most number of times, the smallest such number is considered to be the mode. $f$ is the amount of times that $x$ appears in the queried subarray.

The array has $k$ ($1 \le k \le \min(25000,n)$) distinct elements. However, due to Ray's sins, Omkar will not tell Ray what $k$ is. Ray is allowed to send at most $4k$ queries.

Help Ray find his lost array.

### Input

The only line of the input contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$), which equals to the length of the array that you are trying to find.

## Interaction

The interaction starts with reading $n$.

Then you can make one type of query:

* "$? \enspace l \enspace r$" ($1 \le l \le r \le n$) where $l$ and $r$ are the bounds of the subarray that you wish to query.

The answer to each query will be in the form "$x \enspace f$" where $x$ is the mode of the subarray and $f$ is the number of times $x$ appears in the subarray.

* $x$ satisfies ($1 \leq x \leq 10^9$).
* $f$ satisfies ($1 \leq f \leq r-l+1$).
* If you make more than $4k$ queries or violate the number range in the query, you will get an output "-1."
* If you terminate after receiving the response "$-1$", you will get the "Wrong answer" verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

To output your answer, print:

* "$! \enspace a_1 \enspace a_2 \enspace \ldots \enspace a_{n-1} \enspace a_n$" which is an exclamation point followed by the array with a space between every element.

And quit after that. This query is not counted towards the $4k$ queries limit.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hack Format

To hack, output $1$ integer on the first line, $n$ ($1 \le n \le 2 \cdot 10^5$). On the second line output $n$ integers $a_1, a_2, \ldots, a_{n-1}, a_n$ separated by a space such that there are at most $25000$ distinct numbers and $a_j \le a_{j+1}$ for all $j$ from $1$ to $n-1$.

## Example

### Input


```text
6

2 2

2 2

3 2

2 1
```
#Output
```text

? 1 6

? 1 3

? 4 6

? 3 4

! 1 2 2 3 3 4
```
## Note

The first query is $l=1$ and $r=6$. The mode is $2$, and $2$ appears $2$ times, so $x=2$ and $f=2$. 
## Note

 that $3$ also appears two times, but $2$ is outputted because $2$ is smaller.

The second query is $l=1$ and $r=3$. The mode is $2$ and $2$ appears twice in the subarray with indices $[1,3]$.

The third query is $l=4$ and $r=6$. The mode is $3$ and $3$ appears twice in the subarray with indices $[4,6]$.

The fourth query is $l=3$ and $r=4$. The mode is $2$, which appears once in the subarray with indices $[3,4]$. 
## Note

 that $3$ also appears once in that range, but $2$ is smaller than $3$.



#### Tags 

#2700 #NOT OK #binary_search #divide_and_conquer #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_655_(Div._2).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
