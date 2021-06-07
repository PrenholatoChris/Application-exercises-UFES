#include <stdio.h>
#include <stdlib.h>

#define n_forn 70
#define n_prod 100

typedef struct enderecos{
    char rua[20];
    int numero;
    char comple[20];
    char bairro[20];
    char cidade[30];
    char estado[20];
} end;

typedef struct fornecedores{
    int codigo;
    char nome[30];
    char cpf_cnpj[20];
    end endereco;
    int ddd;
    char telefone[20];
} forn;

typedef struct produtos{
    int cod; //código do produto
    char nome[20];
    char desc[80];
    int codigo; //referente ao fornecedor
    float preco;
    int estoq_at;
    int estoq_min;
} prod;

void ler_dados(forn fornecedor[], prod produto[], int *qtdf, int *qtdp);//0 //NÃO
void cadastro_forn(forn fornecedor[], int *qtdf); //1   //NÃO
void alterar_forn(forn fornecedor[], int qtdf); //2    
void cadastro_prod(prod produto[], forn fornecedor[], int *qtdf, int *qtdp); //3 //NÃO
void alterar_prod(prod produto[],int qtdp); //4
void entrada_estoque(prod produto[], int qtdp); //5
void realizar_venda(prod produto[], int qtdp); //6
void relatorio_estoque_min(prod produto[], forn fornecedor[], int qtdp, int qtdf); //7
void salvar_dados(forn fornecedor[], prod produto[], int qtdf, int qtdp); //8
int pesquisa_vetor(prod produto[], int qtdp, int cod_pes); // extra

int main(){
    int qtdf=0, qtdp=0;
    prod produto[n_prod];
    forn fornecedor[n_forn];
    
    // txt leitura
    ler_dados(fornecedor, produto, &qtdf, &qtdp);

    //escolha do usuario
    int menu;
    while (menu != 9){
        system("cls");
        printf("-------------------------------\n");
        printf("|1 - Cadastrar Fornecedor     |\n");
        printf("|2 - Alterar Fornecedor       |\n");
        printf("|3 - Cadastrar Produtos       |\n");
        printf("|4 - Alterar Produtos         |\n");
        printf("|5 - Entrada de Estoque       |\n");
        printf("|6 - Realizar Venda           |\n");
        printf("|7 - Relatorio Estoque Minimo |\n");
        printf("|8 - Gravar dados             |\n");
        printf("|9 - Sair                     |\n");
        printf("-------------------------------\n");
        printf("\n");
        scanf("%d", &menu);
        switch(menu){
        case 1:
            // cadastro fornecedor
            cadastro_forn(fornecedor, &qtdf);
            break;
            
        case 2:
            // alterar fornecedor
            alterar_forn(fornecedor, qtdf);
            break;

        case 3:
            // cadastrar produtos
            cadastro_prod(produto, fornecedor, &qtdf, &qtdp);
            break;

        case 4:
            // alterar produtos
            alterar_prod(produto, qtdp);
            break;

        case 5:
            // entrada de estoque
            entrada_estoque(produto, qtdp);
            break;

        case 6:
            // realizar venda
            realizar_venda(produto, qtdp);
            break;

        case 7:
            // relatorio de estoque minimo
            relatorio_estoque_min(produto, fornecedor, qtdp, qtdf);
            break;

        case 8:
            // gravar dados
            salvar_dados(fornecedor, produto, qtdf, qtdp);
            break;

        case 9:
            // sair do progama
            system("cls");
            printf("Obrigado por usar o programa\n");
            break;
            

        default:
            printf("nao temos essa opcao!!!\n");
            break;
        }
    }
    return 0;
}

