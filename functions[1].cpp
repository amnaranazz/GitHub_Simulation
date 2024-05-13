#include"Header.h"




nodefile::nodefile()
{
    next = NULL;
}

nodecommit::nodecommit()
{
    next = NULL;
    number = 0;
}

node_hash::node_hash()
{
    key = 0;
    username = "0";
    password = "0";
}

node_graph::node_graph()
{
    next = NULL;
}

hash_table_user::hash_table_user(int size)
{
    max_length = size;
    user_array = new node_hash[max_length];
    for (int i = 0; i < max_length; i++)
    {
        user_array[i].password = "0";
        user_array[i].username = "0";
    }
    readUserCredentials();
}

int hash_table_user::hash_key(string username)
{
    int hash_key = 0, len = 0;
    char c;
    len = username.length();
    for (int i = 0; i < len; ++i)
    {
        c = username[i];
        hash_key = hash_key * 31 + c;
    }
    return hash_key % max_length;
}


void hash_table_user::setUser(string username, string password)
{

    int array_max = max_length, key;
    key = hash_key(username);
    array_max = key;
    while (user_array[key].username != "0" && user_array[key].password != "0")
    {
        key = (key + 1) % max_length;
        if (key == array_max)
        {

            return;
        }
    }
    user_array[key].key = key;
    user_array[key].username = username;
    user_array[key].password = password;

    ofstream outFile("user_credentials.csv", ios::app);
    if (outFile.is_open())
    {
        outFile << username << "," << password << endl;
        outFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}




void hash_table_user::readUserCredentials()
{
    ifstream file("user_credentials.csv");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string username, password;
            getline(ss, username, ',');
            getline(ss, password, ',');
            setUser(username, password);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open user credentials file." << endl;
    }
}


int hash_table_user::verify_user(string username, string password)
{
    int array_max = max_length, key, i = 0;
    key = hash_key(username);
    if (user_array[key].username != username || user_array[key].password != password)
    {
        while (i < max_length && (user_array[key].username != "0" || user_array[key].username != username))
        {
            key = (key + 1) % max_length;
            i++;
        }
    }
    if (user_array[key].username == username && user_array[key].password == password)
    {
        return 1;
    }
    else
    {
        cout << "Invalid credentials" << endl;
        return -1;
    }
}



graph_list::graph_list()
{
    head = NULL;
    tail = NULL;
}


void graph_list:: insert_user(string user1)
{
    node_graph* new_user = new node_graph;
    new_user->follower_name = user1;
    new_user->next = head;
    head = new_user;
    if (tail == NULL)
    {
        tail = head;
    }
}

void graph_list::insert_follower(string user2)
{
    node_graph* new_follower = new node_graph;
    new_follower->follower_name = user2;
    new_follower->next = NULL;
    tail->next = new_follower;
    tail = new_follower;

}


void graph_list::delete_follower(string user2)
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



string graph_list::find_user()
{
    if (head != NULL)
    {
        return head->follower_name;
    }
    return "0";
}


followers::followers(int vertices)
{
    this->vertices = vertices;
    followers_array = new graph_list[vertices];
}

void followers::add_user_graph(string user)
{
    int i = 0;
    while (i < vertices && followers_array[i].find_user() != "0")
    {
        i++;
    }

    if (i < vertices)
    {
        followers_array[i].insert_user(user);
    }
}

void followers::add_follower_graph(string user1, string follower)
{
    int i = 0;
    while (i < vertices && followers_array[i].find_user() != user1)
    {
        i++;
    }

    if (i < vertices)
    {
        followers_array[i].insert_follower(follower);
        cout << "sucessfully follower inserted" << endl;
    }
    else
    {
        cout << "User not found!" << endl;
    }
}


listcommit::listcommit()
{
    head = NULL;
}

void listcommit::insert_list_commit(string data)
{
    nodecommit* new_node = new nodecommit;
    new_node->message = data;
    new_node->next = head;
    head = new_node;
}


void listcommit::delete_list_commit()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    nodecommit* temp = head;
    head = head->next;
    delete temp;
    cout << "Commit deleted" << endl;
}

int listcommit::count_commits()
{
    int count = 0;
    nodecommit* curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}


listfile::listfile()
{
    head = NULL;
}

