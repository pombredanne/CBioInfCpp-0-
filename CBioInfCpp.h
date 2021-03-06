// ���㬥��� CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf (�� 㪠����� 䠩�� ࠧ��饭� � �����饬 ��⠫���) ��⠢���� ᮡ�� ���� �ந��������, ���஥ �����࠭���� �� �᫮���� ��業��� Creative Commons Attribution 4.0 International Public License (᮪�饭�� - CC BY, �������뫪� �� ⥪�� ��業���: https://creativecommons.org/licenses/by/4.0/legalcode.ru).

// ���� CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf - ��୮�客 ��ࣥ� (chernouhov@rambler.ru)

// The documents About_CBioInfCpp.pdf, CBioInfCpp.h, About_CBioInfCpp.rtf (all of them are placed in this directory) constitute a single Work (i.e. this Work is divided into these 3 files), and this Work is distributed under Creative Commons Attribution 4.0 International Public License (CC BY) (hyperlink to the License: https://creativecommons.org/licenses/by/4.0/legalcode.ru).

// CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf are written by Sergey Chernouhov (chernouhov@rambler.ru).

#ifndef CBIOINFCPP_H
#define CBIOINFCPP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <limits.h>
#include <float.h>


int FastaRead (std::ifstream & fin, std::vector <std::string> & IndexS, std::vector <std::string> & DataS)

// �⥭�� ��ப FASTA �� 䠩��. �����頥� 0, �᫨ ���-�� �����ᮢ ��ப ࠢ�� ���-�� ᠬ�� ��ப, ᠬ�� ��ࢠ� ��ப� ���� �����ᮬ (�� ��稭����� � ">") � � ����� ���뢠��� �� ����⨫��� 2 ������ �����. ���� ��୥� -1.

// Reads FASTA dataset from file. Returns 0 if the number of indexes of strings = number of strings, the first string in dataset is index (starts with ">") and in dataset there is no 2 indexes one-by-one without a data string in between. Otherwise returns -1.


{
IndexS.clear();
// � ���� �����뢠���� ������� (������祭��) ��ப
// Here indexes of strings will be contained

DataS.clear();
// � ���� �����뢠���� ᠬ� ��ப�
// Here data strings will be contained

std::string TempS = "";

int q = -1;

char f = 'd';
// 䫠� f = 'd'(data) ��� 'i' (������) - ��� �᪫�祭�� ���樨 ����� ����� ���� 2 ������
// flag f may be set as 'd' (data) or 'i' (index) - to prevent code-after-code situation.


while (!fin.eof())
    {
       TempS.clear();
       getline (fin, TempS);
       if (TempS[0] == '>')
        {
           if (f == 'i') {IndexS.clear(); DataS.clear(); return -1;}
           q++;
           f = 'i';
           DataS.push_back("");
           TempS.erase(0,1); // ��१���� ��砫쭮�� ᨬ���� ">"  cutting symbol ">" from string's code
           IndexS.push_back(TempS);
        }
        else
        {
            if (q==-1) return -1;
            if (TempS.length() !=0) {DataS[q] = DataS[q] + TempS; f = 'd';};
        }

   }

        if (DataS.size()!=IndexS.size()) {IndexS.clear(); DataS.clear(); return -1;}

return 0;
}

void StringsRead (std::ifstream & fin, std::vector <std::string> & DataS) // reads all strings from file to vector DataS

{
   std::string TempS = "";
    while (!fin.eof())
    {
        getline (fin, TempS);
        if (TempS.length()!=0) DataS.push_back(TempS);
        TempS.clear();
}

}

int MatrixSet (std::vector <std::vector <double>> & B, const int NLines, const int NColumns, const double i)
// ������� ������ NLines � NColumns � �������� ���祭��� i (double). �����頥� -1 �᫨ �᫮ ��ப ��� �⮫�殢 ��������⥫쭮
// Sets (resets) matrix NLines x NColumns filled value "i" (double). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }

    }
    return 0;
}


int MatrixSet (std::vector <std::vector <int>> & B, const int NLines, const int NColumns, const int i)
// ������� ������ NLines � NColumns � �������� ���祭��� i (int). �����頥� -1 �᫨ �᫮ ��ப ��� �⮫�殢 ��������⥫쭮
// Sets (resets) matrix NLines x NColumns filled value "i" (int). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }
    }
    return 0;
}



int MatrixSet (std::vector <std::vector <long long int>> & B, const int NLines, const int NColumns, const long long int i)
// ������� ������ NLines � NColumns � �������� ���祭��� i (long long int). �����頥� -1 �᫨ �᫮ ��ப ��� �⮫�殢 ��������⥫쭮
// Sets (resets) matrix NLines x NColumns filled value "i" (long long int). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }
    }
    return 0;
}




int MatrixSet (std::vector <std::vector <long double>> & B, const int NLines, const int NColumns, const long double i)
// ������� ������ NLines � NColumns � �������� ���祭��� i (long double). �����頥� -1 �᫨ �᫮ ��ப ��� �⮫�殢 ��������⥫쭮
// Sets (resets) matrix NLines x NColumns filled value "i" (long double). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }

    }
    return 0;
}




int MatrixCout (std::vector <std::vector <int>> & B, char g = ' ')
// �뢮� ������ (int) �� ��࠭ �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// "Couts" Matrix (int) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.

{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;



    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }
    return 0;
}



int MatrixCout (std::vector <std::vector <long long int>> & B, char g = ' ')
// �뢮� ������ (long long int) �� ��࠭ �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// "Couts" Matrix (long long int) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.

{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;



    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }
    return 0;
}


int MatrixCout (std::vector <std::vector <double>> & B, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// �뢮� ������ (double) �� ��࠭ �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Couts" Matrix (double) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
   {
    std::cout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }

    }


    if (scientifique)
    {


        for (unsigned int row = 0; (row< NLines); row++)
        {

            //for (unsigned int column = 0; column < NColumns; column++)
            for (unsigned int column = 0; column < B[row].size(); column++)
                {
                    std::cout<< std::scientific << B [row] [column]<< " ";
                }

            std::cout.unsetf(std::ios::scientific);

            for (unsigned int column = B[row].size(); column < NColumns; column++)
                {
                    std::cout<< g << " ";
                }


            std::cout<< std::endl;
        }

    }


    return 0;
}


int MatrixCout (std::vector <std::vector <long double>> & B, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// �뢮� ������ (long double) �� ��࠭ �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Couts" Matrix (long double) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
   {
    std::cout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }

    }


    if (scientifique)
    {


        for (unsigned int row = 0; (row< NLines); row++)
        {

            //for (unsigned int column = 0; column < NColumns; column++)
            for (unsigned int column = 0; column < B[row].size(); column++)
                {
                    std::cout<< std::scientific<< B [row] [column]<< " ";
                }

            std::cout.unsetf(std::ios::scientific);

            for (unsigned int column = B[row].size(); column < NColumns; column++)
                {
                    std::cout<< g << " ";
                }


            std::cout<< std::endl;
        }

    }


    return 0;
}


int MatrixFout (std::vector <std::vector <double>> & B, std::ofstream & fout, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// �뢮� ������ (double) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Fouts" Matrix (double) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
    {
    fout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    }


    if (scientifique)
    {


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::scientific<< B [row] [column]<< " ";
            }

        fout.unsetf(std::ios::scientific);
        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }


    }



    return 0;
}


int MatrixFout (std::vector <std::vector <long double>> & B, std::ofstream & fout, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// �뢮� ������ (long double) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Fouts" Matrix (long double) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
    {
    fout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    }


    if (scientifique)
    {


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::scientific<< B [row] [column]<< " ";
            }

        fout.unsetf(std::ios::scientific);
        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }


    }



    return 0;
}



int MatrixFout (std::vector <std::vector <int>> & B, std::ofstream & fout, char g = ' ')
// �뢮� ������ (int) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// "Fouts" Matrix (int) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    return 0;
}



int MatrixFout (std::vector <std::vector <long long int>> & B, std::ofstream & fout, char g = ' ')
// �뢮� ������ (long long int) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� �� ᮤ�ন� ��ப/ �⮫�殢
// �᫨ ��ப� ������ ࠧ��� �����, � "���⪨" ����� �� ���ᨬ��쭮� �� �뢮�� ����������� ᨬ����� g
// "Fouts" Matrix (long long int) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    return 0;
}


int FindIn (std::vector <int> &D, int a, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (int), ᮢ�����饣� � �᪮�� (a), ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// Returns index in vector (int) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0.


    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if (D[y] == a) return y;
    }
    return -1;
}


int FindIn (std::vector <long long int> &D, long long int a, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (long long int), ᮢ�����饣� � �᪮�� (a), ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// Returns index in vector (long long int) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0.


    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if (D[y] == a) return y;
    }
    return -1;
}


int FindIn (std::vector <double> &D, double a, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (double), ᮢ�����饣� � �᪮�� (a), ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// ��, ��אַ� �ࠢ����� �ᥫ double �� ᮢᥬ ���४⭮ � �� �㦭� �ਭ����� �� ��������, �� � �拉 ��砥� �㭪�� ����� ���� �������.
// ��� �ࠢ����� � �������� �筮���� �. ��ਠ�� �㭪樨 ����.
// Returns index in vector (double) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0.
// Yes, operation like (a==b) may be not correct for doubles. But this function may be considered as an useful one in some cases.
//  The following version of the function finds the first element, that differs from "a" less than "d".


    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ((D[y]-a)==0.0) return y;
    }
    return -1;
}



int FindIn (std::vector <double> &D, double a, double d, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (double), ᮢ�����饣� � �᪮�� (a) � �筮���� �� d, ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// Returns index in vector (double) of the first element, that differs from "a" less than nonnegative double "d".
// Search starts from index "start" with step = "step". If no such element found the function returns 0.


    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ( (std::abs(D[y] - a))<d) return y;
    }
    return -1;
}


int FindIn (std::vector <long double> &D, long double a, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (long double), ᮢ�����饣� � �᪮�� (a), ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// ��, ��אַ� �ࠢ����� �ᥫ long double �� ᮢᥬ ���४⭮ � �� �㦭� �ਭ����� �� ��������, �� � �拉 ��砥� �㭪�� ����� ���� �������. ��� �ࠢ����� � �������� �筮���� �. ��ਠ�� �㭪樨 ����.
// Returns index in vector (long double) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0.
// Yes, operation like (a==b) may be not correct for doubles. But this function may be considered as an useful one in some cases. The following version of the function finds the first element, that differs from "a" less than "d".


    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ((D[y]-a)==0.0) return y;
    }
    return -1;
}


int FindIn (std::vector <long double> &D, long double a, long double d, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (long double), ᮢ�����饣� � �᪮�� (a) � �筮���� �� d, ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// Returns index in vector (long double) of the first element, that differs from "a" less than nonnegative long double "d".
// Search starts from index "start" with step = "step". If no such element found the function returns 0.

    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ( (std::abs(D[y] - a))<d) return y;
    }
    return -1;
}



int FindIn (std::vector <std::string> &D, std::string a, unsigned int step = 1, unsigned int start = 0)
{
// �����頥� ������ ��ࢮ�� ���������� ������� (string), ᮢ�����饣� � �᪮�� (a), ���� ������� � ����樨 start, 蠣 ���᪠ = step, �᫨ �� ��諨 ⠪��� ������� - �����頥� -1.
// Returns index in vector (string) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0.


    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if (D[y] == a) return y;
    }
    return -1;
}


int VectorCout (const std::vector <int> &P)
// �뢮� ����� (int) �� ��࠭ �१ �஡���
// "Couts" vector (int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}

int VectorFout (const std::vector <int> &P, std::ofstream &fout)
// �뢮� ����� (int) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� - ���⮩
// "Fouts" vector (int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}



int VectorCout (const std::vector <long long int> &P)
// �뢮� ����� (long long int) �� ��࠭ �१ �஡���
// "Couts" vector (long long int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}

int VectorFout (const std::vector <long long int> &P, std::ofstream &fout)
// �뢮� ����� (long long int) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� - ���⮩
// "Fouts" vector (long long int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}




int VectorCout (const std::vector <double> &P, unsigned int prec = 4, bool scientifique = false)
// �뢮� ����� (double) �� ��࠭ �१ �஡���. �����頥� -1, �᫨ ����� - ���⮩
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Couts" vector (double) to screen. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{
    if (P.size()==0) return -1;

    if (!scientifique)
    {

    std::cout.precision(prec);
    for (int i=0; i<P.size();i++)
        std::cout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        std::cout<< std::scientific<< P[i]<<" ";

    std::cout.unsetf(std::ios::scientific);

    }


    std::cout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <double> &P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// �뢮� ����� (double) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� - ���⮩
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Fouts" vector (double) to file. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    if (P.size()==0) return -1;

    if (!scientifique)
    {
    fout.precision(prec);
    for (int i=0; i<P.size();i++)
        fout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        fout<< std::scientific<< P[i]<<" ";

    fout.unsetf(std::ios::scientific);
    }

    fout<< std::endl;
    return 0;
}




int VectorCout (const std::vector <long double> &P, unsigned int prec = 4, bool scientifique = false)
// �뢮� ����� (long double) �� ��࠭ �१ �஡���. �����頥� -1, �᫨ ����� - ���⮩
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Couts" vector (long double) to screen. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{
    if (P.size()==0) return -1;

    if (!scientifique)
    {

    std::cout.precision(prec);
    for (int i=0; i<P.size();i++)
        std::cout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        std::cout<< std::scientific<< P[i]<<" ";

    std::cout.unsetf(std::ios::scientific);
    }

    std::cout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <long double> &P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// �뢮� ����� (long double) � 䠩� �१ �஡���. �����頥� -1, �᫨ ����� - ���⮩
// �뢮� �ᥫ �஢������ � �������� �筮���� prec, �᫨ bool scientifique == false. �᫨ bool scientifique == true, �뢮� �ந�������� � ��ᯮ���樠�쭮� �ଥ.
// "Fouts" vector (long double) to file. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    if (P.size()==0) return -1;

    if (!scientifique)
    {
    fout.precision(prec);
    for (int i=0; i<P.size();i++)
        fout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        fout<< std::scientific<< P[i]<<" ";


    fout.unsetf(std::ios::scientific);
    }

    fout<< std::endl;
    return 0;
}




