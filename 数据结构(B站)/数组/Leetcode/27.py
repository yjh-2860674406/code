'''
def removeElement (val, nums) :
    x=0
    y=0
    for i in range(len(nums)) :
        if nums[i] == val :
            nums[i] = 0
            x += 1
    for j in range(len(nums)) :
        if nums[j] != 0 :
            nums[y] = nums[j]
            y += 1
    for z in range(y, len(nums)) :
        nums[z] = 0
    return (len(nums)-x, nums)
'''
def removeElement (val, nums) :
    for i in range(len(nums)) :
        if nums[i] == val :
            for j in range(len(nums), -1):
                if nums[j] =

l = [1,1,1,1,2,2,3,4]
print(removeElement(1,l))