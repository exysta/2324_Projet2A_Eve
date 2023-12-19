if __name__ == '__main__':
    # For 5.1V
    E = 24
    f = 1e5
    T = 1/f

    Vs = 5.1
    alpha = Vs/E
    L = 220e-6
    dV = 0.01
    dI = alpha*(1-alpha)*E*T/L

    Cs = alpha*(1-alpha)*E*T*T/(8*L*dV)
    print(f'C {Vs}V : {Cs}F')

    # For 7.5V
    E = 24
    f = 1e5
    T = 1/f

    Vs = 7.5
    alpha = Vs/E
    L = 220e-6
    dV = 0.1
    dI = alpha*(1-alpha)*E*T/L

    Cs = alpha*(1-alpha)*E*T*T/(8*L*dV)
    print(f'C {Vs}V : {Cs}F')

    # For 5.1V
    E = 24
    f = 1e5
    T = 1/f

    Vs = 11.7
    alpha = Vs/E
    L = 220e-6
    dV = 0.01
    dI = alpha*(1-alpha)*E*T/L

    Cs = alpha*(1-alpha)*E*T*T/(8*L*dV)
    print(f'C {Vs}V : {Cs}F')
