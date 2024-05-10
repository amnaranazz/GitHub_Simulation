
int count_files()
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

    nodetree()
    {
        leftroot = NULL;
        rightroot = NULL;
        isprivate = false;
        commits = new listcommit();
        files = new listfile();
    }
};