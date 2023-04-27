//FUNCAO:
// gerar um registo de uma empresa, para cada vendedor e conhecido o nome, a quantidade vendida, o valor da venda e o salario fixo.
// os vendedores recebem comissao de acordo com a quantidade vendida:
// 10 % do valor da venda se quantidade vendida < 15;
// 22 % do valor da venda se 15 <= quantidade vendida < 30;
// 30 % do valor da venda se quantidade vendida >= 30.
// o registo deve incluir: nome, quantidade vendida, valor total da venda, salario fixo, comissao e salario+comissao
// os nomes devem estar ordenados em ordem alfabetica.
#include <iostream>
#include <cctype> //isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stoi, stof
#include <iomanip> // setprecision
#define TMAX 20 // quantidade maxima de vendedores
#define MAXVENDA 100 // quantidade maxima de vendas
using namespace std;

typedef struct {
	string nome;
	unsigned short int qntd;
	float valor[MAXVENDA], salario, valorTotal, comissao, salarioComissao;
}Vendedor;
int leiaN(); // le e valida a quantidade de vendedores
void leiaNome(unsigned short int n, Vendedor empresa[]); // le e valida o nome
void ordenaNomes(unsigned short int n, Vendedor empresa[]); // ordena os nomes em ordem alfabetica
void leiaQntd(unsigned short int n, Vendedor empresa[]); // le e valida a quantidade
void leiaValor(unsigned short int n, Vendedor empresa[]); // le e valida o valor
void leiaSalario(unsigned short int n, Vendedor empresa[]); // le e valida o salario
void gerarComissao(unsigned short int n, Vendedor empresa[]); // gera a comissao
void relatorio(unsigned short int n, Vendedor empresa[]); // relatorio final

