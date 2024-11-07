<h1 style='text-align: center;'> B. Micro-World</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a Petri dish with bacteria and you are preparing to dive into the harsh micro-world. But, unfortunately, you don't have any microscope nearby, so you can't watch them.

You know that you have $n$ bacteria in the Petri dish and size of the $i$-th bacteria is $a_i$. Also you know intergalactic positive integer constant $K$.

The $i$-th bacteria can swallow the $j$-th bacteria if and only if $a_i > a_j$ and $a_i \le a_j + K$. The $j$-th bacteria disappear, but the $i$-th bacteria doesn't change its size. The bacteria can perform multiple swallows. On each swallow operation any bacteria $i$ can swallow any bacteria $j$ if $a_i > a_j$ and $a_i \le a_j + K$. The swallow operations go one after another.

For example, the sequence of bacteria sizes $a=[101, 53, 42, 102, 101, 55, 54]$ and $K=1$. The one of possible sequences of swallows is: $[101, 53, 42, 102, \underline{101}, 55, 54]$ $\to$ $[101, \underline{53}, 42, 102, 55, 54]$ $\to$ $[\underline{101}, 42, 102, 55, 54]$ $\to$ $[42, 102, 55, \underline{54}]$ $\to$ $[42, 102, 55]$. In total there are $3$ bacteria remained in the Petri dish.

Since you don't have a microscope, you can only guess, what the minimal possible number of bacteria can remain in your Petri dish when you finally will find any microscope.

##### Input

The first line contains two space separated positive integers $n$ and $K$ ($1 \le n \le 2 \cdot 10^5$, $1 \le K \le 10^6$) — number of bacteria and intergalactic constant $K$.

The second line contains $n$ space separated integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — sizes of bacteria you have.

##### Output

Print the only integer — minimal possible number of bacteria can remain.

## Examples

##### Input


```text
7 1  
101 53 42 102 101 55 54  

```
##### Output


```text
3  

```
##### Input


```text
6 5  
20 15 10 15 20 25  

```
##### Output


```text
1  

```
##### Input


```text
7 1000000  
1 1 1 1 1 1 1  

```
##### Output


```text
7  

```
## Note

The first example is clarified in the problem statement.

In the second example an optimal possible sequence of swallows is: $[20, 15, 10, 15, \underline{20}, 25]$ $\to$ $[20, 15, 10, \underline{15}, 25]$ $\to$ $[20, 15, \underline{10}, 25]$ $\to$ $[20, \underline{15}, 25]$ $\to$ $[\underline{20}, 25]$ $\to$ $[25]$.

In the third example no bacteria can swallow any other bacteria.



#### Tags 

#1200 #NOT OK #greedy #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_45_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
