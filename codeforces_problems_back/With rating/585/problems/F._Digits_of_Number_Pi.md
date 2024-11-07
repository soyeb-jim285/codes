<h1 style='text-align: center;'> F. Digits of Number Pi</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasily has recently learned about the amazing properties of number π. In one of the articles it has been hypothesized that, whatever the sequence of numbers we have, in some position, this sequence is found among the digits of number π. Thus, if you take, for example, the epic novel "War and Peace" of famous Russian author Leo Tolstoy, and encode it with numbers, then we will find the novel among the characters of number π.

Vasily was absolutely delighted with this, because it means that all the books, songs and programs have already been written and encoded in the digits of π. Vasily is, of course, a bit wary that this is only a hypothesis and it hasn't been proved, so he decided to check it out.

To do this, Vasily downloaded from the Internet the archive with the sequence of digits of number π, starting with a certain position, and began to check the different strings of digits on the presence in the downloaded archive. Vasily quickly found short strings of digits, but each time he took a longer string, it turned out that it is not in the archive. Vasily came up with a definition that a string of length *d* is a half-occurrence if it contains a substring of length of at least ![](images/6506c212e342a05fa22dc84170d811bb2bb2327d.png), which occurs in the archive.

To complete the investigation, Vasily took 2 large numbers *x*, *y* (*x* ≤ *y*) with the same number of digits and now he wants to find the number of numbers in the interval from *x* to *y*, which are half-occurrences in the archive. Help Vasily calculate this value modulo 109 + 7.

## Input

The first line contains string *s* consisting of decimal digits (1 ≤ |*s*| ≤ 1000) that Vasily will use to search substrings in. According to hypothesis, this sequence of digis indeed occurs in the decimal representation of π, although we can't guarantee that.

The second and third lines contain two positive integers *x*, *y* of the same length *d* (*x* ≤ *y*, 2 ≤ *d* ≤ 50). Numbers *x*, *y* do not contain leading zeroes.

## Output

Print how many numbers in the segment from *x* to *y* that are half-occurrences in *s* modulo 109 + 7.

## Examples

## Input


```
02  
10  
19  

```
## Output


```
2  

```
## Input


```
023456789  
10  
19  

```
## Output


```
9  

```
## Input


```
31415926535  
10  
29  

```
## Output


```
20  

```


#### tags 

#3200 #dp #implementation #strings 