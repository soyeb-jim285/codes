<h1 style='text-align: center;'> D. Garbage Disposal</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Enough is enough. Too many times it happened that Vasya forgot to dispose of garbage and his apartment stank afterwards. Now he wants to create a garbage disposal plan and stick to it.

For each of next $n$ days Vasya knows $a_i$ — number of units of garbage he will produce on the $i$-th day. Each unit of garbage must be disposed of either on the day it was produced or on the next day. Vasya disposes of garbage by putting it inside a bag and dropping the bag into a garbage container. Each bag can contain up to $k$ units of garbage. It is allowed to compose and drop multiple bags into a garbage container in a single day.

Being economical, Vasya wants to use as few bags as possible. You are to compute the minimum number of bags Vasya needs to dispose of all of his garbage for the given $n$ days. No garbage should be left after the $n$-th day.

###### Input

The first line of the input contains two integers $n$ and $k$ ($1 \le n \le 2\cdot10^5, 1 \le k \le 10^9$) — number of days to consider and bag's capacity. The second line contains $n$ space separated integers $a_i$ ($0 \le a_i \le 10^9$) — the number of units of garbage produced on the $i$-th day.

###### Output

###### Output

 a single integer — the minimum number of bags Vasya needs to dispose of all garbage. Each unit of garbage should be disposed on the day it was produced or on the next day. No garbage can be left after the $n$-th day. In a day it is allowed to compose and drop multiple bags.

## Examples

###### Input


```text
3 2  
3 2 1  

```
###### Output


```text
3  

```
###### Input


```text
5 1  
1000000000 1000000000 1000000000 1000000000 1000000000  

```
###### Output


```text
5000000000  

```
###### Input


```text
3 2  
1 0 1  

```
###### Output


```text
2  

```
###### Input


```text
4 4  
2 8 4 1  

```
###### Output


```text
4  

```


#### Tags 

#1300 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../2018-2019_ICPC,_NEERC,_Southern_Subregional_Contest_(Online_Mirror,_ACM-ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
