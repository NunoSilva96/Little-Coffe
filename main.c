#include <stdio.h>
#include <stdlib.h>
#include <curses.h> // Possibilitou-me realizar as janelas, fundos entre outras coisas.
#include <locale.h> // Para usar caracteres como acentos, etc.

/*===================== FEITO EM CASA====================*/

//Menu das Opções - Ajuda e Controlos
//Terminar Sessão

/*=======================================================*/

/*===================== ID DE TECLAS ====================*/
// Aqui defino os ids das teclas para não ter de os decorar, usando apenas um define para cada tecla,
#define TECLA_D 100
#define TECLA_S 115
#define TECLA_W 119
#define TECLA_A 97
#define TECLA_ENTER 10
#define TECLA_ESQ 27
#define TECLA_1 49
#define TECLA_2 50
#define TECLA_3 51
#define TECLA_4 52
#define TECLA_5 53

/*=======================================================*/

/*=======================PREÇOS CAFETARIA================*/
// Aqui defino o preço de cada produto, sendo o cafe1, o preco do primeiro produto, o café2 o segundo
//e assim sucessivamente.
float cafe1=0.60;
float cafe2=0.65;
float cafe3=0.55;
float cafe4=1.10;
float cafe5=0.80;
float cafe6=0.80;

float cafe7=0.60;
float cafe8=0.20;
float cafe9=0.65;
float cafe10=0.10;
float cafe11=2.00;
float cafe12=2.20;

/*=======================================================*/
float pago; // Uso esta variável para saber o montante recebido para o pagamento.
float admin00; // Uso esta variável para o sistema de logins, para saber se entrou como Admin, Empregado1 ou 2.
float emp00; // O mesmo que o Admin00
float emp100; // O mesmo que o admin00


/*======================== PRECO DOS PASTEIS =============*/

float pastel1=0.80;
float pastel2=0.80;
float pastel3=0.80;
float pastel4=0.80;
float pastel5=0.90;
float pastel6=1.10;

float pastel7=0.80;
float pastel8=0.80;
float pastel9=0.60;
float pastel10=0.60;
float pastel11=1.20;
float pastel12=0.50;

/*=======================================================*/

/*================== PRECOS PADARIA =====================*/

float padaria1=0.20;
float padaria2=0.25;
float padaria3=1.20;
float padaria4=0.15;
float padaria5=0.30;
float padaria6=0.20;

float padaria7=0.20;
float padaria8=0.15;
float padaria9=0.50;
float padaria10=0.50;
float padaria11=0.35;
float padaria12=0.80;

/*=======================================================*/

/*====================== PRECOS SALGADOS ================*/

float salgado1=0.80;
float salgado2=1.20;
float salgado3=0.90;
float salgado4=0.90;
float salgado5=4.50;
float salgado6=0.60;

float salgado7=2.70;
float salgado8=0.95;
float salgado9=0.95;
float salgado10=0.70;
float salgado11=0.85;
float salgado12=9.40;

/*=======================================================*/

/*========================PREÇO ALCOOL===================*/

float alcool1=1;
float alcool2=2;
float alcool3=1;
float alcool4=2.50;
float alcool5=0.90;
float alcool6=0.80;

float alcool7=0.80;
float alcool8=0.50;
float alcool9=0.60;
float alcool10=0.90;
float alcool11=4;
float alcool12=8;

/*==================== PRECO REFEIÇÕES===================*/

float refeicao1=5;
float refeicao2=1.50;
float refeicao3=3.50;
float refeicao4=3.50;
float refeicao5=3.50;
float refeicao6=3.50;

float refeicao7=3;
float refeicao8=0.50;
float refeicao9=0.50;
float refeicao10=0.70;
float refeicao11=0.50;
float refeicao12=0.50;

float precofinal; // Aqui está a variavel que me dá o valor total do consumo do cliente.






void menuinicial()
{
    WINDOW *janela1, *janela2, *janela3, *janela4; //Ponteiros das janelas

    setlocale(LC_ALL, "Portuguese"); // Permite-me usar caracteres portugueses

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0); // Dá os contornos às Janelas
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0); //Define a Segunda Janela (Lateral Esquerda)
    wbkgd(janela2, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela2, A_BOLD); // Coloca o Texto mais forte (Nomeadamente Negrito)
    wborder(janela2, 0,0,0,0,0,0,0,0); // Dá os contornos ás Janelas
    mvwprintw(janela2, 2,2, "1 - Ver Produtos"); //Define o Texto, nas Coordenadas indicadas.
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20); // Cria a janela 3, que é a box principal.
    wbkgd(janela3, COLOR_PAIR(1)); // Dá o Fundo Azul e a Letra Branca
    wattron(janela3, A_BOLD); // Define o texto para negrito, mais forte.
    wborder(janela3, 0,0,0,0,0,0,0,0); // Dá os contornos às janelas
    mvwprintw(janela3, 4,14, "Bem-Vindo ao Little Coffee");
    mvwprintw(janela3, 6,14, "Trabalho Realizado por: Nuno Silva");
    mvwprintw(janela3, 8,14, "Turma: TGPSI | Ano: 1º");
    mvwprintw(janela3, 10,14, "Professora: Carla Macedo");
    mvwprintw(janela3, 12,14, "Pressione qualquer tecla para continuar");
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login:   ||   ");
    wrefresh(janela4);


    wgetch(janela3);
    wrefresh(janela3);


}

//Estrutura para Logins. Aqui estão as variáveis que me permitem fazer o Login.
struct rgLogin
{
    char cemp[15];
    char password[15];
    char remp1[15];
    char remp2[15];
    char remp3[15];
    char rpass1[15];
    char rpass2[15];
    char rpass3[15];
    int logadm;
    int logemp;
    int logemp2;
    int admin;
    int empregado;
    int empregado2;
};

struct rgLogin login;