int VectorCout (const std::vector <std::string> & P)
// �뢮� ����� (string) �१ Enter �� ��࠭. �����頥� -1, �᫨ ����� - ���⮩
// "Couts" vector (string) to screen. Returns -1 if the vector is empty
{
    if (P.size()==0) return -1;


    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<std::endl;
    std::cout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <std::string> & P, std::ofstream &fout)
// �뢮� ����� (string) �१ Enter � 䠩�. �����頥� -1, �᫨ ����� - ���⮩
// "Fouts" vector (string) to file. Returns -1 if the vector is empty
{
    if (P.size()==0) return -1;


    for (int i=0; i<P.size();i++)
        fout<< P[i]<<std::endl;
    fout<< std::endl;
    return 0;
}




int PairVectorCout (const std::pair < std::vector<int>, std::vector<double>> & P, unsigned int prec = 4)
// ����䨪��� �㭪樨 VectorCout (�. ���).
// Modification of the function VectorCout (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{

    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;
    std::cout.precision(prec);

    for (int i=0; i<(P.second).size();i++)
    {
        std::cout<< (P.first)[2*i]<<" ";
        std::cout<< (P.first)[2*i+1]<<" ";
        std::cout<< std::fixed<<(P.second)[i]<<" ";

    }
    std::cout<< std::endl;

    return 0;
}

int PairVectorFout (const std::pair < std::vector<int>, std::vector<double>> & P, std::ofstream &fout, unsigned int prec = 4)
// ����䨪��� �㭪樨 VectorFout (�. ���).
// Modification of the function VectorFout (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.

{

    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;
    fout.precision(prec);

    for (int i=0; i<(P.second).size();i++)
    {
        fout<< (P.first)[2*i]<<" ";
        fout<< (P.first)[2*i+1]<<" ";
        fout<< std::fixed<<(P.second)[i]<<" ";

    }
    fout<< std::endl;

    return 0;
}




int SwapInVector (std::vector <int> & A1, unsigned int f, unsigned int l)
{
    // swaps 2 elements in vector (int). Returns -1 if some index out of vector's range or vector is empty
    // ������ ������⮢ � ����� (int), �����頥� -1 �᫨ ��� ���� �� ����訢����� �����ᮢ ��室�� �� ࠧ��� ����� ���� �᫨ ����� ���⮩


    if ((A1.size()==0) || (f>=A1.size()) || (l>=A1.size())) return -1;

    int t = A1[f];
    A1[f] = A1[l];
    A1[l] = t;
    return 0;

}

int SwapInVector (std::vector <long long int> & A1, unsigned int f, unsigned int l)
{
    // swaps 2 elements in vector (long long int). Returns -1 if some index out of vector's range or vector is empty
    // ������ ������⮢ � ����� (long long int), �����頥� -1 �᫨ ��� ���� �� ����訢����� �����ᮢ ��室�� �� ࠧ��� ����� ���� �᫨ ����� ���⮩


    if ((A1.size()==0) || (f>=A1.size()) || (l>=A1.size())) return -1;

    long long int t = A1[f];
    A1[f] = A1[l];
    A1[l] = t;
    return 0;

}

int SwapInVector (std::vector <double> & A1, unsigned int f, unsigned int l)
{
    // swaps 2 elements in vector (double). Returns -1 if some index out of vector's range or vector is empty
    // ������ ������⮢ � ����� (double), �����頥� -1 �᫨ ��� ���� �� ����訢����� �����ᮢ ��室�� �� ࠧ��� ����� ���� �᫨ ����� ���⮩


    if ((A1.size()==0) || (f>=A1.size()) || (l>=A1.size())) return -1;

    double t = A1[f];
    A1[f] = A1[l];
    A1[l] = t;
    return 0;

}


int SwapInVector (std::vector <long double> & A1, unsigned int f, unsigned int l)
{
    // swaps 2 elements in vector (long double). Returns -1 if some index out of vector's range or vector is empty
    // ������ ������⮢ � ����� (long double), �����頥� -1 �᫨ ��� ���� �� ����訢����� �����ᮢ ��室�� �� ࠧ��� ����� ���� �᫨ ����� ���⮩


    if ((A1.size()==0) || (f>=A1.size()) || (l>=A1.size())) return -1;

    long double t = A1[f];
    A1[f] = A1[l];
    A1[l] = t;
    return 0;

}


int SwapInVector (std::vector <std::string> & A1, unsigned int f, unsigned int l)
{
    // swaps 2 elements in vector (string). Returns -1 if some index out of vector's range or vector is empty
    // ������ ������⮢ � ����� (string), �����頥� -1 �᫨ ��� ���� �� ����訢����� �����ᮢ ��室�� �� ࠧ��� ����� ���� �᫨ ����� ���⮩


    if ((A1.size()==0) || (f>=A1.size()) || (l>=A1.size())) return -1;

    std::string t = A1[f];
    A1[f] = A1[l];
    A1[l] = t;
    return 0;

}


int HmDist (const std::string &s1, const std::string &s2)
{
    // Counts Hamming Distance; returns -1 if any string is empty or they have different length.
    // ��⠥� Hamming Distance, �����頥� -1 �᫨ ��ப� ࠧ��� ����� ���� ��� ���� �����.

    if ((s1.length()==0) || (s2.length()==0) || (s1.length()!=s2.length())) return -1;
    int q = 0;
    for (unsigned int i=0; i<s1.length(); i++)
    {if (s1[i] != s2[i]) q++;}
    return q;
}

int RComplDNA (const std::string& s, std::string & sr)
{
    // generates reverse complement of string s as string sr, returns -1 and empty string sr if string s is empty or it is not DNA

     sr = s;

     if (s.length()==0) return -1;

     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') {sr [i]  = 'T'; continue;}
      if (s [s.length()-i-1] == 'T') {sr [i]  = 'A'; continue;}
      if (s [s.length()-i-1] == 'G') {sr [i]  = 'C'; continue;}
      if (s [s.length()-i-1] == 'C') {sr [i]  = 'G'; continue;}

      sr.clear();
      return -1;
     }

    return 0;
}


int RComplRNA (const std::string& s, std::string & sr)
{
    // generates reverse complement of string s as string sr, returns -1 and empty string sr if string s is empty or it is not RNA

     sr = s;

     if (s.length()==0) return -1;

     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') {sr [i]  = 'U'; continue;}
      if (s [s.length()-i-1] == 'U') {sr [i]  = 'A'; continue;}
      if (s [s.length()-i-1] == 'G') {sr [i]  = 'C'; continue;}
      if (s [s.length()-i-1] == 'C') {sr [i]  = 'G'; continue;}

      sr.clear();
      return -1;
     }

    return 0;
}


std::string rp (const std::string& s)
{
    // generates reverse complement of DNA without any checking of input data correctness

     std::string sr = s;
     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') sr [i]  = 'T';
      if (s [s.length()-i-1] == 'T') sr [i]  = 'A';
      if (s [s.length()-i-1] == 'G') sr [i]  = 'C';
      if (s [s.length()-i-1] == 'C') sr [i]  = 'G';
     }
    return sr;
}


std::string rpr (const std::string& s)
{
    // generates reverse complement of RNA without any checking of input data correctness

     std::string sr = s;
     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') sr [i]  = 'U';
      if (s [s.length()-i-1] == 'U') sr [i]  = 'A';
      if (s [s.length()-i-1] == 'G') sr [i]  = 'C';
      if (s [s.length()-i-1] == 'C') sr [i]  = 'G';
     }
    return sr;
}



double gcDRNA (const std::string &s)
{

    // Counts DNA/RNA GC-content; in case any symbol not DNA/RNA-nucleotide or string s is empty returns -1.0.

    if (s.length()==0) return -1.0;

    int count = 0;

    for (int i = 0; i< s.length(); i++)
    {
        if ((s[i]=='G') || (s[i]=='C')) {count++; continue;}
        if ((s[i]=='A') || (s[i]=='T') || (s[i]=='U')) {continue;}
        return -1.0;
    }


    return 1.0*count/s.length();
}


int RNAfromDNA (const std::string &s, std::string & sr)
{
     // generates RNA from DNA, returns -1 and empty string sr if the input string s is empty or it is not DNA

    if (s.length()==0) {sr.clear(); return -1;}
    sr = s;
    for (int i = 0; i<s.length(); i++)
    {
        if (sr [i] == 'T') {sr [i]  = 'U'; continue;}
        if (sr [i] == 'A') {continue;}
        if (sr [i] == 'G') {continue;}
        if (sr [i] == 'C') {continue;}

        sr.clear();
        return -1;
    }

return 0;

}


int DNAfromRNA (const std::string &s, std::string & sr)
{
     // generates DNA from RNA, returns -1 and empty string sr if the input string s is empty or it is not RNA

    if (s.length()==0) {sr.clear(); return -1;}
    sr = s;
    for (int i = 0; i<s.length(); i++)
    {
        if (sr [i] == 'U') {sr [i]  = 'T'; continue;}
        if (sr [i] == 'A') {continue;}
        if (sr [i] == 'G') {continue;}
        if (sr [i] == 'C') {continue;}

        sr.clear();
        return -1;
    }

return 0;

}


std::string RNAg (const std::string &s)
{
// generates RNA from DNA without checking of data correctness

    std::string sr = s;
    for (int i = 0; i<s.length(); i++)
        {
        sr [i]= s [i];
        if (sr [i] == 'T') sr [i]  = 'U';
    }

return sr;
}


std::string DNAg (const std::string &s)
{
// generates RNA from DNA without checking of data correctness

    std::string sr = s;
    for (int i = 0; i<s.length(); i++)
        {
        sr [i]= s [i];
        if (sr [i] == 'U') sr [i]  = 'T';
    }

return sr;
}


void GMapCodonRNA (std::map <std::string, std::string> & MapCodon)
{
    //Generates codon table for RNA in the map MapCodon ("$" means stop codon).
    // MapCodon format: Codon -> Amino acid.


    MapCodon.clear();

    MapCodon =
    {
        {"UUU", "F"},
        {"CUU", "L"},
        {"AUU", "I"},
        {"GUU", "V"},
        {"UUC", "F"},
        {"CUC", "L"},
        {"AUC", "I"},
        {"GUC", "V"},
        {"UUA", "L"},
        {"CUA", "L"},
        {"AUA", "I"},
        {"GUA", "V"},
        {"UUG", "L"},
        {"CUG", "L"},
        {"AUG", "M"},
        {"GUG", "V"},
        {"UCU", "S"},
        {"CCU", "P"},
        {"ACU", "T"},
        {"GCU", "A"},
        {"UCC", "S"},
        {"CCC", "P"},
        {"ACC", "T"},
        {"GCC", "A"},
        {"UCA", "S"},
        {"CCA", "P"},
        {"ACA", "T"},
        {"GCA", "A"},
        {"UCG", "S"},
        {"CCG", "P"},
        {"ACG", "T"},
        {"GCG", "A"},
        {"UAU", "Y"},
        {"CAU", "H"},
        {"AAU", "N"},
        {"GAU", "D"},
        {"UAC", "Y"},
        {"CAC", "H"},
        {"AAC", "N"},
        {"GAC", "D"},
        {"UAA", "$"},
        {"CAA", "Q"},
        {"AAA", "K"},
        {"GAA", "E"},
        {"UAG", "$"},
        {"CAG", "Q"},
        {"AAG", "K"},
        {"GAG", "E"},
        {"UGU", "C"},
        {"CGU", "R"},
        {"AGU", "S"},
        {"GGU", "G"},
        {"UGC", "C"},
        {"CGC", "R"},
        {"AGC", "S"},
        {"GGC", "G"},
        {"UGA", "$"},
        {"CGA", "R"},
        {"AGA", "R"},
        {"GGA", "G"},
        {"UGG", "W"},
        {"CGG", "R"},
        {"AGG", "R"},
        {"GGG", "G"}
    };

}


