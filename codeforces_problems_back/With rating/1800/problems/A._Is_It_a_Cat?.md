<h1 style='text-align: center;'> A. Is It a Cat?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You were walking down the street and heard a sound. The sound was described by the string $s$ consisting of lowercase and uppercase Latin characters. Now you want to find out if the sound was a cat meowing.

For the sound to be a meowing, the string can only contain the letters 'm', 'e', 'o' and 'w', in either uppercase or lowercase. Also: 

* string must start with non-empty sequence consisting only of characters 'm' or 'M'
* it must be immediately followed by non-empty sequence consisting only of characters 'e' or 'E'
* it must be immediately followed by non-empty sequence consisting only of characters 'o' or 'O'
* it must be immediately followed by non-empty sequence consisting only of characters 'w' or 'W', this sequence ends the string, after it immediately comes the string end

For example, strings "meow", "mmmEeOWww", "MeOooOw" describe a meowing, but strings "Mweo", "MeO", "moew", "MmEW", "meowmeow" do not.

Determine whether the sound you heard was a cat meowing or something else.

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 50$) — the length of the string describing the sound.

The second line of each test case contains a string $s$ of $n$ characters. The string describes the sound you heard and consists only of lowercase and uppercase Latin letters. 

## Output

For each test case, output on a separate line: 

* YES if the sound was a cat meowing;
* NO otherwise.

You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as positive response).

## Example

## Input


```

74meOw14mMmeoOoWWWwwwW3mew7MmeEeUw4MEOW6MmyaVW5meowA
```
## Output


```

YES
YES
NO
NO
YES
NO
NO

```
## Note

In the first test case, the string consists of a sequence of characters 'm', 'e', 'O', 'w', which satisfies the definition of meowing.

In the second test case, the string consists of a sequence of $3$ characters 'm' and 'M', one 'e', a sequence of $3$ characters 'o' and 'O' and a sequence of $7$ characters 'w' and 'W', which satisfies the definition of meowing.

In the third test case, the string does not describe a meowing because it lacks a sequence of 'o' or 'O' characters between 'e' and 'w'.

In the fourth test case, the string contains the character 'U', so it does not describe a meowing.



#### tags 

#800 #implementation #strings 