#include "Include.h"

void MainScene::Enter()
{

}
void MainScene::Update()
{
	if (IsKey(VK_1))
	{
		SceneMng::Getinstance()->ChangeScene(1);
	}
}
void MainScene::Draw()
{
	ClearScreenEx3(BLUE);
	DrawStrEx3(33, 12, "1.���� ����", WHITE, BLUE);
}
void MainScene::Exit()
{

}