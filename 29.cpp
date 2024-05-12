
void add_commit_repo_git()
{
    string name, message;
    cout << "Enter the name of the repository: ";
    cin >> name;
    cout << "Enter commit message: ";
    cin >> message;
    repo_tree_git->add_commit_repo(root, message, name);
}

void delete_commit_repo_git()
{
    string name;
    cout << "Enter the name of the repository: ";
    cin >> name;
    repo_tree_git->delete_commits_repo(root, name);
}

void copy_rope_git()
{
    string name;
    cout << "Enter the name of the repository to copy: ";
    cin >> name;
    nodetree* newRepo = repo_tree_git->copy_repo_fork(root, name);
    if (newRepo != NULL)
    {
        cout << "Repository copied successfully!" << endl;
    }
}