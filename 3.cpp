//FUNCAO:
// gerar um registro para representar uma turma contendo determinados alunos, contendo nomes, notas de 4 provas e a suas medias.
#include <iostream>
#include <cctype> // isalpha, isdigit
#include <string> // getline
#include <cstdlib> // stof
#include <iomanip> // setprecision
#define TNOTAS 4 // quantidade de notas
#define TMAX 10 // nota maxima
#define TTURMA 20 // tamanho da turma
using namespace std;

typedef struct {
	string nome;
	float notas[TNOTAS], media;
} Aluno;
void leiaNomes(Aluno turma[]); // le e valida os nomes dos alunos
void leiaNotas(Aluno turma[]); // le e valida as notas dos alunos
void gerarMedia(Aluno turma[]); // gera a media de cada aluno
void relatorio(Aluno turma[]); // relatorio da turma

int main()
{
	Aluno turma[TTURMA];

	leiaNomes(turma);
	system("CLS");
	leiaNotas(turma);
	system("CLS");
	gerarMedia(turma);
	relatorio(turma);
	return 0;
}
void leiaNomes(Aluno turma[]) {
	bool validado;
	string info = "";
	for (unsigned short int i = 0; i < TTURMA; i++) {
		turma[i].nome = "";
		do {
			validado = true;
			cout << "Informe o nome do(a) " << i+1 << " aluno(a): ";
			getline(cin, info);
			if (info == "") // se a string for vazia
				validado = false;
			for (unsigned long int j = 0; j < info.size(); j++) // verifica letra por letra
				if (!isalpha(info.at(j)) and info.at(j) != ' ') // se nao e letra do alfabeto ou branco
					validado = false;
			if (!validado)
				cout << "Nome invalido, tente novamente." << endl;
		} while (!validado);
		turma[i].nome = info;
	}
}
void leiaNotas(Aluno turma[]) {
	string info = "";
	bool validado;
	int ponto;
	float x = 0.0;
	for (unsigned short int i = 0; i < TTURMA; i++) {
		for (unsigned short int j = 0; j < TNOTAS; j++) {
			turma[i].notas[j] = 0.0;
			do {
				do {
					info = "";
					validado = true;
					ponto = 0;
					cout << "Informe a " << j + 1 << " nota do(a) " << turma[i].nome << ": ";
					getline(cin, info);
					if (info == "") // se a string for vazia
						validado = false;
					else
						for (unsigned long int k = 0; k < info.size(); k++) // verifica posicao a posicao
							if (!isdigit(info.at(0))) // se nao for digito
								validado = false;
							else
								if (!isdigit(info.at(k))) { // se nao for digito 
									if (isdigit(info.at(k - 1)) and info.at(k) == '.' and ponto == 0) // verifica se ha um ponto antes
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
			turma[i].notas[j] = x;
		}
	}
}
void gerarMedia(Aluno turma[]) {
	for (unsigned short int i = 0; i < TTURMA; i++) {
		float media = 0.0;
		turma[i].media = 0.0;
		for (unsigned short int j = 0; j < TNOTAS; j++)
			media += turma[i].notas[j];
		turma[i].media = media / TNOTAS;
	}
}
void relatorio(Aluno turma[]) {
	cout << "Turma:\n";
	cout << "------------------------------------------\n";
	for (unsigned short int i = 0; i < TTURMA; i++) {
		cout << "Aluno(a): " << turma[i].nome << endl;
		cout << "Notas: \n";
		for (unsigned short int j = 0; j < TNOTAS; j++)
			cout << "[" << fixed << setprecision(2) << turma[i].notas[j] << "]";
		cout << endl;
		cout << "Media: " << fixed << setprecision(2) << turma[i].media << endl;
		cout << "------------------------------------------\n";
	}
}