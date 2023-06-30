#include <stdio.h>
#include <utility>
#include <vector>
#include <cmath>
#include <stdlib.h>     
#include <time.h>
#include <unistd.h>
using namespace std;

enum estado_sensor {INACESSIVEL, ACESSIVEL, ACESSIVEL_INF};
enum categoria_posicao {NAO_VISITADA, ORDINARIA, SAIDA, OBSTRUCAO, RAMIFICACAO};
enum estado_flag {DESATIVADO, ATIVADO};
enum sensor {FRONTAL, ESQUERDA, DIREITA};
enum modo {OBSTRUCAO_UNICA, OBSTRUCAO_MULTIPLA, SAIDA_UNICA, SAIDA_MULTIPLA};


//Modo configurado
enum modo modo;


//Declaração das flags
enum estado_flag flag_retorno;
enum estado_flag flag_nova_posicao;
enum estado_flag flag_requisicao_externa;

//Variáveis dos estados de cada um dos sensores
enum estado_sensor estado_sensores[3]; //0: frontal; 1: esquerda; 2: direita

//Declaração das variáveis de navegação
enum categoria_posicao mapa[250][250]; //Matriz que representa o labirinto
vector<pair<int,int>> historico; //Lista de posições visitadas ao longo do mapeamento

pair<int,int> posicao_atual; //Posição atual na matriz (em coordenadas)

float dist_frontal_cur;   //Distância frontal atual
float dist_frontal_ref;   //Distância frontal de referência

//Variáveis auxiliares para a rotação do vetor frontal
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int direcao_frontal; //Vetor direção frontal (dx[],dy[])
 



//FUNÇÕES AUXILIARES

//Controles associados ao motor
//A. Função que rotaciona o carrinho de 90° no sentido horário
void rot_hor(){
    //Operação de controle do carrinho
    direcao_frontal = (direcao_frontal + 1)%4; //Atualiza a nova direção frontal
}

//B. Função que rotaciona o carrinho de 90° no sentido anti-horário
void rot_anti(){
    //Operação de controle do carrinho
    direcao_frontal = (direcao_frontal - 1)%4; //Atualiza a nova direção frontal
}

//C. Função de parar o motor
void interrompe_motor(){
}

//D. Função de religar o motor
void reativa_motor(){
}


//Funções associadas aos sensores
//A. Função que retorna o tempo que leva para o sinal sonoro de dado sensor ir e voltar
float pulso(enum sensor sensor){
    return 1;
}

//B. Função para obter a distância em centimetros captada por um dos 3 sensores, dado pela entrada "sensor"
//(Uso de uma estimativa usando a velocidade do som como 343 m/s)
float dist_sensor(enum sensor sensor){
    float dist = (34300*pulso(sensor))/2;
    return dist;
}

//C. Função classifica sensor
enum estado_sensor classifica_sensor(enum sensor sensor){
    float dist = dist_sensor(sensor);
    if(dist < 10) return INACESSIVEL;
    if(dist > 200) return ACESSIVEL_INF;
    return ACESSIVEL;
}


//Funções associadas à comunicação com o controlador externo
//A. Função que verifica se houve recepção de sinal do transmissor forçando o retorno
// (true: houve requisição; false: não houve requisição)
bool verifica_requisicao_transmissor(){
    return false;
}

//B. Função de enviar sinal de socorro pelo transmissor
void envia_sinal_socorro(){

}


//Funções associadas ao estado do sistema
//A. Função que causa o desligamento de todo o sistema
void shut_down(){

}

//B. Função que informa o nível de bateria atual em porcentagem
int nivel_bateria(){
    return 1;
}

//C. Função que verifica o modo configurado pelos switches
enum modo verifica_modo(){
    return OBSTRUCAO_UNICA;
}



//EVENTOS NÃO PERIÓDICOS