void GMapCodonRNA_A (std::map <std::string, std::vector<std::string>> & MapCodon)
//Generates codon table for RNA in the map MapCodon ("$" means stop codon).
// MapCodon format: Amino acid -> vector of relevant codons.
{

    MapCodon.clear();

    MapCodon =
        {
            {"F", {"UUU", "UUC"}},
            {"L", {"CUU", "CUC", "CUA", "CUG", "UUG", "UUA"}},
            {"I", {"AUU", "AUC", "AUA"}},
            {"V", {"GUU", "GUC", "GUA", "GUG"}},
            {"M", {"AUG"}},
            {"S", {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC"}},
            {"P", {"CCU", "CCC", "CCA", "CCG"}},
            {"T", {"ACU", "ACC", "ACA", "ACG"}},
            {"A", {"GCU", "GCC", "GCA", "GCG"}},
            {"Y", {"UAU", "UAC"}},
            {"H", {"CAU", "CAC"}},
            {"N", {"AAU", "AAC"}},
            {"D", {"GAU", "GAC"}},
            {"$", {"UAA", "UAG", "UGA"}},
            {"Q", {"CAA", "CAG"}},
            {"K", {"AAA", "AAG"}},
            {"E", {"GAA", "GAG"}},
            {"C", {"UGU", "UGC"}},
            {"R", {"CGU", "CGC", "CGA", "AGA", "CGG", "AGG"}},
            {"G", {"GGU", "GGC", "GGA", "GGG"}},
            {"W", {"UGG"}},
         };


}


void GMapMonoisotopicMassTableLD (std::map <char, long double> & MassTable)
{
    //Generates Monoisotopic mass table in the map (long double)

    MassTable.clear();


MassTable =
  {
    {'A', 71.03711},
    {'C', 103.00919},
    {'D', 115.02694},
    {'E', 129.04259},
    {'F', 147.06841},
    {'G', 57.02146},
    {'H', 137.05891},
    {'I', 113.08406},
    {'K', 128.09496},
    {'L', 113.08406},
    {'M', 131.04049},
    {'N', 114.04293},
    {'P', 97.05276},
    {'Q', 128.05858},
    {'R', 156.10111},
    {'S', 87.03203},
    {'T', 101.04768},
    {'V', 99.06841},
    {'W', 186.07931},
    {'Y', 163.06333}

  };
}



int GPFM (std::vector <std::string> &s, std::vector <std::vector <int>> & B, const std::string &Alph)
{

    // �������� ����樮���� ������ ���� B �� ������ ��室��� ��ப s � ��䠢��� Alph (ᮤ�ন� ��᫥����⥫쭮��� ᨬ����� ��䠢��);
    // ��᫥����⥫쭮��� ��ப � ����� B ᮮ⢥����� ��᫥����⥫쭮�� ᨬ����� � ��ப� Alph (�.�. ��᫥����⥫쭮�� ᨬ����� ��䠢��).
    // � ��砥 �᫨ � ����� ����� 2� ��ப ��� ��� ����� ������������ ����� ��� � ��䠢�� ����� 2 �㪢 ��� ��� ���� �� ��ப ᮤ�ন� ��� ���� ᨬ��� �� �� ��䠢��,
    // ��� �� �᫨ ��䠢�� ᮤ�ন� �㡫����騥�� ᨬ���� - �����頥��� -1  � ����� ����� B (� ��砥 �ᯥ� �����頥��� 0).

    // Generates position frequency matrix (PFM) B upon an array of strings s and given Alphabet (Alphabet is set via string Alph that contains the sequence of its symbols);
    // Ordering of the rows in B corresponds to sequence of symbols in Alph.
    // If s contains 1 or 0 items or strings have not equal length or even the only string contains symbol that not belongs to Alphabet
    // or if there are any identical symbols in the Alphabet - returns -1 and empty B.



    B.clear();
    if ((s.size()<=1) || (Alph.length()<2)) return -1; // checking that s contains more than 2 stings and Alph consists of >=2 symbols.


    int lstring = (s[0]).length();
    int lvector = s.size();


    for (int i=1; i<s.size(); i++)  // checking that all strings in s have equal length
        if (s[i].length()!=lstring)
        {
            return -1;
        }

    std::set <char> T; // �஢�ઠ �� ��� �㡫�������� ᨬ����� � ��䠢��
    T.clear(); // Testing if there are any identical symbols in the Alphabet
    for  (int y=0; y<Alph.length(); y++)
    {
        T.insert(Alph[y]);
        if ((T.size()-1)!=y)
            return -1;

    }
    T.clear();

    MatrixSet (B, Alph.length(), lstring, 0);

    for (int i = 0; i<lstring; i++)
    {
        for (int j = 0; j<lvector; j++)
        {
            for  (int y=0; y<Alph.length(); y++)
                 if (((s[j])[i]) == Alph[y]) {B[y][i]++; goto l1;}



                B.clear(); // �᫨ ��� ���� ᨬ��� �� �� ��䠢�� - ��頥� ������ � �����頥� -1
                return -1; // even one symbol doesn't belong to Alph - matrix B to be cleared and -1 to return

            l1:;
        }

    }

    return 0;

}





double PDist (const std::string& s1, const std::string& s2) // counts p-distance without checking of the input data correctness
{
    double r;
    int q = 0;
    for (unsigned int i=0; i<s1.length(); i++)
    {if (s1[i] != s2[i]) q++;}
    r = double(q)/s1.length();
    return r;
}


int GDistanceMatrix (std::vector <std::string> &s, std::vector <std::vector <double>> & B)
{
// �������� ������ ����ﭨ� "B" �� ������ ��室��� ��ப s; � ��砥 �᫨ � ����� ����� 2� ��ப ��� ��� ����� ������������ ����� - �����頥��� -1 (� ��砥 �ᯥ� - 0).
// Generates DistanceMatrix "B" upon array of strings s; if s contains 1 or 0 items or strings have not equal length returns -1 and empty B.


    B.clear();
    if (s.size()<=1) return -1; // checking that s contains more than 2 stings

    int lstring = (s[0]).length();
    int lvector = s.size();


    for (int i=1; i<s.size(); i++)  // checking that all strings in s have equal length
        if (s[i].length()!=lstring)
        {
            return -1;
        }


    MatrixSet (B, lvector, lvector, 0);

    for (int i = 0; i<lvector; i++)
    for (int j = 0; j<lvector; j++)
    {
        B [i][j] = PDist(s[i], s[j]);
    }

    return 0;
}


int EditDist (const std::string &s1, const std::string &s2)
// ������뢠�� ।��樮���� ����ﭨ� (����ﭨ� ������⥩��) �e��� ��ப���, �ਭ����� �� �室 ���� �����. ���� ������ ����樨 = 1
// Computes Edit Distance (Levenshtein distance) between two strings (strings may be empty too).

{
int n = s1.length()+1;
int m = s2.length()+1;

if ((n==1)&&(m==1)) return 0;

if (n==1) return (m-1);
if (m==1) return (n-1);

std::vector <std::vector <int>> B (n);  // Generating pre-matrix for computing distance filled by zeros.
for (unsigned int row = 0; (row< n); row++)
{
    B [row].resize(m);
    for (unsigned int column = 0; (column < m); column++)
    {
        B [row] [column] = 0;

    }

}



// Filling the matrix
int w=1;
for (unsigned int i = 0; (i< n); i++)
    for (unsigned int j = 0; (j< m); j++)
        if (j==0) B[i][j] = i;
        else if (i==0) B[i][j] = j;
        else
        {
            w = 1;
            if (s1[i-1] == s2[j-1])   // �㦭� �������� ��ப i, j �� ���浪�, �� �.�. �㬥�㥬 � ��� ᨬ���� ��ப - ���ࠢ�� �� -1
            //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                w = 0;
            B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
            if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
        }


return B[n-1][m-1];

}




void EDistForFindMR (const std::string &s1, const std::string &s2, const int D, const int L, int l, int b, std::set <std::pair <int, int>> &Result)

// �ᯮ����⥫쭠� �㭪�� ��� FindMutatedRepeatsED (�. ����, �ਢ������ ᫥���饩).
// An auxiliary function for FindMutatedRepeatsED, see its info for details (below, the following one).

{
int n = s1.length()+1;
int m = s2.length()+1;



std::vector <std::vector <int>> B (n);  // Generating pre-matrix for computing edit distance. It is filled by zeros by default.
MatrixSet(B, n, m, 0);



// Filling the matrix
int w=1;
for (unsigned int i = 0; (i< n); i++)
    for (unsigned int j = 0; (j< m); j++)
        if (j==0) B[i][j] = i;
        else if (i==0) B[i][j] = j;
        else
        {
            w = 1;
            if (s1[i-1] == s2[j-1])   // �㦭� �������� ��ப i, j �� ���浪�, �� �.�. �㬥�㥬 � ��� ᨬ���� ��ப - ���ࠢ�� �� -1
            //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                w = 0;
            B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
            if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
        }


int c1 = n-1;
int c2 = m-1;

while (l>=L-D)
{
    if (B[c1][c2]<=D) // The matrix B contains Edit Distance between s2 and not only s1, but for all prefixes of s1 too (the previous row at the same coloumn for the substring formed by deleting the last symbol etc).
    {


        Result.insert(std::pair<int, int>(b-1, l)); // So if Edit Distance <=D and the length of prefix not less than L-D, this prefix is the one of required. So let's insert its data to Result.

    }
    l--;
    c1--;

}


}



int FindMutatedRepeatsED (std::string &StrShort, std::string &StrLong, int D, std::set <std::pair <int, int>> &Result)
// �㭪�� ��室�� �� �����ப� ��� ��ப� StrLong, ।��樮���� ����ﭨ� ������ �� StrShort �� �ॢ�蠥� D. �� �⮬ �ਭ�������, �� "����" �� �ய�� � ��ᮢ������� ᨬ�����  = 1.
// ������� �����頥��� � set <std::pair <int, int>> Result, ��� ��ࢮ� �᫮ � ��� - ����� ����樨 ��砫� �����ப� � StrLong (��� ����権 ���� � 0), � ��஥ - ����� �����ப� (���� �� �����஢���).
// �᫨ ��室�� ����� �����४�� - �����頥��� -1 � ���⮩ Result;, � ��砥 �ᯥ� �����頥��� 0.
// ���� ॠ����������� �����⬠:
// (1) ���� �� ��砫� ⠪�� �����ப � StrLong.
// ��� �⮣� ��� ��ப� ॢ���������, ��⥬ StrShort "��ࠢ��������" �� StrLong �� ����� �ࠢ���� ��� ��宦����� ।��樮����� ����ﭨ�, �� � ⥬ �⫨稥�,
// �� �㬬��� ��砫�� �ய�� �� StrLong �� "��������" (����� ����� � �� ����樨 � ������� ��ப� ��� "����"). �������� ��砫�� ����樨 �㬥������ � 1. ��⥬ ��ப� ॢ��������� ���⭮.
// (2) ��� ������ ����樨 �������� ���ᨬ��쭮 ��������� ����� �᪮��� �����ப�, ����� �� ����� ���� ����� ����� StrShort ���� D, � �� �⮬ �� ����� ��室��� �� �࠭��� StrLong.
// ���᭥���. ����� �᪮��� �����ப �� ����� �⫨����� �� ����� StrShort ����� 祬 �� D � �� � ����� ��஭�, �.�. ।��樮���� ����ﭨ� �� �ॢ�蠥� D, � 業� �ய�᪠ = 1.
// (3) �᫨ ⠪�� ���ᨬ��쭮 ��������� ����� ���� � ��⠢��� �� ����� ����� StrShort ����� D, � ��� ᮮ⢥����饩 �����ப� (������稬 ��� TempS) � StrShort �����⢫塞 �⠭����� Edit Distance Alignment � ������� �ᯮ����⥫쭮� �㭪樨 EDistForFindMR.
// � � ����ࠨ������ ��� ��� 楫�� ����� ���� ���祭�� Edit Distance �� ⮫쪮 ����� StrShort � TempS, �� � (!) 㪮�祭�� � ���� �����ப�� TempS (��� �⮣� ��६ ���祭�� � ����� �� ⮫쪮 �� ��᫥���� ��ப� (TempS "�⪫��뢠����" ����), �� � �� �।�����騬.
// �᫨ ��� ������� ⠪��� ��䨪� ��ப� TempS (�� �᫮���, �� ��� ����� 㤮���⢮��� ���᭥��� � 蠣� (2)) ���祭�� Edit Distance �� �ॢ�蠥� D - 䨪��㥬 � set Result ��� ��砫��� ������ (� �㬥�樨 �� 0) � �����.
// �㭪�� �����頥� 0 � ���������� Result � ��砥 �ᯥ� � -1 � ���⮩ Result � ��砥 �����४⭮�� ��室��� ������ (�� �� ��ப ���� ��� StrShort ������� StrLong ��� ����� StrShort �� �ॢ��室�� D)


// The function finds all the substrings of a string StrLong, that have Edit Distance to a string StrShort <= D. Gap and mistmatch penalties are set as "1" here.
// If dataset is correct returns 0 and set <std::pair <int, int>> Result, that contains pairs of integers: first one is a start position of a required substring in StrLong (0-based indexing)  and the second one is its length.
// If dataset is not correct (any string is empty of StrShort is longer than StrLong or StrShort's length <= D) returns -1 and empty Result.
// The algorithm idea is:
// (1) to find all start positions of such substrings. To do so we should reverse both strings and then do Edit Distance Alignment but with no gap penalty at the beginning: The required substring may start at every position of the longer string so here are no penalty fo gapping at start.
// (2) For each start position the maximal possible length for the required substring (<= StrShort.length+D, but within StrLong).
// Note that the required substrings may have length <= StrShort.length+D and >= StrShort.length-D because gap penalty = 1.
// (3) If such maximal possible length meets this condition, let a string TempS be a substring of StrLong of this length (TempS starts from relevant start position in StrLong).
// And then let's do Edit Distance Alignment between TempS and StrShort in order to find prefixes of TempS, that require the statement of problem to be solved here.


{
    Result.clear();

    if (StrShort.length()>StrLong.length()) return -1; // �ਢ�ઠ ���४⭮�� ��室��� ������  // checking for input tata correctness
    if ((StrShort.length()==0) || (StrLong.length()==0))return -1; // �ਢ�ઠ ���४⭮�� ��室��� ������  // checking for input tata correctness
    if (D<0) return -1; // �ਢ�ઠ ���४⭮�� ��室��� ������  // checking for input tata correctness
    if (StrShort.length()<=D) return -1; // �ਢ�ઠ ���४⭮�� ��室��� ������  // checking for input tata correctness


    std::string TempS = "";


    const int gapP = -1; //gap penalty
    const int mismP = -1; //mismatch penalty

std::set <int>StartPositions; //Here the start positions of required substrings of StrLong will be contained (their numbering starts from "1" for this set).
// ����� �㤥� �࠭��� ����� ��砫 �᪮��� ��ப (����� ����饭��: ᨬ���� � ��ப� �㬥������ � 1)




int L = StrShort.length();
StartPositions.clear();


//Preparing a matrix for alignment
unsigned int n = StrShort.length()+1;
unsigned int m = StrLong.length()+1;

std::vector <std::vector <int>> B (n);


int count0;
int count1;

int w;
int mt, dt, in;



MatrixSet(B, n, m, 0);


  for (unsigned int i = 0; (i< n); i++)  // ���ࠢ��: ����� ����� � �� ����樨 � ������� ��ப� ��� "����"
      B[i][0] = i*gapP;                  // The required substring may start at every position of the longer string so here are no penalty fo gapping at start

  // End of preparing a matrix for alignment

  reverse(StrShort.begin(),StrShort.end()); // ��ॢ��稢��� ��ப�, �⮡� ���� �� ��砫�� ����樨 �᪮��� �����ப � StrLong
reverse(StrLong.begin(),StrLong.end()); // the strings should be reversed now in order to find all start positions of required substrings of StrLong

for (unsigned int i = 1; (i< n); i++)
    for (unsigned int j = 1; (j< m); j++)

        {
            w=mismP;
            if(StrShort[i-1] == StrLong[j-1]) w=0;
            mt = B[i-1][j-1] + w;
            dt = B[i-1][j] + gapP;
            in = B[i][j-1] + gapP;

            B[i][j] = mt;
            if (B[i][j]<std::max(dt, in)) B[i][j] = std::max(dt, in);
        }

reverse(StrShort.begin(),StrShort.end());  // ⥯��� ��ॢ��稢��� ��ப� �����
reverse(StrLong.begin(),StrLong.end()); // now the strings are reversed back


for (int i=0;i<m;i++)
    if(B[n-1][i]*(-1)<=D) // �᫮��� ⮣�, �� � ������ �窥 �㤥� ��砫� ����� ��� ��᪮�쪨� �᪮��� �����ப (� ���ࠢ��� �� ॢ���)
                          // This means that here will be the beginning for one or more required substrings (reverse adjusted)
    {
        StartPositions.insert(StrLong.length()-i+1);  // Computing the starting position ("1"-based indexing)

    }


int l;




for (auto it = StartPositions.begin(); it!=StartPositions.end(); it++)
    // ��� ������ ��������� �窨 ��砫� �����ப ����塞 l - ���ᨬ��쭮 ��������� ����� �᪮��� �����ப�, ����� �� ����� ���� ����� ����� ���⪮� ��ப� ���� D, � �� �⮬ �� ����� ��室��� �� �࠭��� ������� ��ப�.
    // Let's compute "l" for every starting position. "l" means the maximal possible length for the required substring (<= StrShort.length+D, but within StrLong).
{

    l=-1;
    if ((*it+L+D-1)<=StrLong.length()) l=L+D;
    else if (*it+L-D-1<=StrLong.length()) l=StrLong.length()-*it+1;



    if (l>0) // If so - lets do Edit Distance Alignment between TempS and StrShort in order to find prefixes of TempS, that require the statement of problem to be solved by the function FindMutatedRepeatsED.
    {
        TempS = StrLong.substr(*it-1, l);
        EDistForFindMR(TempS, StrShort, D, L, l, *it, Result);
    }


}


return 0;

}




int PartitionOfNumber (std::vector <std::vector <int>> &B, int n)
// �������� ࠧ������ �᫠ �� ᫠����� ��� �ᥫ ����� 0 (���� ��୥� -1). ������� ���������� � ����� ����஢ B.
//Generates partitions of int n (i.e. representing n as a sum of positive integers) in B. If n<=0 returns empty B and "-1"

{
    B.clear();

    if (n<=0) return -1;
    int t,y;
    std::vector <int> T (n, 1);

    while (true)
    {
        B.push_back(T);

        if (T[0]==n) break;
        if (T.size()==1) break;
        t=T[T.size()-2];
        for (int i=T.size()-2; i>=0; i--)
        {
            if (T[i]>t) {y=i+1; break;}

            y=i;
        }




        T[y]++;
        T[T.size()-1]--;
        if (T[T.size()-1]==0) T.pop_back();

        t=T.size();
        for (int z= y+1; z<t; z++)
        {
            if (T[z]==1) continue;
            T[z]--;
            T.push_back(1);
            z--;
        }


    }

    return 0;
}


int PartitionOfNumberL (std::vector <std::vector <int>> &B, int n, int l=-1)
// �������� ࠧ������ �᫠ �� ᫠����� ��� �ᥫ ����� 0 (���� ��୥� -1). ������� ���������� � ����� ����஢ B. ����७��� �����:
// ����� ������ ����� ࠧ������ l. �᫨ l>0, � ���������� ⮫쪮 ࠧ������ ������ l. �� �⮬ ����� ���⪨� ࠧ������ "���������� �ࠢ�" ��ﬨ.
//Generates partitions of int n (i.e. representing n as a sum of positive integers) in B. Extended version: one may set l>0 as a length of patritions (i.e. number of summands).
// In this case "0" will be added to the end of the shorter partitions. If n<=0 returns empty B and "-1"


{
    B.clear();

    if (n<=0) return -1;
    int t,y;
    std::vector <int> T (n, 1); // starting partition has only ones as summands

    if (l<=0) l=n;  // If l<=0 (as set by default) partitions will have n summands

    while (true)
    {


        if (T.size()<=l)  // Testing if the length of patrition is <=l
            B.push_back(T); // and adding it if it is
        if (T.size()<l) // adding zeros if needed
            for (int e=0; e<l-T.size(); e++)
                B[B.size()-1].push_back(0);


        if (T[0]==n) break; // the last partition is the number n itself
        //if (T.size()==1) break;
        t=T[T.size()-2];
        for (int i=T.size()-2; i>=0; i--)
        {
            if (T[i]>t) {y=i+1; break;}

            y=i;
        }




        T[y]++; // transferring 1 to this summand (y-summand)
        T[T.size()-1]--; //from this summand
        if (T[T.size()-1]==0) T.pop_back();  // deleting it if became 0

        t=T.size();
        for (int z= y+1; z<t; z++) // now representing all the summands after y-summand as a sum of ones only
        {
            if (T[z]==1) continue;
            T[z]--;
            T.push_back(1);
            z--;
        }


    }

    return 0;
}



bool CompStrDLO (const std::string & s1, const std::string & s2)  //Comparing function for arranging an array (vector) of strings in descending length order / �������� ��� ���஢�� ��ப �� �뢠��� ����
{

  return s1.length() > s2.length();

}


std::string ShortSuperstringGr (std::vector <std::string> DataS)
// Generates shortest superstring of an array (vector) of strings DataS via implementing greedy algorithm. In doing so, every string that is a substring of any another one of DataS is to be excluded.
// DataS is copied (not linked) here as it will be changed here.
// Returns empty string if DataS is empty or all strings of DataS are empty.
// �ਬ���� "����� ������" ���᪠ �������襩 �����ப�. �� �⮬ �� ��ᬮ�७�� �᪫������ ��ப�, ��騥�� �����ப��� ��㣨� ��ப DataS.
// ��室�� ����� DataS ����������, � �� �ਢ�뢠���� �� ��뫪�, �.�. DataS �㤥� ���������� � ����� ࠡ��� �㭪樨
// �����頥��� ����� ��ப�, �᫨ DataS - ���⮩ ��� ᮤ�ন� ⮫쪮 ����� ��ப�.


{

    if (DataS.size()==0) return "";

    for (int y=0; y<DataS.size(); y++)  // deleting empty strings
    {
        if (DataS[y]=="")
        {
         DataS.erase(DataS.begin()+y);
         y--;
        }
    }

    if (DataS.size()==0) return "";
    if (DataS.size()==1) return DataS[0];

    std::sort (DataS.begin(), DataS.end(), CompStrDLO);


    for (int z=0; z<DataS.size()-1;z++)      // deleting every string that is a substring of any another one
        {
            for (int zz=z+1; zz<DataS.size();zz++)
                if (DataS[z].find(DataS[zz])!=-1)
                {
                    DataS.erase(DataS.begin()+zz);
                    zz--;
                }
        }


    if (DataS.size()==1) return DataS[0];


    std::vector <std::vector <int>> Arrow;   // A matrix to contain overlap value between strings i and j
    Arrow.clear();
    MatrixSet (Arrow, DataS.size(), DataS.size(), 0); // ����⮢�� ������ ����稭 "��४��⨩" ����� ��ப��� i � j

    // � �� ���������� ����稭��� ��४��⨩: ���� ��ப� i � ��砫� ��ப� j
    // Filling the matrix Arrow with overlap value of end of i th and begin of j-th strings

    int npos=0;
    int l1, l2;

       for (unsigned int i = 0; (i<DataS.size()); i++)
            for (unsigned int j = 0; (j<DataS.size()); j++)
            {
                l1 = DataS[i].length() ;
                l2 = DataS[j].length() ;
                npos=0;
                if (l1 > l2) npos = (l1-l2);

                if (npos==0)
                {
                     for (int y=0; y<l1; y++)
                        if ((DataS[i].substr(y, l1-y) == DataS[j].substr(0, l1-y)) && (i!=j))
                        {Arrow [i] [j] = (l1-y); break;}

                }

                if (npos>0)
                {
                     for (int y=0; y<l2; y++)
                        if ((DataS[i].substr(npos+y, l1-y-npos) == DataS[j].substr(0, l1-y-npos)) && (i!=j))
                        {Arrow [i] [j] = (l1-y-npos); break;}

                }

            }
       //����� ᮧ����� ����������� ������ ��४��⨩
       //end of Arrow filling


        std::string Result = ""; //here result string will be
        std::string TempS;

       int mx = -1;
       int b, e;

       for (int t = 0; t<DataS.size()-1; t++)
       {
           TempS.clear();

           mx = 0;
           for (unsigned int i = 0; (i<DataS.size()); i++)    // �饬 ���ᨬ� mx � 2-��୮� ���ᨢ� � ��� ������� b & e
                for (unsigned int j = 0; (j<DataS.size()); j++)  // searching for maximum of mx (i.e. overlap value), for such maximum indexes of overlapping strings in DataS will be b and e.
                    if ((i!=j) && (Arrow [i] [j] >= mx)) {mx = Arrow [i] [j]; b = i; e=j;}


           TempS = DataS[b].substr(0, DataS[b].length() - mx) + DataS[e]; //�� - ᪫���� ᮮ⢥������ ��ப /Glueing of overlapping strings

           DataS[b] = TempS; //⥯��� �� ��襬 ����� b-� ��ப�, ����� �����ந� ��� ��㬥�� ���ᨢ / and this new glued string shold be write instead of b-th string

           for (unsigned int ii = 0; (ii<DataS.size()); ii++)
                Arrow [ii] [e] = -1;  //"����塞" �⮫��� e - � ��ப� e ᫥�� �� ������ ����� �� ���� ��ப� / switching off e-th coloumn


           for (unsigned int jjj = 0; (jjj<DataS.size()); jjj++)
                {Arrow [b] [jjj] = Arrow [e] [jjj];  //��ப�  e - � ��ப� b, ��ப� e ���㫨�� (⥯��� ��室�� �� �� b) / copying row e to b, switching off e-th row
                Arrow [e] [jjj] = -1;}

       }

       Result = TempS;

       return Result;

}





int TrieMake (std::vector <std::string> &DataS, std::vector <int> & Trie)
// Trie constructing upon vector of strings DataS
// ����஥��� ��䨪᭮�� ��ॢ� Trie �� ���ᨢ� ��ப DataS

{
    Trie.clear(); // Here Trie will be contained as a number of triplets of integers (a = Trie [3i], b = Trie [3i+1], c = Trie [3i+2], i = 0, 1, ...). Each triplet means an edge a->b marked with symbol (char) c. Vertices in the Tree are numerated starting with "1".
    // ����� �㤥� ᠬ� ��ॢ� � ���� ����� �ਯ��⮢ �ᥫ. ���� ��� ������ ॡ� ���, � ���� - ᮮ⢥����騩 ᨬ��� (�㪢�). ���設� ��� �㬥������ � 1.

    if (DataS.size()<2) return -1; // Function works for at least 2 strings


    std::string TempS = "";

    sort (DataS.begin(), DataS.end(), CompStrDLO);

    int last = 0;
    int ind, l;


    for (int i=0;i<DataS[0].length();i++)   // �ନ஢���� ��� �� 1 ��ப� / Pushing to Trie the first (the longest) string from dataset
     {
         Trie.push_back(i+1);
         Trie.push_back(i+2);
         Trie.push_back( (int)DataS[0][i]  );
         last = (i+2);  // ��࠭塞 ����� ��᫥���� (�������襩) ���設� / number of the very last vertex added (i.e. the maximal vertex number at any time)
     }





     for (int j=1;j<DataS.size();j++)  // ������塞 ��⠫�� ��ப�  / Pushing all the rest strings to Trie
     {


         TempS = DataS[j];
         ind = 1; // the number of vertex from which we are searching Trie for symbols matching (when matching is found "ind" will be the number of relevant sinr-vertex)/ � ���ன ���設� �饬 ᮢ�����騥 ᨬ���� (��稭��� �ᥣ�� � ��ࢮ�, ��⥬, ��᫥ ����������, ��६ ���設�-�⮪ �� ᮮ⢥�����饣� ॡ�)
         l = 0; // counter of added symbols of every string being processed / ���稪 ����������� ᨬ����� �� ��।��� ��ப�

         lq: ;

         for (int q = 0; q<Trie.size(); q=q+3)  // searching Trie for symbols matching
         {
             if ((Trie[q]==ind)&&(Trie[q+2]==TempS[l]))
             {
                 ind = Trie[q+1];
                 l++;
                 if (l>=TempS.length()) // if the number of already added symbols = string's length, this means its adding to Trie is completed
                     goto lj;
                 goto lq; // if no - let us observe Trie from begining after adding another symbol

             }

         }

         for (int w = l; w<TempS.length(); w++) // if we haven't add all symbols of adding string at the previous step (searching Trie for symbols matching) - lets add the rest now
         {
             Trie.push_back(ind);
             Trie.push_back(last+1);
             ind = last+1;
             last = ind;
             Trie.push_back( (int)TempS[w]);

         }



         lj: ;
     }

   return 0;
}



void Num (std::string & Numbers, std::vector <double> & A)
{
    // ��ॣ�� ��ப� � �᫠�� <double> � ���ᨢ (�����) �
    // converts string of numbers <double> (separated by spaces) to a vector of numbers

    A.clear();

    int q = 0;  // 㤠����� ��譨� �஡���� �᫨ ���� / deletind doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}


    std::string TempS = "";
    int b=0; //��砫� ������� �᫠ � ��ப�  / The start position of a number
    int e=0; // ����� �᫠ � ��ப� / the end position
    double r;  //� ����� ᠬ� �᫮ / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //�᫮ - �� ᫥���饣� �஡���
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atof(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // �� ���� ����� - �� ��᫥����� �஡��� �� ���� ��ப� / the last iteration - up to the string's end
    r = atof(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}



void Num (std::string & Numbers, std::vector <int> & A)
{
    // ��ॣ�� ��ப� � �᫠�� int � ���ᨢ (�����) �
    // converts string of numbers <int> (separated by spaces) to a vector of numbers


    A.clear();

    int q = 0;  // 㤠����� ��譨� �஡���� / deleting doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}

    std::string TempS = "";
    int b=0; //��砫� ������� �᫠ � ��ப�  / The start position of a number
    int e=0; // ����� �᫠ � ��ப� / the end position
    int r;  //� ����� ᠬ� �᫮ / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //�᫮ - �� ᫥���饣� �஡���
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atoi(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // �� ���� ����� - �� ��᫥����� �஡��� �� ���� ��ப� / the last iteration - up to the string's end
    r = atoi(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}



int Num (std::string & Numbers, int &a1,int &a2, double &a3)
// �ᯮ����⥫쭠� �㭪��: ��ॣ�� ��ப�, ᮤ�ঠ饩 3 �᫠, ࠧ�������� �஡����� (��� 楫��, ������� ���設� ॡ� � ������ double) ᮮ⢥��⢥��� � int a1,int a2, double a3. ��᫠ ������ ���� ࠧ������ �஡�����, � ����� ��祣� ��ப� ᮤ�ঠ�� �� ������.
// �����頥� -1 �᫨ ����� �訡�� ��室��� ������ (��� 3� "�������⮢ � �᫠").
// �� �⮬ �஢�ઠ �� �, �� ��������㥬�� � �᫮ �����ப� ᮤ�ন� ���� ���� � ������� ࠧ����⥫�, � ������ ���ᨨ �㭪樨 �� �஢������.
// Converts a string to 3 numbers (2 integers and 1 double; they should be separated by spaces in the string and the string should not contain any other symbols) to int &1,int a2, double a3.
// Returns -1 if input data is incorrect (no 3 "candidates to numbers" are found).
// But note that here is NO checking if a substring to be converted to a number contains digits and decimal point only.


{

    int q = 0;  // 㤠����� ��譨� �஡���� �᫨ ���� / deletind doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}


    std::string TempS = "";
    int b=0; //��砫� ������� �᫠ � ��ப�  / The start position of a number
    int e=0; // ����� �᫠ � ��ப� / the end position

    e = Numbers.find (" ", b)-1; //reading the first int - i.e. the first vertex of an edge
    if (e<0) return -1;
    TempS = Numbers.substr(b, e-b+1);

    a1 = atoi(TempS.c_str());
    b = e+2;TempS.clear();


    e = Numbers.find (" ", b)-1; //reading the second int - i.e. the second vertex of an edge
    if (e<0) return -1;
    TempS = Numbers.substr(b, e-b+1);

    a2 = atoi(TempS.c_str());
    b = e+2;TempS.clear();


    if (b>=Numbers.length()) return -1; // in this case string does not contain the 3th number

    e = Numbers.find (" ", b)-1;

    if (e<0) //There are no more " "
    {
        TempS = Numbers.substr(b, Numbers.length()-b);
        a3 = atof(TempS.c_str());
    }


    return 0;
}




int UWGraphRead (std::ifstream & fin, std::vector <int> & A)
// �⥭�� ������襭���� ��� � ����� ᬥ�����.
// ������� ����஬ ᬥ����� ��� ����襭���� ��� 㯮�冷祭�� ����� (���ᨢ) �⭮�� ���-�� �ᥫ (�[2i], a[2i+1],... / i �㬥����� c 0 /),
// ��� ������ ��� �ᥫ �[2i], a[2i+1] ������ ॡ� ��� ����� ���設��� �[2i] � a[2i+1] ("ᯨ᮪ ॡ�� � ��ப�").
// ����� �ଠ� �� ᮤ�ন� ���ଠ樨, ���� �� ��� �ਥ��஢���� ��� ��� (�������� ��� ��ਠ��). �� �ᯮ�짮����� �ଠ� ��� ���� ��⠥���, �� ॡ� ���ࠢ���� �� �[2i] � a[2i+1].
// �।���������� ���뢠��� �� 䠩��, ᮤ�ঠ饣� ᯨ᮪ ॡ�� (������ ॡ� - �⤥�쭠� ��ப�)
// �����頥� -1 � ���⮩ ����� A, �᫨ ����祭�� ����� ᬥ����� ���⮩ ��� �� �� ���뢠��� ��।���� ॡ� ��⠭� �� 2 ������� (�᫠)

// Reads Edge list to "Adjacency vector" of unweighted graph. Let "Adjacency vector" of unweighted graph be a data structure,
// that contains array of integers such as �[2i], a[2i+1],... / 0-basing indexing in array /.
// So such array contains even number of elements. Every pair �[2i], a[2i+1] means an edge between vertex �[2i] and �[2i+1] (~ "Edge list as one String").
// This format don't identify the graph as directed or undirected (both cases may be). If the graph is considered as directed, its edges should be considered as �[2i] -> a[2i+1].
// Input file should be in edge list format, every edge in new line.
// Returns -1 and empty "Adjacency vector" A if any line contains number of elements that !=2.


{
    std::string TempS = "";
    A.clear();
    std::vector <int> B1;

    while (!fin.eof())
    {
        B1.clear();
        getline (fin, TempS);
        if (TempS.length()!=0)
        {
             Num(TempS, B1);
             if (B1.size()!=2) {A.clear(); return -1;}
             A.push_back(B1[0]);
             A.push_back(B1[1]);
        }
    }

    if (A.size()==0) return -1;

    return 0;
}




int WGraphRead (std::ifstream & fin, std::vector <int> & A)
// �⥭�� ����襭���� ��� � ����� ᬥ�����. ������� ����஬ ᬥ����� ��� ����襭���� ��� 㯮�冷祭�� ����� (���ᨢ) �ᥫ (�[3i], a[3i+1], a[3i+2],... / i �㬥����� c 0 /), ��� ������ �ன�� �ᥫ �[3i], a[3i+1] ������ ॡ� ��� ����� ���設��� �[3i] � a[3i+1], � a[3i+2] ���� ��� �⮣� ॡ�, ("ᯨ᮪ ॡ�� � ��ப�").
// ���ᬠ�ਢ���� �ଠ� �� ᮤ�ন� ���ଠ樨, ���� ��� �ਥ��஢���� ��� ��� (�������� ��� ��ਠ��). �� �ᯮ�짮����� �ଠ� ��� ���� ��⠥���, �� ॡ� ���ࠢ���� �� �[3i] � a[3i+1].
// ������ ������� ������ �������� ����� �����, 祬 ����� ᬥ�����, � ����� ���� 㤮��� ��� �襭�� �鸞 �����.
// �।���������� ���뢠��� �� 䠩��, ᮤ�ঠ饣� ᯨ᮪ ᬥ����� (������ ॡ� - �⤥�쭠� ��ப�)
// �����頥� -1 � ���⮩ ����� A, , �᫨ ����祭�� ����� ᬥ����� ���⮩ ��� �� �� ���뢠��� ��।���� ॡ� ��⠭� �� 3 ������� (�᫠)

// Reads Edges list to "Adjacency vector" of weighted graph. Let "Adjacency vector" of weighted graph be a data structure, that contains array of integers such as �[3i], a[3i+1], a[3i+2],... / 0-basing indexing in array /.
// So such array contains 3n number of elements. Every pair �[3i], a[3i+1] means an edge between vertex �[3i] and �[3i+1] with weight a[3i+2]("Edge list as one String").
// This format don't identify the graph as directed or undirected (both cases may be). If the graph is considered as directed, its edges should be considered as �[3i] -> a[3i+1].
// Input file should be in edge list format, every edge in new line.
// Returns -1 and empty "Adjacency vector" A if any line contains number of elements of any line that !=3.


{
    std::string TempS = "";
    A.clear();
    std::vector <int> B1;

    while (!fin.eof())
    {
        B1.clear();
        getline (fin, TempS);
        if (TempS.length()!=0)
        {
             Num(TempS, B1);
             if (B1.size()!=3) {A.clear(); return -1;}
             A.push_back(B1[0]);
             A.push_back(B1[1]);
             A.push_back(B1[2]);
        }
    }

    if (A.size()==0) return -1;

    return 0;
}




int WGraphRead (std::ifstream & fin, std::pair < std::vector<int>, std::vector<double>> & A)
// ����䨪��� �㭪樨 WGraphRead (�. ���) ��� ���� ��楫��᫥���� ��ᮢ ॡ�� (double).
// �⥭�� �஢������ � ���� ����஢ pair < std::vector<int>, std::vector<double>> & A, ��� ���� ����� ���� ����஬ ᬥ����� ���뢠����� ��� ��� 㪠����� ��ᮢ,
// � ��ன ����� ᮤ�ন� ᮮ⢥����騥 ���. ���⢥�⢥��� ��� ॡ� ����������� ��ன ���設 ��� �����ᠬ� 2*i, 2*i+1 ��ࢮ�� ����� ��� �㤥� ࠢ�� �������� ��� �����ᮬ i ��ண� �����.

// Modification of the function WGraphRead (see it above) for not-integer (double) weihgts of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weigths are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    std::string TempS = "";
    (A.first).clear();
    (A.second).clear();

   int a1, a2;
   double a3;


    while (!fin.eof())
    {
        getline (fin, TempS);
        if (TempS.length()!=0)
        {
             if (Num(TempS, a1, a2, a3)==-1)
             {
                 (A.first).clear();
                 (A.second).clear();
                 return -1;
             }

             if (Num(TempS, a1, a2, a3)==0)
             {
                (A.first).push_back(a1);
                (A.first).push_back(a2);
                (A.second).push_back(a3);


             }
        }
    }

    if ((A.first).size()==0) return -1;

    return 0;
}





int RangeVGraph (std::vector <int> & A, int & mx, int & mn, const bool weighted, bool IgnoreWeighted = false)
//Finds max (i.e. mx) and min (i.e. mn) value of numbers that assigned to vertices
// Graph must be set as "Adjacency vector", bool "weighted" sets if the graph is weighted or no.
// If (IgnoreWeighted = true) the function looks at every element in A without any dataset checking
{

    mn = INT_MAX;
    mx = INT_MIN;

    if (A.size()==0) return -1;

    if (IgnoreWeighted == false)
    {
    if ( (A.size())%(2+weighted)!=0 ) return -1;

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        if (A[q]>mx) mx = A[q];
        if (A[q+1]>mx) mx = A[q+1];

        if (A[q]<mn) mn = A[q];
        if (A[q+1]<mn) mn = A[q+1];
    }

    }

    if (IgnoreWeighted == true)
    {
        for (int q=0; q<A.size(); q++)
        {
            if (A[q]>mx) mx = A[q];
            if (A[q]<mn) mn = A[q];
        }

    }

    return 0;
}




int RenumVGraph (std::vector <int> & A, const int d, const bool weighted, bool IgnoreWeighted = false)
//Renumerates vertices adding d-parameter (d may be non-negative or negative) / ��७㬥஢뢠���� ���設� ���: �ਡ����� ����稭� d (����� ���� ������⥫쭮� � ����⥫쭮�)
// Graph must be set as "Adjacency vector", bool "weighted" sets if the graph is weighted or no.
// If (IgnoreWeighted = true) the function adds d to every element in A without any dataset checking


{

    if (A.size()==0) return -1;

    if (IgnoreWeighted == false)
    {
        if ( (A.size())%(2+weighted)!=0 ) return -1;

        for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
        {
            A[q] = A[q]+d;
            A[q+1] = A[q+1]+d;
        }
    }

    if (IgnoreWeighted == true)
    {
        for (int q=0; q<A.size(); q++)
        {
            A[q] = A[q]+d;

        }

    }



    return 0;
}




int AdjVector2AdjMatrix (std::vector <int> & A, std::vector <std::vector <int>> &B, const bool weighted, const bool directed)
//Converts "Adjacency vector" to "Adjacency matrix".
// bool "weighted" sets if the graph is weighted or no. bool "directed" sets if the graph is directed or no.
// In case of multiple edges for a weighted graph only the last edge will be written to Adjacency matrix, others will be lost.
// Loops for undirected unweighted graph counts as 2 edges
// In this function zero-value of any item of Adjacency matrix means no edge both for unweighted and weighted graph

{

    B.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1;

    int mx, mn;

    RangeVGraph (A, mx, mn, weighted);

    if (mn<0) return -1;

    MatrixSet(B, mx+1, mx+1, 0);

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        if ( (weighted==false) && (directed==true) ) B[(A[q])][(A[q+1])]++;
        if ( (weighted==true) && (directed==true) ) B[(A[q])][(A[q+1])]= A[q+2];

        if ( (weighted==false) && (directed==false) ) {B[(A[q])][(A[q+1])]++; B[(A[q+1])][(A[q])]++;}
        if ( (weighted==true) && (directed==false) ) {B[(A[q])][(A[q+1])]= A[q+2]; B[(A[q+1])][(A[q])]= A[q+2];}

    }
    return 0;
}



int AdjVector2AdjMatrix (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <std::vector <double>> &B, const bool directed)
// Modification of the function AdjVector2AdjMatrx (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.
// Note that undirected graph may have only zeros lower than the Main diagonal of its Adjacency matrix here

{
    B.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    int mx, mn;

    RangeVGraph (A.first, mx, mn, false);

    if (mn<0) return -1;

    MatrixSet(B, mx+1, mx+1, 0.0);

    for (unsigned int q=0; q<(A.second).size(); q++)
    {
        if ( directed==true ) B[((A.first)[2*q])][((A.first)[2*q+1])]= (A.second)[q];

        if (directed==false)
        {
            if ((A.first)[2*q]<=(A.first)[2*q+1]) B[(A.first)[2*q]][(A.first)[2*q+1]]= (A.second)[q];
            if ((A.first)[2*q]>(A.first)[2*q+1])  B[(A.first)[2*q+1]][(A.first)[2*q]]= (A.second)[q];
        }

    }

    return 0;
}



int AdjMatrix2AdjVector (std::vector <int> & A, const std::vector <std::vector <int>> &B, const bool weighted, const bool directed)
// Converts "Adjacency matrix" to "Adjacency vector".
// bool "weighted" sets if the graph is weighted or no. bool "directed" sets if the graph is directed or no.
// For a weighted graph here are no multiple edges.
// Loops for an undirected unweighted graph counts as 2 edges
// For an undirected graph the data that is lower than the Main diagonal of the matrix B is ignored
// In this function zero-value of any item of Adjacency matrix means "no such edge" both for unweighted and weighted graph


{

    A.clear();
    if (B.size()==0) return -1;

    for (int y=0; y<B.size(); y++)  // lets test: if the matrix B is a "square"
        if (B.size()!=B[y].size()) return -1; // ��� �� �����⭮���


    int t;
    int c = 0;

    for (int i=0; i<B.size(); i++)
    {
        if (directed==false) c = i;
        for (int j=c; j<B.size(); j++) // for undirected graph lets see only not lower than Main diagonal
        {
            t = B[i][j];
            if (t==0) continue;

            if ( (weighted==false)&&(directed==true)  )
            {
                if (t<0) {A.clear(); return -1;}

                for (int x = 0; x<t; x++)
                {
                    A.push_back(i);
                    A.push_back(j);
                }
            }

            if ( (weighted==true)&&(directed==true)  )
            {
                    A.push_back(i);
                    A.push_back(j);
                    A.push_back(t);
            }


            if ( (weighted==false)&&(directed==false)  )
            {
                if (t<0) {A.clear(); return -1;}

                if ((i==j) && ((t%2)!=0) )  {A.clear(); return -1;} // Loops for undirected unweighted graph counts as 2 edges
                if ((i==j)) t = t/2;



                for (int x = 0; x<(t); x++)
                {
                    A.push_back(i);
                    A.push_back(j);
                }

            }

            if ( (weighted==true)&&(directed==false)  )
            {
                A.push_back(i);
                A.push_back(j);
                A.push_back(t);
            }


        }

    }

    return 0;
}



int AdjMatrix2AdjVector (std::pair < std::vector<int>, std::vector<double>> & A, const std::vector <std::vector <double>> &B, const bool directed)
// Modification of the function AdjMatrix2AdjVector (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.
// For an undirected graph the data that is lower than the Main diagonal of the matrix B is ignored

{

    (A.first).clear();
    (A.second).clear();

    if (B.size()==0) return -1;

    for (unsigned int y=0; y<B.size(); y++)  // lets test: if the matrix B is a "square"
        if (B.size()!=B[y].size()) return -1; // ��� �� �����⭮���


    double t;
    int c = 0;

    for (int i=0; i<B.size(); i++)
    {
        if (directed==false) c = i;
        for (int j=c; j<B.size(); j++) // for undirected graph lets see only not lower than Main diagonal
        {
            t = B[i][j];
            if (t==0.0) continue;


            if (directed==true)
            {
                    (A.first).push_back(i);
                    (A.first).push_back(j);
                    (A.second).push_back(t);
            }


            if (directed==false)
            {

                (A.first).push_back(i);
                (A.first).push_back(j);
                (A.second).push_back(t);
            }
        }
    }

    return 0;
}




int CheckUnvisit (std::vector <int> & Visited) // �ᯮ����⥫쭠� �㭪�� ��� ���᪠ ��ࢮ� ������祭��� ���設� � ���
// An auxiliary function that finds the first unmarked vertex in the graph (0 means unmarked)

{
    int b = -1;

    for (unsigned int w = 0; w<Visited.size(); w++)
        if (Visited[w] ==0)   // �饬 ����� ��ࢮ� ������������ ���設�
        {b=w; break;}

    return b;
}




void EcycleDGraph (int t, std::vector <int> & R, const int V, std::vector <std::vector<int>> &B)
// �ᯮ����⥫쭠� �㭪�� ��� ���᪠ ����஢� 横�� � ��������������� ���, ��� �� �������� �������, ��� �����஢����� ���設 � �㬥��� ���設 ���� � 1.
// B - ����� ᬥ�����, ᮤ�ঠ�� ���-�� ॡ�� ����� ���設���, V - ���ᨬ���� ����� ���設�

// An auxiliary function that finds Eulerian cycle in the DIRECTED graph without without checking of input data correctness
//(i.e. (1) the graph includes Eulerian cycle, (2) its vertices numbers start from "1", (3) the graph doesn't contain any isolated vertices).
// B is the Adjacency matrix, containing the number of edges between the vertices. V is the max number assigned to vertices.



{

    int f = 1;

    while (f!=0)  // ��ந� ��稭�� � ���設� �� ����஬ t ���� � ���ન���� �ன����� ॡ� // Building up the path from vertex � t
    {

        for (int i = 1; i<(V+1); i++)
        {
            if (B[t][i]>=1)
            {

            R.push_back(t);
            B [t][i]--; // ॡ� ���ભ㫨 // deleting edge
            t = i; // ����� �饬 � ᫥���饩 ���設� // tet's continue from the end vertex of the deleted edge
            goto l1;
            }

        }
        f = 0;

        l1: ;



    }

    std::vector <int> T;
    T.clear();

    if (R.size()!=0)  // � ⥯��� �饬 �������� 横�� ("����"), �⭮��騥�� � �����-���� ���設� �� 㦥 ����஥����� � R ���. � ⠪ ����७⭮ ("�����" ����� ᮤ�ঠ�� �� "�����" � �.�.)
        // Now we should search for cycles related to every vertex of the path in the vector R recurrently.

    {

    for (unsigned int j = 0; j<R.size(); j++)
    {
        T.clear();
        EcycleDGraph (R[j], T, V, B);

        if (T.size()!=0)  // � �᫨ ⠪�� "�����" ���� // And if we have found such cycle
        {
        T.push_back(R[j]); // lets finish the cycle by pushing back R[j] - it is both its begin and its end.
        for (unsigned int w = (j+1); w<R.size(); w++) // And then lets add to it the rest of the path. So we have in T the Path with cycle related to R[j]-vertex added.
            T.push_back(R[w]); // �������� ��� ���祭��� R[j] (�� ��� � ��砫� � �����) � ��⥬ ��ᮢ��㯨� ���⮪ ��� �� R. �� � �㤥� ����砫�� ����, � ����� ��⠢��� ���� �� "�����" �� ���設� R[j]


        R.resize(j); // ������ ������� ᠬ R. ��०�� ��, �� ����� ���設� R[j] � ������� ����� �⮣� �⪮�४�஢���� ���� �� T
        for (unsigned int e = 0; e<T.size(); e++) // Now it is time to update R. Lets cut all that is further than R[j] and add updated path from T (it contains cycle related to R[j]-vertex now)
            R.push_back(T[e]);
        T.clear();

        }


    }

    }

}





int EPathDGraph (std::vector <int> & A, std::vector <int> & R, const bool weighted, std::vector <int> & Isolated)
// ���� ����஢� ��� ���� ����஢� 横�� � ��������������� ���. �ਭ����� �� �室 ����� ᬥ����� ��� � 㪠������, ����襭�� �� ���, � ⠪�� ����⮢�� R ��� ���������� ��� (横��) � Isolated ��� �����஢����� ���設.
// �� �⮬ �� ��⠥��� �����஢����� ���設�, ������ ���� ��⫨.
// �����頥� ���������� R � Isolated (�᫨ ���� ���� ���� 横�, �� �⮬ �����頥�� ���祭�� ᮮ⢥��⢥��� 2 � 1) � ����� ����� � -1, �᫨ �� �� �������.
// ����஢ ����/ 横� ����� �� �ᥬ ���, ���� �� �����⢥���� ��������� �吝���, �� �᫮��� �� ��稥 ���設� - �����஢����.
// ����� ࠡ���� � �ਥ��஢���묨 ��䠬� � �㡫����騬� ॡࠬ� � � ������⢥��묨 ���ﬨ. �㬥��� ���設 ����� �����⢫����� ��묨 楫묨 �᫠��, � �.�. ����⥫�묨. �� �⮬ ��⠥���, �� ��� ᮤ�ন� �� ���設�, ᮮ⢥�����騥 �ᥬ �᫠� �� min (1, ��������� ������� ����� ���設�) �� ���ᨬ���� ������� ����� ���設� �����⥫쭮.
// � ����� ࠡ��� ��� �ਢ������ � ����, �⮡� ���設� �㬥஢����� ��稭�� � 1. �� ����砭�� ࠡ��� ��室��� �㬥��� ����⠭����������.

// Finding Eulerian Cycle or Path in directed graph (weighted or non-weighted) that may contain multiple edges and multiple loops.
// Returns Path/ Cycle as R, isolated vertices as Isolated. Returns value "1" if Eulerian cycle has been found or value "2" if Eulerian path has been found or "-1" together with empty R and Isolates if no cycle/ path found.
// If any vertex has loops only, such a vertex is not considered as an isolated one.
// Vertices may be numbered in different ways (they may be marked by both negative and non-negative integers). In doing so, we set that the graph contains vertices marked by all the integers from min (1, minimal number assigned to vertices) to maximal number assigned to vertices inclusive.
// In order to implement the function vertices may be renumbered to get started from "1"; after search is completed, the vertices will be assigned their original numbers.


{
    R.clear(); // ����� �㤥� �᪮�� 横�/ ���� // vector for Eulerian cycle/ path
    Isolated.clear(); // ����� ���� �࠭����� �������� �����஢���� ���設� // vector for isolated vertices.


    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    int V; // ����� �㤥� ���ᨬ���� ����� ���設� // the max number of assigned to vertices
    int E = A.size()/(2+weighted); // the total number of edges in the graph


    int mn;
    RangeVGraph (A, V, mn, weighted);

    if (mn<1)  // �ਢ������ ����� � �㬥஢���� ���設 � 1 // renumbering vertices to start from 1.
    {
        RenumVGraph (A, (1-mn), weighted);
        V = V+(1-mn);
    }

    std::vector <int> Visited (V+1, 0); // �㫥��� ������� �ᯮ�짮���� �� �㤥�: �㬥������ ���設� � 1
    Visited [0] = 1;

    std::vector <int> Vin(V+1, 0); //��� ������ �室��� � ��室��� � ���設�
    std::vector <int> Vout (V+1, 0); // for counting in-edges and out-edges

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        Vin[(A[q+1])]++;
        Vout[(A[q])]++;
    }

    int t1, t2;
    int c=0;
    int c0=0;
    int c2=0;
    int c1=0;

    for (int a = 1; a<=V; a++)
    {
        if ((Vin [a]==0) && (Vout [a]==0) ) {Visited [a]=2;Isolated.push_back(a);c0++;continue;} // ⠪�� ���設� - �����஢����� // such a vertex is isolated
        if (Vin [a]==Vout [a]) {c++; continue;} // � ⠪�� �室� = ��室��, ��⠥� �� //such a vertex has the number of in-edges = the number of out-edges. Lets count these vertices.
        if ((Vin [a]-Vout [a])==1) {c2++; t2 = a; continue;} // � ⠪�� �� 1 ����� �室��, ��⠥� �� � ���������� ��᫥����/ // such a vertex has the number of in-edges - the number of out-edges = 1. Lets count them and remember the last one.
        if ((Vin [a]-Vout [a])==-1) {c1++; t1 = a; continue;} // � � ⠪�� - ��室��, ��⠥� �� � ���������� ��᫥����// such a vertex has the number of in-edges - the number of out-edges = -1. Lets count them and remember the last one.


    }


    std::vector <std::vector <int>> B;
    MatrixSet(B, V+1, V+1, 0);


    for (unsigned int x = 0; x<A.size()-1-weighted; x = x+2+weighted)  // ��ନ�㥬 ������ ᬥ����� B, ᮤ�ঠ��� ��-�� ॡ�� ���� ��� ����襭��� ��䮢
        // Forming Adjacency matrix and filling it with the number of edges between vertices.
    {
        B[(A[x])][(A[x+1])]++;

    }

    int t = CheckUnvisit(Visited); // ��筥� �᪠�� ����/横� � �� �������஢����� ���設� // Lets start search from any non-isolated vertex
    sort (Isolated.begin(), Isolated.end());

    if ( ((c+c0)==V) && (c>=1) )  //In this case we may have a Cycle
    {
        EcycleDGraph(t, R, V, B); // ��ନ�㥬 横� // find the cycle
        if (mn<1) // � �᫨ ���� ��७㬥஢뢠�� ���設� ����� �᫨ ����室��� // Renumbering all the vertices back if needed
        {
            RenumVGraph (A, (-1+mn), weighted);
            RenumVGraph (R, (-1+mn), false, true);
            RenumVGraph (Isolated, (-1+mn), false, true);
        }
        R.push_back(R[0]); // � 横�� ��砫� = �����

        if ((R.size()-1)!=E) {Isolated.clear(); R.clear(); return -1;} // all the edges must be in R, the total number of edges = E

        return 1;  //This means "Found Eulerian cycle"
    }


    if (((c+c0+c1+c2)==V) && (c1==1) && (c2==1)) // ����室���� �᫮��� ������ ��� // in this case we may have Path
    {

        B[t2][t1]++; // ������� �������饥 �� 横�� ॡ� // adding edge in order to complete path to cycle
        EcycleDGraph(t1, R, V, B);  // find the cycle

        R.push_back(R[0]);

        for (int i = 0; i<(R.size()-1); i++)  // rearranging cycle to path
            if ((R[i] == t2) && (R[i+1] == t1))
            {
                R.pop_back();
                for (int q = (i+1);q<R.size();q++)
                {    R.insert(R.begin(), R[R.size()-1]); R.pop_back();}

            }


        if (mn<1) // Renumbering all the vertices back if needed
        {

            RenumVGraph (A, (-1+mn), weighted);
            RenumVGraph (R, (-1+mn), false, true);
            RenumVGraph (Isolated, (-1+mn), false, true);

        }

        if ((R.size()-1)!=E) {Isolated.clear(); R.clear(); return -1;} // all the edges must be in R, the total number of edges = E

        return 2; // This means "Found Eulerian path"

    }


    Isolated.clear();
    R.clear();
    if (mn<1) // Renumbering all the vertices back if needed
    {

        RenumVGraph (A, (-1+mn), weighted);

    }

    return -1;
}


int EPathDGraph (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <int> & R, std::vector <int> & Isolated)
// ����䨪��� �㭪樨 EPathDGraph (�. ���) ��� ���� ��楫��᫥���� ��ᮢ ॡ�� (double).
// Modification of the function EPathDGraph (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    R.clear(); // ����� �㤥� �᪮�� 横�/ ���� // vector for Eulerian cycle/ path
    Isolated.clear(); // ����� ���� �࠭����� �������� �����஢���� ���設� // vector for isolated vertices.

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    return EPathDGraph (A.first, R, false, Isolated);

}



int DFSTS (const std::vector <int> & A, const int b, std::vector <int> & Visited, std::vector <int> & order, const bool weighted)
// �ᯮ����⥫쭠� �㭪�� ��� �㭪樨 TSortHP. �஢�ન ��室��� ������ �� �஢������, ���設� � �ਥ��஢����� ����, �������� ����஬ ᬥ����� A, �.�. �㬥஢��� � 1.
// ��� ����� ᮤ�ঠ�� ��⫨ (�����������).
// � ����� ��室� ���訢��� ���設� � ���ᨢ� Visited: 0 - �����饭��� (�����), 1 - ���饭�, �� �� ��ࠡ�⠭� (���), 2 - ��ࠡ�⠭� (�ୠ�).
// weighted - ��⨭�, �᫨ ����襭�� ���, ���� - ����.
// �᫨ ������ 横� - �����頥� 1 � ���⮩ order.

// An auxiliary function for the function TSortHP. Works without any checking of input data correctness. Vertices in the input directed graph (it is set by the Adjacency vector A) are to be numbered starting from 1.
// The graph may contain loops (they will be ignored).
// During building topological sorting we shall colour vertices (using vector Visited): 0 = unvisited (white), 1 = visited, but not still finished yet (grey), 2 = finished (black).
// Bool "weighted" should be set as "true" for weighted graph, "false" for unweighted.
// If the graph contains cycle - returns 1 and empty "order".



{

    Visited [b] = 1;  // b - the vertex to start with. Vertex is to become grey when starting working with it
    int f;


    for (unsigned int r = 0; r+1+weighted<=A.size(); r=r+2+weighted)
    {


        if ( (A[r]==b) && (A[r+1]==b) ) continue; // �᫨ ���� - ���� ����� //if a loop found - let's continue, loop will be ignored

        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 1) )  // in this case a cycle is found
        {
            order.clear();
            return 1;
        }


        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0) )  // ��諨 �����饭���? �����饭��� = 0  //found a non-visited vertex
        {
           Visited[(A[r+1])] = 1;
           f=DFSTS (A, (A[r+1]), Visited, order, weighted);
            if (f==1)
            {
                order.clear();
                return 1;
            }

        }


    }

    order.push_back(b);
    Visited [b] = 2;  // ��ࠡ�⠫� � ��४�ᨫ� � ��� (=2) // now the vertex is to become black (=2)

