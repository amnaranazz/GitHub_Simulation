
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

    void add_follower_graph(int v, string user1)
    {
        followers_array[v].insert_follower(user1);
    }

    void delete_follower_graph(int v, string user)
    {
        followers_array[v].delete_follower(user);
    }
};
