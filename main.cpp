#include <iostream>

using namespace std;


//LAB-6 Вариант-10

/*
Предметная область онлайн-аптеки:

Человек заходит в онлайн-аптеку, регистрируется, вводит банковские данные
Согласно рецепту (Pharmacy_receipt) человек пополняет свою корзину (array of Product) лекарствами и делает запрос на покупку (request_on_purchcase),
прилагая рецепт, который ему дал доктор
Фармацевт проверяет наличие рецепта и совершает покупку


конструктор копирования и оператор присваивания реализованы в классе Pharmacy_receipt

*/

struct Bank_card_info // Банковская информация
{
    string card_number;
    string expiration_date;
    string security_code;
};












class Product // лекарство в аптеке, которое фармацевт может продать
{
public:
    Product()
    {
        //...
    }

    void change_quantity(unsigned new_num) // изменить кол-во товара в наличии
    {
        if (new_num==0)
        {
            in_stock = false;
            quantity = 0;
        } else
        {
            in_stock = true;
            quantity = new_num;
        }

    }

private:
    string _name;
    string _description;
    unsigned quantity;
    bool in_stock;
};













class Pharmacy_receipt // рецепт
{
public:
    Pharmacy_receipt(string desease, string doctor_name, string date, string products_to_buy, string note)
    {
        //...
        //обычный конструктор
        //...
    }
    Pharmacy_receipt(const Pharmacy_receipt &obj) // конструктор копирования создает идентичный рецепт на примере уже существующего (чтобы назначить его другому пользователю аптеки)
    {
        _disease = obj._disease;
        _doctor_name = obj._doctor_name;
        _date = obj._date;
        for (int i = 0; i < 10.; ++i)
        {
            _products_to_buy[i] = obj._products_to_buy[i];
        }
        _note = obj._note;
    }


    Pharmacy_receipt & operator = (const Pharmacy_receipt & other) // использование оператора присваивания
    {
        if (this != &other) // защита от неправильного самоприсваивания
        {

            // освобождаем "старую" память
            delete [] _products_to_buy;

            // присваиваем значения в "новой" памяти объекту
            for (int i = 0; i < 10.; ++i)
            {
                _products_to_buy[i] = other._products_to_buy[i];
            }


        }

        // ...

        return *this;
    }

private:
    string _disease; // заболевание
    string _doctor_name; // имя врача, назначившего рецепт
    string _date; // дата назначения рецепта
    Product _products_to_buy[10]; // массив лекарств для покупки
    string _note; // дополнительные заметки к рецепту (опционально)
};













class User // Родительский объект для Pharmacist и Buyer
{
public:
    long long get_id()
    {
        return _id;
    }
private:
    long long _id;
    string _username;
    string _phone_number;
    string _city;
    bool _is_online; // находится ли пользователь онлайн
    bool _is_verified; // подтвержден ли аккаунт пользователя через СМС
};










class Pharmacist : public User // Фармацевт. Принимает запросы на покупку (request_on_purshcase)
{
public:
    void request_on_purshcase(Pharmacy_receipt request_receipt, string note)
    {
        // если запрос на покупку содержит рецепт -> совершить покупку согласно рецепту

        // если запрос не покупку не содержит рецепт -> создать рецепт согласно note и совершить покупку:

        /*
            if (request_receipt)
                make_purchcase(request_receipt, user_id);
            else
                make_purchcase(create_receipt(note), user_id);
        */
    }

    void make_purchcase(long long user_id, Pharmacy_receipt products)
    {
        //... денежный перевод аптеке ... совершение доставки лекарств на дом ...
    }
private:

};








class Buyer : public User // Покупатель. Ему могут назначить рецепт (add_receipt), он может попробовать совершить покупку, обратившись к фармацевту (buy)
                          // Если фармацевт одобрит покупку, то она будет совершена
{
public:
    void add_receipt(Pharmacy_receipt receipt_to_add)
    {
        current_receipt = receipt_to_add;
    }

    void buy(Pharmacist seller)
    {
        seller.request_on_purshcase(current_receipt,"меня беспокоит ...");
    }

private:
    Bank_card_info _bank_info;
    string doctor; // лечащий врач (опционально)
    Pharmacy_receipt current_receipt;
};





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
