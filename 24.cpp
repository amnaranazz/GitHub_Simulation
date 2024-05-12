
void login_user()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    int result = userTable->verify_user(username, password);
    if (result == 1)
    {
        cout << "Login successful!" << endl;
        loggedin = true;
    }
    else if (result == -1)
    {
        cout << "Login failed. Invalid credentials." << endl;
    }
}