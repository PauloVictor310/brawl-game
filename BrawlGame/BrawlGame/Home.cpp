/**********************************************************************************
// Home (Código Fonte) 
// 
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "DimensionFighter.h"
#include "Home.h"
#include "Level1.h"
#include "Naruto.h"
#include "Natsus.h"
#include "Alex.h"
#include "Veemon.h"
#include "SelectScreen.h"

// ------------------------------------------------------------------------------

Audio* Home::audio = nullptr;
Scene* Home::scene = nullptr;

// ------------------------------------------------------------------------------

void Home::Init()
{
    // cria gerenciador de cena
    scene = new Scene();
    backg = new Sprite("Resources/new/init.png");

    platform_1 = new Platform(-550, -23, 549, 23);
    platform_1->MoveTo(window->CenterX(), 565);
    scene->Add(platform_1, STATIC);

    //tileset = new TileSet("Resources/PressEnter.png", 72, 48, 1, 5);
    //anim = new Animation(tileset, 0.180f, true);
    //DimensionFighter::audio->Play(MENU, true);
    // adiciona jogador na cena
    PlayerInterface* naruto = new Naruto();
    PlayerInterface* alex = new Alex();
    scene->Add(naruto, MOVING);

    // adiciona jogador na cena
    scene->Add(alex, MOVING);
    // posição inicial
    naruto->MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    // posição inicial
    alex->MoveTo(window->CenterX() + 80, 24.0f, Layer::FRONT);
    audio = new Audio();
    audio->Add(MUSIC, "Resources/home.wav");
    audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();
    
    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
        DimensionFighter::audio->Stop(MENU);
        DimensionFighter::NextLevel<SelectScreen>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();
    if (DimensionFighter::viewBBox)
        scene->DrawBBox();
    //anim->Draw(545, 275);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    //delete anim;
    //delete tileset;
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------