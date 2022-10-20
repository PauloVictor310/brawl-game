/**********************************************************************************
// Score (Arquivo de Cabe�alho)
//
// Cria��o:     18 Set 2022
//
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bullets do Etther
//
**********************************************************************************/

#ifndef _DF_Score_H_
#define _DF_Score_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                        // tipos espec��icos da engine
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

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object* obj);               // desenho
};

// ---------------------------------------------------------------------------------

#endif*/