void menulogin()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;

    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0); // Dá os contornos às janelas.
    wrefresh(janela1); //Atualizaremos a janela1




    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    echo();
    mvwprintw(janela3, 7,16, "Código de Empregado:");
    wgetstr(janela3, login.cemp);

    mvwprintw(janela3, 9,16, "Password:");
    wgetstr(janela3,login.password);
    noecho();

    /*==========================================*/

    strcpy(login.remp1, "admin");
    strcpy(login.remp2,"empregado");
    strcpy(login.remp3,"empregado2");
    strcpy(login.rpass1,"superadmin");
    strcpy(login.rpass2,"emppass");
    strcpy(login.rpass3,"emppass2");


    /*==========================================*/

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login:   ||   ");
    wrefresh(janela4);



    if(strcmp(login.cemp, login.remp1) == 0)
    {
        if(strcmp(login.password, login.rpass1) == 0)
        {
            menulogin_adm();
        }
        else
        {
            menulogin_erro();
        }
    }
    else if(strcmp(login.cemp, login.remp2) == 0)
    {
        if(strcmp(login.password, login.rpass2) == 0)
        {
            menulogin_emp1();
        }
        else
        {
            menulogin_erro();
            login.logemp = 0;
        }

    }
    else if(strcmp(login.cemp, login.remp3) == 0)
    {
        if(strcmp(login.password, login.rpass3) == 0)
        {
            menulogin_emp2();
            login.logemp2 = 1;
        }
        else
        {
            menulogin_erro();
            login.logemp2 = 0;
        }
    }
    else
    {
        menulogin_erro();
    }

}

void menumudarconta()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;

    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1




    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    //curs_set(1);
    echo();
    mvwprintw(janela3, 7,16, "Código de Empregado:");
    wgetstr(janela3, login.cemp);

    mvwprintw(janela3, 9,16, "Password:");
    wgetstr(janela3,login.password);
    noecho();

    /*==========================================*/

    strcpy(login.remp1, "admin");
    strcpy(login.remp2,"empregado");
    strcpy(login.remp3,"empregado2");
    strcpy(login.rpass1,"superadmin");
    strcpy(login.rpass2,"emppass");
    strcpy(login.rpass3,"emppass2");


    /*==========================================*/

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login:   ||   ");
    wrefresh(janela4);



    if(strcmp(login.cemp, login.remp1) == 0)
    {
        if(strcmp(login.password, login.rpass1) == 0)
        {
            menulogin_adm();
            login.logadm = 1;
        }
        else
        {
            menulogin_erro();
            login.logadm = 0;
        }
    }
    else
    {
        menulogin_erro();
    }

    if(strcmp(login.cemp, login.remp2) == 0)
    {
        if(strcmp(login.password, login.rpass2) == 0)
        {
            menulogin_emp1();
            login.logemp = 1;
        }
        else
        {
            menulogin_erro();
            login.logemp = 0;
        }

    }
    else
    {
        menulogin_erro();
    }
    if(strcmp(login.cemp, login.remp3) == 0)
    {
        if(strcmp(login.password, login.rpass3) == 0)
        {
            menulogin_emp2();
            login.logemp2 = 1;
        }
        else
        {
            menulogin_erro();
            login.logemp2 = 0;
        }
    }
    else
    {
        menulogin_erro();
    }

}


void menulogin_adm()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    time_t current_time; //Lê a data e hora
    char *tempo; //Ponteiro para Mostrar / Gravar a Data e Hora
    current_time = time(NULL); //
    tempo = ctime(&current_time); // Converte o Tempo para a Nossa Leitura


    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    admin00=1;
    emp00=0;
    emp100=0;

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 7,16, "Logado como: Administrador");
    mvwprintw(janela3, 9,16, "Detalhes: %s", tempo);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login: Administrador");
    wrefresh(janela4);
    wgetch(janela3);
    menu_prod_caf();

}


void menugestao()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,23, "MENU DA GESTÃO");
    mvwprintw(janela3, 2,2,"********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,26, "Contas");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,24, "Patrocinios");
    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menugestao_1();
    }
    else if(ch==TECLA_S)
    {
        menugestao_1();
    }
    else if(ch==TECLA_ENTER)
    {
        if(admin00==1)
        {
            menugestao_contas();
        }
        else
        {
           menugestao_erro();
        }

    }
    else if(ch==TECLA_1)
    {
        menu_prod_caf();
    }
    else if(ch==TECLA_2)
    {
        menulogin();
    }
    else if(ch==TECLA_3)
    {
        menugestao();
    }
    else if(ch==TECLA_4)
    {
        menuopcoes();
    }
    else if(ch==TECLA_5)
    {
        menufinalizar_0();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_caf();
    }


}

void menugestao_erro()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1

    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,23, "MENU DA GESTÃO");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Lamento informar, mas apenas o Administrador tem acesso");

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);
    wgetch(janela3);

    menu_prod_caf();
}


void menugestao_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,23, "MENU DA GESTÃO");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,26, "Contas");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,24, "Patrocínios");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menugestao();
    }
    else if(ch==TECLA_S)
    {
        menugestao();
    }
    else if(ch==TECLA_ENTER)
    {
        menupatrocinios();
    }
    else if(ch==TECLA_1)
    {
        menugestao();
    }
    else if(ch==TECLA_2)
    {
        menulogin();
    }
    else if(ch==TECLA_3)
    {
        menugestao();
    }
    else if(ch==TECLA_4)
    {
        menuopcoes();
    }
    else if(ch==TECLA_5)
    {
        menufinalizar_0();
    }

}


