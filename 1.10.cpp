
void delete_file_repo(nodetree* root, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        temp->files->deletelist();
        cout << "File successfully deleted" << endl;
    }
    else
    {
        cout << "Repository not found." << endl;
    }
}

void add_commit_repo(nodetree* root, string message, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        temp->commits->insert_list_commit(message);
        cout << "Commit successfully added" << endl;
    }
    else {
        cout << "Repository not found." << endl;
    }
}

void delete_commits_repo(nodetree* root, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        temp->commits->deletelist_commit();
    }
    else
    {
        cout << "Repository not found." << endl;
    }
}