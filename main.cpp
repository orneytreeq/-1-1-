#include <iostream>
#include "User.h"

// file "User.h":
/*
#include <iostream>
using namespace std;

namespace N
{
    class User // Родительский объект для Pharmacist и Buyer
{
	public:
	    void set_user_info(unsigned id, string username, string phone_number)
	    {
	        _id = id;
	        _username = username;
	        _phone_number = phone_number;
	        _is_verified = true;
	    }
	bool _is_verified;

	private:
	    unsigned _id;
	    string _username;
	    string _phone_number;
	    string _city;
	    bool _is_online; // находится ли пользователь онлайн
	};

}

*/
using namespace N;

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












class Product // ëåêàðñòâî â àïòåêå, êîòîðîå ôàðìàöåâò ìîæåò ïðîäàòü
{
public:
    Product(string name, unsigned q)
    {
        _name = name;
        change_quantity(q);
    }

    void change_quantity(unsigned new_num) // èçìåíèòü êîë-âî òîâàðà â íàëè÷èè
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

    string get_name()
    {
        return _name;
    }

private:
    string _name;
    string _description;
    unsigned quantity;
    bool in_stock;
};

















class Pharmacy_receipt // ðåöåïò
{
public:

    Pharmacy_receipt(string disease = "none", Product *product_list = {})
    {
        _disease = disease;
        _products_to_buy = product_list;
    }
    Pharmacy_receipt(const Pharmacy_receipt &obj) // êîíñòðóêòîð êîïèðîâàíèÿ ñîçäàåò èäåíòè÷íûé ðåöåïò íà ïðèìåðå óæå ñóùåñòâóþùåãî (÷òîáû íàçíà÷èòü åãî äðóãîìó ïîëüçîâàòåëþ àïòåêè)
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


    Pharmacy_receipt & operator = (const Pharmacy_receipt & other) // èñïîëüçîâàíèå îïåðàòîðà ïðèñâàèâàíèÿ
    {
        if (this != &other) // çàùèòà îò íåïðàâèëüíîãî ñàìîïðèñâàèâàíèÿ
        {

            // îñâîáîæäàåì "ñòàðóþ" ïàìÿòü
            delete [] _products_to_buy;

            // ïðèñâàèâàåì çíà÷åíèÿ â "íîâîé" ïàìÿòè îáúåêòó
            for (int i = 0; i < 10.; ++i)
            {
                _products_to_buy[i] = other._products_to_buy[i];
            }


        }

        // ...

        return *this;
    }


    Product * get_prodcuts_from_receipt()
    {
        return _products_to_buy;
    }

private:
    string _disease; // çàáîëåâàíèå
    string _doctor_name; // èìÿ âðà÷à, íàçíà÷èâøåãî ðåöåïò
    string _date; // äàòà íàçíà÷åíèÿ ðåöåïòà
    Product *_products_to_buy; // ìàññèâ ëåêàðñòâ äëÿ ïîêóïêè
    string _note; // äîïîëíèòåëüíûå çàìåòêè ê ðåöåïòó (îïöèîíàëüíî)
};





class Buyer : public User // Ïîêóïàòåëü. Åìó ìîãóò íàçíà÷èòü ðåöåïò (add_receipt), îí ìîæåò ïîïðîáîâàòü ñîâåðøèòü ïîêóïêó, îáðàòèâøèñü ê ôàðìàöåâòó (buy)
                          // Åñëè ôàðìàöåâò îäîáðèò ïîêóïêó, òî îíà áóäåò ñîâåðøåíà
{
public:

    Buyer(unsigned id, string username, string phone_number, Bank_card_info bank_info)
    {
        User::set_user_info(id, username, phone_number);
        _bank_info = bank_info;

    }

    void add_receipt(Pharmacy_receipt receipt_to_add)
    {
        current_receipt = receipt_to_add;
    }


    Pharmacy_receipt get_current_receipt()
    {
        return current_receipt;
    }

private:
    Bank_card_info _bank_info;
    Pharmacy_receipt current_receipt;
};











class Pharmacist : public User // Ôàðìàöåâò. Ïðèíèìàåò çàïðîñû íà ïîêóïêó (request_on_purshcase)
{
public:
    void request_on_purshcase(Buyer client)
    {
        if (client._is_verified)
        {
            make_purchcase(client);
        }
    }

    void make_purchcase(Buyer client)
    {
        for (int i=0;i<10;i++)
        {
            cout << "You bought: " + client.get_current_receipt().get_prodcuts_from_receipt()[i].get_name() << endl;
        }
    }
private:

};



























int main()
{
    Product nurofen("nurofen", 5); //создаем лекарства и их количество в наличии
    Product kagocel("kagocel", 5);
    Product mixidil("mixidil", 5);

    Product arr_of_products[] = {nurofen, kagocel, mixidil};
    Pharmacy_receipt receipt_for_headache("headache",arr_of_products); // создаем рецепт, который содержит лекарства для покупки

    Buyer Brendon(1, "Brendon", "+79097836723", {"1234 5678 9101 1121","12/12/12","564"}); // регистрируем нового пользователя аптеки с его банковскими данными
    Brendon.add_receipt(receipt_for_headache);

    Pharmacist worker_1; // Ñîçäàåì ôàðìàöåâòà

    worker_1.request_on_purshcase(Brendon); // пользователь посылает запрос на покупку и если все хорошо, то фармацевт совершает покупку





    return 0;
}
