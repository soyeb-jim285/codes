<h1 style='text-align: center;'> B. Suspects</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As Sherlock Holmes was investigating a crime, he identified *n* suspects. He knows for sure that exactly one of them committed the crime. To find out which one did it, the detective lines up the suspects and numbered them from 1 to *n*. After that, he asked each one: "Which one committed the crime?". Suspect number *i* answered either "The crime was committed by suspect number *a**i*", or "Suspect number *a**i* didn't commit the crime". Also, the suspect could say so about himself (*a**i* = *i*).

Sherlock Holmes understood for sure that exactly *m* answers were the truth and all other answers were a lie. Now help him understand this: which suspect lied and which one told the truth?

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 105, 0 ≤ *m* ≤ *n*) — the total number of suspects and the number of suspects who told the truth. Next *n* lines contain the suspects' answers. The *i*-th line contains either "+*a**i*" (without the quotes), if the suspect number *i* says that the crime was committed by suspect number *a**i*, or "-*a**i*" (without the quotes), if the suspect number *i* says that the suspect number *a**i* didn't commit the crime (*a**i* is an integer, 1 ≤ *a**i* ≤ *n*).

It is guaranteed that at least one suspect exists, such that if he committed the crime, then exactly *m* people told the truth.

## Output

Print *n* lines. Line number *i* should contain "Truth" if suspect number *i* has told the truth for sure. Print "Lie" if the suspect number *i* lied for sure and print "Not defined" if he could lie and could tell the truth, too, depending on who committed the crime.

## Examples

## Input


```
1 1  
+1  

```
## Output


```
Truth  

```
## Input


```
3 2  
-1  
-2  
-3  

```
## Output


```
Not defined  
Not defined  
Not defined  

```
## Input


```
4 1  
+2  
-3  
+4  
-1  

```
## Output


```
Lie  
Not defined  
Lie  
Not defined  

```
## Note

The first sample has the single person and he confesses to the crime, and Sherlock Holmes knows that one person is telling the truth. That means that this person is telling the truth.

In the second sample there are three suspects and each one denies his guilt. Sherlock Holmes knows that only two of them are telling the truth. Any one of them can be the criminal, so we don't know for any of them, whether this person is telling the truth or not.

In the third sample the second and the fourth suspect defend the first and the third one. But only one is telling the truth, thus, the first or the third one is the criminal. Both of them can be criminals, so the second and the fourth one can either be lying or telling the truth. The first and the third one are lying for sure as they are blaming the second and the fourth one.



#### tags 

#1600 #constructive_algorithms #data_structures #implementation 