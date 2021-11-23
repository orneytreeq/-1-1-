#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <array>
#include <vector>


// 5 ËÀÁ
// 10 ÂÀÐÈÀÍÒ



/*
ÏÐÈÌÅÐ ÔÀÉËÀ note.txt ãäå õðàíÿòñÿ çàïèñè íîóòáóêîâ:

Lenovo-2183 | 12.4/123.2/1.6 | 523.123 | 39284 | 123
Apple_MacBook_Pro_16 | 12.4/123.2/1.6 | 523.123 | 39284 | 45
HUAWEI-123 | 12.4/123.2/1.6 | 523.123 | 39284 | 123
Apple_MacBook_Pro_15 | 12.4/123.2/1.6 | 523.123 | 39284 | 45

*/

using namespace std;
struct size { // ãàáàðèòíûå ðàçìåðû
    float x;
    float y;
    float z;
  };
struct LAPTOP{
  string model; // íàèìåíîâàíèå
  size s; //ðàçìåðû
  float w; // âåñ
  int price; // öåíà
  int frequency;
};


vector<string> my_split(string temp,string delim)
{
    //vector<string> arr;

    string space_delimiter = delim;
    vector<string> words{};
    temp = temp+delim;
    size_t pos = 0;
    while ((pos = temp.find(space_delimiter)) != string::npos) {
        words.push_back(temp.substr(0, pos));
        temp.erase(0, pos + space_delimiter.length());
    }
    return words;
}

void add_record_to_the_file(string FILE_PATH, LAPTOP lap)
{
    string new_line;
    new_line = lap.model + " | " + to_string(lap.s.x)+"/"+to_string(lap.s.y)+"/"+to_string(lap.s.z)+" | "+to_string(lap.w)+" | "+to_string(lap.price)+" | "+to_string(lap.frequency);
    ofstream out(FILE_PATH, std::ios_base::app | std::ios_base::out);
    out << endl << new_line;
}






vector<LAPTOP> read_laptop_file(string FILE_PATH, bool b)
{
    string temp;
    vector<LAPTOP> my_laptops;
    ifstream fi(FILE_PATH); // îêðûâàåì ôàéë äëÿ ÷òåíèÿ
    if (fi.is_open())
    {
        while (getline(fi, temp))
        {
            LAPTOP new_one;

            vector<string> words;
            words = my_split(temp, " | ");


            new_one.model = words[0];
            vector<string> size_values = my_split(words[1], "/");
            size size_for_new_one = {stof(size_values[0]),stof(size_values[1]),stof(size_values[2])};
            new_one.s = size_for_new_one;
            new_one.w = stof(words[2]);
            new_one.price = stoi(words[3]);
            new_one.frequency = stoi(words[4]);

            if ((b) && (new_one.frequency>120))
            {
                my_laptops.push_back(new_one);
                add_record_to_the_file("D:\\frequency_120.txt", new_one);
            } else
            {
                my_laptops.push_back(new_one);
            }
        }
    }
    fi.close();

    //sort(my_laptops.begin(), my_laptops.end(), less_than_key());


    return my_laptops;
}



int main()
{
    //÷èòàåì çàïèñè èç note.txt / âòîðîé àðãóìåíò true/false - ôèëüòð äëÿ ïðîöåññîðà
    vector<LAPTOP> my_laptops = read_laptop_file("D:\\note.txt",true);// âòîðîé àðãóìåíò - ôëàã äëÿ çàïèñè òîëüêî ñ ÷àñòîòîé > 120ìãö

    //Ñîçäàåì íîâóþ çàïèñü íîóòáóêà, ÷òîáû ïîòîì äîáàâèòü:
    LAPTOP my_new_laptop;
    my_new_laptop.model = "ggg312";
    size my_new_laptop_size = {12.2, 12.2, 12.2};
    my_new_laptop.s = my_new_laptop_size;
    my_new_laptop.w = 44;
    my_new_laptop.price = 213;
    my_new_laptop.frequency = 23;


    //äîáàâëÿåì:
    add_record_to_the_file("D:\\note.txt", my_new_laptop);


    cout << "End of program" << endl;
    return 0;

}
