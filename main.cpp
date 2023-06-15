#include <iostream>
#include <conio.h>
#include <strings.h>
using namespace std;

// ESTRUTURAS //
struct cidades{
    int codigoCidade;
    char nomeCidade[30];
    char uf[3];
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

// VERIFICAÇÃO E LEITURA DE CIDADE //
int verificarCidade(struct cidades CI[], int codigoCidade, int contadorCidades){
    int i = 0, f = contadorCidades;
    int m = ( i + f ) / 2;
    int codigoCidadeEncontrado = 0;

    for(; f >= i && codigoCidade != CI[m].codigoCidade; m = ( i + f ) / 2 ){
        if ( codigoCidade > CI[m].codigoCidade )
            i = m + 1;
        else
            f = m - 1;
    }
    if ( codigoCidade == CI[m].codigoCidade ){
        cout << " \n Cidade Encontrada! ";
        cout << " \n Nome da Cidade: " << CI[m].nomeCidade << endl;
        cout << " \n Unidade Federativa: " << CI[i].uf << endl;
        cout << "---------------------------------------------------" << endl;
        codigoCidadeEncontrado = CI[m].codigoCidade;
        return m;
    }
    else {
        return -1;
    }
}
void leituraCidades(struct cidades CI[], int &contadorCidades){
    int saida = 1;
    int i = 0;

    for(; i < 20 && saida != 0; i++ ){
        cout << " \n Informe o codigo da Cidade: ";
        cin >> CI[i].codigoCidade;
        cin.ignore();
        if ( CI[i].codigoCidade > 0 ){
            cout << "\n Informe o nome da Cidade: ";
            gets(CI[i].nomeCidade);
            cout << "\n Informe a Unidade Federativa: ";
            gets(CI[i].uf);
            cout << "---------------------------------------------------" << endl;
        }
        else {
            saida = 0;
        }
    }
    contadorCidades = i -1;
    cout << " Foram cadastradas (" << contadorCidades << ") Cidades. " << endl;
}

// VERIFICAÇÃO E LEITURA DE APRESENTADOR //
int verificarApresentador(struct apresentadores AP[], int codigoApresentador, int contadorApresentadores){
    int i = 0, f = contadorApresentadores;
    int m = ( i + f ) / 2;
    int codigoApresentadorEncontrado = 0;

    for (; f >= i && codigoApresentador != AP[m].codigoApresentador; m = ( i + f ) / 2 ){
        if ( codigoApresentador > AP[m].codigoApresentador)
            i = m + 1;
        else
            f = m - 1;
    }
    if ( codigoApresentador == AP[m].codigoApresentador ){
        cout << "\n Apresentador Encontrado! ";
        cout << " \n Nome do Apresentador: " << AP[m].nomeApresentador << endl;
        cout << "---------------------------------------------------" << endl;
        codigoApresentadorEncontrado = AP[m].codigoApresentador;
        return m;
    }
    else {
        return -1;
    }
}
/*void leituraApresentadores(struct apresentadores AP[], int &contadorApresentadores){
    int i = 0;
    int saida = -1;

    for (; i < 20 && saida != 0; i++ ){
        cout << " \n Informe o codigo do Apresentador: ";
        cin >> AP[i].codigoApresentador;
        cin.ignore();
            if ( AP[i].codigoApresentador > 0 ){
                cout << " \n Informe o nome do apresentador: ";
                gets(AP[i].nomeApresentador);
                cout << "---------------------------------------------------" << endl;
            }
            else{
                cout << " \n Apresentadores Cadastrados.  " << endl;
                saida = 0;
            }
    }
    contadorApresentadores = i - 1;
    cout << " Foram cadastrados (" << contadorApresentadores << ") Apresentadores. ";
}*/

void leituraApresentadores(struct apresentadores AP[], int &contadorApresentadores) {
    int i = 0;
    int saida = -1;
    int contador = contadorApresentadores;

    for (; i < 20 && saida != 0; i++) {
        cout << "\nInforme o codigo do Apresentador: ";
        cin >> AP[contador].codigoApresentador;
        cin.ignore();

        if (AP[contador].codigoApresentador > 0) {
            cout << "\nInforme o nome do apresentador: ";
            gets(AP[contador].nomeApresentador);
            cout << "---------------------------------------------------" << endl;
            contador++;
        } else {
            cout << "\nApresentadores Cadastrados." << endl;
            saida = 0;
        }

    }
    contadorApresentadores = contador + 1 - 1;
    cout << "Foram cadastrados (" << contadorApresentadores << ") Apresentadores." << endl;
}

// VERIFICAÇÃO E LEITURA DE EVENTO //
int verificarEvento(struct eventos EV[], int codigoEvento, int contadorEventos, struct cidades CI[], struct apresentadores AP[]) {
    int i = 0, f = contadorEventos;
    int m = (i + f) / 2;
    int codigoEventoEncontrado = 0;
    for (; f >= i && codigoEvento != EV[m].codigoEvento; m = ( i + f ) / 2) {
        if ( codigoEvento > EV[m].codigoEvento )
            i = m + 1;
        else
            f = m - 1;
    }
    if( codigoEvento == EV[m].codigoEvento ){
        cout <<"---------------Evento encontrado---------------" << endl;
        cout << " \n Descricao do Evento: " << EV[m].descricaoEvento << endl;
        cout << " Cidade do Evento " << CI[m].nomeCidade << endl;
        cout << " Apresentador do Evento: " << AP[m].nomeApresentador << endl;
        cout << "---------------------------------------------------" << endl;
        codigoEventoEncontrado = EV[m].codigoEvento;

        return m;
    }
    else {
        return -1;
    }
}
void leituraEventos(struct eventos EV[], int &contadorEventos, struct cidades CI[], int &contadorCidades, struct apresentadores AP[], int &contadorApresentadores){
    int i = 0;
    int x = 1;
    int y = 1;
    int saida = 1;
    int cidadeEncontrada;
    int apresentadorEncontrado;

    for(; i < 20 && saida != 0; i++ ){
        cout << " Informe o codigo do Evento: ";
        cin >> EV[i].codigoEvento;
        cin.ignore();
        if( EV[i].codigoEvento > 0 ){
            cout << " Informe a Descricao do Evento: ";
            gets(EV[i].descricaoEvento);
            cout << "---------------------------------------------------" << endl;

            x = 1;

            while( x != 0 ){
                cout << " Informe o codigo da Cidade para o Evento: ";
                cin >> EV[i].codCidade;
                cin.ignore();

                cidadeEncontrada = verificarCidade(CI, EV[i].codCidade, contadorCidades);
                if( cidadeEncontrada != -1 ){
                    x = 0;
                }
                else {
                    cout << " \n Cidade nao encontrada, informe um codigo valido! \n " << endl;
                }
            }

            y = 1;

            while ( y != 0 ){
                cout << " Informe o codigo do Apresentador para o Evento: ";
                cin >> EV[i].codApresentador;
                cin.ignore();

                apresentadorEncontrado = verificarApresentador(AP, EV[i].codApresentador, contadorApresentadores);
                if ( apresentadorEncontrado != -1 ){
                    y = 0;
                }
                else {
                    cout << " \n Apresentador nao encontrado, informe um codigo valido! \n" << endl;
                }
            }

            cout << " \n Informe qual sera o limite de Participantes: ";
            cin >> EV[i].limiteParticipante;
            cin.ignore();

            cout << " \n Informe a quantidade de Participantes: ";
            cin >> EV[i].quantidadeParticipante;
            cin.ignore();

            while ( EV[i].quantidadeParticipante > EV[i].limiteParticipante ){
                cout << " \n Limite de Participantes Ultrapassado! " << endl;
                cout << " \n Informe um novo valor menor que (" << EV[i].limiteParticipante << ") : ";
                cin >> EV[i].quantidadeParticipante;
                cin.ignore();
            }

            cout << " \n Informe qual o valor para entrada deste evento: ";
            cin >> EV[i].precoUnitario;
            cin.ignore();
            cout << "---------------------------------------------------" << endl;

            contadorEventos = i + 1;
        }
        else {
            cout << " Eventos Cadastrados. " << endl;
            saida = 0;
        }
    }

    cout << " Foram cadastrados (" << contadorEventos << ") Eventos. " << endl;
}

// VERIFICAÇÂO E LEITURA DE PARTICIPANTE //
int verificarParticipante(struct participantes PA[], int codigoParticipante, int contadorParticipantes){
    int i = 0, f = contadorParticipantes;
    int m = ( i + f ) / 2;
    for(; f >= i && codigoParticipante != PA[m].codigoParticipante; m = ( i + f) / 2) {
        if (codigoParticipante > PA[m].codigoParticipante)
            i = m + 1;
        else
            f = m - 1;
    }
    if( codigoParticipante == PA[m].codigoParticipante ){
        cout << PA[m].codigoParticipante;
        return m;
    }
    else
        return - 1;
}
/*void leituraParticipantes(struct participantes PA[],struct eventos EV[], int contEvento, struct cidades CI[], struct apresentadores AP[], int &contadorParticipantes){
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

        }else{
            saida=0;
        }
        contadorParticipantes = i + 1 - 1;
    }
    cout<<"Foram cadastrados (" << contadorParticipantes<< ") participantes"<<endl;
} */
void leituraParticipantes(struct participantes PA[], struct eventos EV[], int contEvento, struct cidades CI[], struct apresentadores AP[], int &contadorParticipantes) {
    int i = 0;
    int saida = 1;
    int eventoEncontrado;
    int x = 0;
    int verificadorCodEvento;
    int contador = contadorParticipantes;

    for (; i < 20 && saida != 0; i++) {
        cout << "Digite o codigo do participante: ";
        cin >> PA[contador].codigoParticipante;
        cin.ignore();

        if (PA[contador].codigoParticipante > 0) {
            cout << "Informe o nome do participante: ";
            gets(PA[contador].nomeParticipante);

            x = 1;
            contador++;
        } else {
            saida = 0;
        }
    }
    contadorParticipantes = contador + 1 - 1;
    cout << "Foram cadastrados (" << contadorParticipantes << ") participantes" << endl;
}


// INCLUSÔES //
void incluirApresentadores(struct apresentadores AP[], int &contadorApresentadores){
    struct apresentadores inclusaoApresentadores[20];
    int contadorInclusaoApresentadores = 0;
    leituraApresentadores(AP, contadorApresentadores);
    struct apresentadores apresentadoresAtualizado[20];

    int i = 0;
    int j = 0, k = 0;
    for(; i < contadorApresentadores && j < contadorInclusaoApresentadores; k++){
        if (AP[i].codigoApresentador < inclusaoApresentadores[j].codigoApresentador){
            apresentadoresAtualizado[k].codigoApresentador = AP[i].codigoApresentador;
            strcpy(apresentadoresAtualizado[k].nomeApresentador, AP[i].nomeApresentador);
            i++;
        }
        else
        {
            apresentadoresAtualizado[k].codigoApresentador = inclusaoApresentadores[j].codigoApresentador;
            strcpy(apresentadoresAtualizado[k].nomeApresentador, inclusaoApresentadores[j].nomeApresentador);
            j++;
        }
    }

    while (i < contadorApresentadores){
        apresentadoresAtualizado[k].codigoApresentador = AP[i].codigoApresentador;
        strcpy(apresentadoresAtualizado[k].nomeApresentador, AP[i].nomeApresentador);
        i++;
        k++;
    }

    while (j < contadorInclusaoApresentadores){
        apresentadoresAtualizado[k].codigoApresentador = inclusaoApresentadores[j].codigoApresentador;
        strcpy(apresentadoresAtualizado[k].nomeApresentador, inclusaoApresentadores[j].nomeApresentador);
        j++;
        k++;
    }

    for (int i = 0; i < k; i++){
        AP[i].codigoApresentador = apresentadoresAtualizado[i].codigoApresentador;
        strcpy(AP[i].nomeApresentador, apresentadoresAtualizado[i].nomeApresentador);
    }

    contadorApresentadores = k;
}
void incluirEventos(struct eventos EV[], int &contadorEventos, int quantidadeCidades, int quantidadeApresentadores, struct  cidades CI[], struct apresentadores AP[]){
    struct eventos inclusaoEventos[20];
    int contadorInclusaoEvento = 0;
    leituraEventos(EV, contadorEventos, CI, quantidadeCidades, AP, quantidadeApresentadores);
    struct eventos eventosAtualizado[20];

    int i = 0;
    int k = 0, j = 0;
    for (; i < contadorEventos && j < contadorInclusaoEvento; k++)
    {
        if (EV[i].codigoEvento < inclusaoEventos[j].codigoEvento)
        {
            eventosAtualizado[k].codigoEvento = EV[i].codigoEvento;
            strcpy(eventosAtualizado[k].descricaoEvento, EV[i].descricaoEvento);
            eventosAtualizado[k].codCidade = EV[i].codCidade;
            eventosAtualizado[k].codApresentador = EV[i].codApresentador;
            eventosAtualizado[k].quantidadeParticipante = EV[i].quantidadeParticipante;
            eventosAtualizado[k].limiteParticipante = EV[i].limiteParticipante;
            eventosAtualizado[k].precoUnitario = EV[i].precoUnitario;
            i++;
        }
        else
        {
            eventosAtualizado[k].codigoEvento = inclusaoEventos[j].codigoEvento;
            strcpy(eventosAtualizado[k].descricaoEvento, inclusaoEventos[j].descricaoEvento);
            eventosAtualizado[k].codCidade = inclusaoEventos[j].codCidade;
            eventosAtualizado[k].codApresentador = inclusaoEventos[j].codApresentador;
            eventosAtualizado[k].quantidadeParticipante = inclusaoEventos[j].quantidadeParticipante;
            eventosAtualizado[k].limiteParticipante = inclusaoEventos[j].limiteParticipante;
            eventosAtualizado[k].precoUnitario = inclusaoEventos[j].precoUnitario;
            j++;
        }
    }

    while (i < contadorEventos)
    {
        eventosAtualizado[k].codigoEvento = EV[i].codigoEvento;
        strcpy(eventosAtualizado[k].descricaoEvento, EV[i].descricaoEvento);
        eventosAtualizado[k].codCidade = EV[i].codCidade;
        eventosAtualizado[k].codApresentador = EV[i].codApresentador;
        eventosAtualizado[k].quantidadeParticipante = EV[i].quantidadeParticipante;
        eventosAtualizado[k].limiteParticipante = EV[i].limiteParticipante;
        eventosAtualizado[k].precoUnitario = EV[i].precoUnitario;
        i++;
        k++;
    }

    while (j < contadorInclusaoEvento)
    {
        eventosAtualizado[k].codigoEvento = inclusaoEventos[j].codigoEvento;
        strcpy(eventosAtualizado[k].descricaoEvento, inclusaoEventos[j].descricaoEvento);
        eventosAtualizado[k].codCidade = inclusaoEventos[j].codCidade;
        eventosAtualizado[k].codApresentador = inclusaoEventos[j].codApresentador;
        eventosAtualizado[k].quantidadeParticipante = inclusaoEventos[j].quantidadeParticipante;
        eventosAtualizado[k].limiteParticipante = inclusaoEventos[j].limiteParticipante;
        eventosAtualizado[k].precoUnitario = inclusaoEventos[j].precoUnitario;
        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        EV[i].codigoEvento = eventosAtualizado[i].codigoEvento;
        strcpy(EV[i].descricaoEvento, eventosAtualizado[i].descricaoEvento);
        EV[i].codCidade = eventosAtualizado[i].codCidade;
        EV[i].codApresentador = eventosAtualizado[i].codApresentador;
        EV[i].quantidadeParticipante = eventosAtualizado[i].quantidadeParticipante;
        EV[i].limiteParticipante = eventosAtualizado[i].limiteParticipante;
        EV[i].precoUnitario = eventosAtualizado[i].precoUnitario;
    }

    contadorEventos = k;
}
void inscreverParticipantes(struct participantes PA[], int &contadorParticipantes, struct eventos EV[], int contEventos, struct cidades CI[],
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
                    participanteEncontrado =  verificarParticipante(PA, contadorParticipantes, codParticipante);
                    PA[participanteEncontrado].codigoEvento = codEvento;
                    EV[eventoEncontrado].quantidadeParticipante++;
                    cout<<"\n Participante inscrito! ";
                }
            } else {
                cout <<"O evento escolhido nao possui vagas para novas inscricoes";
            }
            cout << "Quantidade de participantes: " << EV[eventoEncontrado].quantidadeParticipante << endl;
            cout << "Limite de participantes: " << EV[eventoEncontrado].limiteParticipante << endl;
        } else {
            cout << "Evento nao encontrado!" << endl;
        }
    }
    contadorParticipantes ++;
    getch();
}

