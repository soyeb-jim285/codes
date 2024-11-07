<h1 style='text-align: center;'> D. Strange Device</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This problem is interactive.

We have hidden an array $a$ of $n$ pairwise different numbers (this means that no two numbers are equal). You can get some information about this array using a new device you just ordered on Amazon. 

This device can answer queries of the following form: in response to the positions of $k$ different elements of the array, it will return the position and value of the $m$-th among them in the ascending order.

Unfortunately, the instruction for the device was lost during delivery. However, you remember $k$, but don't remember $m$. Your task is to find $m$ using queries to this device. 

You can ask not more than $n$ queries.

## Note

 that the array $a$ and number $m$ are fixed before the start of the interaction and don't depend on your queries. In other words, interactor is not adaptive.

## Note

 that you don't have to minimize the number of queries, and you don't need to guess array $a$. You just have to guess $m$.

### Input

The first line contains two integers $n$ and $k$ ($1\le k < n \le 500$) — the length of the array and the number of the elements in the query.

It is guaranteed that number $m$ satisfies $1\le m \le k$, elements $a_1, a_2, \dots, a_n$ of the array satisfy $0\le a_i \le 10^9$, and all of them are different.

## Interaction

You begin the interaction by reading $n$ and $k$.

To ask a question about elements on positions $x_1, x_2, \dots, x_k$, in a separate line output

$?$ $x_1$ $x_2$ $x_3$ ... $x_k$

Numbers in the query have to satisfy $1 \le x_i \le n$, and all $x_i$ have to be different. Don't forget to 'flush', to get the answer.

In response, you will receive two integers $pos$ and $a_{pos}$ — the position in the array $a$ of the $m$-th in ascending order element among $a_{x_1}, a_{x_2}, \dots, a_{x_k}$, and the element on this position.

In case your query is invalid or you asked more than $n$ queries, the program will print $-1$ and will finish interaction. You will receive a Wrong answer verdict. Make sure to exit immediately to avoid getting other verdicts.

When you determine $m$, output 

$!$ $m$

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hack format

For the hacks use the following format:

The first line has to contain three integers $n, k, m$ ($1 \le m \le k < n \le 500$) — the length of the array, number of elements in the query, and which in the ascending order number the device returns.

In the next line output $n$ integers $a_1, a_2, \dots, a_n$ ($0\le a_i \le 10^9$) — the elements of the array. They have to be pairwise different.

## Example

### Input


```text
4 3
4 9
4 9
4 9
1 2
```
#Output
```text

? 2 3 4
? 1 3 4
? 1 2 4
? 1 2 3
! 3
```
## Note

In the example, $n = 4$, $k = 3$, $m = 3$, $a = [2, 0, 1, 9]$.



#### Tags 

#1900 #NOT OK #constructive_algorithms #interactive #math #sortings 

## Blogs
- [All Contest Problems](../Good_Bye_2019.md)
- [Good Bye 2019](../blogs/Good_Bye_2019.md)
- [Goodbye 2019 (en)](../blogs/Goodbye_2019_(en).md)
- [Разбор Goodbye 2019 (ru)](../blogs/Разбор_Goodbye_2019_(ru).md)
