<h1 style='text-align: center;'> D. Crime Management</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Zeyad wants to commit *n* crimes in Egypt and not be punished at the end. There are several types of crimes. For example, bribery is a crime but is not considered such when repeated twice. Therefore, bribery is not considered a crime when repeated an even number of times. Speeding is a crime, but is not considered such when repeated a number of times which is a multiple of five.

More specifically, *c* conditions on crime repetitions are known. Each condition describes the crime type *t**i* and its multiplicity *m**i*. If the number of times Zeyad committed the crime *t**i* is a multiple of *m**i*, Zeyad will not be punished for crime *t**i*. Some crimes may be listed more than once. In this case fulfilling at least one condition for this crime is enough to not be punished for it. Of course, if for certain crime the number of times Zeyad committed it is zero, he is innocent with respect to this crime.

Now Zeyad is interested in a number of ways he can commit exactly *n* crimes without any punishment.

The order of commiting the crimes matters. More formally, two ways, sequences *w*1 and *w*2, of committing *n* crimes are equal if *w*1*i* = *w*2*i*, for all 1 ≤ *i* ≤ *n*.

## Input

The first line contains two integers *n* and *c* (0 ≤ *n* ≤ 1018, 0 ≤ *c* ≤ 1000) — the number of crimes Zeyad would like to commit and the number of conditions he is aware of.

Then the definitions for *c* conditions follow. There are 26 types of crimes. Each crime definition consists of crime type — a capital Latin letter — and its multiplicity. 

The multiplicity of each crime is a positive integer number and the product of all multiplicities does not exceed 123. Some conditions may be repeated in the input more than once.

Crime of multiplicity 1 is not yielding any punishment regardless of the number of times it was committed. The strictness of the law is compensated by the fact that it's non-mandatory.

Obviously, if some crime is not listed in the set of conditions, then Zeyad will not consider it, as committing it would unavoidably lead to the punishment.

Please, do not use the %lld specificator to read or write 64-bit integers in С++. It is preferred to use the cin stream (you may also use the %I64d specificator).

## Output

## Output

 the number of different ways Zeyad can commit exactly *n* crimes with no punishment modulo 12345.

## Examples

## Input


```
5 2  
A 1  
B 2  

```
## Output


```
16  

```
## Input


```
6 3  
A 1  
B 2  
C 3  

```
## Output


```
113  

```
## Input


```
8 3  
A 2  
A 3  
B 2  

```
## Output


```
128  

```
## Note

In the first test case, the 16 ways are: AAAAA, AAABB, AABAB, AABBA, ABAAB, ABABA, ABBAA, BAAAB, BAABA, BABAA, BBAAA, ABBBB, BABBB, BBABB, BBBAB, BBBBA.



#### tags 

#2400 #dp #graphs #matrices 