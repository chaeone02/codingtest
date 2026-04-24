def solution(n, lost, reserve):
    answer = 0
    lost.sort()
    
    # 도난+여벌 학생 먼저 처리 (lost, reserve 양쪽에서 제거), 복사본으로 순회
    for i in lost[:]:
        if i in reserve:
            reserve.remove(i)
            lost.remove(i)
    
    for i in lost:
        if (i-1) in reserve:
            reserve.remove(i-1)
            answer += 1
        elif (i+1) in reserve:
            reserve.remove(i+1)
            answer += 1
    return n - len(lost) + answer



# def solution(n, lost, reserve):
#     # 도난+여벌 중복학생 -> set으로 제거
#     real_lost = set(lost) - set(reserve)
#     real_reserve = set(reserve) - set(lost)
    
#     # 빌려주기
#     for i in sorted(real_lost):
#         if (i-1) in real_reserve:
#             real_reserve.remove(i-1)
#             real_lost.remove(i)
#         elif (i+1) in real_reserve:
#             real_reserve.remove(i+1)
#             real_lost.remove(i)
    
#     # real_lost = 끝까지 못 빌린 학생들
#     return n - len(real_lost)