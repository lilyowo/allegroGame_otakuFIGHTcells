#include <functional>
#include <memory>
#include <string>

#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Start_Scene.hpp"
#include "StageSelectScene.hpp"
#include "AudioHelper.hpp"

void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;

    btn = new Engine::ImageButton("start_scene/out.png", "start_scene/in.png", halfW - 200, halfH , 400, 100);
    btn->SetOnClickCallback(std::bind(&StartScene::PlayOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Play", "pirulen.ttf", 48, halfW, halfH +50 , 0, 0, 0, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Tower Defense", "pirulen.ttf", 108, halfW, halfH/2 , 255, 255, 0, 255, 0.5, 0.5));

    //bonus_2
     btn = new Engine::ImageButton("start_scene/out.png", "start_scene/in.png", halfW - 200, halfH+150 , 400, 100);
    btn->SetOnClickCallback(std::bind(&StartScene::PlayOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Animation", "pirulen.ttf", 48, halfW, halfH +200 , 0, 0, 0, 255, 0.5, 0.5));
    bgmId = AudioHelper::PlayBGM("lets_play.ogg");

}
void StartScene::Terminate() {
    AudioHelper::StopBGM(bgmId);
	IScene::Terminate();
}
void StartScene::PlayOnClick(int stage) {
    if(stage==1)
        Engine::GameEngine::GetInstance().ChangeScene("stage-select");
    else if(stage==2)//bonus_2
        Engine::GameEngine::GetInstance().ChangeScene("animation");
}


