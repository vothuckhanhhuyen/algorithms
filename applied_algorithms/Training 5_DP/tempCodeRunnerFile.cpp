int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int smax = a[0];
    int ei = a[0];
    for (int i = 1; i < n; i++) {
        ei = max(a[i], a[i] + ei);
        smax = max(smax, ei);
    }

    cout << smax;

    return 0;