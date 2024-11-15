<h1 style='text-align: center;'> B. Spongebob and Joke</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

While Patrick was gone shopping, Spongebob decided to play a little trick on his friend. The naughty Sponge browsed through Patrick's personal stuff and found a sequence *a*1, *a*2, ..., *a**m* of length *m*, consisting of integers from 1 to *n*, not necessarily distinct. Then he picked some sequence *f*1, *f*2, ..., *f**n* of length *n* and for each number *a**i* got number *b**i* = *f**a**i*. To finish the prank he erased the initial sequence *a**i*.

It's hard to express how sad Patrick was when he returned home from shopping! We will just say that Spongebob immediately got really sorry about what he has done and he is now trying to restore the original sequence. Help him do this or determine that this is impossible.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 100 000) — the lengths of sequences *f**i* and *b**i* respectively.

The second line contains *n* integers, determining sequence *f*1, *f*2, ..., *f**n* (1 ≤ *f**i* ≤ *n*).

The last line contains *m* integers, determining sequence *b*1, *b*2, ..., *b**m* (1 ≤ *b**i* ≤ *n*).

## Output

Print "Possible" if there is exactly one sequence *a**i*, such that *b**i* = *f**a**i* for all *i* from 1 to *m*. Then print *m* integers *a*1, *a*2, ..., *a**m*.

If there are multiple suitable sequences *a**i*, print "Ambiguity".

If Spongebob has made a mistake in his calculations and no suitable sequence *a**i* exists, print "Impossible".

## Examples

## Input


```
3 3  
3 2 1  
1 2 3  

```
## Output


```
Possible  
3 2 1   

```
## Input


```
3 3  
1 1 1  
1 1 1  

```
## Output


```
Ambiguity  

```
## Input


```
3 3  
1 2 1  
3 3 3  

```
## Output


```
Impossible  

```
## Note

In the first sample 3 is replaced by 1 and vice versa, while 2 never changes. The answer exists and is unique.

In the second sample all numbers are replaced by 1, so it is impossible to unambiguously restore the original sequence.

In the third sample *f**i* ≠ 3 for all *i*, so no sequence *a**i* transforms into such *b**i* and we can say for sure that Spongebob has made a mistake.



#### tags 

#1500 #implementation 