#include "Include.h"
void GameScene::Enter()
{
	Cmap::Getmapinstance()->file_road();

	player.Init_he();
}
void GameScene::Update()
{
	Cmap::Getmapinstance()->map_set(player.getoffset());
	PutFPS();

	MonsterMng::Getinstance()->update(player.getoffset());
	player.UPdate_he();
	BulletMng::Getinstance()->update(player.getoffset());

	Monster* monster = MonsterMng::Getinstance()->Crash(player.getx() + player.getoffset(), player.gety());
	if (monster != NULL)
	{
		for (int i = 0; i < 10; i++)
		{
			MonsterMng::Getinstance()->monster[i].state = false;
		}
		player.life = false;
		SceneMng::Getinstance()->ChangeScene(2);
	}
}
void GameScene::Draw()
{
	MonsterMng::Getinstance()->Draw(player.getoffset());

	player.Draw_he(player.getx(), player.gety());

	BulletMng::Getinstance()->Draw();
}
void GameScene::Exit()
{

}