#include "my_class.h"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    cout << "Имитация работы!" << endl;
    int x = 5;
    DBConnection* DB = new DBConnectionMySQL();
    ChatBotStat t(DB);
    cout << "main Result: " << t.useConnection(x) << endl;
    delete DB;
    
    return 0;
}
