#include <stdio.h>
#include <allegro5/allegro.h>
#include <algorithm>
#include <random>
#include <cmath>
#include <fstream>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <memory>
#include <numeric>

#include "AudioHelper.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "Image.hpp"
#include "Label.hpp"
#include "AnimationScene.hpp"
#include "Resources.hpp"
#include "Sprite.hpp"
#include "LOG.hpp"



const std::vector<Engine::Point> AnimationScene::directions = { Engine::Point(-1, 0), Engine::Point(0, -1), Engine::Point(1, 0), Engine::Point(0, 1) };
const int AnimationScene::MapWidth = 12, AnimationScene::MapHeight = 6;//50;//13;

void AnimationScene::Initialize() {
    trytime = 0;
    tensecond = 0;
	AddNewControlObject(UIGroup = new Group());
	ConstructUI();
	BGImage_1->Tint = al_map_rgba(255, 255, 255,255);
	bgmId = AudioHelper::PlayBGM("BGM.ogg");
}
void AnimationScene::Terminate() {
    AudioHelper::StopBGM(bgmId);
	//AudioHelper::StopSample(BGM_1);
	//BGM_1 = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void AnimationScene::Update(float deltaTime) {
    trytime++;
    //printf("trytime have plused?? %d\n",trytime);
    if(trytime==250)tensecond++,trytime=0;
    //printf("tensecond passed %d\n",tensecond);
    IScene::Update(deltaTime);

    if(tensecond == 1 && trytime==0){
        //AudioHelper::StopBGM(bgmId);
        BGImage_1->Tint.a = 0;
        BGImage_2->Tint = al_map_rgba(255, 255, 255,255);
        //BGM_1 = AudioHelper::PlaySample("astronomia.ogg", false, AudioHelper::BGMVolume, 0);
    }
    else if(tensecond == 2 && trytime==0){
        //AudioHelper::StopSample(BGM_1);
        BGImage_2->Tint.a = 0;
        BGImage_3->Tint = al_map_rgba(255, 255, 255,255);

    }
    else if(tensecond == 3 && trytime==0){
        //AudioHelper::StopSample(BGM_1);
        BGImage_3->Tint.a = 0;
        BGImage_4->Tint = al_map_rgba(255, 255, 255,255);

    }
    else if(tensecond == 4 && trytime==0){
        //AudioHelper::StopSample(BGM_1);
        BGImage_4->Tint.a = 0;
        BGImage_5->Tint = al_map_rgba(255, 255, 255,255);

    }
    else if(tensecond == 5 && trytime==0){
        //AudioHelper::StopSample(BGM_1);
        BGImage_5->Tint.a = 0;
        BGImage_6->Tint = al_map_rgba(255, 255, 255,255);

    }
    else if(tensecond == 6 && trytime==200){
        BGImage_6->Tint.a = 0;
        Engine::GameEngine::GetInstance().ChangeScene("start_scene");
    }

}
void AnimationScene::Draw() const {
	IScene::Draw();
}

void AnimationScene::ConstructUI() {

	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	int shift = 135 + 25;
	BGImage_1 = new Engine::Sprite("play/BGimage_1.png", w -750, h - 500);
	BGImage_1->Tint.a = 0;
	UIGroup->AddNewObject(BGImage_1);
	BGImage_2 = new Engine::Sprite("play/BGimage_2.png", w -750, h - 500);
	BGImage_2->Tint.a = 0;
	UIGroup->AddNewObject(BGImage_2);
	BGImage_3 = new Engine::Sprite("play/BGimage_3.png", w -750, h - 500);
	BGImage_3->Tint.a = 0;
	UIGroup->AddNewObject(BGImage_3);
	BGImage_4 = new Engine::Sprite("play/BGimage_4.png", w -750, h - 500);
	BGImage_4->Tint.a = 0;
	UIGroup->AddNewObject(BGImage_4);
	BGImage_5 = new Engine::Sprite("play/BGimage_5.png", w -750, h - 500);
	BGImage_5->Tint.a = 0;
	UIGroup->AddNewObject(BGImage_5);
	BGImage_6 = new Engine::Sprite("play/BGimage_6.png", w -750, h - 500);
	BGImage_6->Tint.a = 0;
	UIGroup->AddNewObject(BGImage_6);
}
