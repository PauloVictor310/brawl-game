/**********************************************************************************
// Player (C�digo Fonte)
//
// Cria��o:     20 Abr 2012
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player2.h"
#include "DimensionFighter.h"
#include "PlayerInterface.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Player2::Player2()
{
    tileset = new TileSet("Resources/new/definitive/alex/alexkidd.png", 64, 56, 8, 32);
    anim = new Animation(tileset, 0.120f, true);

    // sequ�ncias de anima��o do player
    uint normal[4] = { 0,1,2,3 };
    uint invert[4] = { 4,5,6,7};
    uint still[2] = { 12,13 };

    anim->Add(INVERTED, invert, 4);
    anim->Add(NORMAL, normal, 4);
    anim->Add(STILL, still, 2);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 3.0f,
        -1.0f * tileset->TileHeight() / 3.0f,
        tileset->TileWidth() / 14.0f,
        tileset->TileHeight() / 2.2f));

    // inicializa estado do player
    gravity = NORMAL;
    level = 0;
    state = STILL;
    speed = 300.0f;

    
}

// ---------------------------------------------------------------------------------

Player2::~Player2()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Player2::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX() + 300, 24.0f, Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}

void Player2::Draw()
{
    anim->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

void Player2::OnCollision(Object* obj)
{
    Translate(0, -2);
}

// ---------------------------------------------------------------------------------

void Player2::Update()
{
    // a��o da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 300 * gameTime);
    else
        Translate(0, -30);

    // anda para esquerda
    if (window->KeyDown('A'))
    {
        state = INVERTED;
        Translate(-speed * gameTime, 0);
    }

    // anda para direita
    if (window->KeyDown('D'))
    {
        state = NORMAL;
        Translate(speed * gameTime, 0);
    }

    // se todas as teclas est�o liberadas, mude para o estado parado
    if (window->KeyUp('W') && window->KeyUp('S') && window->KeyUp('A') && window->KeyUp('D'))
    {
        state = STILL;
    }

    // atualiza anima��o
    anim->Select(state);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------