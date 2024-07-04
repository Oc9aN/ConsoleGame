#include "Include.h"

Cmap* Cmap::mapinstance = NULL;
MonsterMng* MonsterMng::instance = NULL;
BulletMng* BulletMng::instance = NULL;
SceneMng* SceneMng::instance = NULL;

int main(void)
{
	bool	bLoop = true;
	char lifes[10];

	//!< Memory 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	/*	Console 초기화 셋팅
			화면 크기	가로: 0~79
						세로: 0~24
			스크롤 제거
			프롬프트 커서 제거
			마우스 커서 제거								*/
	InitialConsole();
	//!< Console 창의 제목을 변경
	SetWindowTitle("A 슈팅 Hero");
	/*	Console 언어 설정
			CP_ENGLISH_ = 영어
			CP_KOREAN_ = 한글										*/
	ChangeCodePage(CP_KOREAN_);

	

	while (bLoop)
	{
		/*	Console 키보드 입력을 실시간으로 검사하기 위해
			무한 반복하면서 검사한다						*/
		CheckInput();
		/*	Console 숨어 있는 공간의 색상을 지정한 색으로
			입힌다											*/
		ClearScreenEx3(BLACK);

//!<	디버그 모드로 프로그램 실행시 적용
#if defined(DEBUG) | defined(_DEBUG)
		//!< FPS 출력
		//!< Esc 키가 눌렸다면 반복문에서 나온다
		if (IsKey(VK_ESCAPE))
		{
			break;
		}
#endif

		//!< 사용자 설정 실행
		/*	Console 숨어 있는 공간에 한 문자를 그린다		*/

		SceneMng::Getinstance()->curScene->Update();
		SceneMng::Getinstance()->curScene->Draw();

		/*	Console 숨은 공간에 그려진 내용을 보여지는 공간과
			교체하여준다									*/
		Flip();
		/*	Console 의 무한 반복을 실시하는 시간을 조절한다	*/
		EngineSync(32);
	}

	/*	Console 셋팅을 해제한다.							*/
	ReleaseConsole();
	//!< 반환. type int
	return 0;
}
