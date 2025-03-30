class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        la = len(arr)
        a, b = 0, la - 1
        while a != la - 1 and arr[a+1] > arr[a]: a += 1
        while b != 0 and arr[b] < arr[b-1]: b -= 1
        return a == b and a != 0 and a != la - 1
        