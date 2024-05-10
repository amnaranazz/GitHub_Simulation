
class listfile
{
private:
    nodefile* head;

public:
    listfile()
    {
        head = NULL;
    }

    void insert_list(string data)
    {
        nodefile* new_node = new nodefile;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    void deletelist()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        nodefile* temp = head;
        head = head->next;
        delete temp;
        cout << "File deleted." << endl;
    }
