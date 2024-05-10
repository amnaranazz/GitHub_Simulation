
nodetree* add_repo(nodetree* root, bool privatee, string name)
{
    if (root == nullptr)
    {
        nodetree* new_repo = new nodetree;
        new_repo->isprivate = privatee;
        new_repo->name = name;
        return new_repo;
    }

    if (name < root->name)
        root->leftroot = add_repo(root->leftroot, privatee, name);
    else if (name > root->name)
        root->rightroot = add_repo(root->rightroot, privatee, name);
    else
        return root;

    root->height = 1 + max(height(root->leftroot), height(root->rightroot));

    int balance = get_balance(root);
    if (balance > 1 && name < root->leftroot->name)
        return rightRotate(root);
    if (balance < -1 && name > root->rightroot->name)
        return leftRotate(root);
    if (balance > 1 && name > root->leftroot->name)
    {
        root->leftroot = leftRotate(root->leftroot);
        return rightRotate(root);
    }
    if (balance < -1 && name < root->rightroot->name)
    {
        root->rightroot = rightRotate(root->rightroot);
        return leftRotate(root);
    }

    return root;
}