#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void WriteBinTextFileforshort(unsigned short QWE[4][16], const char* fileName) {
    ofstream Pew("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            Pew.write((const char*)&QWE[i][j], sizeof(unsigned short));
        }
    }
    Pew.close();

}
int ConsoleInputText( char Text[4][16], const char* fileName)
{
    int i, j;
    cout << "input text: " << '\n';
    for (i = 0; i < 4; i++) {
        cin.getline(Text[i], 16);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            if (Text[i][j] == '\0') {
                for (int k = j; k < 16; k++) {
                    Text[i][k] = ' ';
                }
            }
        }
    }
    return 1;
}
void WriteArrayTextFileFor1and3Task(int a, const char* fileName)
{
    ofstream fout(fileName);
        fout << a << " ";
    fout.close(); 
}
void WriteArrayTextFileForChar(char A[4][16], const char* fileName)
{
    ofstream fout(fileName);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            fout << A[i][j] << "  ";
            fout.close();
        }
    }
}


void  ReadArrayTextFileForChar(char A[4][16],const char* fileName)
{
    ifstream fin(fileName);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            fin >>A[i][j];
            fin.close(); 
        }
    }
}
void ReadBinFile( char QWE[4][16], const char* fileName) {
    ifstream Pew("binary.dat", ios::in | ios::binary);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            Pew.read((char*)&QWE[i][j], sizeof(char));
        }
    }
    Pew.close();
    return;
}
void task1() {
    int a, b, c, d;
cout << "Enter a:";
cin >> a;
 WriteArrayTextFileFor1and3Task(a, "firstnumber.txt");
cout << "Enter b:";
cin >> b;
 WriteArrayTextFileFor1and3Task(b, "secondnumber.txt");
cout << "Enter c:";
cin >> c;
 WriteArrayTextFileFor1and3Task(c, "thirdnumber.txt");
cout << "Enter d:";
cin >> d;
WriteArrayTextFileFor1and3Task(d, "fourthnumber.txt");
int result = (b << 10) + ((d << 5) - ((a << 3) + (a << 2)) >> 9) - ((c << 12) + c) + ((d << 3) + d);
WriteArrayTextFileFor1and3Task(result, "Answerfor1taskforx.txt");
cout << result<<endl;

int result1 = 1024 * b + ((32 * d - (8 * a + 4 * a)) / 512) - (4096 * c + c) + (8 * d + d);
cout << result1 << endl;
return;
}

void task2()
{
     char Text[4][16];
    unsigned short Res[4][16];
    unsigned short i, j, z, x, c, sf, ez;

    ConsoleInputText(Text);

    // Доповнення рядків пробілами до 16 символів
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            if (Text[i][j] == '\0') {
                for (; j < 16; j++) {
                    Text[i][j] = ' ';
                }
                break;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            // Молодша частина ASCII коду символу (4 біти)
            z = Text[i][j] & 0x0F;
            // Номер рядка (2 біти)
            z |= (i & 0x03) << 4;
            // Позиція символу в рядку (4 біти)
            z |= (j & 0x0F) << 6;
            // Старша частина ASCII коду символу (4 біти)
            z |= (Text[i][j] & 0xF0) << 6;

            // Біт парності полів 4-9
            c = 0;
            ez = 0x10; // Починаємо з 4-го біта
            for (sf = 4; sf <= 9; sf++) {
                if (z & ez) c ^= 1;
                ez <<= 1;
            }
            if (c == 1) z |= 1 << 14;

            // Біт парності коду символу
            c = 0;
            ez = 1; // Починаємо з 0-го біта
            for (sf = 0; sf < 16; sf++) {
                if (Text[i][j] & ez) c ^= 1;
                ez <<= 1;
            }
            if (c == 1) z |= 1 << 15;

            // Збереження результату
            Res[i][j] = z;
        }
    }

    // Вивід зашифрованого тексту і запис у файл
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 16; j++) {
            bitset<16> qwe(Res[i][j]);
            cout << qwe << endl;
        }
    }

    WriteBinTextFileforshort(Res, "Writetask2.bin");

    return;

}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


