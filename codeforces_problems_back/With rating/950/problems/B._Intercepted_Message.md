<h1 style='text-align: center;'> B. Intercepted Message</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Hacker Zhorik wants to decipher two secret messages he intercepted yesterday. Yeah message is a sequence of encrypted blocks, each of them consists of several bytes of information.

Zhorik knows that each of the messages is an archive containing one or more files. Zhorik knows how each of these archives was transferred through the network: if an archive consists of *k* files of sizes *l*1, *l*2, ..., *l**k* bytes, then the *i*-th file is split to one or more blocks *b**i*, 1, *b**i*, 2, ..., *b**i*, *m**i* (here the total length of the blocks *b**i*, 1 + *b**i*, 2 + ... + *b**i*, *m**i* is equal to the length of the file *l**i*), and after that all blocks are transferred through the network, maintaining the order of files in the archive.

Zhorik thinks that the two messages contain the same archive, because their total lengths are equal. However, each file can be split in blocks in different ways in the two messages.

You are given the lengths of blocks in each of the two messages. Help Zhorik to determine what is the maximum number of files could be in the archive, if the Zhorik's assumption is correct.

## Input

The first line contains two integers *n*, *m* (1 ≤ *n*, *m* ≤ 105) — the number of blocks in the first and in the second messages.

The second line contains *n* integers *x*1, *x*2, ..., *x**n* (1 ≤ *x**i* ≤ 106) — the length of the blocks that form the first message.

The third line contains *m* integers *y*1, *y*2, ..., *y**m* (1 ≤ *y**i* ≤ 106) — the length of the blocks that form the second message.

It is guaranteed that *x*1 + ... + *x**n* = *y*1 + ... + *y**m*. Also, it is guaranteed that *x*1 + ... + *x**n* ≤ 106.

## Output

Print the maximum number of files the intercepted array could consist of.

## Examples

## Input


```
7 6  
2 5 3 1 11 4 4  
7 8 2 4 1 8  

```
## Output


```
3  

```
## Input


```
3 3  
1 10 100  
1 100 10  

```
## Output


```
2  

```
## Input


```
1 4  
4  
1 1 1 1  

```
## Output


```
1  

```
## Note

In the first example the maximum number of files in the archive is 3. For example, it is possible that in the archive are three files of sizes 2 + 5 = 7, 15 = 3 + 1 + 11 = 8 + 2 + 4 + 1 and 4 + 4 = 8.

In the second example it is possible that the archive contains two files of sizes 1 and 110 = 10 + 100 = 100 + 10. ## Note

 that the order of files is kept while transferring archives through the network, so we can't say that there are three files of sizes 1, 10 and 100.

In the third example the only possibility is that the archive contains a single file of size 4.



#### tags 

#1100 #greedy #implementation 