// leitura do fornecedor 0
void ler_dados(forn fornecedor[], prod produto[], int *qtdf, int *qtdp){
    char lixo[5];
    
    // fornecedor
    FILE *arqf;
    arqf = fopen("forn.txt","r+");
    if(arqf == NULL){
        printf("Nao existe banco de dados de fornecedores\n");
    }
    
    // produto
    FILE *arqp;
    arqp = fopen("prod.txt","r+");
    if(arqp == NULL){
        printf("Nao existe banco de dados de produto\n");
    }
    
    // fornecedor 
    fscanf(arqf, "%d", qtdf);
    fscanf(arqf,"%s", lixo);
    while(!feof(arqf)){
        for(int i=0; i < *qtdf; i++){
            fscanf(arqf, "%d", &fornecedor[i].codigo);
            fscanf(arqf, " %[^\n]", fornecedor[i].nome);
            fscanf(arqf, "%s", fornecedor[i].cpf_cnpj);
            fscanf(arqf, " %[^\n]", fornecedor[i].endereco.rua);
            fscanf(arqf, "%d", &fornecedor[i].endereco.numero);
            fscanf(arqf, " %[^\n]", fornecedor[i].endereco.comple);
            fscanf(arqf, " %[^\n]", fornecedor[i].endereco.bairro);
            fscanf(arqf, " %[^\n]", fornecedor[i].endereco.cidade);
            fscanf(arqf, "%s", fornecedor[i].endereco.estado);
            fscanf(arqf, "%d", &fornecedor[i].ddd);
            fscanf(arqf, "%s", fornecedor[i].telefone); 
            fscanf(arqf,"%s", lixo);
        }
    }
    fclose(arqf);
    

    // produto
    fscanf(arqp, "%d", qtdp);
    fscanf(arqp,"%s", lixo);
    while(!feof(arqp)){
        for(int i=0; i<*qtdp; i++){
            fscanf(arqp, "%d", &produto[i].cod);
            fscanf(arqp, " %[^\n]", produto[i].nome);
            fscanf(arqp, " %[^\n]", produto[i].desc);
            fscanf(arqp, "%d", &produto[i].codigo);
            fscanf(arqp, "%f", &produto[i].preco);
            fscanf(arqp, "%d", &produto[i].estoq_at);
            fscanf(arqp, "%d", &produto[i].estoq_min);
            fscanf(arqp,"%s", lixo);
        }
    }
    
    fclose(arqp);
}

// cadastrar novo fornecedor  1
void cadastro_forn(forn fornecedor[], int *qtdf){
    system("cls");
    int e, i;
    
    printf("Digite o codigo do novo fornecedor\n");
    scanf("%d", &fornecedor[*qtdf].codigo);
    int encontrado = 0;
    if(*qtdf >= n_forn){
        printf("O maximo de fornecedores foi atingido\n");
        system("PAUSE");
        return;
    }
    
    for(e=0; e < *qtdf; e++){
        if(fornecedor[*qtdf].codigo == fornecedor[e].codigo){ //cadastrar um novo fornecedor, não pode existir codigos iguais
            encontrado = 1;
            break;
        }
    }

    if(encontrado == 1){
        printf("Esse codigo de fornecedor ja foi registrado, retornando...\n");
        system("PAUSE");
        return;
    }
    else{
        printf("Digite o nome do novo fornecedor\n");
        scanf(" %[^\n]", fornecedor[*qtdf].nome);
        printf("Digite seu cpf ou cnpj\n");
        scanf(" %{^\n]", fornecedor[*qtdf].cpf_cnpj);
        printf("Endereco\n");
        printf("Digite a Rua\n");
        scanf(" %[^\n]", fornecedor[*qtdf].endereco.rua);
        printf("Digite o numero\n");
        scanf("%d", &fornecedor[*qtdf].endereco.numero);
        printf("Digite o complemento\n");
        scanf(" %[^\n]", fornecedor[*qtdf].endereco.comple);
        printf("Digite o bairro\n");
        scanf(" %[^\n]", fornecedor[*qtdf].endereco.bairro);
        printf("Digite a cidade\n");
        scanf(" %[^\n]", fornecedor[*qtdf].endereco.cidade);
        printf("Digite o estado\n");
        scanf(" %s", fornecedor[*qtdf].endereco.estado);
        printf("Digite o DDD\n");
        scanf("%d", &fornecedor[*qtdf].ddd);
        printf("Digite o telefone\n");
        scanf("%s", fornecedor[*qtdf].telefone);
        system("cls");
        printf("O novo fornecedor foi cadastrado\n");
        *qtdf += 1;
        system("PAUSE");
    }
}

// alterar fornecedor 2
void alterar_forn(forn fornecedor[], int qtdf){
    system("cls");
    int cod_pes, t = -1; 

    printf("Digite o codigo do fornecedor a alterar\n");
    scanf("%d", &cod_pes);
    for(int i = 0; i < qtdf; i++){
        if(cod_pes == fornecedor[i].codigo){
            t = i;
            break;
        }
    }

    if(t != -1){
        printf("Fornecedor encontrado\n");
        printf("Digite o nome do fornecedor\n");
        scanf(" %[^\n]", fornecedor[t].nome);
        printf("Digite seu cpf ou cnpj\n");
        scanf(" %{^\n]", fornecedor[t].cpf_cnpj);
        printf("Endereco\n");
        printf("Digite a Rua\n");
        scanf(" %[^\n]", fornecedor[t].endereco.rua);
        printf("Digite o numero\n");
        scanf("%d", &fornecedor[t].endereco.numero);
        printf("Digite o complemento\n");
        scanf(" %[^\n]", fornecedor[t].endereco.comple);
        printf("Digite o bairro\n");
        scanf(" %[^\n]", fornecedor[t].endereco.bairro);
        printf("Digite a cidade\n");
        scanf(" %[^\n]", fornecedor[t].endereco.cidade);
        printf("Digite o estado\n");
        scanf(" %s", fornecedor[t].endereco.estado);
        printf("Digite o DDD\n");
        scanf("%d", &fornecedor[t].ddd);
        printf("Digite o telefone\n");
        scanf("%s", fornecedor[t].telefone);
        system("cls");
        printf("Fornecedor atualizado\n");
        system("PAUSE"); 

    }
    else{
        printf("Nao existe esse codigo de fornecedor\n");
        system("PAUSE");
        return;
    }
}

