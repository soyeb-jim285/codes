<h1 style='text-align: center;'> F. Asterisk Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Consider a string $s$ of $n$ lowercase English letters. Let $t_i$ be the string obtained by replacing the $i$-th character of $s$ with an asterisk character *. For example, when $s = \mathtt{abc}$, we have $t_1 = \tt{*bc}$, $t_2 = \tt{a*c}$, and $t_3 = \tt{ab*}$.

Given a string $s$, count the number of distinct strings of lowercase English letters and asterisks that occur as a substring of at least one string in the set $\{s, t_1, \ldots, t_n \}$. The empty string should be counted.

## Note

 that *'s are just characters and do not play any special role as in, for example, regex matching.

### Input

The only line contains a string $s$ of $n$ lowercase English letters ($1 \leq n \leq 10^5$).

### Output

Print a single integer — the number of distinct strings of $s, t_1, \ldots, t_n$.

## Example

### Input


```text
abc
```
### Output


```text
15
```
## Note

For the sample case, the distinct substrings are (empty string), a, b, c, *, ab, a*, bc, b*, *b, *c, abc, ab*, a*c, *bc.



#### Tags 

#3400 #NOT OK #string_suffix_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_606_(Div._1,_based_on_Technocup_2020_Elimination_Round_4).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