int main()
{
	Vendedor empresa[TMAX];
	unsigned short int n = 0;
	n = leiaN();
	system("CLS");
	leiaNome(n, empresa);
	system("CLS");
	ordenaNomes(n, empresa);
	leiaQntd(n, empresa);
	system("CLS");
	leiaValor(n, empresa);
	system("CLS");
	leiaSalario(n, empresa);
	system("CLS");
	gerarComissao(n, empresa);
	relatorio(n, empresa);
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe a quantidade de vendedores: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (unsigned short int i = 0; i < info.size(); i++) // verifica posicao a posicao
					if (!isdigit(info.at(i))) // se nao for digito
						validado = false;
			if (!validado)
				cout << "Quantidade invalida, tente novamente." << endl;
		} while (!validado);
		x = stoi(info.c_str()); // converte string para inteiro
		if (x == 0 or x > TMAX)
			cout << "Quantidade invalida, tente novamente." << endl;
	} while (x == 0 or x > TMAX);
	return x;
}
void leiaNome(unsigned short int n, Vendedor empresa[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		empresa[i].nome = "";
		do {
			validado = true;
			cout << "Informe o " << i + 1 << " nome do(a) vendedor(a): ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Nome invalido, tente novamente." << endl;
		} while (!validado);
		empresa[i].nome = info;
	}
}
void ordenaNomes(unsigned short int n, Vendedor empresa[]) {
	string aux = "";
	for (unsigned short int i = 0; i < n; i++) {
		for (unsigned short int j = i + 1; j < n; j++) {
			if (empresa[i].nome > empresa[j].nome) {
				aux = empresa[i].nome;
				empresa[i].nome = empresa[j].nome;
				empresa[j].nome = aux;
			}
		}
	}
}
void leiaQntd(unsigned short int n, Vendedor empresa[]) {
	string info = "";
	bool validado;
	unsigned short int x = 0;
	for (unsigned short int i = 0; i < n; i++) {
		empresa[i].qntd = 0;
		do {
			do {
				validado = true;
				cout << "Informe a quantidade de vendas do(a) " << empresa[i].nome << ": ";
				getline(cin, info);
				if (info == "") // se a string for vazia
					validado = false;
				else
					for (unsigned short int i = 0; i < info.size(); i++) // verifica posicao a posicao
						if (!isdigit(info.at(i))) // se nao for digito
							validado = false;
				if (!validado)
					cout << "Quantidade invalida, tente novamente." << endl;
			} while (!validado);
			x = stoi(info.c_str()); // converte string para inteiro
			if (x == 0 or x > MAXVENDA)
				cout << "Quantidade invalida, tente novamente." << endl;
		} while (x == 0 or x > MAXVENDA);
		empresa[i].qntd = x;
	}
}
void leiaValor(unsigned short int n, Vendedor empresa[]) {
	string info = "";
	bool validado;
	unsigned short int ponto;
	float x = 0.0;
	for (unsigned short int i = 0; i < n; i++) {
		for (unsigned short int j = 0; j < empresa[i].qntd; j++) {
			empresa[i].valor[j] = 0.0;
			do {
				do {
					validado = true;
					ponto = 0;
					cout << "Informe o valor da " << j + 1 << " venda do(a) vendedor(a) " << empresa[i].nome << ": $";
					getline(cin, info);
					if (info == "") // se a string for vazia
						validado = false;
					if (info.size() > 10) // tamanho maximo do valor (assumindo milhoes e centavos)
						validado = false;
					else
						for (unsigned short int k = 0; k < info.size(); k++) // verifica posicao a posicao
							if (!isdigit(info.at(k))) { // se nao for digito
								if (isdigit(info.at(k - 1)) and info.at(k) == '.' and ponto == 0) // verifica se ha um ponto antes
									ponto++; // permite somente um ponto
								else
									validado = false;
							}
					if (!validado)
						cout << "Valor invalido, tente novamente." << endl;
				} while (!validado);
				x = stof(info.c_str()); // converte string para float
				if (x == 0.0)
					cout << "Valor invalido, tente novamente." << endl;
			} while (x == 0.0);
			empresa[i].valor[j] = x;
		}
	}
}
void leiaSalario(unsigned short int n, Vendedor empresa[]) {
	string info = "";
	bool validado;
	unsigned short int ponto;
	float x = 0.0;
	for (unsigned short int i = 0; i < n; i++) {
		empresa[i].salario = 0.0;
		do {
			do {
				validado = true;
				ponto = 0;
				cout << "Informe o salario do(a) vendedor(a) " << empresa[i].nome << ": $";
				getline(cin, info);
				if (info == "") // se a string for vazia
					validado = false;
				if (info.size() > 10) // tamanho maximo do valor (assumindo milhoes e centavos)
					validado = false;
				else
					for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(j))) { // se nao for digito
							if (isdigit(info.at(j - 1)) and info.at(j) == '.' and ponto == 0) // verifica se ha um ponto antes
								ponto++; // permite somente um ponto
							else
								validado = false;
						}
				if (!validado)
					cout << "Valor invalido, tente novamente." << endl;
			} while (!validado);
			x = stof(info.c_str()); // converte string para float
			if (x == 0.0)
				cout << "Valor invalido, tente novamente." << endl;
		} while (x == 0.0);
		empresa[i].salario = x;
	}
}
void gerarComissao(unsigned short int n, Vendedor empresa[]) {
	for (unsigned short int i = 0; i < n; i++) {
		empresa[i].valorTotal = 0.0;
		empresa[i].comissao = 0.0;
		empresa[i].salarioComissao = 0.0;
		for (unsigned short int j = 0; j < empresa[i].qntd; j++) {
			empresa[i].valorTotal += empresa[i].valor[j];
		}
		if (empresa[i].qntd < 15) {
			empresa[i].comissao = empresa[i].valorTotal * 0.10;
			empresa[i].salarioComissao = empresa[i].salario + empresa[i].comissao;
		}
		if (empresa[i].qntd >= 15 and empresa[i].qntd < 30) {
			empresa[i].comissao = empresa[i].valorTotal * 0.22;
			empresa[i].salarioComissao = empresa[i].salario + empresa[i].comissao;
		}
		if (empresa[i].qntd >= 30) {
			empresa[i].comissao = empresa[i].valorTotal * 0.30;
			empresa[i].salarioComissao = empresa[i].salario + empresa[i].comissao;
		}
	}
}
void relatorio(unsigned short int n, Vendedor empresa[]) {
	cout << "Relatorio:\n";
	cout << "------------------------------------------------\n";
	for (unsigned short int i = 0; i < n; i++) {
		cout << "Nome: " << empresa[i].nome << endl;
		cout << "Quantidade vendida: " << empresa[i].qntd << endl;
		cout << "Valor total: $" << fixed << setprecision(2) << empresa[i].valorTotal << endl;
		cout << "Salario fixo: $" << fixed << setprecision(2) << empresa[i].salario << endl;
		cout << "Comissao: $" << fixed << setprecision(2) << empresa[i].comissao << endl;
		cout << "Salario + Comissao: $" << fixed << setprecision(2) << empresa[i].salarioComissao << endl;
		cout << "------------------------------------------------\n";
	}
}
