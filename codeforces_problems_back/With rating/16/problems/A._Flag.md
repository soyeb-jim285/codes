<h1 style='text-align: center;'> A. Flag</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

According to a new ISO standard, a flag of every country should have a chequered field *n* × *m*, each square should be of one of 10 colours, and the flag should be «striped»: each horizontal row of the flag should contain squares of the same colour, and the colours of adjacent horizontal rows should be different. Berland's government asked you to find out whether their flag meets the new ISO standard.

## Input

The first line of the input contains numbers *n* and *m* (1 ≤ *n*, *m* ≤ 100), *n* — the amount of rows, *m* — the amount of columns on the flag of Berland. Then there follows the description of the flag: each of the following *n* lines contain *m* characters. Each character is a digit between 0 and 9, and stands for the colour of the corresponding square.

## Output

## Output

 YES, if the flag meets the new ISO standard, and NO otherwise.

## Examples

## Input


```
3 3  
000  
111  
222  

```
## Output


```
YES  

```
## Input


```
3 3  
000  
000  
111  

```
## Output


```
NO  

```
## Input


```
3 3  
000  
111  
002  

```
## Output


```
NO  

```


#### tags 

#800 #implementation 