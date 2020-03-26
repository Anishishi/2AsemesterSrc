def ndsolve(func, x0, t_0, t_last):
    delta_t = 0.01
    repeat_num = int((t_last - t_0)/delta_t)
    t = [t_0]
    x = [x0]
    for i in range(repeat_num):
        temp = []
        for j in range(len(func)):
            temp.append(x[i][j]+delta_t*(func[j](*x[i])))
        t_0 += delta_t
        x.append(temp)
        t.append(t_0)
    ans = []
    for i in range(len(t)):
        temp = []
        temp.append(t[i])
        for j in range(len(func)):
            temp.append(x[i][j])
        ans.append(temp)
    return ans