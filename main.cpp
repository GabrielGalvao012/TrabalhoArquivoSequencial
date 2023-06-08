#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>

using namespace std;

struct cidades {
    int codigoCidade;
    char nomeCidade[30];
    char uf[2];
};

struct apresentadores{
    int codigoApresentador;
    char nomeApresentador[30];
};

struct eventos {
    int codigoEvento;
    char descricaoEvento[30];
    int codCidade;
    int codApresentador;
    int quantidadeParticipante;
    int limiteParticipante;
    float precoUnitario;
    int codEvento;
};

struct participantes{
    int codigoParticipante;
    char nomeParticipante[30];
    int codigoEvento;
};


int verificarCidade(struct cidades CI[], int cod, int contadorCidade){
    int i = 0, f=contadorCidade;
    int m=(i+f)/2;
    int codEncontrado;

    for(; f >= i && cod != CI[m].codigoCidade; m = (i + f)/2){
        if (cod > CI[m].codigoCidade)
            i = m + 1;
        else
            f = m - 1;
    }

    if( cod == CI[m].codigoCidade){
        cout<<"\nCidade encontrada";
        cout<<"\nNome da cidade: " <<CI[m].nomeCidade;
        cout<<"\nEstado: "<<CI[m].uf<<endl;
        cout<<"__________________________________________________________________________"<<endl;
        codEncontrado = CI[m].codigoCidade;
        return m;
    } else {
        return -1;
    }
}
int verificarApresentador(struct apresentadores AP[], int cod, int contadorApresentador){
    int i = 0, f=contadorApresentador;
    int m=(i+f)/2;
    int codAPencontrado = 0;

    for(; f >= i && cod != AP[m].codigoApresentador; m = (i + f)/2){
        if(cod > AP[m].codigoApresentador)
            i = m + 1;
        else
            f = m - 1;
    }
    if( cod == AP[m].codigoApresentador){

        cout<<"\nApresentador encontrado.";
        cout<<"\nNome do apresentador: "<<AP[m].nomeApresentador<<endl;
        cout<<"__________________________________________________________________________"<<endl;
        codAPencontrado = AP[m].codigoApresentador;
        //cout<<"\n apresentador"<< codAPencontrado;
        return m;
    }else {
        return -1;
    }
}
int verificarParticipantes(struct participantes PA[], int contadorParticipantes, int codigoParticipante){
    int i = 0, f = contadorParticipantes;
    int m = (i + f) / 2;
    for(; f > i && codigoParticipante != PA[m].codigoParticipante; m = (i + f) / 2){
        if(codigoParticipante > PA[m].codigoParticipante)
            i = m +1;
        else
            f = m - 1;
    }
    if (codigoParticipante == PA[m].codigoParticipante){
        cout <<PA[m].codigoParticipante;
        return m;
    } else
        return -1;
}
int verificarEvento(struct eventos EV[], int codEvento, int contEvento, cidades CI[], apresentadores AP[]){
    int i = 0, f=contEvento;
    int m=(i+f)/2;
    int codEventoEncontrado = 0;
    for (; f >= i && codEvento != EV[m].codigoEvento; m = (i + f)/2){
        if(codEvento > EV[m].codigoEvento)
            i = m + 1;
        else
            f = m - 1;
    }
    if( codEvento == EV[m].codigoEvento){
        cout<<"---------------Evento encontrado---------------"<<endl;
        cout<<"\nDescricao do evento: "<<EV[m].descricaoEvento<<endl;
        cout<<"cidade do evento: "<<CI[m].nomeCidade<<endl;
        cout<<"apresentador do evento: "<<AP[m].nomeApresentador<<endl;
        cout<<"__________________________________________________________________________"<<endl;
        codEventoEncontrado = EV[m].codigoEvento;

        return m;
    }else {
        return -1;
    }
}

