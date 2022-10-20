/**********************************************************************************
// Score (Arquivo de Cabeçalho)
//
// Criação:     18 Set 2022
//
// Compilador:  Visual C++ 2019
//
// Descrição:   Bullets do Etther
//
**********************************************************************************/

#ifndef _DF_Score_H_
#define _DF_Score_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                        // tipos especúŸicos da engine
#include "Object.h"      
#include "Scene.h"
#include "Sprite.h"
#include "DimensionFighter.h"

// ---------------------------------------------------------------------------------


class Score : public Object
{
private:
    Sprite* sprite = nullptr;

public:

    Score(int life, bool p1);                // construtor
    ~Score();                               // destrutor

    int life; // velocidade no eixo Y]
    bool p1;

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object* obj);               // desenho
};

// ---------------------------------------------------------------------------------

#endif*/