<h1 style='text-align: center;'> D. Deletive Editing</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Daisy loves playing games with words. Recently, she has been playing the following Deletive Editing word game with Daniel. 

Daisy picks a word, for example, "DETERMINED". On each game turn, Daniel calls out a letter, for example, 'E', and Daisy removes the first occurrence of this letter from the word, getting "DTERMINED". On the next turn, Daniel calls out a letter again, for example, 'D', and Daisy removes its first occurrence, getting "TERMINED". They continue with 'I', getting "TERMNED", with 'N', getting "TERMED", and with 'D', getting "TERME". Now, if Daniel calls out the letter 'E', Daisy gets "TRME", but there is no way she can get the word "TERM" if they start playing with the word "DETERMINED".

Daisy is curious if she can get the final word of her choice, starting from the given initial word, by playing this game for zero or more turns. Your task it help her to figure this out.

### Input

The first line of the input contains an integer $n$ — the number of test cases ($1 \le n \le 10\,000$). The following $n$ lines contain test cases. 

Each test case consists of two words $s$ and $t$ separated by a space. Each word consists of at least one and at most 30 uppercase English letters; $s$ is the Daisy's initial word for the game; $t$ is the final word that Daisy would like to get at the end of the game.

### Output

### Output

 $n$ lines to the output — a single line for each test case. 
### Output

 "YES" if it is possible for Daisy to get from the initial word $s$ to the final word $t$ by playing the Deletive Editing game. 
### Output

 "NO" otherwise.

## Example

### Input


```text
6DETERMINED TRMEDETERMINED TERMPSEUDOPSEUDOHYPOPARATHYROIDISM PEPADEINSTITUTIONALIZATION DONATIONCONTEST CODESOLUTION SOLUTION
```
### Output

```text

YES
NO
NO
YES
NO
YES

```


#### Tags 

#900 #NOT OK #greedy 

## Blogs
- [All Contest Problems](../2021-2022_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement #2 (en)](../blogs/Announcement_2_(en).md)
