string readline(char delim = '\n'){
    string t; getline(cin, t, delim);
    return move(t);
}
// istringstream iss(s = "1 2 3 4 5"); // iss >> x;