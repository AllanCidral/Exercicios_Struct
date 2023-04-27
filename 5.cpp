//FUNCAO:
//le n codigos de profissao e o respectivo nome da profissao.
//le um numero indeterminado de codigos e informa, para cada codigo lido, o nome da profissao correspondente, caso exista.
//O tamanho do codigo foi definido como 7.
#include <iostream>
#include <cctype> // isdigit
#include <string> // getline
#include <cstdlib> // stoi
#define TMAX 50 // quantidade maxima de codigos
#define TCOD 7 // tamanho do codigo
using namespace std;

typedef struct {
	string codigo, nome;
} Profissao;
int leiaN(); // le e valida a quantidade de codigos
void leiaCodigo(unsigned short int n, Profissao p[]); // le e valida o codigo
void leiaNome(unsigned short int n, Profissao p[]); // le e valida o nome
string leiaPesquisa(); // le e valida a pesquisa
void verificarCodigo(unsigned short int n, string &pesquisa, Profissao p[]); // verifica se a pesquisa corresponde a algum codigo
char leiaResp(); // verifica a resposta do usuario para continuar o programa

int main()
{
	unsigned short int n = 0;
	Profissao p[TMAX];
	string pesquisa = "";
	char resp = 'S';
	n = leiaN();
	system("CLS");
	leiaCodigo(n, p);
	system("CLS");
	leiaNome(n, p);
	system("CLS");
	do {
		pesquisa = leiaPesquisa();
		system("CLS");
		verificarCodigo(n, pesquisa, p);
		resp = leiaResp();
		system("CLS");
	} while (resp == 'S');
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	unsigned short int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe a quantidade de codigos: ";
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
void leiaCodigo(unsigned short int n, Profissao p[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		p[i].codigo = "";
		do {
			validado = true;
			cout << "Informe o " << i + 1 << " codigo: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			if (info.size() != TCOD) // se a entrada for maior ou menor ao estabelecido
				validado = false;
			else
				for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
					if (!isdigit(info.at(j))) // se nao for digito
						validado = false;
			if (!validado)
				cout << "Entrada invalida, tente novamente." << endl;
		} while (!validado);
		p[i].codigo = info;
	}
}
void leiaNome(unsigned short int n, Profissao p[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		p[i].nome = "";
		do {
			validado = true;
			cout << "Informe o nome da profissao referente ao codigo " << p[i].codigo << ": ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Entrada invalida, tente novamente." << endl;
		} while (!validado);
		p[i].nome = info;
	}
}
string leiaPesquisa() {
	string info = "";
	bool validado;
	do {
		validado = true;
		cout << "Informe o codigo que deseja procurar: ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		if (info.size() != TCOD) // se a entrada for maior ou menor ao estabelecido
			validado = false;
		else
			for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
				if (!isdigit(info.at(j))) // se nao for digito
					validado = false;
		if (!validado)
			cout << "Entrada invalida, tente novamente." << endl;
	} while (!validado);
	return info;
}
void verificarCodigo(unsigned short int n, string &pesquisa, Profissao p[]) {
	for (unsigned short int i = 0; i < n; i++) {
		if (pesquisa == p[i].codigo) {
			cout << "O codigo " << p[i].codigo << " e referente a profissao: " << p[i].nome << endl;
			return;
		}
	}
	cout << "O codigo fornecido nao corresponde a nenhuma profissao." << endl;
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		cout << endl;
		validado = true;
		cout << "Deseja pesquisar outro codigo? (S/N): ";
		cin.get(info);
		info = toupper(info);
		cin.ignore();
		if (info == ' ') // se for vazio
			validado = false;
		if (info != 'S' and info != 'N') // se nao e letra do alfabeto ou S/N
			validado = false;
		if (!validado)
			cout << "Opcao invalida, tente novamente." << endl;
	} while (!validado);
	return info;
}
