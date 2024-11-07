<h1 style='text-align: center;'> F. Data Center</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are developing a project to build a new data center. The data center will be a rectangle with an area of exactly $n$ square meters. Each side of the data center must be an integer.

Your goal is to minimize the impact of the external environment on the data center. For this reason, you want to minimize the length of the perimeter of the data center (that is, the sum of the lengths of its four sides).

What is the minimum perimeter of a rectangular data center with an area of exactly $n$ square meters, if the lengths of all its sides must be integers?

##### Input

The first and only line of the input contains an integer $n$ ($1 \le n \le 10^5$), where $n$ is the area of the data center in square meters.

##### Output

Print the required minimum perimeter in meters.

## Examples

##### Input


```text
36
```
##### Output


```text
24
```
##### Input


```text
13
```
##### Output


```text
28
```
##### Input


```text
1
```
##### Output


```text
4
```
## Note

In the first example, the required shape of the data center is $6\times6$ square. Its area is $36$ and the perimeter is $6+6+6+6=24$.

In the second example, the required shape of the data center is $1\times13$ rectangle. Its area is $13$ and the perimeter is $1+13+1+13=28$.

In the third example, the required shape of the data center is $1\times1$ square. Its area is $1$ and the perimeter is $1+1+1+1=4$.



#### Tags 

#800 #NOT OK #brute_force #implementation 

## Blogs
- [All Contest Problems](../2019-2020_ICPC,_NERC,_Southern_and_Volga_Russian_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
