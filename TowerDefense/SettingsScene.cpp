#include <functional>
#include <string>

#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "Slider.hpp"
#include "SettingsScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

void SettingsScene::Initialize() {
	// TODO 1 (2/3): You can imitate the 2 files: 'LoseScene.hpp', 'LoseScene.cpp' to implement your setting scene.
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	int halfW = w / 2;
	int halfH = h / 2;
	AddNewObject(new Engine::Label("SET VOLUME", "pirulen.ttf", 48, halfW, halfH / 4 + 10, 255, 255, 255, 255, 0.5, 0.5));
	Engine::ImageButton* btn;
	btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
	btn->SetOnClickCallback(std::bind(&SettingsScene::BackOnClick, this, 2));
	AddNewControlObject(btn);
	AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));


	// TODO 1 (3/3): Move the sliderBGM, sliderSFX to the setting Scene and make sure the background music will be played
	Slider* sliderBGM, * sliderSFX;
	sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
	sliderBGM->SetOnValueChangedCallback(std::bind(&SettingsScene::BGMSlideOnValueChanged, this, std::placeholders::_1));
	AddNewControlObject(sliderBGM);
	AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5, 0.5));
	sliderSFX = new Slider(40 + halfW - 95, halfH + 50 - 2, 190, 4);
	sliderSFX->SetOnValueChangedCallback(std::bind(&SettingsScene::SFXSlideOnValueChanged, this, std::placeholders::_1));
	AddNewControlObject(sliderSFX);
	AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5, 0.5));
	// Not safe if release resource while playing, however we only free while change scene, so it's fine.
	bgmInstance = AudioHelper::PlaySample("shooting-stars.ogg", true, AudioHelper::BGMVolume);
	sliderBGM->SetValue(AudioHelper::BGMVolume);
	sliderSFX->SetValue(AudioHelper::SFXVolume);
}
void SettingsScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void SettingsScene::BackOnClick(int stage) {
	// Change to select scene.
	Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void SettingsScene::BGMSlideOnValueChanged(float value) {
	AudioHelper::ChangeSampleVolume(bgmInstance, value);
	AudioHelper::BGMVolume = value;
}
void SettingsScene::SFXSlideOnValueChanged(float value) {
	AudioHelper::SFXVolume = value;
}

