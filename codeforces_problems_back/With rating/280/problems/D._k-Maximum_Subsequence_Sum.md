<h1 style='text-align: center;'> D. k-Maximum Subsequence Sum</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider integer sequence *a*1, *a*2, ..., *a**n*. You should run queries of two types:

* The query format is "0 *i* *val*". In reply to this query you should make the following assignment: *a**i* = *val*.
* The query format is "1 *l* *r* *k*". In reply to this query you should print the maximum sum of at most *k* non-intersecting subsegments of sequence *a**l*, *a**l* + 1, ..., *a**r*. Formally, you should choose at most *k* pairs of integers (*x*1, *y*1), (*x*2, *y*2), ..., (*x**t*, *y**t*) (*l* ≤ *x*1 ≤ *y*1 < *x*2 ≤ *y*2 < ... < *x**t* ≤ *y**t* ≤ *r*; *t* ≤ *k*) such that the sum *a**x*1 + *a**x*1 + 1 + ... + *a**y*1 + *a**x*2 + *a**x*2 + 1 + ... + *a**y*2 + ... + *a**x**t* + *a**x**t* + 1 + ... + *a**y**t* is as large as possible. ## Note

 that you should choose at most *k* subsegments. Particularly, you can choose 0 subsegments. In this case the described sum considered equal to zero.
## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105), showing how many numbers the sequence has. The next line contains *n* integers *a*1, *a*2, ..., *a**n* (|*a**i*| ≤ 500). 

The third line contains integer *m* (1 ≤ *m* ≤ 105) — the number of queries. The next *m* lines contain the queries in the format, given in the statement.

All changing queries fit into limits: 1 ≤ *i* ≤ *n*, |*val*| ≤ 500.

All queries to count the maximum sum of at most *k* non-intersecting subsegments fit into limits: 1 ≤ *l* ≤ *r* ≤ *n*, 1 ≤ *k* ≤ 20. It is guaranteed that the number of the queries to count the maximum sum of at most *k* non-intersecting subsegments doesn't exceed 10000.

## Output

For each query to count the maximum sum of at most *k* non-intersecting subsegments print the reply — the maximum sum. Print the answers to the queries in the order, in which the queries follow in the input.

## Examples

## Input


```
9  
9 -8 9 -1 -1 -1 9 -8 9  
3  
1 1 9 1  
1 1 9 2  
1 4 6 3  

```
## Output


```
17  
25  
0  

```
## Input


```
15  
-4 8 -3 -10 10 4 -7 -7 0 -6 3 8 -10 7 2  
15  
1 3 9 2  
1 6 12 1  
0 6 5  
0 10 -7  
1 4 9 1  
1 7 9 1  
0 10 -3  
1 4 10 2  
1 3 13 2  
1 4 11 2  
0 15 -9  
0 13 -9  
0 11 -10  
1 5 14 2  
1 6 12 1  

```
## Output


```
14  
11  
15  
0  
15  
26  
18  
23  
8  

```
## Note

In the first query of the first example you can select a single pair (1, 9). So the described sum will be 17.

Look at the second query of the first example. How to choose two subsegments? (1, 3) and (7, 9)? Definitely not, the sum we could get from (1, 3) and (7, 9) is 20, against the optimal configuration (1, 7) and (9, 9) with 25.

The answer to the third query is 0, we prefer select nothing if all of the numbers in the given interval are negative.



#### tags 

#2800 #data_structures #flows #graphs #implementation 