<h1 style='text-align: center;'> E. notepad.exe</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There are $n$ words in a text editor. The $i$-th word has length $l_i$ ($1 \leq l_i \leq 2000$). The array $l$ is hidden and only known by the grader. 

The text editor displays words in lines, splitting each two words in a line with at least one space. 
## Note

 that a line does not have to end with a space. Let the height of the text editor refer to the number of lines used. For the given width, the text editor will display words in such a way that the height is minimized.

More formally, suppose that the text editor has width $w$. Let $a$ be an array of length $k+1$ where $1=a_1 < a_2 < \ldots < a_{k+1}=n+1$. $a$ is a valid array if for all $1 \leq i \leq k$, $l_{a_i}+1+l_{a_i+1}+1+\ldots+1+l_{a_{i+1}-1} \leq w$. Then the height of the text editor is the minimum $k$ over all valid arrays.

## Note

 that if $w < \max(l_i)$, the text editor cannot display all the words properly and will crash, and the height of the text editor will be $0$ instead.

You can ask $n+30$ queries. In one query, you provide a width $w$. Then, the grader will return the height $h_w$ of the text editor when its width is $w$.

Find the minimum area of the text editor, which is the minimum value of $w \cdot h_w$ over all $w$ for which $h_w \neq 0$.

The lengths are fixed in advance. In other words, the interactor is not adaptive.

### Input

The first and only line of input contains a single integer $n$ ($1 \leq n \leq 2000$)  — the number of words on the text editor.

It is guaranteed that the hidden lengths $l_i$ satisfy $1 \leq l_i \leq 2000$.

## Interaction

Begin the interaction by reading $n$.

To make a query, print "? $w$" (without quotes, $1 \leq w \leq 10^9$). Then you should read our response from standard input, that is, $h_w$.

If your program has made an invalid query or has run out of tries, the interactor will terminate immediately and your program will get a verdict Wrong answer. 

To give the final answer, print "! $area$" (without the quotes). 
## Note

 that giving this answer is not counted towards the limit of $n+30$ queries.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

 Hacks

The first line of input must contain a single integer $n$ ($1 \leq n \leq 2000$) — the number of words in the text editor.

The second line of input must contain exactly $n$ space-separated integers $l_1,l_2,\ldots,l_n$ ($1 \leq l_i \leq 2000$).

## Example

### Input


```text
6

0

4

2

```
#Output
```text

? 1

? 9

? 16

! 32
```
## Note

In the first test case, the words are $\{\texttt{glory},\texttt{to},\texttt{ukraine},\texttt{and},\texttt{anton},\texttt{trygub}\}$, so $l=\{5,2,7,3,5,6\}$. 

If $w=1$, then the text editor is not able to display all words properly and will crash. The height of the text editor is $h_1=0$, so the grader will return $0$.

If $w=9$, then a possible way that the words will be displayed on the text editor is: 

* $\texttt{glory__to}$
* $\texttt{ukraine__}$
* $\texttt{and_anton}$
* $\texttt{__trygub_}$

The height of the text editor is $h_{9}=4$, so the grader will return $4$.

If $w=16$, then a possible way that the words will be displayed on the text editor is: 

* $\texttt{glory_to_ukraine}$
* $\texttt{and_anton_trygub}$

The height of the text editor is $h_{16}=2$, so the grader will return $2$.

We have somehow figured out that the minimum area of the text editor is $32$, so we answer it.



#### Tags 

#2200 #NOT OK #binary_search #constructive_algorithms #greedy #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_20.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
