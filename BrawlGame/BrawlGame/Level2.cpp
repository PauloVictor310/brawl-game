/**********************************************************************************
// Level2 (Código Fonte)
//
// Criação:     27 Set 2021
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Nú“el 2 do jogo
//
**********************************************************************************/

#include "DimensionFighter.h"
#include "Home.h"
#include "Level2.h"
#include "Level3.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros estáticos da classe

Scene* Level2::scene = nullptr;
Audio* Level2::audio = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    audio = new Audio();
    audio->Add(MUSIC, "Resources/level_2.wav");

    // adiciona jogador na cena
    scene->Add(DimensionFighter::player2, MOVING);

    // adiciona jogador na cena
    scene->Add(DimensionFighter::player, MOVING);
    // posição inicial
    DimensionFighter::player2->MoveTo(window->CenterX() + 80, 24.0f, Layer::FRONT);
    // posição inicial
    DimensionFighter::player->MoveTo(window->CenterX(), 24.0f, Layer::FRONT);

    // pano de fundo do jogo
    backg = new Sprite("Resources/new/level_2.png");


    // cria e adiciona bbox das plataformas
    platform_1 = new Platform(-64, -23, 64, 23);
    platform_1->MoveTo(187, 203);
    scene->Add(platform_1, STATIC);
    
    platform_2 = new Platform(-188, -21, 188, 21);
    platform_2->MoveTo(529, 115);
    scene->Add(platform_2, STATIC);
    
    platform_3 = new Platform(-157, -21, 157, 21);
    platform_3->MoveTo(942, 209);
    scene->Add(platform_3, STATIC);
    
    platform_4 = new Platform(-67, -19, 67, 19);
    platform_4->MoveTo(67, 356);
    scene->Add(platform_4, STATIC);
    
    platform_5 = new Platform(-264, -21, 264, 21);
    platform_5->MoveTo(528, 324);
    scene->Add(platform_5, STATIC);
    
    platform_6 = new Platform(-64, -23, 64, 23);
    platform_6->MoveTo(964, 417);
    scene->Add(platform_6, STATIC);

    platform_7 = new Platform(-187, -21, 187, 21);
    platform_7->MoveTo(188, 464);
    scene->Add(platform_7, STATIC);

    platform_8 = new Platform(-187, -21, 187, 21);
    platform_8->MoveTo(678, 519);
    scene->Add(platform_8, STATIC);
    

    // adiciona jogador na cena
    //scene->Add(DimensionFighter::player, MOVING);

    //DimensionFighter::audio->Frequency(MUSIC, 1.00f);
    //DimensionFighter::audio->Frequency(TRANSITION, 0.85f);

    audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    if (window->KeyPress(VK_ESCAPE))
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
    else if (DimensionFighter::player->Level() == 2 || window->KeyPress('N'))
    {
        DimensionFighter::NextLevel<Level3>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    if (DimensionFighter::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(DimensionFighter::player, MOVING);
    scene->Remove(DimensionFighter::player2, MOVING);
    delete backg;
    delete scene;
    delete audio;
}

// ------------------------------------------------------------------------------
