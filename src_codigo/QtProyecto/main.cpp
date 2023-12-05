#include "mainwindow.h"

#include <QApplication>

//Teorema del Seno y del Coseno.
float teoremacos(float lado1, float lado2, float angulo){
    float ladox;
    ladox= sqrt(lado1*lado1+lado2*lado2-(2*lado1*lado2*(cos(angulo*PI/180))));
    return ladox;
}

float teoremasen(float ang1, float lado, float ang2){
    float ang3, ladodesc;
    ang3=180-ang1+ang2;
    ladodesc=(sin(ang1*PI/180)*lado)/sin(ang3*PI/180);
    return ladodesc;
}

geometria2d crearTriangulo(int a, float b, float c, float d){
    geometria2d triangulo;
    triangulo.tipo=a;
    triangulo.lado1=b;
    triangulo.lado2=c;
    triangulo.lado3=d;

    cout<<"\nLas medidas de los lados del triangulo a graficar son: "<<endl;
    cout<<"Lado 1: "<<b<<"\nLado 2: "<<c<<"\nLado 3: "<<d<<endl;
    return triangulo;
}

geometria2d trianguloEquilatero(){
    int respuesta;
    cout<<"\n¿Dispone de la medida del lado del triangulo? (1-Si/2-No): ";
    //En este caso es imposible armar el triángulo con ángulos.
    cin>>respuesta;
    if(respuesta==1){
        float lado;
        cout<<"\nIntroduzca la medida de los lados del triangulo: ";
        cin>>lado;
        geometria2d triangulo;
        triangulo = crearTriangulo(1,lado,lado,lado);
        cout<<"\nCreando triangulo..."<<endl;
        return triangulo;
        //Confirmación de que el triángulo ha sido creado.
    }
    else if(respuesta==2){
        cout<<"\n||ERROR|| No se puede formar el Triangulo"<<endl;
    }
    else{
        cout<<"\n||ERROR|| Respuesta no valida. Por favor, intente nuevamente."<<endl;
    }
}

geometria2d trianguloIsosceles(){
    float respuesta, respuesta2, respuesta3, resp4, resp5, resp6, angulo2, angulo, anguloo, angulooo, ladoconocido, lado2, lado3;
    float ladonoconocido, ladonoconocido2, ladosiguales, ladosigualess, ladoo, ladooo, ladorestante, unicoladoconocido, medidaangulo, medidaanguloo;
    float lado2noconocido, lado3noconocido;
    cout<<"\n¿Dispone de las 3 medidas de los lados del triangulo? (1-Si/2-No): ";
    cin>>respuesta;
    if(respuesta==2){
            cout<<"\n¿Dispone de la medida de dos lados? (1-Si/2-No): ";
            cin>>respuesta3;
            if (respuesta3==1){
                cout<<"\n¿Son estos lados de la misma medida? (1-Si/2-No): ";
                cin>>resp4;
                if (resp4==1){
                    cout<<"\nIngrese la medida de los lados iguales: ";
                    cin>>ladosiguales;
                    cout<<"\nPara formar un triangulo con esta informacion es necesario que ingrese el angulo existente entre ambos lados: ";
                    cin>>anguloo;
                    ladonoconocido=teoremacos(ladosiguales,ladosiguales,anguloo);
                    if ((ladosiguales+ladosiguales<ladonoconocido)||(ladosiguales+ladonoconocido<ladosiguales)){
                        cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas ingresadas "<<endl;
                    }
                    else{
                        geometria2d triangulo;
                        triangulo = crearTriangulo(2,ladosiguales,ladosiguales,ladonoconocido);
                        cout<<"\nCreando triangulo..."<<endl;
                        return triangulo;
                    }
                }
                else if(resp4==2){
                    cout<<"\nIngrese la medida de uno de los lados: ";
                    cin>>ladoo;
                    cout<<"\nIngrese la medida del lado restante: ";
                    cin>>ladooo;
                    cout<<"\nPara formar un triangulo con esta informacion, es necesario que ingrese el angulo existente entre ambos lados: ";
                    cin>>angulooo;
                    ladonoconocido2=teoremacos(ladoo,ladooo,angulooo);   //ladonoconocido2 es igual a ladoo o ladooo
                    if ((ladoo+ladooo<ladonoconocido2)||(ladoo+ladonoconocido2<ladooo)){
                        cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas ingresadas."<<endl;
                    }
                    else{
                        geometria2d triangulo;
                        triangulo = crearTriangulo(2,ladoo,ladooo,ladonoconocido2);
                        cout<<"\nCreando triangulo..."<<endl;
                        return triangulo;
                    }

                }
            }

            else if(respuesta3==2){
                cout<<"\n¿Dispone de la medida de un lado? (1-Si/2-No): ";
                cin>>resp5;
                if (resp5==1){
                    cout<<"\nIngrese la medida del lado conocido: ";
                    cin>>unicoladoconocido;
                    cout<<"\n¿Dispone de los dos angulos que rodean el lado conocido? (1-Si/2-No): ";
                    cin>>resp6;
                    if (resp6==1){
                        cout<<"\nIngrese la medida de uno de los angulos: ";
                        cin>>medidaangulo;
                        cout<<"\nIngrese la medida del otro angulo: ";
                        cin>>medidaanguloo;
                        lado2noconocido=teoremasen(medidaangulo,unicoladoconocido,medidaanguloo);
                        lado3noconocido=teoremasen(medidaanguloo,unicoladoconocido,medidaangulo);
                        if ((lado2noconocido+lado3noconocido<unicoladoconocido)||(lado2noconocido+unicoladoconocido<lado3noconocido)){
                            cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas ingresadas "<<endl;
                        }
                        else{
                            geometria2d triangulo;
                            triangulo = crearTriangulo(2,lado2noconocido,lado3noconocido,unicoladoconocido);
                            cout<<"\nCreando triangulo..."<<endl;
                            return triangulo;
                        }
                        //Ahora tenemos los 3 lados, solo falta las condiciones de medidas.

                    }
                    else if (resp6==2){
                        cout<<"\n||ERROR|| Es imposible formar un triangulo con la infromacion dada."<<endl;
                    }
                }
                else if(resp5==2){
                    cout<<"\n||ERROR|| Es imposible formar un triangulo con la informacion dada."<<endl;
                }
            }

    }
    if(respuesta==1){
        cout<<"\nIngrese la medida de los lados iguales: ";
        cin>>ladosigualess;
        cout<<"\nIngrese la medida del lado restante: ";
        cin>>ladorestante;
        if ((ladosigualess+ladosigualess<ladorestante)||(ladosigualess+ladorestante<ladosigualess)){
            cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas ingresadas"<<endl;
        }
        else{
            geometria2d triangulo;
            triangulo = crearTriangulo(2,ladosigualess,ladosigualess,ladorestante);
            cout<<"\nCreando triangulo..."<<endl;
            return triangulo;
                    //Confirmación de que el triángulo ha sido creado.
        }
    }
}

