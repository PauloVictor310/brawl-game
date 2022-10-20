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
#include "Veemon.h"

// ---------------------------------------------------------------------------------

Veemon::Veemon()
{
    tileset = new TileSet("Resources/new/definitive/digimon/digimon copy.png", 111, 106, 9, 72);
    anim = new Animation(tileset, 0.120f, true);

    // sequências de animação do player
    uint normal[8] = { 63,64,65,66,67,68,69,70 };
    uint invert[8] = { 54,55,56,57,58,59,60,61 };
    uint still[9] = { 27,28, 29, 30, 31, 32, 33, 34, 35};

    anim->Add(INVERTED, invert, 8);
    anim->Add(NORMAL, normal, 8);
    anim->Add(STILL, still, 9);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 3.0f,
        -1.0f * tileset->TileHeight() / 8.0f,
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

Veemon::~Veemon()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Veemon::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX() + 300, 24.0f, Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}

void Veemon::Draw()
{
    anim->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

void Veemon::OnCollision(Object* obj)
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

void Veemon::Update()
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