// FUNÇÕES PARA MOSTRAR //
void consultarEventos(struct eventos EV[], int contadorEventos, struct cidades CI[], int contadorCidades, struct apresentadores AP[], int contadorApresentadores){
    int codigoConsultaEvento;
    int indiceEvento = 0;
    int referenciaCidade = 0;
    int referenciaApresentador = 0;

    cout << " Informe o codigo do Evento que deseja consultar: ";
    cin >> codigoConsultaEvento;

    if( codigoConsultaEvento != 0 ){
        cout << " Descricacao do Evento: ";
        indiceEvento = verificarEvento(EV, codigoConsultaEvento, contadorEventos, CI, AP);
        if( indiceEvento != -1 ){
            referenciaCidade = EV[indiceEvento].codCidade;
            cout << " \n Cidade do Evento: ";
            verificarCidade(CI, referenciaCidade, contadorCidades);
            referenciaApresentador = EV[indiceEvento].codApresentador;
            cout << " \n Apresentador do Evento: ";
            verificarApresentador(AP, referenciaApresentador, contadorApresentadores);
            cout << " \n Valor total do evento: R$ " << EV[indiceEvento].quantidadeParticipante * EV[indiceEvento].precoUnitario;
        }
        else {
            cout << " Evento nao encontrado! " << endl;
        }
    } else {
        cout << " Codigo invalido! " << endl;
    }
    getch();
}
void mostrarEventos(struct eventos EV[], int contEvento, struct cidades CI[], int qtdeCidades, struct apresentadores AP[], int qtdeApresentadores){
    float total= 0;

    if( contEvento == 0 ){
        cout << "\n Lista Vazia! " << endl;
    }else {

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
}

//FUNÇÕES DE EXIBIÇÃO //
  void exibirCidades(struct cidades CI[], int contadorCidades){
    cout << "\t\tIMPRIMINDO CIDADES\n\n";
    for (int i = 0; i < contadorCidades; i++)
    {
        cout << "ID: " << CI[i].codigoCidade << endl;
        cout << "Nome: " << CI[i].nomeCidade << endl;
        cout << "UF: " << CI[i].uf << endl;
        cout << "============================================\n";
    }
}
void exibirApresentadores(struct apresentadores AP[], int contadorApresentadores){
    cout << "\t\tIMPRIMINDO APRESENTADORES\n\n";
    for (int i = 0; i < contadorApresentadores; i++)
    {
        cout << " Codigo do Apresentador: " << AP[i].codigoApresentador << endl;
        cout << " Nome do Apresentador: " << AP[i].nomeApresentador << endl;
        cout << "============================================\n";
    }
}
void exibirParticipantes(struct participantes PA[], int contadorParticipantes){
    cout << "\t\tIMPRIMINDO PARTICIPANTES\n\n";
    for (int i = 0; i < contadorParticipantes; i++)
    {
        cout << " Codigo do Participante: " << PA[i].codigoParticipante << endl;
        cout << " Nome do Participante: " << PA[i].nomeParticipante << endl;
        cout << "============================================\n";
    }
}

// MAIN //
int main(){

    // CIDADE //
    struct cidades CI[20];
    int contadorCidades = 0;
    int quantidadeCidades = 0;

    // APRESENTADOR //
    struct apresentadores AP[20];
    int contadorApresentadores = 0;

    // EVENTO //
    struct eventos EV[20];
    int contadorEventos = 0;

    // PARTICIPANTE //
    struct participantes PA[20];
    int contadorParticipantes = 0;

    int sair;
    int opcao;

    while ( sair == 0 ){

        system("cls");

        cout << " \t\t OPCOES: \n\n ";
        cout << " \t\t\t 1 - Realizar leitura de Cidades \n\n";
        cout << " \t\t\t 2 - Realizar leitura de Apresentador \n\n";
        cout << " \t\t\t 3 - Realizar leitura de Eventos \n\n";
        cout << " \t\t\t 4 - Realizar leitura de Participantes \n\n";
        cout << " \t\t\t 5 - Incluir Apresentadores \n\n";
        cout << " \t\t\t 6 - Incluir Evento \n\n";
        cout << " \t\t\t 7 - Inscrever Participantes \n\n";
        cout << " \t\t\t 8 - Mostrar Eventos \n\n";
        cout << " \t\t\t 9 - Consultar Evento \n\n";
        cout << " \t\t\t 10 - Exibir Cidadade \n\n";
        cout << " \t\t\t 11 - Exibir Apresentador \n\n";
        cout << " \t\t\t 12 - Exibir Participantes \n\n";
        cout << " \t\t\t 0 - Encerrar Programa \n\n";
        cout << " \t\t ESCOLHA: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {
                system("cls");
                leituraCidades(CI, contadorCidades);
                getch();
                break;
            }

            case 2: {
                system("cls");
                leituraApresentadores(AP, contadorApresentadores);
                getch();
                break;
            }

            case 3: {
                system("cls");
                leituraEventos(EV, contadorEventos, CI, contadorCidades, AP, contadorApresentadores);
                getch();
                break;
            }

            case 4: {
                system("cls");
                leituraParticipantes(PA, EV, contadorEventos, CI, AP, contadorParticipantes);
                getch();
                break;
            }

            case 5: {
                system("cls");
                incluirApresentadores(AP, contadorApresentadores);
                getch();
                break;
            }

            case 7: {
                system("cls");
                inscreverParticipantes(PA, contadorParticipantes, EV, contadorEventos, CI, contadorCidades, AP, contadorApresentadores);
                getch();
                break;
            }

            case 6: {
                system("cls");
                incluirEventos(EV, contadorEventos, quantidadeCidades, contadorApresentadores, CI, AP);
                getch();
                break;
            }

            case 8: {
                system("cls");
                mostrarEventos(EV, contadorEventos, CI, quantidadeCidades, AP, contadorApresentadores);
                getch();
                break;
            }

            case 9: {
                system("cls");
                consultarEventos(EV, contadorEventos, CI, contadorCidades, AP, contadorApresentadores);
                getch();
                break;
            }

            case 10: {
                system("cls");
                exibirCidades(CI, contadorCidades);
                getch();
                break;
            }

            case 11: {
                system("cls");
                exibirApresentadores(AP, contadorApresentadores);
                getch();
                break;
            }

            case 12: {
                system("cls");
                exibirParticipantes(PA, contadorParticipantes);
                getch();
                break;
            }

            case 0: {
                system("cls");
                char Encerrar = 'N';
                cout<<"\n\nDeseja encerrar o programa? (S/N) : ";
                sair = toupper(getche());
                if(Encerrar=='S'){
                    cout<<"\n\nSaindo do programa...";

                }
                getch();
                break;
            }
        }
    }
}
