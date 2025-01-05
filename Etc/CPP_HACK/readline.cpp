string readline(char delim = '\n') {
    while(cin.peek() == delim) cin.ignore();
    string t; getline(cin, t, delim);
    return move(t);
}