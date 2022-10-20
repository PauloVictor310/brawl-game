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

#include "DimensionFighter.h"
#include "PlayerInterface.h"
#include "Platform.h"
#include "Attack.h"
#include "Natsus.h"

// ---------------------------------------------------------------------------------

Natsus::Natsus()
{
    tileset = new TileSet("Resources/new/definitive/natsu.png", 118, 102, 10, 60);
    anim = new Animation(tileset, 0.120f, true);

    // sequências de animação do player
    uint normal[6] = { 10,11,12,13, 14, 15 };
    uint invert[6] = { 15,14,13,12, 11, 10};
    uint still[4] = { 0,1, 2, 3 };

    anim->Add(INVERTED, invert, 4);
    anim->Add(NORMAL, normal, 4);
    anim->Add(STILL, still, 4);

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
    type = PLAYER;

}

// ---------------------------------------------------------------------------------

Natsus::~Natsus()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Natsus::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX() + 300, 24.0f, Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}

void Natsus::Draw()
{
    anim->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

void Natsus::OnCollision(Object* obj)
{
    if (obj->Type() == ATTACK) {
        Attack* attack = (Attack*)obj;
        life -= attack->damage;
    }
    else if (obj->Type() == PLAYER) {

    }
    else {
        MoveTo(this->X(), obj->Y() - tileset->TileHeight() + 35);
    }
}

// ---------------------------------------------------------------------------------

void Natsus::Update()
{
    // ação da gravidade sobre o personagem
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

    // se todas as teclas estão liberadas, mude para o estado parado
    if (window->KeyUp('W') && window->KeyUp('S') && window->KeyUp('A') && window->KeyUp('D'))
    {
        state = STILL;
    }

    // atualiza animação
    anim->Select(state);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------