// cadastrar novo produto 3
void cadastro_prod(prod produto[], forn fornecedor[], int *qtdf, int *qtdp){
    system("cls");
    printf("Digite o codigo do novo produto\n");
    scanf("%d", &produto[*qtdp].cod);
    int t = 0; // encontra o produto
    int aux = 0; //encontra o fornecedor
    
    if(*qtdp >= n_prod){
        printf("O maximo de produtos foi atingido\n");
        system("PAUSE");
        return;
    }

    for(int j = 0; j < *qtdp; j++){
        if(produto[j].cod == produto[*qtdp].cod){
            t = 1;
            break;
        }
    }

    if(t == 1){
        printf("Codigo de produto ja existe\n");
        system("PAUSE"); 
        return;
    }

    else{
        printf("Digite o nome do produto\n");
        scanf(" %[^\n]", produto[*qtdp].nome);
        printf("Digite uma decricao do produto\n");
        scanf(" %[^\n]", produto[*qtdp].desc);
        printf("Digite o codigo do fornecedor\n");
        scanf("%d", &produto[*qtdp].codigo);
        for(int j = 0; j < *qtdf; j++){
            if(fornecedor[j].codigo == produto[*qtdp].codigo){
                aux = 1;
                break;
            }
        }

        if(aux == 1){
            printf("Digite o preco unitario\n");
            scanf("%f", &produto[*qtdp].preco);
            printf("Digite o estoque atual\n");
            scanf("%d", &produto[*qtdp].estoq_at);
            printf("Digite o estoque minimo\n");
            scanf("%d", &produto[*qtdp].estoq_min);
            system("cls");
            *qtdp += 1;
            printf("O novo produto foi cadastrado\n");
            system("PAUSE"); 
        }

        else{
            printf("Fornecedor nao encontrado\n");
            system("PAUSE"); 
            return;
        }
    }
}

// alterar produtos 4
void alterar_prod(prod produto[], int qtdp){
    system("cls");
    int cod_pes, t = -1;
    printf("Digite o codigo do produto a ser alterado\n");
    scanf("%d", &cod_pes);
     
    t = pesquisa_vetor(produto, qtdp, cod_pes);

    if(t != -1){
        printf("Digite o nome do produto\n");
        scanf(" %[^\n]", produto[t].nome);
        printf("Digite uma decricao do produto\n");
        scanf(" %[^\n]", produto[t].desc);
        printf("Digite o preco unitario\n");
        scanf("%f", &produto[t].preco);
        printf("Digite o estoque minimo\n");
        scanf("%d", &produto[t].estoq_min);
        system("cls");
        printf("O novo produto foi alterado\n");
    }
    
    else{
        printf("Codigo de produto nao existe\n");
        return;
    }
    system("PAUSE");
}

// entrada de estoque 5
void entrada_estoque(prod produto[], int qtdp){
    system("cls");
    int cod_pes, t = -1, q_prod;
    printf("Digite o codigo do produto que recebera produto\n");
    scanf("%d", &cod_pes);

    t = pesquisa_vetor(produto, qtdp, cod_pes);

    if(t != -1){
        printf("Digite a quantidade de produtos que foi recebido\n");    
        scanf("%d", &q_prod);
        produto[t].estoq_at += q_prod;
        printf("O estoque foi alterado\n");
    }

    else{
        printf("Codigo de produto nao existe\n");
        system("PAUSE");
        return;
    }
    
    system("PAUSE");
}