return 0;
}


int TSortHP (std::vector <int> & A, std::vector <int> & R, std::vector <int> & order, std::vector <int> & Isolated, const bool weighted, const bool OnlyTS = false)
// �㭪�� ��� ⮯������᪮� ���஢�� � ����. ����� � ��砥 ������ ⮯������᪮� ���஢�� (� �� �᫮��� OnlyTS = false) ��� ������⮭�� ���� � ���祭� �����஢����� ���設. �� �⮬ �� ��⠥��� �����஢����� ���設�, ������ ���� ��⫨.
// �㭪�� �� ���� �㭪樥� ���᪠ ������ ������⮭��� ���, �� ����� ������ � ��砥 ������ ⮯������᪮� ���஢��.
// �ਭ����� �� �室 ����� ᬥ����� ��� A � 㪠������, ����襭�� �� ��� (��ࠬ��� weighted), � ⠪�� ����⮢�� R ��� ������⮭��� ���, order ��� ⮯������᪮� ���஢��, Isolated ��� ����� �����஢����� ���設.
// ����� ࠡ���� � �ਥ��஢���묨 ��䠬� � �㡫����騬� ॡࠬ� � � ������⢥��묨 ���ﬨ (��⫨ ���� �����஢�����).
// �㬥��� ���設 ����� �����⢫����� ��묨 楫묨 �᫠��, � �.�. ����⥫�묨. �� �⮬ ��⠥���, �� ��� ᮤ�ন� �� ���設�, ᮮ⢥�����騥 �ᥬ �᫠� �� min (1, ��������� ������� ����� ���設�) �� ���ᨬ���� ������� ����� ���設� �����⥫쭮.
// � ����� ࠡ��� ��� �ਢ������ � ����, �⮡� ���設� �㬥஢����� ��稭�� � 1. �� ����砭�� ࠡ��� ��室��� �㬥��� ����⠭����������.
// �᫨ OnlyTS == false (��ଠ�쭠� ࠡ�� �㭪樨):
// �����頥� 0, �᫨ ������� � ⮯������᪠� ���஢��, � ������⮭�� ����.
// �����頥� -1 � ����� R, order, Isolated, �᫨ � ��� ������ 横�.
// �����頥� 1 � ���⮩ R, �᫨ ���� ⮯������᪠� ���஢��, � ������⮭��� ��� ���.
// �᫨ ��ࠬ��� OnlyTS == true, � ����� ⮫쪮 ⮯������᪠� ���஢�� (����� ०�� �।�ᬮ�७ ��� �᪮७�� ࠡ���). �����頥� 0, �᫨ ��� ������� � -1 �᫨ ���. ������⮭�� ���� � �����஢���� ���設� �� ���������� (R � Isolated ���� ����� � �� ��砥).

