#include "Include.h"

Cmap* Cmap::mapinstance = NULL;
MonsterMng* MonsterMng::instance = NULL;
BulletMng* BulletMng::instance = NULL;
SceneMng* SceneMng::instance = NULL;

int main(void)
{
	bool	bLoop = true;
	char lifes[10];

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
			������											*/
		ClearScreenEx3(BLACK);

//!<	����� ���� ���α׷� ����� ����
#if defined(DEBUG) | defined(_DEBUG)
		//!< FPS ���
		//!< Esc Ű�� ���ȴٸ� �ݺ������� ���´�
		if (IsKey(VK_ESCAPE))
		{
			break;
		}
#endif

		//!< ����� ���� ����
		/*	Console ���� �ִ� ������ �� ���ڸ� �׸���		*/

		SceneMng::Getinstance()->curScene->Update();
		SceneMng::Getinstance()->curScene->Draw();

		/*	Console ���� ������ �׷��� ������ �������� ������
			��ü�Ͽ��ش�									*/
		Flip();
		/*	Console �� ���� �ݺ��� �ǽ��ϴ� �ð��� �����Ѵ�	*/
		EngineSync(32);
	}

	/*	Console ������ �����Ѵ�.							*/
	ReleaseConsole();
	//!< ��ȯ. type int
	return 0;
}
