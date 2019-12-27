# Fillit
There is a better, faster version that uses dancing links algoritm over here, check it out!

The purpose is to make the smallest possible "square" (which can contain holes) with a given list of tetriminos, but the disposition must be as such that it returns the first possible solution when placing them recursively from the top left.


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
