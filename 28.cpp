
void add_file_repo_git()
{
    string name, data;
    cout << "Enter the name of the repository: ";
    cin >> name;
    cout << "Enter file data: ";
    cin >> data;
    repo_tree_git->add_file_repo(root, data, name);
}

void delete_file_repo_git()
{
    string name;
    cout << "Enter the name of the repository: ";
    cin >> name;
    repo_tree_git->delete_file_repo(root, name);
}