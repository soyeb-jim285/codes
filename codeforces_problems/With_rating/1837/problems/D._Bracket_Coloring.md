<h1 style='text-align: center;'> D. Bracket Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example:

* the bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
* the bracket sequences ")(", "(" and ")" are not.

A bracket sequence is called beautiful if one of the following conditions is satisfied:

* it is a regular bracket sequence;
* if the order of the characters in this sequence is reversed, it becomes a regular bracket sequence.

For example, the bracket sequences "()()", "(())", ")))(((", "))()((" are beautiful.

You are given a bracket sequence $s$. You have to color it in such a way that:

* every bracket is colored into one color;
* for every color, there is at least one bracket colored into that color;
* for every color, if you write down the sequence of brackets having that color in the order they appear, you will get a beautiful bracket sequence.

Color the given bracket sequence $s$ into the minimum number of colors according to these constraints, or report that it is impossible.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of characters in $s$. The second line contains $s$ — a string of $n$ characters, where each character is either "(" or ")".

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, print the answer as follows:

* if it is impossible to color the brackets according to the problem statement, print $-1$;
* otherwise, print two lines. In the first line, print one integer $k$ ($1 \le k \le n$) — the minimum number of colors. In the second line, print $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le k$), where $c_i$ is the color of the $i$-th bracket. If there are multiple answers, print any of them.
## Example

### Input


```text
48((())))(4(())4))((3(()
```
### Output

```text

2
2 2 2 1 2 2 2 1
1
1 1 1 1
1
1 1 1 1
-1

```


#### Tags 

#1400 #NOT OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_149_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
