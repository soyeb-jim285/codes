<h1 style='text-align: center;'> C. Running Track</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A boy named Ayrat lives on planet AMI-1511. Each inhabitant of this planet has a talent. Specifically, Ayrat loves running, moreover, just running is not enough for him. He is dreaming of making running a real art.

First, he wants to construct the running track with coating *t*. On planet AMI-1511 the coating of the track is the sequence of colored blocks, where each block is denoted as the small English letter. Therefore, every coating can be treated as a string.

Unfortunately, blocks aren't freely sold to non-business customers, but Ayrat found an infinite number of coatings *s*. Also, he has scissors and glue. Ayrat is going to buy some coatings *s*, then cut out from each of them exactly one continuous piece (substring) and glue it to the end of his track coating. Moreover, he may choose to flip this block before glueing it. Ayrat want's to know the minimum number of coating *s* he needs to buy in order to get the coating *t* for his running track. Of course, he also want's to know some way to achieve the answer.

## Input

First line of the input contains the string *s* — the coating that is present in the shop. Second line contains the string *t* — the coating Ayrat wants to obtain. Both strings are non-empty, consist of only small English letters and their length doesn't exceed 2100.

## Output

The first line should contain the minimum needed number of coatings *n* or -1 if it's impossible to create the desired coating.

If the answer is not -1, then the following *n* lines should contain two integers *x**i* and *y**i* — numbers of ending blocks in the corresponding piece. If *x**i* ≤ *y**i* then this piece is used in the regular order, and if *x**i* > *y**i* piece is used in the reversed order. Print the pieces in the order they should be glued to get the string *t*.

## Examples

## Input


```
abc  
cbaabc  

```
## Output


```
2  
3 1  
1 3  

```
## Input


```
aaabrytaaa  
ayrat  

```
## Output


```
3  
1 1  
6 5  
8 7  

```
## Input


```
ami  
no  

```
## Output


```
-1  

```
## Note

In the first sample string "cbaabc" = "cba" + "abc".

In the second sample: "ayrat" = "a" + "yr" + "at".



#### tags 

#2000 #dp #greedy #strings #trees 