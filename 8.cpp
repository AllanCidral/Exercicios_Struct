//FUNCAO:
// gerar um registro de uma loja com N vendedores, para cada vendedor: nome, quantidade vendida, valor das vendas e valor total das vendas
// a leitura de vendas nao e sequencial e deve ser feita individualmente
// os nomes devem estar ordenados em ordem alfabetica
// quantidade maxima de vendedores foi definida como 50
// quantidade maxima de vendas por vendedor foi definida como 100
#include <iostream>
#include <cctype> // isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stoi, stof
#include <iomanip> // setprecision
#define TMAX 50 // quantidade maxima de vendedores
#define MAXVENDA 100 // quantidade maxima de vendas por vendedor
using namespace std;

typedef struct {
    string nome;
    unsigned short int qntd;
    float vendas[MAXVENDA], totalVendas;
} Vendedor;
int leiaN(); // le e valida a quantidade de vendedores
void leiaNomes(unsigned short int n, Vendedor loja[]); // le e valida os nomes
void ordenaNomes(unsigned short int n, Vendedor loja[]); // ordena os nomes em ordem alfabetica
void leiaVendas(unsigned short int n, Vendedor loja[]); // le e valida as vendas por vendedor e verifica se o vendedor possui mais vendas
void relatorio(unsigned short int n, Vendedor loja[]); // relatorio final

int main()
{
    Vendedor loja[TMAX];
    unsigned short int n = 0;
	n = leiaN();
	system("CLS");
	leiaNomes(n, loja);
	system("CLS");
	ordenaNomes(n, loja);
	leiaVendas(n, loja);
	system("CLS");
	relatorio(n, loja);
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	unsigned short int x = 0;
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
void leiaNomes(unsigned short int n, Vendedor loja[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		loja[i].nome = "";
		do {
			validado = true;
			cout << "Informe o nome do(a) " << i + 1 << " vendedor(a): ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Nome invalido, tente novamente." << endl;
		} while (!validado);
		loja[i].nome = info;
	}
}
void ordenaNomes(unsigned short int n, Vendedor loja[]) {
	string aux = "";
	for (unsigned short int i = 0; i < n; i++) {
		for (unsigned short int j = i + 1; j < n; j++) {
			if (loja[i].nome > loja[j].nome) {
				aux = loja[i].nome;
				loja[i].nome = loja[j].nome;
				loja[j].nome = aux;
			}
		}
	}
}
void leiaVendas(unsigned short int n, Vendedor loja[]) {
	string info = "";
	bool validado, validadoResp;
	unsigned short int ponto = 0;
	float x = 0.0;
	char resp = 'S';
	for (unsigned short int i = 0; i < n; i++) {
		loja[i].qntd = 1;
		loja[i].vendas[loja[i].qntd] = 0.0;
		loja[i].totalVendas = 0.0;
		do {
			do {
				do {
					validado = true;
					ponto = 0;
					cout << "Informe o valor da " << loja[i].qntd << " venda do(a) vendedor(a) " << loja[i].nome << ": $";
					getline(cin, info);
					if (info == "") // se a string for vazia
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
			loja[i].vendas[loja[i].qntd] = x;
			loja[i].totalVendas += loja[i].vendas[loja[i].qntd];
			do {
				validadoResp = true;
				cout << "O(A) vendedor(a) " << loja[i].nome << " possui mais uma venda? (S/N) : ";
				cin.get(resp);
				resp = toupper(resp);
				cin.ignore();
				if (resp == ' ') // se a string for vazia
					validadoResp = false;
				if (resp != 'S' and resp != 'N') // se nao e letra do alfabeto ou S/N
					validadoResp = false;
				if (!validadoResp)
					cout << "Entrada invalida, tente novamente." << endl;
			} while (!validadoResp);
			if (loja[i].qntd > MAXVENDA) {
				cout << "Quantidade maxima de vendas por vendedor atingida!" << endl;
				resp = 'N';
			}
			if (resp == 'S')
				loja[i].qntd++;
		} while (resp == 'S');
	}
}
void relatorio(unsigned short int n, Vendedor loja[]) {
	cout << "Relatorio:\n";
	cout << "----------------------------------------\n";
	for (unsigned short int i = 0; i < n; i++) {
		cout << "Nome: " << loja[i].nome << endl;
		cout << "Quantidade vendida: " << loja[i].qntd << endl;
		cout << "Total de vendas: $" << fixed << setprecision(2) << loja[i].totalVendas << endl;
		cout << "----------------------------------------\n";
	}
}