
class followers
{
private:
    graph_list* followers_array;
    int vertices;

public:
    followers(int vertices)
    {
        this->vertices = vertices;
        followers_array = new graph_list[vertices];
    }

    void add_user_graph(string user)
    {
        int i = 0;
        while (i < vertices && followers_array[i].find_user() != "0")
        {
            i++;
        }

        if (i < vertices)
        {
            followers_array[i].insert_user(user);
        }
    }
