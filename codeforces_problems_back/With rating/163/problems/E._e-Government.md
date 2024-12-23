<h1 style='text-align: center;'> E. e-Government</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The best programmers of Embezzland compete to develop a part of the project called "e-Government" — the system of automated statistic collecting and press analysis.

We know that any of the *k* citizens can become a member of the Embezzland government. The citizens' surnames are *a*1, *a*2, ..., *a**k*. All surnames are different. Initially all *k* citizens from this list are members of the government. The system should support the following options:

* Include citizen *a**i* to the government.
* Exclude citizen *a**i* from the government.
* Given a newspaper article text, calculate how politicized it is. To do this, for every active government member the system counts the number of times his surname occurs in the text as a substring. All occurrences are taken into consideration, including the intersecting ones. The degree of politicization of a text is defined as the sum of these values for all active government members.

Implement this system.

## Input

The first line contains space-separated integers *n* and *k* (1 ≤ *n*, *k* ≤ 105) — the number of queries to the system and the number of potential government members.

Next *k* lines contain the surnames *a*1, *a*2, ..., *a**k*, one per line. All surnames are pairwise different.

Next *n* lines contain queries to the system, one per line. Each query consists of a character that determines an operation and the operation argument, written consecutively without a space.

Operation "include in the government" corresponds to the character "+", operation "exclude" corresponds to "-". An argument of those operations is an integer between 1 and *k* — the index of the citizen involved in the operation. Any citizen can be included and excluded from the government an arbitrary number of times in any order. Including in the government a citizen who is already there or excluding the citizen who isn't there changes nothing.

The operation "calculate politicization" corresponds to character "?". Its argument is a text.

All strings — surnames and texts — are non-empty sequences of lowercase Latin letters. The total length of all surnames doesn't exceed 106, the total length of all texts doesn't exceed 106.

## Output

For any "calculate politicization" operation print on a separate line the degree of the politicization of the given text. Print nothing for other operations.

## Examples

## Input


```
7 3  
a  
aa  
ab  
?aaab  
-2  
?aaab  
-3  
?aaab  
+2  
?aabbaa  

```
## Output


```
6  
4  
3  
6  

```


#### tags 

#2800 #data_structures #dfs_and_similar #dp #strings #trees 