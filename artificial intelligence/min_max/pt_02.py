import math

def min_max(currDept, nodeIndex, scores, maxTurn, targetDept):

    if currDept == targetDept:
        return scores[nodeIndex]

    if maxTurn:
        return max(min_max(currDept + 1, nodeIndex * 3 , scores, False, targetDept),min_max(currDept + 1, nodeIndex * 3 + 1 , scores, False, targetDept),min_max(currDept + 1, nodeIndex * 3 +2, scores, False, targetDept))
    else:
        return min(min_max(currDept + 1, nodeIndex * 3 , scores, True, targetDept),min_max(currDept + 1, nodeIndex * 3 + 1 , scores, True, targetDept),min_max(currDept + 1, nodeIndex * 3 +2, scores, True, targetDept))
    

scores = [4,3,5,2,1,4,2,3,5,4,7,3,2,1,4,0,5,3,0,2,7,4,3,6,5,3,1]
dept = int(math.log(len(scores), 3))

ans = min_max(0,0,scores, True, dept)
print("ans: ", ans)