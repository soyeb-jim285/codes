<h1 style='text-align: center;'> A. City Day</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For years, the Day of city N was held in the most rainy day of summer. New mayor decided to break this tradition and select a not-so-rainy day for the celebration. The mayor knows the weather forecast for the $n$ days of summer. On the $i$-th day, $a_i$ millimeters of rain will fall. All values $a_i$ are distinct.

The mayor knows that citizens will watch the weather $x$ days before the celebration and $y$ days after. Because of that, he says that a day $d$ is not-so-rainy if $a_d$ is smaller than rain amounts at each of $x$ days before day $d$ and and each of $y$ days after day $d$. In other words, $a_d < a_j$ should hold for all $d - x \le j < d$ and $d < j \le d + y$. Citizens only watch the weather during summer, so we only consider such $j$ that $1 \le j \le n$.

Help mayor find the earliest not-so-rainy day of summer.

##### Input

The first line contains three integers $n$, $x$ and $y$ ($1 \le n \le 100\,000$, $0 \le x, y \le 7$) — the number of days in summer, the number of days citizens watch the weather before the celebration and the number of days they do that after.

The second line contains $n$ distinct integers $a_1$, $a_2$, ..., $a_n$ ($1 \le a_i \le 10^9$), where $a_i$ denotes the rain amount on the $i$-th day.

##### Output

Print a single integer — the index of the earliest not-so-rainy day of summer. We can show that the answer always exists.

## Examples

##### Input


```text
10 2 2
10 9 6 7 8 3 2 1 4 5
```
##### Output


```text
3
```
##### Input


```text
10 2 3
10 9 6 7 8 3 2 1 4 5
```
##### Output


```text
8
```
##### Input


```text
5 5 5
100000 10000 1000 100 10
```
##### Output


```text
5
```
## Note

In the first example days $3$ and $8$ are not-so-rainy. The $3$-rd day is earlier.

In the second example day $3$ is not not-so-rainy, because $3 + y = 6$ and $a_3 > a_6$. Thus, day $8$ is the answer. 
## Note

 that $8 + y = 11$, but we don't consider day $11$, because it is not summer.



#### Tags 

#1000 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_576_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [E (en)](../blogs/E_(en).md)
