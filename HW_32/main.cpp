#include "my_class.h"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Имитация работы!" << endl;
    int x = 5;
    DBConnection* DB = new DBConnectionMySQL();
    ChatBotStat t(DB);
    cout << "Подключение: " << t.openConnection() << endl;
    cout << "Результат: " << t.useConnection(x) << endl;
    cout << "Закрываю соединение: " << t.closeConnection() << endl;
    delete DB;
    
    return 0;
}
