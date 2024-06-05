#include <iostream>
#include <string>
using namespace std;

char* mas = new char[50];
char* arr = new char[50];

int sizes = strlen(mas);


void Result();

char* overwriting(char arr1[], int index, int index1, string res) {
    int size = strlen(arr1);
    char* mas1 = new char[size];
    for (int i = 0; i < index; i++)
    {
        mas1[i] = arr1[i];
    }
    mas1[index] = '\0';
    strcat(mas1, res.c_str());
    for (int i = index + res.size(); i < size; i++, index1++)
    {
        mas1[i] = arr1[index1];
    }
    delete[]arr1;
    return mas1;
}


int CountZnak(int size, char z) {
    int kol = 0;
    for (int i = 0; i < size; i++)
    {
        if (mas[i] == z)
            kol++;
    }
    return kol;
}


int Znak(int size, char a) {
    int x;
    bool nal = false;
    for (int i = 0; i < size; i++)
    {
        if (mas[i] == a)
        {
            x = i;
            break;
            nal = true;
        }
    }
    if (nal = true)
        return x;
    else
        return 0;
}


int Znaknd(int size, char a, char b) {
    int x;
    bool nal = false;
    for (int i = 0; i < size; i++)
    {
        if (mas[i] == a or mas[i] == b)
        {
            x = i;
            nal = true;
            break;
        }
    }
    if (nal = true)
        return x;
    else
        return 0;
}


int Count(char znak, int numb1, int numb2) {
    int res;
    if (znak == '+')
        res = numb1 + numb2;
    else if (znak == '-')
        res = numb1 - numb2;
    else if (znak == '*')
        res = numb1 * numb2;
    else if (znak == '/')
        res = numb1 / numb2;
    else if (znak == ' ^')
        res = pow(numb1, numb2);
    return res;
}


char* Numbers(int i) {
    string numb2;
    string numb1;
    int x = i + 1;
    int y = i - 1;
    while (mas[x] != '*' and mas[x] != '/' and mas[x] != '+' and mas[x] != '-' and mas[x] != ')' and x < strlen(mas))
    {
        numb2 += mas[x];
        x++;
    }
    int right_number = stoi(numb2);
    while (mas[y] != '*' and mas[y] != '/' and mas[y] != '+' and mas[y] != '-' and mas[y] != '(' and y >= 0)
    {
        numb1 += mas[y];
        y--;
    }
    reverse(numb1.begin(), numb1.end());
    int left_number = stoi(numb1);
    int res = Count(mas[i], left_number, right_number);
    string ch_res = to_string(res);
    mas = overwriting(mas, y + 1, x, ch_res);
    return mas;
}
void Scobky(int start, int end) {
    int size = 0;
    string res;
    for (int i = start + 1; i < end; i++)
    {
        size++;
    }
    int start1 = start + 1;
    for (int i = 0; i < size; i++, start1++)
    {
        mas[i] = arr[start1];
    }
    Result();
    for (int i = 0; i < strlen(mas); i++)
    {
        res += mas[i];
    }
    arr = overwriting(arr, start, end + 1, res);
    /*int kol_open = 0;
    int kol_close = 0;
    for (size_t i = *start; i < *end; i++)
    {
        if (mas[i] == '(')
        {
            *start = i;
        }
        else if (mas[i] == ')')
        {
            *end = i;
            break;
        }
    }*/
}

void Result() {
    string res;
    int size_arr = strlen(mas);
    int kol_mult = CountZnak(size_arr, '*');
    int kol_div = CountZnak(size_arr, '/');
    int kol_pluse = CountZnak(size_arr, '+');
    int kol_minus = CountZnak(size_arr, '-');

    int second_action = CountZnak(size_arr, '^');
    int third_action = kol_mult + kol_div;
    int fourth_action = kol_pluse + kol_minus;
    if (second_action != 0)
    {
        for (int i = 0; i < second_action; i++)
        {
            int znak = Znak(size_arr, '^');
            mas = Numbers(znak);
            size_arr = strlen(mas);
        }
    }
    if (third_action != 0)
    {
        for (int i = 0; i < third_action; i++)
        {

            int znak = Znaknd(size_arr, '*', '/');
            mas = Numbers(znak);
            size_arr = strlen(mas);
        }
    }
    if (fourth_action != 0)
    {
        for (int i = 0; i < fourth_action; i++)
        {
            int znak = Znaknd(size_arr, '-', '+');
            mas = Numbers(znak);
            size_arr = strlen(mas);
        }
    }
}
int main()
{
    cin >> arr;
    bool t = true;
    int size = strlen(arr);
    int start;
    int end;
    int scobki = 0;
    string res;
    int size_arrrrrr = strlen(arr);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == '(')
        {
            start = i;
            t = false;
            break;
        }
    }
    if (t == false)
    {
        for (int i = start; i < size; i++)
        {
            if (arr[i] == '(')
                start = i;
            else if (arr[i] == ')')
            {
                end = i;
                Scobky(start, end);
                break;
            }
        }
    }

    for (int i = 0; i < strlen(arr); i++)
    {
        mas[i] = arr[i];
    }
    delete[] arr;
    Result();
    for (int i = 0; i < strlen(mas); i++)
    {
        cout << mas[i];
    }
}