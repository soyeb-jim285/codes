<h1 style='text-align: center;'> A. Newspaper Headline</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A newspaper is published in Walrusland. Its heading is *s*1, it consists of lowercase Latin letters. Fangy the little walrus wants to buy several such newspapers, cut out their headings, glue them one to another in order to get one big string. After that walrus erase several letters from this string in order to get a new word *s*2. It is considered that when Fangy erases some letter, there's no whitespace formed instead of the letter. That is, the string remains unbroken and it still only consists of lowercase Latin letters.

For example, the heading is "abc". If we take two such headings and glue them one to the other one, we get "abcabc". If we erase the letters on positions 1 and 5, we get a word "bcac".

Which least number of newspaper headings *s*1 will Fangy need to glue them, erase several letters and get word *s*2?

## Input

The input data contain two lines. The first line contain the heading *s*1, the second line contains the word *s*2. The lines only consist of lowercase Latin letters (1 ≤ |*s*1| ≤ 104, 1 ≤ |*s*2| ≤ 106).

## Output

If it is impossible to get the word *s*2 in the above-described manner, print "-1" (without the quotes). Otherwise, print the least number of newspaper headings *s*1, which Fangy will need to receive the word *s*2.

## Examples

## Input


```
abc  
xyz  

```
## Output


```
-1  

```
## Input


```
abcd  
dabc  

```
## Output


```
2  

```


#### tags 

#1500 #greedy #strings 