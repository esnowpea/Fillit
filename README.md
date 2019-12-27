# Fillit
There is a better, faster version that uses Algorithm X over here, check it out!

The purpose is to make the smallest possible "square" (which can contain holes) with a given list of tetriminos, but the disposition must be as such that it returns the first possible solution when placing them recursively from the top left.

"Algorithm X" is the name Donald Knuth used in his paper "Dancing Links" to refer to "the most obvious trial-and-error approach" for finding all solutions to the exact cover problem. Because exact cover problems tend to be sparse, this representation is usually much more efficient in both size and processing time required. Algorithm X then uses dancing links to quickly select permutations of rows as possible solutions and to efficiently backtrack (undo) mistaken guesses.


## Compiling
Run `make`, an executable called `fillit` should compile directly

## Usage
`./fillit [file]`

Example:
```
~ cat -e valid_19
....$
..#.$
.##.$
..#.$
$
.##.$
##..$
....$
....$
$
....$
..##$
.##.$
....$
$
#...$
#...$
#...$
#...$
$
.#..$
.#..$
.##.$
....$
$
....$
..#.$
..##$
...#$
$
....$
..##$
..##$
....$
$
.#..$
.#..$
.##.$
....$
$
.#..$
.##.$
.#..$
....$

~ ./fillit valid_19

.A.BBCC
AABBCCD
EAF.GGD
E.FFGGD
EEHFI.D
..H.II.
..HHI..
```
