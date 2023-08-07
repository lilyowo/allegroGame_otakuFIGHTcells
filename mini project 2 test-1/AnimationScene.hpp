#ifndef ANIMATIONSCENE_HPP
#define ANIMATIONSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <tuple>

#include "IScene.hpp"
#include "Point.hpp"

namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}  // namespace Engine

class AnimationScene final : public Engine::IScene {
private:
	ALLEGRO_SAMPLE_ID bgmId;
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> BGM_1;
protected:
	int trytime;
	int tensecond;
	int SpeedMult;
public:
	static const std::vector<Engine::Point> directions;
	static const int MapWidth, MapHeight;
	static const float DangerTime;
	int MapId;
	float ticks;
	float deathCountDown;
	Group* UIGroup;
	Engine::Image* imgTarget;
	Engine::Sprite* BGImage_1;
	Engine::Sprite* BGImage_2;
	Engine::Sprite* BGImage_3;
	Engine::Sprite* BGImage_4;
	Engine::Sprite* BGImage_5;
	Engine::Sprite* BGImage_6;
	static Engine::Point GetClientSize();
	explicit AnimationScene() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void ReadMap();
	void ConstructUI();
	std::vector<std::vector<int>> CalculateBFSDistance();

};
#endif // ANIMATIONSCENE_HPP
