def Max (nums) :
    result = 0
    count = 0
    for i in range (len(nums)) :
        if nums[i] == 1 :
            count += 1
        else :
            if count > result :
                result = count
                count = 0
            else :
                count = 0
    if count > result :
        return count
    else :
        return result

l = [1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1]

print(Max(l))