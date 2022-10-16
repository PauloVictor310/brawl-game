/**********************************************************************************
// Level2 (C�digo Fonte)
//
// Cria��o:     27 Set 2021
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   N�vel 2 do jogo
//
**********************************************************************************/

#include "GravityGuy.h"
#include "Home.h"
#include "Level2.h"
#include "GameOver.h"
#include "Player.h"
#include "Platform.h"
#include "Background.h"

#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

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
    //scene->Add(GravityGuy::player, MOVING);

    //GravityGuy::audio->Frequency(MUSIC, 1.00f);
    //GravityGuy::audio->Frequency(TRANSITION, 0.85f);
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    if (window->KeyPress(VK_ESCAPE) || GravityGuy::player->Level() == 2 || window->KeyPress('N'))
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Bottom() < 0 || GravityGuy::player->Top() > window->Height())
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<GameOver>();
        GravityGuy::player->Reset();
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

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------
