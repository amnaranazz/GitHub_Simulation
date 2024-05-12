
class graph_list
{
private:
    node_graph* head;
    node_graph* tail;

public:
    graph_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_user(string user1)
    {
        node_graph* new_user = new node_graph;
        new_user->follower_name = user1;
        new_user->next = head;
        head = new_user;
        if (tail == NULL)
        {
            tail = head;
        }
    }