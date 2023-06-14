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
        cout<<"____"<<endl;
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
        cout<<"____"<<endl;
        codAPencontrado = AP[m].codigoApresentador;
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
            cout<<"____"<<endl;
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
            cout<<"____"<<endl;
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
            cout<<"____"<<endl;

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
            cout<<"____"<<endl;

            contEvento = i+1;
        }
        else {
            cout<<"Eventos cadastrados..."<<endl;
            saida = 0;
        }
    }
    cout<<"Foram cadastrados (" << contEvento<< ") eventos."<<endl;
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
        cout<<"____"<<endl;
        codEventoEncontrado = EV[m].codigoEvento;

        return m;
    }else {
        return -1;
    }
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
                    cout<<"\n Evento nao encontrada informe um codigo valido! \n"<<endl;
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
void incluirApresentadores(struct apresentadores AP[], int &contApresentadores){
    system("cls");
    struct apresentadores inclusaoApresentadores[20];
    int contInclusaoApresentadores = 0;
    leituraApresentadores(AP, contApresentadores);

    struct apresentadores atApresentadores[20];

    int i = 0, j = 0, k = 0;
    for (; i < contApresentadores && j < contInclusaoApresentadores; k++){
        if (AP[i].codigoApresentador < inclusaoApresentadores[j].codigoApresentador){
            atApresentadores[k].codigoApresentador = AP[i].codigoApresentador;
            strcpy(atApresentadores[k].nomeApresentador, AP[i].nomeApresentador);
            i++;
        }
        else
        {
            atApresentadores[k].codigoApresentador = inclusaoApresentadores[j].codigoApresentador;
            strcpy(atApresentadores[k].nomeApresentador, inclusaoApresentadores[j].nomeApresentador);
            j++;
        }
    }

    while (i < contApresentadores){
        atApresentadores[k].codigoApresentador = AP[i].codigoApresentador;
        strcpy(atApresentadores[k].nomeApresentador, AP[i].nomeApresentador);
        i++;
        k++;
    }

    while (j < contInclusaoApresentadores){
        atApresentadores[k].codigoApresentador = inclusaoApresentadores[j].codigoApresentador;
        strcpy(atApresentadores[k].nomeApresentador, inclusaoApresentadores[j].nomeApresentador);
        j++;
        k++;
    }

    for (int i = 0; i < k; i++){
        AP[i].codigoApresentador = atApresentadores[i].codigoApresentador;
        strcpy(AP[i].nomeApresentador, atApresentadores[i].nomeApresentador);
    }

    contApresentadores = k;
}

void consultarEventos(struct eventos EV[], int contEvento, struct cidades CI[], int contCidade, struct apresentadores AP[], int contAprens){
    int codigoEvents, indiceEvento = 0, refMun = 0, refAprens = 0;

    cout<<"Digite o codigo evento que deseja consultar: ";
    cin>> codigoEvents;

    if(codigoEvents != 0){
        cout<< "Descricao do evento: ";
        indiceEvento = verificarEvento(EV, codigoEvents, contEvento, CI, AP);
        if(indiceEvento != -1){
            refMun = EV[indiceEvento].codCidade;
            cout<<"\nCidade do evento: ";
            verificarCidade(CI, refMun, contCidade );
            refAprens = EV[indiceEvento].codApresentador;
            cout<<"\nApresentador do evento: ";
            verificarApresentador(AP, refAprens, contAprens );
            cout << "\nValor total do evento: R$" << EV[indiceEvento].quantidadeParticipante * EV[indiceEvento].precoUnitario;
        } else {
            cout << "Evento nao encontrado!" << endl;
        }
    } else {
        cout << "Codigo invalido!" << endl;
    }
    getch();
}

void mostrarEventos(struct eventos EV[], int &contEvento, struct cidades CI[], int qtdeCidades, struct apresentadores AP[], int qtdeApresentadores){
    float total= 0;
    cout<<"Lista de todos os eventos atualizados: " <<endl;
    for(int i = 0; i < contEvento; i++){
        cout<<"\nCodigo do evento: "<<EV[i].codigoEvento;
        cout<<"\nDescricao do evento: "<<EV[i].descricaoEvento;
        cout<<"\nCodigo da cidade do evento: "<<EV[i].codCidade << " - ";
        verificarCidade(CI, EV[i].codCidade,qtdeCidades);
        cout<<"\nCodigo do apresentador do evento: "<<EV[i].codApresentador << " - ";
        verificarApresentador(AP, EV[i].codApresentador, qtdeApresentadores);
        cout<<"\nQuantidade de participantes: "<<EV[i].quantidadeParticipante;
        cout<<"\nQuantidade limites de participantes: "<<EV[i].limiteParticipante;
        cout<<"\nPreco do evento: R$"<<EV[i].precoUnitario;
        cout<<"\nValor do evento: R$"<<EV[i].quantidadeParticipante * EV[i].precoUnitario;
        cout<<"\n\n";
        total = total + (EV[i].quantidadeParticipante * EV[i].precoUnitario);
    }
    cout<<"Valor total de todos os eventos: R$" << total;
    getch();
}

