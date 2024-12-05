data = """
61967   56543
11022   54992
21268   29417
90452   95846
90728   95846
82351   12878
"""

lines = data.strip().split("\n")

arr1 = []
arr2 = []

for line in lines:
    col1, col2 = map(int, line.split())
    arr1.append(col1)
    arr2.append(col2)

arr1.sort()
arr2.sort()

diff = 0

n = len(arr1)
i = 0
while i < n:
    diff += abs(arr1[i] - arr2[i])
    i += 1

print("Difference is", diff)