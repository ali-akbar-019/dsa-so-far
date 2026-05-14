import math

def min_max(currDept, nodeIndex, scoresArray, maxTurn, targetDept):
    if currDept == targetDept:
        return scoresArray[nodeIndex]

    if maxTurn:
        return max(min_max(currDept + 1, nodeIndex * 3, scoresArray, False, targetDept),min_max(currDept + 1, nodeIndex * 3 + 1, scoresArray, False, targetDept),min_max(currDept + 1, nodeIndex * 3 + 2, scoresArray , False, targetDept))
    else:
        return min(min_max(currDept + 1, nodeIndex  *3 , scoresArray, True, targetDept),min_max(currDept + 1, nodeIndex  * 3 + 1, scoresArray , True, targetDept), min_max(currDept + 1, nodeIndex * 3 + 2, scoresArray, True, targetDept))

scores = [3, 12,8,2,4,6,14,5,2]
targetDept = int(math.log(len(scores), 3))

ans = min_max(0, 0, scores, True, targetDept)
print("ans: ", ans)