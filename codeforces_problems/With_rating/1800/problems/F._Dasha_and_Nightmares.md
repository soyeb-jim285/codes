<h1 style='text-align: center;'> F. Dasha and Nightmares</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Dasha, an excellent student, is studying at the best mathematical lyceum in the country. Recently, a mysterious stranger brought $n$ words consisting of small latin letters $s_1, s_2, \ldots, s_n$ to the lyceum. Since that day, Dasha has been tormented by nightmares.

Consider some pair of integers $\langle i, j \rangle$ ($1 \le i \le j \le n$). A nightmare is a string for which it is true:

* It is obtained by concatenation $s_{i}s_{j}$;
* Its length is odd;
* The number of different letters in it is exactly $25$;
* The number of occurrences of each letter that is in the word is odd.

For example, if $s_i=$ "abcdefg" and $s_j=$ "ijklmnopqrstuvwxyz", the pair $\langle i, j \rangle$ creates a nightmare.

Dasha will stop having nightmares if she counts their number. There are too many nightmares, so Dasha needs your help. Count the number of different nightmares.

Nightmares are called different if the corresponding pairs $\langle i, j \rangle$ are different. The pairs $\langle i_1, j_1 \rangle$ and $\langle i_2, j_2 \rangle$ are called different if $i_1 \neq i_2$ or $j_1 \neq j_2$.

### Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of words.

The following $n$ lines contain the words $s_1, s_2, \ldots, s_n$, consisting of small latin letters.

It is guaranteed that the total length of words does not exceed $5 \cdot 10^6$.

### Output

Print a single integer — the number of different nightmares.

## Example

### Input


```text
10ftlabcdefghijklmnopqrstuvwxyabcdeffghijkllmnopqrsttuvwxyffftlaabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyythedevidbcdefghhiiiijklmnopqrsuwxyzgorillasilverbackabcdefgijklmnopqrstuvwxyz
```
### Output

```text

5

```
## Note

In the first test, nightmares are created by pairs $\langle 1, 3 \rangle$, $\langle 2, 5 \rangle$, $\langle 3, 4 \rangle$, $\langle 6, 7 \rangle$, $\langle 9, 10 \rangle$.



#### Tags 

#1900 #NOT OK #bitmasks #hashing #meet-in-the-middle #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_855_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
