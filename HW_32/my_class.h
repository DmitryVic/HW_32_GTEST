#pragma once
#include <iostream>


class DBConnection
{
protected:
    int data = 0;
   
public:
    DBConnection() = default;
    virtual ~DBConnection() {}
    virtual int execQuery(int x) = 0;
    virtual bool open() = 0;
    virtual void close() = 0;
};

class DBConnectionMySQL : public DBConnection
{
public:
    ~DBConnectionMySQL() override {
        close();
    }
    int execQuery(int x) override{
        return x * x;
    }
    bool open() override{
        return true;
    }

    void close() override{
        std::cout << "close\n";
    }
};




class ClassThatUseDb
{
protected:
    DBConnection* _con;
public:
    ClassThatUseDb(DBConnection* con): _con(con){}

    virtual ~ClassThatUseDb() {
    }

    virtual int useConnection(int x) = 0;
    virtual bool openConnection() = 0;
    virtual bool closeConnection() = 0;
};

class ChatBotStat : ClassThatUseDb
{
public:
    ChatBotStat(DBConnection* con) : ClassThatUseDb(con){}
    
    int useConnection(int x) override {
        if (_con != nullptr) {
            return _con->execQuery(x);
        }
        return 0;
    }

    
    bool openConnection() override{
        if (_con != nullptr) {
            return _con->open();
        }
        else
        {
            /* подключение */
            return true;
        }
    }

    bool closeConnection() override{
        return true;
    }

};
