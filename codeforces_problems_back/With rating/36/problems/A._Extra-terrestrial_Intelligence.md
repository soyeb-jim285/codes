<h1 style='text-align: center;'> A. Extra-terrestrial Intelligence</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

Recently Vasya got interested in finding extra-terrestrial intelligence. He made a simple extra-terrestrial signals’ receiver and was keeping a record of the signals for *n* days in a row. Each of those *n* days Vasya wrote a 1 in his notebook if he had received a signal that day and a 0 if he hadn’t. Vasya thinks that he has found extra-terrestrial intelligence if there is a system in the way the signals has been received, i.e. if all the intervals between successive signals are equal. Otherwise, Vasya thinks that the signals were sent by some stupid aliens no one cares about. Help Vasya to deduce from the information given by the receiver if he has found extra-terrestrial intelligence or not.

## Input

The first line contains integer *n* (3 ≤ *n* ≤ 100) — amount of days during which Vasya checked if there were any signals. The second line contains *n* characters 1 or 0 — the record Vasya kept each of those *n* days. It’s guaranteed that the given record sequence contains at least three 1s.

## Output

If Vasya has found extra-terrestrial intelligence, output YES, otherwise output NO.

## Examples

## Input


```
8  
00111000  

```
## Output


```
YES  

```
## Input


```
7  
1001011  

```
## Output


```
NO  

```
## Input


```
7  
1010100  

```
## Output


```
YES  

```


#### tags 

#1300 #implementation 