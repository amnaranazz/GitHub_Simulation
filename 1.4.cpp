
class listcommit
{
private:
    nodecommit* head;

public:
    listcommit()
    {
        head = NULL;
    }

    void insert_list_commit(string data)
    {
        nodecommit* new_node = new nodecommit;
        new_node->message = data;
        new_node->next = head;
        head = new_node;
    }

    void deletelist_commit()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        nodecommit* temp = head;
        head = head->next;
        delete temp;
        cout << "Commit deleted." << endl;
    }

    int count_commits()
    {
        int count = 0;
        nodecommit* curr = head;
        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
};