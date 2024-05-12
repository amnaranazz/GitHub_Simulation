
void menu_option(int option)
{
    if (loggedin)
    {
        switch (option)
        {
        case 1:
            add_repo_git();
            break;
        case 2:
            delete_repo_git();
            break;
        case 3:
            add_file_repo_git();
            break;
        case 4:
            delete_file_repo_git();
            break;
        case 5:
            add_commit_repo_git();
            break;
        case 6:
            delete_commit_repo_git();
            break;
        case 7:
            copy_rope_git();
            break;
        case 8:
            print_repo_stats_git();
            break;
        case 9:
            loggedin = false;
            break;
        case 10:
            cout << "Exiting program. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
    else
    {
        switch (option)
        {
        case 1:
            register_user_git();
            break;
        case 2:
            login_user();
            break;
        case 3:
            cout << "Exiting program. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
}