//FUNCAO:
// gerar um registro de uma empresa com n funcionarios e verificar quais funcionarios possuem salario acima da media.
// o algoritmo deve socilitar os dados do funcionario individualmente para so depois calcular a media salarial.
// tamanho da matricula foi definido como 7.
#include <iostream>
#include <cctype> // isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stof
#include <iomanip> // setprecision
#define TMAX 50 // quantidade maxima de funcionarios
#define TMAT 7 // tamanho da matricula
#define ANOMIN 1950 // ano minimo da data de admissao
#define ANOMAX 2023 // ano maximo da data de admissao
using namespace std;

typedef struct {
	string matricula, nome, cargo, dpto, data;
	float salario;
	bool salarioSuperior;
} Funcionario;
void leiaMatricula(unsigned short int i, Funcionario empresa[]); // le e valida a matricula
void leiaNome(unsigned short int i, Funcionario empresa[]); // le e valida o nome
void leiaCargo(unsigned short int i, Funcionario empresa[]); // le e valida o cargo
void leiaDpto(unsigned short int i, Funcionario empresa[]); // le e valida o departamento
void leiaData(unsigned short int i, Funcionario empresa[]); // le e valida a data de admissao
void leiaSalario(unsigned short int i, Funcionario empresa[]); // le e valida o salario
char leiaResp(unsigned short int i); // le a resposta do usuario para inserir mais um funcionario
float gerarSalarioMedio(unsigned short int i, Funcionario empresa[]); // gera a media salarial dos funcionarios
void verificarSalarioSuperior(unsigned short int i, float media, Funcionario empresa[]); // verifica se o salario do funcionario e maior que a media 
void relatorio(unsigned short int i, float media, Funcionario empresa[]); // relatorio final

