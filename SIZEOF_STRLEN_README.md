# sizeof() vs strlen() Problem Solution

## Problem Description

This program demonstrates the difference between `sizeof()` and `strlen()` in C when dealing with strings containing null characters.

### Key Differences:
- **sizeof()**: Returns the total memory occupied by the string, including all characters (even embedded null characters) plus the final null terminator.
- **strlen()**: Returns the length of the string up to the first null character, excluding the null character itself.

## Example

For the string: `abracadabra\0abraka`

- **strlen()** = 11 (counts only "abracadabra", stops at first \0)
- **sizeof()** = 19 (counts "abracadabra" + \0 + "abraka" + final \0 = 11 + 1 + 6 + 1)

## Input Format

```
N
S1
S2
...
SN
```

Where:
- N is the number of test cases (N < 1000)
- Each Si is a string containing alphabets (A-Z, a-z) and null characters denoted as '\0'
- Maximum 100 characters per string (where '\' and '0' are counted separately in input)

## Output Format

For each string, output two space-separated integers:
```
sizeof(S) strlen(S)
```

## Compilation and Usage

```bash
gcc -o sizeof_strlen sizeof_strlen.c
./sizeof_strlen < input.txt
```

Or with direct input:
```bash
echo "1
abracadabra\0abraka" | ./sizeof_strlen
```

## Sample Input/Output

Sample files are provided in the repository:
- `sample_input.txt` - Contains test cases
- `sample_output.txt` - Expected output

**Input:**
```
5
abracadabra\0abraka
hello
test\0middle\0end
a\0b\0c
ABC
```

**Output:**
```
19 11
6 5
16 4
6 1
4 3
```

To test with the sample files:
```bash
./sizeof_strlen < sample_input.txt
```
