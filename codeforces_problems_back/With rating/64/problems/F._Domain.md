<h1 style='text-align: center;'> F. Domain</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

This problem doesn't contain real-world specifications about domains, just use the problem statement as a formal document to solve the problem.

The given string *s* is a domain name if it contains the characters "a"-"z", "0"-"9" and dots. No two dots shoud follow one after another (consecutive). The dots split the given string *s* into the parts, the last (most right) part should have the length 2 or 3. Domain can't start or end with a dot.

You are given the string *s*, check if it is domain name.

## Input

The only line of the input contains given string *s*. The string may contain any characters with ASCII codes from 33 to 127, inclusive. The string length is between 1 and 100, inclusive.

## Output

Print "YES" if the given string *s* is a domain name, or print "NO" if it is not.

## Examples

## Input


```
codeforces.com  

```
## Output


```
YES  

```
## Input


```
mail.v-kontakte.ru  

```
## Output


```
NO  

```


#### tags 

#2000 #*special #expression_parsing 