geometria2d trianguloEscaleno(){
    float respuesta, resp2, resp3, resp4, ladorestante;
    float ladoconocido, angulo, anguloo, lado2noconocido, lado3noconocido;
    cout<<"\n¿Dispone de medidas de los lados del triangulo? (1-Si/2-No): ";
    cin>>respuesta;
    if(respuesta==2){
        cout<<"\nSi no dispone de ninguna medida de los lados del triangulo, no es posible formarlo."<<endl;
    }
    else if(respuesta==1){
        int respuesta2;
        cout<<"\n¿Cuantos lados son conocidos? (1/2/3): ";
        cin>>respuesta2;
        if(respuesta2==1){
            cout<<"\n¿Conoce los angulos que rodean al lado conocido? (1-Si/2-No): ";
            cin>>resp2;
            if (resp2==2){
                cout<<"\n||ERROR|| No es posible formar un triangulo con la informacion dada."<<endl;
            }
            else if(resp2==1){
                cout<<"\nIngrese la medida del lado conocido: ";
                cin>>ladoconocido;
                cout<<"\nIngrese la medida de uno de los angulos: ";
                cin>>angulo;
                cout<<"\nIngrese la medida del otro angulo: ";
                cin>>anguloo;
                lado2noconocido=teoremasen(angulo,ladoconocido,anguloo);
                lado3noconocido=teoremasen(anguloo,ladoconocido,angulo);
                if ((lado2noconocido+lado3noconocido<ladoconocido)||(lado2noconocido+ladoconocido<lado3noconocido)||(lado3noconocido+ladoconocido<lado2noconocido)){
                    cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas ingresadas."<<endl;
                }
                else{
                    geometria2d triangulo;
                    triangulo = crearTriangulo(3,ladoconocido,lado2noconocido,lado3noconocido);
                    cout<<"\nCreando triangulo..."<<endl;
                    return triangulo;
                    //Confirmación de que el triángulo ha sido creado.
                }

            }
        }
        else if(respuesta2==2){
            float medidaprimerlado, medidasegundolado, angulo;
            cout<<"\nIngrese la medida del primer lado: ";
            cin>>medidaprimerlado;
            cout<<"\nIngrese la medida del segundo lado: ";
            cin>>medidasegundolado;
            cout<<"\nPara formar un triangulo con esta informacion, es necesario que ingrese el angulo existente entre ambos lados: ";
            cin>>angulo;
            ladorestante=teoremacos(medidaprimerlado,medidasegundolado,angulo);
            cout<<"\nAhora tenemos todos las medidas de los lados!"<<endl;
            if ((medidaprimerlado+medidasegundolado<ladorestante)||(medidaprimerlado+ladorestante<medidasegundolado)||(medidasegundolado+ladorestante<medidaprimerlado)){
                cout<<"Pero... ||ERROR|| Es imposible formar un triangulo con las medidas ingresadas."<<endl;
            }
            else{
                geometria2d triangulo;
                triangulo = crearTriangulo(3,medidaprimerlado,medidasegundolado,ladorestante);
                cout<<"\nCreando triangulo..."<<endl;
                return triangulo;
            }
        }
        else if(respuesta2==3){
            float lado1, lado2, lado3;
            cout<<"\nIntroduzca el primer lado: ";
            cin>>lado1;
            cout<<"\nIntroduzca el segundo lado: ";
            cin>>lado2;
            cout<<"\nIntroduzca el tercer lado: ";
            cin>>lado3;
            if ((lado1+lado2<lado3)||(lado1-lado2>lado3)||(lado2-lado1>lado3)){
                cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas dadas."<<endl;
            }
            else if((lado2+lado3<lado1)||(lado2-lado3>lado1)||(lado3-lado2>lado1)){
                cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas dadas."<<endl;
            }
            else if((lado3+lado1<lado2)||(lado3-lado1>lado2)||(lado1-lado3>lado2)){
                cout<<"\n||ERROR|| Es imposible formar un triangulo con las medidas dadas."<<endl;
            }
            else{
                geometria2d triangulo;
                triangulo = crearTriangulo(3,lado1,lado2,lado3);
                cout<<"\nCreando triangulo..."<<endl;
                //Confirmación de que el triángulo ha sido creado.
                return triangulo;
            }
        }
        else{
            cout<<"\n||ERROR|| Respuesta no valida. Por favor, intente nuevamente."<<endl;
        }
    }
    else{
        cout<<"\n||ERROR|| Respuesta no valida. Por favor, intente nuevamente."<<endl;
    }
}