void listfile::insert_list(string data)
{
    nodefile* new_node = new nodefile;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void listfile::deletelist()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    nodefile* temp = head;
    head = head->next;
    delete temp;
    cout << "File deleted" << endl;
}

int listfile::count_files()
{
    int count = 0;
    nodefile* curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

nodetree::nodetree()
{
    leftroot = NULL;
    rightroot = NULL;
    isprivate = false;
    commits = new listcommit();
    files = new listfile();
    height = 1;
    num_of_forks = 0;
    num_of_commits = 0;
}

repository::repository()
{
    root = NULL;
}

int repository::max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int repository::height(nodetree* node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

nodetree* repository::rightRotate(nodetree* y)
{
    nodetree* x = y->leftroot;
    nodetree* T2 = x->rightroot;

    x->rightroot = y;
    y->leftroot = T2;

    y->height = max(height(y->leftroot), height(y->rightroot)) + 1;
    x->height = max(height(x->leftroot), height(x->rightroot)) + 1;

    return x;
}

nodetree* repository::leftRotate(nodetree* x)
{
    nodetree* y = x->rightroot;
    nodetree* T2 = y->leftroot;

    y->leftroot = x;
    x->rightroot = T2;

    x->height = max(height(x->leftroot), height(x->rightroot)) + 1;
    y->height = max(height(y->leftroot), height(y->rightroot)) + 1;

    return y;
}

int repository::get_balance(nodetree* node)
{
    if (node == NULL)
        return 0;
    return height(node->rightroot) - height(node->leftroot);
}

nodetree* repository::add_repo(nodetree* root, bool privatee, string name)
{
    if (root == NULL)
    {
        nodetree* new_repo = new nodetree;
        new_repo->isprivate = privatee;
        new_repo->name = name;
        return new_repo;
    }

    if (name < root->name)
    {
        root->leftroot = add_repo(root->leftroot, privatee, name);
    }
    else if (name > root->name)
    {
        root->rightroot = add_repo(root->rightroot, privatee, name);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(height(root->leftroot), height(root->rightroot));

    int balance = get_balance(root);
    if (balance > 1 && name < root->leftroot->name)
    {
        return rightRotate(root);
    }
    if (balance < -1 && name > root->rightroot->name)
    {
        return leftRotate(root);
    }
    if (balance > 1 && name > root->leftroot->name)
    {
        root->leftroot = leftRotate(root->leftroot);
        {
            return rightRotate(root);
        }
    }
    if (balance < -1 && name < root->rightroot->name)
    {
        root->rightroot = rightRotate(root->rightroot);
        {
            return leftRotate(root);
        }
    }

    return root;
}

nodetree* repository::search_repo(nodetree* root, string name)
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

void repository::add_file_repo(nodetree* root, string data, string name)
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

void repository::delete_file_repo(nodetree* root, string name)
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

void repository::add_commit_repo(nodetree* root, string message, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        temp->commits->insert_list_commit(message);
        cout << "Commit successfully added" << endl;
    }
    else
    {
        cout << "Repository not found." << endl;
    }
}

void repository::delete_commits_repo(nodetree* root, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        temp->commits->delete_list_commit();
    }
    else
    {
        cout << "Repository not found." << endl;
    }
}

nodetree* repository::delete_repository(nodetree* root, string& name)
{
    if (root == NULL)
    {
        cout << "Repository not found." << endl;
        return root;
    }

    if (name < root->name)
    {
        root->leftroot = delete_repository(root->leftroot, name);
    }
    else if (name > root->name)
    {
        root->rightroot = delete_repository(root->rightroot, name);
    }
    else
    {
        if (root->leftroot == NULL || root->rightroot == NULL)
        {
            nodetree* temp = root->leftroot ? root->leftroot : root->rightroot;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                root = temp;
            }
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
    {
        return root;
    }

    root->height = 1 + max(height(root->leftroot), height(root->rightroot));
    int balance = get_balance(root);
    if (balance > 1 && get_balance(root->leftroot) >= 0)
    {
        return rightRotate(root);
    }
    if (balance > 1 && get_balance(root->leftroot) < 0)
    {
        root->leftroot = leftRotate(root->leftroot);
        return rightRotate(root);
    }
    if (balance < -1 && get_balance(root->rightroot) <= 0)
    {
        return leftRotate(root);
    }
    if (balance < -1 && get_balance(root->rightroot) > 0)
    {
        root->rightroot = rightRotate(root->rightroot);
        return leftRotate(root);
    }
    return root;
}

nodetree* repository::copy_repo_fork(nodetree* root, string name)
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

void repository::print_stats(nodetree* root, string name)
{
    nodetree* temp = search_repo(root, name);
    if (temp != NULL)
    {
        cout << "Repository name: " << temp->name << endl;
        cout << "Number of files: " << temp->files->count_files() << endl;
        cout << "Number of commits: " << temp->commits->count_commits() << endl;
    }
    else
    {
        cout << "Repository not found." << endl;
    }
}

nodetree* repository::minValueNode(nodetree* node)
{
    nodetree* current = node;
    while (current && current->leftroot != NULL)
        current = current->leftroot;
    return current;
}



User_git_interface::User_git_interface(int userSize)
{
    this->userSize = userSize;
    userTable = new hash_table_user(userSize);
    repo_tree_git = new repository();
    follower_git = new followers(userSize);
}



void User_git_interface::register_user_git()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    userTable->setUser(username, password);
    loggedin = true;
}

void User_git_interface::login_user()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    int result = userTable->verify_user(username, password);
    if (result == 1)
    {
        cout << "Login successful!" << endl;
        loggedin = true;
    }
    else if (result == -1)
    {
        cout << "Login failed. Invalid credentials." << endl;
    }
}