void menugestao_contas()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,23, "MENU DA GESTÃO");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Conta 1: Administrador");
    mvwprintw(janela3, 6,2,"Password: superadmin");
    mvwprintw(janela3, 8,2,"Conta 2: Empregado");
    mvwprintw(janela3, 10,2,"Password: emppass");
    mvwprintw(janela3, 12,2, "Conta 3: Empregado2");
    mvwprintw(janela3, 14,2, "Password: emppass2");
    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


    if(ch==TECLA_1)
    {
        menu_prod_caf();
    }
    else if(ch==TECLA_2)
    {
        menulogin();
    }
    else if(ch==TECLA_3)
    {
        menugestao();
    }
    else if(ch==TECLA_4)
    {
        menuopcoes();
    }
    else if(ch==TECLA_5)
    {
        menufinalizar_0();
    }
    else if(ch==TECLA_ENTER)
    {
        menugestao();
    }

}

void menupatrocinios()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,23, "PATROCÍNIOS");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Cadeia de Hoteis Stana");
    mvwprintw(janela3, 6,2,"Companhia Aéria Ana Voos");
    mvwprintw(janela3, 8,2,"Escola Profissional Digital");
    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


    if(ch==TECLA_1)
    {
        menu_prod_caf();
    }
    else if(ch==TECLA_2)
    {
        menulogin();
    }
    else if(ch==TECLA_3)
    {
        menugestao();
    }
    else if(ch==TECLA_4)
    {
        menuopcoes();
    }
    else if(ch==TECLA_5)
    {
        menufinalizar_0();
    }
    else if(ch==TECLA_ENTER)
    {
        menugestao();
    }

}

void menuopcoes()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "MENU DAS OPÇÕES");
    mvwprintw(janela3, 2,2,"********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "Créditos");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "Ajuda e Controlos");
    mvwprintw(janela3, 8,2, "Terminar Sessão");
    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menuopcoes_2();
    }
    else if(ch==TECLA_S)
    {
        menuopcoes_1();
    }
    else if(ch==TECLA_ENTER)
    {
        menuopcoes_creditos();
    }

}

void menuopcoes_creditos()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "CRÉDITOS");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2, "Trabalho Realizado por Nuno Silva");
    mvwprintw(janela3, 6,2, "Data de Entrega: 23/6/2014");
    mvwprintw(janela3, 8,2, "Total de Linhas Finais:");
    mvwprintw(janela3, 10,2,"Bibliotecas: Curses.h, stdio.h, stdlib.h, locale.h");

    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);
    if(ch==TECLA_ENTER)
    {
        menuopcoes();
    }

}

void menuopcoes_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1
    int ch;


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,22, "MENU DAS OPÇÕES");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2, "Créditos");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "Ajuda e Controlos");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "Terminar Sessão");
    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menuopcoes();
    }
    else if(ch==TECLA_S)
    {
        menuopcoes_2();
    }
    else if(ch==TECLA_ENTER)
    {
        menuopcoes_ajuda();
    }
}

void menuopcoes_ajuda()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1
    int ch;


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);


    mvwprintw(janela3, 1,22, "MENU AJUDA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 6,2, "W - Para Cima");
    mvwprintw(janela3, 8,2, "S - Para Baixo");
    mvwprintw(janela3, 10,2, "A - Para a Direita");
    mvwprintw(janela3, 12,2, "D - Para a Esquerda");
    mvwprintw(janela3, 6,25, "ESQ - Para Sair");
    mvwprintw(janela3, 8,25, "ENTER - Para Selecionar os items");

    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_ENTER)
    {
        menuopcoes();
    }
    else if(ch==TECLA_ESQ)
    {
        menuopcoes();
    }
}

void menuopcoes_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    int ch;

    mvwprintw(janela3, 1,22, "MENU DAS OPÇÕES");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2, "Créditos");
    mvwprintw(janela3, 6,2, "Ajuda e Controlos");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "Terminar Sessão");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menuopcoes_1();
    }
    else if(ch==TECLA_S)
    {
        menuopcoes();
    }

}

struct rgDados
{
    char nome[100];
    char localidade[40];
    char codigopostal[40];
    int numerocontribuinte[40];
    int result;

};

struct rgDados fatura;



void menufinalizar_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    echo();

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 3,2, "Nome:");
    wgetstr(janela3, fatura.nome);
    mvwprintw(janela3, 5,2, "Localidade:");
    wgetstr(janela3, fatura.localidade);
    mvwprintw(janela3, 7,2, "Número Contribuinte:");
    wgetstr(janela3, fatura.numerocontribuinte);
    mvwprintw(janela3, 9,2, "Código-Postal:");
    wgetstr(janela3, fatura.codigopostal);
    wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);
    wgetch(janela3);
    menufinalizar_3();

}


void menufinalizar_0()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Montante a Pagar: %.2f", precofinal);
    mvwprintw(janela3, 6,2, "Deseja Número de Contribuinte na Fatura:");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "SIM");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,6, "NÃO");
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_D)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_2();
    }
}

float recebido2;
float recebido;

void menufinalizar_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    echo();
    mvwprintw(janela3, 4,2,"Digite o Montante Recebido:");
    wscanw(janela3, "%f", &recebido2);
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_D)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_8();
    }
}

void menufinalizar_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Recebido: %.2f", recebido2);
    mvwprintw(janela3, 6,2,"Pagar: %.2f", precofinal);
    recebido=recebido2-precofinal;
    mvwprintw(janela3, 8,2,"Troco: %.2f", recebido);
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_D)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_9();
    }
}

void menufinalizar_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Obrigado e Volte Sempre !");
    mvwprintw(janela3, 6,2,"Porque no Little Coffee há Stana");
    mvwprintw(janela3, 8,2,"E onde há Stana, há Coffee de Banana!");
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_D)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_1();
    }
    else if(ch==TECLA_ENTER)
    {
        menu_prod_caf();
    }
}

void menufinalizar_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Selecione uma das Seguintes Contas:");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2,"Ana Costa");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2,"Florinda Ramos");
    mvwprintw(janela3, 10,2,"Carla Macedo");
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menufinalizar_12();
    }
    else if(ch==TECLA_S)
    {
        menufinalizar_11();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_ana();
    }
}