int main()
{
	Funcionario empresa[TMAX];
	unsigned short int i = 0;
	float media = 0.0;
	char resp = 'S';
	do {
		leiaMatricula(i, empresa);
		system("CLS");
		leiaNome(i, empresa);
		system("CLS");
		leiaCargo(i, empresa);
		system("CLS");
		leiaDpto(i, empresa);
		system("CLS");
		leiaData(i, empresa);
		system("CLS");
		leiaSalario(i, empresa);
		system("CLS");
		resp = leiaResp(i);
		system("CLS");
		if (resp == 'S')
			i++;
	} while (resp == 'S');
	media = gerarSalarioMedio(i, empresa);
	verificarSalarioSuperior(i, media, empresa);
	relatorio(i, media, empresa);
	return 0;
}
void leiaMatricula(unsigned short int i, Funcionario empresa[]) {
	string info = "";
	bool validado;
	do {
		empresa[i].matricula = "";
		validado = true;
		cout << "Informe a matricula: ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		if (info.size() != TMAT)
			validado = false;
		else
			for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
				if (!isdigit(info.at(j))) // se nao for digito
					validado = false;
		if (!validado)
			cout << "Matricula invalida, tente novamente." << endl;
	} while (!validado);
	empresa[i].matricula = info;
}
void leiaNome(unsigned short int i, Funcionario empresa[]) {
	string info = "";
	bool validado;
	do {
		empresa[i].nome = "";
		validado = true;
		cout << "Informe o nome: ";
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
void leiaCargo(unsigned short int i, Funcionario empresa[]) {
	string info = "";
	bool validado;
	do {
		empresa[i].cargo = "";
		validado = true;
		cout << "Informe o cargo: ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
			if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
				validado = false;
		if (!validado)
			cout << "Cargo invalido, tente novamente." << endl;
	} while (!validado);
	empresa[i].cargo = info;
}
void leiaDpto(unsigned short int i, Funcionario empresa[]) {
	string info = "";
	bool validado;
	do {
		empresa[i].dpto = "";
		validado = true;
		cout << "Informe o departamento: ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
			if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
				validado = false;
		if (!validado)
			cout << "Departamento invalido, tente novamente." << endl;
	} while (!validado);
	empresa[i].dpto = info;
}
void leiaData(unsigned short int i, Funcionario empresa[]) {
	string info = "";
	bool validado;
	do {
		empresa[i].data = "";
		validado = true;
		cout << "Informe a data de admissao: ";
		getline(cin, info);
		if (info == "")  // se a string for vazia
			validado = false; 
		if (info.size() != 10) // se a string nao tiver o tamanho correto
			validado = false;
		else {
			for (unsigned short int j = 0; j < info.size(); j++) {
				if (j == 2 or j == 5) { // verificar barras
					if (info.at(j) != '/')
						validado = false;
				}
				else
					if (!isdigit(info.at(j))) // se nao for digito
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
	empresa[i].data = info;
}
void leiaSalario(unsigned short int i, Funcionario empresa[]) {
	string info = "";
	bool validado;
	int ponto;
	float x = 0.0;
	do {
		empresa[i].salario = 0.0;
		do {
			validado = true;
			ponto = 0;
			cout << "Informe o salario: $";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			else
				for (unsigned short int j = 0; j < info.size(); j++) // verifica posicao a posicao
					if (!isdigit(info.at(j))) { // se nao for digito
						if (!isdigit(info.at(j - 1)) and info.at(j) == '.' and ponto == 0) // verifica se ha um ponto antes
							ponto++; // permite somente um ponto
						else
							validado = false;
					}
			if (!validado)
				cout << "Salario invalido, tente novamente." << endl;
		} while (!validado);
		x = stof(info.c_str()); // converte string para float
		if (x == 0.0)
			cout << "Salario invalido, tente novamente." << endl;
	} while (x == 0.0);
	empresa[i].salario = x;
}
char leiaResp(unsigned short int i) {
	bool validado;
	char info = ' ';
	if (i > TMAX)
		return 'N';
	do {
		validado = true;
		cout << "Deseja inserir outro funcionario? (S/N): ";
		cin.get(info);
		info = toupper(info);
		cin.ignore();
		if (info == ' ') // se a string for vazia
			validado = false;
		if (info != 'S' and info != 'N') // se nao e letra do alfabeto ou S/N
			validado = false;
		if (!validado)
			cout << "Opcao invalida, tente novamente." << endl;
	} while (!validado);
	return info;
}
float gerarSalarioMedio(unsigned short int i, Funcionario empresa[]) {
	float media = 0.0;
	for (short int j = 0; j <= i; j++)
		media += empresa[j].salario;
	return media / (i + 1);
}
void verificarSalarioSuperior(unsigned short int i, float media, Funcionario empresa[]) {
	for (short int j = 0; j <= i; j++) {
		empresa[j].salarioSuperior = false;
		if (empresa[j].salario > media)
			empresa[j].salarioSuperior = true;
	}
}
void relatorio(unsigned short int i, float media, Funcionario empresa[]) {
	cout << "Funcionarios:\n";
	cout << "--------------------------------------------\n";
	for (unsigned short int j = 0; j <= i; j++) {
		cout << "Matricula: " << empresa[j].matricula << endl;
		cout << "Nome: " << empresa[j].nome << endl;
		cout << "Cargo: " << empresa[j].cargo << endl;
		cout << "Departamento: " << empresa[j].dpto << endl;
		cout << "Data de admissao: " << empresa[j].data << endl;
		cout << "Salario: $" << fixed << setprecision(2) << empresa[j].salario << endl;
		cout << "--------------------------------------------\n";
	}
	cout << "Media salarial: $" << fixed << setprecision(2) << media << endl;
	cout << "--------------------------------------------\n";
	cout << "Funcionarios com salario acima da media:\n";
	cout << "--------------------------------------------\n";
	for (unsigned short int j = 0; j <= i; j++)
		if (empresa[j].salarioSuperior) {
			cout << "Matricula: " << empresa[j].matricula << endl;
			cout << "Nome: " << empresa[j].nome << endl;
			cout << "Cargo: " << empresa[j].cargo << endl;
			cout << "Departamento: " << empresa[j].dpto << endl;
			cout << "Data de admissao: " << empresa[j].data << endl;
			cout << "Salario: $" << fixed << setprecision(2) << empresa[j].salario << endl;
			cout << "--------------------------------------------\n";
		}
}