void User_git_interface::display_menu1()
{
    cout << "====== Menu ======" << endl;
    cout << "1. Add Repository" << endl;
    cout << "2. Delete Repository" << endl;
    cout << "3. Add File to Repository" << endl;
    cout << "4. Delete File from Repository" << endl;
    cout << "5. Add Commit to Repository" << endl;
    cout << "6. Delete Commit from Repository" << endl;
    cout << "7. Copy Repository (Fork)" << endl;
    cout << "8. Print Repository Stats" << endl;
    cout << "9. Logout" << endl;
    cout << "10. Exit" << endl;
}

void User_git_interface::display_menu()
{
    if (loggedin)
    {
        display_menu1();
    }
    else
    {
        cout << "====== Menu ======" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
    }
}

void User_git_interface::menu_option(int option)
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

void User_git_interface::add_repo_git()
{
    string name;
    bool isPrivate;
    cout << "Enter repository name: ";
    cin >> name;
    cout << "Is the repository private? (1 for yes, 0 for no): ";
    cin >> isPrivate;
    root = repo_tree_git->add_repo(root, isPrivate, name);
}

void User_git_interface::delete_repo_git()
{
    string name;
    cout << "Enter the name of the repository to delete: ";
    cin >> name;
    root = repo_tree_git->delete_repository(root, name);
}

void User_git_interface::add_file_repo_git()
{
    string name, data;
    cout << "Enter the name of the repository: ";
    cin >> name;
    cout << "Enter file data: ";
    cin >> data;
    repo_tree_git->add_file_repo(root, data, name);
}

void User_git_interface::delete_file_repo_git()
{
    string name;
    cout << "Enter the name of the repository: ";
    cin >> name;
    repo_tree_git->delete_file_repo(root, name);
}

void User_git_interface::add_commit_repo_git()
{
    string name, message;
    cout << "Enter the name of the repository: ";
    cin >> name;
    cout << "Enter commit message: ";
    cin >> message;
    repo_tree_git->add_commit_repo(root, message, name);
}

void User_git_interface::delete_commit_repo_git()
{
    string name;
    cout << "Enter the name of the repository: ";
    cin >> name;
    repo_tree_git->delete_commits_repo(root, name);
}

void User_git_interface::copy_rope_git()
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

void User_git_interface::print_repo_stats_git()
{
    string name;
    cout << "Enter the name of the repository: ";
    cin >> name;
    repo_tree_git->print_stats(root, name);
}

void User_git_interface::run()
{
    int option;
    while (true)
    {
        display_menu();
        cout << " please enter your choice: ";
        cin >> option;
        menu_option(option);
        system("pause");
        system("CLS");
        
    }
}

