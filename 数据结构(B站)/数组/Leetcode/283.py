'''
def moveZeroes (nums) :
    for i in range (len(nums)) :
        if nums[i] == 0 :
            for j in range (i, len(nums)-1) :
                nums[j] = nums[j+1]
                nums[len(nums)-1] = 0
    return nums
'''

def moveZeroes (nums) :
    x = 0
    for i in range(len(nums)) :
        if nums[i] != 0 :
            nums[x] = nums[i]
            x += 1
    for j in range(x, len(nums)) :
        nums[j] = 0
    return nums

l = [0,0,2,1,1,2]

print(moveZeroes(l))