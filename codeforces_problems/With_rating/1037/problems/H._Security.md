<h1 style='text-align: center;'> H. Security</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Some programming website is establishing a secure communication protocol. For security reasons, they want to choose several more or less random strings.

Initially, they have a string $s$ consisting of lowercase English letters. Now they want to choose $q$ strings using the following steps, and you are to help them.

1. A string $x$ consisting of lowercase English letters and integers $l$ and $r$ ($1 \leq l \leq r \leq |s|$) are chosen.
2. Consider all non-empty distinct substrings of the $s_l s_{l + 1} \ldots s_r$, that is all distinct strings $s_i s_{i+1} \ldots s_{j}$ where $l \le i \le j \le r$. Among all of them choose all strings that are lexicographically greater than $x$.
3. If there are no such strings, you should print $-1$. Otherwise print the lexicographically smallest among them.

String $a$ is lexicographically less than string $b$, if either $a$ is a prefix of $b$ and $a \ne b$, or there exists such a position $i$ ($1 \le i \le min(|a|, |b|)$), such that $a_i < b_i$ and for all $j$ ($1 \le j < i$) $a_j = b_j$. Here $|a|$ denotes the length of the string $a$.

##### Input

The first line of input contains a non-empty string $s$ ($1 \leq |s| \leq 10^{5}$) consisting of lowercase English letters.

The second line contains an integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of strings to select.

Each of the next $q$ lines contains two integers $l$, $r$ ($1 \leq l \leq r \leq |s|$) and a non-empty string $x$ consisting of lowercase English letters. The total length of strings $x$ for all queries does not exceed $2 \cdot 10^{5}$.

##### Output

##### Output

 $q$ lines, each of them should contain the desired string or $-1$, if there is no such string.

## Examples

##### Input


```text
baa  
5  
1 2 ba  
2 3 a  
1 2 b  
2 3 aa  
1 3 b  

```
##### Output


```text
-1  
aa  
ba  
-1  
ba  

```
##### Input


```text
bacb  
4  
1 2 ba  
2 3 ac  
1 3 ac  
3 4 c  

```
##### Output


```text
-1  
c  
b  
cb  

```
##### Input


```text
bba  
1  
1 1 b  

```
##### Output


```text
-1  

```
## Note

Consider the first example.

The string $s$ is "baa". The queries are as follows.

1. We consider the substring $s_1 s_2$ that is "ba". It has substrings "b", "a" and "ba", since none of them is greater than the query string "ba", the answer is $-1$.
2. We consider substring "aa". Among its substrings only "aa" is greater than the query string "a". So the answer is "aa".
3. We consider substring "ba". Out of "b", "a" and "ba" only "ba" is greater than the query string "b", so the answer is "ba".
4. We consider substring "aa". No substring of "aa" is greater than the query string "aa" so the answer is $-1$.
5. We consider substring "baa" and it has (among others) substrings "ba", "baa" which are greater than the query string "b". Since "ba" is lexicographically smaller than "baa", the answer is "ba".


#### Tags 

#3200 #NOT OK #data_structures #string_suffix_structures 

## Blogs
- [All Contest Problems](../Manthan,_Codefest_18_(rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
