<h1 style='text-align: center;'> G. Rudolf and CodeVid-23</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A new virus called "CodeVid-23" has spread among programmers. Rudolf, being a programmer, was not able to avoid it.

There are $n$ symptoms numbered from $1$ to $n$ that can appear when infected. Initially, Rudolf has some of them. He went to the pharmacy and bought $m$ medicines.

For each medicine, the number of days it needs to be taken is known, and the set of symptoms it removes. Unfortunately, medicines often have side effects. Therefore, for each medicine, the set of symptoms that appear when taking it is also known.

After reading the instructions, Rudolf realized that taking more than one medicine at a time is very unhealthy.

Rudolph wants to be healed as soon as possible. Therefore, he asks you to calculate the minimum number of days to remove all symptoms, or to say that it is impossible.

### Input

The first line contains a single integer $t$ $(1 \le t \le 100)$ — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains two integers $n, m$ $(1 \le n \le 10, 1 \le m \le 10^3)$ — the number of symptoms and medicines, respectively.

The second line of each test case contains a string of length $n$ consisting of the characters $0$ and $1$ — the description of Rudolf's symptoms. If the $i$-th character of the string is $1$, Rudolf has the $i$-th symptom, otherwise he does not.

Then follow $3 \cdot m$ lines — the description of the medicines.

The first line of each medicine description contains an integer $d$ $(1 \le d \le 10^3)$ — the number of days the medicine needs to be taken.

The next two lines of the medicine description contain two strings of length $n$, consisting of the characters $0$ and $1$ — the description of the symptoms it removes and the description of the side effects.

In the first of the two lines, $1$ at position $i$ means that the medicine removes the $i$-th symptom, and $0$ otherwise.

In the second of the two lines, $1$ at position $i$ means that the $i$-th symptom appears after taking the medicine, and $0$ otherwise.

Different medicines can have the same sets of symptoms and side effects. If a medicine relieves a certain symptom, it will not be among the side effects.

The sum of $m$ over all test cases does not exceed $10^3$.

### Output

For each test case, output a single integer on a separate line — the minimum number of days it will take Rudolf to remove all symptoms. If this never happens, output $-1$.

## Example

### Input


```text
45 410011310000001103001010000030101000100511010001004 1000010101101002 21121001301102 311301103100041001
```
### Output

```text

8
0
-1
6

```
## Note

In the first example, we can first apply medicine number $4$, after which the symptoms will look like "00101". After that, medicine number $2$, then all symptoms will disappear, and the number of days will be $5 + 3 = 8$. Another option is to apply the medicines in the order $1, 3, 2$. In this case, all symptoms will also disappear, but the number of days will be $3 + 3 + 3 = 9$.

In the second example, there are no symptoms initially, so the treatment will take $0$ days.

In the third example, there are no options to remove all symptoms.



#### Tags 

#1900 #NOT OK #bitmasks #dp #graphs #greedy #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_883_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
