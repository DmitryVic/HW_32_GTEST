#pragma once



class zavisim
{
private:
    int data = 0;
public:
    zavisim() = default;;
    virtual ~zavisim() {}
    virtual int kv(int x) = 0;
};

class zavisim2 : public zavisim
{
public:
    int kv(int x) override{
        return x * x;
    }
};




class my_class
{
protected:
    zavisim* _zav;
public:
    my_class(zavisim* zav): _zav(zav){}
    // Определяем реализацию деструктора
    virtual ~my_class() {
        // if (_zav != nullptr) {
        //     delete _zav;
        // }
    }

    virtual int test(int x) = 0;
};

class test_my_class : my_class
{
public:
    test_my_class(zavisim* zav) : my_class(zav){}
    
      // Реализация метода test
    int test(int x) override {
        // Проверка на nullptr перед вызовом метода
        if (_zav != nullptr) {
            return _zav->kv(x);
        }
        return 0; // или другое значение по умолчанию
    }
};
