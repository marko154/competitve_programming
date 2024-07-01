def partition(arr, fr, to):
    pidx = fr - 1
    pivot = arr[to]
    for i in range(fr, to):
        if arr[i] < pivot:
            pidx += 1
            arr[pidx], arr[i] = arr[i], arr[pidx]
    print(pidx)
    arr[pidx + 1], arr[to] = arr[to], arr[pidx + 1]
    return pidx + 1


def kth(arr, k, fr, to):
    while True:
        pivot = partition(arr, fr, to)
        if pivot == k:
            return arr[k]
        elif pivot < k:
            to = pivot - 1
        else:
            fr = pivot + 1


arr = [3, 2, 3, 1, 2, 4, 5, 5, 6]
k = 4

print(kth(arr, k, 0, len(arr) - 1))