void menufinalizar_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Selecione uma das Seguintes Contas:");
    mvwprintw(janela3, 6,2,"Ana Costa");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2,"Florinda Ramos");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2,"Carla Macedo");
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menufinalizar_10();
    }
    else if(ch==TECLA_S)
    {
        menufinalizar_12();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_florinda();
    }
}

void menufinalizar_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Selecione uma das Seguintes Contas:");
    mvwprintw(janela3, 6,2,"Ana Costa");
    mvwprintw(janela3, 8,2,"Florinda Ramos");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2,"Carla Macedo");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menufinalizar_11();
    }
    else if(ch==TECLA_S)
    {
        menufinalizar_10();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_carla();
    }
}

struct rgMultibanco
{
    char codsecreto[5];
    char ccodsecreto[5];
};

struct rgMultibanco mb;

void menufinalizar_ana()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");

    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,6,"Conta Bancária em Nome de: Ana Costa");
    mvwprintw(janela3, 6,6,"Digite o Código Secreto\n");
    echo();
    wgetstr(janela3, mb.codsecreto);
    echo();
    def_prog_mode();

    FILE *mb1;
    mb1 = fopen("mb1.txt" , "r");
    fgets(mb.ccodsecreto, 5, mb1);
    fclose(mb1);
    reset_prog_mode();

    if(strcmp(mb.codsecreto, mb.ccodsecreto) == 0)
    {
        multicerto();
    }
    else
    {
        multierrado();
    }

    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_ENTER)
    {
        // EM BREVE
    }
}

void menufinalizar_florinda()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");

    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,6,"Conta Bancária em Nome de: Florinda Ramos");
    echo();
    mvwprintw(janela3, 6,6,"Digite o Código Secreto\n");
    wgetstr(janela3, mb.codsecreto);
    noecho();
    def_prog_mode();

    FILE *mb1;
    mb1 = fopen("mb2.txt" , "r");
    fgets(mb.ccodsecreto, 5, mb1);
    fclose(mb1);
    reset_prog_mode();

    if(strcmp(mb.codsecreto, mb.ccodsecreto) == 0)
    {
        multicerto();
    }
    else
    {
        multierrado();
    }

    ch = wgetch(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_ENTER)
    {
        // EM BREVE
    }
}

void menufinalizar_carla()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");

    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,6,"Conta Bancária em Nome de: Florinda Ramos");
    echo();
    mvwprintw(janela3, 6,6,"Digite o Código Secreto\n\t");
    wgetstr(janela3, mb.codsecreto);
    noecho();
    def_prog_mode();

    FILE *mb1;
    mb1 = fopen("mb3.txt" , "r");
    fgets(mb.ccodsecreto, 5, mb1);
    fclose(mb1);
    reset_prog_mode();

    if(strcmp(mb.codsecreto, mb.ccodsecreto) == 0)
    {
        multicerto();
    }
    else
    {
        multierrado();
    }

    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_ENTER)
    {
        // EM BREVE
    }
}

void multierrado()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Código Secreto Errado!", precofinal);



    wgetch(janela3);
    menufinalizar_5();

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


}
void multicerto()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Montante a Pagar: %.2f", precofinal);
    mvwprintw(janela3, 6,2,"Montante pago com sucesso!");

    wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


}

void menufinalizar_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Montante a Pagar: %.2f", precofinal);
    mvwprintw(janela3, 6,2, "Deseja Número de Contribuinte na Fatura:");
    mvwprintw(janela3, 8,2, "SIM");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,6, "NÃO");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_D)
    {
        menufinalizar_0();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_0();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_5();
    }
}


void menufinalizar_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2, "Nome: %s", fatura.nome);
    mvwprintw(janela3, 6,2, "Localidade: %s", fatura.localidade);
    mvwprintw(janela3, 8,2, "Número Contribuinte: %s", fatura.numerocontribuinte);
    mvwprintw(janela3, 10,2, "Código Postal: %s", fatura.codigopostal);
    mvwprintw(janela3, 13,2, "Confirma os dados a cima referidos?");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 15,2, "SIM");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 15,6, "NÃO");
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);

    if(ch==TECLA_D)
    {
        menufinalizar_4();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_4();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_5();
    }
}

void menufinalizar_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2, "Nome: %s", fatura.nome);
    mvwprintw(janela3, 6,2, "Localidade: %s", fatura.localidade);
    mvwprintw(janela3, 8,2, "Número Contribuinte: %s", fatura.numerocontribuinte);
    mvwprintw(janela3, 10,2, "Código Postal: %s", fatura.codigopostal);
    mvwprintw(janela3, 13,2, "Confirma os dados a cima referidos?");
    mvwprintw(janela3, 15,2, "SIM");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 15,6, "NÃO");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


    if(ch==TECLA_D)
    {
        menufinalizar_3();
    }
    else if(ch==TECLA_A)
    {
        menufinalizar_3();
    }
    else if(ch==TECLA_ENTER)
    {

    }

}

void menufinalizar_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Qual o Método de Pagamento que Deseja:");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2,"Multibanco");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2,"Dinheiro");
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menufinalizar_6();
    }
    else if(ch==TECLA_S)
    {
        menufinalizar_6();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_10();
    }

}

void menufinalizar_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);

    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 1,22, "FINALIZAR FATURA");
    mvwprintw(janela3, 2,2,"********************************************************");
    mvwprintw(janela3, 4,2,"Qual o Método de Pagamento que Deseja:");
    mvwprintw(janela3, 6,2,"Multibanco");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2,"Dinheiro");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    noecho();

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menufinalizar_5();
    }
    else if(ch==TECLA_S)
    {
        menufinalizar_5();
    }
    else if(ch==TECLA_ENTER)
    {
        menufinalizar_7();
    }

}

float recebido;








