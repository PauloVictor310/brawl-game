/**********************************************************************************
// Level3 (Código Fonte)
//
// Criação:     16 Out 2022
// Atualização: 16 Out 2022
// Compilador:  Visual C++ 2019
//
// Descrição:   Nú“el 3 do jogo
//
**********************************************************************************/

#include "DimensionFighter.h"
#include "Home.h"
#include "Level3.h"
#include "GameOver.h"
#include "Naruto.h"
#include "Platform.h"
#include "Background.h"
#include "Audio.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level3::scene = nullptr;
Audio* Level3::audio = nullptr;

// ------------------------------------------------------------------------------

void Level3::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Sprite("Resources/new/level_3.png");

    audio = new Audio();
    audio->Add(MUSIC, "Resources/level_3.wav");

    Platform* plat1;
    plat1 = new Platform(0, 0, 82, 33);
    plat1->MoveTo(140.0f, 128.0f);
    scene->Add(plat1, STATIC);

    Platform* plat2;
    plat2 = new Platform(0, 0, 124, 38);
    plat2->MoveTo(240.0f, 230.0f);
    scene->Add(plat2, STATIC);
    
    Platform* plat3;
    plat3 = new Platform(0, 0, 124, 38);
    plat3->MoveTo(31.0f, 281.0f);
    scene->Add(plat3, STATIC);

    Platform* plat4;
    plat4 = new Platform(0, 0, 124, 38);
    plat4->MoveTo(188.0f, 372.0f);
    scene->Add(plat4, STATIC);

    Platform* plat5;
    plat5 = new Platform(0, 0, 176, 38);
    plat5->MoveTo(457.0f, 164.0f);
    scene->Add(plat5, STATIC);

    Platform* plat6;
    plat6 = new Platform(0, 0, 268, 30);
    plat6->MoveTo(404.0f, 430.0f);
    scene->Add(plat6, STATIC);

    Platform* plat7;
    plat7 = new Platform(0, 0, 82, 33);
    plat7->MoveTo(863.0f, 118.0f);
    scene->Add(plat7, STATIC);

    Platform* plat8;
    plat8 = new Platform(0, 0, 124, 38);
    plat8->MoveTo(706.0f, 230.0f);
    scene->Add(plat8, STATIC);

    Platform* plat9;
    plat9 = new Platform(0, 0, 124, 38);
    plat9->MoveTo(925.0f, 267.0f);
    scene->Add(plat9, STATIC);

    Platform* plat10;
    plat10 = new Platform(0, 0, 124, 38);
    plat10->MoveTo(760.0f, 372.0f);
    scene->Add(plat10, STATIC);

    // adiciona jogador na cena
    scene->Add(DimensionFighter::player2, MOVING);

    // adiciona jogador na cena
    scene->Add(DimensionFighter::player, MOVING);
    // posição inicial
    DimensionFighter::player2->MoveTo(window->CenterX() + 80, 24.0f, Layer::FRONT);
    // posição inicial
    DimensionFighter::player->MoveTo(window->CenterX(), 24.0f, Layer::FRONT);

    // ----------------------

    //DimensionFighter::audio->Frequency(MUSIC, 1.00f);
    //DimensionFighter::audio->Frequency(TRANSITION, 0.85f);
    audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level3::Update()
{
    if (window->KeyPress(VK_ESCAPE) || DimensionFighter::player->Level() == 3 || window->KeyPress('N'))
    {
        DimensionFighter::audio->Stop(MUSIC);
        DimensionFighter::NextLevel<Home>();
        DimensionFighter::player->Reset();
    }
    else if (DimensionFighter::player->Bottom() < 0 || DimensionFighter::player->Top() > window->Height())
    {
        DimensionFighter::audio->Stop(MUSIC);
        DimensionFighter::NextLevel<Home>();
        DimensionFighter::player->Reset();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level3::Draw()
{
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
    scene->Draw();

    if (DimensionFighter::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level3::Finalize()
{
    scene->Remove(DimensionFighter::player, MOVING);
    scene->Remove(DimensionFighter::player2, MOVING);
    delete scene;
    delete backg;
    delete audio;
}

// ------------------------------------------------------------------------------
