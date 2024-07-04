#include "Include.h"
#include "Bullet.h"
#include "player.h"
#include "monster.h"
#include "Effect.h"
#include "mom.h"
#include <windows.h>
int ranking[6];
bool _crash(mom _bullet,mom _monster)
{
	if (_monster.GetX() == _bullet.GetX() && _monster.GetY() == _bullet.GetY() && _monster.Getdead() == 1 && _bullet.Getdead() == 1)
		return true;
	return false;
}
void file_in()
{
	FILE* file = fopen("date.txt", "wb");

	for (int i = 0; i < 5; i++)
		fwrite(&ranking[i], sizeof(int), 1, file);
	fclose(file);
}
void file_out()
{
	char temp[10];
	FILE* file = fopen("date.txt", "rb");
	for (int i = 0; i < 5; i++)
	{
		fread(&ranking[i], sizeof(int), 1, file);
		sprintf(temp, "%d.%d��", i + 1, ranking[i]);
		DrawStrEx3(33, 12 + i, temp, WHITE, BLUE);
	}
	fclose(file);
}
void setting()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			if (ranking[j] < ranking[j + 1])
			{
				int temp = ranking[j];
				ranking[j] = ranking[j + 1];
				ranking[j + 1] = temp;
			}
		}
	}
}
int Meue_Scene()
{
	bool bLoop = true;
	char str_1[16];
	char str_2[16];
	char str_3[16];
	//�޴� ����
	while (bLoop)
	{
		CheckInput();
		ClearScreenEx3(BLUE);

		sprintf(str_1, "1.���� ����!");
		DrawStrEx3(33, 12, str_1, WHITE, BLUE);
		sprintf(str_2, "2.���� ����!");
		DrawStrEx3(33, 13, str_2, WHITE, BLUE);
		sprintf(str_1, "3.��ŷ!");
		DrawStrEx3(33, 14, str_1, WHITE, BLUE);
		if (IsKey(VK_1))
		{
			return 2;
		}
		else if (IsKey(VK_2))
		{
			return 3;
		}
		else if (IsKey(VK_3))
		{
			while (1)
			{
				CheckInput();
				ClearScreenEx3(BLUE);
				file_out();
				Flip();
				if (IsKey(VK_RETURN))
					break;
			}
		}
		Flip();
		EngineSync(32);
	}
}
int Game_Scene()
{
	//�������̽�
	char str_life1[16];
	char str_score[16];
	char str_life[16];
	char str_rule[10], str_rule1[10], str_rule2[10], str_rule3[10], str_rule4[10], str_rule5[15];
	int nScore = 0;
	int nLIFE = 4;

	//����
	bool	bLoop = true;
	int count_bullet = GetTickCount();
	int count = GetTickCount();
	int count_it = GetTickCount();

	Ceffect *effect = new Ceffect[25];
	Cplayer player = Cplayer();
	bullet *pBullet = new bullet[25];
	monster *pMonster = new monster[25];

	while (bLoop)
	{
		/*	Console Ű���� �Է��� �ǽð����� �˻��ϱ� ����
		���� �ݺ��ϸ鼭 �˻��Ѵ�						*/
		CheckInput();
		/*	Console ���� �ִ� ������ ������ ������ ������
		������											*/
		ClearScreenEx3(BLACK);
		//�������̽� ����
		DrawFillBoxEx3(50, 0, 15, 25, BLUE);//�������̽� �ڽ�

		sprintf(str_score, "score : %d", nScore);//���� �������̽�
		DrawStrEx3(52, 3, str_score, WHITE, BLUE);

		DrawBoxCharEx3(50, 0, 15, 25, '#', WHITE, BLUE);//�ڽ� �׵θ�

		sprintf(str_rule, "*��Ģ*"); //��Ģ
		DrawStrEx3(55, 5, str_rule, WHITE, BLUE);
		sprintf(str_rule1, "�� ��");
		DrawStrEx3(55, 6, str_rule1, WHITE, BLUE);
		sprintf(str_rule2, "�Ʒ� ��");
		DrawStrEx3(53, 7, str_rule2, WHITE, BLUE);
		sprintf(str_rule3, "������ ��");
		DrawStrEx3(51, 8, str_rule3, WHITE, BLUE);
		sprintf(str_rule4, "���� ��");
		DrawStrEx3(53, 9, str_rule4, WHITE, BLUE);
		sprintf(str_rule5, "���� : SPACE");
		DrawStrEx3(51, 10, str_rule5, WHITE, BLUE);

		sprintf(str_life, "LIFE", nLIFE);//����
		DrawStrEx3(56, 19, str_life, WHITE, BLUE);
		if (nLIFE == 4)
		{
			sprintf(str_life1, "�� �� ��");
			DrawStrEx3(54, 20, str_life1, RED, BLUE);
		}
		else if (nLIFE == 3)
		{
			sprintf(str_life1, "�� ��");
			DrawStrEx3(54, 20, str_life1, RED, BLUE);
		}
		else if (nLIFE == 2)
		{
			sprintf(str_life1, "��");
			DrawStrEx3(54, 20, str_life1, RED, BLUE);
		}
		else if (nLIFE == 1)
		{
			sprintf(str_life1, "*���ӿ���*");
			DrawStrEx3(53, 20, str_life1, RED, BLUE);
			nLIFE -= 1;
		}
		else if (nLIFE == 0)
		{
			ranking[5] = nScore;
			setting();
			file_in();
			return 1;
		}

		//!<	����� ���� ���α׷� ����� ����
#if defined(DEBUG) | defined(_DEBUG)
		//!< FPS ���
		PutFPS();
		//!< Esc Ű�� ���ȴٸ� �ݺ������� ���´�
		if (IsKey(VK_ESCAPE))
		{
			return 1;
		}
#endif

		//!< ����� ���� ����
		/*	Console ���� �ִ� ������ �� ���ڸ� �׸���	!+!	*/

		//�÷��̾� ������
		player.UPdate();
		player.Draw();

		//���� ����
		if (GetTickCount() - count >= 150)
		{
			for (int j = 0; j < 25; j++)
			{
				if (pMonster[j].Getdead() == 0)
				{
					pMonster[j].create_Monster();
					count = GetTickCount();
					break;
				}
			}
		}
		for (int j = 0; j < 25; j++)
		{
			if (pMonster[j].Getdead() == 1)
			{
				pMonster[j].UPdate();
				pMonster[j].Draw();
			}
		}
		//��� ����Ʈ
		for (int i = 0; i < 25; i++)
		{
			if (pMonster[i].Getdead() == 0)
			{
				for (int i = 0; i < 25; i++)
				{
					effect[i].UPdate_Effect();
					effect[i].Draw_Effect();
				}
			}
		}
		/*�Ѿ� ���*/
		if (IsKey(VK_SPACE) && GetTickCount() - count_bullet >= 0) //ceate
		{
			for (int i = 0; i < 25; i++)
			{
				if (pBullet[i].Getdead() == 0)
				{
					pBullet[i].create_Bullet(player.GetX(), player.GetY());
					count_bullet = GetTickCount();
					break;
				}
			}
		}
		for (int i = 0; i < 25; i++)
		{
			pBullet[i].UPdate();
			pBullet[i].Drow();
		}
		//���� ����
		for (int i = 0; i < 25; i++)
		{
			if (player.GetX() + 1 == pMonster[i].GetX() && player.GetY() == pMonster[i].GetY() && pMonster[i].Getdead() == 1)
			{

				pMonster[i].Setdead(0);
				effect[i].Create_Effect(pMonster[i].GetX(), pMonster[i].GetY());
				nLIFE -= 1;
			}
		}


		//�浹 �˻�
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				if (_crash(pMonster[i], pBullet[j]) == true)
				{
					pMonster[i].Setdead(0);
					pBullet[j].Setdead(0);
					effect[i].Create_Effect(pMonster[i].GetX(), pMonster[i].GetY());
					nScore += 10;
				}
			}
		}

		/*	Console ���� ������ �׷��� ������ �������� ������
		��ü�Ͽ��ش�									*/
		Flip();
		/*	Console �� ���� �ݺ��� �ǽ��ϴ� �ð��� �����Ѵ�	*/
		EngineSync(32);
	}

	delete[] effect;
	delete[] pMonster;
	delete[] pBullet;
}
int main(void)
{
	bool	bLoop = true;
	int num = 1;
	//!< Memory ���� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*	Console �ʱ�ȭ ����
			ȭ�� ũ��	����: 0~79
						����: 0~24
			��ũ�� ����
			������Ʈ Ŀ�� ����
			���콺 Ŀ�� ����								*/
	InitialConsole();
	//!< Console â�� ������ ����
	SetWindowTitle("�������� ���ð���");
	/*	Console ��� ����
			CP_ENGLISH_ = ����
			CP_KOREAN_ = �ѱ�										*/
	ChangeCodePage(CP_KOREAN_);
	while (bLoop)
	{
		if (num == 1)
		{
			num = Meue_Scene();
		}
		else if (num == 2)
		{
			num = Game_Scene();
		}
		else if (num == 3)
		{
			return 0;
		}
	}
	/*	Console ������ �����Ѵ�.							*/
	ReleaseConsole();
	//!< ��ȯ. type int
	return 0;
}