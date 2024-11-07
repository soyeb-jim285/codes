<h1 style='text-align: center;'> D. Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given $n$ non-decreasing arrays of non-negative numbers. 

Vasya repeats the following operation $k$ times: 

* Selects a non-empty array.
* Puts the first element of the selected array in his pocket.
* Removes the first element from the selected array.

Vasya wants to maximize the sum of the elements in his pocket.

### Input

The first line contains two integers $n$ and $k$ ($1 \le n, k \le 3\,000$): the number of arrays and operations.

Each of the next $n$ lines contain an array. The first integer in each line is $t_i$ ($1 \le t_i \le 10^6$): the size of the $i$-th array. The following $t_i$ integers $a_{i, j}$ ($0 \le a_{i, 1} \le \ldots \le a_{i, t_i} \le 10^8$) are the elements of the $i$-th array.

It is guaranteed that $k \le \sum\limits_{i=1}^n t_i \le 10^6$.

### Output

Print one integer: the maximum possible sum of all elements in Vasya's pocket after $k$ operations.

## Example

### Input


```text
3 3
2 5 10
3 1 2 3
2 1 20
```
### Output


```text
26
```


#### Tags 

#2800 #NOT OK #data_structures #divide_and_conquer #dp #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_681_(Div._1,_based_on_VK_Cup_2019-2020_-_Final).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
