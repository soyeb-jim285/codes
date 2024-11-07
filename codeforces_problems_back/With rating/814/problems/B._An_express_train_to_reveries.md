<h1 style='text-align: center;'> B. An express train to reveries</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sengoku still remembers the mysterious "colourful meteoroids" she discovered with Lala-chan when they were little. In particular, one of the nights impressed her deeply, giving her the illusion that all her fancies would be realized.

On that night, Sengoku constructed a permutation *p*1, *p*2, ..., *p**n* of integers from 1 to *n* inclusive, with each integer representing a colour, wishing for the colours to see in the coming meteor outburst. Two incredible outbursts then arrived, each with *n* meteorids, colours of which being integer sequences *a*1, *a*2, ..., *a**n* and *b*1, *b*2, ..., *b**n* respectively. Meteoroids' colours were also between 1 and *n* inclusive, and the two sequences were not identical, that is, at least one *i* (1 ≤ *i* ≤ *n*) exists, such that *a**i* ≠ *b**i* holds.

Well, she almost had it all — each of the sequences *a* and *b* matched exactly *n* - 1 elements in Sengoku's permutation. In other words, there is exactly one *i* (1 ≤ *i* ≤ *n*) such that *a**i* ≠ *p**i*, and exactly one *j* (1 ≤ *j* ≤ *n*) such that *b**j* ≠ *p**j*.

For now, Sengoku is able to recover the actual colour sequences *a* and *b* through astronomical records, but her wishes have been long forgotten. You are to reconstruct any possible permutation Sengoku could have had on that night.

## Input

The first line of input contains a positive integer *n* (2 ≤ *n* ≤ 1 000) — the length of Sengoku's permutation, being the length of both meteor outbursts at the same time.

The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n*) — the sequence of colours in the first meteor outburst.

The third line contains *n* space-separated integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ *n*) — the sequence of colours in the second meteor outburst. At least one *i* (1 ≤ *i* ≤ *n*) exists, such that *a**i* ≠ *b**i* holds.

## Output

## Output

 *n* space-separated integers *p*1, *p*2, ..., *p**n*, denoting a possible permutation Sengoku could have had. If there are more than one possible answer, output any one of them.

## Input

 guarantees that such permutation exists.

## Examples

## Input


```
5  
1 2 3 4 3  
1 2 5 4 5  

```
## Output


```
1 2 5 4 3  

```
## Input


```
5  
4 4 2 3 1  
5 4 5 3 1  

```
## Output


```
5 4 2 3 1  

```
## Input


```
4  
1 1 3 4  
1 4 3 4  

```
## Output


```
1 2 3 4  

```
## Note

In the first sample, both 1, 2, 5, 4, 3 and 1, 2, 3, 4, 5 are acceptable outputs.

In the second sample, 5, 4, 2, 3, 1 is the only permutation to satisfy the constraints.



#### tags 

#1300 #constructive_algorithms 