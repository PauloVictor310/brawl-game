/**********************************************************************************
// Level1 (C?digo Fonte) 
// 
// Cria??o:     14 Fev 2013
// Atualiza??o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri??o:   N??el 1 do jogo
//
**********************************************************************************/

#include "DimensionFighter.h"
#include "Home.h"
#include "Font.h"
#include "Level1.h"
#include "Level2.h"
#include "GameOver.h"
#include "Naruto.h"
#include "Attack.h"
#include "Alex.h"
#include "Platform.h"
#include "Background.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est?ticos da classe

Scene * Level1::scene = nullptr;
Audio* Level1::audio = nullptr;

// ------------------------------------------------------------------------------
Color red(1.0f, 0.2f, 0.2f, 1.0f);
Color blue(1.0f, 1.0f, 1.0f, 1.0f);
void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    audio = new Audio();
    audio->Add(MUSIC, "Resources/level_1.wav");

    // pano de fundo do jogo
    backg = new Sprite("Resources/new/level_1.png");

    // adiciona jogador na cena
    scene->Add(DimensionFighter::player2, MOVING);

    // adiciona jogador na cena
    scene->Add(DimensionFighter::player, MOVING);
    // posi??o inicial
    DimensionFighter::player->MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    // posi??o inicial
    DimensionFighter::player2->MoveTo(window->CenterX() + 80, 24.0f, Layer::FRONT);

    life1 = DimensionFighter::player->life;
    life2 = DimensionFighter::player2->life;
    
    // ----------------------
    // plataformas
    // ----------------------

    //ok
    platform_1 = new Platform(-550, -23, 549, 23);
    platform_1->MoveTo(window->CenterX(), 565);
    scene->Add(platform_1, STATIC);

    //ok
    platform_2 = new Platform(-82, -19, 82, 19);
    platform_2->MoveTo(355, 442);
    scene->Add(platform_2, STATIC);

    platform_3 = new Platform(-82, -19, 82, 19);
    platform_3->MoveTo(778, 438);
    scene->Add(platform_3, STATIC);

    //ok
    platform_4 = new Platform(-82, -19, 82, 19);
    platform_4->MoveTo(145, 350);
    scene->Add(platform_4, STATIC);

    platform_5 = new Platform(-82, -19, 82, 19);
    platform_5->MoveTo(562, 336);
    scene->Add(platform_5, STATIC);

    //ok
    platform_6 = new Platform(-82, -19, 82, 19);
    platform_6->MoveTo(980, 350);
    scene->Add(platform_6, STATIC);

    // ----------------------

    // inicia com m?sica
    //DimensionFighter::audio->Frequency(MUSIC, 0.94f);
    //DimensionFighter::audio->Frequency(TRANSITION, 1.0f);
    //DimensionFighter::audio->Play(MUSIC);
    audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    life1 = DimensionFighter::player->life;
    life2 = DimensionFighter::player2->life;
    if (DimensionFighter::player->state == SPECIAL) {
        Attack* attack = new Attack(200, 300, 1);
        attack->MoveTo(DimensionFighter::player->X() + 30, DimensionFighter::player->Y(), Layer::FRONT);
        scene->Add(attack, STATIC);
    }
    
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
    else if (DimensionFighter::player->life <= 0 || DimensionFighter::player2->life <= 0 || window->KeyPress('N'))
    {
        DimensionFighter::NextLevel<Level2>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }    
   
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{   
    

    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    DimensionFighter::bit->Draw(180, 20, std::to_string(life1), red, Layer::FRONT, 0.6f);
    DimensionFighter::bit->Draw(1080, 20, std::to_string(life2), blue, Layer::FRONT, 0.6f);

    if (DimensionFighter::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    scene->Remove(DimensionFighter::player, MOVING);
    scene->Remove(DimensionFighter::player2, MOVING);
    delete backg;
    delete scene;
    delete audio;
}

// ------------------------------------------------------------------------------
