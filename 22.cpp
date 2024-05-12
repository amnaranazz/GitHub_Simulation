void add_follower_graph(string user1, string follower)
{
    int i = 0;
    while (i < vertices && followers_array[i].find_user() != user1)
    {
        i++;
    }

    if (i < vertices)
    {
        followers_array[i].insert_follower(follower);
        cout << "sucessfully follower inserted" << endl;
    }
    else
    {
        cout << "User not found!" << endl;
    }
}