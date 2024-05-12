
void delete_follower(string user2)
{
    node_graph* curr = head;
    node_graph* temp = NULL;

    while (curr != NULL && curr->next->follower_name != user2)
    {
        curr = curr->next;
    }
    if (curr->next == tail)
    {
        temp = curr->next;
        tail = curr;
        delete curr;
        temp = NULL;

    }
    else
    {
        temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        temp = NULL;
    }
}

string find_user()
{
    if (head != NULL)
    {
        return head->follower_name;
    }
    return "0";
}
};
