#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

long BACA_FILE_BANTUAN_DAN_TENTANG(char NAMA_FILE[80])
{
	FILE* DATA;
	int LIHAT;
	long A;

	DATA = fopen(NAMA_FILE, "a+");

	if (DATA == NULL)
	{
		printf("File Yang Akan Dibaca tidak ditemukan");
	}
	else
	{
		LIHAT = ftell(DATA);
		fseek(DATA, 0L, SEEK_END);
		A = ftell(DATA);
		fseek(DATA, LIHAT, SEEK_SET);
		fclose(DATA);
	}
	return A;
}

void BUKA_FILE_BANTUAN_DAN_TENTANG()
{
	long BACA_FILE_TENTANG = 0;
	FILE* DATA_X_TENTANG;
	char NAMA_FILE_X[100];

	BACA_FILE_TENTANG = BACA_FILE_BANTUAN_DAN_TENTANG("File/FileContoh.txt");

	DATA_X_TENTANG = fopen("File/FileContoh.txt", "a+");
	while (fgets(NAMA_FILE_X, sizeof NAMA_FILE_X, DATA_X_TENTANG) != NULL)
	{
		printf(NAMA_FILE_X, stdout);
	}
	fclose(DATA_X_TENTANG);
}

void main()
{
	BUKA_FILE_BANTUAN_DAN_TENTANG();
	_getch();
}