<h1 style='text-align: center;'> B. Security Guard</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is a security guard in Berland State University. Every day, he tracks how many people and at what time enter and leave the university. He writes this information down as follows: 

* when someone enters the university, Monocarp writes a plus sign '+';
* when someone leaves the university, Monocarp writes a minus sign '-'.

At the beginning of the current day, there are no people at the university, except for Monocarp. During the day, Monocarp wrote out a sequence $s$. The characters in $s$ are listed in the order Monocarp wrote them.

Suddenly, Monocarp's boss decided to check his work. Unfortunately, Monocarp is a bit careless. So, the sequence $s$ that he wrote might be impossible. For example, the sequence "+--" can't happen, since it represents a scenario when one person enters the university and two leave.

Before his boss starts checking the sequence, Monocarp has the time to swap at most one pair of characters in it. Can he do it in such a way that the resulting sequence is plausible? Note that if the given sequence is already plausible, Monocarp doesn't have to swap anything.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains a single string $s$ ($1 \le |s| \le 3 \cdot 10^5$), consisting only of characters '+' and/or '-'. A plus sign '+' represents a person entering the university. A minus sign '-' represents a person leaving the university.

The sum of all $|s|$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print an answer.

If it's impossible to swap at most one pair of characters so that the resulting sequence is plausible, print -1.

Otherwise, print two integers. If you swap one pair of characters, print two distinct integers from $1$ to $n$ — the indices of characters to swap. If you don't swap, print one integer from $1$ to $n$ twice — swap a character with itself.

If there are multiple answers, print any of them.

## Example

### Input


```text
6-++-+++----+++-
```
### Output

```text

1 2
1 1
1 1
-1
1 1
-1

```


#### Tags 

#1600 #NOT OK #*special #greedy 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_9_(Unrated,_T-Shirts_+_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
