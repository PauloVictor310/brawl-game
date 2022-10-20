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

    // cria e adiciona bbox das plataformas
    platform_1 = new Platform(-41, -17, 41, 17);
    platform_1->MoveTo(182, 145);
    scene->Add(platform_1, STATIC);

    platform_2 = new Platform(-62, -21, 62, 21);
    platform_2->MoveTo(302, 250);
    scene->Add(platform_2, STATIC);

    platform_3 = new Platform(-62, -21, 62, 21);
    platform_3->MoveTo(93, 302);
    scene->Add(platform_3, STATIC);

    platform_4 = new Platform(-62, -21, 62, 21);
    platform_4->MoveTo(250, 393);
    scene->Add(platform_4, STATIC);

    platform_5 = new Platform(-88, -21, 88, 21);
    platform_5->MoveTo(545, 186);
    scene->Add(platform_5, STATIC);

    platform_6 = new Platform(-135, -21, 135, 21);
    platform_6->MoveTo(538, 452);
    scene->Add(platform_6, STATIC);

    platform_7 = new Platform(-41, -17, 41, 17);
    platform_7->MoveTo(905, 135);
    scene->Add(platform_7, STATIC);

    platform_8 = new Platform(-62, -21, 62, 21);
    platform_8->MoveTo(768, 250);
    scene->Add(platform_8, STATIC);

    platform_9 = new Platform(-62, -21, 62, 21);
    platform_9->MoveTo(987, 288);
    scene->Add(platform_9, STATIC);

    platform_10 = new Platform(-62, -21, 62, 21);
    platform_10->MoveTo(822, 393);
    scene->Add(platform_10, STATIC);

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
