<h1 style='text-align: center;'> D. Tavas and Malekas</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tavas is a strange creature. Usually "zzz" comes out of people's mouth while sleeping, but string *s* of length *n* comes out from Tavas' mouth instead.

 ![](images/6f1c94e6d6b2b5bdfd15dbf7f81f50aecd7a1d99.png) Today Tavas fell asleep in Malekas' place. While he was sleeping, Malekas did a little process on *s*. Malekas has a favorite string *p*. He determined all positions *x*1 < *x*2 < ... < *x**k* where *p* matches *s*. More formally, for each *x**i* (1 ≤ *i* ≤ *k*) he condition *s**x**i**s**x**i* + 1... *s**x**i* + |*p*| - 1 = *p* is fullfilled.

Then Malekas wrote down one of subsequences of *x*1, *x*2, ... *x**k* (possibly, he didn't write anything) on a piece of paper. Here a sequence *b* is a subsequence of sequence *a* if and only if we can turn *a* into *b* by removing some of its elements (maybe no one of them or all).

After Tavas woke up, Malekas told him everything. He couldn't remember string *s*, but he knew that both *p* and *s* only contains lowercase English letters and also he had the subsequence he had written on that piece of paper.

Tavas wonders, what is the number of possible values of *s*? He asked SaDDas, but he wasn't smart enough to solve this. So, Tavas asked you to calculate this number for him.

Answer can be very large, so Tavas wants you to print the answer modulo 109 + 7.

## Input

The first line contains two integers *n* and *m*, the length of *s* and the length of the subsequence Malekas wrote down (1 ≤ *n* ≤ 106 and 0 ≤ *m* ≤ *n* - |*p*| + 1).

The second line contains string *p* (1 ≤ |*p*| ≤ *n*).

The next line contains *m* space separated integers *y*1, *y*2, ..., *y**m*, Malekas' subsequence (1 ≤ *y*1 < *y*2 < ... < *y**m* ≤ *n* - |*p*| + 1).

## Output

In a single line print the answer modulo 1000 000 007.

## Examples

## Input


```
6 2  
ioi  
1 3  

```
## Output


```
26  

```
## Input


```
5 2  
ioi  
1 2  

```
## Output


```
0  

```
## Note

In the first sample test all strings of form "ioioi?" where the question mark replaces arbitrary English letter satisfy.

Here |*x*| denotes the length of string x.

Please note that it's possible that there is no such string (answer is 0).



#### tags 

#1900 #greedy #hashing #string_suffix_structures #strings 