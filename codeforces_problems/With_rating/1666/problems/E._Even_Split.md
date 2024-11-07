<h1 style='text-align: center;'> E. Even Split</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A revolution has recently happened in Segmentland. The new government is committed to equality, and they hired you to help with land redistribution in the country.

Segmentland is a segment of length $l$ kilometers, with the capital in one of its ends. There are $n$ citizens in Segmentland, the home of $i$-th citizen is located at the point $a_i$ kilometers from the capital. No two homes are located at the same point. Each citizen should receive a segment of positive length with ends at integer distances from the capital that contains her home. The union of these segments should be the whole of Segmentland, and they should not have common points besides their ends. To ensure equality, the difference between the lengths of the longest and the shortest segments should be as small as possible.

#### Input

The first line of the input contains two integers $l$ and $n$ ($2 \leq l \leq 10^9; 1 \leq n \leq 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 < a_1 < a_2 < \dots < a_n < l$).

#### Output

#### Output

 $n$ pairs of numbers $s_i, f_i$ ($0 \leq s_i < f_i \leq l$), one pair per line. The pair on $i$-th line denotes the ends of the $[s_i, f_i]$ segment that $i$-th citizen receives.

If there are many possible arrangements with the same difference between the lengths of the longest and the shortest segments, you can output any of them.

## Examples

#### Input


```text
6 3
1 3 5
```
#### Output


```text
0 2
2 4
4 6
```
#### Input


```text
10 2
1 2
```
#### Output


```text
0 2
2 10
```
## Note

In the first example, it is possible to make all segments equal. Viva la revolucion!

 ![](images/0a33b33cd101e97d642a701fbd2eab48c4313320.png) In the second example, citizens live close to the capital, so the length of the shortest segment is 2 and the length of the longest segment is 8.

 ![](images/8c37b8db5c5291aca50e0735015df2238f0d741d.png) 

#### Tags 

#2500 #NOT OK #binary_search #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../2021-2022_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement #2 (en)](../blogs/Announcement_2_(en).md)
