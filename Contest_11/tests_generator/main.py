def hook(ty):
    h = 0
    u = 0
    for i in range(len(tyu)):
        u -= 1
        if u < 1 and tyu[i] <= ty:
            h += 1
            u = people_in_team
    if h >= num_of_teams:
        return True
    return False


num_of_people, num_of_teams, people_in_team = map(int, input().split())
hs = sorted([int(input()) for line in range(num_of_people)])
tyu = [hs[i + people_in_team - 1] - hs[i] for i in range(len(hs) - people_in_team + 1)]

leg = -1
reg = hs[-1] - hs[0]
if num_of_teams > 1:
    while leg + 1 != reg:
        m = (leg + reg) // 2
        if hook(m):
            reg = m
        else:
            leg = m
    print(reg)
else:
    print(min(tyu))