// The function finds topological sorting of directed graph (returned as vector "order").
// ONLY IF topological sorting exists AND OnlyTS == false the function also checks for Hamiltonian path (returned as vector R) and list of Isolated vertices (returned as vector Isolated).
// The graph is set by Adjacency vector A, may be weighted or no (bool weighted).
// The graph may contain loops (they will be ignored).
// If any vertex has loops only, such a vertex is not considered as an isolated one.
// The graph may contain multiple edges.
// Vertices may be numbered in different ways (they may be marked by both negative and non-negative integers). In doing so, we set that the graph contains vertices marked by all the integers from min (1, minimal number assigned to vertices) to maximal number assigned to vertices inclusive.
// In order to implement the function vertices may be renumbered to get started from "1"; after search is completed, the vertices will be assigned their original numbers.
// So if OnlyTS == false:
// the function returns 0 if both topological sorting and Hamiltonian path found.
// the function returns -1 and empty Isolated, order, R if the graph contains cycle.
// the function returns 1 if topological sorting found and, upon that, Hamiltonian path doesn't exist.
// If OnlyTS == true, both R and Isolated will be returned empty (to make this function faster). The function returns 0 if topological sorting is found and -1 otherwise.



{
    R.clear(); order.clear(); Isolated.clear();



    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    int Vg; // ����� �㤥� ���ᨬ���� ����� ���設� // the max number of assigned to vertices
    int E = A.size()/(2+weighted); // the total number of edges in the graph


    int mn;
    RangeVGraph (A, Vg, mn, weighted);

    if (mn<1)  // �ਢ������ ����� � �㬥஢���� ���設 � 1 // renumbering vertices to start from 1.
    {
        RenumVGraph (A, (1-mn), weighted);
        Vg = Vg+(1-mn);
    }

    if (!OnlyTS)
    {
    std::vector <int> Vin(Vg+1, 0); //��� ������ �室��� � ��室��� � ���設�
    std::vector <int> Vout (Vg+1, 0); // for counting in-edges and out-edges


    // ���� �����஢�����
    // Let's find isolated vertices

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        Vin[(A[q+1])]++;
        Vout[(A[q])]++;
    }


    for (int a = 1; a<=Vg; a++)
        if ((Vin [a]==0) && (Vout [a]==0) ) Isolated.push_back(a);

    if (mn<1) // Renumbering all the vertices back if needed
    {

        RenumVGraph (Isolated, (-1+mn), false, true);

    }

    // ����� ���᪠ �����஢����� // end of finding isolated vertices
    }

    std::vector <int> Visited (Vg+1, 0); // �㫥��� ������� �ᯮ�짮���� �� �㤥�: �㬥������ ���設� � 1  // all vertices are to be numbered starting from 1
    Visited [0] = 1;
    int b=CheckUnvisit(Visited);  // ���設� ��㤠 ���� ����  // let's start from here

    int f;

    while (CheckUnvisit(Visited)!=-1)
    {
        b=CheckUnvisit(Visited);  // ��६ ����� �� �����饭��� ���設�  // vertex not visited yet



         f=DFSTS (A, b, Visited, order, weighted);
         if (f==1)
         {
             R.clear();
             Isolated.clear();

             if (mn<1) // Renumbering all the vertices back if needed
             {

                 RenumVGraph (A, (-1+mn), weighted);

             }

             return -1; // cycle is found
         }

    }

    reverse (order.begin(),order.end());  // � ���ᨢ� order - १���� ⮯������᪮� ���஢��  // order contains topological sorting


    if (!OnlyTS)
    {

    std::vector < std::vector <int> > B;
    MatrixSet(B, Vg+1, Vg+1, 0);


    for (unsigned int x = 0; x<A.size()-1-weighted; x = x+2+weighted)  // ��ନ�㥬 ������ ᬥ����� B, ᮤ�ঠ��� ��-�� ॡ�� ���� ��� ����襭��� ��䮢
        // Forming Adjacency matrix and filling it with the number of edges between vertices.
    {
        if (A[x]!=A[x+1]) B[(A[x])][(A[x+1])]++;

    }



    int y = 1;

    if (order.size()==1) y=-1;


    for (unsigned int z = 0; z<(order.size()-1); z++)
    {
        if (B[(order[z])][(order[z+1])] < 1)
        {y=-1;break;}

    }




        if (y==-1)
        {
            R.clear();
                if (mn<1) // Renumbering all the vertices back if needed
                {

                    RenumVGraph (A, (-1+mn), weighted);

                    RenumVGraph (order, (-1+mn), false, true);

                }
                return 1; // means no Hamiltonian Path found, only Topological Sorting returned

        }
        else
        {

            for (unsigned int i=0; i<order.size(); i++)
            {R.push_back(order [i]);

            }
        }

    }


            if (mn<1) // Renumbering all the vertices back if needed
            {

                RenumVGraph (A, (-1+mn), weighted);
                RenumVGraph (R, (-1+mn), false, true);
                RenumVGraph (order, (-1+mn), false, true);

            }

        return 0; // means both Hamiltonian Path and Topological Sorting returned
}




