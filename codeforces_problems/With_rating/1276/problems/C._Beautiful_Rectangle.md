<h1 style='text-align: center;'> C. Beautiful Rectangle</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ integers. You need to choose a subset and put the chosen numbers in a beautiful rectangle (rectangular matrix). Each chosen number should occupy one of its rectangle cells, each cell must be filled with exactly one chosen number. Some of the $n$ numbers may not be chosen.

A rectangle (rectangular matrix) is called beautiful if in each row and in each column all values are different.

What is the largest (by the total number of cells) beautiful rectangle you can construct? Print the rectangle itself.

#### Input

The first line contains $n$ ($1 \le n \le 4\cdot10^5$). The second line contains $n$ integers ($1 \le a_i \le 10^9$).

#### Output

In the first line print $x$ ($1 \le x \le n$) — the total number of cells of the required maximum beautiful rectangle. In the second line print $p$ and $q$ ($p \cdot q=x$): its sizes. In the next $p$ lines print the required rectangle itself. If there are several answers, print any.

## Examples

#### Input


```text
12
3 1 4 1 5 9 2 6 5 3 5 8
```
#### Output


```text
12
3 4
1 2 3 5
3 1 5 4
5 6 8 9
```
#### Input


```text
5
1 1 1 1 1
```
#### Output


```text
1
1 1
1
```


#### Tags 

#2300 #NOT OK #brute_force #combinatorics #constructive_algorithms #data_structures #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_606_(Div._1,_based_on_Technocup_2020_Elimination_Round_4).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