// realizar a venda 6 
void realizar_venda(prod produto[], int qtdp){
    system("cls");
    int cod_pes, t = -1, q_comprar;
    float total_pagar;
    do{
        printf("Digite o codigo do produto que quer comprar\n");
        printf("Caso deseje voltar sem comprar nada digite -1\n");
        scanf("%d", &cod_pes);
        
        if(cod_pes == -1){
            return;
        }
        
        t = pesquisa_vetor(produto, qtdp, cod_pes);

        if(t == -1){
            printf("Este codigo de produto nao existe\n");
        }
        
        if(t != -1 ){
            printf("Quantas Unidades deseja comprar?\n");
            scanf("%d", &q_comprar);
            system("cls");
            if(q_comprar <= produto[t].estoq_at){
                total_pagar = produto[t].preco * q_comprar;
                produto[t].estoq_at -= q_comprar;
                printf("Nota fiscal\n");
                printf("---------------\n");
                printf("|| C.M Industry ||\n");
                printf("Preco unidade: %.2f\n", produto[t].preco);
                printf("preco total: %.2f\n", total_pagar);
                printf("quantidade comprada %d\n", q_comprar);
                printf("Date: XX/XX/XXXX\nHora XX:XX\n");
                printf("---------------\n");
                system("PAUSE");
            }
            
            else{
                printf("Nao foi possivel comprar pois a quantidade que deseja comprar eh superior a disponivel em estoque\n");
                system("PAUSE");
                return;
            }  
        }
    }while(t == -1);
}

// relatorio do estoque minimo 7
void relatorio_estoque_min(prod produto[], forn fornecedor[], int qtdp, int qtdf){
    system("cls");
    int i, j, aux = 0;

    for(i=0; i < qtdp; i++){
        if(produto[i].estoq_at < produto[i].estoq_min){
            aux = 1;
            printf("Codigo do produto: %d\n", produto[i].cod);
            printf("Nome do produto: %s\n", produto[i].nome);
            printf("Estoque atual: %d\n", produto[i].estoq_at);
            printf("Estoque minimo: %d\n", produto[i].estoq_min);
            for(j=0; j < qtdf; j++){
                if(produto[i].codigo == fornecedor[j].codigo){
                    printf("Nome do fornecedor: %s\n", fornecedor[j].nome);
                    printf("Telefone do fornecedor: (%d) %s\n", fornecedor[j].ddd, fornecedor[j].telefone);
                }
            }
            printf("\n");
        }
    }

    if(aux == 0){
        printf("Nao tem nenhum produto com estoque abaixo do minimo\n");
    }
    system("PAUSE");
}   

// salvar no arquivo .txt 8
void salvar_dados(forn fornecedor[], prod produto[], int qtdf, int qtdp){
    system("cls");
    int i;
    FILE *arqf;
    arqf = fopen("forn.txt","w+");
    
    fprintf(arqf,"%d\n",qtdf);
    fprintf(arqf,"***\n");
    for(i = 0; i < qtdf; i++){
        fprintf(arqf,"%d\n", fornecedor[i].codigo);
        fprintf(arqf,"%s\n", fornecedor[i].nome);
        fprintf(arqf,"%s\n", fornecedor[i].cpf_cnpj);
        fprintf(arqf,"%s\n", fornecedor[i].endereco.rua);
        fprintf(arqf,"%d\n", fornecedor[i].endereco.numero);
        fprintf(arqf,"%s\n", fornecedor[i].endereco.comple);
        fprintf(arqf,"%s\n", fornecedor[i].endereco.bairro);
        fprintf(arqf,"%s\n", fornecedor[i].endereco.cidade);
        fprintf(arqf,"%s\n", fornecedor[i].endereco.estado);
        fprintf(arqf,"%d\n", fornecedor[i].ddd);
        fprintf(arqf,"%s\n", fornecedor[i].telefone);
        fprintf(arqf,"***\n");
    }
    fclose(arqf);
    
    

    FILE *arqp;
    arqp = fopen("prod.txt","w+");

    fprintf(arqp,"%d\n", qtdp);
    fprintf(arqp,"***\n");
    for(i = 0; i < qtdp; i++){
        fprintf(arqp,"%d\n", produto[i].cod);
        fprintf(arqp,"%s\n", produto[i].nome);
        fprintf(arqp,"%s\n", produto[i].desc);
        fprintf(arqp,"%d\n", produto[i].codigo);
        fprintf(arqp,"%.2f\n", produto[i].preco);
        fprintf(arqp,"%d\n", produto[i].estoq_at);
        fprintf(arqp,"%d\n", produto[i].estoq_min);
        fprintf(arqp,"***\n");
    }
    fclose(arqp);
    printf("Dados salvos\n");
    system("PAUSE");
}

// procura de produtos extra
int pesquisa_vetor(prod produto[], int qtdp, int cod_pes){
    int t = -1;
    for(int i = 0; i < qtdp; i++){
        if(produto[i].cod == cod_pes){
            t = i;
            break;
        }
    }
    return t;
}