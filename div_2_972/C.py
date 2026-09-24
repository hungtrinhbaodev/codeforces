# Link: https://codeforces.com/contest/2005/problem/C 
# python3 -u "/Users/lap13994/Documents/SelfLearn/codeforce.py"
 
import math 
import sys 
from collections import deque 
 
 
input = lambda: sys.stdin.readline().rstrip() 
input_to_int = lambda: int(input()) 
input_to_map = lambda: map(int, input().split()) 
input_to_list = lambda: list(input_to_map()) 
 
 
_desired_str = "narek" 
_desired_str_len = len(_desired_str) 
_inf_val = math.inf 
_inf_min = int(-1000000)
_used_chars = ["n", "a", "r", "e", "k"]
 
 
def cal_total_appearance_of(chars: str, sample_str: str) -> int: 
    appearances = 0 
    for chr in chars: 
        appearances += sample_str.count(chr) 
    return appearances 
 
 
 # vi du prev_tail = "nar", next_sample = "aarekne", last_delta_point = 10
 # ham nay se tra ve (next_state: "n", next_delta_point: 11)

 # giai thich "nar" + "aarekne" = "naraarekne" trong do "NARaarEKNe" (viet hoa la human take point, viet thuong la bot take point)
 # nen nguoi se co them 5 diem o state nay va du "N" nguoc lai bot se duoc 4 diem o step nay nen diem chenh lech
 # tiep theo se la 10 + 5 - 4 = 11 va state "nar" o step truoc da duoc bien thanh state "n" o step nay voi so diem la 11 @@

 # sau do se dung cai next_state: "n" co next_delta_point la 11 nay
 # so sanh voi dp_tmp["n"] la ket qua cua state "n" o step truoc
 # neu lon hon se cap nhat

def cal_optimal_scores(last_delta_point: int, prev_tail: str, next_sample: str ) -> tuple:
    # point is bonus for bot or human when choose current sample at current prev_tal
    bonus_point_bot_at_step = 0
    bonus_point_human_at_step = 0

    # make stack by last tail
    stack_right_string = []
    for char in prev_tail:
        stack_right_string.append(char)

    # iterator all char in sample to calculate next delta point 
    for char_in_sample in next_sample:
        if len(stack_right_string) <= 0:
            # check current char in sample is equal n
            if char_in_sample == "n":
                stack_right_string.append(char_in_sample)
            # if it not check char in sample in _use_char and add point for bot
            elif char_in_sample in _used_chars:
                bonus_point_bot_at_step += 1
        else:
            # in this else char in stack just is "n", "na", "nar", "nare"
            # so last char just is n, a, r, e
            last_char = stack_right_string[-1]

            # find a index of last right char in _use char list and next char human need will have the next index in _use_char
            # khuc nay hoi trick nha em Cuong em co the dung cho sau nay a
            index_last_char = _used_chars.index(last_char) % len(_used_chars)
            # print(_used_chars.index(last_char))
            # print(last_char + " " + str(index_last_char))
            char_human_need = _used_chars[index_last_char + 1]

            # check current char in sample is equal char human need
            if char_human_need == char_in_sample:
                stack_right_string.append(char_in_sample)
            # if it not check char in sample in _use_char and add point for bot
            elif char_in_sample in _used_chars:
                bonus_point_bot_at_step += 1

        # if stack len is equal len _use_char it mean human take a right pattern he need is narek
        # so add point for him and clear stack
        if len(stack_right_string) >= len(_used_chars):
            bonus_point_human_at_step += len(_used_chars)
            stack_right_string = []

    # get next state string by stack
    next_state_str = ""
    for char in stack_right_string:
        next_state_str += char
    
    # cal delta point of human and bot by last point and bonus point of both
    next_delta_point = last_delta_point + (bonus_point_human_at_step - bonus_point_bot_at_step)

    return (next_state_str, next_delta_point)

    
 
 
def cal_final_score_per_state(human_score: int, bot_score: int) -> int: 
    cur_score = human_score - bot_score 
    if cur_score > 0: 
        return cur_score 
    return 0 
 
 
def solve() -> int: 
    total_samples, _ = input_to_map() 
    samples = [input() for _ in range(total_samples)] 
    # t := [n, a, r, e, k] 
    # + Calculate the total appearance of each letter from t. 
    # + Calculate the maximize number which the `_desired_str` sequence was able to exist. 
    dp = {"nare": _inf_min, "nar": _inf_min, "na": _inf_min, "n": _inf_min, "empty": 0} 
    for sample in samples: 

        dp_tmp = {}
        # copy dp to dp temp
        for key in dp.keys():
            dp_tmp[key] = dp[key]

        for key in dp.keys():
            # get point human - point bot at last step
            last_delta_point = dp[key]

            # get last state string remain ("", "n", "na", "nar", "nare")
            prev_tail = key
            if prev_tail == "empty":
                prev_tail = ""

            # cal new state and new value at last state
            cur_state, cur_delta_point = cal_optimal_scores(last_delta_point, prev_tail, sample)

            # remap "" to "empty" to get right key in dp
            if cur_state == "":
                cur_state = "empty"
            
            # print(cur_state + ": " + str(cur_delta_point) + ", " + str(last_delta_point))
            # calulate dp at new step make to last step and get the bigger
            if dp_tmp[cur_state] < cur_delta_point:
                dp_tmp[cur_state] = cur_delta_point
        
        dp = dp_tmp

    # khuc nay la bai tap cua em tai sao phai lam
    # nhu vay em Cuong nhe
    for key in dp.keys():
        val = dp[key]
        true_key = key
        if true_key == "empty":
            true_key = ""
        dp[key] = val - len(true_key)

    
    return max(dp.values()) 
 
for _ in range(input_to_int()): 
    print(solve())


/**
 * link contest: https://codeforces.com/contest/2005/problem/C
 */
