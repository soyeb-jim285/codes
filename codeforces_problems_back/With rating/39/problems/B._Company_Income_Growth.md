<h1 style='text-align: center;'> B. Company Income Growth</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

Petya works as a PR manager for a successful Berland company BerSoft. He needs to prepare a presentation on the company income growth since 2001 (the year of its founding) till now. Petya knows that in 2001 the company income amounted to *a*1 billion bourles, in 2002 — to *a*2 billion, ..., and in the current (2000 + *n*)-th year — *a**n* billion bourles. On the base of the information Petya decided to show in his presentation the linear progress history which is in his opinion perfect. According to a graph Petya has already made, in the first year BerSoft company income must amount to 1 billion bourles, in the second year — 2 billion bourles etc., each following year the income increases by 1 billion bourles. Unfortunately, the real numbers are different from the perfect ones. Among the numbers *a**i* can even occur negative ones that are a sign of the company’s losses in some years. That is why Petya wants to ignore some data, in other words, cross some numbers *a**i* from the sequence and leave only some subsequence that has perfect growth.

Thus Petya has to choose a sequence of years *y*1, *y*2, ..., *y**k*,so that in the year *y*1 the company income amounted to 1 billion bourles, in the year *y*2 — 2 billion bourles etc., in accordance with the perfect growth dynamics. Help him to choose the longest such sequence.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 100). The next line contains *n* integers *a**i* ( - 100 ≤ *a**i* ≤ 100). The number *a**i* determines the income of BerSoft company in the (2000 + *i*)-th year. The numbers in the line are separated by spaces.

## Output

## Output

 *k* — the maximum possible length of a perfect sequence. In the next line output the sequence of years *y*1, *y*2, ..., *y**k*. Separate the numbers by spaces. If the answer is not unique, output any. If no solution exist, output one number 0.

## Examples

## Input


```
10  
-2 1 1 3 2 3 4 -10 -2 5  

```
## Output


```
5  
2002 2005 2006 2007 2010  

```
## Input


```
3  
-1 -2 -3  

```
## Output


```
0  

```


#### tags 

#1300 #greedy 