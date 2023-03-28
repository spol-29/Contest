from collections import defaultdict

# function to count the number of double-sends in a given string
def count_excitement_level(s):
    count = 0
    for i in range(len(s)-1):
        if s[i:i+2] == "BB" or s[i:i+2] == "EE":
            count += 1
    return count

n = int(input())
s = input().strip()
num_obfuscated = int(input()) if n > 1 else 0

# create a dictionary to store the count of each possibility
excitement_counts = defaultdict(int)

# iterate over all possible combinations of obfuscated characters
for i in range(2**num_obfuscated):
    t = list(s)
    for j in range(num_obfuscated):
        if i & (1 << j):
            t[s.index("F", j)] = "B"
        else:
            t[s.index("F", j)] = "E"
    excitement_counts[count_excitement_level("".join(t))] += 1

# output the number of distinct excitement levels and the excitement levels themselves
print(len(excitement_counts))
for k in sorted(excitement_counts.keys()):
    print(k)
