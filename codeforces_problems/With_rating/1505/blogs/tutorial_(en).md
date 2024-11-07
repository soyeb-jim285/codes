# tutorial_(en)

[1505A - Is it rated - 2](../problems/A._Is_it_rated_-_2.md "April Fools Day Contest 2021")
---------------------------------------------------------------------------------------------------------

This problem described the task in quite a lot of detail. The main challenge was that it was interactive, so some effort was required to figure out the right sequence of reading from standard input, writing the answer and checking for end of file. Here is the code in Python:

 
```cpp
while True:
    try:
        q = input()
    except EOFError:
        break
    print("no", flush=True)
```
[1505B - DMCA](../problems/B._DMCA.md "April Fools Day Contest 2021")
---------------------------------------------------------------------------------------------

As the problem statement strongly hinted, in this problem you had to calculate the **digital** root of the given number.

The digital root of a given number is the (single digit) value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.

[1505C - Fibonacci Words](../problems/C._Fibonacci_Words.md "April Fools Day Contest 2021")
--------------------------------------------------------------------------------------------------------

YES or NO answer implies that you need to figure out whether the given word is a Fibonacci word. Similarly to the Fibonacci-style integer sequences, a Fibonacci word is a word for which each letter equals the sum of two previous ones. Unlike the integer sequences, for this definition to make sense we have to convert each letter to a number between 0 and 25, and perform addition modulo 26.

[1505D - Xenolith? Hippodrome?](../problems/D._Xenolith_Hippodrome_.md "April Fools Day Contest 2021")
--------------------------------------------------------------------------------------------------------------

Again, YES or NO answer implies that you need to figure out whether the given pair of numbers describes something called something like "hippodrome"... Or was it "xenolith" after all? Neither of these options makes a lot of sense, but you know how it is when you're trying to remember a fancy-sounding word and come up with all kinds of similar-looking ones? The word you're looking for here is "xenodrome" — a number which, when written in a certain base, has no duplicate digits. This explains a lot: the given numbers NN and MM are the candidate number and the base, respectively; the task is to write NN in base MM and check whether all digits are unique.

[1505E - Cakewalk](../problems/E._Cakewalk.md "April Fools Day Contest 2021")
-------------------------------------------------------------------------------------------------

As the flavor text hinted and examples 3 and 4 confirmed, the mouse doesn't use an optimal strategy, but rather follows a greedy algorithm: it always goes for the nearest berry square, where the distance between squares is defined by Manhattan distance (i.e., the number of steps to the right or down that the mouse needs to take to get between them). In case of a tie, it goes for the square in the top row.

[1505F - Math](../problems/F._Math.md "April Fools Day Contest 2021")
---------------------------------------------------------------------------------------------

The images given encode a formula 2−x22−x2 using Braille for math; the top image (the shorter one) gives Nemeth representation, and the bottom one — Universal English Braille. 

[1505G - Encoded message](../problems/G._Encoded_message.md "April Fools Day Contest 2021")
--------------------------------------------------------------------------------------------------------

The biggest hint for this problem is that it follows [1505F - Math](../problems/F._Math.md "April Fools Day Contest 2021"). Once you spent some time staring at Braille symbols, recognizing the pattern of 5 numbers becomes easier: the first three numbers and the last two are the numbers of dots in the rows and columns of the Braille symbol for the encoded letter, respectively. Typing in those numbers in the solution required a fair amount of focus, but I did it at 2 am and got them right on the first try, so I figured out it's realistic :-)

[1505H - L BREAK into program](../problems/H._L_BREAK_into_program.md "April Fools Day Contest 2021")
-------------------------------------------------------------------------------------------------------------

The given program is a ZX Spectrum emulator memory snapshot.

Here are the possible steps to solve the problem:

 1. Load the file into a ZX Spectrum emulator (there are many versions, even online ones).
2. Press BREAK (usually Shift+Space in the emulator).
3. Press LIST (k) to see the BASIC source code.
4. Notice that the actual program ("Admin zone") starts on line 1000.
5. Execute "RUN 1000" and get "Integer out of range" error.
6. Find a bug in the line 1150 and fix it by changing "-" to "+", then re-run.

Line 1140 has a hidden comment about the bug. To see the comment, the background needs to be changed to a color different from white, by executing "PAPER 4", for example. It's also possible to see the comment by looking at the snapshot file in a text editor.

Instead of fixing the BASIC program, it's also should be not too hard to understand the logic and re-implement it in a more conventional programming language.

[1505I - Mysterious language again, seriously?](../problems/I._Mysterious_language_again,_seriously_.md "April Fools Day Contest 2021")
------------------------------------------------------------------------------------------------------------------------------

Unlike the past years, this time any code you submit in ``Secret 2021'' language will run successfully — or at least produce no recognizable error. The key hint at the solution can be found in the title: turns out [Seriously is a programming language](https://codeforces.com/https://github.com/Mego/Seriously)!

The next part of the challenge is figuring out how to print a message in this language — since most characters are valid commands, there's a lot of documentation to go through! There are multiple ways to print the right message (a lot of them undocumented). The reference solution used commands '1'-'9' to put corresponding numbers on the stack, '+' and '*' to perform addition and multiplication on the stack elements to get the necessary ASCII codes on the stack, 'c' to convert the integer ASCII code into the corresponding character, and '◙' to print the character on top of the stack.