void leituraCidades(struct cidades CI[], int &contadorCidade){
    int saida = 1;
    int i= 0;

    for(; i<20 && saida !=0; i++ ){
        cout<<"\nDigite o codigo da cidade: ";
        cin>>CI[i].codigoCidade;
        cin.ignore();
        if(CI[i].codigoCidade > 0){
            cout<<"\nDigite o nome da cidade: ";
            gets(CI[i].nomeCidade);
            cout<<"\nDigite a UF: ";
            cin>>CI[i].uf;
            cout<<"__________________________________________________________________________"<<endl;
            cin.ignore();
        }
        else {
            saida = 0;
        }
    }
    contadorCidade=i-1;
    cout<<"Foram cadastradas (" <<contadorCidade<< ") Cidades."<<endl;
}
void leituraApresentadores(struct apresentadores AP[], int &contadorApresentador){
    int i=0;
    int saida = 1;

    for(; i<20 && saida !=0; i++ ){
        cout<<"\nDigite o codigo do apresentador: ";
        cin>>AP[i].codigoApresentador;
        cin.ignore();
        if(AP[i].codigoApresentador > 0){
            cout<<"\nDigite o nome do apresentador: ";
            gets(AP[i].nomeApresentador);
            cout<<"__________________________________________________________________________"<<endl;
        }
        else {
            cout<<"\nApresentadores cadastrados."<<endl;
            saida = 0;
        }
    }
    contadorApresentador=i-1;
    cout<<"Foram cadastrados ("<<contadorApresentador<<") Apresentadores.";
}
void leituraEventos(struct eventos EV[],int &contEvento,struct cidades CI[], struct apresentadores AP[],
                    int contadorCidade, int contadorApresentador){
    int i=0;
    int x=1;
    int y=1;
    int saida = 1;
    int achouCidade;
    int achouApresentador;

    for(; i<20 && saida !=0; i++ ){
        cout<<"Digite o codigo do evento: ";
        cin>>EV[i].codigoEvento;
        cin.ignore();
        if(EV[i].codigoEvento > 0){
            cout<<"Digite a descricao do evento: ";
            gets(EV[i].descricaoEvento);
            cout<<"__________________________________________________________________________"<<endl;

            x=1;
            while (x !=0){
                cout<<"Digite o codigo da cidade para o evento:  ";
                cin>>EV[i].codCidade;
                cin.ignore();

                achouCidade = verificarCidade(CI,EV[i].codCidade, contadorCidade);
                if(achouCidade != -1){
                    x = 0;
                }
                else {
                    cout<<"\n !!! Cidade nao encontrada informe um codigo valido !!! \n"<<endl;
                }
            }
            y=1;
            while (y !=0){
                cout<<"Digite o codigo do apresentador do evento: ";
                cin>>EV[i].codApresentador;
                cin.ignore();

                achouApresentador = verificarApresentador(AP, EV[i].codApresentador,contadorApresentador);
                if(achouApresentador != -1){
                    y = 0;
                }
                else{
                    cout<<"\n !!! Apresentador nao encontrada informe um codigo valido !!! \n"<<endl;
                }
            }

            cout<<"\nInforme qual sera o limite de participantes: ";
            cin>>EV[i].limiteParticipante;
            cin.ignore();

            cout<<"\nDigite a quantidade de participantes: ";
            cin>>EV[i].quantidadeParticipante;
            cin.ignore();

            while(EV[i].quantidadeParticipante > EV[i].limiteParticipante){
                cout<<"\n LIMITE DE PARTICIPANTES ULTRAPASSADO"<<endl;
                cout<<"\nInforme um valor menor que ("<<EV[i].limiteParticipante<<") novo valor: ";
                cin>>EV[i].quantidadeParticipante;
                cin.ignore();
            }
            cout << "\nInforme qual o preco de entrada para este evento: ";
            cin>>EV[i].precoUnitario;
            cin.ignore();
            cout<<"__________________________________________________________________________"<<endl;

            contEvento = i+1;
        }
        else {
            cout<<"Eventos cadastrados..."<<endl;
            saida = 0;
        }
    }
    cout<<"Foram cadastrados (" << contEvento<< ") eventos."<<endl;
}
void leituraParticipantes(struct participantes PA[],struct eventos EV[], int contEvento, cidades CI[], apresentadores AP[], int contadorParticipantes){
    int i = 0;
    int saida = 1;
    int eventoEncontrado;
    int x = 0;
    int verificadorCodEvento;

    for(;i<20 && saida != 0; i++){

        cout<<"Digite o codigo do participante: ";
        cin>>PA[i].codigoParticipante;
        cin.ignore();

        if(PA[i].codigoParticipante > 0 ){
            cout<<"Informe o nome do participante: ";
            gets(PA[i].nomeParticipante);

            x=1;
            while(x != 0){
                cout<<"Informe o evento do participante: ";
                cin>>verificadorCodEvento;
                cin.ignore();
                eventoEncontrado = verificarEvento(EV,verificadorCodEvento,contEvento, CI, AP);

                if(eventoEncontrado != -1 ){
                    x=0;
                }
                else{
                    cout<<"\n Participante nao encontrada informe um codigo valido! \n"<<endl;
                }
            }
        }else{
            saida=0;
        }
        contadorParticipantes = i+1-1;
    }
    cout<<"Foram cadastrados (" << contadorParticipantes<< ") participantes"<<endl;
}

