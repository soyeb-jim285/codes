<h1 style='text-align: center;'> E. Flag 2</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 128 megabytes</h5>

According to a new ISO standard, a flag of every country should have, strangely enough, a chequered field *n* × *m*, each square should be wholly painted one of 26 colours. The following restrictions are set: 

* In each row at most two different colours can be used.
* No two adjacent squares can be painted the same colour.

Pay attention, please, that in one column more than two different colours can be used.

Berland's government took a decision to introduce changes into their country's flag in accordance with the new standard, at the same time they want these changes to be minimal. By the given description of Berland's flag you should find out the minimum amount of squares that need to be painted different colour to make the flag meet the new ISO standard. You are as well to build one of the possible variants of the new Berland's flag.

## Input

The first input line contains 2 integers *n* and *m* (1 ≤ *n*, *m* ≤ 500) — amount of rows and columns in Berland's flag respectively. Then there follows the flag's description: each of the following *n* lines contains *m* characters. Each character is a letter from a to z, and it stands for the colour of the corresponding square.

## Output

In the first line output the minimum amount of squares that need to be repainted to make the flag meet the new ISO standard. The following *n* lines should contain one of the possible variants of the new flag. Don't forget that the variant of the flag, proposed by you, should be derived from the old flag with the minimum amount of repainted squares. If the answer isn't unique, output any.

## Examples

## Input


```
3 4  
aaaa  
bbbb  
cccc  

```
## Output


```
6  
abab  
baba  
acac  

```
## Input


```
3 3  
aba  
aba  
zzz  

```
## Output


```
4  
aba  
bab  
zbz  

```


#### tags 

#2000 #dp 