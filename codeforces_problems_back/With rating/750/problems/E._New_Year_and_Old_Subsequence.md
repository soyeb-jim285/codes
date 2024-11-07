<h1 style='text-align: center;'> E. New Year and Old Subsequence</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A string *t* is called nice if a string "2017" occurs in *t* as a subsequence but a string "2016" doesn't occur in *t* as a subsequence. For example, strings "203434107" and "9220617" are nice, while strings "20016", "1234" and "20167" aren't nice.

The ugliness of a string is the minimum possible number of characters to remove, in order to obtain a nice string. If it's impossible to make a string nice by removing characters, its ugliness is  - 1.

Limak has a string *s* of length *n*, with characters indexed 1 through *n*. He asks you *q* queries. In the *i*-th query you should compute and print the ugliness of a substring (continuous subsequence) of *s* starting at the index *a**i* and ending at the index *b**i* (inclusive).

## Input

The first line of the input contains two integers *n* and *q* (4 ≤ *n* ≤ 200 000, 1 ≤ *q* ≤ 200 000) — the length of the string *s* and the number of queries respectively.

The second line contains a string *s* of length *n*. Every character is one of digits '0'–'9'.

The *i*-th of next *q* lines contains two integers *a**i* and *b**i* (1 ≤ *a**i* ≤ *b**i* ≤ *n*), describing a substring in the *i*-th query.

## Output

For each query print the ugliness of the given substring.

## Examples

## Input


```
8 3  
20166766  
1 8  
1 7  
2 8  

```
## Output


```
4  
3  
-1  

```
## Input


```
15 5  
012016662091670  
3 4  
1 14  
4 15  
1 13  
10 15  

```
## Output


```
-1  
2  
1  
-1  
-1  

```
## Input


```
4 2  
1234  
2 4  
1 2  

```
## Output


```
-1  
-1  

```
## Note

In the first sample:

* In the first query, *ugliness*("20166766") = 4 because all four sixes must be removed.
* In the second query, *ugliness*("2016676") = 3 because all three sixes must be removed.
* In the third query, *ugliness*("0166766") =  - 1 because it's impossible to remove some digits to get a nice string.

In the second sample:

* In the second query, *ugliness*("01201666209167") = 2. It's optimal to remove the first digit '2' and the last digit '6', what gives a string "010166620917", which is nice.
* In the third query, *ugliness*("016662091670") = 1. It's optimal to remove the last digit '6', what gives a nice string "01666209170".


#### tags 

#2600 #data_structures #divide_and_conquer #dp #matrices 