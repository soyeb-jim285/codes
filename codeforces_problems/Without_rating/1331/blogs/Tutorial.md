# Tutorial

*This was the most well-attended April Fools Day Contest in the whole history of them: 10343 participants solved at least one problem! It was also fairly well-balanced: while each problem has been solved by at least 200 participants, only 17 of them solved all 8 problems.*

[1331A - Is it rated?](../problems/A._Is_it_rated_.md "April Fools Day Contest 2020")
-----------------------------------------------------------------------------------------------------

This was the consolation problem of the contest, and still a lot of participants asked me for hints on this problem — some even before the beginning of the round! If you're still not sure how to solve it, the contest announcement itself promised that the contest is not rated, so the answer is a resolute ``NO'' (case insensitive, quotes for clarity only) :-) 

[1331B - Limericks](../problems/B._Limericks.md "April Fools Day Contest 2020")
--------------------------------------------------------------------------------------------------

Unusually for this type of contests, the second problem had an actual problem statement! The real task was hidden in it using Steganography 101 — the first letters of the lines spelled out "TWO FACTORS". A quick look at the examples confirmed that you needed to factor the given number and print its factors (in non-decreasing order, without space between them).

[1331C - ...And after happily lived ever they](../problems/C._...And_after_happily_lived_ever_they.md "April Fools Day Contest 2020")
-----------------------------------------------------------------------------------------------------------------------------

You are probably familiar with the fairy tale ending "... and they lived happily ever after". The problem title is almost that phrase, but with the words scrambled. If you check the problem statement in the other language, it will be a different 6-word phrase that underwent the same scramble. The constraints on the input say that it is an integer are from 0 to 26-1; these two things together should push you towards thinking about binary. The solution is as follows: read the input, convert it into a 6-bit binary representation and scramble it in the same way as the words in the title are scrambled (swapping the 2nd with the 6th and the 3rd with the 4th) before converting it back to the integer. You didn't need to worry whether you need to apply the permutation or the inverse permutation, since those two were the same.

[1331D - Again?](../problems/D._Again_.md "April Fools Day Contest 2020")
-----------------------------------------------------------------------------------------------

*This problem has been written by [kit1980](https://codeforces.com/profile/kit1980 "Specialist kit1980").*

The answer is just the hexadecimal number given in the input taken modulo 2. The problem is absolutely unrelated to OEIS, same as [656F - Ace It!](https://codeforces.com/contest/656/problem/F "April Fools Day Contest 2016").

[1331E - Jordan Smiley](../problems/E._Jordan_Smiley.md "April Fools Day Contest 2020")
------------------------------------------------------------------------------------------------------

The problem was inspired by the [Jordan curve theorem](https://codeforces.com/https://en.wikipedia.org/wiki/Jordan_curve_theorem), more specifically by [this blog post](https://codeforces.com/http://www2.oberlin.edu/math/faculty/bosch/making-tspart-page.html). You were given the coordinates of a pixel within the picture, and you had to figure out whether it was inside or outside of the region defined by the closed curve that made up the picture.

Once you figured that out, the problem became mostly image parsing :-) The easiest way was to flood-fill the region inside the curve using an image editor, and then somehow convert pixels of different colors into an array of 0s and 1s.

[1331F - Elementary!](../problems/F._Elementary!.md "April Fools Day Contest 2020")
----------------------------------------------------------------------------------------------------

YES or NO answer implies that you need to figure out whether the given word is "elementary!". At a glance this seems *elementary, my dear Watson!* — but the fact that "HOLMES" is a "NO" while "WATSON" is a "YES" suggests that this is not what's going on here. In fact you were supposed to use another meaning of the word "elementary" — the one of the periodic table of chemical elements. The word was "elementary" if it could be spelled using only the abbreviated symbols of elements: Ge-Ni-U-S or W-At-S-O-N.

[1331G - Lingua Romana](../problems/G._Lingua_Romana.md "April Fools Day Contest 2020")
------------------------------------------------------------------------------------------------------

*This problem has been written by [kit1980](https://codeforces.com/profile/kit1980 "Specialist kit1980").*

The problem statement is actual source code of a program written in [Perligata](https://codeforces.com/http://users.monash.edu/~damian/papers/HTML/Perligata.html). If you manage to run it (or translate it from Latin, though I wouldn't recommend that!), you might recognize [TPK algorithm](https://codeforces.com/https://en.wikipedia.org/wiki/TPK_algorithm). After that you can implement it yourself or look it up on [RosettaCode](https://codeforces.com/https://rosettacode.org/wiki/Trabb_Pardo%E2%80%93Knuth_algorithm).

[1331H - It's showtime](../problems/H._It's_showtime.md "April Fools Day Contest 2020")
------------------------------------------------------------------------------------------------------

Both the problem title and the error message you'd get if you try to run some random code like "123" in custom invocation tab point you to an esoteric language [ArnoldC](https://codeforces.com/https://github.com/lhartikk/ArnoldC) — a language based on the one-liners of Arnold Schwarzenegger. You'd have to experiment a bit with finer and less documented points of the language, such as reading input, but modulo function is defined in the documentation, and overall it's a fairly approachable language — as long as you don't try anything fancy like arrays!

