void readUserCredentials()
{
    ifstream file("user_credentials.csv");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string username, password;
            getline(ss, username, ',');
            getline(ss, password, ',');
            setUser(username, password);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open user credentials file." << endl;
    }
}