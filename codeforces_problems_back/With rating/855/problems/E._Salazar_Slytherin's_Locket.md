<h1 style='text-align: center;'> E. Salazar Slytherin's Locket</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Harry came to know from Dumbledore that Salazar Slytherin's locket is a horcrux. This locket was present earlier at 12 Grimmauld Place, the home of Sirius Black's mother. It was stolen from there and is now present in the Ministry of Magic in the office of Dolorous Umbridge, Harry's former Defense Against the Dark Arts teacher. 

Harry, Ron and Hermione are infiltrating the Ministry. Upon reaching Umbridge's office, they observed a code lock with a puzzle asking them to calculate count of magic numbers between two integers *l* and *r* (both inclusive). 

Harry remembered from his detention time with Umbridge that she defined a magic number as a number which when converted to a given base *b*, all the digits from 0 to *b* - 1 appear even number of times in its representation without any leading zeros.

You have to answer *q* queries to unlock the office. Each query has three integers *b**i*, *l**i* and *r**i*, the base and the range for which you have to find the count of magic numbers.

## Input

First line of input contains *q* (1 ≤ *q* ≤ 105) — number of queries.

Each of the next *q* lines contain three space separated integers *b**i*, *l**i*, *r**i* (2 ≤ *b**i* ≤ 10, 1 ≤ *l**i* ≤ *r**i* ≤ 1018).

## Output

You have to output *q* lines, each containing a single integer, the answer to the corresponding query.

## Examples

## Input


```
2  
2 4 9  
3 1 10  

```
## Output


```
1  
2  

```
## Input


```
2  
2 1 100  
5 1 100  

```
## Output


```
21  
4  

```
## Note

In sample test case 1, for first query, when we convert numbers 4 to 9 into base 2, we get: 

* 4 = 1002,
* 5 = 1012,
* 6 = 1102,
* 7 = 1112,
* 8 = 10002,
* 9 = 10012.

Out of these, only base 2 representation of 9 has even number of 1 and 0. Thus, the answer is 1.



#### tags 

#2200 #bitmasks #dp 