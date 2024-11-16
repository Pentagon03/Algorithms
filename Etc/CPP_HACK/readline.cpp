string readline(char delim = '\n'){
    string t; getline(cin, t, delim);
    return move(t);
}