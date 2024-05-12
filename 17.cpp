
int verify_user(string username, string password)
{
    int array_max = max_length, key, i = 0;
    key = hash_key(username);
    if (user_array[key].username != username || user_array[key].password != password)
    {
        while (i < max_length && (user_array[key].username != "0" || user_array[key].username != username))
        {
            key = (key + 1) % max_length;
            i++;
        }
    }
    if (user_array[key].username == username && user_array[key].password == password)
    {
        return 1;
    }
    else
    {
        cout << "Invalid credentials" << endl;
        return -1;
    }
}