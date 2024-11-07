<h1 style='text-align: center;'> D. Scissors</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jenya has recently acquired quite a useful tool — *k*-scissors for cutting strings. They are generally used for cutting out two non-intersecting substrings of length *k* from an arbitrary string *s* (its length should be at least 2·*k* in order to perform this operation) and concatenating them afterwards (preserving the initial order). For example, with the help of 2-scissors you can cut *ab* and *de* out of *abcde* and concatenate them into *abde*, but not *ab* and *bc* since they're intersecting.

It's a nice idea to test this tool before using it in practice. After looking through the papers, Jenya came up with two strings *s* and *t*. His question is whether it is possible to apply his scissors to string *s* such that the resulting concatenation contains *t* as a substring?

##### Input

The first line contains three integers *n*, *m*, *k* (2 ≤ *m* ≤ 2·*k* ≤ *n* ≤ 5·105) — length of *s*, length of *t* and the aforementioned scissors' parameter correspondingly.

The next two lines feature *s* and *t* consisting of lowercase latin letters.

##### Output

If there is no answer, print «No». 

Otherwise print «Yes» and two integers *L* and *R* denoting the indexes where cutted substrings start (1-indexed). If there are several possible answers, output any.

## Examples

##### Input


```text
7 4 3  
baabaab  
aaaa  

```
##### Output


```text
Yes  
1 5  

```
##### Input


```text
6 3 2  
cbcbcb  
bcc  

```
##### Output


```text
Yes  
2 5  

```
##### Input


```text
7 5 3  
aabbaaa  
aaaaa  

```
##### Output


```text
No  

```
## Note

In the first sample case you can cut out two substrings starting at 1 and 5. The resulting string baaaab contains aaaa as a substring.

In the second sample case the resulting string is bccb.



#### Tags 

#2600 #NOT OK #brute_force #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_471_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial](../blogs/Editorial.md)