//2-3. Verificação de bateria e Requisição de retorno
void precisa_voltar(){
    int bat = nivel_bateria();
    if(bat < 10 || flag_requisicao_externa == ATIVADO){
        if(flag_requisicao_externa == ATIVADO) flag_requisicao_externa == DESATIVADO;
        rot_hor();
        rot_hor();
        flag_retorno = ATIVADO;
    }
}


//4. Verificar a distância do ponto inicial
void limite(){
    int d = pow(posicao_atual.first,2) + pow(posicao_atual.second,2);
    //Verifica se saiu do limite do raio de atuação e dá meia-volta caso positivo
    if(d > 10000){
        rot_hor();
        rot_hor();
    }
}


//6. Encontrou ramificação
void encontrou_ramificacao(){
    mapa[posicao_atual.first][posicao_atual.second] = RAMIFICACAO;
    int acessivel[3]; //1: é acessível; 0: inacessível
    int visitado[3];  //1: já visitado; 0: ainda não visitado
   
    int cur_x = posicao_atual.first;
    int cur_y = posicao_atual.second;
    int direcao_esquerda = (direcao_frontal + 1) % 4;
    int direcao_direita = (direcao_frontal - 1) % 4;
    int next_x[3], next_y[3];
    //Coordenadas da posição frontal
    next_x[0] = cur_x + dx[direcao_frontal];
    next_y[0] = cur_y + dy[direcao_frontal];
    //Coordendas da posição à esquerda
    next_x[1] = cur_x + dx[direcao_esquerda];
    next_y[1] = cur_y + dy[direcao_esquerda];
    //Coordenadas da posição à direita
    next_x[2] = cur_x + dx[direcao_direita];
    next_y[2] = cur_y + dy[direcao_direita];
    
    //Classificar as 3 direções como acesíveis ou não e visitadas ou não
     for(int i=0; i<3; i++){
        acessivel[i] = 0;
        visitado[i] = 0;
        if(estado_sensores[i] != INACESSIVEL){
            acessivel[i] = 1;
            if(mapa[next_x[i]][next_y[i]] != NAO_VISITADA) visitado[i] = 1;
        } 
     }

    //Determinar qual caminho seguir
    int next_step = -1;
    if(flag_retorno == ATIVADO){
        //Verificar a lista para escolher o caminho mais antigo
        for(int i=0;i++;i<historico.size()){
            for(int j=0;j++;j<2){
                if(acessivel[j] == 0) continue;
                if(make_pair(next_x[j], next_y[j]) == historico[i]){
                    next_step = j;
                    break;
                }
            }
            if(next_step != -1) break;
        }
    }
    else{
        //Verifica quais caminhos estão acessíveis e não foram visitados
        int disponivel[3];
        for(int i=0;i++;i<3){
            disponivel[i] = 0;
            if(acessivel[i] == 1 && visitado[i] == 0) disponivel[i] = 1;
        }
        //Se todos os caminhos acessíveis já foram visitados, escolhe um aleatório dentre os acessíveis
        if(disponivel[0] + disponivel[1] + disponivel[2] == 0){
            //Escolhe um caminho aleatório e verifica se ele está acessível
            //Caso o caminho escolhido não esteja acessível, repete o processo
            while(true){
                srand (time(NULL));
                int rand_sensor = rand() % 3;
                if(acessivel[rand_sensor] == 1){
                    next_step = rand_sensor;
                    break;
                }
            }
        }
        //Em condições normais, escolhe um caminho disponível com prioridade frente > esquerda > direita
        else{
            for(int i=0;i<3;i++){
                if(disponivel[i] == 1){
                    next_step = i;
                    break;
                }
            }
        }
    }

    //Tendo a direção a se seguir, basta alterar a direção do carrinho
    switch (next_step){
        case 1: rot_hor(); break; //Caso a escolha seja esquerda, vire no sentido horário
        case 2: rot_anti(); break; //Caso a escolha seja direita, vire no sentido anti-horário
    }
    //Caso a escolha seja para frente, não precisa girar
}


