<h1 style='text-align: center;'> D. Slavic's Exam</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Slavic has a very tough exam and needs your help in order to pass it. Here is the question he is struggling with:

There exists a string $s$, which consists of lowercase English letters and possibly zero or more "?".

Slavic is asked to change each "?" to a lowercase English letter such that string $t$ becomes a subsequence (not necessarily continuous) of the string $s$.

### Output

any such string, or say that it is impossible in case no string that respects the conditions exists.

### Input

The first line contains a single integer $T$ ($1 \leq T \leq 10^4$) — the number of test cases.

The first line of each test case contains a single string $s$ ($1 \leq |s| \leq 2 \cdot 10^5$, and $s$ consists only of lowercase English letters and "?"-s)  – the original string you have.

The second line of each test case contains a single string $t$ ($1 \leq |t| \leq |s|$, and $t$ consists only of lowercase English letters)  – the string that should be a subsequence of string $s$.

The sum of $|s|$ over all test cases doesn't exceed $2 \cdot 10^5$, where $|x|$ denotes the length of the string $x$.

### Output

For each test case, if no such string exists as described in the statement, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string that respects all conditions.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.

## Example

### Input

```text
5?????xbxab??eabcdeayy?xaab??edacpaiumom
```

### Output

```text

YES
xabax
YES
abcde
YES
ayyyx
NO
NO

```

#### Tags

#NOT OK #greedy #implementation #strings

## Blogs

- [All Contest Problems](<../Codeforces_Round_964_(Div._4).md>)
- [Announcement (en)](<../blogs/Announcement_(en).md>)
- [Video Tutorial (en)](<../blogs/Video_Tutorial_(en).md>)
- [Tutorial #2 (en)](<../blogs/Tutorial_2_(en).md>)
