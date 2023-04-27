//FUNCAO:
// gerar um registro para representar um determinado aluno, contendo nome, notas de 4 provas e a sua media.
#include <iostream>
#include <cctype> // isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stof
#include <iomanip> // setprecision
#define TNOTAS 4 // quantidade de notas
#define TMAX 10 // nota maxima
using namespace std;

typedef struct {
	string nome;
	float notas[TNOTAS], media;
} Aluno;
string leiaNome(Aluno& aluno); // le e valida o nome
void leiaNotas(Aluno& aluno); // le e valida as notas
float gerarMedia(Aluno& aluno); // gera a media
void relatorio(Aluno& aluno); // relatorio do aluno
char leiaResp(); // le a resposta do usuario para continuar o programa

int main()
{
	Aluno aluno;
	char resp = 'S';
	do {
		aluno.nome = leiaNome(aluno);
		system("CLS");
		leiaNotas(aluno);
		system("CLS");
		aluno.media = gerarMedia(aluno);
		system("CLS");
		relatorio(aluno);
		resp = leiaResp();
		system("CLS");
	} while (resp == 'S');
	return 0;
}
string leiaNome(Aluno& aluno) {
	bool validado;
	string info = "";
	do {
		validado = true;
		cout << "Informe o nome do(a) aluno(a): ";
		getline(cin, info);
		if (info == "") // se a string for vazia
			validado = false;
		for (unsigned long int i = 0; i < info.size(); i++) // verifica letra por letra
			if (!isalpha(info.at(i)) and info.at(i) != ' ') // se nao e letra do alfabeto ou branco
				validado = false;
		if (!validado)
			cout << "Nome invalido, tente novamente." << endl;
	} while (!validado);
	return info;
}
void leiaNotas(Aluno& aluno) {
	string info = "";
	bool validado;
	int ponto;
	float x = 0.0;
	for (unsigned short int i = 0; i < TNOTAS; i++) {
		aluno.notas[i] = 0.0;
		do {
			do {
				info = "";
				validado = true;
				ponto = 0;
				cout << "Informe a " << i + 1 << " nota do(a) " << aluno.nome << ": ";
				getline(cin, info);
				if (info == "") // se a string for vazia
					validado = false;
				else
					for (unsigned long int j = 0; j < info.size(); j++) // verifica posicao a posicao
						if (!isdigit(info.at(0))) // se nao for digito
							validado = false;
						else
							if (!isdigit(info.at(j))) { // se nao for digito 
								if (isdigit(info.at(j - 1)) and info.at(j) == '.' and ponto == 0) // verifica se ha um ponto antes
									ponto++; // permite somente um ponto
								else
									validado = false;
							}
				if (!validado)
					cout << "Nota invalida, tente novamente." << endl;
			} while (!validado);
			x = stof(info.c_str());
			if (x > TMAX)
				cout << "Nota invalida, tente novamente." << endl;
		} while (x > TMAX);
		aluno.notas[i] = x;
	}
}
float gerarMedia(Aluno& aluno) {
	float media = 0.0;
	for (unsigned short int i = 0; i < TNOTAS; i++)
		media += aluno.notas[i];
	return media / TNOTAS;
}
void relatorio(Aluno& aluno) {
	cout << "Notas:\n";
	for (unsigned short int i = 0; i < TNOTAS; i++)
		cout << "[" << fixed << setprecision(2) << aluno.notas[i] << "]";
	cout << endl;
	cout << endl;
	cout << "O(A) aluno(a) " << aluno.nome << " teve a media de: " << fixed << setprecision(2) << aluno.media << endl;
	cout << endl;
}
char leiaResp() {
	bool validado;
	char info = ' ';
	do {
		validado = true;
		cout << "Deseja calcular a media de outro(a) aluno(a)? (S/N): ";
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