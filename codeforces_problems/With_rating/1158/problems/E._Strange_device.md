<h1 style='text-align: center;'> E. Strange device</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It is an interactive problem.

Vasya enjoys solving quizzes. He found a strange device and wants to know how it works.

This device encrypted with the tree (connected undirected graph without cycles) with $n$ vertices, numbered with integers from $1$ to $n$. To solve this quiz you should guess this tree.

Fortunately, this device can make one operation, using which you should guess the cipher. You can give the device an array $d_1, d_2, \ldots, d_n$ of non-negative integers. On the device, there are $n$ lamps, $i$-th of them is connected with $i$-th vertex of the tree. For all $i$ the light will turn on the $i$-th lamp, if there exist such vertex of the tree with number $j \neq i$ that $dist(i, j) \leq d_j$. Let's define $dist(i, j)$ as the distance between vertices $i$ and $j$ in tree or number of edges on the simple path between vertices $i$ and $j$.

Vasya wants to solve this quiz using $\leq 80$ operations with the device and guess the tree. Help him! 

## Interaction

In the beginning, your program should read one integer $n$ — the number of vertices of the tree which encrypts the device ($2 \leq n \leq 1000$).

After that, you can make several operations in the following format. To do operation print a symbol"?" (without quotes) and $n$ integers $d_1, d_2, \ldots, d_n$, separated by spaces after it. Please note, that for all $i$ you can only use the numbers, satisfying the inequality $0 \leq d_i < n$. After that, you should read a string $s$ with length $n$, consisting of symbols "0" and "1" (without quotes). For all $i$ the symbol $s_i$ is equal to "0", if the lamp on the device, connected with $i$-th vertex of the tree is switched off and "1" otherwise.

After several operations, you should print guessed tree. To do it print the only symbol "!" (without quotes). In the next $n-1$ lines print $2$ integers $a_i$, $b_i$ — indexes of the vertices connected by $i$-th edge of the tree. This numbers should satisfy the conditions $1 \leq a_i, b_i \leq n$ and $a_i \neq b_i$. This edges should form a tree, which is equal to the hidden tree. After that, your program should terminate.

It is guaranteed, that in each test the tree is fixed before and won't change depending on your program's operations.

Your program can make from $0$ to $80$ operations with the device and after that guess the tree equal with the hidden.

If your program will make more than $80$ operations it can get any verdict, because it will continue reading from closed input. If your program will make operation or print the answer in the incorrect format, it can get any verdict too. Be careful.

Don't forget to flush the output after printing questions and answers.

To flush the output, you can use: 

* fflush(stdout) in C++.
* System.out.flush() in Java.
* stdout.flush() in Python.
* flush(output) in Pascal.
* See the documentation for other languages.

Hacks:

The first line should contain one integer $n$ — the number of vertices in the tree ($2 \leq n \leq 1000$). Next $n-1$ lines should contain $2$ integers $a_i$, $b_i$ — indexes of the vertices connected by $i$-th edge of the tree ($1 \leq a_i, b_i \leq n$, $a_i \neq b_i$). All edges should form a tree. Be careful, extra spaces or line breaks are not allowed.

## Example

#Input
```text
5
00000
11011
11100
10010
```
#Output
```text
? 0 0 0 0 0
? 1 1 2 0 2
? 0 0 0 1 0
? 0 1 0 0 1
!
4 2
1 5
3 4
4 1
```
## Note

It is a picture of the tree which encrypt the device from the first test:

 ![](images/1dc4531527b158b99b5e3d06c9fa3256a0a87bca.png) It is a table of pairwise distances between vertices in this tree:

 ![](images/83592cfb57350593c1207cd472a798b19b01b48a.png) * If you make operation where $d = [0, 0, 0, 0, 0]$, no lamp will switch on, because $dist(i, j) > 0$ for all $i \neq j$.
* If you make operation where $d = [1, 1, 2, 0, 2]$, all lamps except the lamp connected with the $3$-rd vertex will switch on. For example, lamp connected with the $1$-st vertex will switch on, because $dist(1, 5) = 1 \leq 2 = d_5$.
* If you make operation where $d = [0, 0, 0, 1, 0]$, all lamps except lamps connected with the $4$-th and $5$-th vertices will switch on.
* If you make operation where $d = [0, 1, 0, 0, 1]$, only lamps connected with the $1$-st and $4$-th vertices will switch on.


#### Tags 

#3400 #NOT OK #binary_search #interactive #math #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_559_(Div._1).md)
- [Codeforces Round #559](../blogs/Codeforces_Round_559.md)
- [Tutorial (en) (en)](../blogs/Tutorial_(en)_(en).md)
- [Tutorial #2 (ru)](../blogs/Tutorial_2_(ru).md)
