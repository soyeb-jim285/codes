<h1 style='text-align: center;'> E. Director</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya is a born Berland film director, he is currently working on a new blockbuster, "The Unexpected". Vasya knows from his own experience how important it is to choose the main characters' names and surnames wisely. He made up a list of *n* names and *n* surnames that he wants to use. Vasya haven't decided yet how to call characters, so he is free to match any name to any surname. Now he has to make the list of all the main characters in the following format: "*Name*1 *Surname*1, *Name*2 *Surname*2, ..., *Name**n* *Surname**n*", i.e. all the name-surname pairs should be separated by exactly one comma and exactly one space, and the name should be separated from the surname by exactly one space. First of all Vasya wants to maximize the number of the pairs, in which the name and the surname start from one letter. If there are several such variants, Vasya wants to get the lexicographically minimal one. Help him.

An answer will be verified a line in the format as is shown above, including the needed commas and spaces. It's the lexicographical minimality of such a line that needs to be ensured. The output line shouldn't end with a space or with a comma.

## Input

The first input line contains number *n* (1 ≤ *n* ≤ 100) — the number of names and surnames. Then follow *n* lines — the list of names. Then follow *n* lines — the list of surnames. No two from those 2*n* strings match. Every name and surname is a non-empty string consisting of no more than 10 Latin letters. It is guaranteed that the first letter is uppercase and the rest are lowercase.

## Output

The output data consist of a single line — the needed list. Note that one should follow closely the output data format!

## Examples

## Input


```
4  
Ann  
Anna  
Sabrina  
John  
Petrov  
Ivanova  
Stoltz  
Abacaba  

```
## Output


```
Ann Abacaba, Anna Ivanova, John Petrov, Sabrina Stoltz
```
## Input


```
4  
Aa  
Ab  
Ac  
Ba  
Ad  
Ae  
Bb  
Bc  

```
## Output


```
Aa Ad, Ab Ae, Ac Bb, Ba Bc
```


#### tags 

#2000 #constructive_algorithms #greedy 