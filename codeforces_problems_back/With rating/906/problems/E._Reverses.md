<h1 style='text-align: center;'> E. Reverses</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hurricane came to Berland and to suburbs Stringsvill. You are going to it to check if it's all right with you favorite string. Hurrinace broke it a bit by reversing some of its non-intersecting substrings. You have a photo of this string before hurricane and you want to restore it to original state using reversing minimum possible number of its substrings and find out which substrings you should reverse.

You are given a string *s* — original state of your string and string *t* — state of the string after hurricane. You should select *k* non-intersecting substrings of *t* in such a way that after reverse of these substrings string will be equal *s* and *k* is minimum possible.

## Input

First line of input contains string *s* and second line contains string *t*. Both strings have same length and consist of lowercase English letters. 1 ≤ |*s*| = |*t*| ≤ 5·105

## Output

In first line print *k* — minimum number of substrings you should reverse. Next output *k* lines. Each line should contain two integers *l**i*, *r**i* meaning that you should reverse substring from symbol number *l**i* to symbol *r**i* (strings are 1-indexed). These substrings shouldn't intersect. If there are multiple answers print any. If it's impossible to restore string output -1.

## Example

## Input


```
abcxxxdef  
cbaxxxfed  

```
## Output


```
2  
7 9  
1 3  

```


#### tags 

#3300 #dp #string_suffix_structures #strings 