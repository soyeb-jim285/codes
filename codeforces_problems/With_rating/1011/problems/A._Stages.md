<h1 style='text-align: center;'> A. Stages</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Natasha is going to fly to Mars. She needs to build a rocket, which consists of several stages in some order. Each of the stages is defined by a lowercase Latin letter. This way, the rocket can be described by the string — concatenation of letters, which correspond to the stages.

There are $n$ stages available. The rocket must contain exactly $k$ of them. Stages in the rocket should be ordered by their weight. So, after the stage with some letter can go only stage with a letter, which is at least two positions after in the alphabet (skipping one letter in between, or even more). For example, after letter 'c' can't go letters 'a', 'b', 'c' and 'd', but can go letters 'e', 'f', ..., 'z'.

For the rocket to fly as far as possible, its weight should be minimal. The weight of the rocket is equal to the sum of the weights of its stages. The weight of the stage is the number of its letter in the alphabet. For example, the stage 'a 'weighs one ton,' b 'weighs two tons, and' z' — $26$ tons.

Build the rocket with the minimal weight or determine, that it is impossible to build a rocket at all. Each stage can be used at most once.

###### Input

The first line of input contains two integers — $n$ and $k$ ($1 \le k \le n \le 50$) – the number of available stages and the number of stages to use in the rocket.

The second line contains string $s$, which consists of exactly $n$ lowercase Latin letters. Each letter defines a new stage, which can be used to build the rocket. Each stage can be used at most once.

###### Output

Print a single integer — the minimal total weight of the rocket or -1, if it is impossible to build the rocket at all.

## Examples

###### Input


```text
5 3  
xyabd  

```
###### Output


```text
29
```
###### Input


```text
7 4  
problem  

```
###### Output


```text
34
```
###### Input


```text
2 2  
ab  

```
###### Output


```text
-1
```
###### Input


```text
12 1  
abaabbaaabbb  

```
###### Output


```text
1
```
## Note

In the first example, the following rockets satisfy the condition:

* "adx" (weight is $1+4+24=29$);
* "ady" (weight is $1+4+25=30$);
* "bdx" (weight is $2+4+24=30$);
* "bdy" (weight is $2+4+25=31$).

Rocket "adx" has the minimal weight, so the answer is $29$.

In the second example, target rocket is "belo". Its weight is $2+5+12+15=34$.

In the third example, $n=k=2$, so the rocket must have both stages: 'a' and 'b'. This rocket doesn't satisfy the condition, because these letters are adjacent in the alphabet. Answer is -1.



#### Tags 

#900 #NOT OK #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_499_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
