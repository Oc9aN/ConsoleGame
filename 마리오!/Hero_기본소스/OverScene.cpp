#include "Include.h"

void OverScene::Enter()
{

}
void OverScene::Update()
{
	if(IsKey(VK_R))
	{
		SceneMng::Getinstance()->ChangeScene(1);
	}
}
void OverScene::Draw()
{
	DrawStrEx3(33, 12, "R : 다시시작", WHITE, BLACK);
	DrawStrEx3(33, 15, "ESC : 게임종료", WHITE, BLACK);
}
void OverScene::Exit()
{

}