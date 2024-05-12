void display_menu1()
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

void display_menu()
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