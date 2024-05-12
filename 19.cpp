
void insert_follower(string user2)
{
    node_graph* new_follower = new node_graph;
    new_follower->follower_name = user2;
    new_follower->next = NULL;
    tail->next = new_follower;
    tail = new_follower;

}