int TSortHP (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <int> & R, std::vector <int> & order, std::vector <int> & Isolated, const bool OnlyTS = false)
// ����䨪��� �㭪樨 TSortHP (�. ���) ��� ���� ��楫��᫥���� ��ᮢ ॡ�� (double).
// Modification of the function TSortHP (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    R.clear(); order.clear(); Isolated.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    return TSortHP (A.first, R, order, Isolated, false, OnlyTS);

}



int DistanceBFA (std::vector <int> &A, std::vector <long long int> & D, const int b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)
{

    // ������뢠�� ����ﭨ� �� �������� ���設� b �� ��� ���� � ���� (�ᯮ������ ��⮤ ���᪠ � �ਭ�).
    // �����頥��� 1 � ��砥 �ᯥ� (����� D ᮤ�ন� ���砩訥 ����ﭨ� �� ���設� b �� ���設� i, � ����� Prev - ������ ���設-�।��� � ⠪�� ���).
    // �� 㬮�砭�� ����� D ᮤ�ন� ���祭�� LLONG_MAX, � ����� Prev - "-1".
    // �᫨ � 室� ࠡ��� �����㦥� 横� ����⨢���� ���, � �㭪�� �����頥� -1 � ����� ����� D � Prev.
    // �� �室� �.�. ���, ������� ����஬ ᬥ����� A (��⠥���, �� ���設� �㬥������ � 0), ����� ��室��� ���設� b � 䫠�, ���� �� ��� ����襭�� (const bool weighted). ��� ������襭��� ��⠥���, �� ������ ॡ� ����� ��� = 1.
    // ����� �� �室 �������� ����� �������襩 ���設� V (�᫨ �� ��।��, �����뢠���� ᠬ����⥫쭮 ��� ����� �������襩 ���設� � ॡ��)
    // �㭪�� ࠡ�⠥� � ����襭�묨 � � ������襭�묨 ��䠬�, ��祬 ��� ����� ᮤ�ঠ�� ��⫨ � ������⢥��� ॡ�. ���� ����� ����� ��� ������⥫�� (� �.�. � �㫥���), ⠪ � ����⥫�� ���.

    // The function counts the shortest distances from the vertex b to all vertices in the graph (these distances are to be contained in vector D, i.e. D[i] means the shortest distance from b to I).
    // By default vector D is filled with LLONG_MAX.
    // Vector Prev is intended to contain the number of the previous vertex for every vertex in such shortest paths ("-1" value is set by default and means "this vertex doesn't included in any such path").
    // The Breadth-first search method is used here.
    // The input graph should be directed, both weighted or unweighted (in case of unweighted graph we consider every edge's weight as "1".) The graph may have loops and multiple edges.
    // Input data: Adjacency vector A (it is supposed that vertices are numbered starting from 0) and the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A)
    // The edges may have weight of 0, >0, <0.
    // In case we found a negative weight cycle as well as input data is incorrect the function returns "-1" and empty D and Prev.


    D.clear();
    Prev.clear();

    if (A.size()==0) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness




    int E = A.size()/(2+weighted); // the total number of edges in the graph


    int mn, mx;
    RangeVGraph (A, mx, mn, weighted);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // ����� �㤥� ���ᨬ���� ����� ���設� // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, LLONG_MAX); // �� 㬮�砭�� ����ﭨ� ࠢ�� + ��᪮��筮��� // The default distance values is LLONG_MAX for every vertex


    Prev.resize(V+1, -1); // �� 㬮�砭�� "�।��" ���. // The previous vartexes are not set by default (i.e. =-1 for every vertex)


    std::queue <int> Q; //����� ��।�


   D[b] = 0; //���⠭�� �� ��ࢮ� ���設� �� ᥡ� = 0 // the distance from starting vertex to itself = 0

   Q.push (b);

    unsigned int j;
    int i;
    long long int count = 0;
    long long int c = (long long int)(V*E);




    while (!(Q.empty()))
    {
        j = 0;// ������ �஡��� �� ������ ᬥ����� A // indexes of beginning-vertices of edges in A
        i = Q.front(); // ����� ��।��� ���設� �� ��।� � ��ᬮ�७�� (������塞 � �����, ���⠥� � ��砫�) // number of vertex to continue from

        while (j<=A.size()-2-weighted) // lets look through A
        {

            if (weighted)
            {
                // for a weighted graph:

                if (  (A[j]==i) &&  (A[j+1]==i) &&  (A[j+2]<0) )  {D.clear(); Prev.clear(); return -1;} // i.e. we have found a negative weight loop

                if (  (A[j]==i) && ((D[ (A[j+1] )] == LLONG_MAX) || (D[ (A[j+1]) ] > (D[ i ]+ (long long int)(A[j+2]) ) ))  )
                // we should recount distance if we have found non-visited vertex or we may reduce its distance from vertex b.

                {
                    Q.push(A[j+1]);  //��� j+1 ���設� - � ��।� // in this casr we should push such vertex to quenue Q
                    count++;
                    D[(A[j+1])] = D[(i)]+(long long int)(A[j+2]); // �� ��� ����⠥� ���⠭�� // and recount its distance from b

                    Prev [(A[j+1])] = i;// � �।�� // and reset its previous vertex too
                }

            }

            if (!weighted)
            {
            // ��� ������襭���� �� �������筮, �� ��⠥� �� ��� ������� ॡ� =1
            // for an unweighted graph lets put every edge has distance =1.


                if (  (A[j]==i) && ((D[ (A[j+1] )] == LLONG_MAX) || (D[ (A[j+1]) ] > (D[ i ]+1) ))  )
                //�᫨ ��諨 ���設� i � ᫥����� �� ��� (�� ����஬ j+1 � ����� �): (1) �� ��室��� (�� ���ன ��⠥�, ࠢ��� b),
                // � (2) ���⠭�� �� ��� ࠢ�� LLONG_MAX (⠬ �� �� �뫨) ���� ����� ���⠭樨 �� i, 㢥��祭��� �� A[j+1] (���� �१ i + ��᫥���� ॡ� �� i)
                // we should recount distance if we have found non-visited vertex or we may reduce its distance from vertex b.

                {
                    Q.push(A[j+1]);  //��� j+1 ���設� - � ��।� // in this casr we should push such vertex to quenue Q
                    count++;
                    D[(A[j+1])] = D[(i)]+1; // �� ��� ����⠥� ���⠭�� // and recount its distance from b

                    Prev [(A[j+1])] = i;// � �।�� // and reset its previous vertex too
                }

            }

            j = j+2+weighted;
        }

        Q.pop();

        if (count > (c)) //�����, �� ��⪭㫨�� �� 横� ����⥫쭮�� ��� // This means we found a negative weight cycle
        {
            D.clear();
            Prev.clear();

            return -1;
        }

    }




    return 0;
}