//7. Encontrou obstrução
void encontrou_obstrucao(){
    mapa[posicao_atual.first][posicao_atual.second] = OBSTRUCAO;
    rot_hor();
    rot_hor();
    if(modo == OBSTRUCAO_UNICA) flag_retorno = ATIVADO;
}

//8. Encontrou saída
void encontrou_saida(){
    mapa[posicao_atual.first][posicao_atual.second] = SAIDA;
    rot_hor();
    rot_hor();
    if(modo == SAIDA_UNICA) flag_retorno = ATIVADO;
}


//5. Navegação
void navegacao(){
    if(estado_sensores[2] == INACESSIVEL &&
       estado_sensores[1] == INACESSIVEL && 
       estado_sensores[0] == INACESSIVEL){
        encontrou_obstrucao();
        return;
    }
    if(estado_sensores[2] == ACESSIVEL_INF &&
        estado_sensores[1] == ACESSIVEL_INF && 
        estado_sensores[0] == ACESSIVEL_INF){
        encontrou_saida();
        return;
    }

    int inacessiveis=0;
    for(int i=0;i++;i<3){
        if(estado_sensores[i] == INACESSIVEL) inacessiveis++;
    }
    //Ramificação caracterizada por 2 ou mais caminhos livres (1 ou 0 caminhos inacessíveis)
    if(inacessiveis <= 1){
        encontrou_ramificacao();
        return;
    }

    //Se não caiu em nenhuma das anteriores, o ponto é ordinário
    mapa[posicao_atual.first][posicao_atual.second] = ORDINARIA;

    //Caso o caminho a seguir é para frente
    if(estado_sensores[0] != INACESSIVEL) return;
    //Caso o caminho a seguir é para a esquerda
    if(estado_sensores[1] != INACESSIVEL){
        rot_hor();
        return;
    }
    //Caso o caminho a seguir é para a direita
    if(estado_sensores[2] != INACESSIVEL){
        rot_anti();
        return;
    }
}


//1. Mapeamento
void mapeamento(){
    historico.push_back(posicao_atual); //Adiciona a posição arual na lista
    if(posicao_atual == make_pair(125,125)){
        shut_down();
        return;
    }
    limite();
    precisa_voltar();
    estado_sensores[0] = classifica_sensor(FRONTAL);
    estado_sensores[1] = classifica_sensor(ESQUERDA);
    estado_sensores[2] = classifica_sensor(DIREITA);
    navegacao();
    reativa_motor();
}


//EVENTOS PERIÓDICOS

//1. Verificar distância frontal
void verifica_dist_frontal(){
    dist_frontal_cur = dist_sensor(FRONTAL);
    if(dist_frontal_cur - dist_frontal_ref < 10) return;

    dist_frontal_ref = dist_frontal_cur;
    //Atualiza posição atual
    posicao_atual.first += dx[direcao_frontal];
    posicao_atual.second += dy[direcao_frontal];
    interrompe_motor();
    flag_nova_posicao = ATIVADO;
    mapeamento();
}

//2. Verificar status da locomoção
void verifica_status_locomocao(){
    if(flag_nova_posicao = ATIVADO){
        flag_nova_posicao = DESATIVADO;
        return;
    }
    envia_sinal_socorro();
    shut_down();
}


int main(){
    //Inicialização
    modo = verifica_modo();
    posicao_atual = make_pair(125,125);
    dist_frontal_ref = dist_sensor(FRONTAL);
    while(true){
        for(int i=0; i++; i<15){
            //A cada 1s confere a distância frontal e verifica se houve requisição externa
            sleep(1);
            verifica_dist_frontal();
            if(verifica_requisicao_transmissor()) flag_requisicao_externa = ATIVADO;
        }
        //a cada 15s confere se está se mexendo ainda
        verifica_status_locomocao();
    }

    return 0;
}