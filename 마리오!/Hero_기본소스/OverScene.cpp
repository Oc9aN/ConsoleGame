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
	DrawStrEx3(33, 12, "R : �ٽý���", WHITE, BLACK);
	DrawStrEx3(33, 15, "ESC : ��������", WHITE, BLACK);
}
void OverScene::Exit()
{

}