int DistanceBFA (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, std::vector <int> & Prev, int V = INT_MIN)
// ����䨪��� �㭪樨 DistanceBFA (�. ���) ��� ���� ��楫��᫥���� ��ᮢ ॡ�� (double).
// Modification of the function DistanceBFA (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.

{
    D.clear();
    Prev.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;



    if ((V<0)&&(V != INT_MIN)) return -1;





    int E = (A.first).size()/(2); // the total number of edges in the graph


    int mn, mx;
    RangeVGraph (A.first, mx, mn, false);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // ����� �㤥� ���ᨬ���� ����� ���設� // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, INFINITY); // �� 㬮�砭�� ����ﭨ� ࠢ�� + ��᪮��筮��� // The default distance values is INFINITY for every vertex


    Prev.resize(V+1, -1); // �� 㬮�砭�� "�।��" ���. // The previous vartexes are not set by default (i.e. =-1 for every vertex)


    std::queue <int> Q; //����� ��।�


   D[b] = 0.0; //���⠭�� �� ��ࢮ� ���設� �� ᥡ� = 0 // the distance from starting vertex to itself = 0

   Q.push (b);

    unsigned int j;
    int i;
    long long int count = 0;
    long long int c = (long long int)(V*E);




    while (!(Q.empty()))
    {
        j = 0;// ������ �஡��� �� ������ ᬥ����� A // indexes of beginning-vertices of edges in A
        i = Q.front(); // ����� ��।��� ���設� �� ��।� � ��ᬮ�७�� (������塞 � �����, ���⠥� � ��砫�) // number of vertex to continue from

        while (j<A.second.size()) // lets look through A
        {


                if (  ( (A.first)[2*j]==i) &&  ( (A.first)[2*j+1]==i) &&  ( (A.second)[j]<0) )  {D.clear(); Prev.clear(); return -1;} // i.e. we have found a negative weight loop

                if (  ( (A.first)[2*j]==i) && ( (D[ (A.first)[2*j+1] ] == INFINITY) || (D[ (A.first)[2*j+1] ] > (D[ i ]+ (long double)((A.second)[j]) ) )  ) )
                // we should recount distance if we have found non-visited vertex or we may reduce its distance from vertex b.

                {
                    Q.push((A.first)[2*j+1]);  //��� ���設� - � ��।� // in this casr we should push such vertex to quenue Q
                    count++;
                    D[ (A.first)[2*j+1] ] = D[ i ]+ (long double)((A.second)[j]); // �� ��� ����⠥� ���⠭�� // and recount its distance from b

                    Prev [ (A.first)[2*j+1] ] = i;// � �।�� // and reset its previous vertex too
                }

            j = j+1;
        }

        Q.pop();

        if (count > (c)) //�����, �� ��⪭㫨�� �� 横� ����⥫쭮�� ��� // This means we found a negative weight cycle
        {
            D.clear();
            Prev.clear();

            return -1;
        }

    }

    return 0;
}






