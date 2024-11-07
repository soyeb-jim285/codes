<h1 style='text-align: center;'> D. Decoding of Integer Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp is developing a method for transmitting $n$ integer sequences over a network. This method should support the transmission of an arbitrary number of integer sequences; sequences can have different lengths. The sequences contain arbitrary non-negative integers.

Polycarp developed the following encoding procedure:

* We assume that the sequences are numbered from $1$ to $n$.
* We add a special terminating marker to each sequence at the end, an element equal to -1.
* The encoding result is a new single sequence that contains all the elements of the specified $n$ in a special order: first, add to the result of coding all the first elements of the sequences (in the order from the $1$-st to the $n$-th), then all the second elements (in the order from the $1$-st to the $n$-th) and so on, if the sequence does not have the corresponding element, then it is simply skipped. The process ends when all elements of all sequences are added.

For example, if you want to encode three sequences $[3, 1, 4]$, $[2, 7]$ and $[1, 2, 3, 4]$, then the sequence of actions will be as follows:

* we modify all three sequences by appending -1: $[3, 1, 4, -1]$, $[2, 7, -1]$ and $[1, 2, 3, 4, -1]$;
* we write out all the first elements, we get $[3, 2, 1]$;
* then write down all the second elements, we get $[3, 2, 1, 1, 7, 2]$;
* then write down all the third elements, we get $[3, 2, 1, 1, 7, 2, 4, -1, 3]$;
* then write down all fourth elements, get $[3, 2, 1, 1, 7, 2, 4, -1, 3, -1, 4]$ (note that the second sequence has already ended);
* then write down all the fifth elements, we get $[3, 2, 1, 1, 7, 2, 4, -1, 3, -1, 4, -1]$ (note that the first and second sequences have already ended);
* all the sequences are ended now, and the encoding process is finished;
* the encoding result is: $[3, 2, 1, 1, 7, 2, 4, -1, 3, -1, 4, -1]$.

Your task is to implement decoding by a given encoding result.

#### Input

The first line contains integer number $m$ ($1 \le m \le 3\cdot10^5$), denoting the length of the encoding result. The second line contains the result of encoding as a sequence of integers $b_1, b_2, \dots, b_m$ ($-1 \le b_i \le 100$).

It is guaranteed that in the initial sequences before encoding contains only non-negative integers from $0$ to $100$, that you are in fact given the result of correct encoding (in other words, it is guaranteed that the answer exists). It is possible that one or more initial sequences were empty before encoding.

#### Output

Print $n$, where $n$ is the number of encoded sequences. Then print $n$ lines in the format $k_i, a_{i1}, a_{i2}, \dots, a_{ik_i}$, where $k_i$ is the length of the $i$-th sequence, and $a_{i1}, a_{i2}, \dots, a_{ik_i}$ are its elements. Separate the numbers in the lines with spaces. Please note that the encoding procedure is such that every possible encoding result can be decoded in only one way.

## Examples

#### Input


```text
12
3 2 1 1 7 2 4 -1 3 -1 4 -1
```
#### Output


```text
3
3 3 1 4
2 2 7
4 1 2 3 4
```
#### Input


```text
6
2 -1 2 -1 3 -1
```
#### Output


```text
3
1 2
0
2 2 3
```


#### Tags 

#NOT OK #*special #data_structures #implementation 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_1.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Kotlin Heroes Editorial (en)](../blogs/Kotlin_Heroes_Editorial_(en).md)