void menulogin_erro()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    time_t current_time; //Lê a data e hora
    char *tempo; //Ponteiro para Mostrar / Gravar a Data e Hora
    current_time = time(NULL); //
    tempo = ctime(&current_time); // Converte o Tempo para a Nossa Leitura


    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 4,16, "Nome de Utilizador ou Password Errados!");

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login:     ||");
    wrefresh(janela4);
    wgetch(janela3);
    menulogin();

}

void menulogin_emp1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    time_t current_time; //Lê a data e hora
    char *tempo; //Ponteiro para Mostrar / Gravar a Data e Hora
    current_time = time(NULL); //
    tempo = ctime(&current_time); // Converte o Tempo para a Nossa Leitura


    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 7,16, "Logado como: Empregado 1");
    mvwprintw(janela3, 9,16, "Detalhes: %s", tempo);
    admin00=0;
    emp00=1;
    emp100=0;

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login: Empregado 1");
    wrefresh(janela4);
    wgetch(janela3);

    menu_prod_caf();
}

void menulogin_emp2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    time_t current_time; //Lê a data e hora
    char *tempo; //Ponteiro para Mostrar / Gravar a Data e Hora
    current_time = time(NULL); //
    tempo = ctime(&current_time); // Converte o Tempo para a Nossa Leitura


    setlocale(LC_ALL, "Portuguese");

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);

    mvwprintw(janela3, 7,16, "Logado como: Empregado 2");
    mvwprintw(janela3, 9,16, "Detalhes: %s", tempo);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1.5,1, "Login: Empregado 2");
    wrefresh(janela4);
    wgetch(janela3);

    admin00=0;
    emp00=0;
    emp100=1;
    menu_prod_caf();

}

struct rgAbas1
{
    int incafetaria;
    int inpadaria;
    int insalgado;
    int inpastelaria;
    int inalcool;
    int inrefeicao;
    int key;

};

struct rgAbas1 aba;

void menu_prod_caf()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();

        if(ch==TECLA_D)
        {
            menu_prod_pad();
        }
        else if(ch==TECLA_A)
        {
            menu_prod_ref();
        }
        else if(ch==TECLA_ENTER)
        {
            menu_cafe_1();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }




}

void menu_prod_ref()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);



    if(ch==TECLA_A)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_D)
    {
        menu_prod_caf();
    }
    else if(ch==TECLA_ENTER)
    {
        menu_refeicao_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_prod_pad()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
       mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_A)
    {
        menu_prod_caf();
    }
    if(ch==TECLA_D)
    {
        menu_prod_sal();
    }
    if(ch==TECLA_ENTER)
    {
        menu_pada_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_prod_pas()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_A)
    {
        menu_prod_sal();
    }
    if(ch==TECLA_D)
    {
        menu_prod_alc();
    }
    if(ch==TECLA_ENTER)
    {
        menu_pastel_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }



}
void menu_prod_alc()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_A)
    {
        menu_prod_pas();
    }
    else if(ch==TECLA_D)
    {
        menu_prod_ref();
    }
    else if(ch==TECLA_ENTER)
    {
        menu_alcoo_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}


void menu_prod_sal()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);



    if(ch==TECLA_A)
    {

        menu_prod_pad();
    }
    else if(ch==TECLA_D)
    {
        menu_prod_pas();
    }
    else if(ch==TECLA_ENTER)
    {
        menu_salga_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_cafe_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "Café           0,60");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);
    noecho();

        if(ch==TECLA_D)
        {
            menu_cafe_7();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_7();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_2();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {

           precofinal+=cafe1;
           menu_cafe_1();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }



}

void menu_cafe_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    noecho();
    wrefresh(janela4);

        if(ch==TECLA_D)
        {
            menu_cafe_8();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_8();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_3();
        }
        else if(ch==TECLA_W)
        {
            menu_cafe_1();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe2;
           menu_cafe_2();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }




}

void menu_cafe_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();


        if(ch==TECLA_W)
        {
            menu_cafe_2();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_9();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_4();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_9();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe3;
            menu_cafe_3();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }



}

void menu_cafe_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2,"Chá            1,10");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();

        if(ch==TECLA_W)
        {
            menu_cafe_3();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_5();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_10();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_10();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe4;
           menu_cafe_4();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_cafe_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,2,"Galão          0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));


mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    noecho();


        if(ch==TECLA_W)
        {
            menu_cafe_4();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_6();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_11();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_11();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe5;
            menu_cafe_5();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_cafe_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,2,"Chocolate      0,80");
    wattron(janela3, COLOR_PAIR(1));

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();

        if(ch==TECLA_W)
        {
            menu_cafe_5();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_1();
        }
        else if(ch==TECLA_A)
        {
           menu_cafe_12();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_12();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe6;
            menu_cafe_6();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}
void menu_cafe_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();


        if(ch==TECLA_W)
        {
            menu_cafe_12();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_8();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_1();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_1();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe7;
            menu_cafe_7();
        }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_cafe_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,38,"Leite          0,20");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();

    if(ch==TECLA_W)
        {
            menu_cafe_7();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_9();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_2();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_2();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe8;
           menu_cafe_8();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_cafe_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);
    noecho();

   if(ch==TECLA_W)
        {
            menu_cafe_8();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_10();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_3();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_3();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe9;
            menu_cafe_9();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_cafe_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);
    noecho();

    if(ch==TECLA_W)
        {
            menu_cafe_9();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_11();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_4();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_4();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe10;
            menu_cafe_10();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}
