/**********************************************************************************
// Naruto (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador 
//
**********************************************************************************/

#include "Naruto.h"
#include "PlayerInterface.h"
#include "DimensionFighter.h"
#include "Attack.h"
#include "Platform.h"

// ---------------------------------------------------------------------------------

Naruto::Naruto()
{
    tileset = new TileSet("Resources/narutinho.png", 194, 101, 6, 126);
    anim = new Animation(tileset, 0.120f, true);

    // sequências de animação do player
    uint rightrun[6] = { 78, 79, 80, 81, 82, 83 };
    uint leftrun[6] = { 84, 85, 86, 87, 88, 89 };
    uint special[30] = { 0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 12, 13, 14,15,16,18,19,20,21,22, 24, 25, 26, 27, 28 };
    uint jump[5] = { 55, 56, 57, 58, 59 };
    uint still[2] = { 90, 91 };

    anim->Add(LEFTRUN, leftrun, 6);
    anim->Add(RIGHTRUN, rightrun, 6);
    anim->Add(SPECIAL, special, 30);
    anim->Add(JUMP, jump, 5);
    anim->Add(STILL, still, 2);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 3.0f,
        -1.0f * tileset->TileHeight() / 6.0f,
        tileset->TileWidth() / 14.0f,
        tileset->TileHeight() / 2.2f));
    
    // inicializa estado do Naruto
    gravity = NORMAL;  
    level = 0;
    state = STILL;
    speed = 300.0f;

    
}

// ---------------------------------------------------------------------------------

Naruto::~Naruto()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Naruto::Reset()
{
    // volta ao estado inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}

void Naruto::Draw()
{
    anim->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------

void Naruto::OnCollision(Object * obj)
{
    
    if (obj->Type() == ATTACK) {
        Attack* attack = (Attack*)obj;
        life -= attack->damage;
    }
    else if (obj->Type() == PLAYER) {

    }
    else {
        MoveTo(this->X(), obj->Y() - tileset->TileHeight() + 33.3);
    }
}

// ---------------------------------------------------------------------------------

void Naruto::Update()
{
    // ação da gravidade sobre o personagem
    if (gravity == NORMAL)    
        Translate(0, 300 * gameTime);
    else
        Translate(0, -30);

    // anda para esquerda
    if (window->KeyDown(VK_LEFT))
    {
        state = LEFTRUN;
        Translate(-speed * gameTime, 0);
    }

    // anda para direita
    if (window->KeyDown(VK_RIGHT))
    {
        state = RIGHTRUN;
        Translate(speed * gameTime, 0);
    }

    // pula
    if (window->KeyPress(VK_UP))
    {
        state = JUMP;
        Translate(speed * gameTime, -30);
    }

    if (window->KeyDown(VK_SPACE))
    {
        state = SPECIAL;
    }

    // se todas as teclas estão liberadas, mude para o estado parado
    if (window->KeyUp(VK_UP) && window->KeyUp(VK_DOWN) && window->KeyUp(VK_LEFT) && window->KeyUp(VK_RIGHT) && window->KeyUp(VK_SPACE))
    {
        state = STILL;
    }

    // atualiza animação
    anim->Select(state);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------