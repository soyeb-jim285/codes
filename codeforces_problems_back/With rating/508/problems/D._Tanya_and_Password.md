<h1 style='text-align: center;'> D. Tanya and Password</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

While dad was at work, a little girl Tanya decided to play with dad's password to his secret database. Dad's password is a string consisting of *n* + 2 characters. She has written all the possible *n* three-letter continuous substrings of the password on pieces of paper, one for each piece of paper, and threw the password out. Each three-letter substring was written the number of times it occurred in the password. Thus, Tanya ended up with *n* pieces of paper.

Then Tanya realized that dad will be upset to learn about her game and decided to restore the password or at least any string corresponding to the final set of three-letter strings. You have to help her in this difficult task. We know that dad's password consisted of lowercase and uppercase letters of the Latin alphabet and digits. Uppercase and lowercase letters of the Latin alphabet are considered distinct.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 2·105), the number of three-letter substrings Tanya got. 

Next *n* lines contain three letters each, forming the substring of dad's password. Each character in the input is a lowercase or uppercase Latin letter or a digit.

## Output

If Tanya made a mistake somewhere during the game and the strings that correspond to the given set of substrings don't exist, print "NO". 

If it is possible to restore the string that corresponds to given set of substrings, print "YES", and then print any suitable password option.

## Examples

## Input


```
5  
aca  
aba  
aba  
cab  
bac  

```
## Output


```
YES  
abacaba  

```
## Input


```
4  
abc  
bCb  
cb1  
b13  

```
## Output


```
NO  

```
## Input


```
7  
aaa  
aaa  
aaa  
aaa  
aaa  
aaa  
aaa  

```
## Output


```
YES  
aaaaaaaaa  

```


#### tags 

#2500 #dfs_and_similar #graphs 