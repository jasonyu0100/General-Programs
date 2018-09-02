from collections import Counter

with open("leaderboardin.txt") as f:
    scoreCount = int(f.readline())
    scores = list(map(int,f.readline().split()))
    myScoreCount = int(f.readline())
    myScores = list(map(int,f.readline().split()))
    sortedScores = sorted(list(set(scores)),reverse=True)
    for currentScore in myScores:
        currentRank = 0
        for score in sortedScores:
            currentRank += 1
            if score <= currentScore:
                break
        else:
            currentRank += 1
        print(currentScore,currentRank)

        
