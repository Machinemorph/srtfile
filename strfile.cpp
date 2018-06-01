// strfile.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <Windows.h>

using namespace std;

int main()
{
	ifstream inp("inp.txt");
	ofstream otp("otp.txt");
	const int len = 81;
	char word1[len], word2[len], let[2];
	set<char> vow;
	vow.insert('a');
	vow.insert('e');
	vow.insert('y');
	vow.insert('u');
	vow.insert('i');
	vow.insert('o');
	while (!inp.eof())
	{
		inp >> word1;
		if (vow.count(word1[0]))
		{
			word2[0] = towupper(word1[0]);
			word2[1] = '\0';
			strncat_s(word2, word1 + 1, 70);
		}
		else {
			strcpy_s(word2, word1);
		}
		otp << word2 << " ";
	}
	return 0;
}

//12.	Написать программу, которая считывает английский текст из файла и записывает его в другой файл, заменив каждую первую букву слов, начинающихся с гласной буквы, на прописную
//towupper(ch)