#include <iostream>
#include <string>
#include <windows.h>
#include "����.h"
using namespace std;
char PlayerName1[80], PlayerName2[80]; //���������� ��� ���� �������
char cells[9] = { '-','-','-','-','-','-','-','-','-' };//����� ����� �������� ������ � �������
char win = '-'; //������ ������ ("-" - �����, "�" - ������� ������, "�" - �������)
void show_cells() {
	system("cls");

	cout << "����� ������: \n";
	cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
	cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
	cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

	cout << "������� �������� (---������):\n" << endl;
	cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
	cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
	cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

}
void make_move(int num) {/*��� ������� ���� ������ �� ����������, �� � ��� ���� �������� - �����������, ������� ����� ������ ���*/
	if (num == 1) cout << PlayerName1;
	else cout << PlayerName2;
	int cell;
	bool faw = true;
	do {
		cout << ",������� ����� ������,�������� ���� ���:" << endl;
		cin >> cell;
		if (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
			cout << "������� ����� ����������� ( 1-9 ) ��� ������ ( --- ) ������ , ����� ������� ���:";
		}
		else {
			faw = false;
		}
	} while (faw);
	if (num == 1) cells[cell - 1] = 'X';
	else cells[cell - 1] = 'O';
	//������ ����� ������ "����������", � ������ - "��������"

}
char check()
{
	for (int i = 0; i < 3; i++) //��� ������ ����� 3 ��������
		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]) //���������� ��� ������ ����������� ��
			return cells[i]; //������ ��������, ��� - �� �����������
			//0-1-2, 3-4-5 � 6-7-8
			//��������� � ������� ���������� � 0
		else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) //������������
			return cells[i]; //0-3-6, 1-4-7 � 2-5-8
		else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]))
			return cells[i]; //� �� ���������: 0-4-8 � 2-4-6
	return '-'; //����� - �����
}
void result() {
	if (win == 'X') {
		cout << PlayerName1 << " �������� ����������� " << PlayerName2 << " �� ���������..." << endl;
	}
	else if (win == 'O') {
		cout << PlayerName2 << " �� �������� " << PlayerName1 << " �� ���������..." << endl;
	}
	else cout << "!!!" << endl;
}
int igra()
{
	do {
		cout << "\t\t\t\t������� ��� ������� ������ : ";
		cin >> PlayerName1;

		cout << "\t\t\t\t������� ��� ������� ������: ";
		cin >> PlayerName2;
		cout << "\n";
	} while (!strcmp(PlayerName1, PlayerName2));
	// //////////////////////////////////////////
	show_cells();

	for (int move = 1; move <= 9; move++) {
		if (move % 2) make_move(1); //���� ��� ��������, �� ������� �� ������� �� ����� ����� 1 (�� ���� true)
		else make_move(2);//���� ������, �� 0 (false). ����� ���� ��� �������� ����� ������ �����

		show_cells();
		/*���� ����� ���� 5 ��� ������, �� �������� �������� �� ������ (������, ��� �� 5-�� ���� �������� ������)*/
		if (move >= 5)
		{
			win = check();
			if (win != '-')
				break;
		}
		//���� ���������� � ����� �� ������� - �����

	}

	result();
	system("pause");
	system("cls");
	return 0;
}