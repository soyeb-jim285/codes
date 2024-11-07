<h1 style='text-align: center;'> D. Vasiliy's Multiset</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Author has gone out of the stories about Vasiliy, so here is just a formal task description.

You are given *q* queries and a multiset *A*, initially containing only integer 0. There are three types of queries:

1. "+ x" — add integer *x* to multiset *A*.
2. "- x" — erase one occurrence of integer *x* from multiset *A*. It's guaranteed that at least one *x* is present in the multiset *A* before this query.
3. "? x" — you are given integer *x* and need to compute the value ![](images/e8f2e13983d6f05b3e4b5b3f51e3fa786849dc1b.png), i.e. the maximum value of bitwise exclusive OR (also know as XOR) of integer *x* and some integer *y* from the multiset *A*.

Multiset is a set, where equal elements are allowed.

## Input

The first line of the input contains a single integer *q* (1 ≤ *q* ≤ 200 000) — the number of queries Vasiliy has to perform.

Each of the following *q* lines of the input contains one of three characters '+', '-' or '?' and an integer *x**i* (1 ≤ *x**i* ≤ 109). It's guaranteed that there is at least one query of the third type.

## Note

, that the integer 0 will always be present in the set *A*.

## Output

For each query of the type '?' print one integer — the maximum value of bitwise exclusive OR (XOR) of integer *x**i* and some integer from the multiset *A*.

## Example

## Input


```
10  
+ 8  
+ 9  
+ 11  
+ 6  
+ 1  
? 3  
- 8  
? 3  
? 8  
? 11  

```
## Output


```
11  
10  
14  
13  

```
## Note

After first five operations multiset *A* contains integers 0, 8, 9, 11, 6 and 1.

The answer for the sixth query is integer ![](images/9e2f3d4f1a7c134a5695ba1d548df2b4f9292206.png) — maximum among integers ![](images/6cb1b5a0f9bbad177b1de700e918187c8fb3e972.png), ![](images/7644536d2010111824755b5dd2b6043340b2bf4d.png), ![](images/9a437d1611f6c2ae5cd9a275a6ab2df61296988e.png), ![](images/4e3eeab99fa495ecdcd103c68de47dd72943016f.png) and ![](images/97b73b0f3e59862ed9f80fa83527d97e0ed0a084.png).



#### tags 

#1800 #binary_search #bitmasks #data_structures #trees 