int DistanceTS (std::vector <int> &A, std::vector <long long int> & D, const int b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)
{

// ������뢠�� ����ﭨ� �� �������� ���設� b �� ��� ���� � ����. ��⮤ ࠡ�⠥� ����॥, 祬 DistanceBFA �� ��� �।���⥫쭮� ⮯������᪮� ���஢�� ����.
// ������ ��⮤ ���ਬ���� ��� ���䮢, ᮤ�ঠ�� �� 横� �஬� ��⥫�,  � �.�. - ������⢥���� (��⫨ ���� �����஢�����).
// �����頥��� 1 � ��砥 �ᯥ� (����� D ᮤ�ন� ���砩訥 ����ﭨ� �� ���設� b �� ���設� i, � ����� Prev - ������ ���設-�।��� � ⠪�� ���).
// �� 㬮�砭�� ����� D ᮤ�ন� ���祭�� LLONG_MAX, � ����� Prev - "-1".
// �᫨ �� �����㦥� 横� - �����頥��� -1 � ����� ����� D � Prev.
// �� �室� �.�. ���, ������� ����஬ ᬥ����� A (��⠥���, �� ���設� �㬥������ � 0), ����� ��室��� ���設� � 䫠�, ���� �� ��� ����襭��.
// ��� ������襭��� ��䮢 ��⠥���, �� ������ ॡ� ����� ��� = 1. ��� ����襭��� - ����� ॡ�� ������ ���� ��ண� ����� INT_MAX.
// ����� �� �室 �������� ����� �������襩 ���設� V (�᫨ �� ��।��, �����뢠���� ᠬ����⥫쭮 ��� ����� �������襩 ���設� � ॡ��)
// �㭪�� ࠡ�⠥� � ����襭�묨 � � ������襭�묨 ��䠬�, ��祬 ��� ����� ᮤ�ঠ�� ��⫨ � ������⢥��� ॡ�.
// ���� ����� ����� ��� ������⥫�� (� �.�. � �㫥���), ⠪ � ����⥫�� ���.

// The function counts the shortest distances from the vertex b to all vertices in the graph (these distances are to be contained in vector D, i.e. D[i] means the shortest distance from b to i).
// By default vector D is filled with LLONG_MAX.
// In doing so, vector Prev is intended to contain the number of the previvous vertex for every vertex in such shortest paths ("-1" value is set by default and means "this vertex doesn't included in any such path").
// This function seems to be faster than DistanceBFA, but DistanceTS works only with graphs containing no cycles (except loops, multiply loops).
// The input graph should be directed, both weighted or unweighted (in this case we consider every edge's weight as "1".) The graph may have loops and multiple edges.
// Input data: Adjacency vector A (it is supposed that vertices are numbered starting from 0) and the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A)
// The edges of a weighted graph may have weight of 0, >0, <0, but only less than INT_MAX (<INT_MAX).
// In case we found a cycle as well as input data is incorrect the function returns "-1" and empty D and Prev.



    D.clear();
    Prev.clear();

    if (A.size()==0) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness



    int mn, mx;
    RangeVGraph (A, mx, mn, weighted);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // ����� �㤥� ���ᨬ���� ����� ���設� // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, LLONG_MAX); // �� 㬮�砭�� ����ﭨ� ࠢ�� + ��᪮��筮��� // The default distance values is LLONG_MAX for every vertex


    Prev.resize(V+1, -1); // �� 㬮�砭�� "�।��" ���. // The previous vertices are not set by default (i.e. =-1 for every vertex)



    std::vector <int> order; // ����� �㤥� �࠭����� ⮯������᪠� ���஢�� ���設
    order.clear();

    std::vector <int> R; // An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    R.clear();

    std::vector <int> I; //  An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    I.clear();

    int t=TSortHP (A, R, order, I, weighted, true);



    if (t==-1)  // if there are no topological sorting (i.e. the graph contains cycle except any loops) this function can't work.
    {
        D.clear();
        Prev.clear();
        return -1;
    }


    if (mn!=0) order.insert(order.begin(), 0); // if vertices are numbrered starting not from 0 - let's add 0

    if (V>mx)   //adding to "order" vertices that have number more than maximal in A and <= V
        for (int ff = (mx+1); ff<=V; ff++)
             order.insert(order.begin(), ff);


    int bb;

    for (int i = 0; i< order.size(); i++)   // ���� ������ ����� ���設� ��砫� ���᪠
    {

        if (order[i]==b) {bb = i; break;}

    }


    D[order[bb]] = 0; //���⠭�� �� ��ࢮ� ���設� �� ᥡ� = 0

    std::vector <std::vector <int>> B (V+1);

    MatrixSet(B, V+1, V+1, INT_MAX);    // �������� ����⮢�� ������ B � ���� 2-嬥୮�� ���ᨢ� (�� ����஢)


    for (unsigned int x = 0; x<=(A.size()-(2+weighted)); x = x+2+weighted)
    {
        if (weighted)
        {
            if ( (A[x]!=A[x+1]) && ( B[(A[x])][(A[x+1])] > A[x+2] ) ) B[(A[x])][(A[x+1])] = A[x+2];  // � ������ ᬥ����� ��⠢�塞 ����� ���砩襣� ॡ�
        }

        if (!weighted)
        {
            if (A[x]!=A[x+1]) B[(A[x])][(A[x+1])] = 1;  // � ������ ᬥ����� ��⠢�塞 ����� ॡ�
        }
    }

    // ����� ���������� ������ ᬥ�����



    for (int b = bb; b<V; b++)              // ����� �� ����� ᬥ����� �� �᪮��� ���設� � ����訬 ����ࠬ � ������뢠�� ���⠭��
        for (int j = b+1; j<=V; j++)
        {


            if (D[order[b]]==LLONG_MAX) continue; //�᫨ ���設� b �����⨦��� �� ��室���, ��祣� �� ��� ����ﭨ� ������뢠�� // We should recalculate distances only from vertices that are accessible from vertex b as initial one.

            if ( (B[order[b]][order[j]]!=INT_MAX) && ((D[order[j]]==LLONG_MAX) || (D[order[j]]>(D[order[b]]+(long long int)(B[order[b]][order[j]]) ) ) ) )   {D[order[j]]=(D[order[b]]+ (long long int)(B[order[b]][order[j]]) ); Prev[order[j]]= order[b];}

        }



    return 0;
}


int DistanceTS (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, std::vector <int> & Prev, int V = INT_MIN)
// ����䨪��� �㭪樨 DistanceTS (�. ���) ��� ���� ��楫��᫥���� ��ᮢ ॡ�� (double).
// Modification of the function DistanceTS (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.



{
    D.clear();
    Prev.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;



    int mn, mx;
   RangeVGraph (A.first, mx, mn, false);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // ����� �㤥� ���ᨬ���� ����� ���設� // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, INFINITY); // �� 㬮�砭�� ����ﭨ� ࠢ�� + ��᪮��筮��� // The default distance values is INFINITY for every vertex


    Prev.resize(V+1, -1); // �� 㬮�砭�� "�।��" ���. // The previous vertices are not set by default (i.e. =-1 for every vertex)



    std::vector <int> order; // ����� �㤥� �࠭����� ⮯������᪠� ���஢�� ���設
    order.clear();

    std::vector <int> R; // An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    R.clear();

    std::vector <int> I; //  An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    I.clear();

    int t=TSortHP (A.first, R, order, I, false, true);



    if (t==-1)  // if there are no topological sorting (i.e. the graph contains cycle except any loops) this function can't work.
    {
        D.clear();
        Prev.clear();
        return -1;
    }


    if (mn!=0) order.insert(order.begin(), 0); // if vertices are numbrered starting not from 0 - let's add 0

    if (V>mx)   //adding to "order" vertices that have number more than maximal in A and <= V
        for (int ff = (mx+1); ff<=V; ff++)
             order.insert(order.begin(), ff);


    int bb;

    for (int i = 0; i< order.size(); i++)   // ���� ������ ����� ���設� ��砫� ���᪠
    {

        if (order[i]==b) {bb = i; break;}

    }


    D[order[bb]] = 0.0; //���⠭�� �� ��ࢮ� ���設� �� ᥡ� = 0

    std::vector <std::vector <double>> B (V+1);

    MatrixSet(B, V+1, V+1, INFINITY);    // �������� ����⮢�� ������ B � ���� 2-嬥୮�� ���ᨢ� (�� ����஢)


    for (unsigned int x = 0; x<=((A.first).size()-(2)); x = x+2)
    {

            if ( ((A.first)[x]!=(A.first)[x+1]) && ( B[((A.first)[x])][((A.first)[x+1])] > (A.second)[x/2] ) ) B[(A.first)[x]][(A.first)[x+1]] = (A.second)[x/2];  // � ������ ᬥ����� ��⠢�塞 ����� ���砩襣� ॡ�
   }

    // ����� ���������� ������ ᬥ�����



    for (int b = bb; b<V; b++)              // ����� �� ����� ᬥ����� �� �᪮��� ���設� � ����訬 ����ࠬ � ������뢠�� ���⠭��
        for (int j = b+1; j<=V; j++)
        {


            if (D[order[b]]==INFINITY) continue; //We should recalculate distances only from vertices that are accessible from vertex b as initial one.

            if ( (B[order[b]][order[j]]!=INFINITY) && ((D[order[j]]==INFINITY) || (D[order[j]]>(D[order[b]]+(long double)(B[order[b]][order[j]]) ) ) ) )   {D[order[j]]=(D[order[b]]+ (long double)(B[order[b]][order[j]]) ); Prev[order[j]]= order[b];}

        }



    return 0;
}




#endif
