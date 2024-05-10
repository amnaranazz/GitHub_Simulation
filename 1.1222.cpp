
int main()
{
    repository repo;
    nodetree* root = NULL;
    root = repo.add_repo(root, false, "repo1");
    root = repo.add_repo(root, true, "repo2");
    repo.add_file_repo(root, "file1", "repo1");
    repo.add_commit_repo(root, "commit1", "repo1");
    repo.add_file_repo(root, "file2", "repo2");
    repo.add_commit_repo(root, "commit2", "repo2");
    repo.print_stats(root, "repo1");
    repo.print_stats(root, "repo2");
    repo.delete_repository(root, "repo1");
    repo.delete_repository(root, "repo2");
    return 0;
}