void menu_cafe_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);


    wrefresh(janela4);
    noecho();

    if(ch==TECLA_W)
        {
            menu_cafe_10();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_12();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_6();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_6();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe11;
            menu_cafe_11();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_cafe_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1




    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Café           0,60");
    mvwprintw(janela3, 6,2, "Garoto         0,65");
    mvwprintw(janela3, 8,2, "Carioca        0,55");
    mvwprintw(janela3, 10,2,"Chá            1,10");
    mvwprintw(janela3, 12,2,"Galão          0,80");
    mvwprintw(janela3, 14,2,"Chocolate      0,80");

    mvwprintw(janela3, 4,38,"Abatanado      0,60");
    mvwprintw(janela3, 6,38,"Leite          0,20");
    mvwprintw(janela3, 8,38,"Descafeinado   0,65");
    mvwprintw(janela3, 10,38,"Copo Água      0,10");
    mvwprintw(janela3, 12,38,"Sumo Laranja   2,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,38,"Sumo Natural   2,20");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);
    noecho();

    if(ch==TECLA_W)
        {
            menu_cafe_11();
        }
        else if(ch==TECLA_S)
        {
            menu_cafe_7();
        }
        else if(ch==TECLA_A)
        {
            menu_cafe_6();
        }
        else if(ch==TECLA_D)
        {
            menu_cafe_6();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=cafe12;
            menu_cafe_12();
        }
        else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_pastel_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
        mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_6();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_2();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_7();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_7();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel1;
            menu_pastel_1();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_pastel_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_1();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_3();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_8();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_8();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel2;
            menu_pastel_2();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1- Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_2();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_4();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_9();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_9();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel3;
            menu_pastel_3();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
        mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_3();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_5();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_10();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_10();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel4;
            menu_pastel_4();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
        mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_4();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_6();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_11();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_11();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel5;
            menu_pastel_5();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");
    wattron(janela3, COLOR_PAIR(1));

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
        mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_5();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_1();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_12();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_12();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel6;
            menu_pastel_6();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,33,"Croissant            0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_12();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_8();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_1();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_1();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel7;
            menu_pastel_7();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,33,"Trança               0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_7();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_9();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_2();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_2();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel8;
            menu_pastel_8();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");

    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_8();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_10();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_3();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_3();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel9;
            menu_pastel_9();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pastel_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");

    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,33,"Queque               1,20");
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_9();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_11();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_4();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_4();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel10;
            menu_pastel_10();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_pastel_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");

    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");

    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,33,"Queque               1,20");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
        {
            menu_pastel_10();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_12();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_5();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_5();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel11;
            menu_pastel_11();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}
void menu_pastel_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Mil Folhas        0,80");
    mvwprintw(janela3, 6,2, "Palmier Coberto   0,80");
    mvwprintw(janela3, 8,2, "Pirâmide          0,80");
    mvwprintw(janela3, 10,2,"Bola Creme        0,80");
    mvwprintw(janela3, 12,2,"Bola Chocolate    0,90");
    mvwprintw(janela3, 14,2,"Bola Chantily     1,10");

    mvwprintw(janela3, 4,33,"Croissant            0,80");
    mvwprintw(janela3, 6,33,"Trança               0,80");
    mvwprintw(janela3, 8,33,"Pastel Nata          0,60");
    mvwprintw(janela3, 10,33,"Queijadinha          0,60");
    mvwprintw(janela3, 12,33,"Queque               1,20");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,33,"Bolo de Arroz        0,50");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

   if(ch==TECLA_W)
        {
            menu_pastel_11();
        }
        else if(ch==TECLA_S)
        {
            menu_pastel_7();
        }
        else if(ch==TECLA_A)
        {
            menu_pastel_6();
        }
        else if(ch==TECLA_D)
        {
            menu_pastel_6();
        }
        else if(ch==TECLA_ESQ)
        {
            menu_prod_pas();
        }
        else if(ch==TECLA_ENTER)
        {
            precofinal+=pastel2;
            menu_pastel_12();
        }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

/*================== MENU DA PADARIA ===================*/
void menu_pada_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_6();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_2();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_7();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_7();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria1;
        menu_pada_1();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_pada_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_1();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_3();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_8();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_8();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria2;
        menu_pada_2();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_2();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_4();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_9();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_9();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria3;
        menu_pada_3();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_3();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_5();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_10();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_10();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria4;
        menu_pada_4();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}
void menu_pada_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");


    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_4();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_6();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_11();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_11();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria5;
        menu_pada_5();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");
    wattron(janela3, COLOR_PAIR(1));

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_5();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_1();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_12();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_12();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria6;
        menu_pada_6();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");

    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menu_pada_12();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_8();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_1();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_1();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria7;
        menu_pada_7();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}


void menu_pada_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,36, "Baguete           0,50");

    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_7();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_9();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_2();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_2();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria8;
        menu_pada_8();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");

    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_8();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_10();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_3();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_3();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria9;
        menu_pada_9();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_pada_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");

    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");

    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_9();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_11();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_4();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_4();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria10;
        menu_pada_10();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");


    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_10();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_12();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_5();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_5();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria11;
        menu_pada_11();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_pada_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");

        int ch;

    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Pão Centeio       0,20");
    mvwprintw(janela3, 6,2, "Pão Mistura       0,25");
    mvwprintw(janela3, 8,2, "Pão Grande        1,20");
    mvwprintw(janela3, 10,2, "Carcaça           0,15");
    mvwprintw(janela3, 12,2, "Pão Cereais       0,30");
    mvwprintw(janela3, 14,2, "Pão Bolinha       0,20");

    mvwprintw(janela3, 4,36, "Pão da Avó        0,20");
    mvwprintw(janela3, 6,36, "Pão de Trigo      0,15");
    mvwprintw(janela3, 8,36, "Baguete           0,50");
    mvwprintw(janela3, 10,36, "Baguete Cereais   0,50");
    mvwprintw(janela3, 12,36,"Pão Integral      0,35");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,36,"Pão Ciabatta      0,80");
    wattron(janela3, COLOR_PAIR(1));

    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);

    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_pada_11();
    }
    else if(ch==TECLA_S)
    {
        menu_pada_7();
    }
    else if(ch==TECLA_D)
    {
        menu_pada_6();
    }
    else if(ch==TECLA_A)
    {
        menu_pada_6();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_pad();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=padaria12;
        menu_pada_12();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }

}

