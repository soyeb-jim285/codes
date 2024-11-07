<h1 style='text-align: center;'> E. Dreamoon and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dreamoon has a string *s* and a pattern string *p*. He first removes exactly *x* characters from *s* obtaining string *s*' as a result. Then he calculates ![](images/1192a2998b54697e4a989e6f58ef5fbeb45cb351.png) that is defined as the maximal number of non-overlapping substrings equal to *p* that can be found in *s*'. He wants to make this number as big as possible.

More formally, let's define ![](images/795678a6a9498dc0226eefd698ff90929957a4e3.png) as maximum value of ![](images/1192a2998b54697e4a989e6f58ef5fbeb45cb351.png) over all *s*' that can be obtained by removing exactly *x* characters from *s*. Dreamoon wants to know ![](images/795678a6a9498dc0226eefd698ff90929957a4e3.png) for all *x* from 0 to |*s*| where |*s*| denotes the length of string *s*.

## Input

The first line of the input contains the string *s* (1 ≤ |*s*| ≤ 2 000).

The second line of the input contains the string *p* (1 ≤ |*p*| ≤ 500).

Both strings will only consist of lower case English letters.

## Output

Print |*s*| + 1 space-separated integers in a single line representing the ![](images/795678a6a9498dc0226eefd698ff90929957a4e3.png) for all *x* from 0 to |*s*|.

## Examples

## Input


```
aaaaa  
aa  

```
## Output


```
2 2 1 1 0 0  

```
## Input


```
axbaxxb  
ab  

```
## Output


```
0 1 1 2 1 1 0 0  

```
## Note

For the first sample, the corresponding optimal values of *s*' after removal 0 through |*s*| = 5 characters from *s* are {"aaaaa", "aaaa", "aaa", "aa", "a", ""}. 

For the second sample, possible corresponding optimal values of *s*' are {"axbaxxb", "abaxxb", "axbab", "abab", "aba", "ab", "a", ""}.



#### tags 

#2200 #dp #strings 