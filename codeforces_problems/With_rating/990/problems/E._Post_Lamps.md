<h1 style='text-align: center;'> E. Post Lamps</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Adilbek's house is located on a street which can be represented as the OX axis. This street is really dark, so Adilbek wants to install some post lamps to illuminate it. Street has $n$ positions to install lamps, they correspond to the integer numbers from $0$ to $n - 1$ on the OX axis. However, some positions are blocked and no post lamp can be placed there.

There are post lamps of different types which differ only by their power. When placed in position $x$, post lamp of power $l$ illuminates the segment $[x; x + l]$. The power of each post lamp is always a positive integer number.

The post lamp shop provides an infinite amount of lamps of each type from power $1$ to power $k$. Though each customer is only allowed to order post lamps of exactly one type. Post lamps of power $l$ cost $a_l$ each.

What is the minimal total cost of the post lamps of exactly one type Adilbek can buy to illuminate the entire segment $[0; n]$ of the street? If some lamps illuminate any other segment of the street, Adilbek does not care, so, for example, he may place a lamp of power $3$ in position $n - 1$ (even though its illumination zone doesn't completely belong to segment $[0; n]$).

###### Input

The first line contains three integer numbers $n$, $m$ and $k$ ($1 \le k \le n \le 10^6$, $0 \le m \le n$) — the length of the segment of the street Adilbek wants to illuminate, the number of the blocked positions and the maximum power of the post lamp available.

The second line contains $m$ integer numbers $s_1, s_2, \dots, s_m$ ($0 \le s_1 < s_2 < \dots s_m < n$) — the blocked positions.

The third line contains $k$ integer numbers $a_1, a_2, \dots, a_k$ ($1 \le a_i \le 10^6$) — the costs of the post lamps.

###### Output

Print the minimal total cost of the post lamps of exactly one type Adilbek can buy to illuminate the entire segment $[0; n]$ of the street.

If illumintaing the entire segment $[0; n]$ is impossible, print -1.

## Examples

###### Input


```text
6 2 3  
1 3  
1 2 3  

```
###### Output


```text
6  

```
###### Input


```text
4 3 4  
1 2 3  
1 10 100 1000  

```
###### Output


```text
1000  

```
###### Input


```text
5 1 5  
0  
3 3 3 3 3  

```
###### Output


```text
-1  

```
###### Input


```text
7 4 3  
2 4 5 6  
3 14 15  

```
###### Output


```text
-1  

```


#### Tags 

#2100 #NOT OK #brute_force #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_45_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
