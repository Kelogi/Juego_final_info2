#include "rick.h"

void rick::CicloAutomatico_Rick()
{
    //Aplicar las leyes de la dinamica al personaje Rick

    if(this->saberRick_herido()==false and this->saber_Rick_in_Rock()==false){
        if(salto==true){
            t=k*n*TY;

            //a traves del parametro t, se obtiene la nueva posion en y del movmiento
            posicion_Y=yo_Salto-Vyo*t+0.5*g*t*t;

            //si la fuerza en x!=0, Rick previamente tomo impulso->trayectoria parabolica
            if(saberDatos(0)!=0)Posicion_X=xo_Salto+Vxo*t;

            /*si la posicion en Y del movmiento (de caida libre o parabolico) es menor que 300
            se posiciona a Rick en un punto de la trayectoria.
            */
            if(posicion_Y<=300){
                this->setY(posicion_Y);
                if(this->saberDatos(0)!=0)this->setX(Posicion_X);

             }

            /*Si rick esta saltando pero la posicion en Y es mayor que 300
            Rick esta en el sulo*/
            else {
                salto=false;
                posicion_Y=300;
                this->setY(300);
                //posicion final en x, del movimiento.
                this->setX(Posicion_X);
                n=0.0;
                //despues de saltar rick permanece quieto
                this->actualizarFuerzas(0,0);
            }
            n+=1.0;
        }

        else{

            //Aplicar las leyes de la dinamica al personaje Rick en direccion del eje X:
            Aceleracion_X = FuerzaEnX/masa;
            Velocidad_X = Aceleracion_X*T;
            //Se actuliza la nueva posicion en X de Rick
            Posicion_X = Posicion_X + Velocidad_X;
            //Dependiendo el signo de la velocidad se mueve Rick hacia la derecha o hacia la izquierda.
            if(FuerzaEnX!=0){
                if(Velocidad_X>0)this->Mover_derecha();
                if(Velocidad_X<0)this->Mover_izquierda();
                //Siempre actua la fuerza de friccion en el personaje, dependiendo el signo de la Fx de Rick se le suma o resta la de friccion.
                if(FuerzaEnX>0)FuerzaEnX -=friccionX;
                else  FuerzaEnX+=friccionX;
             }
            else Seleccion_rick(4);

        }
     }

}

rick::rick()
{
    Imagen_rick.load(":/imagenes/sprites-rick.png");
    setPos(0, 0);
    TimerRick= new QTimer(this);
    connect(TimerRick, SIGNAL(timeout()), this, SLOT(CicloAutomatico_Rick()));
    TimerRick->start(50);
}

void rick::Seleccion_rick(int Tipo)
{

    if(Tipo < 5){
        rick_ind = Imagen_rick.copy(size_spritex*Tipo, 0, size_spritex, size_spritey).scaled(50, 60);
    }
    else if(Tipo < 10){
        rick_ind = Imagen_rick.copy(size_spritex*(Tipo-5), size_spritey, size_spritex, size_spritey).scaled(50, 60);
    }
    setPixmap(rick_ind);

}

void rick::actualizarFuerzas(float fuerzaX, float fuerzaY)
{
    FuerzaEnX=fuerzaX;
    FuerzaEnY=fuerzaY;
}

void rick::actualizarVidas(int actualVidas)
{
    vidasRick=actualVidas;
}

void rick::actualizarPuntos(int actualPuntos)
{
    puntosRick=actualPuntos;
}

void rick::actualizarDisparos(int actualDisparos)
{
    disparosRick=actualDisparos;
}

int rick::saberVidas()
{
    return vidasRick;
}

int rick::saberDisparos()
{
    return disparosRick;
}

int rick::saberPuntos()
{
    return puntosRick;
}

float rick::saberDatos(int date)
{
    if(date==0) return FuerzaEnX;
    else if(date==1) return FuerzaEnY;
    else if (date==2) return Posicion_X;
    else if(date==3) return posicion_Y;
}

void rick::Mover_derecha()
{
    //se efectua el cambio de sprites.
    if(spriteMovDerecha<9) Seleccion_rick(spriteMovDerecha);

    else if(spriteMovDerecha==9) spriteMovDerecha=5;

    spriteMovDerecha++;
    //se actualiza la posicion de Rick
    this->setX(Posicion_X);
}

void rick::Mover_izquierda()
{
    //se efectua el cambio de sprites.
    if(spriteMovIzquierda<4) Seleccion_rick(spriteMovIzquierda);

    else if(spriteMovIzquierda==4) spriteMovIzquierda=0;

    spriteMovIzquierda++;
    //se actualiza la posicion de Rick
    if(Posicion_X>=0){
        this->setX(Posicion_X);
    }
    else{

        this->setX(0);
        Posicion_X=0;
        FuerzaEnX=0;
    }
}

void rick::Rick_salto()
{
    salto=true;
    xo_Salto=this->saberDatos(2);
    yo_Salto=this->saberDatos(3);
}

bool rick::saberSalta_Rick()
{
    return salto;
}

bool rick::saberRick_herido()
{
    return rick_herido;
}

void rick::actualizar_Rickherido(bool herido)
{
    rick_herido=herido;
}

bool rick::saber_Rick_in_Rock()
{
    return rick_InRock;
}

void rick::actualizar_RickinRock(bool inRock)
{
    rick_InRock=inRock;
}

void rick::actualizar_posicionRick(int x, int y)
{
    Posicion_X=x;
    posicion_Y=y;
}

void rick::recibir_Vyo(int Vy)
{
    Vyo=Vy;
}
