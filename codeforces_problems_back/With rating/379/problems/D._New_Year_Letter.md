<h1 style='text-align: center;'> D. New Year Letter</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Many countries have such a New Year or Christmas tradition as writing a letter to Santa including a wish list for presents. Vasya is an ordinary programmer boy. Like all ordinary boys, he is going to write the letter to Santa on the New Year Eve (we Russians actually expect Santa for the New Year, not for Christmas). 

Vasya has come up with an algorithm he will follow while writing a letter. First he chooses two strings, *s*1 anf *s*2, consisting of uppercase English letters. Then the boy makes string *s**k*, using a recurrent equation *s**n* = *s**n* - 2 + *s**n* - 1, operation '+' means a concatenation (that is, the sequential record) of strings in the given order. Then Vasya writes down string *s**k* on a piece of paper, puts it in the envelope and sends in to Santa. 

Vasya is absolutely sure that Santa will bring him the best present if the resulting string *s**k* has exactly *x* occurrences of substring AC (the short-cut reminds him оf accepted problems). Besides, Vasya decided that string *s*1 should have length *n*, and string *s*2 should have length *m*. Vasya hasn't decided anything else.

At the moment Vasya's got urgent New Year business, so he asks you to choose two strings for him, *s*1 and *s*2 in the required manner. Help Vasya.

## Input

The first line contains four integers *k*, *x*, *n*, *m* (3 ≤ *k* ≤ 50; 0 ≤ *x* ≤ 109; 1 ≤ *n*, *m* ≤ 100).

## Output

In the first line print string *s*1, consisting of *n* uppercase English letters. In the second line print string *s*2, consisting of *m* uppercase English letters. If there are multiple valid strings, print any of them.

If the required pair of strings doesn't exist, print "Happy new year!" without the quotes.

## Examples

## Input


```
3 2 2 2  

```
## Output


```
AC  
AC  

```
## Input


```
3 3 2 2  

```
## Output


```
Happy new year!  

```
## Input


```
3 0 2 2  

```
## Output


```
AA  
AA  

```
## Input


```
4 3 2 1  

```
## Output


```
Happy new year!  

```
## Input


```
4 2 2 1  

```
## Output


```
Happy new year!  

```


#### tags 

#2000 #bitmasks #brute_force #dp 