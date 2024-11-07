<h1 style='text-align: center;'> F. Family Photos</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bonnie are sisters, but they don't like each other very much. So when some old family photos were found in the attic, they started to argue about who should receive which photos. In the end, they decided that they would take turns picking photos. Alice goes first.

There are *n* stacks of photos. Each stack contains exactly two photos. In each turn, a player may take only a photo from the top of one of the stacks.

Each photo is described by two non-negative integers *a* and *b*, indicating that it is worth *a* units of happiness to Alice and *b* units of happiness to Bonnie. Values of *a* and *b* might differ for different photos.

It's allowed to pass instead of taking a photo. The game ends when all photos are taken or both players pass consecutively.

The players don't act to maximize their own happiness. Instead, each player acts to maximize the amount by which her happiness exceeds her sister's. Assuming both players play optimal, find the difference between Alice's and Bonnie's happiness. That is, if there's a perfectly-played game such that Alice has *x* happiness and Bonnie has *y* happiness at the end, you should print *x* - *y*.

## Input

The first line of input contains a single integer *n* (1 ≤ *n* ≤ 100 000) — the number of two-photo stacks. Then follow *n* lines, each describing one of the stacks. A stack is described by four space-separated non-negative integers *a*1, *b*1, *a*2 and *b*2, each not exceeding 109. *a*1 and *b*1 describe the top photo in the stack, while *a*2 and *b*2 describe the bottom photo in the stack.

## Output

## Output

 a single integer: the difference between Alice's and Bonnie's happiness if both play optimally.

## Examples

## Input


```
2  
12 3 4 7  
1 15 9 1  

```
## Output


```
1  

```
## Input


```
2  
5 4 8 8  
4 12 14 0  

```
## Output


```
4  

```
## Input


```
1  
0 10 0 10  

```
## Output


```
-10  

```


#### tags 

#2900 #games #greedy 