
void add_repo_git()
{
    string name;
    bool isPrivate;
    cout << "Enter repository name: ";
    cin >> name;
    cout << "Is the repository private? (1 for yes, 0 for no): ";
    cin >> isPrivate;
    root = repo_tree_git->add_repo(root, isPrivate, name);
}

void delete_repo_git()
{
    string name;
    cout << "Enter the name of the repository to delete: ";
    cin >> name;
    root = repo_tree_git->delete_repository(root, name);
}