void incluirParticipantes(struct participantes PA[], int contadorParticipantes, struct eventos EV[], int contEventos, struct cidades CI[],
                          int contadorCidade, struct apresentadores AP[], int contadorApresentador){

    int eventoEncontrado = 0;
    int refCidade = 0;
    int refApresentador = 0;
    int codEvento;
    int codParticipante;

    cout << "Digite o codigo do evento que deseja inscrever o participante: ";
    cin >> codEvento;

    if(codEvento != 0){
        cout<< "\n---------------Descricao do evento---------------"<<endl;
        eventoEncontrado = verificarEvento(EV,codEvento,contEventos, CI, AP);
        getch();
        if(eventoEncontrado != -1){
            refCidade = EV[eventoEncontrado].codCidade;
            cout<<"-------------Cidade do evento-------------";
            verificarCidade(CI,EV[eventoEncontrado].codCidade, contadorCidade);
            refApresentador = EV[eventoEncontrado].codApresentador;
            cout<<"-------------Apresentador do evento-------------";
            verificarApresentador(AP, EV[eventoEncontrado].codApresentador,contadorApresentador);

            if(EV[eventoEncontrado].quantidadeParticipante < EV[eventoEncontrado].limiteParticipante){
                int codParticipante = 0, participanteEncontrado = 0;
                cout <<"\nHa vagas disponiveis!"<<endl;
                cout <<"\nDigite o codigo do participante a ser inscrito: ";
                cin >>codParticipante;

                if(codParticipante != 0){
                    participanteEncontrado =  verificarParticipantes(PA, contadorParticipantes, codParticipante);
                    PA[participanteEncontrado].codigoEvento = codEvento;
                    EV[eventoEncontrado].quantidadeParticipante = EV[eventoEncontrado].quantidadeParticipante + 1;
                    cout<<"\n Participante inscrito! ";
                }
            } else {
                cout <<"O evento escolhido não possui vagas para novas inscrições";
            }
            cout << "Quantidade de participantes: " << EV[eventoEncontrado].quantidadeParticipante << endl;
            cout << "Limite de participantes: " << EV[eventoEncontrado].limiteParticipante << endl;
        } else {
            cout << "Evento não encontrado!" << endl;
        }
    }
    getch();
}
void incluirApresentador(struct apresentadores A[], int contA, struct apresentadores P[], int contP, struct apresentadores R[], int &contR){
    int i = 0, a = 0, p = 0;

    for (;i < contA && a < contP; p++){
        if(A[i].codigoApresentador < P[a].codigoApresentador){
            R[p].codigoApresentador = A[i].codigoApresentador;
            strcpy (R[p].nomeApresentador,A[i].nomeApresentador);
            i++;
        }
        else {
            R[p].codigoApresentador = P[a].codigoApresentador;
            strcpy(R[p].nomeApresentador,P[a].nomeApresentador);
            a++;
        }
    }
    while (i< contA){
        R[p].codigoApresentador = A[i].codigoApresentador;
        strcpy (R[p].nomeApresentador,A[i].nomeApresentador);
        i++;
        p++;
    }
    while (a<contP){
        R[p].codigoApresentador = P[a].codigoApresentador;
        strcpy (R[p].nomeApresentador,P[a].nomeApresentador);
        a++;
        p++;
    }
    contR = p;
    cout<<"\nInclusao concluida...";
    getch();
}

