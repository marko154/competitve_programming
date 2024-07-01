import sys
import difflib

if len(sys.argv) < 3:
    exit(1)

in_file_name = sys.argv[1]
out_file_name = sys.argv[2]

_, S, T = open(in_file_name).readlines()
operations = open(out_file_name).readlines()[1].split()

S = list(S)

idx = 0
for operation in operations:
    if "-" in operation:
        S.pop(idx)
    elif "+" in operation:
        S.insert(idx, operation[1])
        idx += 1
    elif ">" in operation:
        fr, to = operation.split(">")
        S[idx] = to
        idx += 1
    else:
        idx += 1

result = "".join(S)
print("result: ", result)
print("expected: ", T)


def print_diff(string1, string2):
    differ = difflib.Differ()
    diff = list(differ.compare(string1.splitlines(), string2.splitlines()))

    print("\n".join(diff))


if T != result:
    print_diff(T, result)
