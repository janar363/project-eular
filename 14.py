import time
import math

start_time = time.time() 

# Your Python program code
has_multi = True

dp = {1: 1}
sol = []
def find_seq_len_starting_at(n):
    if n in dp: return dp[n]
    
    if n == 1: return 1
    
    if n & 1: nextSeqLen = find_seq_len_starting_at(3 * n + 1)
    else: nextSeqLen = find_seq_len_starting_at(n // 2)
    
    if n > 5000000:
        return 1 + nextSeqLen
    
    dp[n] = 1 + nextSeqLen
    
    return dp[n]

n = int(input())

inps = [int(input()) for _ in range(n)]
max_inp = max(inps)

mx = 0 
mx_id = -1
for i in range(1, max_inp+1):
    cur = find_seq_len_starting_at(i)
    if i not in dp:
        dp[i] = cur

    if dp[i] >= mx:
        mx = dp[i]
        mx_id = i

    sol.append(mx_id)

for inp in inps:
    print(sol[inp-1])    

# ...

end_time = time.time()

print("Program run time:", round(end_time - start_time, 5), "seconds")


