#include "Include.h"


int main(void)
{
	Snake Csnake;
	apple apple;
	bool	bLoop = true;

	

	//!< Memory ���� üũ
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	/*	Console �ʱ�ȭ ����
			ȭ�� ũ��	����: 0~79
						����: 0~24
			��ũ�� ����
			������Ʈ Ŀ�� ����
			���콺 Ŀ�� ����								*/
	InitialConsole();
	//!< Console â�� ������ ����
	SetWindowTitle("A ���� Hero");
	/*	Console ��� ����
			CP_ENGLISH_ = ����
			CP_KOREAN_ = �ѱ�										*/
	ChangeCodePage(CP_KOREAN_);

	

	while (bLoop)
	{
		/*	Console Ű���� �Է��� �ǽð����� �˻��ϱ� ����
			���� �ݺ��ϸ鼭 �˻��Ѵ�						*/
		CheckInput();
		/*	Console ���� �ִ� ������ ������ ������ ������
			������					*/					
		ClearScreenEx3(WHITE);
		DrawBoxCharEx3(0, 0, 80, 25, ' ', RED, RED);

//!<	����� ���� ���α׷� ����� ����
#if defined(DEBUG) | defined(_DEBUG)
		//!< FPS ���
		PutFPS();
		//!< Esc Ű�� ���ȴٸ� �ݺ������� ���´�
		if (IsKey(VK_ESCAPE))
		{
			break;
		}
#endif

		//!< ����� ���� ����
		/*	Console ���� �ִ� ������ �� ���ڸ� �׸���		*/
		
	
		apple.create();
		apple.Draw();
		apple.eat(Csnake.mbady[0].x,Csnake.mbady[0].y);
		Csnake.Draw();
		
		Csnake.Update();
		Csnake.eat(apple.x, apple.y);

		for (int i = 1; i <= Csnake.Length; i++)
		{
			if (Csnake.mbady[0].x == Csnake.mbady[i].x&&Csnake.mbady[0].y == Csnake.mbady[i].y)
				bLoop = false;
		}
		

		
		/*apple.eat(Csnake.hx, Csnake.hy);*/

		/*	Console ���� ������ �׷��� ������ �������� ������
			��ü�Ͽ��ش�									*/
		Flip();
		/*	Console �� ���� �ݺ��� �ǽ��ϴ� �ð��� �����Ѵ�	*/
		EngineSync(16);
	}

	/*	Console ������ �����Ѵ�.							*/
	ReleaseConsole();
	//!< ��ȯ. type int
	return 0;
}