geometria3d crearPiramide(float alt){
    geometria3d piramide;
    piramide.altura = alt;
    return piramide;
}

geometria3d piramide_default(){

    geometria3d piramide;
    piramide = crearPiramide(1);
    cout<<"\Creando piramide..."<<endl;
    //Confirmación.
    return piramide;
}

geometria getInfo(){
    geometria info;
    int visualizar;
    cout<<"||| ¡Bienvenido al visualizador de triangulos 2D y piramides 3D! |||"<<endl << endl;
        int tipo;
        cout<<"Introduzca el tipo de triangulo: "<<endl;
        cout<<"(1.- Equilatero / 2.- Isosceles / 3.- Escaleno): ";
        cin>>tipo;
        if(tipo==1){
            geometria2d triangulo = trianguloEquilatero();
            info.triforce = triangulo;
            geometria3d piramide = piramide_default();
            info.pyramid = piramide;
            return info;
        }
        else if(tipo==2){
            geometria2d triangulo = trianguloIsosceles();
            info.triforce = triangulo;
            geometria3d piramide = piramide_default();
            info.pyramid = piramide;
            return info;
        }
        else if(tipo==3){
            geometria2d triangulo = trianguloEscaleno();
            info.triforce = triangulo;
            geometria3d piramide = piramide_default();
            info.pyramid = piramide;
            return info;
        }
}

//Funcion para chequear el tamaño del lado del triangulo y que este no sea muy grande ni muy pequeño.
float checkSize(float lado){
    if(lado<100 && lado>=10){
        return lado*2;
    }
    else if(lado < 10){
        return lado*4;
    }
    else if(lado>550){
        cout << "\n||ERROR|| El lado de tamaño " << lado << " es demasiado grande para poder graficar." << endl;
        return 0;
    }
    else{
        return lado;
    }
}

int main(int argc, char *argv[])
{
    geometria informacion = getInfo();

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Resultado de la Visualizacion");

    float ld1_tr = (informacion.triforce).lado1;
    float ld2_tr = (informacion.triforce).lado2;
    float ld3_tr = (informacion.triforce).lado3;
    int tipo_tr = (informacion.triforce).tipo;

    //Verificacion de que no existen "lados 0".
    if( (ld1_tr!=0) && (ld2_tr!=0) && (ld3_tr!=0) ){
            //Creacion de lados listos para poder ser graficados sin inconvenientes.
            if((informacion.triforce).tipo == 1){
                float lado_graf = checkSize(ld3_tr);
                if(lado_graf != 0){
                    w.getPuntos(lado_graf, lado_graf, lado_graf);
                    w.getTipo(1);
                    w.show();
                    return a.exec();
                }
            }

            else{
                float lado1_graf = checkSize(ld1_tr);
                float lado2_graf = checkSize(ld2_tr);
                float lado3_graf = checkSize(ld3_tr);

                if(lado1_graf != 0 && lado2_graf != 0 && lado3_graf != 0){
                    w.getPuntos(lado1_graf, lado2_graf, lado3_graf);
                    w.getTipo(tipo_tr);
                    w.show();
                    return a.exec();
                }
            }
    }
    return 0;
}
