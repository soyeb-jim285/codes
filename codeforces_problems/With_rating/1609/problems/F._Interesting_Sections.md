<h1 style='text-align: center;'> F. Interesting Sections</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/a3929a7b640488cd5e0319a7c43d10f2210a1170.png) William has an array of non-negative numbers $a_1, a_2, \dots, a_n$. He wants you to find out how many segments $l \le r$ pass the check. The check is performed in the following manner: 

1. The minimum and maximum numbers are found on the segment of the array starting at $l$ and ending at $r$.
2. The check is considered to be passed if the binary representation of the minimum and maximum numbers have the same number of bits equal to 1.
#### Input

The first line contains a single integer $n$ ($1 \le n \le 10^6$), the size of array $a$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 10^{18}$), the contents of array $a$.

#### Output

#### Output

 a single number  — the total number of segments that passed the check.

## Examples

#### Input


```text
5
1 2 3 4 5
```
#### Output


```text
9
```
#### Input


```text
10
0 5 7 3 9 10 1 6 13 7
```
#### Output


```text
18
```


#### Tags 

#2800 #NOT OK #data_structures #divide_and_conquer #meet-in-the-middle #two_pointers 

## Blogs
- [All Contest Problems](../Deltix_Round,_Autumn_2021_(open_for_everyone,_rated,_Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
