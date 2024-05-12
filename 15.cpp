         }
         void setUser(string username, string password)
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