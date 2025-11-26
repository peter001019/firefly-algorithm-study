

def group(m_list):
    sum = 0
    for m in m_list:
        if m == "diamond":
            sum += 25
        elif m == "iron":
            sum += 5
        else:
            sum += 1
    return sum

def max_need(picks, minerals):
    minerals_group = []
    # 5개씩 끊어서 각 그룹의 난이도(돌 곡괭이 기준) 계산
    for i in range(0, len(minerals), 5):
        s = group(minerals[i:i+5])
        minerals_group.append(s)

    # 1) 난이도 기준으로 내림차순 정렬된 인덱스 리스트
    sorted_idx = sorted(
        range(len(minerals_group)),
        key=lambda i: minerals_group[i],
        reverse=True
    )

    # 2) 각 그룹 번호에 "등수"를 기록
    #    ranks[g] = 0 → 가장 어려운 그룹
    ranks = [0] * len(minerals_group)
    for rank, idx in enumerate(sorted_idx):
        ranks[idx] = rank
    return ranks

def fatigue(pick_type, mineral):
    if pick_type == 0:  # 다이아 곡괭이
        return 1
    elif pick_type == 1:  # 철 곡괭이
        if mineral == "diamond":
            return 5
        else:  # iron, stone
            return 1
    else:  # 돌 곡괭이
        if mineral == "diamond":
            return 25
        elif mineral == "iron":
            return 5
        else:
            return 1

def solution(picks, minerals):
    answer = 0
    picks_num=0
    for p in picks:
        picks_num+=p
    minerals_index=0
    minerals_group_rank = max_need(picks, minerals)
    minerals_group_rank_i=0
                
#     while minerals_group_rank_i < len(minerals_group_rank) and picks_num > 0:

#         # 어떤 곡괭이를 쓸지 선택 (다이아 → 철 → 돌 순)
#         pick_type = -1
#         for t in range(3):
#             if picks[t] > 0:
#                 pick_type = t
#                 break

#         if pick_type == -1:
#             break  # 더 이상 사용할 곡괭이가 없음

#         # 해당 곡괭이 1개 사용
#         picks[pick_type] -= 1
#         picks_num -= 1

#         # 이 그룹에 속하는 광물들에 대해 피로도 누적
#         group_idx = minerals_group_rank[minerals_group_rank_i]
#         start = group_idx * 5
#         end = start + 5
#         for m in minerals[start:end]:
#             answer += fatigue(pick_type, m)

#         minerals_group_rank_i += 1
    # 곡괭이로 캘 수 있는 최대 광물 수만 남겨두기
    picks_num = sum(picks)
    max_minerals = picks_num * 5
    minerals = minerals[:max_minerals]

    # 그룹별 난이도 등수 (0등 = 제일 어려운 그룹)
    minerals_group_rank = max_need(picks, minerals)
    group_cnt = len(minerals_group_rank)

    # 곡괭이 개수 기반으로 구간 나누기
    dia_cnt, iron_cnt, stone_cnt = picks
    dia_end = dia_cnt                      # rank < dia_end         → 다곡
    iron_end = dia_cnt + iron_cnt          # dia_end ≤ rank < iron_end → 철곡
    stone_end = dia_cnt + iron_cnt + stone_cnt  # 그 이후 rank < stone_end → 돌곡

    # 각 그룹별로, "자기 등수"에 따라 곡괭이 타입 결정
    for g in range(group_cnt):
        rank = minerals_group_rank[g]  # 이 그룹의 등수

        if rank < dia_end:
            pick_type = 0   # 다곡
        elif rank < iron_end:
            pick_type = 1   # 철곡
        elif rank < stone_end:
            pick_type = 2   # 돌곡
        else:
            # 이 그룹은 사용할 곡괭이가 없음 (건너뛰기)
            continue

        # 이 그룹에 속하는 광물들에 대해 피로도 누적
        start = g * 5
        end = min(start + 5, len(minerals))  # 마지막 그룹은 5개 미만일 수 있음
        for m in minerals[start:end]:
            answer += fatigue(pick_type, m)

    return answer