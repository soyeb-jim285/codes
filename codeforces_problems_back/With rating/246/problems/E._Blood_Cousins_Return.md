<h1 style='text-align: center;'> E. Blood Cousins Return</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus got hold of a family tree. The found tree describes the family relations of *n* people, numbered from 1 to *n*. Every person in this tree has at most one direct ancestor. Also, each person in the tree has a name, the names are not necessarily unique.

We call the man with a number *a* a 1-ancestor of the man with a number *b*, if the man with a number *a* is a direct ancestor of the man with a number *b*.

We call the man with a number *a* a *k*-ancestor (*k* > 1) of the man with a number *b*, if the man with a number *b* has a 1-ancestor, and the man with a number *a* is a (*k* - 1)-ancestor of the 1-ancestor of the man with a number *b*.

In the tree the family ties do not form cycles. In other words there isn't a person who is his own direct or indirect ancestor (that is, who is an *x*-ancestor of himself, for some *x*, *x* > 0).

We call a man with a number *a* the *k*-son of the man with a number *b*, if the man with a number *b* is a *k*-ancestor of the man with a number *a*.

Polycarpus is very much interested in how many sons and which sons each person has. He took a piece of paper and wrote *m* pairs of numbers *v**i*, *k**i*. Help him to learn for each pair *v**i*, *k**i* the number of distinct names among all names of the *k**i*-sons of the man with number *v**i*.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 105) — the number of people in the tree. Next *n* lines contain the description of people in the tree. The *i*-th line contains space-separated string *s**i* and integer *r**i* (0 ≤ *r**i* ≤ *n*), where *s**i* is the name of the man with a number *i*, and *r**i* is either the number of the direct ancestor of the man with a number *i* or 0, if the man with a number *i* has no direct ancestor. 

The next line contains a single integer *m* (1 ≤ *m* ≤ 105) — the number of Polycarpus's records. Next *m* lines contain space-separated pairs of integers. The *i*-th line contains integers *v**i*, *k**i* (1 ≤ *v**i*, *k**i* ≤ *n*).

It is guaranteed that the family relationships do not form cycles. The names of all people are non-empty strings, consisting of no more than 20 lowercase English letters.

## Output

Print *m* whitespace-separated integers — the answers to Polycarpus's records. Print the answers to the records in the order, in which the records occur in the input.

## Examples

## Input


```
6  
pasha 0  
gerald 1  
gerald 1  
valera 2  
igor 3  
olesya 1  
5  
1 1  
1 2  
1 3  
3 1  
6 1  

```
## Output


```
2  
2  
0  
1  
0  

```
## Input


```
6  
valera 0  
valera 1  
valera 1  
gerald 0  
valera 4  
kolya 4  
7  
1 1  
1 2  
2 1  
2 2  
4 1  
5 1  
6 1  

```
## Output


```
1  
0  
0  
0  
2  
0  
0  

```


#### tags 

#2400 #binary_search #data_structures #dfs_and_similar #dp #sortings 