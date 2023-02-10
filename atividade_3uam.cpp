#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

typedef struct
{
	char nome[30];
	int anoNascimento;
	double montante;
} c_cliente;

int opcao = 0;

/*void carregarLista()
{
	c_cliente cliente[10];
	c_cliente* c;
	c = &cliente[0];
}*/

void menu()
{
	cout << "+-------------------------------------------+" << endl;
	cout << "|\t\tSISTEMA			" << endl;
	cout << "+-------------------------------------------+" << endl;
	cout << "| [ 1 ] - Incluir um novo cliente " << endl;
	cout << "| [ 2 ] - Listar clientes " << endl;
	cout << "| [ 3 ] - Remover cliente " << endl;
	cout << "| [ 4 ] - Zerar todos montantes " << endl;
	cout << "| [ 5 ] - Listar o melhor comprador " << endl;
	cout << "| [ 6 ] - Exibir montante de um cliente específico " << endl;
	cout << "| [ 7 ] - Sair " << endl;
	cout << "+-------------------------------------------+" << endl;
	cout << "|Opção ";
	cin >> opcao;

	/*- incluir um novo cliente
	- remover cliente - atualizar o montante de compras do cliente realizadas no mês corrente
	- zerar todos os montantes de compras por ocasião da virada de mês
	- listar o cliente melhor comprador
	- exibir um montante de compras de um cliente específico.*/
}

void incluirCliente(c_cliente* c)
{
	//system("cls");
	int i = 0;
	char cont;

	do
	{
		cout << "Dados do " << i + 1 << "º Cliente: "  << endl;
		cout << "Nome: ";
		cin >> (c + i)->nome;
		cout << "Ano Nascimento: ";
		cin >> (c + i)-> anoNascimento;
		cout << "Montante em Gastos  R$";
		cin >> (c + i)->montante;
		i++;
		cout << "Deseja continuar [s/n]";
		cin >> cont;
		if((cont == 'n') || (cont == 'N'))
		{
			break;
		}
		if( i >= 10)
		{
			cout << "Atingido quantidade máxima de clientes" << endl;
			break;
		}
	}
	while(i < 10 || cont == 'n' || cont == 'N');
}

void listarCliente(c_cliente* c)
{
	for(int i = 0; i < 10; i++)
	{
		if((c + i)-> montante != 0.0)
		{
			cout << "===================================" << endl;
			cout << "Dados do " << i + 1 << " cliente" << endl;
			cout << "===================================" << endl;
			cout << "Nome: " << (c + i)->nome << endl;
			cout << "Ano Nascimento: " << (c + i)->anoNascimento << endl;
			cout << "Montante em R$" << (c + i)->montante << endl;
		}
	}
}

void removerCliente(c_cliente* c)
{
	char procurar[30];
	//char procurar[30];
	cout << "Informe um nome para remover: ";
	cin >> procurar;
	for(int i = 0; i < 10; i++)
	{
		if(!strcmp(procurar, (c + i)-> nome))
		{
			strcpy((c + i)->nome, "-");
			(c + i)->anoNascimento = 0;
			(c + i)->montante = 0;
		}
	}
}


void zerarMontantes(c_cliente* c)
{
	char zerar;
	cout << "Deseja zerar montantes? [s][n]" << endl;
	cin >> zerar;
	if(zerar == 'S' || zerar == 's')
	{
		for(int i = 0; i < 10; i++)
		{
			cout << "Zerando montante do " << i + 1 << " cliente: " << endl;
			(c + i)->montante = 0 ;
		}
		cout << "Montantes zerados com sucesso " << endl;
	}
}

void melhorComprador(c_cliente* c)
{
	cout << "Melhor Comprador" << endl;
	char n[30];
	int ano = 0;
	double mon = 0;
	strcpy(n, (c + 0)->nome);
	ano = (c + 0)->anoNascimento;
	mon = (c + 0)->montante;
	for(int i = 1; i < 10; i++)
	{
		if((c + i)->montante > mon)
		{
			strcpy(n, (c + i)->nome);
			ano = (c + i)->anoNascimento;
			mon = (c + i)->montante;
		}
	}
	cout << "Nome do Melhor comprador " << n << " com ano de nascimento " << ano << " no valor de montante de  " << mon << endl;
}

void montanteCliente(c_cliente* c){ 
	char n[30];
	double m; 
	for(int i = 0; i < 10;i++){ 
		if(!strcmp(n, (c + i)-> nome))
		{
			m += (c + i)->montante;
		}
	}
	cout << "Montante do Cliente " << m << endl; 
}


int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "Portuguese");

	int i = 0;
	char cont;

	c_cliente cliente[10];
	c_cliente* c;
	c = &cliente[0];

	for(int i = 0; i < 10; i++)
	{
		//cout << "Zerando montante do " << i + 1 << " cliente: " << endl;
		strcpy((c + i)->nome, "---");
		(c + i)->anoNascimento = 0;
		(c + i)->montante = 0.0;
	}

	//carregarLista(&cliente);
	do
	{
		menu();
		switch(opcao)
		{
		case 1:
			incluirCliente(&cliente[0]);
			break;
		case 2:
			listarCliente(&cliente[0]);
			break;
		case 3:
			removerCliente(&cliente[0]);
			break;
		case 4:
			zerarMontantes(&cliente[0]);
			break;
		case 5:
			melhorComprador(&cliente[0]);
			break;
		case 6: 
			montanteCliente(&cliente[0]); 
			break; 	
		}
	}
	while(opcao != 7);

	return 0;
}
