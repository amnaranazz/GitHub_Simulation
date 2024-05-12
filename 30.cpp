void print_repo_stats_git()
{
    string name;
    cout << "Enter the name of the repository: ";
    cin >> name;
    repo_tree_git->print_stats(root, name);
}

void run()
{
    int option;
    while (true)
    {
        display_menu();
        cout << " please enter your choice: ";
        cin >> option;
        menu_option(option);
    }
}
};