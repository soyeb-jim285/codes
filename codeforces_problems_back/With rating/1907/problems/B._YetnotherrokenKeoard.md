<h1 style='text-align: center;'> B. YetnotherrokenKeoard</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has a problem — his laptop keyboard is broken.

Now, when he presses the 'b' key, it acts like an unusual backspace: it deletes the last (rightmost) lowercase letter in the typed string. If there are no lowercase letters in the typed string, then the press is completely ignored.

Similarly, when he presses the 'B' key, it deletes the last (rightmost) uppercase letter in the typed string. If there are no uppercase letters in the typed string, then the press is completely ignored.

In both cases, the letters 'b' and 'B' are not added to the typed string when these keys are pressed.

Consider an example where the sequence of key presses was "ARaBbbitBaby". In this case, the typed string will change as follows: "" $\xrightarrow{\texttt{A}}$ "A" $\xrightarrow{\texttt{R}}$ "AR" $\xrightarrow{\texttt{a}}$ "ARa" $\xrightarrow{\texttt{B}}$ "Aa" $\xrightarrow{\texttt{b}}$ "A" $\xrightarrow{\texttt{b}}$ "A" $\xrightarrow{\texttt{i}}$ "Ai" $\xrightarrow{\texttt{t}}$ "Ait" $\xrightarrow{\texttt{B}}$ "it" $\xrightarrow{\texttt{a}}$ "ita" $\xrightarrow{\texttt{b}}$ "it" $\xrightarrow{\texttt{y}}$ "ity".

Given a sequence of pressed keys, output the typed string after processing all key presses.

## Input

The first line of the input data contains an integer $t$ ($1 \le t \le 1000$), the number of test cases in the test.

The following contains $t$ non-empty lines, which consist of lowercase and uppercase letters of the Latin alphabet.

It is guaranteed that each line contains at least one letter and the sum of the lengths of the lines does not exceed $10^6$.

## Output

For each test case, output the result of processing the key presses on a separate line. If the typed string is empty, then output an empty line.

## Example

## Input


```

12ARaBbbitBabyYetAnotherBrokenKeyboardBubbleImprobableabbreviableBbBBBusyasaBeeinaBedofBloomingBlossomsCoDEBARbIEScodeforcesbobebobbesbTheBBlackbboard
```
## Output


```

ity
YetnotherrokenKeoard
le
Imprle
revile

usyasaeeinaedofloominglossoms
CDARIES
codeforces
es

helaoard

```


#### tags 

#1000 #data_structures #implementation #strings 