#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <Servo.h>

/*--------------------------------------------------------------------------------
 * Definicion de los pines conectados a los servos y a las 4 entradas del motor
 *------------------------------------------------------------------------------*/
#define SERVOPINZA 6
#define SERVOGRUA 5
#define SERVOMUNECA 3

#define BASE0 11
#define BASE1 10
#define BASE2 9
#define BASE3 8

/*--------------------------------------------------------------------------------
 * Grados de apertura de las tres posiciones de PINZA
 *------------------------------------------------------------------------------*/
#define PINZA_ABIERTA 100
#define PINZA_SEMI 25
#define PINZA_CERRADA 0

/*--------------------------------------------------------------------------------
 * Grados de giro de las tres posiciones de la MUNECA
 *------------------------------------------------------------------------------*/
#define MUNECA0 0
#define MUNECA1 90
#define MUNECA2 180

/*--------------------------------------------------------------------------------
 * Grados de giro de las tres posiciones de la GRUA
 *------------------------------------------------------------------------------*/
#define GRUA_ARRIBA 130
#define GRUA_MITAD 40
#define GRUA_ABAJO 10

/*--------------------------------------------------------------------------------
 * Pasos que necesita el motor para girar una cara 90º
 *------------------------------------------------------------------------------*/
#define PASOS_POR_CARA 103

/*--------------------------------------------------------------------------------
 * Pasos que necesita retroceder el motor para compensar la holgura de la base
 *------------------------------------------------------------------------------*/
#define PASOS_RETROCESO 4

/*--------------------------------------------------------------------------------
 * Retardo entre pasos del motor. A menos retardo, mas velocidad
 *------------------------------------------------------------------------------*/
#define SPEED 3


class Robot {

    public:

        
        Robot();
        ~Robot();
        void init();

        void setServo(Servo servo, int nuevoEstado, int espera);

        void preparaY();
        void preparaX(int giros);
        void preparaGiro();

        void traslacionX(int giros);

        void giraBase(int caras);
        struct s_motor {
            int pin[4];
            int indexStep;
            int position;
            int speed;
        } base ;
            

        void do1step(s_motor* motor, int direccion);
        void traslacion(int stepsGrua, int speed, int speed2); 

        void setSpeed(int speed);

        Servo servoMuneca;
        Servo servoPinza;    
        Servo servoGrua;

        void apagarMotor(s_motor motor);
        float desfase; // No hay un valor entero justo para un giro de 90 grados
        float actualDesfase; // No hay un valor entero justo para un giro de 90 grados

    private:
        // variables aux, para no tener que inicializar/destruir en llamadas
        int i;

};

#endif
