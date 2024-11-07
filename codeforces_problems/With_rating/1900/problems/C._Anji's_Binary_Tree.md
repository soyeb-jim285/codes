<h1 style='text-align: center;'> C. Anji's Binary Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Keksic keeps getting left on seen by Anji. Through a mutual friend, he's figured out that Anji really likes binary trees and decided to solve her problem in order to get her attention.

Anji has given Keksic a binary tree with $n$ vertices. Vertex $1$ is the root and does not have a parent. All other vertices have exactly one parent. Each vertex can have up to $2$ children, a left child, and a right child. For each vertex, Anji tells Keksic index of both its left and its right child or tells him that they do not exist. 

Additionally, each of the vertices has a letter $s_i$ on it, which is either 'U', 'L' or 'R'.

Keksic begins his journey on the root, and in each move he does the following: 

* If the letter on his current vertex is 'U', he moves to its parent. If it doesn't exist, he does nothing.
* If the letter on his current vertex is 'L', he moves to its left child. If it doesn't exist, he does nothing.
* If the letter on his current vertex is 'R', he moves to its right child. If it doesn't exist, he does nothing.

 Before his journey, he can perform the following operations: choose any node, and replace the letter written on it with another one. You are interested in the minimal number of operations he needs to do before his journey, such that when he starts his journey, he will reach a leaf at some point. A leaf is a vertex that has no children. It does not matter which leaf he reaches. 
## Note

 that it does not matter whether he will stay in the leaf, he just needs to move to it. Additionally, note that it does not matter how many times he needs to move before reaching a leaf.

Help Keksic solve Anji's tree so that he can win her heart, and make her come to Čačak.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 5 \cdot 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 3 \cdot 10^5$) — the number of vertices in a tree.

The second line of each test case contains a string $s$ of $n$ characters — characters are written on the vertices. It is guaranteed that $s$ consists only of characters 'U', 'L', and 'R'.

The $i$-th of the next $n$ lines contains two integers $l_i$ and $r_i$ ($0 \le l_i, r_i \le n$) — indices of left and right child of the vertex $i$. If $l_i = 0$, it means that vertex $i$ does not have a left child. If $r_i = 0$, it means that vertex $i$ does not have a right child. It is guaranteed that this data describes a valid binary tree rooted at $1$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, output a single integer — the minimal number of operations Keksic needs to do to reach a leaf.

## Example

### Input


```text
53LRU2 30 00 03ULR3 20 00 02LU0 20 04RULR3 00 00 42 07LLRRRLU5 23 60 07 04 00 00 0
```
### Output

```text

0
1
1
3
1

```
## Note

In the first test case, vertex $1$ has $2$ as its left child and $3$ as its right child. Vertices $2$ and $3$ do not have children and are therefore leaves. As 'L' is written on vertex $1$, Keksic will go to vertex $2$, therefore he has to do no operations.

In the second test case, vertex $1$ has $3$ as its left child and $2$ as its right child. Vertices $2$ and $3$ are leaves. As 'U' is written on vertex $1$, Keksic needs to change it to either 'L' or 'R' in order for him to reach a leaf.

In the third case, vertex $1$ has only a right child, which is vertex $2$. As 'L' is written on it, Keksic needs to change it to 'R', otherwise he would be stuck on vertex $1$.

In the fourth case, he can change $3$ characters so that letters on the vertices are "LURL", which makes him reach vertex $2$.

In the fifth case, there are $3$ leaves, $3$, $6$ and $7$. To reach either leaf $6$ or leaf $7$, he needs to change $2$ characters. However, if he changes character on vertex $1$ to 'R', he will reach leaf $3$, therefore the answer is $1$.

 ![](images/1e67bb5647fb5e25676addfa3412a2a9c8b1a705.png) The initial tree in test case 5. 

#### Tags 

#1300 #NOT OK #dfs_and_similar #dp #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_911_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
