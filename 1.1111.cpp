nodetree* delete_repository(nodetree* root, const string& name)
{
    if (root == NULL)
    {
        cout << "Repository not found." << endl;
        return root;
    }

    if (name < root->name)
        root->leftroot = delete_repository(root->leftroot, name);
    else if (name > root->name)
        root->rightroot = delete_repository(root->rightroot, name);
    else {
        if (root->leftroot == nullptr || root->rightroot == nullptr)
        {
            nodetree* temp = root->leftroot ? root->leftroot : root->rightroot;
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            nodetree* temp = minValueNode(root->rightroot);
            root->name = temp->name;
            root->rightroot = delete_repository(root->rightroot, temp->name);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->leftroot), height(root->rightroot));
    int balance = get_balance(root);
    if (balance > 1 && get_balance(root->leftroot) >= 0)
        return rightRotate(root);
    if (balance > 1 && get_balance(root->leftroot) < 0)
    {
        root->leftroot = leftRotate(root->leftroot);
        return rightRotate(root);
    }
    if (balance < -1 && get_balance(root->rightroot) <= 0)
        return leftRotate(root);
    if (balance < -1 && get_balance(root->rightroot) > 0)
    {
        root->rightroot = rightRotate(root->rightroot);
        return leftRotate(root);
    }
    return root;
}

nodetree* copy_repo_fork(nodetree* root, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        nodetree* new_repo = new nodetree;
        new_repo->isprivate = temp->isprivate;
        new_repo->name = temp->name;
        return new_repo;
    }
    else
    {
        cout << "Repository not found." << endl;
        return NULL;
    }
}

void print_stats(nodetree* root, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        cout << "Repository name: " << temp->name << endl;
        cout << "Number of files: " << temp->files->count_files() << endl;
        cout << "Number of commits: " << temp->commits->count_commits() << endl;
    }
    else {
        cout << "Repository not found." << endl;
    }
}
};