void menu_salga_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_6();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_7();
    }
    else if(ch==TECLA_A)
    {
       menu_salga_7();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_2();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado1;
        menu_salga_1();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_1();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_3();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_8();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_8();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado2;
        menu_salga_2();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_2();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_4();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_9();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_9();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado3;
        menu_salga_3();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_3();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_5();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_10();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_10();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado4;
        menu_salga_4();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");


    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_4();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_6();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_11();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_11();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado5;
        menu_salga_5();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");
    wattron(janela3, COLOR_PAIR(1));

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_5();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_1();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_12();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_12();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado6;
        menu_salga_6();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_12();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_8();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_1();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_1();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado7;
        menu_salga_7();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_7();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_9();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_2();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_2();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado8;
        menu_salga_8();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_8();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_10();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_3();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_3();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado9;
        menu_salga_9();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_9();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_11();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_4();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_4();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado10;
        menu_salga_10();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_10();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_12();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_5();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_5();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado11;
        menu_salga_11();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_salga_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,22, "Salgado");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Croquete         0,80");
    mvwprintw(janela3, 6,2, "Chamuça          1,20");
    mvwprintw(janela3, 8,2, "Empada Galinha   0,90");
    mvwprintw(janela3, 10,2,"Empada Frango    0,90");
    mvwprintw(janela3, 12,2,"Empada de Stana  4,50");
    mvwprintw(janela3, 14,2,"Rissol Camarão   0,60");

    mvwprintw(janela3, 4,34,"Pastel de Stana     2,70");
    mvwprintw(janela3, 6,34,"Folhado Misto       0,95");
    mvwprintw(janela3, 8,34,"Folhado Cogumelos   0,95");
    mvwprintw(janela3, 10,34,"Coxa Frango         0,70");
    mvwprintw(janela3, 12,34,"Coxa de Stana       0,85");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,34,"Asa de Stana        9,40");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);
    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    wrefresh(janela3);
    if(ch==TECLA_W)
    {
        menu_salga_11();
    }
    else if(ch==TECLA_S)
    {
        menu_salga_7();
    }
    else if(ch==TECLA_A)
    {
        menu_salga_6();
    }
    else if(ch==TECLA_D)
    {
        menu_salga_6();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_sal();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=salgado12;
        menu_salga_12();
    }
else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}


void menu_alcoo_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_6();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_2();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_7();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_7();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool1;
        menu_alcoo_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_1();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_3();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_8();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_8();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool2;
        menu_alcoo_2();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);




    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
    {
        menu_alcoo_2();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_4();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_9();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_9();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool3;
        menu_alcoo_3();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);
    wrefresh(janela3);

    if(ch==TECLA_W)
    {
        menu_alcoo_3();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_5();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_10();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_10();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool4;
        menu_alcoo_4();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_4();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_6();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_11();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_11();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool5;
        menu_alcoo_5();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,2,"Panaché            0,80");
    wattron(janela3, COLOR_PAIR(1));

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_5();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_1();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_12();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_12();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool6;
        menu_alcoo_6();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_12();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_8();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_1();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_1();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool7;
        menu_alcoo_7();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menu_alcoo_7();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_9();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_2();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_2();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool8;
        menu_alcoo_8();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_8();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_10();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_3();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_3();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool9;
        menu_alcoo_9();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    ch = wgetch(janela3);

    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);

    if(ch==TECLA_W)
    {
        menu_alcoo_9();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_11();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_4();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_4();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool10;
        menu_alcoo_10();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");


    wrefresh(janela3);



    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_10();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_12();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_5();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_5();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool11;
        menu_alcoo_11();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_alcoo_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1



    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    wattron(janela3, COLOR_PAIR(3 ));
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 1,51, "Refeição");
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "1/2 Whiskey Novo   1,00");
    mvwprintw(janela3, 6,2, "1/2 Whiskey Velho  2,00");
    mvwprintw(janela3, 8,2, "1/2 Brandy         1,00");
    mvwprintw(janela3, 10,2,"1/2 Vodka          2,50");
    mvwprintw(janela3, 12,2,"Imperial           0,90");
    mvwprintw(janela3, 14,2,"Panaché            0,80");

    mvwprintw(janela3, 4,35,"Shot Triplex       0,80");
    mvwprintw(janela3, 6,35,"Shot B-51          0,50");
    mvwprintw(janela3, 8,35,"Shot TnT           0,60");
    mvwprintw(janela3, 10,35,"Shot Stana         0,90");
    mvwprintw(janela3, 12,35,"Shot Banana        4,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,35,"Shot Bad-Trip      8,00");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67,"Total: %.2f", precofinal);
    wrefresh(janela4);


    if(ch==TECLA_W)
    {
        menu_alcoo_11();
    }
    else if(ch==TECLA_S)
    {
        menu_alcoo_7();
    }
    else if(ch==TECLA_A)
    {
        menu_alcoo_6();
    }
    else if(ch==TECLA_D)
    {
        menu_alcoo_6();
    }
    else if(ch==TECLA_ESQ)
    {
        menu_prod_alc();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=alcool12;
        menu_alcoo_12();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }
}

void menu_refeicao_1()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);

    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_6();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_2();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_7();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_7();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao1;
        menu_refeicao_1();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_2()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);

    noecho();

    if(ch==TECLA_A)
    {
        menu_refeicao_8();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_8();
    }
    else if(ch==TECLA_W)
    {
        menu_refeicao_1();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_3();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao2;
        menu_refeicao_2();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_3()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);

    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_2();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_4();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_9();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_9();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao3;
        menu_refeicao_3();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_4()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_3();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_5();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_10();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_10();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao4;
        menu_refeicao_4();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_5()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);

    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_4();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_6();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_11();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_11();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao5;
        menu_refeicao_5();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}



