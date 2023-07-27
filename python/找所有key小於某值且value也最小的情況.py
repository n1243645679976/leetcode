#1. sort by value並以value做迭代
#2. 建立key對應到的結果的list
#3. 建立stack，由小到大存放key
#4. 由value取得key, while stack最上方>=此key, 則stack最上方的key對應到現在的key, 並pop掉
#5. 最後留在stack的都賦予最後值


def get_after_kth_lt_ind(arr, k, init_value=None):
    if init_value == None:
        init_value = len(arr)
    output = [init_value] * len(arr)
    stacks = [[] for i in range(k)]
    for j in range(len(arr)):
        #print(stacks)
        #print(j, output)
        for i in range(k-1, -1, -1):
            if i != k-1:
                temp = []
                while stacks[i] and arr[j] > arr[stacks[i][-1]]:
                    temp.append(stacks[i].pop())
                while temp:
                    stacks[i+1].append(temp.pop())
            else:
                while stacks[i] and arr[j] > arr[stacks[i][-1]]:
                    c = stacks[i].pop()
                    output[c] = j
            if i == 0:
                stacks[i].append(j)
    return output
    
def get_before_kth_le_ind(arr, k, init_value=-1):
    output = [init_value] * len(arr)
    stacks = [[] for i in range(k)]
    for j in range(len(arr)-1, -1, -1):
        #print(stacks)
        for i in range(k-1, -1, -1):
            if i != k-1:
                temp = []
                while stacks[i] and arr[j] >= arr[stacks[i][-1]]:
                    temp.append(stacks[i].pop())
                while temp:
                    stacks[i+1].append(temp.pop())
            else:
                while stacks[i] and arr[j] >= arr[stacks[i][-1]]:
                    c = stacks[i].pop()
                    output[c] = j
            if i == 0:
                stacks[i].append(j)
    return output