void mostrarCidades(struct cidades CI[], int contCID){
    cout << "\t\tIMPRIMINDO CIDADES\n\n";
    for (int i = 0; i < contCID; i++)
    {
        cout << "ID: " << CI[i].codigoCidade << endl;
        cout << "Nome: " << CI[i].nomeCidade << endl;
        cout << "UF: " << CI[i].uf << endl;
        cout << "============================================\n";
    }
}
void mostrarApresentador(struct apresentadores AP[], int contAPR){
    system("cls");
    cout << "\t\tIMPRIMINDO APRESENTADORES\n\n";
    for (int i = 0; i < contAPR; i++)
    {
        cout << "ID: " << AP[i].codigoApresentador << endl;
        cout << "Nome: " << AP[i].nomeApresentador << endl;
        cout << "============================================\n";
    }
}
void mostrarEvento(struct eventos EV[],int contEVEN){
    system("cls");
    cout << "\t\tIMPRIMINDO EVENTOS\n\n";
    for (int i = 0; i < contEVEN; i++)
    {
        cout << "Codigo: " << EV[i].codigoEvento << endl;
        cout << "Nome: " << EV[i].descricaoEvento << endl;
        cout << "Codigo cidade: " << EV[i].codCidade << endl;
        cout << "Codigo apresentador: " << EV[i].codApresentador << endl;
        cout << "Limite de participantes: " << EV[i].limiteParticipante << endl;
        cout << "Quantidade de participantes: " << EV[i].quantidadeParticipante << endl;
        cout << " Valor de entrada para o evento: " << EV[i].precoUnitario << endl;
        cout << "==========================================================\n";
    }
}
void mostrarParticipante(struct participantes PA[], int contPART){
    system("cls");
    cout << "\t\tIMPRIMINDO EVENTOS\n\n";
    for (int i = 0; i < contPART; i++){
        cout << "Codigo: " << PA[i].codigoParticipante << endl;
        cout << "Nome: " << PA[i].nomeParticipante << endl;
        cout << "Codigo de evento que participara: " << PA[i].codigoEvento << endl;
    }
}


int main(){

    struct apresentadores AP[20];
    int contadorApresentador;
    struct apresentadores velhoAP[2], aguardandoAP[2], atualAP[4];
    int contApresentadorVelho = 0, contApresentadorAguardando = 0, contApresentadorAtual = 0;
    int contAPR;

    struct eventos EV[20];
    int contEvento;
    struct eventos velhoEV[2], aguardandoEV[2], atualEV[4];
    int contEventoVelho = 0, contEventoAguardando = 0, contEventoAtual = 0;
    int contEVEN;

    struct participantes P[20], A[20], R[40];
    struct participantes PA[20];
    int contadorParticipantes;
    int verificadorCodEvento;
    int qtdeParticipantes = 5;
    struct participantes listaParticipantes[qtdeParticipantes];
    int contPART;

    //int contC, contI, contD;
    struct cidades CI[20];
    int contadorCidade;
    int qtdeCidades = 5;
    struct cidades listaCidades[qtdeCidades];
    int contCID;

    int contApresentadorInicio;

    int sair;
    int opcao;

    while (sair == 0) {

        system("cls");

        cout << " \t\t OPCOES: \n\n";
        cout << " \t\t\t 1 - Realizar leitura de cidades \n\n";
        cout << " \t\t\t 2 - Realizar leitura de apresentador \n\n";
        cout << " \t\t\t 3 - Realizar leitura de eventos \n\n";
        cout << " \t\t\t 4 - Realizar leitura de participantes \n\n";
        cout << " \t\t\t 5 - Incluir apresentadores \n\n";
        cout << " \t\t\t 6 - Incluir participantes \n\n";
        cout << " \t\t\t 7 - Mostrar cidades \n\n ";
        cout << " \t\t\t 8 - Mostrar apresentador \n\n";
        cout << " \t\t\t 9 - Mostrar eventos \n\n";
        cout << " \t\t\t 10 - Mostrar participantes \n\n";
        cout << " \t\t\t 0 - Encerrar programa \n\n";
        cout << " \t\t ESCOLHA: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                system("cls");
                leituraCidades(CI, contadorCidade);
                break;
            }

            case 2: {
                system("cls");
                leituraApresentadores(AP, contadorApresentador);
                break;
            }

            case 3: {
                system("cls");
                leituraEventos(EV, contEvento, CI, AP, contadorCidade, contadorApresentador);
                break;
            }

            case 4: {
                system("cls");
                leituraParticipantes(PA,EV, contEvento, CI, AP, contadorParticipantes);
                break;
            }

            case 5: {
                system("cls");
                incluirApresentador(velhoAP, contApresentadorVelho, aguardandoAP, contApresentadorAguardando, atualAP,contApresentadorAtual);
                break;
            }

            case 6: {
                system("cls");
                incluirParticipantes(PA, contadorParticipantes,EV, contEvento,  CI,  contadorCidade,AP, contadorApresentador);
                break;
            }

            case 7: {
                system("cls");
                mostrarCidades(CI, contCID);
                getch();
                break;
            }

            case 8: {
                system("cls");
                mostrarApresentador(AP, contAPR);
                getch();
                break;
            }

            case 9: {
                system("cls");
                mostrarEvento(EV, contEVEN);
                getch();
                break;
            }

            case 10: {
                system("cls");
                mostrarParticipante(PA, contPART);
                getch();
                break;
            }
        }
    }
}