void menu_refeicao_6()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");
    wattron(janela3, COLOR_PAIR(1));

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);

    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_5();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_1();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_12();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_12();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao6;
        menu_refeicao_6();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_7()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_12();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_8();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_1();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_1();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao7;
        menu_refeicao_7();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_8()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_7();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_9();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_2();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_2();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao8;
        menu_refeicao_8();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_9()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_8();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_10();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_3();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_3();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao9;
        menu_refeicao_9();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_10()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_9();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_11();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_4();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_4();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao10;
        menu_refeicao_10();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_11()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    wattron(janela3,COLOR_PAIR(3));
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    ch = wgetch(janela3);

    wrefresh(janela3);


    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_10();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_12();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_5();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_5();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao11;
        menu_refeicao_11();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}

void menu_refeicao_12()
{
    WINDOW *janela1, *janela2, *janela3, *janela4;
    setlocale(LC_ALL, "Portuguese");
    int ch;
    //menu_prod = 1;
    janela1 = newwin(5,80,0,0); // Define a Janela1 (Inicial)
    wbkgd(janela1, COLOR_PAIR(1)); // Define a Cor de Fundo
    wattron(janela1, A_BOLD); //Coloca a cor do texto em formato A_BOLD
    mvwprintw(janela1, 2,25, "Caixa Registadora - LITTLE COFFEE"); //Define o Texto que Aparece nas coordenadas.
    wborder(janela1, 0, 0, 0, 0, 0, 0, 0, 0);
    wrefresh(janela1); //Atualizaremos a janela1


    janela2 = newwin(17,20,5,0);
    wbkgd(janela2, COLOR_PAIR(1));
    wattron(janela2, A_BOLD);
    wborder(janela2, 0,0,0,0,0,0,0,0);
    mvwprintw(janela2, 2,2, "1 - Ver Produtos");
    mvwprintw(janela2, 5,2, "2 - Mudar Conta");
    mvwprintw(janela2, 8,2, "3 - Gestão");
    mvwprintw(janela2, 11,2, "4 - Opções");
    mvwprintw(janela2, 14,2, "5 - Finalizar");
    wrefresh(janela2);



    janela3 = newwin(17,60, 5,20);
    wbkgd(janela3, COLOR_PAIR(1));
    wattron(janela3, A_BOLD);
    wborder(janela3, 0,0,0,0,0,0,0,0);
    mvwprintw(janela3, 1,2, "Cafetaria");
    mvwprintw(janela3, 1,13, "Padaria");
    mvwprintw(janela3, 1,22, "Salgado");
    mvwprintw(janela3, 1,31, "Pastelaria");
    mvwprintw(janela3, 1,43, "Alcool");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 1,51, "Refeição");
    wattron(janela3, COLOR_PAIR(1));
    mvwprintw(janela3, 2,2, "*********************************************************");
    mvwprintw(janela3, 4,2, "Prato do Dia       5,00");
    mvwprintw(janela3, 6,2, "Sopa               1,50");
    mvwprintw(janela3, 8,2, "Omelete            3,50");
    mvwprintw(janela3, 10,2,"Quiche             3,50");
    mvwprintw(janela3, 12,2,"Tarte Vegetariana  3,50");
    mvwprintw(janela3, 14,2,"Tarte da Bimby     3,50");

    mvwprintw(janela3, 4,35,"Hamburguer         3,00");
    mvwprintw(janela3, 6,35,"Queijo             0,50");
    mvwprintw(janela3, 8,35,"Fiambre            0,50");
    mvwprintw(janela3, 10,35,"Bacon              0,70");
    mvwprintw(janela3, 12,35,"Ovo                0,50");
    wattron(janela3, COLOR_PAIR(3));
    mvwprintw(janela3, 14,35,"Alface e Tomate    0,50");
    wattron(janela3, COLOR_PAIR(1));
    ch = wgetch(janela3);

    wrefresh(janela3);

    janela4 = newwin(3,80, 22,0);
    wbkgd(janela4, COLOR_PAIR(2));
    mvwprintw(janela4, 1,67, "Total: %.2f", precofinal);

    wrefresh(janela4);


    noecho();

    if(ch==TECLA_W)
    {
        menu_refeicao_11();
    }
    else if(ch==TECLA_S)
    {
        menu_refeicao_7();
    }
    else if(ch==TECLA_A)
    {
        menu_refeicao_6();
    }
    else if(ch==TECLA_D)
    {
        menu_refeicao_6();
    }
    else if(ch==TECLA_ENTER)
    {
        precofinal+=refeicao12;
        menu_refeicao_12();
    }
    else if(ch==TECLA_1)
        {
            menu_prod_caf();
        }
        else if(ch==TECLA_2)
        {
            menumudarconta();
        }
        else if(ch==TECLA_3)
        {
            menugestao();
        }
        else if(ch==TECLA_4)
        {
            menuopcoes();
        }
        else if(ch==TECLA_5)
        {
            menufinalizar_0();
        }


}


int main()
{


    initscr();	// Inicia o Curses
    noecho();

	start_color();

    init_pair(1,COLOR_WHITE,COLOR_BLUE); // Pares de Cores (Texto Branco, Fundo Azul)
    init_pair(2,COLOR_BLACK, COLOR_WHITE);
    init_pair(3,COLOR_BLUE,COLOR_WHITE);
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
    cbreak(); // Buffer da Linha desligado

	keypad(stdscr, TRUE); // Posso obter teclas especiais como F1, F2, etc.
    curs_set(0); // Desliga o Piscar do Cursor
    menuinicial(); //Faz aparece o primeiro menu
    menulogin(); //Após um getch, aparece o menu para efetuar o Login.





	endwin();//Termina a biblioteca Curses


	return 0;

}



