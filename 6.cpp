//FUNCAO:
// gerar um registro de socios com mais de 3 dependentes, incluindo matricula, nome, nome dos dependentes, data de nascimento dos dependentes.
// quantidade maxima de dependentes definida como 5.
// tamanho da matricula definido como 7.
#include <iostream>
#include <cctype> // isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stoi
#define MAXSOC 20 // quantidade maxima de socios
#define MAXDEP 5 // quantidade maxima de dependentes
#define TMAT 7 // tamanho da matricula
#define ANOMIN 1960 // data de nascimento maxima do(s) dependente(s)
#define ANOMAX 2023 // data de nascimento minima do(s) dependente(s)
using namespace std;

typedef struct {
	string matricula, nome, nomeDep[MAXDEP], dataDep[MAXDEP];
	unsigned short int qntd;
} Socio;
int leiaN(); // le e valida a quantidade de socios
void leiaMatricula(unsigned short int n, Socio x[]); // le e valida a matricula
void leiaNome(unsigned short int n, Socio x[]); // le e valida o nome
void leiaQntd(unsigned short int n, Socio x[]); // le e valida a quantidade de dependentes
void leiaNomeDep(unsigned short int n, Socio x[]); // le e valida o(s) nome(s) do(s) dependente(s)
void leiaDataDep(unsigned short int n, Socio x[]); // le e valida a(s) data(s) do(s) dependente(s)
void relatorio(unsigned short int n, Socio x[]); // mostra o(s) registro(s) referente ao(s) socio(s) que possuem mais de 3 dependentes

int main()
{
	Socio x[MAXSOC];
	unsigned short int n = 0;
	n = leiaN();
	system("CLS");
	leiaMatricula(n, x);
	system("CLS");
	leiaNome(n, x);
	system("CLS");
	leiaQntd(n, x);
	system("CLS");
	leiaNomeDep(n, x);
	system("CLS");
	leiaDataDep(n, x);
	system("CLS");
	relatorio(n, x);
	return 0;
}
int leiaN() {
	string info = "";
	bool validado;
	unsigned short int x = 0;
	do {
		do {
			validado = true;
			cout << "Informe a quantidade de socios: ";
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
		if (x == 0 or x > MAXSOC)
			cout << "Quantidade invalida, tente novamente." << endl;
	} while (x == 0 or x > MAXSOC);
	return x;
}
void leiaMatricula(unsigned short int n, Socio x[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		x[i].matricula = "";
		do {
			validado = true;
			cout << "Informe a matricula do " << i + 1 << " socio: ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			if (info.size() != TMAT) // se a entrada for maior ou menor ao estabelecido
				validado = false;
			else
				for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
					if (!isdigit(info.at(j))) // se nao for digito
						validado = false;
			if (!validado)
				cout << "Matricula invalida, tente novamente." << endl;
		} while (!validado);
		x[i].matricula = info;
	}
}
void leiaNome(unsigned short int n, Socio x[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		x[i].nome = "";
		do {
			validado = true;
			cout << "Informe o nome do socio referente a matricula " << x[i].matricula << ": ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Nome invalido, tente novamente." << endl;
		} while (!validado);
		x[i].nome = info;
	}
}
void leiaQntd(unsigned short int n, Socio x[]) {
	string info = "";
	bool validado;
	unsigned short int z = 0;
	for (unsigned short int i = 0; i < n; i++) {
		x[i].qntd = 0;
		do {
			do {
				validado = true;
				cout << "Informe a quantidade de dependentes referente a matricula: " << x[i].matricula << ": ";
				getline(cin, info);
				if (info == "") // se a string for vazia
					validado = false;
				else
					for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(j))) // se nao for digito
							validado = false;
				if (!validado)
					cout << "Quantidade invalida, tente novamente." << endl;
			} while (!validado);
			z = stoi(info.c_str()); // converte string para inteiro
			if (z > MAXDEP)
				cout << "Quantidade invalida, tente novamente." << endl;
		} while (z > MAXDEP);
		x[i].qntd = z;
	}
}
void leiaNomeDep(unsigned short int n, Socio x[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		if (x[i].qntd > 0) {
			for (unsigned short int j = 0; j < x[i].qntd; j++) {
				x[i].nomeDep[j] = "";
				do {
					validado = true;
					cout << "Informe o nome do " << j + 1 << " dependente referente a matricula " << x[i].matricula << ": ";
					getline(cin, info);
					if (info == "") // se a string for vazia
						validado = false;
					for (unsigned long int k = 0; k < info.size(); k++) // verifica letra por letra
						if (!isalpha(info.at(k)) and info.at(k) != ' ') // se nao e letra do alfabeto ou branco
							validado = false;
					if (!validado)
						cout << "Nome invalido, tente novamente." << endl;
				} while (!validado);
				x[i].nomeDep[j] = info;
			}
		}
	}
}
void leiaDataDep(unsigned short int n, Socio x[]) {
	string info = "";
	bool validado;
	for (unsigned short int i = 0; i < n; i++) {
		if (x[i].qntd > 0) {
			for (unsigned short int j = 0; j < x[i].qntd; j++) {
				x[i].dataDep[j] = "";
				do {
					validado = true;
					cout << "Informe a data de nascimento (xx/xx/xxxx) do " << j + 1 << " dependente referente a matricula " << x[i].matricula << ": ";
					getline(cin, info);
					if (info == "")  // se a string for vazia
						validado = false;
					if (info.size() != 10) // se a string nao tiver o tamanho correto
						validado = false;
					else {
						for (unsigned short int k = 0; k < info.size(); k++) {
							if (k == 2 or k == 5) { // verificar barras
								if (info.at(k) != '/')
									validado = false;
							}
							else
								if (!isdigit(info.at(k))) // se nao for digito
									validado = false;
						}
						int dia = stoi(info.substr(0, 2));
						int mes = stoi(info.substr(3, 2));
						int ano = stoi(info.substr(6, 4));
						if (dia < 1 or dia > 31)
							validado = false;
						if (mes < 1 or mes > 12)
							validado = false;
						if (ano < ANOMIN or ano > ANOMAX)
							validado = false;
						if (mes == 2)
							if (dia > 28)
								validado = false;
					}
					if (!validado)
						cout << "Data invalida, tente novamente." << endl;
				} while (!validado);
				x[i].dataDep[j] = info;
			}
		}
	}
}
void relatorio(unsigned short int n, Socio x[]) {
	cout << "Socios com mais de 3 dependentes:\n";
	cout << "-----------------------------------\n";
	for (unsigned short int i = 0; i < n; i++) {
		if (x[i].qntd > 3) {
			cout << "Matricula: " << x[i].matricula << endl;
			cout << "Nome: " << x[i].nome << endl;
			cout << "Quantidade de dependentes: " << x[i].qntd << endl;
			for (unsigned short int j = 0; j < x[i].qntd; j++) {
				cout << "Dependente " << j + 1 << ":\n";
				cout << "Nome: " << x[i].nomeDep[j] << endl;
				cout << "Data de nascimento: " << x[i].dataDep[j] << endl;
			}
			cout << "-----------------------------------\n";
		}
	}
}


