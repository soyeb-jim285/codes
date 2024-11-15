<h1 style='text-align: center;'> E. Verifying Kingdom</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

The judge has a hidden rooted full binary tree with *n* leaves. A full binary tree is one where every node has either 0 or 2 children. The nodes with 0 children are called the leaves of the tree. Since this is a full binary tree, there are exactly 2*n* - 1 nodes in the tree. The leaves of the judge's tree has labels from 1 to *n*. You would like to reconstruct a tree that is isomorphic to the judge's tree. To do this, you can ask some questions.

A question consists of printing the label of three distinct leaves *a*1, *a*2, *a*3. Let the depth of a node be the shortest distance from the node to the root of the tree. Let *LCA*(*a*, *b*) denote the node with maximum depth that is a common ancestor of the nodes *a* and *b*.

Consider *X* = *LCA*(*a*1, *a*2), *Y* = *LCA*(*a*2, *a*3), *Z* = *LCA*(*a*3, *a*1). The judge will tell you which one of *X*, *Y*, *Z* has the maximum depth. ## Note

, this pair is uniquely determined since the tree is a binary tree; there can't be any ties. 

More specifically, if *X* (or *Y*, *Z* respectively) maximizes the depth, the judge will respond with the string "X" (or "Y", "Z" respectively). 

You may only ask at most 10·*n* questions.

## Input

The first line of input will contain a single integer *n* (3 ≤ *n* ≤ 1 000) — the number of leaves in the tree.

## Output

To print the final answer, print out the string "-1" on its own line. Then, the next line should contain 2*n* - 1 integers. The *i*-th integer should be the parent of the *i*-th node, or -1, if it is the root.

Your answer will be judged correct if your output is isomorphic to the judge's tree. In particular, the labels of the leaves do not need to be labeled from 1 to *n*. Here, isomorphic means that there exists a permutation π such that node *i* is the parent of node *j* in the judge tree if and only node π(*i*) is the parent of node π(*j*) in your tree.

## Interaction

To ask a question, print out three distinct integers *a*1, *a*2, *a*3. These integers should be between 1 and *n*, inclusive.

The judge will respond with a single character, either "X", "Y", "Z". 

If the string is "X" (or "Y", "Z" respectively), that means the pair (*a*1, *a*2) (or (*a*2, *a*3), (*a*3, *a*1) respectively) has the deepest *LCA* among the three pairs.

You may only ask a question at most 10·*n* times, otherwise, you will get Wrong Answer.

When you are ready to answer, print out a single integer "-1" on its own line. The next line should contain 2*n* - 1 integers. The *i*-th integer should be the parent of the *i*-th node, or -1, if it is the root. Do not forget to flush the final answer as well. Printing the answer does not count as asking a question.

You will get Wrong Answer verdict if 

* Your question or answers are not in the format described in this statement.
* You ask strictly more than 10·*n* questions.
* Your question contains duplicate indices.
* Your final answer is not isomorphic to the judge tree.

You will get Idleness Limit Exceeded if you don't print anything or if you forget to flush the output, including for the final answer (more info about flushing output below).

To flush you can use (just after printing an integer and end-of-line): 

* fflush(stdout) in C++;
* System.out.flush() in Java;
* stdout.flush() in Python;
* flush(output) in Pascal;
* See the documentation for other languages.

If at any moment your program reads -1 as an answer, it should immediately exit normally (for example, by calling exit(0)). You will get Wrong Answer in this case, it means that you made more queries than allowed, or made an invalid query. If you ignore this, you can get other verdicts since your program will continue to read from a closed stream.

Hacking To hack someone, use the following format 


```
  
n  
p_1 p_2 ... p_{2n-1}  

```
This denotes a tree where the parent of the *i*-th node is *p**i* (*p**i* =  - 1 or *n* < *p**i* ≤ 2*n* - 1). If *p**i* is equal to -1, then node *i* is the root. This input must describe a valid full rooted binary tree.

Of course, contestant programs will not be able to see this input.

## Example

## Input


```
5  
X  
Z  
Y  
Y  
X  

```
## Output


```
1 4 2  
1 2 4  
2 4 1  
2 3 5  
2 4 3  
-1  
-1 1 1 2 2 3 3 6 6  

```
## Note

For the first sample, the judge has the hidden tree:

![](images/2c9cae7de194cc1bc508ea7243ff4d0d509d34bd.png)

Here is a more readable format of the interaction: 

![](images/1cfb86747dfd0278bc848ef24aa3a158e4ce0220.png) The last line can also be 8 6 9 8 9 7 -1 6 7. 

#### tags 

#3200 #binary_search #divide_and_conquer #interactive #trees 