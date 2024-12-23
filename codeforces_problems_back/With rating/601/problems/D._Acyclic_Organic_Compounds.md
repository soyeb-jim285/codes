<h1 style='text-align: center;'> D. Acyclic Organic Compounds</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a tree *T* with *n* vertices (numbered 1 through *n*) and a letter in each vertex. The tree is rooted at vertex 1.

Let's look at the subtree *T**v* of some vertex *v*. It is possible to read a string along each simple path starting at *v* and ending at some vertex in *T**v* (possibly *v* itself). Let's denote the number of distinct strings which can be read this way as ![](images/bd208c8f291ac26d2c1afe01926632d52a3b9c7f.png). 

Also, there's a number *c**v* assigned to each vertex *v*. We are interested in vertices with the maximum value of ![](images/f502ea3f6cf16bce416fd43b9c9bb79980ffa382.png).

You should compute two statistics: the maximum value of ![](images/f502ea3f6cf16bce416fd43b9c9bb79980ffa382.png) and the number of vertices *v* with the maximum ![](images/f502ea3f6cf16bce416fd43b9c9bb79980ffa382.png).

## Input

The first line of the input contains one integer *n* (1 ≤ *n* ≤ 300 000) — the number of vertices of the tree.

The second line contains *n* space-separated integers *c**i* (0 ≤ *c**i* ≤ 109).

The third line contains a string *s* consisting of *n* lowercase English letters — the *i*-th character of this string is the letter in vertex *i*.

The following *n* - 1 lines describe the tree *T*. Each of them contains two space-separated integers *u* and *v* (1 ≤ *u*, *v* ≤ *n*) indicating an edge between vertices *u* and *v*.

It's guaranteed that the input will describe a tree.

## Output

Print two lines. 

On the first line, print ![](images/1ca61e8ad8b32ae7f5adbad10109a51bd42f3ab4.png) over all 1 ≤ *i* ≤ *n*. 

On the second line, print the number of vertices *v* for which ![](images/6604043b6c7f1f01412e02c2d1b462b73786da81.png).

## Examples

## Input


```
10  
1 2 7 20 20 30 40 50 50 50  
cacabbcddd  
1 2  
6 8  
7 2  
6 2  
5 4  
5 9  
3 10  
2 5  
2 3  

```
## Output


```
51  
3  

```
## Input


```
6  
0 2 4 1 1 1  
raaaba  
1 2  
2 3  
2 4  
2 5  
3 6  

```
## Output


```
6  
2  

```
## Note

In the first sample, the tree looks like this:

 ![](images/e73c5960bdba5494ac0d005fdbeceb58e8011859.png) The sets of strings that can be read from individual vertices are:

 ![](images/cdd20e7ec866e6f991ca2f90e08792408c889db7.png) Finally, the values of ![](images/14691bbbb07694ceb84c7c73aa24a29ecfcb9e6b.png) are:

 ![](images/984bc948f68a2c35f75db857f62c005dcf9206d7.png) In the second sample, the values of ![](images/58314b06b4c754bc3d1eeee1a5f0140ed5645015.png) are (5, 4, 2, 1, 1, 1). The distinct strings read in *T*2 are ![](images/072d38bb85cddb83248af087aadc065527254da5.png); note that ![](images/439f442d1a281ff76510cd09766962dff9fdbd65.png) can be read down to vertices 3 or 4.



#### tags 

#2400 #data_structures #dfs_and_similar #dsu #hashing #strings #trees 