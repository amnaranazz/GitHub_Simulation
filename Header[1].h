#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

class nodefile
{
public:
    nodefile* next;
    string data;

    nodefile();
};

class nodecommit
{
public:
    nodecommit* next;
    string message;
    int number;

    nodecommit();
};

class node_hash
{
public:
    int key;
    string username;
    string password;
    node_hash();
};

class node_graph
{
public:
    node_graph* next;
    string follower_name;
    node_graph();
};
class hash_table_user
{
private:
    node_hash* user_array;
    int max_length;
    int length;

public:
    hash_table_user(int size);
    int hash_key(string username);
    void setUser(string username, string password);
    void readUserCredentials();

    int verify_user(string username, string password);
};



class graph_list
{
private:
    node_graph* head;
    node_graph* tail;

public:
    graph_list();

    void insert_user(string user1);

    void insert_follower(string user2);

    void delete_follower(string user2);

    string find_user();
};

class followers
{
private:
    graph_list* followers_array;
    int vertices;

public:
    followers(int vertices);

    void add_user_graph(string user);

    void add_follower_graph(string user1, string follower);
};

class listcommit
{
private:
    nodecommit* head;

public:
    listcommit();

    void insert_list_commit(string data);

    void delete_list_commit();

    int count_commits();
};

class listfile
{
private:
    nodefile* head;

public:
    listfile();

    void insert_list(string data);

    void deletelist();

    int count_files();
};

class nodetree
{
public:
    nodetree* leftroot;
    nodetree* rightroot;
    bool isprivate;
    string name;
    int num_of_commits;
    int num_of_forks;
    listcommit* commits;
    listfile* files;
    int height;

    nodetree();
};

class repository
{
private:
    nodetree* root;

public:
    repository();

    int max(int a, int b);

    int height(nodetree* node);

    nodetree* rightRotate(nodetree* y);

    nodetree* leftRotate(nodetree* x);

    int get_balance(nodetree* node);

    nodetree* add_repo(nodetree* root, bool privatee, string name);

    nodetree* search_repo(nodetree* root, string name);

    void add_file_repo(nodetree* root, string data, string name);

    void delete_file_repo(nodetree* root, string name);

    void add_commit_repo(nodetree* root, string message, string name);

    void delete_commits_repo(nodetree* root, string name);

    nodetree* delete_repository(nodetree* root, string& name);

    nodetree* copy_repo_fork(nodetree* root, string name);

    void print_stats(nodetree* root, string name);

    nodetree* minValueNode(nodetree* node);

};

class User_git_interface
{
private:
    hash_table_user* userTable;
    repository* repo_tree_git;
    followers* follower_git;
    nodetree* root = NULL;
    int userSize;
    bool loggedin = false;

public:
    User_git_interface(int userSize);

    void register_user_git();

    void login_user();

    void display_menu1();

    void display_menu();

    void menu_option(int option);

    void add_repo_git();

    void delete_repo_git();

    void add_file_repo_git();

    void delete_file_repo_git();

    void add_commit_repo_git();

    void delete_commit_repo_git();

    void copy_rope_git();

    void print_repo_stats_git();

    void run();
};

