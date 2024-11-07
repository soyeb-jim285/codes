# Tutorial

This turned out to be the hardest April Fools Day Contest to date — the winner solved only 5 problems out of 7! 

[1145A - Thanos Sort](../problems/A._Thanos_Sort.md "April Fools Day Contest 2019")
----------------------------------------------------------------------------------------------------

The easiest problem of the contest, with a statement and without any caveats — I just likes the idea of sorting the array by destroying elements you dislike :-) Since the array has at most 16 elements, it's enough to implement the described algorithm precisely: check if the array is sorted, if it is, return its length, otherwise return the maximum of the answers for its left and right halves.

[1145B - Kanban Numbers](../problems/B._Kanban_Numbers.md "April Fools Day Contest 2019")
-------------------------------------------------------------------------------------------------------

YES or NO answer implies that you need to figure out whether the given number is a kanban number; but first you need to figure out what kind of a number is kanban? OEIS does not have this sequence, but it has several similar ones, such as [urban numbers](https://codeforces.com/https://oeis.org/A072957) and [turban numbers](https://codeforces.com/http://oeis.org/A072956). These sequences are defined as numbers which "ban" certain letters, i.e., don't use them in their English spelling. Thus, kanban numbers "ban" letters "k", "a" and "n"; in practice the numbers from 1 to 99 never contain letters "k" or "a" so you only need to watch for "n".

[1145C - Mystery Circuit](../problems/C._Mystery_Circuit.md "April Fools Day Contest 2019")
--------------------------------------------------------------------------------------------------------

This problem was a little Easter egg for the people who follow [my recent activity](//codeforces.com/blog/entry/65063) on Codeforces :-) The image contained a (relatively) simple quantum circuit for an operation which 1) represents the number in 4-bit binary notation, 2) reverses it, 3) decrements the resulting number, 4) reverses it again and 5) outputs the resulting number in decimal notation again. You could figure this out without doing the math yourself by building this circuit in any tool for quantum circuit modeling, such as [Quirk](https://codeforces.com/https://algassert.com/quirk).

[1145D - Pigeon d'Or](../problems/D._Pigeon_d'Or.md "April Fools Day Contest 2019")
----------------------------------------------------------------------------------------------------

Pigeon d'Or is an actually existing project (well, an existing project concept). But for the purposes of this problem you don't need this knowledge, I just needed a sufficiently long text to hide the real statement. Но для целей этой задачи это знание излишне, мне просто нужен был достаточно длинный текст, в котором можно было бы спрятать настоящее условие. "We did not proofread this statement at all" hints that the typos are not accidental, and you need to pay attention to them. All typos replace correct letters with incorrect ones; if you collect all incorrect letters they will spell the real statement: "two plus xor of third and min elements".

[1145E - Fourier Doodles](../problems/E._Fourier_Doodles.md "April Fools Day Contest 2019")
--------------------------------------------------------------------------------------------------------

This problem was written by [kit1980](https://codeforces.com/profile/kit1980 "Specialist kit1980"). 

The word Fourier hints at using Fourier transform for images (you can also notice that the training data set files are a lot larger than the rest of the files, so they probably hide some extra information). Fortunately, you didn't have to implement it manually, there are plenty of existing tools to do that, including online ones (I used [http://www.ejectamenta.com/Imaging-Experiments/fourierimagefiltering.html)](https://codeforces.com/http://www.ejectamenta.com/Imaging-Experiments/fourierimagefiltering.html)). If you look at the transforms of the first 20 files, each of them has one or two characters, which together spell the formula: "((min(id, 25) + id) % (2 + id % 3)) > 0".

[1145F - Neat Words](../problems/F._Neat_Words.md "April Fools Day Contest 2019")
---------------------------------------------------------------------------------------------------

Again, YES or NO answer implies that you need to figure out whether the given word is neat. It can be tricky, especially since WORD itself is not neat... Long story short, in this problem you had to group all letters of English alphabet in two types — "linear", consisting only of straight lines, and "curved", including curved elements (you had to take the letters the way they are spelled in the statement, i.e., uppercase). Now, obviously, neat words are words in which all letters belong to the same type, and their opposite (disorderly?) are words which mix letters from both types.

[1145G - AI Takeover](../problems/G._AI_Takeover.md "April Fools Day Contest 2019")
----------------------------------------------------------------------------------------------------

The hardest part of this problem is identifying the strategies used by the agent. Once you're done with that, the rest of the solution becomes easy: find a sequence of 10 or less moves which produces a different sequence of outcomes for each strategy, play it, deduce the strategy based on the outcomes you've received, and play the counter-strategy for it.

The AI strategies were:

 * always play R, P or S,
* loop through a sequence R-P-S,
* start with R, then always play the human player's last move,
* start with R, then always play the move that beats the human player's last move.

You can check that, for example, a sequence of moves RRPPSS allows to distinguish these strategies and to win the next 10 rounds.

As for how to identify the strategies used, [majk](https://codeforces.com/profile/majk "International Grandmaster majk") described [one reasonable strategy](//codeforces.com/blog/entry/66327?#comment-503503). If you don't like relying on guesswork, you could try some kind of brute force to figure out the AI's responses to your strategy by encoding them in memory allocation or sleep time, like people frequently do for easier problems.

Oh well, I guess AI takeover is a more serious threat to humanity than I expected...

