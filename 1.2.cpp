
class node_graph
{
public:
    node_graph* next;
    string follower_name;
};

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

    void insert_follower(string user2)
    {
        node_graph* new_follower = new node_graph;
        new_follower->follower_name = user2;
        new_follower->next = NULL;

        if (head == NULL)
        {
            head = new_follower;
            tail = new_follower;
        }
        else
        {
            tail->next = new_follower;
            tail = new_follower;
        }
    }

    void delete_follower(string user2)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        node_graph* curr = head;
        node_graph* prev = NULL;
        while (curr != NULL && curr->follower_name != user2)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Follower not found." << endl;
            return;
        }

        if (curr == head && curr == tail)
        {
            head = tail = NULL;
        }
        else if (curr == head)
        {
            head = head->next;
        }
        else if (curr == tail)
        {
            tail = prev;
            prev->next = NULL;
        }
        else
        {
            prev->next = curr->next;
        }

        delete curr;
        cout << "Follower deleted." << endl;
    }
};
