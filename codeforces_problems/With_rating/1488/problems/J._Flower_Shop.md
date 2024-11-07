<h1 style='text-align: center;'> J. Flower Shop</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Your friend is running a flower shop. In order to be prepared for the next holidays (when, as usual, sales skyrocket) she asked you to write her a special program that will help to analyze the stocks she has.

There are $n$ different types of flowers she can order and each flower of the type $i$ costs $w_i$. The last holidays were a great success, she sold all flowers she had, so right now all her stocks are empty.

From this point, she starts routine operations of ordering and selling flowers, while trying to analyze what she has at hand. All of this can be represented as $m$ queries of three types: 

* "$1$ $i$ $c$" — she bought $c$ flowers of type $i$;
* "$2$ $i$ $c$" — she disposed of $c$ flowers of type $i$;
* "$3$ $l$ $r$ $k$" — how many variants of bouquets she can make using only flowers of types $l, l + 1, \dots, r$ with the total cost no more than $k$. For simplicity, you can think that a bouquet is a multiset of flowers, and two bouquets are different if they are different as multisets. The cost of a bouquet is the sum of all flowers it has.

Help your friend and write the program that can process all these queries.

### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 1000$; $1 \le m \le 1000$) — the number of flower types and the number of queries.

The second line contains $n$ integers $w_1, w_2, \dots, w_n$ ($1 \le w_i \le 1000$) — the cost of one flower of each type.

The next $m$ lines contains queries — one per line. Each query has one of three types: 

* $1$ $i$ $c$ ($1 \le i \le n$; $1 \le c \le 5000$);
* $2$ $i$ $c$ ($1 \le i \le n$; $1 \le c \le 5000$). It's guaranteed that there are at least $c$ flowers of type $i$ at this moment;
* $3$ $l$ $r$ $k$ ($1 \le l \le r \le n$; $1 \le k \le 5000$)

It's guaranteed that the total cost of all flowers in stock after each query doesn't exceed $5000$.

### Output

For each query of the third type, print how many variants of bouquets she can make using only flowers of types $l, l + 1, \dots, r$ with the total cost no more than $k$. Since the answer may be too large, print it modulo $998\,244\,353$.

## Example

### Input


```text
5 12
1 2 3 2 1
1 1 5
1 2 3
1 3 1
3 1 5 10
3 4 5 100
1 4 4
1 5 1
3 2 5 7
3 1 1 3
3 1 5 100
2 1 5
3 1 5 100
```
### Output


```text
40
0
28
3
479
79
```


#### Tags 

#3100 #NOT OK #*special #data_structures #fft #math 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_6.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
