import math

def min_max(currentDept, nodeIndex, scoresArray, maxTurn, targetDept):
    if currentDept == targetDept:
        return scoresArray[nodeIndex]
    
    if maxTurn:
        return max(min_max(currentDept + 1, nodeIndex * 2, scoresArray, False, targetDept),min_max(currentDept + 1, nodeIndex * 2 +1, scoresArray, False, targetDept))
    else:
        return min(min_max(currentDept + 1, nodeIndex * 2, scoresArray, True, targetDept), min_max(currentDept + 1, nodeIndex * 2 + 1, scoresArray, True, targetDept))
    

scores =  [3, 5, 2, 9, 12, 5, 23, 23]
targetDept = int(math.log(len(scores), 2))

ans = min_max(0, 0, scores, True, targetDept)
print("ans: ", ans)