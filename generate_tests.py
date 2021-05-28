from random import randint
import numpy as np

def solution(data, value):
    mid = len(data) // 2
    low = 0
    high = len(data) - 1

    while data[mid] != value and low <= high:
        if value > data[mid]:
            low = mid + 1
        else:
            high = mid - 1
        mid = (low + high) // 2

    if low <= high:
        return "YES"
    else:
        return "NO"


def saveFiles(index, data, value, result):
    name_index = ""
    if (index < 10):
        name_index = "0" + str(index)
    else:
        name_index = str(index)

    input = open("tests/" + name_index + ".in", "w")
    output = open("tests/" + name_index + ".out", "w")

    input.write(str(len(data)) + "\n")
    input.write(' '.join(map(str, data)) + "\n")
    input.write(str(value))
    input.close()

    output.write(result)

start_index = 4
for test in range(start_index, 11):
    data = []
    for i in range(0, randint(100000, 500000)):
        data.append(randint(1, 1000))

    value = randint(1, 10000)
    if randint(0, 1) == 1:
        value = data[randint(0, len(data) - 10000)]

    data.sort()
    result = solution(data, value)
    saveFiles(test, data, value, result)

data = list(np.random.choice(np.arange(1, 2000000), 1000000, replace=False))
value = 3000000
data.sort()
result = solution(data, value)
saveFiles(11, data, value, result)

data = list(np.random.choice(np.arange(1, 5000000), 3000000, replace=False))
value = data[len(data) - 25000]
data.sort()
result = solution(data, value)
saveFiles(12, data, value, result)