void incluirEventos(struct eventos EV[], int &contEventos, int qtdCidade, int qtdApresentador, struct cidades CI[], struct apresentadores AP[]){

    struct eventos inclusaoEvento[20];
    int contInclusaoEvento = 0;
    leituraEventos(EV, contEventos, CI, AP, qtdCidade, qtdApresentador);

    struct eventos atEvento[20];

    int i = 0, k = 0, j = 0;
    for (; i < contEventos && j < contInclusaoEvento; k++)
    {
        if (EV[i].codigoEvento < inclusaoEvento[j].codigoEvento)
        {
            atEvento[k].codigoEvento = EV[i].codigoEvento;
            strcpy(atEvento[k].descricaoEvento, EV[i].descricaoEvento);
            atEvento[k].codCidade = EV[i].codCidade;
            atEvento[k].codApresentador = EV[i].codApresentador;
            atEvento[k].quantidadeParticipante = EV[i].quantidadeParticipante;
            atEvento[k].limiteParticipante = EV[i].limiteParticipante;
            atEvento[k].precoUnitario = EV[i].precoUnitario;
            i++;
        }
        else
        {
            atEvento[k].codigoEvento = inclusaoEvento[j].codigoEvento;
            strcpy(atEvento[k].descricaoEvento, inclusaoEvento[j].descricaoEvento);
            atEvento[k].codCidade = inclusaoEvento[j].codCidade;
            atEvento[k].codApresentador = inclusaoEvento[j].codApresentador;
            atEvento[k].quantidadeParticipante = inclusaoEvento[j].quantidadeParticipante;
            atEvento[k].limiteParticipante = inclusaoEvento[j].limiteParticipante;
            atEvento[k].precoUnitario = inclusaoEvento[j].precoUnitario;
            j++;
        }
    }

    while (i < contEventos)
    {
        atEvento[k].codigoEvento = EV[i].codigoEvento;
        strcpy(atEvento[k].descricaoEvento, EV[i].descricaoEvento);
        atEvento[k].codCidade = EV[i].codCidade;
        atEvento[k].codApresentador = EV[i].codApresentador;
        atEvento[k].quantidadeParticipante = EV[i].quantidadeParticipante;
        atEvento[k].limiteParticipante = EV[i].limiteParticipante;
        atEvento[k].precoUnitario = EV[i].precoUnitario;
        i++;
        k++;
    }

    while (j < contInclusaoEvento)
    {
        atEvento[k].codigoEvento = inclusaoEvento[j].codigoEvento;
        strcpy(atEvento[k].descricaoEvento, inclusaoEvento[j].descricaoEvento);
        atEvento[k].codCidade = inclusaoEvento[j].codCidade;
        atEvento[k].codApresentador = inclusaoEvento[j].codApresentador;
        atEvento[k].quantidadeParticipante = inclusaoEvento[j].quantidadeParticipante;
        atEvento[k].limiteParticipante = inclusaoEvento[j].limiteParticipante;
        atEvento[k].precoUnitario = inclusaoEvento[j].precoUnitario;
        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        EV[i].codigoEvento = atEvento[i].codigoEvento;
        strcpy(EV[i].descricaoEvento, atEvento[i].descricaoEvento);
        EV[i].codCidade = atEvento[i].codCidade;
        EV[i].codApresentador = atEvento[i].codApresentador;
        EV[i].quantidadeParticipante = atEvento[i].quantidadeParticipante;
        EV[i].limiteParticipante = atEvento[i].limiteParticipante;
        EV[i].precoUnitario = atEvento[i].precoUnitario;
    }

    contEventos = k;
}

int main(){

    struct apresentadores AP[20];
    int contadorApresentador;

    struct eventos EV[20];
    int contEvento;

    struct participantes P[20], A[20], R[40];
    struct participantes PA[20];
    int contadorParticipantes;
    int qtdeParticipantes ;

    struct cidades CI[20];
    int contadorCidade;
    int qtdeCidades ;
    struct cidades listaCidades[qtdeCidades];

    int sair;
    int opcao;

    while (sair == 0) {

        system("cls");

        cout << " \t\t OPCOES: \n\n";
        cout << " \t\t\t 1 - Realizar leitura de Cidades \n\n";
        cout << " \t\t\t 2 - Realizar leitura de Apresentador \n\n";
        cout << " \t\t\t 3 - Realizar leitura de Eventos \n\n";
        cout << " \t\t\t 4 - Realizar leitura de Participantes \n\n";
        cout << " \t\t\t 5 - Incluir Apresentadores \n\n";
        cout << " \t\t\t 6 - Incluir Participantes \n\n";
        cout << " \t\t\t 7 - Incluir Evento \n\n";
        cout << " \t\t\t 8 - Mostrar Eventos \n\n";
        cout << " \t\t\t 9 - Consultar Evento \n\n";
        cout << " \t\t\t 0 - Encerrar Programa \n\n";
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

            case 5:{
                system("cls");
                incluirApresentadores(AP, contadorApresentador);
                getch();
                break;
            }

            case 6: {
                system("cls");
                incluirParticipantes(PA, contadorParticipantes,EV, contEvento,  CI,  contadorCidade,AP, contadorApresentador);
                break;
            }

            case 7: {
                system("cls");
                incluirEventos(EV, contEvento, qtdeCidades, contadorApresentador, CI, AP);
                getch();
                break;
            }

            case 8: {
                system("cls");
                mostrarEventos(EV, contEvento, CI, qtdeCidades, AP, contadorApresentador);
                getch();
                break;
            }

            case 9: {
                system("cls");
                consultarEventos(EV, contEvento,CI, contadorCidade, AP, contadorApresentador);
                getch();
                break;
            }
            default:
            {
                cout << "Opcao invalida\n";
                break;
            }
        }
        system("pause");
    }
}