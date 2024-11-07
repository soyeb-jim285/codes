<h1 style='text-align: center;'> A. Sonya and Queries</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today Sonya learned about long integers and invited all her friends to share the fun. Sonya has an initially empty multiset with integers. Friends give her *t* queries, each of one of the following type:

1. +  *a**i* — add non-negative integer *a**i* to the multiset. ## Note

, that she has a multiset, thus there may be many occurrences of the same integer.
2. -  *a**i* — delete a single occurrence of non-negative integer *a**i* from the multiset. It's guaranteed, that there is at least one *a**i* in the multiset.
3. ? *s* — count the number of integers in the multiset (with repetitions) that match some pattern *s* consisting of 0 and 1. In the pattern, 0 stands for the even digits, while 1 stands for the odd. Integer *x* matches the pattern *s*, if the parity of the *i*-th from the right digit in decimal notation matches the *i*-th from the right digit of the pattern. If the pattern is shorter than this integer, it's supplemented with 0-s from the left. Similarly, if the integer is shorter than the pattern its decimal notation is supplemented with the 0-s from the left.

For example, if the pattern is *s* = 010, than integers 92, 2212, 50 and 414 match the pattern, while integers 3, 110, 25 and 1030 do not.

## Input

The first line of the input contains an integer *t* (1 ≤ *t* ≤ 100 000) — the number of operation Sonya has to perform.

Next *t* lines provide the descriptions of the queries in order they appear in the input file. The *i*-th row starts with a character *c**i* — the type of the corresponding operation. If *c**i* is equal to '+' or '-' then it's followed by a space and an integer *a**i* (0 ≤ *a**i* < 1018) given without leading zeroes (unless it's 0). If *c**i* equals '?' then it's followed by a space and a sequence of zeroes and onse, giving the pattern of length no more than 18.

It's guaranteed that there will be at least one query of type '?'.

It's guaranteed that any time some integer is removed from the multiset, there will be at least one occurrence of this integer in it.

## Output

For each query of the third type print the number of integers matching the given pattern. Each integer is counted as many times, as it appears in the multiset at this moment of time.

## Examples

## Input


```
12  
+ 1  
+ 241  
? 1  
+ 361  
- 241  
? 0101  
+ 101  
? 101  
- 101  
? 101  
+ 4000  
? 0  

```
## Output


```
2  
1  
2  
1  
1  

```
## Input


```
4  
+ 200  
+ 200  
- 200  
? 0  

```
## Output


```
1  

```
## Note

Consider the integers matching the patterns from the queries of the third type. Queries are numbered in the order they appear in the input. 

1. 1 and 241.
2. 361.
3. 101 and 361.
4. 361.
5. 4000.


#### tags 

#1400 #data_structures #implementation 