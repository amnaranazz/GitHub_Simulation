
    nodetree* search_repo(nodetree* root, string name)
    {
        if (root == NULL || root->name == name) 
        {
            return root;
        }
        else if (name < root->name) 
        {
            return search_repo(root->leftroot, name);
        }
        return search_repo(root->rightroot, name);
    }

    void add_file_repo(nodetree* root, string data, string name)
    {
        nodetree* temp = search_repo(root, name);
        if (temp != NULL) 
        {
            temp->files->insert_list(data);
            cout << "File successfully uploaded" << endl;
        }
        else
        {
            cout << "Repository not found." << endl;
        }
    }
