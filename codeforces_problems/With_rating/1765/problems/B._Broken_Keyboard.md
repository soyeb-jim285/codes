<h1 style='text-align: center;'> B. Broken Keyboard</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Recently, Mishka started noticing that his keyboard malfunctions — maybe it's because he was playing rhythm games too much. Empirically, Mishka has found out that every other time he presses a key, it is registered as if the key was pressed twice. For example, if Mishka types text, the first time he presses a key, exactly one letter is printed; the second time he presses a key, two same letters are printed; the third time he presses a key, one letter is printed; the fourth time he presses a key, two same letters are printed, and so on. 
## Note

 that the number of times a key was pressed is counted for the whole keyboard, not for each key separately. For example, if Mishka tries to type the word osu, it will be printed on the screen as ossu.

You are given a word consisting of $n$ lowercase Latin letters. You have to determine if it can be printed on Mishka's keyboard or not. You may assume that Mishka cannot delete letters from the word, and every time he presses a key, the new letter (or letters) is appended to the end of the word.

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of the test case contains one integer $n$ ($1 \le n \le 100$) — the length of the word.

The second line of the test case contains a string $s$ consisting of $n$ lowercase Latin letters — the word that should be checked.

### Output

For each test case, print YES if the word $s$ can be printed on Mishka's keyboard, and NO otherwise.

## Example

### Input


```text
44ossu2aa6addonn3qwe
```
### Output

```text

YES
NO
YES
NO

```
## Note

In the first test case, Mishka can type the word as follows: press o (one letter o appears at the end of the word), then presses s (two letters s appear at the end of the word), and, finally, press u (one letter appears at the end of the word, making the resulting word ossu).

In the second test case, Mishka can try typing the word as follows: press a (one letter a appears at the end of the word). But if he tries to press a one more time, two letters a will appear at the end of the word, so it is impossible to print the word using his keyboard.

In the fourth test case, Mishka has to start by pressing q. Then, if he presses w, two copies of w will appear at the end of the word, but the third letter should be e instead of w, so the answer is NO.



#### Tags 

#800 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../2022-2023_ICPC,_NERC,_Southern_and_Volga_Russian_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Preferably_Teams).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
