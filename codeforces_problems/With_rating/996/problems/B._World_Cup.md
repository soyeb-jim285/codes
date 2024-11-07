<h1 style='text-align: center;'> B. World Cup</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Allen wants to enter a fan zone that occupies a round square and has $n$ entrances.

There already is a queue of $a_i$ people in front of the $i$-th entrance. Each entrance allows one person from its queue to enter the fan zone in one minute.

Allen uses the following strategy to enter the fan zone: 

* Initially he stands in the end of the queue in front of the first entrance.
* Each minute, if he is not allowed into the fan zone during the minute (meaning he is not the first in the queue), he leaves the current queue and stands in the end of the queue of the next entrance (or the first entrance if he leaves the last entrance).

Determine the entrance through which Allen will finally enter the fan zone.

##### Input

The first line contains a single integer $n$ ($2 \le n \le 10^5$) — the number of entrances.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the number of people in queues. These numbers do not include Allen.

##### Output

Print a single integer — the number of entrance that Allen will use.

## Examples

##### Input


```text
4  
2 3 2 0  

```
##### Output


```text
3  

```
##### Input


```text
2  
10 10  

```
##### Output


```text
1  

```
##### Input


```text
6  
5 2 6 5 7 4  

```
##### Output


```text
6  

```
## Note

In the first example the number of people (not including Allen) changes as follows: $[\textbf{2}, 3, 2, 0] \to [1, \textbf{2}, 1, 0] \to [0, 1, \textbf{0}, 0]$. The number in bold is the queue Alles stands in. We see that he will enter the fan zone through the third entrance.

In the second example the number of people (not including Allen) changes as follows: $[\textbf{10}, 10] \to [9, \textbf{9}] \to [\textbf{8}, 8] \to [7, \textbf{7}] \to [\textbf{6}, 6] \to \\\ [5, \textbf{5}] \to [\textbf{4}, 4] \to [3, \textbf{3}] \to [\textbf{2}, 2] \to [1, \textbf{1}] \to [\textbf{0}, 0]$.

In the third example the number of people (not including Allen) changes as follows: $[\textbf{5}, 2, 6, 5, 7, 4] \to [4, \textbf{1}, 5, 4, 6, 3] \to [3, 0, \textbf{4}, 3, 5, 2] \to \\\ [2, 0, 3, \textbf{2}, 4, 1] \to [1, 0, 2, 1, \textbf{3}, 0] \to [0, 0, 1, 0, 2, \textbf{0}]$.



#### Tags 

#1300 #NOT OK #binary_search #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_492_(Div._2)_[Thanks,_uDebug!].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
