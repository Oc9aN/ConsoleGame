#pragma once
#include "Include.h"

class SceneMng
{
	static SceneMng* instance;
	int SceneNum;

	SceneMng()
	{
		curScene = NULL;
		SceneList[0] = new MainScene();
		SceneList[1] = new GameScene();
		SceneList[2] = new OverScene();
		ChangeScene(0);
	}
public:
	static SceneMng* Getinstance()
	{
		if (instance == NULL)
		{
			instance = new SceneMng();
		}
		return instance;
	}

	cScene* SceneList[3];
	cScene* curScene;

	void ChangeScene(int idx)
	{
		if (curScene == NULL)
		{
			curScene = SceneList[idx];
			curScene->Enter();
		}
		else
		{
			curScene->Exit();
			curScene = SceneList[idx];
			curScene->Enter();
		}
	}
};