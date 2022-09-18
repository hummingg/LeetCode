from multiprocessing.forkserver import connect_to_new_process


class Solution:
    def maxmiumScore(self, cards: List[int], cnt: int) -> int:
        cards.sort(reverse=True)
        odds, evens = [], []
        ret = 0
        for i in range(len(cards)):
            if cards[i] % 2 == 0:
                evens.append(cards[i])
            else:
                odds.append(cards[i])
        # print(evens, odds)
        while cnt > 1 and len(odds) > 1 and len(evens) > 1:
            sumodd = odds[0] + odds[1]
            sumeven = evens[0] + evens[1]
            # print(sumeven)
            if sumodd >= sumeven:
                ret += sumodd
                # print(odds[0:2])
                odds.pop(0)
                odds.pop(0)
                cnt -= 2
            else:
                ret += evens[0]
                # print(evens[0:1])
                evens.pop(0)
                cnt -= 1

        if cnt == 0:
            return ret
        
        if cnt == 1:
            if len(evens) == 0:
                return 0
            else:
                return ret + evens[0]
        # cnt>=2
        if len(odds) < 2:
            return ret + sum(evens[0:cnt])
        # cnt>1 and len(odds)>1 => len(odds) <= 1
        if len(evens) == 0:
            return ret + odds[0:cnt] if cnt%2==0 else 0 # 不会越界
        else:   # len(evens) == 1
            if cnt % 2 == 1:
                return ret + evens[0] + sum(odds[0:cnt-1])   # 不会越界
            else:
                if odds[cnt-1] >= evens[0]:
                    return ret + sum(odds[0:cnt])
                else:
                    return ret + evens[0] + sum(odds[0:cnt-1])
    # TLE
    def maxmiumScore8(self, cards: List[int], cnt: int) -> int:
        cards.sort(reverse=True)
        odds, evens = [], []
        ret = 0
        for i in range(len(cards)):
            if cards[i] % 2 == 0:
                evens.append(cards[i])
            else:
                odds.append(cards[i])
        oddsize, evensize = len(odds), len(evens)
        oddPreSum, evenPreSum = [0] * (oddsize+1), [0] * (evensize+1)
        for i in range(oddsize):
            oddPreSum[i+1] = oddPreSum[i] + odds[i]
        for i in range(evensize):
            evenPreSum[i+1] = evenPreSum[i] + evens[i]
        for i in range(evensize+1):
            # i个偶数,cnt-i个奇数
            if (cnt-i) % 2 != 0 or (cnt-i)<0 or (cnt-i)>len(oddsize):
                continue
            ret = max(ret, evenPreSum[i] + oddPreSum[cnt-i])
        return ret
    
    def maxmiumScore9(self, cards: List[int], cnt: int) -> int:
        cards.sort(reverse=True)
        # print(cards)
        odds, evens = [], []
        ret = 0
        for i in range(len(cards)):
            if cards[i] % 2 == 0:
                evens.append(cards[i])
            else:
                odds.append(cards[i])
        while cnt > 0:
            if len(odds) > 1:
                if cnt>1:
                    oddsum = odds[0] + odds[1]
                    if len(evens) == 0:
                        ret += oddsum
                        odds.pop(0)
                        odds.pop(0)
                        cnt -= 2
                    elif len(evens) == 1:
                        if oddsum > evens[0]:
                            ret += odds[0] + odds[1]
                            odds.pop(0)
                            odds.pop(0)
                            cnt -= 2
                        else:
                            ret += evens[0]
                            cnt -= 1
                            evens.pop(0)
                    else:
                        evensum = evens[0]+evens[1]
                        if oddsum >= evensum:
                            ret += oddsum
                            odds.pop(0)
                            odds.pop(0)
                            cnt -= 2
                        else:
                            ret += evensum
                            cnt -= 2
                            evens.pop(0)
                            evens.pop(0)
                        
                else:
                    if len(evens) == 0:
                        break   # 没有偶数了，也没有2个奇数了
                    ret += evens[0]
                    cnt -= 1
                    evens.pop(0)
            else:
                if len(evens) == 0:
                    break   # 没有偶数了，也没有2个奇数了
                ret += evens[0]
                evens.pop(0)
                cnt -= 1
        return ret if cnt == 0 else 0
            
'''
[1,2,8,9]
3
[3,3,1]
1
[7,4,1]
1
[3,4,5,3,4,10,7,4]
6
[2,2,2,2]
3
[1,3,4,5]
4
[7,1,5,8,3,3,1,2]
7
[7,6,4,6]
1
'''