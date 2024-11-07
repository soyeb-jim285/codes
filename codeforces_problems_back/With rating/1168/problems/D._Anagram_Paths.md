<h1 style='text-align: center;'> D. Anagram Paths</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Toad Ilya has a rooted binary tree with vertex $1$ being the root. A tree is a connected graph without cycles. A tree is rooted if one vertex is selected and called the root. A vertex $u$ is a child of a vertex $v$ if $u$ and $v$ are connected by an edge and $v$ is closer to the root than $u$. A leaf is a non-root vertex that has no children.

In the tree Ilya has each vertex has at most two children, and each edge has some character written on it. The character can be a lowercase English letter or the question mark '?'.

Ilya will $q$ times update the tree a bit. Each update will replace exactly one character on some edge. After each update Ilya needs to find if the tree is anagrammable and if yes, find its anagramnity for each letter. Well, that's difficult to explain, but we'll try.

To start with, a string $a$ is an anagram of a string $b$ if it is possible to rearrange letters in $a$ (without changing the letters itself) so that it becomes $b$. For example, the string "fortyfive" is an anagram of the string "overfifty", but the string "aabb" is not an anagram of the string "bbba".

Consider a path from the root of the tree to a leaf. The characters on the edges on this path form a string, we say that this string is associated with this leaf. The tree is anagrammable if and only if it is possible to replace each question mark with a lowercase English letter so that for all pair of leaves the associated strings for these leaves are anagrams of each other.

If the tree is anagrammable, then its anagramnity for the letter $c$ is the maximum possible number of letters $c$ in a string associated with some leaf in a valid replacement of all question marks.

Please after each update find if the tree is anagrammable and if yes, find the $\sum{f(c) \cdot ind(c)}$ for all letters $c$, where $f(c)$ is the anagramnity for the letter $c$, and $ind(x)$ is the index of this letter in the alphabet ($ind($"a"$) = 1$, $ind($"b"$) = 2$, ..., $ind($"z"$) = 26$).

## Input

The first line of input contains two integers $n$ and $q$ ($2 \leq n \leq 150\,000$, $1 \leq q \leq 150\,000$) — the number of vertices in the tree and the number of queries.

The next $n-1$ lines describe the initial tree. The $i$-th of them contains an integer $p_i$ and a character $c_i$ ($1 \leq p_i \leq i$, $c_i$ is a lowercase English letter or the question mark '?') describing an edge between vertices $p_i$ and $i+1$ with character $c_i$ written on it.

The root of this tree is the vertex $1$, and each vertex has at most two children.

The next $q$ lines describe the queries. The $i$-th of them contains two integers $v$ and $c$ ($2 \leq v \leq n$, $c$ is a lowercase English letter or the question mark '?'), meaning that updated character on the edge between $p_{v-1}$ to $v$ is $c$. The updated character can be the same as was written before.

## Output

## Output

 $q$ lines. In the $i$-th of them print "Fou" if the tree is not anagrammable after the first $i$ updates.

Otherwise output "Shi" and the $\sum{f(c) \cdot ind(c)}$ for all letters $c$.

## Examples

## Input


```

3 4
1 ?
1 ?
2 ?
2 a
3 b
2 b

```
## Output


```

Shi 351
Shi 1
Fou
Shi 2

```
## Input


```

5 2
1 ?
1 ?
2 ?
3 ?
4 a
5 b

```
## Output


```

Shi 352
Shi 3

```
## Note

In the first example after the first query, for each character, you can set all edges equal to that character, and you will get $1$ such character on each path, so the answer is $1 \cdot (1+2+\ldots+26) = 351$.

In the first example after the second query, you know that all paths should be an anagram of "a", so all paths should be "a", so the answer is $1 \cdot 1 = 1$.

In the first example after the third query, you have two paths with strings "a" and "b", but these strings are not anagrams, so the answer is "Fou".

In the first example after the fourth query, you know that all paths should be "b", so the answer is $1 \cdot 2 = 2$.

In the second example after the first query, you know that $f($'a'$) = 2$ and $f(c) = 1$ for all other characters, so the answer is $1 \cdot (2 + 3 + \ldots + 26) + 2 = 352$.

In the second example after the second query, you know that each path should contain one 'a' and one 'b', so the answer is $1 \cdot 1 + 1 \cdot 2 = 3$.



#### tags 

#3000 #dp #implementation #trees 