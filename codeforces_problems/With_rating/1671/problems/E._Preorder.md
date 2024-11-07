<h1 style='text-align: center;'> E. Preorder</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a rooted tree of $2^n - 1$ vertices. Every vertex of this tree has either $0$ children, or $2$ children. All leaves of this tree have the same distance from the root, and for every non-leaf vertex, one of its children is the left one, and the other child is the right one. Formally, you are given a perfect binary tree.

The vertices of the tree are numbered in the following order:

* the root has index $1$;
* if a vertex has index $x$, then its left child has index $2x$, and its right child has index $2x+1$.

Every vertex of the tree has a letter written on it, either A or B. Let's define the character on the vertex $x$ as $s_x$.

Let the preorder string of some vertex $x$ be defined in the following way:

* if the vertex $x$ is a leaf, then the preorder string of $x$ be consisting of only one character $s_x$;
* otherwise, the preorder string of $x$ is $s_x + f(l_x) + f(r_x)$, where $+$ operator defines concatenation of strings, $f(l_x)$ is the preorder string of the left child of $x$, and $f(r_x)$ is the preorder string of the right child of $x$.

The preorder string of the tree is the preorder string of its root.

Now, for the problem itself...

You have to calculate the number of different strings that can be obtained as the preorder string of the given tree, if you are allowed to perform the following operation any number of times before constructing the preorder string of the tree:

* choose any non-leaf vertex $x$, and swap its children (so, the left child becomes the right one, and vice versa).
####### Input

The first line contains one integer $n$ ($2 \le n \le 18$).

The second line contains a sequence of $2^n-1$ characters $s_1, s_2, \dots, s_{2^n-1}$. Each character is either A or B. The characters are not separated by spaces or anything else.

####### Output

Print one integer — the number of different strings that can be obtained as the preorder string of the given tree, if you can apply any number of operations described in the statement. Since it can be very large, print it modulo $998244353$.

## Examples

####### Input


```text
4
BAAAAAAAABBABAB
```
####### Output


```text
16
```
####### Input


```text
2
BAA
```
####### Output


```text
1
```
####### Input


```text
2
ABA
```
####### Output


```text
2
```
####### Input


```text
2
AAB
```
####### Output


```text
2
```
####### Input


```text
2
AAA
```
####### Output


```text
1
```


#### Tags 

#2100 #NOT OK #combinatorics #divide_and_conquer #dp #dsu #hashing #sortings #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_127_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
