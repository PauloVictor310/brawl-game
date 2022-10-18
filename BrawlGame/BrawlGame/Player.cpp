/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Player.h"
#include "DimensionFighter.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/new/definitive/narutinho/naruto_run.png", 72, 59, 6, 12);
    anim = new Animation(tileset, 0.120f, true);

    // sequências de animação do player
    uint invert[6] = { 6, 7, 8, 9, 10, 11 };
    uint normal[6] = { 0, 1, 2, 3, 4, 5 };
    uint still[2] = { 0, 1 };

    anim->Add(INVERTED, invert, 6);
    anim->Add(NORMAL, normal, 6);
    anim->Add(STILL, still, 2);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    gravity = NORMAL;  
    level = 0;
    state = STILL;
    speed = 300.0f;

    // posição inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    Translate(0, -2);
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // ação da gravidade sobre o personagem
    if (gravity == NORMAL)    
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);

    // anda para esquerda
    if (window->KeyDown(VK_LEFT))
    {
        state = INVERTED;
        Translate(-speed * gameTime, 0);
    }

    // anda para direita
    if (window->KeyDown(VK_RIGHT))
    {
        state = NORMAL;
        Translate(speed * gameTime, 0);
    }

    // se todas as teclas estão liberadas, mude para o estado parado
    if (window->KeyUp(VK_UP) && window->KeyUp(VK_DOWN) && window->KeyUp(VK_LEFT) && window->KeyUp(VK_RIGHT))
    {
        state = STILL;
    }

    // atualiza animação
    anim->Select(state);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------