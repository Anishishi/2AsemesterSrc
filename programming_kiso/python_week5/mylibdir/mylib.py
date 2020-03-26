def nintegrate(func, x_start, x_end, split_num):
    ans = 0
    split = abs(x_end - x_start) / split_num
    x0 = 0
    for i in range(split_num):
        ans += (func(x0) + func(x0+split)) * split / 2
        x0 += split
    return ans