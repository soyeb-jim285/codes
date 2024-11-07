<h1 style='text-align: center;'> L. Lisa's Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Lisa loves playing with the sequences of integers. When she gets a new integer sequence $a_i$ of length $n$, she starts looking for all monotone subsequences. A monotone subsequence $[l, r]$ is defined by two indices $l$ and $r$ ($1 \le l < r \le n$) such that $\forall i = l, l+1, \ldots, r-1: a_i \le a_{i+1}$ or $\forall i = l, l+1, \ldots, r-1: a_i \ge a_{i+1}$. 

Lisa considers a sequence $a_i$ to be boring if there is a monotone subsequence $[l, r]$ that is as long as her boredom threshold $k$, that is when $r - l + 1 = k$.

Lucas has a sequence $b_i$ that he wants to present to Lisa, but the sequence might be boring for Lisa. So, he wants to change some elements of his sequence $b_i$, so that Lisa does not get bored playing with it. However, Lucas is lazy and wants to change as few elements of the sequence $b_i$ as possible. Your task is to help Lucas find the required changes. 

########### Input

The first line of the input contains two integers $n$ and $k$ ($3 \le k \le n \le 10^6$) — the length of the sequence and Lisa's boredom threshold. The second line contains $n$ integers $b_i$ ($1 \le b_i \le 99\,999$) — the original sequence that Lucas has.

########### Output

On the first line output an integer $m$ — the minimal number of elements in $b_i$ that needs to be changed to make the sequence not boring for Lisa. On the second line output $n$ integers $a_i$ ($0 \le a_i \le 100\,000$), so that the sequence of integers $a_i$ is not boring for Lisa and is different from the original sequence $b_i$ in exactly $m$ positions.

## Examples

########### Input


```text
5 3
1 2 3 4 5
```
########### Output


```text
2
1 0 3 0 5
```
########### Input


```text
6 3
1 1 1 1 1 1
```
########### Output


```text
3
1 100000 0 1 0 1
```
########### Input


```text
6 4
1 1 4 4 1 1
```
########### Output


```text
1
1 1 4 0 1 1
```
########### Input


```text
6 4
4 4 4 2 2 2
```
########### Output


```text
2
4 4 0 2 0 2
```
########### Input


```text
6 4
4 4 4 3 4 4
```
########### Output


```text
1
4 4 100000 3 4 4
```
########### Input


```text
8 4
2 1 1 3 3 1 1 2
```
########### Output


```text
2
2 1 1 3 0 1 0 2
```
########### Input


```text
10 4
1 1 1 2 2 1 1 2 2 1
```
########### Output


```text
2
1 1 100000 2 2 100000 1 2 2 1
```
########### Input


```text
7 5
5 4 4 3 4 4 4
```
########### Output


```text
0
5 4 4 3 4 4 4
```
########### Input


```text
10 10
1 1 1 1 1 1 1 1 1 1
```
########### Output


```text
1
1 1 1 1 1 1 1 1 0 1
```


#### Tags 

#3500 #NOT OK #dp 

## Blogs
- [All Contest Problems](../2022-2023_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement](../blogs/Announcement.md)
