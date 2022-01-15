#include <iostream>
#include "User.h"

// file "User.h":
/*
#include <iostream>
using namespace std;

namespace N
{
    class User // ������������ ������ ��� Pharmacist � Buyer
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
	    bool _is_online; // ��������� �� ������������ ������
	};

}

*/
using namespace N;

using namespace std;


//LAB-6 �������-10

/*
���������� ������� ������-������:

������� ������� � ������-������, ��������������, ������ ���������� ������
�������� ������� (Pharmacy_receipt) ������� ��������� ���� ������� (array of Product) ����������� � ������ ������ �� ������� (request_on_purchcase),
�������� ������, ������� ��� ��� ������
��������� ��������� ������� ������� � ��������� �������


����������� ����������� � �������� ������������ ����������� � ������ Pharmacy_receipt

*/

struct Bank_card_info // ���������� ����������
{
    string card_number;
    string expiration_date;
    string security_code;
};












class Product // ��������� � ������, ������� ��������� ����� �������
{
public:
    Product(string name, unsigned q)
    {
        _name = name;
        change_quantity(q);
    }

    void change_quantity(unsigned new_num) // �������� ���-�� ������ � �������
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

















class Pharmacy_receipt // ������
{
public:

    Pharmacy_receipt(string disease = "none", Product *product_list = {})
    {
        _disease = disease;
        _products_to_buy = product_list;
    }
    Pharmacy_receipt(const Pharmacy_receipt &obj) // ����������� ����������� ������� ���������� ������ �� ������� ��� ������������� (����� ��������� ��� ������� ������������ ������)
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


    Pharmacy_receipt & operator = (const Pharmacy_receipt & other) // ������������� ��������� ������������
    {
        if (this != &other) // ������ �� ������������� ����������������
        {

            // ����������� "������" ������
            delete [] _products_to_buy;

            // ����������� �������� � "�����" ������ �������
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
    string _disease; // �����������
    string _doctor_name; // ��� �����, ������������ ������
    string _date; // ���� ���������� �������
    Product *_products_to_buy; // ������ �������� ��� �������
    string _note; // �������������� ������� � ������� (�����������)
};





class Buyer : public User // ����������. ��� ����� ��������� ������ (add_receipt), �� ����� ����������� ��������� �������, ����������� � ���������� (buy)
                          // ���� ��������� ������� �������, �� ��� ����� ���������
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











class Pharmacist : public User // ���������. ��������� ������� �� ������� (request_on_purshcase)
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
    Product nurofen("nurofen", 5); //������� ��������� � �� ���������� � �������
    Product kagocel("kagocel", 5);
    Product mixidil("mixidil", 5);

    Product arr_of_products[] = {nurofen, kagocel, mixidil};
    Pharmacy_receipt receipt_for_headache("headache",arr_of_products); // ������� ������, ������� �������� ��������� ��� �������

    Buyer Brendon(1, "Brendon", "+79097836723", {"1234 5678 9101 1121","12/12/12","564"}); // ������������ ������ ������������ ������ � ��� ����������� �������
    Brendon.add_receipt(receipt_for_headache);

    Pharmacist worker_1; // ������� ����������

    worker_1.request_on_purshcase(Brendon); // ������������ �������� ������ �� ������� � ���� ��� ������, �� ��������� ��������� �������





    return 0;
}
