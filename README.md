*This project has been created as part of the 42 curriculum by dianasta*

# push_swap

## Description

`push_swap` sorts a stack of integers using a second stack and a limited set of
operations, and prints the list of operations it used. The goal is to produce as
few operations as possible, which means choosing the right algorithm for the
input.

Stack `a` starts with the given integers (no duplicates, first argument on top),
stack `b` is empty. The 11 operations are `sa sb ss pa pb ra rb rr rra rrb rrr`.

The program embeds four strategies and picks one at runtime:

| Flag | Strategy | Complexity (in operations) |
|---|---|---|
| `--simple` | selection sort | O(n²) |
| `--medium` | chunk sort | O(n√n) |
| `--complex` | LSD binary radix sort | O(n log n) |
| `--adaptive` (default) | chooses one of the above from the disorder | see below |

## Instructions

```bash
make                     # builds libft and ./push_swap
./push_swap 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --bench --complex 4 67 3 87 23   # statistics on stderr
make clean; make fclean; make re         # cleanup and rebuild
```

Arguments: an optional strategy flag (`--simple`, `--medium`, `--complex`,
`--adaptive`), an optional `--bench`, and the integers. A single quoted string
(`"4 67 3 87 23"`) is also accepted. Any invalid input (non-integer, value
outside the `int` range, duplicate, unknown flag, two strategy flags) prints
`Error` on stderr and exits with status 1. Without arguments nothing is printed.

`--bench` writes to **stderr**: the disorder (%), the strategy and its
complexity class, the total number of operations and the count of each
operation. The operations themselves stay on stdout.

Checking a result:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

All input values are first replaced by their rank (0 to n-1), so every strategy
works on a permutation. Complexities are counted in **push_swap operations
generated**, not in array operations.

### Disorder

`disorder = mistakes / total_pairs`, where a mistake is a pair `i < j` with
`a[i] > a[j]`. It is computed once, before any move. It is 0 for a sorted stack
and 1 for a reversed one. A random permutation is around 0.5.

### Simple: selection sort, O(n²)

Repeatedly bring the smallest remaining value to the top of `a` (using `ra` or
`rra`, whichever is shorter) and push it to `b`, until three elements are left.
Sort those three with a fixed case table, then push everything back with `pa`.
Each of the n extractions costs up to n/2 rotations, so the total is O(n²).
Extra space: O(1) besides the two stacks.

### Medium: chunk sort, O(n√n)

The ranks are cut into about √n chunks of about √n values. For each chunk, scan
`a` once, pushing the values of the current range to `b` and rotating `a` past
the others; smaller values are rotated to the bottom of `b`. Then bring the
largest value of `b` to the top (`rb` or `rrb`) and push it back to `a`, n times.
The push phase makes one pass over `a` per chunk, giving √n · n rotations. In the
pull phase the wanted value is always within a chunk of the top, about √n
rotations each. Total: O(n√n).

### Complex: LSD radix sort, O(n log n)

For each bit of the rank, from the lowest, go through `a` once: a value with that
bit set is rotated (`ra`), otherwise it is pushed to `b` (`pb`). Then push all of
`b` back. There are ⌈log₂ n⌉ passes, each costing at most 2n operations, so the
total is O(n log n). A pass is skipped as soon as `a` is already sorted.

### Adaptive

| Disorder | Strategy | Why |
|---|---|---|
| < 0.2 | simple | few inversions: the list is nearly sorted and the cheap method is enough |
| 0.2 to < 0.5 | medium | partly mixed: chunking pays off without radix's fixed cost |
| ≥ 0.5 | complex | heavily mixed: only the O(n log n) bound is safe |

The thresholds are the regime boundaries given in the subject; the choice of
which method serves each regime is ours. Space is O(n) for the two stacks.

### Measured results (random input, operations)

| n | simple | medium | complex |
|---|---|---|---|
| 100 | about 1450 | about 585 | 1084 |
| 500 | not a target | about 5200 | 6784 |

With the default `--adaptive`, a random list has a disorder close to 0.5, so
depending on the draw it uses medium (excellent range) or complex (good range).

## Testing

- The official `checker_linux` on random inputs of 1 to 500 numbers for all four
  strategies, plus sorted, reversed, `INT_MIN`/`INT_MAX` and negative inputs.
- `valgrind --leak-check=full` on every strategy and on the error paths.
- `norminette` on all sources.

## Contributions

- **dianasta**: <fill in: e.g. parsing, stack and operations, ...>
- **<partner_login>**: <fill in: e.g. sorting strategies, bench mode, ...>

## Resources

- Subject: push_swap (version 1.1), 42 curriculum.
- Big-O notation and sorting algorithms: selection sort, chunk/bucket sort, LSD
  radix sort (general references such as Wikipedia and GeeksforGeeks).
- Push_swap write-ups and visualizers found online, used to understand the
  problem and typical approaches.

### How AI was used

AI was used in these ways:

- **Testing:** writing test scripts and a stand-in checker, running random and
  edge-case tests for all four strategies, comparing against the official
  checker, running valgrind and norminette, and measuring operation counts.
- **Debugging and vulnerability review:** finding bugs, error-handling gaps
  (overflow, duplicates, empty arguments) and leaks.
- **Algorithm ideas:** suggestions on how to reduce the operation count
  (for example combining `rr`/`rrr`, a quicksort-style alternative to radix) and
  explanations of the complexity classes.

