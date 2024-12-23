<h1 style='text-align: center;'> B. The Teacher of Physical Education</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

*n* pupils came to Physical Education lesson. We know the name and the height of each pupil. 

Your task is to help the teacher of Physical Education to line up all pupils in non-decreasing order of their heights.

## Input

The first line contains the positive integer *n* (1 ≤ *n* ≤ 5000) — the number of pupils.

The next *n* lines contain the pupils' description. In the *i*-th line there is pupil's name *name**i* (a non-empty string which consists of uppercase and lowercase Latin letters, the length does not exceed five) and pupil's height *x**i* (130 ≤ *x**i* ≤ 215). Some pupils can have the same name. Uppercase and lowercase letters of the alphabet should be considered different. 

## Output

Print *n* lines — pupils' names in the non-decreasing order of their heights. Each line must contain exactly one name. 

If there are several answers, print any of them. Uppercase and lowercase letters of the alphabet should be considered different. 

## Examples

## Input


```
4  
Ivan 150  
Igor 215  
Dasha 158  
Katya 150  

```
## Output


```
Ivan  
Katya  
Dasha  
Igor  

```
## Input


```
2  
SASHA 180  
SASHA 170  

```
## Output


```
SASHA  
SASHA  

```


#### tags 

#1600 #*special 